//
//  lipsync op --- sse3 version
//
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef VIPER_MODULES_LIPSYNC_OP_SSE3_H_
#define VIPER_MODULES_LIPSYNC_OP_SSE3_H_

#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <cstring>

#if (defined(WEBRTC_ARCH_ARM_NEON) || defined(__ARM_NEON__))
#include "sse2neon.h"
#else
#include <pmmintrin.h>
#include <xmmintrin.h>
#endif

namespace viper
{
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#endif

class LipsyncOperation_SSE3
{
public:
    inline float sigmoid_sse3(float x)
    {
        return 1.0f / (1.0f + expf(-x));
    }

    inline float cal_leaky_relu_sse3(float val, float gamma)
    {
        return MAX(0, val) + gamma * MIN(0, val);
    }

    inline float cal_hard_swish_relu_sse3(float val)
    {
        return val * MAX(0, MIN(6, val + 3)) / 6;
    }

    inline float cal_bn_sse3(float val, float mean, float gamma, float varsq, float betta)
    {
        return gamma * (val - mean) / sqrtf(varsq + 0.00001f) + betta;
    }

    float __sum_m128(__m128 x)
    {
        __m128 temp_sum;
        temp_sum = _mm_hadd_ps(x, x);
        temp_sum = _mm_hadd_ps(temp_sum, temp_sum);
        return _mm_cvtss_f32(temp_sum);
    }

    template <class FC_PARAM>
    void linear_withskip_sse3(float* input, float* output, const float** fc_par, bool is_transpose)
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
    void linear_withskip_notrans_sse3(float* input, float* output, const float** fc_par)
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
                for (; k + 11 < FC_PARAM::in_nodes; k = k + 12)
                {
                    __m128 xmm_A0 = _mm_loadu_ps(&vecA[k]);
                    __m128 xmm_A1 = _mm_loadu_ps(&vecA[k + 4]);
                    __m128 xmm_A2 = _mm_loadu_ps(&vecA[k + 8]);

                    __m128 xmm_B0 = _mm_loadu_ps(&vecB[k]);
                    __m128 xmm_B1 = _mm_loadu_ps(&vecB[k + 4]);
                    __m128 xmm_B2 = _mm_loadu_ps(&vecB[k + 8]);

                    xmm_B0 = _mm_mul_ps(xmm_B0, xmm_A0);
                    xmm_B1 = _mm_mul_ps(xmm_B1, xmm_A1);
                    xmm_B2 = _mm_mul_ps(xmm_B2, xmm_A2);

                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B1);
                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B2);

                    vecC[j] += __sum_m128(xmm_B0);
                }

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB[k];
                }
            }
        }
    }

    template <class FC_PARAM>
    void linear_withskip_dotrans_sse3(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];
        assert(FC_PARAM::in_nodes == FC_PARAM::o_nodes);
        memset(output, 0, sizeof(float) * FC_PARAM::o_nodes * FC_PARAM::n_ch); // checked safe

        for (int i = 0; i < FC_PARAM::o_nodes; i++)
        {
            const float* vecA = &(linear_weights[i * FC_PARAM::in_nodes]);
            float* vecC = &(output[i * FC_PARAM::n_ch]);
            int j = 0;
            for (; j + 3 < FC_PARAM::in_nodes; j += 4)
            {
                float* vecB0 = &(input[j * FC_PARAM::n_ch]);
                float* vecB1 = &(input[(j + 1) * FC_PARAM::n_ch]);
                float* vecB2 = &(input[(j + 2) * FC_PARAM::n_ch]);
                float* vecB3 = &(input[(j + 3) * FC_PARAM::n_ch]);
                int k = 0;
                __m128 xmm_A0 = _mm_set_ps1(vecA[j]);
                __m128 xmm_A1 = _mm_set_ps1(vecA[j + 1]);
                __m128 xmm_A2 = _mm_set_ps1(vecA[j + 2]);
                __m128 xmm_A3 = _mm_set_ps1(vecA[j + 3]);
                for (; k + 3 < FC_PARAM::n_ch; k += 4)
                {
                    __m128 xmm_B0 = _mm_loadu_ps(&vecB0[k]);
                    __m128 xmm_B1 = _mm_loadu_ps(&vecB1[k]);
                    __m128 xmm_B2 = _mm_loadu_ps(&vecB2[k]);
                    __m128 xmm_B3 = _mm_loadu_ps(&vecB3[k]);

                    __m128 xmm_C = _mm_loadu_ps(&vecC[k]);

                    xmm_B0 = _mm_mul_ps(xmm_B0, xmm_A0);
                    xmm_B1 = _mm_mul_ps(xmm_B1, xmm_A1);
                    xmm_B2 = _mm_mul_ps(xmm_B2, xmm_A2);
                    xmm_B3 = _mm_mul_ps(xmm_B3, xmm_A3);

                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B1);
                    xmm_B2 = _mm_add_ps(xmm_B2, xmm_B3);
                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B2);
                    xmm_C = _mm_add_ps(xmm_C, xmm_B0);

                    _mm_storeu_ps(&vecC[k], xmm_C);
                }
                for (; k < FC_PARAM::n_ch; k++)
                {
                    vecC[k] += vecA[j] * vecB0[k];
                    vecC[k] += vecA[j + 1] * vecB1[k];
                    vecC[k] += vecA[j + 2] * vecB2[k];
                    vecC[k] += vecA[j + 3] * vecB3[k];
                }
            }
            for (; j < FC_PARAM::in_nodes; j++)
            {
                float* vecB = &(input[j * FC_PARAM::n_ch]);
                int k = 0;
                for (; k < FC_PARAM::n_ch; k++)
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
    void linear_softmax_sse3(float* input, float* output, const float** fc_par)
    {
        const float* linear_weights = fc_par[0];
        const float* linear_bias = fc_par[1];

        for (int i = 0; i < FC_PARAM::n_ch; i++)
        {
            float* vecA = &(input[i * FC_PARAM::in_nodes]);
            // each element in vecC isn't init as 0, that's why we needed to store
            // results to float* temp_out, or nan will occur
            float* vecC = &(output[i * FC_PARAM::o_nodes]);
            std::vector<float> vecexp(FC_PARAM::o_nodes, 0);
            float sumexp = 0;
            int k = 0;

            for (int _idx = 0; _idx < 14; ++_idx)
                vecC[_idx] = linear_bias[_idx];

            for (; k + 15 < FC_PARAM::in_nodes; k += 16)
            {

                // load input nodes
                __m128 xmm_A0 = _mm_loadu_ps(&vecA[k]);
                __m128 xmm_A1 = _mm_loadu_ps(&vecA[k + 4]);
                __m128 xmm_A2 = _mm_loadu_ps(&vecA[k + 8]);
                __m128 xmm_A3 = _mm_loadu_ps(&vecA[k + 12]);

                int j = 0;
                for (; j < FC_PARAM::o_nodes; ++j)
                {

                    const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);

                    // load output nodes
                    __m128 xmm_B0 = _mm_loadu_ps(&vecB[k]);
                    __m128 xmm_B1 = _mm_loadu_ps(&vecB[k + 4]);
                    __m128 xmm_B2 = _mm_loadu_ps(&vecB[k + 8]);
                    __m128 xmm_B3 = _mm_loadu_ps(&vecB[k + 12]);

                    xmm_B0 = _mm_mul_ps(xmm_B0, xmm_A0);
                    xmm_B1 = _mm_mul_ps(xmm_B1, xmm_A1);
                    xmm_B2 = _mm_mul_ps(xmm_B2, xmm_A2);
                    xmm_B3 = _mm_mul_ps(xmm_B3, xmm_A3);

                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B1);
                    xmm_B2 = _mm_add_ps(xmm_B2, xmm_B3);
                    xmm_B0 = _mm_add_ps(xmm_B0, xmm_B2);

                    vecC[j] += __sum_m128(xmm_B0);
                }
            }

            for (; k < FC_PARAM::in_nodes; k++)
            {
                for (int j = 0; j < FC_PARAM::o_nodes; ++j)
                {
                    const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                    vecC[j] += vecA[k] * vecB[k];
                }
            }

            for (int j = 0; j < FC_PARAM::o_nodes; ++j)
            {
                vecexp[j] = expf(vecC[j]);
                sumexp += vecexp[j];
            }

            for (int j = 0; j < FC_PARAM::o_nodes; j++)
            {
                vecC[j] = vecexp[j] / sumexp;
            }
        }
    }

    template <class FC_PARAM>
    void linear_softmax_laugh_sse3(float* input, float* output, const float** fc_par)
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

    // just the linear function above with bn
    template <class FC_PARAM>
    void laughter_linear_hardswish_withskip_notrans_sse3(float* input, float* output, const float** fc_par)
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
            int j = 0;
            for (; j + 3 < FC_PARAM::o_nodes; j += 4)
            {
                const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);
                const float* vecB1 = &(linear_weights[(j + 1) * FC_PARAM::in_nodes]);
                const float* vecB2 = &(linear_weights[(j + 2) * FC_PARAM::in_nodes]);
                const float* vecB3 = &(linear_weights[(j + 3) * FC_PARAM::in_nodes]);

                __m128 xmm_bias = _mm_loadu_ps(&linear_bias[j]);
                _mm_storeu_ps(&vecC[j], xmm_bias);

                int k = 0;
                for (; k + 3 < FC_PARAM::in_nodes; k = k + 4)
                {
                    __m128 xmm_B = _mm_loadu_ps(&vecB[k]);
                    __m128 xmm_B1 = _mm_loadu_ps(&vecB1[k]);
                    __m128 xmm_B2 = _mm_loadu_ps(&vecB2[k]);
                    __m128 xmm_B3 = _mm_loadu_ps(&vecB3[k]);
                    __m128 xmm_vecA = _mm_loadu_ps(&vecA[k]);
                    __m128 xmm_vecC = _mm_loadu_ps(&vecC[j]);

                    xmm_B = _mm_mul_ps(xmm_B, xmm_vecA);
                    xmm_B1 = _mm_mul_ps(xmm_B1, xmm_vecA);
                    xmm_B2 = _mm_mul_ps(xmm_B2, xmm_vecA);
                    xmm_B3 = _mm_mul_ps(xmm_B3, xmm_vecA);

                    xmm_B = _mm_hadd_ps(xmm_B, xmm_B1);
                    xmm_B = _mm_hadd_ps(xmm_B, xmm_B); // vecC[j]'  vecC[j+1]' XX
                    xmm_B2 = _mm_hadd_ps(xmm_B2, xmm_B3);
                    xmm_B2 = _mm_hadd_ps(xmm_B2, xmm_B2); // vecC[j+2]'  vecC[j+3]' XX
                    xmm_B = _mm_shuffle_ps(xmm_B, xmm_B2, _MM_SHUFFLE(1, 0, 1, 0));
                    xmm_vecC = _mm_add_ps(xmm_B, xmm_vecC);
                    _mm_storeu_ps(&vecC[j], xmm_vecC);
                }

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB[k];
                    vecC[j + 1] += vecA[k] * vecB1[k];
                    vecC[j + 2] += vecA[k] * vecB2[k];
                    vecC[j + 3] += vecA[k] * vecB3[k];
                }
                vecC[j] =
                    cal_bn_sse3(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_sse3(vecC[j]);

                vecC[j + 1] = cal_bn_sse3(vecC[j + 1], linear_bn_mean[j + 1], linear_bn_gamma[j + 1],
                                          linear_bn_var[j + 1], linear_bn_betta[j + 1]);
                vecC[j + 1] = cal_hard_swish_relu_sse3(vecC[j + 1]);

                vecC[j + 2] = cal_bn_sse3(vecC[j + 2], linear_bn_mean[j + 2], linear_bn_gamma[j + 2],
                                          linear_bn_var[j + 2], linear_bn_betta[j + 2]);
                vecC[j + 2] = cal_hard_swish_relu_sse3(vecC[j + 2]);

                vecC[j + 3] = cal_bn_sse3(vecC[j + 3], linear_bn_mean[j + 3], linear_bn_gamma[j + 3],
                                          linear_bn_var[j + 3], linear_bn_betta[j + 3]);
                vecC[j + 3] = cal_hard_swish_relu_sse3(vecC[j + 3]);
            }
            for (; j < FC_PARAM::o_nodes; j++)
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
                    cal_bn_sse3(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_sse3(vecC[j]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz1_sse3(float* input, float* output, const float** conv1d_par)
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
                int kidx = 0;

                for (; kidx + 3 < CONV_PARAM::in_ch; kidx += 4)
                {
                    int midx = 0;
                    float* vecA0 = &(input[kidx * CONV_PARAM::in_phi]);
                    float* vecA1 = &(input[(kidx + 1) * CONV_PARAM::in_phi]);
                    float* vecA2 = &(input[(kidx + 2) * CONV_PARAM::in_phi]);
                    float* vecA3 = &(input[(kidx + 3) * CONV_PARAM::in_phi]);
                    for (; midx + 3 < output_len; midx += 4)
                    {
                        __m128 xmm_AA_0 = _mm_loadu_ps(
                            &(vecA0[midx * CONV_PARAM::stride])); // vecAA00[0] vecAA01[0] vecAA02[0] vecAA03[0]
                        __m128 xmm_AA_1 = _mm_loadu_ps(
                            &(vecA1[midx * CONV_PARAM::stride])); // vecAA10[0] vecAA11[0] vecAA12[0] vecAA13[0]
                        __m128 xmm_AA_2 = _mm_loadu_ps(
                            &(vecA2[midx * CONV_PARAM::stride])); // vecAA20[0] vecAA11[0] vecAA22[0] vecAA23[0]
                        __m128 xmm_AA_3 = _mm_loadu_ps(
                            &(vecA3[midx * CONV_PARAM::stride])); // vecAA30[0] vecAA31[0] vecAA32[0] vecAA33[0]

                        __m128 xmm_B = _mm_set_ps1(vecB[kidx]);       // vecB[kidx]
                        __m128 xmm_B_1 = _mm_set_ps1(vecB[kidx + 1]); // vecB[kidx+1]
                        __m128 xmm_B_2 = _mm_set_ps1(vecB[kidx + 2]); // vecB[kidx+2]
                        __m128 xmm_B_3 = _mm_set_ps1(vecB[kidx + 3]); // vecB[kidx+3]

                        __m128 xmm_vecC = _mm_loadu_ps(&vecC[midx]); // vecB[kidx+3]

                        xmm_AA_0 = _mm_mul_ps(xmm_AA_0, xmm_B);
                        xmm_AA_1 = _mm_mul_ps(xmm_AA_1, xmm_B_1);
                        xmm_AA_2 = _mm_mul_ps(xmm_AA_2, xmm_B_2);
                        xmm_AA_3 = _mm_mul_ps(xmm_AA_3, xmm_B_3);

                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_AA_1);
                        xmm_AA_2 = _mm_add_ps(xmm_AA_2, xmm_AA_3);
                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_AA_2);
                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_vecC);

                        _mm_storeu_ps(&vecC[midx], xmm_AA_0);
                    }
                    for (; midx < output_len; midx++)
                    {
                        float* vecAA0 = &(vecA0[midx * CONV_PARAM::stride]);
                        float* vecAA1 = &(vecA1[midx * CONV_PARAM::stride]);
                        float* vecAA2 = &(vecA2[midx * CONV_PARAM::stride]);
                        float* vecAA3 = &(vecA3[midx * CONV_PARAM::stride]);
                        vecC[midx] += vecAA0[0] * vecB[kidx];
                        vecC[midx] += vecAA1[0] * vecB[kidx + 1];
                        vecC[midx] += vecAA2[0] * vecB[kidx + 2];
                        vecC[midx] += vecAA3[0] * vecB[kidx + 3];
                    }
                }
                for (; kidx < CONV_PARAM::in_ch; kidx++)
                {
                    int midx = 0;
                    float* vecA0 = &(input[kidx * CONV_PARAM::in_phi]);
                    for (; midx < output_len; midx++)
                    {
                        float* vecAA0 = &(vecA0[midx * CONV_PARAM::stride]);
                        vecC[midx] += vecAA0[0] * vecB[kidx];
                    }
                }

                for (int midx = 0; midx < output_len; midx++)
                {
                    vecC[midx] += conv1d_bias[jidx];
                    vecC[midx] = cal_bn_sse3(vecC[midx], conv1d_bn_mean[midx], conv1d_bn_gamma[midx],
                                             conv1d_bn_var[midx], conv1d_bn_betta[midx]);
                    vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
                }
            }
        }
        else
        {
            printf("CONV_PARAM::kernel_size must be 1 !!!");
            //exit(0);
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_sse3(float* input, float* output, const float** conv1d_par)
    {
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
                    vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
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
                    vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
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
    void conv1d_bn_hardswish_ksz3_sse3(float* input, float* output, const float** conv1d_par)
    {
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
                int midx = 0;
                __m128 xmm_BB_0 = _mm_set_ps1(vecBB[0]);
                __m128 xmm_BB_1 = _mm_set_ps1(vecBB[1]);
                __m128 xmm_BB_2 = _mm_set_ps1(vecBB[2]);
                for (; midx + 3 < output_len; midx += 4)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    __m128 xmm_AA_0 = _mm_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m128 xmm_AA_1 = _mm_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m128 xmm_AA_2 = _mm_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    __m128 xmm_C = _mm_loadu_ps(&vecC[midx]);

                    xmm_AA_0 = _mm_mul_ps(xmm_AA_0, xmm_BB_0);
                    xmm_AA_1 = _mm_mul_ps(xmm_AA_1, xmm_BB_1);
                    xmm_AA_2 = _mm_mul_ps(xmm_AA_2, xmm_BB_2);

                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_0);
                    xmm_AA_1 = _mm_add_ps(xmm_AA_1, xmm_AA_2);
                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_1);
                    _mm_storeu_ps(&vecC[midx], xmm_C);
                }
                for (; midx < output_len; midx++)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    vecC[midx] += vecAA[0] * vecBB[0] + vecAA[1] * vecBB[1] + vecAA[2] * vecBB[2];
                }
            }
            for (int midx = 0; midx < output_len; midx++)
            {
                vecC[midx] += conv1d_bias[jidx];
                vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_sse3(float* input, float* output, const float** conv1d_par)
    {
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;
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
                __m128 vecBBx4 = _mm_loadu_ps(vecBB);       // vecBB[0] vecBB[1] vecBB[2] vecBB[3]
                __m128 vecBBx4_b = _mm_loadu_ps(vecBB + 1); // vecBB[1] vecBB[2] vecBB[3] vecBB[4]
                vecBBx4_b = _mm_shuffle_ps(vecBBx4_b, vecBBx4_b,
                                           _MM_SHUFFLE(3, 3, 3, 3)); // vecBB[4] vecBB[4] vecBB[4] vecBB[4]
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    const float* vecAA0 = &(vecA[midx * CONV_PARAM::stride]);
                    const float* vecAA1 = &(vecA[(midx + 1) * CONV_PARAM::stride]);
                    const float* vecAA2 = &(vecA[(midx + 2) * CONV_PARAM::stride]);
                    const float* vecAA3 = &(vecA[(midx + 3) * CONV_PARAM::stride]);

                    __m128 vecAA0x4 = _mm_loadu_ps(vecAA0);
                    __m128 vecAA1x4 = _mm_loadu_ps(vecAA1);
                    __m128 vecAA2x4 = _mm_loadu_ps(vecAA2);
                    __m128 vecAA3x4 = _mm_loadu_ps(vecAA3);

                    __m128 tmpx4 = _mm_mul_ps(vecAA0x4, vecBBx4);  // D0 C0 B0 A0
                    __m128 tmp1x4 = _mm_mul_ps(vecAA1x4, vecBBx4); // D1 C1 B1 A1
                    __m128 tmp2x4 = _mm_mul_ps(vecAA2x4, vecBBx4); // D2 C2 B2 A2
                    __m128 tmp3x4 = _mm_mul_ps(vecAA3x4, vecBBx4); // D3 C3 B3 A3

                    // D1+C1 B1+A1
                    tmpx4 = _mm_hadd_ps(tmpx4, tmp1x4);   // D1+C1 B1+A1 D0+C0 B0+A0
                    tmp2x4 = _mm_hadd_ps(tmp2x4, tmp3x4); // D3+C3 B3+A3 D2+C2 B1+A1
                    tmpx4 = _mm_hadd_ps(tmpx4, tmp2x4);   // D3+C3+B3+A3 D2+C2+B1+A1 D1+C1+B1+A1 D0+C0+B0+A0

                    vecAA0x4 = _mm_loadu_ps(vecAA0 + 1); // vecAA0[4] vecAA0[3] XX XX
                    vecAA1x4 = _mm_loadu_ps(vecAA1 + 1); // vecAA1[4] vecAA1[3] XX XX
                    vecAA2x4 = _mm_loadu_ps(vecAA2 + 1); // vecAA2[4] vecAA2[3] XX XX
                    vecAA3x4 = _mm_loadu_ps(vecAA3 + 1); // vecAA3[4] vecAA3[3] XX XX

                    vecAA0x4 = _mm_shuffle_ps(vecAA0x4, vecAA1x4,
                                              _MM_SHUFFLE(3, 3, 3, 3)); // vecAA1[4] vecAA1[4] vecAA0[4] vecAA0[4]
                    vecAA2x4 = _mm_shuffle_ps(vecAA2x4, vecAA3x4,
                                              _MM_SHUFFLE(3, 3, 3, 3)); // vecAA3[4] vecAA3[4] vecAA2[4] vecAA2[4]
                    vecAA2x4 = _mm_shuffle_ps(vecAA0x4, vecAA2x4,
                                              _MM_SHUFFLE(3, 1, 3, 1)); // vecAA3[4] vecAA2[4] vecAA1[4] vecAA0[4]

                    vecAA2x4 = _mm_mul_ps(vecBBx4_b, vecAA2x4);

                    __m128 vecCx4 = _mm_loadu_ps(vecC + midx);
                    tmpx4 = _mm_add_ps(vecAA2x4, tmpx4);
                    tmpx4 = _mm_add_ps(vecCx4, tmpx4);
                    _mm_storeu_ps(vecC + midx, tmpx4);

                    //                    vecC[midx] +=
                    //                        vecAA0[0] * vecBB[0] + vecAA0[1] * vecBB[1] + vecAA0[2] * vecBB[2] +
                    //                        vecAA0[3] * vecBB[3]
                    //                    + vecAA0[4] * vecBB[4];
                    //                    vecC[midx+1] +=
                    //                        vecAA1[0] * vecBB[0] + vecAA1[1] * vecBB[1] + vecAA1[2] * vecBB[2] +
                    //                        vecAA1[3] * vecBB[3]
                    //                    + vecAA1[4] * vecBB[4];
                    //                    vecC[midx+2] +=
                    //                        vecAA2[0] * vecBB[0] + vecAA2[1] * vecBB[1] + vecAA2[2] * vecBB[2] +
                    //                        vecAA2[3] * vecBB[3]
                    //                    + vecAA2[4] * vecBB[4];
                    //                    vecC[midx+3] +=
                    //                        vecAA3[0] * vecBB[0] + vecAA3[1] * vecBB[1] + vecAA3[2] * vecBB[2] +
                    //                        vecAA3[3] * vecBB[3]
                    //                    + vecAA3[4] * vecBB[4];
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
                vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride1_sse3(float* input, float* output, const float** conv1d_par)
    {
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;
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
                __m128 xmm_BB_0 = _mm_set_ps1(vecBB[0]);
                __m128 xmm_BB_1 = _mm_set_ps1(vecBB[1]);
                __m128 xmm_BB_2 = _mm_set_ps1(vecBB[2]);
                __m128 xmm_BB_3 = _mm_set_ps1(vecBB[3]);
                __m128 xmm_BB_4 = _mm_set_ps1(vecBB[4]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    __m128 xmm_AA_0 = _mm_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m128 xmm_AA_1 = _mm_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m128 xmm_AA_2 = _mm_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    __m128 xmm_AA_3 = _mm_loadu_ps(&(vecA[(midx + 3) * CONV_PARAM::stride]));
                    __m128 xmm_AA_4 = _mm_loadu_ps(&(vecA[(midx + 4) * CONV_PARAM::stride]));
                    __m128 xmm_C = _mm_loadu_ps(&vecC[midx]);

                    xmm_AA_0 = _mm_mul_ps(xmm_AA_0, xmm_BB_0);
                    xmm_AA_1 = _mm_mul_ps(xmm_AA_1, xmm_BB_1);
                    xmm_AA_2 = _mm_mul_ps(xmm_AA_2, xmm_BB_2);
                    xmm_AA_3 = _mm_mul_ps(xmm_AA_3, xmm_BB_3);
                    xmm_AA_4 = _mm_mul_ps(xmm_AA_4, xmm_BB_4);

                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_0);
                    xmm_AA_1 = _mm_add_ps(xmm_AA_1, xmm_AA_2);
                    xmm_AA_3 = _mm_add_ps(xmm_AA_3, xmm_AA_4);
                    xmm_AA_1 = _mm_add_ps(xmm_AA_1, xmm_AA_3);
                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_1);
                    _mm_storeu_ps(&vecC[midx], xmm_C);

                    //                    vecC[midx] +=
                    //                        vecAA0[0] * vecBB[0] + vecAA0[1] * vecBB[1] + vecAA0[2] * vecBB[2] +
                    //                        vecAA0[3] * vecBB[3]
                    //                    + vecAA0[4] * vecBB[4];
                    //                    vecC[midx+1] +=
                    //                        vecAA1[0] * vecBB[0] + vecAA1[1] * vecBB[1] + vecAA1[2] * vecBB[2] +
                    //                        vecAA1[3] * vecBB[3]
                    //                    + vecAA1[4] * vecBB[4];
                    //                    vecC[midx+2] +=
                    //                        vecAA2[0] * vecBB[0] + vecAA2[1] * vecBB[1] + vecAA2[2] * vecBB[2] +
                    //                        vecAA2[3] * vecBB[3]
                    //                    + vecAA2[4] * vecBB[4];
                    //                    vecC[midx+3] +=
                    //                        vecAA3[0] * vecBB[0] + vecAA3[1] * vecBB[1] + vecAA3[2] * vecBB[2] +
                    //                        vecAA3[3] * vecBB[3]
                    //                    + vecAA3[4] * vecBB[4];
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
                vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride2_sse3(float* input, float* output, const float** conv1d_par)
    {
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride + 1;
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
                __m128 xmm_BB_0 = _mm_set_ps1(vecBB[0]);
                __m128 xmm_BB_1 = _mm_set_ps1(vecBB[1]);
                __m128 xmm_BB_2 = _mm_set_ps1(vecBB[2]);
                __m128 xmm_BB_3 = _mm_set_ps1(vecBB[3]);
                __m128 xmm_BB_4 = _mm_set_ps1(vecBB[4]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    __m128 xmm_AA_0 = _mm_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m128 xmm_AA_1 = _mm_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m128 xmm_AA_2 = _mm_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    __m128 xmm_AA_3 = _mm_loadu_ps(&(vecA[(midx + 3) * CONV_PARAM::stride]));
                    __m128 xmm_AA_4 = _mm_loadu_ps(&(vecA[(midx + 4) * CONV_PARAM::stride]));

                    __m128 xmm_input_v0 = _mm_shuffle_ps(xmm_AA_0, xmm_AA_2, 0x88); // 10001000 = 2,0 2,0
                    __m128 xmm_input_v1 = _mm_shuffle_ps(xmm_AA_0, xmm_AA_2, 0xdd); // 11011101 = 3,1,3,1
                    __m128 xmm_input_v2 = _mm_shuffle_ps(xmm_AA_1, xmm_AA_3, 0x88);
                    __m128 xmm_input_v3 = _mm_shuffle_ps(xmm_AA_1, xmm_AA_3, 0xdd);
                    __m128 xmm_input_v4 = _mm_shuffle_ps(xmm_AA_2, xmm_AA_4, 0x88);

                    __m128 xmm_C = _mm_loadu_ps(&vecC[midx]);

                    xmm_AA_0 = _mm_mul_ps(xmm_input_v0, xmm_BB_0);
                    xmm_AA_1 = _mm_mul_ps(xmm_input_v1, xmm_BB_1);
                    xmm_AA_2 = _mm_mul_ps(xmm_input_v2, xmm_BB_2);
                    xmm_AA_3 = _mm_mul_ps(xmm_input_v3, xmm_BB_3);
                    xmm_AA_4 = _mm_mul_ps(xmm_input_v4, xmm_BB_4);

                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_0);
                    xmm_AA_1 = _mm_add_ps(xmm_AA_1, xmm_AA_2);
                    xmm_AA_3 = _mm_add_ps(xmm_AA_3, xmm_AA_4);
                    xmm_AA_1 = _mm_add_ps(xmm_AA_1, xmm_AA_3);
                    xmm_C = _mm_add_ps(xmm_C, xmm_AA_1);
                    _mm_storeu_ps(&vecC[midx], xmm_C);
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
                vecC[midx] = cal_hard_swish_relu_sse3(vecC[midx]);
            }
        }
    }

    template <class POOL_PARAM>
    int avgpool1d_sse3(float* input, float* output)
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

#endif // VIPER_MODULES_LIPSYNC_OP_SSE3_H_
