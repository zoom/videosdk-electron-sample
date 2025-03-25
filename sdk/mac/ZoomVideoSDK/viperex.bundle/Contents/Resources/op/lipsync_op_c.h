//
//  lipsync op --- C version
//
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef VIPER_MODULES_LIPSYNC_OP_C_H_
#define VIPER_MODULES_LIPSYNC_OP_C_H_

#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <cstring>

namespace viper
{
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#endif

class LipsyncOperation_C
{
public:
    inline float sigmoid_c(float x)
    {
        return 1.0f / (1.0f + expf(-x));
    }

    inline float cal_leaky_relu_c(float val, float gamma)
    {
        return MAX(0, val) + gamma * MIN(0, val);
    }

    inline float cal_hard_swish_relu_c(float val)
    {
        return val * MAX(0, MIN(6, val + 3)) / 6;
    }

    inline float cal_bn_c(float val, float mean, float gamma, float varsq, float betta)
    {
        return gamma * (val - mean) / sqrtf(varsq + 0.00001f) + betta;
    }

    template <class FC_PARAM>
    void linear_withskip_c(float* input, float* output, const float** fc_par, bool is_transpose)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];
        assert(FC_PARAM::in_nodes == FC_PARAM::o_nodes);
        memset(output, 0, sizeof(float) * FC_PARAM::o_nodes * FC_PARAM::n_ch); // checked safe

        if (is_transpose) // avoid two matrix transpose operate
        {
            for (int i = 0; i < FC_PARAM::o_nodes; i++)
            {
                const float* vecA = &(linear_weights[i * FC_PARAM::in_nodes]);
                float* vecC = &(output[i * FC_PARAM::n_ch]);
                for (int j = 0; j < FC_PARAM::in_nodes; j++)
                {
                    float* vecB = &(input[j * FC_PARAM::n_ch]);
                    for (int k = 0; k < FC_PARAM::n_ch; k++)
                    {
                        vecC[k] += vecA[j] * vecB[k];
                    }
                }
                float* vecB = &(input[i * FC_PARAM::n_ch]);
                for (int k = 0; k < FC_PARAM::n_ch; k++)
                {
                    vecC[k] += linear_bias[i] + vecB[k];
                }
            }
        }
        else
        {
            for (int i = 0; i < FC_PARAM::n_ch; i++)
            {
                float* vecA = &(input[i * FC_PARAM::in_nodes]);
                float* vecC = &(output[i * FC_PARAM::o_nodes]);
                for (int j = 0; j < FC_PARAM::o_nodes; j++)
                {
                    const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                    float sum = 0.0f;
                    for (int k = 0; k < FC_PARAM::in_nodes; k++)
                    {
                        sum += vecA[k] * vecB[k];
                    }
                    vecC[j] = sum + linear_bias[j] + vecA[j];
                }
            }
        }
    }

    template <class FC_PARAM>
    void linear_withskip_notrans_c(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];
        assert(FC_PARAM::in_nodes == FC_PARAM::o_nodes);

        for (int i = 0; i < FC_PARAM::n_ch; i++)
        {
            float* vecA = &(input[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::o_nodes]);
            for (int j = 0; j < FC_PARAM::o_nodes; j++)
            {
                const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                vecC[j] = linear_bias[j] + vecA[j];
                int k = 0;
                for (; k + 3 < FC_PARAM::in_nodes; k = k + 4)
                {
                    vecC[j] += vecA[k] * vecB[k];
                    vecC[j] += vecA[k + 1] * vecB[k + 1];
                    vecC[j] += vecA[k + 2] * vecB[k + 2];
                    vecC[j] += vecA[k + 3] * vecB[k + 3];
                }

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB[k];
                }
            }
        }
    }
    // just the linear function above with bn
    template <class FC_PARAM>
    void laughter_linear_hardswish_withskip_notrans_c(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];

        const float* linear_bn_mean = fc_par[2];
        const float* linear_bn_gamma = fc_par[3];
        const float* linear_bn_var = fc_par[4];
        const float* linear_bn_betta = fc_par[5];

        for (int i = 0; i < FC_PARAM::n_ch; i++)
        {
            float* vecA = &(input[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::o_nodes]);
            for (int j = 0; j < FC_PARAM::o_nodes; j++)
            {
                const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                vecC[j] = linear_bias[j];
                int k = 0;
                for (; k + 3 < FC_PARAM::in_nodes; k = k + 4)
                {
                    vecC[j] += vecA[k] * vecB[k];
                    vecC[j] += vecA[k + 1] * vecB[k + 1];
                    vecC[j] += vecA[k + 2] * vecB[k + 2];
                    vecC[j] += vecA[k + 3] * vecB[k + 3];
                }

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB[k];
                }
                vecC[j] =
                    cal_bn_c(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_c(vecC[j]);
            }
        }
    }
    template <class FC_PARAM>
    void linear_withskip_dotrans_c(float* input, float* output, const float** fc_par)
    {
        // std::cout<<"BN_FOLDING: linear_withskip_dotrans_c"<<std::endl;
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];
        assert(FC_PARAM::in_nodes == FC_PARAM::o_nodes);
        memset(output, 0, sizeof(float) * FC_PARAM::o_nodes * FC_PARAM::n_ch); // checked safe

        for (int i = 0; i < FC_PARAM::o_nodes; i++)
        {
            const float* vecA = &(linear_weights[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::n_ch]);

            for (int j = 0; j < FC_PARAM::in_nodes; j++)
            {
                float* vecB = &(input[j * FC_PARAM::n_ch]);
                for (int k = 0; k < FC_PARAM::n_ch; k++)
                {
                    vecC[k] += vecA[j] * vecB[k];
                }
            }
            float* vecB = &(input[i * FC_PARAM::n_ch]);
            for (int k = 0; k < FC_PARAM::n_ch; k++)
            {
                vecC[k] += linear_bias[i] + vecB[k];
            }
        }
    }

    template <class FC_PARAM>
    void linear_softmax_c(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];

        for (int i = 0; i < FC_PARAM::n_ch; i++)
        {
            float* vecA = &(input[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::o_nodes]);
            std::vector<float> vecexp(FC_PARAM::o_nodes, 0);
            float sumexp = 0;
            int j = 0;
            for (; j < FC_PARAM::o_nodes; j++)
            {
                const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                float sum = linear_bias[j];
                int k = 0;
                for (; k + 3 < FC_PARAM::in_nodes; k = k + 4)
                {
                    sum += vecA[k] * vecB[k];
                    sum += vecA[k + 1] * vecB[k + 1];
                    sum += vecA[k + 2] * vecB[k + 2];
                    sum += vecA[k + 3] * vecB[k + 3];
                }
                for (; k < FC_PARAM::in_nodes; k++)
                {
                    sum += vecA[k] * vecB[k];
                }
                vecexp[j] = expf(sum);
                sumexp += vecexp[j];
            }
            j = 0;
            for (; j < FC_PARAM::o_nodes; j++)
            {
                vecC[j] = vecexp[j] / sumexp;
            }
        }
    }
    template <class FC_PARAM>
    void linear_softmax_laugh_c(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];

        for (int i = 0; i < FC_PARAM::n_ch; i++)
        {
            float* vecA = &(input[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::o_nodes]);
            std::vector<float> vecexp(FC_PARAM::o_nodes, 0);
            float sumexp = 0;
            int j = 0;
            for (; j < FC_PARAM::o_nodes; j++)
            {
                const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                float sum = linear_bias[j];
                int k = 0;
                for (; k + 3 < FC_PARAM::in_nodes; k = k + 4)
                {
                    sum += vecA[k] * vecB[k];
                    sum += vecA[k + 1] * vecB[k + 1];
                    sum += vecA[k + 2] * vecB[k + 2];
                    sum += vecA[k + 3] * vecB[k + 3];
                }
                for (; k < FC_PARAM::in_nodes; k++)
                {
                    sum += vecA[k] * vecB[k];
                }
                vecexp[j] = expf(sum);
                sumexp += vecexp[j];
            }
            j = 0;
            for (; j < FC_PARAM::o_nodes; j++)
            {
                vecC[j] = vecexp[j] / sumexp;
            }
        }
    }
    // conv->reshape->bn->hardswish all in one func, with a kernel size of 1 (exclusively for laughter's conv1)
    template <class CONV_PARAM>
    void conv1d_bn_hardswish_laughter(float* input, float* output, const float** conv1d_par)
    {

        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;

        assert(CONV_PARAM::kernel_size == 1);
        const float* conv1d_weights = conv1d_par[0];
        const float* conv1d_bias = conv1d_par[1];

        const float* conv1d_bn_mean = conv1d_par[2];
        const float* conv1d_bn_gamma = conv1d_par[3];
        const float* conv1d_bn_var = conv1d_par[4];
        const float* conv1d_bn_betta = conv1d_par[5];

        memset(output, 0, sizeof(float) * output_len * CONV_PARAM::o_ch); // checked safe

        if (CONV_PARAM::kernel_size == 1)
        {
            for (int jidx = 0; jidx < CONV_PARAM::o_ch; jidx++)
            {
                // o_ch is always 1
                float* vecC = &(output[jidx * output_len]);
                const float* vecB = &(conv1d_weights[jidx * CONV_PARAM::in_ch]);
                for (int kidx = 0; kidx < CONV_PARAM::in_ch; kidx++)
                {
                    float* vecA = &(input[kidx * CONV_PARAM::in_phi]);
                    const float* vecBB = &(vecB[kidx]);
                    for (int midx = 0; midx < output_len; midx++)
                    {
                        float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                        vecC[midx] += vecAA[0] * vecBB[0];
                    }
                }
                for (int midx = 0; midx < output_len; midx++)
                {
                    vecC[midx] += conv1d_bias[jidx];
                    vecC[midx] = cal_bn_c(vecC[midx], conv1d_bn_mean[midx], conv1d_bn_gamma[midx], conv1d_bn_var[midx],
                                          conv1d_bn_betta[midx]);
                    vecC[midx] = cal_hard_swish_relu_c(vecC[midx]);
                }
            }
        }
        else
        {
            printf("CONV_PARAM::kernel_size must be 1 !!!");
            //exit(0);
        }
    }

    // conv->bn->hardswish all in one func, taking an option of kernel size of either 3 or 5
    template <class CONV_PARAM>
    void conv1d_bn_hardswish_c(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz3_c"<<std::endl;
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;
        assert(CONV_PARAM::kernel_size == 3 || CONV_PARAM::kernel_size == 5);
        const float* conv1d_weights = conv1d_par[0];
        const float* conv1d_bias = conv1d_par[1];
        memset(output, 0, sizeof(float) * output_len * CONV_PARAM::o_ch); // checked safe

        if (CONV_PARAM::kernel_size == 3)
        {
            for (int jidx = 0; jidx < CONV_PARAM::o_ch; jidx++)
            {
                float* vecC = &(output[jidx * output_len]);
                const float* vecB = &(conv1d_weights[jidx * CONV_PARAM::in_ch * 3]);
                for (int kidx = 0; kidx < CONV_PARAM::in_ch; kidx++)
                {
                    float* vecA = &(input[kidx * CONV_PARAM::in_phi]);
                    const float* vecBB = &(vecB[kidx * 3]);
                    for (int midx = 0; midx < output_len; midx++)
                    {
                        float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                        vecC[midx] += vecAA[0] * vecBB[0] + vecAA[1] * vecBB[1] + vecAA[2] * vecBB[2];
                    }
                }
                for (int midx = 0; midx < output_len; midx++)
                {
                    vecC[midx] += conv1d_bias[jidx];
                    vecC[midx] = cal_hard_swish_relu_c(vecC[midx]);
                }
            }
        }
        else if (CONV_PARAM::kernel_size == 5)
        {
            for (int jidx = 0; jidx < CONV_PARAM::o_ch; jidx++)
            {
                float* vecC = &(output[jidx * output_len]);
                const float* vecB = &(conv1d_weights[jidx * CONV_PARAM::in_ch * 5]);
                for (int kidx = 0; kidx < CONV_PARAM::in_ch; kidx++)
                {
                    float* vecA = &(input[kidx * CONV_PARAM::in_phi]);
                    const float* vecBB = &(vecB[kidx * 5]);
                    for (int midx = 0; midx < output_len; midx++)
                    {
                        float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                        vecC[midx] += vecAA[0] * vecBB[0] + vecAA[1] * vecBB[1] + vecAA[2] * vecBB[2] +
                                      vecAA[3] * vecBB[3] + vecAA[4] * vecBB[4];
                    }
                }
                for (int midx = 0; midx < output_len; midx++)
                {
                    vecC[midx] += conv1d_bias[jidx];
                    vecC[midx] = cal_hard_swish_relu_c(vecC[midx]);
                }
            }
        }
        else
        {
            printf("CONV_PARAM::kernel_size must be 3 or 5 !!!");
            // exit(0);
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz3_c(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz3_c"<<std::endl;
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;
        assert(CONV_PARAM::kernel_size == 3);
        const float* conv1d_weights = conv1d_par[0];
        const float* conv1d_bias = conv1d_par[1];
        memset(output, 0, sizeof(float) * output_len * CONV_PARAM::o_ch); // checked safe

        for (int jidx = 0; jidx < CONV_PARAM::o_ch; jidx++)
        {
            float* vecC = &(output[jidx * output_len]);
            const float* vecB = &(conv1d_weights[jidx * CONV_PARAM::in_ch * 3]);
            for (int kidx = 0; kidx < CONV_PARAM::in_ch; kidx++)
            {
                float* vecA = &(input[kidx * CONV_PARAM::in_phi]);
                const float* vecBB = &(vecB[kidx * 3]);
                for (int midx = 0; midx < output_len; midx++)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    vecC[midx] += vecAA[0] * vecBB[0] + vecAA[1] * vecBB[1] + vecAA[2] * vecBB[2];
                }
            }
            for (int midx = 0; midx < output_len; midx++)
            {
                vecC[midx] += conv1d_bias[jidx];
                vecC[midx] = cal_hard_swish_relu_c(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_c(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz5_c"<<std::endl;
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +1;
        assert(CONV_PARAM::kernel_size == 5);
        const float* conv1d_weights = conv1d_par[0];
        const float* conv1d_bias = conv1d_par[1];
        memset(output, 0, sizeof(float) * output_len * CONV_PARAM::o_ch); // checked safe

        for (int jidx = 0; jidx < CONV_PARAM::o_ch; jidx++)
        {
            float* vecC = &(output[jidx * output_len]);
            const float* vecB = &(conv1d_weights[jidx * CONV_PARAM::in_ch * 5]);
            for (int kidx = 0; kidx < CONV_PARAM::in_ch; kidx++)
            {
                float* vecA = &(input[kidx * CONV_PARAM::in_phi]);
                const float* vecBB = &(vecB[kidx * 5]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    const float* vecAA0 = &(vecA[midx * CONV_PARAM::stride]);
                    const float* vecAA1 = &(vecA[(midx + 1) * CONV_PARAM::stride]);
                    const float* vecAA2 = &(vecA[(midx + 2) * CONV_PARAM::stride]);
                    const float* vecAA3 = &(vecA[(midx + 3) * CONV_PARAM::stride]);
                    vecC[midx] += vecAA0[0] * vecBB[0] + vecAA0[1] * vecBB[1] + vecAA0[2] * vecBB[2] +
                                  vecAA0[3] * vecBB[3] + vecAA0[4] * vecBB[4];
                    vecC[midx + 1] += vecAA1[0] * vecBB[0] + vecAA1[1] * vecBB[1] + vecAA1[2] * vecBB[2] +
                                      vecAA1[3] * vecBB[3] + vecAA1[4] * vecBB[4];
                    vecC[midx + 2] += vecAA2[0] * vecBB[0] + vecAA2[1] * vecBB[1] + vecAA2[2] * vecBB[2] +
                                      vecAA2[3] * vecBB[3] + vecAA2[4] * vecBB[4];
                    vecC[midx + 3] += vecAA3[0] * vecBB[0] + vecAA3[1] * vecBB[1] + vecAA3[2] * vecBB[2] +
                                      vecAA3[3] * vecBB[3] + vecAA3[4] * vecBB[4];
                }

                for (; midx < output_len; midx++)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    vecC[midx] += vecAA[0] * vecBB[0] + vecAA[1] * vecBB[1] + vecAA[2] * vecBB[2] +
                                  vecAA[3] * vecBB[3] + vecAA[4] * vecBB[4];
                }
            }
            for (int midx = 0; midx < output_len; midx++)
            {
                vecC[midx] += conv1d_bias[jidx];
                vecC[midx] = cal_hard_swish_relu_c(vecC[midx]);
            }
        }
    }

    template <class POOL_PARAM>
    int avgpool1d_c(float* input, float* output)
    {
        const int Lout = (POOL_PARAM::Lin + 2 * POOL_PARAM::padding - POOL_PARAM::kernel_size) / POOL_PARAM::stride + 1;
        const float invscale = 1.0f / POOL_PARAM::kernel_size;
        std::vector<float> presum(POOL_PARAM::Lin + 1, 0);
        for (int i = 0; i < POOL_PARAM::Ch; i++)
        {
            float* vecA = &(input[i * POOL_PARAM::Lin]);
            float* vecC = &(output[i * Lout]);
            presum.assign(POOL_PARAM::Lin + 1, 0);
            float sum = 0;
            for (int j = 0; j < POOL_PARAM::Lin; j++)
            {
                sum += vecA[j];
                presum[j + 1] = sum;
            }
            int idx = 0;
            for (int j = POOL_PARAM::kernel_size; j <= POOL_PARAM::Lin; j += POOL_PARAM::stride)
            {
                vecC[idx++] = (presum[j] - presum[j - POOL_PARAM::kernel_size]) * invscale;
            }
            assert(idx == Lout);
        }
        return Lout;
    }
};

}

#endif // VIPER_MODULES_LIPSYNC_OP_C_H_
