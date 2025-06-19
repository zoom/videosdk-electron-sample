//
//  nn_op.hpp
//  lipSync_test
//
//  Created by Tao Yao on 4/14/22.
//  Copyright © 2022 Key Zhu. All rights reserved.
//
// lipsync_nn: includes all neural network layer function implementations and API, such as conv or fc layers

// assignee: Rocky
// todo: add, remove, and modify these api functions that are used by lipsync_model accordingly by referring to the
// pytorch model forward pipeline

#ifndef VIPER_MODULES_LIPSYNC_OP_NEON_H_
#define VIPER_MODULES_LIPSYNC_OP_NEON_H_

#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <vector>

#if defined(WEBRTC_TARGET_WIN_ARM64) || defined(WEBRTC_TARGET_MAC_ARM64) || defined(WEBRTC_TARGET_ANDROID_ARM32) ||    \
    defined(WEBRTC_TARGET_ANDROID_ARM64) || defined(WEBRTC_TARGET_IOS_ARM64) || defined(WEBRTC_TARGET_LINUX_ARM32) || defined(WEBRTC_TARGET_LINUX_ARM64)
#include <arm_neon.h>
#include <string.h>
#endif

namespace viper
{
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#endif

class LipsyncOperation_NEON
{
public:
    inline float sigmoid_neon(float x)
    {
        return 1.0f / (1.0f + expf(-x));
    }

    inline float cal_leaky_relu_neon(float val, float gamma)
    {
        return MAX(0, val) + gamma * MIN(0, val);
    }

    inline float cal_hard_swish_relu_neon(float val)
    {
        return val * MAX(0, MIN(6, val + 3)) / 6;
    }

    inline float cal_bn_neon(float val, float mean, float gamma, float varsq, float betta)
    {
        return gamma * (val - mean) / sqrtf(varsq + 0.00001f) + betta;
    }

    template <class FC_PARAM>
    void linear_withskip_neon(float* input, float* output, const float** fc_par, bool is_transpose)
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
    void linear_withskip_notrans_neon(float* input, float* output, const float** fc_par)
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
                for (; k < FC_PARAM::in_nodes - 11; k = k + 12)
                {
                    float32x4_t A0 = vld1q_f32((float*)&vecA[k]);
                    float32x4_t A1 = vld1q_f32((float*)&vecA[k + 4]);
                    float32x4_t A2 = vld1q_f32((float*)&vecA[k + 8]);

                    float32x4_t B0 = vld1q_f32((float*)&vecB[k]);
                    float32x4_t B1 = vld1q_f32((float*)&vecB[k + 4]);
                    float32x4_t B2 = vld1q_f32((float*)&vecB[k + 8]);

                    B0 = vmulq_f32(B0, A0);
                    B1 = vmulq_f32(B1, A1);
                    B2 = vmulq_f32(B2, A2);

                    B0 = vaddq_f32(B0, B1);
                    B0 = vaddq_f32(B0, B2);

                    float32x2_t B = vadd_f32(vget_low_f32(B0), vget_high_f32(B0));
                    B = vpadd_f32(B, B);
                    vecC[j] += vget_lane_f32(B, 0);
                }

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB[k];
                }
            }
        }
    }

    template <class FC_PARAM>
    void linear_withskip_dotrans_neon(float* input, float* output, const float** fc_par)
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
                float32x4_t A0 = vdupq_n_f32(vecA[j]);
                float32x4_t A1 = vdupq_n_f32(vecA[j + 1]);
                float32x4_t A2 = vdupq_n_f32(vecA[j + 2]);
                float32x4_t A3 = vdupq_n_f32(vecA[j + 3]);
                for (; k + 3 < FC_PARAM::n_ch; k += 4)
                {
                    float32x4_t C = vld1q_f32((float*)&vecC[k]);
                    float32x4_t B0 = vld1q_f32((float*)&vecB0[k]);
                    float32x4_t B1 = vld1q_f32((float*)&vecB1[k]);
                    float32x4_t B2 = vld1q_f32((float*)&vecB2[k]);
                    float32x4_t B3 = vld1q_f32((float*)&vecB3[k]);

                    C = vmlaq_f32(C, B0, A0);
                    C = vmlaq_f32(C, B1, A1);
                    C = vmlaq_f32(C, B2, A2);
                    C = vmlaq_f32(C, B3, A3);

                    vst1q_f32((float*)&vecC[k], C);
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
    void linear_softmax_neon(float* input, float* output, const float** fc_par)
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
                float32x4_t A0 = vld1q_f32((float*)&vecA[k]);
                float32x4_t A1 = vld1q_f32((float*)&vecA[k + 4]);
                float32x4_t A2 = vld1q_f32((float*)&vecA[k + 8]);
                float32x4_t A3 = vld1q_f32((float*)&vecA[k + 12]);

                int j = 0;
                for (; j < FC_PARAM::o_nodes; ++j)
                {
                    const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);

                    // load output nodes
                    float32x4_t B0 = vld1q_f32((float*)&vecB[k]);
                    float32x4_t B1 = vld1q_f32((float*)&vecB[k + 4]);
                    float32x4_t B2 = vld1q_f32((float*)&vecB[k + 8]);
                    float32x4_t B3 = vld1q_f32((float*)&vecB[k + 12]);

                    B0 = vmulq_f32(B0, A0);
                    B1 = vmulq_f32(B1, A1);
                    B2 = vmulq_f32(B2, A2);
                    B3 = vmulq_f32(B3, A3);

                    B0 = vaddq_f32(B0, B1);
                    B2 = vaddq_f32(B2, B3);
                    B0 = vaddq_f32(B0, B2);

                    float32x2_t B = vadd_f32(vget_low_f32(B0), vget_high_f32(B0));
                    B = vpadd_f32(B, B);
                    vecC[j] += vget_lane_f32(B, 0);
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
    void linear_softmax_laugh_neon(float* input, float* output, const float** fc_par)
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
    void laughter_linear_hardswish_withskip_notrans_neon(float* input, float* output, const float** fc_par)
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
                const float* vecB0 = &(linear_weights[j * FC_PARAM::in_nodes]);
                const float* vecB1 = &(linear_weights[(j + 1) * FC_PARAM::in_nodes]);
                const float* vecB2 = &(linear_weights[(j + 2) * FC_PARAM::in_nodes]);
                const float* vecB3 = &(linear_weights[(j + 3) * FC_PARAM::in_nodes]);

                float32x4_t c = vld1q_f32((float*)&linear_bias[j]);

                int k = 0;
                float32x4_t sum_v0 = vdupq_n_f32(0);
                float32x4_t sum_v1 = vdupq_n_f32(0);
                float32x4_t sum_v2 = vdupq_n_f32(0);
                float32x4_t sum_v3 = vdupq_n_f32(0);
                for (; k + 3 < FC_PARAM::in_nodes; k += 4)
                {
                    float32x4_t q_vecA = vld1q_f32((float*)&vecA[k]);
                    float32x4_t B0 = vld1q_f32((float*)&vecB0[k]);
                    float32x4_t B1 = vld1q_f32((float*)&vecB1[k]);
                    float32x4_t B2 = vld1q_f32((float*)&vecB2[k]);
                    float32x4_t B3 = vld1q_f32((float*)&vecB3[k]);

                    B0 = vmulq_f32(B0, q_vecA);
                    B1 = vmulq_f32(B1, q_vecA);
                    B2 = vmulq_f32(B2, q_vecA);
                    B3 = vmulq_f32(B3, q_vecA);

                    float32x4x2_t ROW01 = vtrnq_f32(B0, B1);
                    float32x4x2_t ROW23 = vtrnq_f32(B2, B3);
                    B0 = vcombine_f32(vget_low_f32(ROW01.val[0]), vget_low_f32(ROW23.val[0]));
                    B1 = vcombine_f32(vget_low_f32(ROW01.val[1]), vget_low_f32(ROW23.val[1]));
                    B2 = vcombine_f32(vget_high_f32(ROW01.val[0]), vget_high_f32(ROW23.val[0]));
                    B3 = vcombine_f32(vget_high_f32(ROW01.val[1]), vget_high_f32(ROW23.val[1]));

                    B0 = vaddq_f32(B0, B1);
                    B2 = vaddq_f32(B2, B3);
                    B0 = vaddq_f32(B0, B2);
                    c = vaddq_f32(c, B0);
                }
                vst1q_f32((float*)&vecC[j], c);

                for (; k < FC_PARAM::in_nodes; k++)
                {
                    vecC[j] += vecA[k] * vecB0[k];
                    vecC[j + 1] += vecA[k] * vecB1[k];
                    vecC[j + 2] += vecA[k] * vecB2[k];
                    vecC[j + 3] += vecA[k] * vecB3[k];
                }
                vecC[j] =
                    cal_bn_neon(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_neon(vecC[j]);

                vecC[j + 1] = cal_bn_neon(vecC[j + 1], linear_bn_mean[j + 1], linear_bn_gamma[j + 1],
                                          linear_bn_var[j + 1], linear_bn_betta[j + 1]);
                vecC[j + 1] = cal_hard_swish_relu_neon(vecC[j + 1]);

                vecC[j + 2] = cal_bn_neon(vecC[j + 2], linear_bn_mean[j + 2], linear_bn_gamma[j + 2],
                                          linear_bn_var[j + 2], linear_bn_betta[j + 2]);
                vecC[j + 2] = cal_hard_swish_relu_neon(vecC[j + 2]);

                vecC[j + 3] = cal_bn_neon(vecC[j + 3], linear_bn_mean[j + 3], linear_bn_gamma[j + 3],
                                          linear_bn_var[j + 3], linear_bn_betta[j + 3]);
                vecC[j + 3] = cal_hard_swish_relu_neon(vecC[j + 3]);
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
                    cal_bn_neon(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_neon(vecC[j]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz1_neon(float* input, float* output, const float** conv1d_par)
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
                    float32x4_t B = vdupq_n_f32(vecB[kidx]);       // vecB[kidx]
                    float32x4_t B_1 = vdupq_n_f32(vecB[kidx + 1]); // vecB[kidx+1]
                    float32x4_t B_2 = vdupq_n_f32(vecB[kidx + 2]); // vecB[kidx+2]
                    float32x4_t B_3 = vdupq_n_f32(vecB[kidx + 3]); // vecB[kidx+3]
                    for (; midx < output_len - 3; midx += 4)
                    {
                        float32x4_t q_vecC = vld1q_f32((float*)&vecC[midx]); // vecB[kidx+3]
                        float32x4_t AA_0 = vld1q_f32(
                            (float*)&(vecA0[midx * CONV_PARAM::stride])); // vecAA00[0] vecAA01[0] vecAA02[0] vecAA03[0]
                        float32x4_t AA_1 = vld1q_f32(
                            (float*)&(vecA1[midx * CONV_PARAM::stride])); // vecAA10[0] vecAA11[0] vecAA12[0] vecAA13[0]
                        float32x4_t AA_2 = vld1q_f32(
                            (float*)&(vecA2[midx * CONV_PARAM::stride])); // vecAA20[0] vecAA11[0] vecAA22[0] vecAA23[0]
                        float32x4_t AA_3 = vld1q_f32(
                            (float*)&(vecA3[midx * CONV_PARAM::stride])); // vecAA30[0] vecAA31[0] vecAA32[0] vecAA33[0]

                        q_vecC = vmlaq_f32(q_vecC, AA_0, B);
                        q_vecC = vmlaq_f32(q_vecC, AA_1, B_1);
                        q_vecC = vmlaq_f32(q_vecC, AA_2, B_2);
                        q_vecC = vmlaq_f32(q_vecC, AA_3, B_3);

                        vst1q_f32((float*)&vecC[midx], q_vecC);
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
                    vecC[midx] = cal_bn_neon(vecC[midx], conv1d_bn_mean[midx], conv1d_bn_gamma[midx],
                                             conv1d_bn_var[midx], conv1d_bn_betta[midx]);
                    vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
                }
            }
        }
        else
        {
            printf("CONV_PARAM::kernel_size must be 1 !!!");
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_neon(float* input, float* output, const float** conv1d_par)
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
                    vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
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
                    vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
                }
            }
        }
        else
        {
            printf("CONV_PARAM::kernel_size must be 3 or 5 !!!");
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz3_neon(float* input, float* output, const float** conv1d_par)
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
                float32x4_t BB_0 = vdupq_n_f32(vecBB[0]);
                float32x4_t BB_1 = vdupq_n_f32(vecBB[1]);
                float32x4_t BB_2 = vdupq_n_f32(vecBB[2]);
                for (; midx + 3 < output_len; midx += 4)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    float32x4_t C = vld1q_f32((float*)&vecC[midx]);
                    float32x4_t AA_0 = vld1q_f32((float*)&(vecA[midx * CONV_PARAM::stride]));
                    float32x4_t AA_1 = vld1q_f32((float*)&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    float32x4_t AA_2 = vld1q_f32((float*)&(vecA[(midx + 2) * CONV_PARAM::stride]));

                    C = vmlaq_f32(C, AA_0, BB_0);
                    C = vmlaq_f32(C, AA_1, BB_1);
                    C = vmlaq_f32(C, AA_2, BB_2);

                    vst1q_f32((float*)&vecC[midx], C);
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
                vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride1_neon(float* input, float* output, const float** conv1d_par)
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
                float32x4_t BB_0 = vdupq_n_f32(vecBB[0]);
                float32x4_t BB_1 = vdupq_n_f32(vecBB[1]);
                float32x4_t BB_2 = vdupq_n_f32(vecBB[2]);
                float32x4_t BB_3 = vdupq_n_f32(vecBB[3]);
                float32x4_t BB_4 = vdupq_n_f32(vecBB[4]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    float32x4_t C = vld1q_f32((float*)&vecC[midx]);
                    float32x4_t AA_0 = vld1q_f32((float*)&(vecA[midx * CONV_PARAM::stride]));
                    float32x4_t AA_1 = vld1q_f32((float*)&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    float32x4_t AA_2 = vld1q_f32((float*)&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    float32x4_t AA_3 = vld1q_f32((float*)&(vecA[(midx + 3) * CONV_PARAM::stride]));
                    float32x4_t AA_4 = vld1q_f32((float*)&(vecA[(midx + 4) * CONV_PARAM::stride]));

                    C = vmlaq_f32(C, AA_0, BB_0);
                    C = vmlaq_f32(C, AA_1, BB_1);
                    C = vmlaq_f32(C, AA_2, BB_2);
                    C = vmlaq_f32(C, AA_3, BB_3);
                    C = vmlaq_f32(C, AA_4, BB_4);

                    vst1q_f32((float*)&vecC[midx], C);
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
                vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride2_neon(float* input, float* output, const float** conv1d_par)
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
                float32x4_t BB_0 = vdupq_n_f32(vecBB[0]);
                float32x4_t BB_1 = vdupq_n_f32(vecBB[1]);
                float32x4_t BB_2 = vdupq_n_f32(vecBB[2]);
                float32x4_t BB_3 = vdupq_n_f32(vecBB[3]);
                float32x4_t BB_4 = vdupq_n_f32(vecBB[4]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    float32x4_t C = vld1q_f32(&vecC[midx]);
                    float32x4x2_t AA_0 = vld2q_f32((float*)&(vecA[midx * CONV_PARAM::stride])); // 0 2 4 6 -- 1 3 5 7
                    float32x4x2_t AA_1 =
                        vld2q_f32((float*)&(vecA[(midx + 1) * CONV_PARAM::stride])); // 2 4 6 8 -- 3 5 7 9
                    float32x4x2_t AA_2 =
                        vld2q_f32((float*)&(vecA[(midx + 2) * CONV_PARAM::stride])); // 4 6 8 10-- 5 7 9 11
                    // float32x4x2_t AA_3 = vld2q_f32((float*)&(vecA[(midx + 3) * CONV_PARAM::stride]));  // 6 8 10 12
                    // -- 7 9 11 13 float32x4x2_t AA_4 = vld2q_f32((float*)&(vecA[(midx + 4) * CONV_PARAM::stride])); //
                    // 8 10 12 14 -- 9 11 13 14

                    C = vmlaq_f32(C, AA_0.val[0], BB_0);
                    C = vmlaq_f32(C, AA_0.val[1], BB_1);
                    C = vmlaq_f32(C, AA_1.val[0], BB_2);
                    C = vmlaq_f32(C, AA_1.val[1], BB_3);
                    C = vmlaq_f32(C, AA_2.val[0], BB_4);

                    vst1q_f32((float*)&vecC[midx], C);
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
                vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride3_neon(float* input, float* output, const float** conv1d_par)
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
                float32x4_t BB_0 = vdupq_n_f32(vecBB[0]);
                float32x4_t BB_1 = vdupq_n_f32(vecBB[1]);
                float32x4_t BB_2 = vdupq_n_f32(vecBB[2]);
                float32x4_t BB_3 = vdupq_n_f32(vecBB[3]);
                float32x4_t BB_4 = vdupq_n_f32(vecBB[4]);
                int midx = 0;
                for (; midx + 3 < output_len; midx = midx + 4)
                {
                    float32x4_t C = vld1q_f32(&vecC[midx]);
                    float32x4x3_t AA_0 =
                        vld3q_f32((float*)&(vecA[midx * CONV_PARAM::stride])); // 0 3 6 9 -- 1 4 7 10 -- 2 5 8 11
                    float32x4x3_t AA_1 = vld3q_f32((float*)&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    /*float32x4x3_t AA_2 = vld3q_f32((float*)&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    float32x4x3_t AA_3 = vld3q_f32((float*)&(vecA[(midx + 3) * CONV_PARAM::stride]));
                    float32x4x3_t AA_4 = vld3q_f32((float*)&(vecA[(midx + 4) * CONV_PARAM::stride]));*/

                    C = vmlaq_f32(C, AA_0.val[0], BB_0);
                    C = vmlaq_f32(C, AA_0.val[1], BB_1);
                    C = vmlaq_f32(C, AA_0.val[2], BB_2);
                    C = vmlaq_f32(C, AA_1.val[0], BB_3);
                    C = vmlaq_f32(C, AA_1.val[1], BB_4);

                    vst1q_f32((float*)&vecC[midx], C);
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
                vecC[midx] = cal_hard_swish_relu_neon(vecC[midx]);
            }
        }
    }

    template <class POOL_PARAM>
    int avgpool1d_neon(float* input, float* output)
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

#endif // VIPER_MODULES_LIPSYNC_OP_NEON_H_
