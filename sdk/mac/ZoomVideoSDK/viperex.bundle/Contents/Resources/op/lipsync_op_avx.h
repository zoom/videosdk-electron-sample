//
//  lipsync op --- avx version
//
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef VIPER_MODULES_LIPSYNC_OP_AVX_H_
#define VIPER_MODULES_LIPSYNC_OP_AVX_H_

#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <immintrin.h>

namespace viper
{
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#endif

class LipsyncOperation_AVX
{
public:
    inline float sigmoid_avx(float x)
    {
        return 1.0f / (1.0f + expf(-x));
    }

    inline float cal_leaky_relu_avx(float val, float gamma)
    {
        return MAX(0, val) + gamma * MIN(0, val);
    }

    inline float cal_hard_swish_relu_avx(float val)
    {
        return val * MAX(0, MIN(6, val + 3)) / 6;
    }

    inline float cal_bn_avx(float val, float mean, float gamma, float varsq, float betta)
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

    float __sum_m256(__m256 x)
    {
        __m128 hi = _mm256_extractf128_ps(x, 1);
        __m128 lo = _mm256_extractf128_ps(x, 0);
        lo = _mm_add_ps(hi, lo);
        hi = _mm_movehl_ps(hi, lo);
        lo = _mm_add_ps(hi, lo);
        hi = _mm_shuffle_ps(lo, lo, 1);
        lo = _mm_add_ss(hi, lo);
        return _mm_cvtss_f32(lo);
    }

    template <class FC_PARAM>
    void linear_withskip_avx(float* input, float* output, const float** fc_par, bool is_transpose)
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
    void linear_withskip_notrans_avx(float* input, float* output, const float** fc_par)
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

                __m256 xmm256_A = _mm256_loadu_ps(&vecA[0]);
                __m256 xmm256_B = _mm256_loadu_ps(&vecB[0]);
                xmm256_B = _mm256_mul_ps(xmm256_B, xmm256_A);

                __m128 xmm128_A = _mm_loadu_ps(&vecA[8]);
                __m128 xmm128_B = _mm_loadu_ps(&vecB[8]);
                xmm128_B = _mm_mul_ps(xmm128_B, xmm128_A);

                vecC[j] += (vecA[12] * vecB[12] + __sum_m128(xmm128_B) + __sum_m256(xmm256_B));
            }
        }
    }

    template <class FC_PARAM>
    void linear_withskip_dotrans_avx(float* input, float* output, const float** fc_par)
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
            for (; j + 7 < FC_PARAM::in_nodes; j += 8)
            {
                float* vecB0 = &(input[j * FC_PARAM::n_ch]);
                float* vecB1 = &(input[(j + 1) * FC_PARAM::n_ch]);
                float* vecB2 = &(input[(j + 2) * FC_PARAM::n_ch]);
                float* vecB3 = &(input[(j + 3) * FC_PARAM::n_ch]);
                float* vecB4 = &(input[(j + 4) * FC_PARAM::n_ch]);
                float* vecB5 = &(input[(j + 5) * FC_PARAM::n_ch]);
                float* vecB6 = &(input[(j + 6) * FC_PARAM::n_ch]);
                float* vecB7 = &(input[(j + 7) * FC_PARAM::n_ch]);
                int k = 0;

                __m256 ymm256_A0 =
                    _mm256_set_ps(vecA[j], vecA[j], vecA[j], vecA[j], vecA[j], vecA[j], vecA[j], vecA[j]);
                __m256 ymm256_A1 = _mm256_set_ps(vecA[j + 1], vecA[j + 1], vecA[j + 1], vecA[j + 1], vecA[j + 1],
                                                 vecA[j + 1], vecA[j + 1], vecA[j + 1]);
                __m256 ymm256_A2 = _mm256_set_ps(vecA[j + 2], vecA[j + 2], vecA[j + 2], vecA[j + 2], vecA[j + 2],
                                                 vecA[j + 2], vecA[j + 2], vecA[j + 2]);
                __m256 ymm256_A3 = _mm256_set_ps(vecA[j + 3], vecA[j + 3], vecA[j + 3], vecA[j + 3], vecA[j + 3],
                                                 vecA[j + 3], vecA[j + 3], vecA[j + 3]);
                __m256 ymm256_A4 = _mm256_set_ps(vecA[j + 4], vecA[j + 4], vecA[j + 4], vecA[j + 4], vecA[j + 4],
                                                 vecA[j + 4], vecA[j + 4], vecA[j + 4]);
                __m256 ymm256_A5 = _mm256_set_ps(vecA[j + 5], vecA[j + 5], vecA[j + 5], vecA[j + 5], vecA[j + 5],
                                                 vecA[j + 5], vecA[j + 5], vecA[j + 5]);
                __m256 ymm256_A6 = _mm256_set_ps(vecA[j + 6], vecA[j + 6], vecA[j + 6], vecA[j + 6], vecA[j + 6],
                                                 vecA[j + 6], vecA[j + 6], vecA[j + 6]);
                __m256 ymm256_A7 = _mm256_set_ps(vecA[j + 7], vecA[j + 7], vecA[j + 7], vecA[j + 7], vecA[j + 7],
                                                 vecA[j + 7], vecA[j + 7], vecA[j + 7]);
                for (; k + 7 < FC_PARAM::n_ch; k += 8)
                {
                    __m256 ymm256_B0 = _mm256_loadu_ps(&vecB0[k]);
                    __m256 ymm256_B1 = _mm256_loadu_ps(&vecB1[k]);
                    __m256 ymm256_B2 = _mm256_loadu_ps(&vecB2[k]);
                    __m256 ymm256_B3 = _mm256_loadu_ps(&vecB3[k]);
                    __m256 ymm256_B4 = _mm256_loadu_ps(&vecB4[k]);
                    __m256 ymm256_B5 = _mm256_loadu_ps(&vecB5[k]);
                    __m256 ymm256_B6 = _mm256_loadu_ps(&vecB6[k]);
                    __m256 ymm256_B7 = _mm256_loadu_ps(&vecB7[k]);

                    __m256 ymm256_C = _mm256_loadu_ps(&vecC[k]);

                    ymm256_B0 = _mm256_mul_ps(ymm256_B0, ymm256_A0);
                    ymm256_B1 = _mm256_mul_ps(ymm256_B1, ymm256_A1);
                    ymm256_B2 = _mm256_mul_ps(ymm256_B2, ymm256_A2);
                    ymm256_B3 = _mm256_mul_ps(ymm256_B3, ymm256_A3);
                    ymm256_B4 = _mm256_mul_ps(ymm256_B4, ymm256_A4);
                    ymm256_B5 = _mm256_mul_ps(ymm256_B5, ymm256_A5);
                    ymm256_B6 = _mm256_mul_ps(ymm256_B6, ymm256_A6);
                    ymm256_B7 = _mm256_mul_ps(ymm256_B7, ymm256_A7);

                    ymm256_B0 = _mm256_add_ps(ymm256_B0, ymm256_B1);
                    ymm256_B2 = _mm256_add_ps(ymm256_B2, ymm256_B3);
                    ymm256_B4 = _mm256_add_ps(ymm256_B4, ymm256_B5);
                    ymm256_B6 = _mm256_add_ps(ymm256_B6, ymm256_B7);
                    ymm256_B0 = _mm256_add_ps(ymm256_B0, ymm256_B2);
                    ymm256_B4 = _mm256_add_ps(ymm256_B4, ymm256_B6);
                    ymm256_B0 = _mm256_add_ps(ymm256_B0, ymm256_B4);
                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_B0);

                    _mm256_storeu_ps(&vecC[k], ymm256_C);
                }
                for (; k < FC_PARAM::n_ch; k++)
                {
                    vecC[k] += vecA[j] * vecB0[k];
                    vecC[k] += vecA[j + 1] * vecB1[k];
                    vecC[k] += vecA[j + 2] * vecB2[k];
                    vecC[k] += vecA[j + 3] * vecB3[k];
                    vecC[k] += vecA[j + 4] * vecB4[k];
                    vecC[k] += vecA[j + 5] * vecB5[k];
                    vecC[k] += vecA[j + 6] * vecB6[k];
                    vecC[k] += vecA[j + 7] * vecB7[k];
                }
            }
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
    void linear_softmax_avx(float* input, float* output, const float** fc_par)
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

            for (; k + 31 < FC_PARAM::in_nodes; k += 32)
            {

                // load input nodes
                __m256 xmm_A0 = _mm256_loadu_ps(&vecA[k]);
                __m256 xmm_A1 = _mm256_loadu_ps(&vecA[k + 8]);
                __m256 xmm_A2 = _mm256_loadu_ps(&vecA[k + 16]);
                __m256 xmm_A3 = _mm256_loadu_ps(&vecA[k + 24]);

                int j = 0;
                for (; j < FC_PARAM::o_nodes; ++j)
                {

                    const float* vecB = &(linear_weights[j * FC_PARAM::in_nodes]);

                    // load output nodes
                    __m256 xmm_B0 = _mm256_loadu_ps(&vecB[k]);
                    __m256 xmm_B1 = _mm256_loadu_ps(&vecB[k + 8]);
                    __m256 xmm_B2 = _mm256_loadu_ps(&vecB[k + 16]);
                    __m256 xmm_B3 = _mm256_loadu_ps(&vecB[k + 24]);

                    xmm_B0 = _mm256_mul_ps(xmm_B0, xmm_A0);
                    xmm_B1 = _mm256_mul_ps(xmm_B1, xmm_A1);
                    xmm_B2 = _mm256_mul_ps(xmm_B2, xmm_A2);
                    xmm_B3 = _mm256_mul_ps(xmm_B3, xmm_A3);

                    xmm_B0 = _mm256_add_ps(xmm_B0, xmm_B1);
                    xmm_B2 = _mm256_add_ps(xmm_B2, xmm_B3);
                    xmm_B0 = _mm256_add_ps(xmm_B0, xmm_B2);

                    vecC[j] += __sum_m256(xmm_B0);
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
    void linear_softmax_laugh_avx(float* input, float* output, const float** fc_par)
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
    void laughter_linear_hardswish_withskip_notrans_avx(float* input, float* output, const float** fc_par)
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
                    cal_bn_avx(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_avx(vecC[j]);

                vecC[j + 1] = cal_bn_avx(vecC[j + 1], linear_bn_mean[j + 1], linear_bn_gamma[j + 1],
                                         linear_bn_var[j + 1], linear_bn_betta[j + 1]);
                vecC[j + 1] = cal_hard_swish_relu_avx(vecC[j + 1]);

                vecC[j + 2] = cal_bn_avx(vecC[j + 2], linear_bn_mean[j + 2], linear_bn_gamma[j + 2],
                                         linear_bn_var[j + 2], linear_bn_betta[j + 2]);
                vecC[j + 2] = cal_hard_swish_relu_avx(vecC[j + 2]);

                vecC[j + 3] = cal_bn_avx(vecC[j + 3], linear_bn_mean[j + 3], linear_bn_gamma[j + 3],
                                         linear_bn_var[j + 3], linear_bn_betta[j + 3]);
                vecC[j + 3] = cal_hard_swish_relu_avx(vecC[j + 3]);
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
                    cal_bn_avx(vecC[j], linear_bn_mean[j], linear_bn_gamma[j], linear_bn_var[j], linear_bn_betta[j]);
                vecC[j] = cal_hard_swish_relu_avx(vecC[j]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_laughter_avx(float* input, float* output, const float** conv1d_par)
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

                for (; kidx + 7 < CONV_PARAM::in_ch; kidx += 8)
                {
                    int midx = 0;
                    for (; midx + 7 < output_len; midx += 8)
                    {
                        float* vecA0 = &(input[kidx * CONV_PARAM::in_phi]);
                        float* vecA1 = &(input[(kidx + 1) * CONV_PARAM::in_phi]);
                        float* vecA2 = &(input[(kidx + 2) * CONV_PARAM::in_phi]);
                        float* vecA3 = &(input[(kidx + 3) * CONV_PARAM::in_phi]);
                        float* vecA4 = &(input[(kidx + 4) * CONV_PARAM::in_phi]);
                        float* vecA5 = &(input[(kidx + 5) * CONV_PARAM::in_phi]);
                        float* vecA6 = &(input[(kidx + 6) * CONV_PARAM::in_phi]);
                        float* vecA7 = &(input[(kidx + 7) * CONV_PARAM::in_phi]);

                        float* vecAA00 = &(vecA0[midx * CONV_PARAM::stride]);
                        float* vecAA10 = &(vecA1[midx * CONV_PARAM::stride]);
                        float* vecAA20 = &(vecA2[midx * CONV_PARAM::stride]);
                        float* vecAA30 = &(vecA3[midx * CONV_PARAM::stride]);
                        float* vecAA40 = &(vecA4[midx * CONV_PARAM::stride]);
                        float* vecAA50 = &(vecA5[midx * CONV_PARAM::stride]);
                        float* vecAA60 = &(vecA6[midx * CONV_PARAM::stride]);
                        float* vecAA70 = &(vecA7[midx * CONV_PARAM::stride]);

                        __m256 ymm256_vecAA_0 = _mm256_loadu_ps(vecAA00);
                        __m256 ymm256_vecAA_1 = _mm256_loadu_ps(vecAA10);
                        __m256 ymm256_vecAA_2 = _mm256_loadu_ps(vecAA20);
                        __m256 ymm256_vecAA_3 = _mm256_loadu_ps(vecAA30);
                        __m256 ymm256_vecAA_4 = _mm256_loadu_ps(vecAA40);
                        __m256 ymm256_vecAA_5 = _mm256_loadu_ps(vecAA50);
                        __m256 ymm256_vecAA_6 = _mm256_loadu_ps(vecAA60);
                        __m256 ymm256_vecAA_7 = _mm256_loadu_ps(vecAA70);

                        __m256 ymm256_BB_0 = _mm256_set_ps(vecB[kidx], vecB[kidx], vecB[kidx], vecB[kidx], vecB[kidx],
                                                           vecB[kidx], vecB[kidx], vecB[kidx]);
                        __m256 ymm256_BB_1 =
                            _mm256_set_ps(vecB[kidx + 1], vecB[kidx + 1], vecB[kidx + 1], vecB[kidx + 1],
                                          vecB[kidx + 1], vecB[kidx + 1], vecB[kidx + 1], vecB[kidx + 1]);
                        __m256 ymm256_BB_2 =
                            _mm256_set_ps(vecB[kidx + 2], vecB[kidx + 2], vecB[kidx + 2], vecB[kidx + 2],
                                          vecB[kidx + 2], vecB[kidx + 2], vecB[kidx + 2], vecB[kidx + 2]);
                        __m256 ymm256_BB_3 =
                            _mm256_set_ps(vecB[kidx + 3], vecB[kidx + 3], vecB[kidx + 3], vecB[kidx + 3],
                                          vecB[kidx + 3], vecB[kidx + 3], vecB[kidx + 3], vecB[kidx + 3]);
                        __m256 ymm256_BB_4 =
                            _mm256_set_ps(vecB[kidx + 4], vecB[kidx + 4], vecB[kidx + 4], vecB[kidx + 4],
                                          vecB[kidx + 4], vecB[kidx + 4], vecB[kidx + 4], vecB[kidx + 4]);
                        __m256 ymm256_BB_5 =
                            _mm256_set_ps(vecB[kidx + 5], vecB[kidx + 5], vecB[kidx + 5], vecB[kidx + 5],
                                          vecB[kidx + 5], vecB[kidx + 5], vecB[kidx + 5], vecB[kidx + 5]);
                        __m256 ymm256_BB_6 =
                            _mm256_set_ps(vecB[kidx + 6], vecB[kidx + 6], vecB[kidx + 6], vecB[kidx + 6],
                                          vecB[kidx + 6], vecB[kidx + 6], vecB[kidx + 6], vecB[kidx + 6]);
                        __m256 ymm256_BB_7 =
                            _mm256_set_ps(vecB[kidx + 7], vecB[kidx + 7], vecB[kidx + 7], vecB[kidx + 7],
                                          vecB[kidx + 7], vecB[kidx + 7], vecB[kidx + 7], vecB[kidx + 7]);

                        __m256 ymm256_vecC = _mm256_loadu_ps(&vecC[midx]);

                        ymm256_vecAA_0 = _mm256_mul_ps(ymm256_vecAA_0, ymm256_BB_0);
                        ymm256_vecAA_1 = _mm256_mul_ps(ymm256_vecAA_1, ymm256_BB_1);
                        ymm256_vecAA_2 = _mm256_mul_ps(ymm256_vecAA_2, ymm256_BB_2);
                        ymm256_vecAA_3 = _mm256_mul_ps(ymm256_vecAA_3, ymm256_BB_3);
                        ymm256_vecAA_4 = _mm256_mul_ps(ymm256_vecAA_4, ymm256_BB_4);
                        ymm256_vecAA_5 = _mm256_mul_ps(ymm256_vecAA_5, ymm256_BB_5);
                        ymm256_vecAA_6 = _mm256_mul_ps(ymm256_vecAA_6, ymm256_BB_6);
                        ymm256_vecAA_7 = _mm256_mul_ps(ymm256_vecAA_7, ymm256_BB_7);

                        ymm256_vecAA_0 = _mm256_add_ps(ymm256_vecAA_0, ymm256_vecAA_1);
                        ymm256_vecAA_2 = _mm256_add_ps(ymm256_vecAA_2, ymm256_vecAA_3);
                        ymm256_vecAA_4 = _mm256_add_ps(ymm256_vecAA_4, ymm256_vecAA_5);
                        ymm256_vecAA_6 = _mm256_add_ps(ymm256_vecAA_6, ymm256_vecAA_7);

                        ymm256_vecAA_0 = _mm256_add_ps(ymm256_vecAA_0, ymm256_vecAA_2);
                        ymm256_vecAA_4 = _mm256_add_ps(ymm256_vecAA_4, ymm256_vecAA_6);

                        ymm256_vecAA_0 = _mm256_add_ps(ymm256_vecAA_0, ymm256_vecAA_4);

                        ymm256_vecC = _mm256_add_ps(ymm256_vecAA_0, ymm256_vecC);

                        _mm256_storeu_ps(&vecC[midx], ymm256_vecC);
                    }

                    for (; midx + 3 < output_len; midx += 4)
                    {
                        float* vecA0 = &(input[kidx * CONV_PARAM::in_phi]);
                        float* vecA1 = &(input[(kidx + 1) * CONV_PARAM::in_phi]);
                        float* vecA2 = &(input[(kidx + 2) * CONV_PARAM::in_phi]);
                        float* vecA3 = &(input[(kidx + 3) * CONV_PARAM::in_phi]);
                        float* vecA4 = &(input[(kidx + 4) * CONV_PARAM::in_phi]);
                        float* vecA5 = &(input[(kidx + 5) * CONV_PARAM::in_phi]);
                        float* vecA6 = &(input[(kidx + 6) * CONV_PARAM::in_phi]);
                        float* vecA7 = &(input[(kidx + 7) * CONV_PARAM::in_phi]);

                        __m128 xmm_AA_0 = _mm_loadu_ps(
                            &(vecA0[midx * CONV_PARAM::stride])); // vecAA00[0] vecAA01[0] vecAA02[0] vecAA03[0]
                        __m128 xmm_AA_1 = _mm_loadu_ps(
                            &(vecA1[midx * CONV_PARAM::stride])); // vecAA10[0] vecAA11[0] vecAA12[0] vecAA13[0]
                        __m128 xmm_AA_2 = _mm_loadu_ps(
                            &(vecA2[midx * CONV_PARAM::stride])); // vecAA20[0] vecAA11[0] vecAA22[0] vecAA23[0]
                        __m128 xmm_AA_3 = _mm_loadu_ps(
                            &(vecA3[midx * CONV_PARAM::stride])); // vecAA30[0] vecAA31[0] vecAA32[0] vecAA33[0]
                        __m128 xmm_AA_4 = _mm_loadu_ps(
                            &(vecA4[midx * CONV_PARAM::stride])); // vecAA00[0] vecAA01[0] vecAA02[0] vecAA03[0]
                        __m128 xmm_AA_5 = _mm_loadu_ps(
                            &(vecA5[midx * CONV_PARAM::stride])); // vecAA10[0] vecAA11[0] vecAA12[0] vecAA13[0]
                        __m128 xmm_AA_6 = _mm_loadu_ps(
                            &(vecA6[midx * CONV_PARAM::stride])); // vecAA20[0] vecAA11[0] vecAA22[0] vecAA23[0]
                        __m128 xmm_AA_7 = _mm_loadu_ps(
                            &(vecA7[midx * CONV_PARAM::stride])); // vecAA30[0] vecAA31[0] vecAA32[0] vecAA33[0]

                        __m128 xmm_B = _mm_set_ps1(vecB[kidx]);       // vecB[kidx]
                        __m128 xmm_B_1 = _mm_set_ps1(vecB[kidx + 1]); // vecB[kidx+1]
                        __m128 xmm_B_2 = _mm_set_ps1(vecB[kidx + 2]); // vecB[kidx+2]
                        __m128 xmm_B_3 = _mm_set_ps1(vecB[kidx + 3]); // vecB[kidx+3]
                        __m128 xmm_B_4 = _mm_set_ps1(vecB[kidx + 4]); // vecB[kidx+4]
                        __m128 xmm_B_5 = _mm_set_ps1(vecB[kidx + 5]); // vecB[kidx+5]
                        __m128 xmm_B_6 = _mm_set_ps1(vecB[kidx + 6]); // vecB[kidx+6]
                        __m128 xmm_B_7 = _mm_set_ps1(vecB[kidx + 7]); // vecB[kidx+7]

                        __m128 xmm_vecC = _mm_loadu_ps(&vecC[midx]); // vecB[kidx+3]

                        xmm_AA_0 = _mm_mul_ps(xmm_AA_0, xmm_B);
                        xmm_AA_1 = _mm_mul_ps(xmm_AA_1, xmm_B_1);
                        xmm_AA_2 = _mm_mul_ps(xmm_AA_2, xmm_B_2);
                        xmm_AA_3 = _mm_mul_ps(xmm_AA_3, xmm_B_3);
                        xmm_AA_4 = _mm_mul_ps(xmm_AA_4, xmm_B_4);
                        xmm_AA_5 = _mm_mul_ps(xmm_AA_5, xmm_B_5);
                        xmm_AA_6 = _mm_mul_ps(xmm_AA_6, xmm_B_6);
                        xmm_AA_7 = _mm_mul_ps(xmm_AA_7, xmm_B_7);

                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_AA_1);
                        xmm_AA_2 = _mm_add_ps(xmm_AA_2, xmm_AA_3);
                        xmm_AA_4 = _mm_add_ps(xmm_AA_4, xmm_AA_5);
                        xmm_AA_6 = _mm_add_ps(xmm_AA_6, xmm_AA_7);

                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_AA_2);
                        xmm_AA_4 = _mm_add_ps(xmm_AA_4, xmm_AA_6);

                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_AA_4);
                        xmm_AA_0 = _mm_add_ps(xmm_AA_0, xmm_vecC);

                        _mm_storeu_ps(&vecC[midx], xmm_AA_0);
                    }
                    for (; midx < output_len; midx++)
                    {
                        float* vecA0 = &(input[kidx * CONV_PARAM::in_phi]);
                        float* vecA1 = &(input[(kidx + 1) * CONV_PARAM::in_phi]);
                        float* vecA2 = &(input[(kidx + 2) * CONV_PARAM::in_phi]);
                        float* vecA3 = &(input[(kidx + 3) * CONV_PARAM::in_phi]);
                        float* vecA4 = &(input[(kidx + 4) * CONV_PARAM::in_phi]);
                        float* vecA5 = &(input[(kidx + 5) * CONV_PARAM::in_phi]);
                        float* vecA6 = &(input[(kidx + 6) * CONV_PARAM::in_phi]);
                        float* vecA7 = &(input[(kidx + 7) * CONV_PARAM::in_phi]);

                        float* vecAA0 = &(vecA0[midx * CONV_PARAM::stride]);
                        float* vecAA1 = &(vecA1[midx * CONV_PARAM::stride]);
                        float* vecAA2 = &(vecA2[midx * CONV_PARAM::stride]);
                        float* vecAA3 = &(vecA3[midx * CONV_PARAM::stride]);
                        float* vecAA4 = &(vecA4[midx * CONV_PARAM::stride]);
                        float* vecAA5 = &(vecA5[midx * CONV_PARAM::stride]);
                        float* vecAA6 = &(vecA6[midx * CONV_PARAM::stride]);
                        float* vecAA7 = &(vecA7[midx * CONV_PARAM::stride]);

                        vecC[midx] += vecAA0[0] * vecB[kidx];
                        vecC[midx] += vecAA1[0] * vecB[kidx + 1];
                        vecC[midx] += vecAA2[0] * vecB[kidx + 2];
                        vecC[midx] += vecAA3[0] * vecB[kidx + 3];
                        vecC[midx] += vecAA4[0] * vecB[kidx + 4];
                        vecC[midx] += vecAA5[0] * vecB[kidx + 5];
                        vecC[midx] += vecAA6[0] * vecB[kidx + 6];
                        vecC[midx] += vecAA7[0] * vecB[kidx + 7];
                    }
                }

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
                    vecC[midx] = cal_bn_avx(vecC[midx], conv1d_bn_mean[midx], conv1d_bn_gamma[midx],
                                            conv1d_bn_var[midx], conv1d_bn_betta[midx]);
                    vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
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
    void conv1d_bn_hardswish_avx(float* input, float* output, const float** conv1d_par)
    {
        int dilation = 1;
        int output_len =
            (CONV_PARAM::in_phi + 2 * CONV_PARAM::padding_size - dilation * (CONV_PARAM::kernel_size - 1) - 1) /
                CONV_PARAM::stride +
            1;
        assert(CONV_PARAM::kernel_size == 3 || CONV_PARAM::kernel_size == 5);
        const float* conv1d_weights = conv1d_par[0];
        const float* conv1d_bias = conv1d_par[1];
        const float* conv1d_bn_gamma = conv1d_par[2];
        const float* conv1d_bn_betta = conv1d_par[3];
        const float* conv1d_bn_mean = conv1d_par[4];
        const float* conv1d_bn_varsq = conv1d_par[5];
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
                    vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
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
                    vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
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
    void conv1d_bn_hardswish_ksz3_avx(float* input, float* output, const float** conv1d_par)
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
                __m256 ymm256_BB_0 =
                    _mm256_set_ps(vecBB[0], vecBB[0], vecBB[0], vecBB[0], vecBB[0], vecBB[0], vecBB[0], vecBB[0]);
                __m256 ymm256_BB_1 =
                    _mm256_set_ps(vecBB[1], vecBB[1], vecBB[1], vecBB[1], vecBB[1], vecBB[1], vecBB[1], vecBB[1]);
                __m256 ymm256_BB_2 =
                    _mm256_set_ps(vecBB[2], vecBB[2], vecBB[2], vecBB[2], vecBB[2], vecBB[2], vecBB[2], vecBB[2]);
                int midx = 0;
                for (; midx + 7 < output_len; midx += 8)
                {
                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    float* vecAA_1 = &(vecA[(midx + 1) * CONV_PARAM::stride]);
                    float* vecAA_2 = &(vecA[(midx + 2) * CONV_PARAM::stride]);

                    __m256 ymm256_AA_0 = _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m256 ymm256_AA_1 = _mm256_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_2 = _mm256_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));

                    __m256 ymm256_C = _mm256_loadu_ps(&vecC[midx]);

                    ymm256_AA_0 = _mm256_mul_ps(ymm256_AA_0, ymm256_BB_0);
                    ymm256_AA_1 = _mm256_mul_ps(ymm256_AA_1, ymm256_BB_1);
                    ymm256_AA_2 = _mm256_mul_ps(ymm256_AA_2, ymm256_BB_2);

                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_0);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_2);
                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_1);
                    _mm256_storeu_ps(&vecC[midx], ymm256_C);
                }
                __m128 xmm_BB_0 = _mm_set_ps1(vecBB[0]);
                __m128 xmm_BB_1 = _mm_set_ps1(vecBB[1]);
                __m128 xmm_BB_2 = _mm_set_ps1(vecBB[2]);
                for (; midx + 3 < output_len; midx += 4)
                {
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
                vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
            }
        }
    }

    inline void transpose8_ps(__m256& row0, __m256& row1, __m256& row2, __m256& row3, __m256& row4, __m256& row5,
                              __m256& row6, __m256& row7)
    {
        __m256 __t0, __t1, __t2, __t3, __t4, __t5, __t6, __t7;
        __m256 __tt0, __tt1, __tt2, __tt3, __tt4, __tt5, __tt6, __tt7;
        __t0 = _mm256_unpacklo_ps(row0, row1);
        __t1 = _mm256_unpackhi_ps(row0, row1);
        __t2 = _mm256_unpacklo_ps(row2, row3);
        __t3 = _mm256_unpackhi_ps(row2, row3);
        __t4 = _mm256_unpacklo_ps(row4, row5);
        __t5 = _mm256_unpackhi_ps(row4, row5);
        __t6 = _mm256_unpacklo_ps(row6, row7);
        __t7 = _mm256_unpackhi_ps(row6, row7);
        __tt0 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(1, 0, 1, 0));
        __tt1 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(3, 2, 3, 2));
        __tt2 = _mm256_shuffle_ps(__t1, __t3, _MM_SHUFFLE(1, 0, 1, 0));
        __tt3 = _mm256_shuffle_ps(__t1, __t3, _MM_SHUFFLE(3, 2, 3, 2));
        __tt4 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(1, 0, 1, 0));
        __tt5 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(3, 2, 3, 2));
        __tt6 = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(1, 0, 1, 0));
        __tt7 = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(3, 2, 3, 2));
        row0 = _mm256_permute2f128_ps(__tt0, __tt4, 0x20);
        row1 = _mm256_permute2f128_ps(__tt1, __tt5, 0x20);
        row2 = _mm256_permute2f128_ps(__tt2, __tt6, 0x20);
        row3 = _mm256_permute2f128_ps(__tt3, __tt7, 0x20);
        row4 = _mm256_permute2f128_ps(__tt0, __tt4, 0x31);
        row5 = _mm256_permute2f128_ps(__tt1, __tt5, 0x31);
        row6 = _mm256_permute2f128_ps(__tt2, __tt6, 0x31);
        row7 = _mm256_permute2f128_ps(__tt3, __tt7, 0x31);
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_avx(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz5_c"<<std::endl;
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
                __m256 ymm256_BB = _mm256_loadu_ps(vecBB);
                int midx = 0;
                for (; midx + 7 < output_len; midx = midx + 8)
                {
                    const float* vecAA0 = &(vecA[midx * CONV_PARAM::stride]);
                    const float* vecAA1 = &(vecA[(midx + 1) * CONV_PARAM::stride]);
                    const float* vecAA2 = &(vecA[(midx + 2) * CONV_PARAM::stride]);
                    const float* vecAA3 = &(vecA[(midx + 3) * CONV_PARAM::stride]);
                    const float* vecAA4 = &(vecA[(midx + 4) * CONV_PARAM::stride]);
                    const float* vecAA5 = &(vecA[(midx + 5) * CONV_PARAM::stride]);
                    const float* vecAA6 = &(vecA[(midx + 6) * CONV_PARAM::stride]);
                    const float* vecAA7 = &(vecA[(midx + 7) * CONV_PARAM::stride]);
                    __m256 ymm256_vecAA0 = _mm256_loadu_ps(vecAA0);
                    __m256 ymm256_vecAA1 = _mm256_loadu_ps(vecAA1);
                    __m256 ymm256_vecAA2 = _mm256_loadu_ps(vecAA2);
                    __m256 ymm256_vecAA3 = _mm256_loadu_ps(vecAA3);
                    __m256 ymm256_vecAA4 = _mm256_loadu_ps(vecAA4);
                    __m256 ymm256_vecAA5 = _mm256_loadu_ps(vecAA5);
                    __m256 ymm256_vecAA6 = _mm256_loadu_ps(vecAA6);
                    __m256 ymm256_vecAA7 = _mm256_loadu_ps(vecAA7);

                    ymm256_vecAA0 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA0);
                    ymm256_vecAA1 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA1);
                    ymm256_vecAA2 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA2);
                    ymm256_vecAA3 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA3);
                    ymm256_vecAA4 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA4);
                    ymm256_vecAA5 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA5);
                    ymm256_vecAA6 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA6);
                    ymm256_vecAA7 = _mm256_mul_ps(ymm256_BB, ymm256_vecAA7);

                    transpose8_ps(ymm256_vecAA0, ymm256_vecAA1, ymm256_vecAA2, ymm256_vecAA3, ymm256_vecAA4,
                                  ymm256_vecAA5, ymm256_vecAA6, ymm256_vecAA7);
                    __m256 ymm256_vecC = _mm256_loadu_ps(&vecC[midx]);
                    ymm256_vecAA0 = _mm256_add_ps(
                        _mm256_add_ps(_mm256_add_ps(_mm256_add_ps(ymm256_vecAA0, ymm256_vecAA1), ymm256_vecAA2),
                                      ymm256_vecAA3),
                        ymm256_vecAA4);
                    ymm256_vecAA0 = _mm256_add_ps(ymm256_vecAA0, ymm256_vecC);

                    _mm256_storeu_ps(&vecC[midx], ymm256_vecAA0);
                }
                __m128 vecBBx4 = _mm_loadu_ps(vecBB);       // vecBB[0] vecBB[1] vecBB[2] vecBB[3]
                __m128 vecBBx4_b = _mm_loadu_ps(vecBB + 1); // vecBB[1] vecBB[2] vecBB[3] vecBB[4]
                vecBBx4_b = _mm_shuffle_ps(vecBBx4_b, vecBBx4_b,
                                           _MM_SHUFFLE(3, 3, 3, 3)); // vecBB[4] vecBB[4] vecBB[4] vecBB[4]
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
                vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride1_avx(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz5_c"<<std::endl;
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
                __m256 ymm256_BB_0 = _mm256_set1_ps(vecBB[0]);
                __m256 ymm256_BB_1 = _mm256_set1_ps(vecBB[1]);
                __m256 ymm256_BB_2 = _mm256_set1_ps(vecBB[2]);
                __m256 ymm256_BB_3 = _mm256_set1_ps(vecBB[3]);
                __m256 ymm256_BB_4 = _mm256_set1_ps(vecBB[4]);
                int midx = 0;
                for (; midx + 7 < output_len; midx = midx + 8)
                {

                    float* vecAA = &(vecA[midx * CONV_PARAM::stride]);
                    float* vecAA_1 = &(vecA[(midx + 1) * CONV_PARAM::stride]);
                    float* vecAA_2 = &(vecA[(midx + 2) * CONV_PARAM::stride]);

                    __m256 ymm256_AA_0 = _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m256 ymm256_AA_1 = _mm256_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_2 = _mm256_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_3 = _mm256_loadu_ps(&(vecA[(midx + 3) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_4 = _mm256_loadu_ps(&(vecA[(midx + 4) * CONV_PARAM::stride]));

                    __m256 ymm256_C = _mm256_loadu_ps(&vecC[midx]);

                    ymm256_AA_0 = _mm256_mul_ps(ymm256_AA_0, ymm256_BB_0);
                    ymm256_AA_1 = _mm256_mul_ps(ymm256_AA_1, ymm256_BB_1);
                    ymm256_AA_2 = _mm256_mul_ps(ymm256_AA_2, ymm256_BB_2);
                    ymm256_AA_3 = _mm256_mul_ps(ymm256_AA_3, ymm256_BB_3);
                    ymm256_AA_4 = _mm256_mul_ps(ymm256_AA_4, ymm256_BB_4);

                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_0);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_2);
                    ymm256_AA_3 = _mm256_add_ps(ymm256_AA_3, ymm256_AA_4);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_3);
                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_1);
                    _mm256_storeu_ps(&vecC[midx], ymm256_C);
                }
                __m128 vecBBx4 = _mm_loadu_ps(vecBB);       // vecBB[0] vecBB[1] vecBB[2] vecBB[3]
                __m128 vecBBx4_b = _mm_loadu_ps(vecBB + 1); // vecBB[1] vecBB[2] vecBB[3] vecBB[4]
                vecBBx4_b = _mm_shuffle_ps(vecBBx4_b, vecBBx4_b,
                                           _MM_SHUFFLE(3, 3, 3, 3)); // vecBB[4] vecBB[4] vecBB[4] vecBB[4]
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
                vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride2_avx(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz5_c"<<std::endl;
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
                __m256 ymm256_BB_0 = _mm256_set1_ps(vecBB[0]);
                __m256 ymm256_BB_1 = _mm256_set1_ps(vecBB[1]);
                __m256 ymm256_BB_2 = _mm256_set1_ps(vecBB[2]);
                __m256 ymm256_BB_3 = _mm256_set1_ps(vecBB[3]);
                __m256 ymm256_BB_4 = _mm256_set1_ps(vecBB[4]);
                int midx = 0;
                for (; midx + 7 < output_len; midx = midx + 8)
                {
                    // stride = 2
                    __m256 ymm256_AA_0 = _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride]));
                    __m256 ymm256_AA_1 = _mm256_loadu_ps(&(vecA[(midx + 4) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_2 = _mm256_loadu_ps(&(vecA[(midx + 1) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_3 = _mm256_loadu_ps(&(vecA[(midx + 5) * CONV_PARAM::stride]));

                    __m256 ymm_input11 = _mm256_permute2f128_ps(ymm256_AA_0, ymm256_AA_1, 0x20);
                    __m256 ymm_input12 = _mm256_permute2f128_ps(ymm256_AA_0, ymm256_AA_1, 0x31);
                    __m256 ymm_input13 = _mm256_permute2f128_ps(ymm256_AA_2, ymm256_AA_3, 0x20);
                    __m256 ymm_input14 = _mm256_permute2f128_ps(ymm256_AA_2, ymm256_AA_3, 0x31);

                    __m256 ymm_input_v0 = _mm256_shuffle_ps(ymm_input11, ymm_input12, 0x88);
                    __m256 ymm_input_v1 = _mm256_shuffle_ps(ymm_input11, ymm_input12, 0xdd);
                    __m256 ymm_input_v2 = _mm256_shuffle_ps(ymm_input13, ymm_input14, 0x88);
                    __m256 ymm_input_v3 = _mm256_shuffle_ps(ymm_input13, ymm_input14, 0xdd);

                    __m256 ymm256_AA_4 = _mm256_loadu_ps(&(vecA[(midx + 2) * CONV_PARAM::stride]));
                    __m256 ymm256_AA_5 = _mm256_loadu_ps(&(vecA[(midx + 6) * CONV_PARAM::stride]));
                    ymm_input11 = _mm256_permute2f128_ps(ymm256_AA_4, ymm256_AA_5, 0x20);
                    ymm_input12 = _mm256_permute2f128_ps(ymm256_AA_4, ymm256_AA_5, 0x31);
                    __m256 ymm_input_v4 = _mm256_shuffle_ps(ymm_input11, ymm_input12, 0x88);
                    __m256 ymm256_C = _mm256_loadu_ps(&vecC[midx]);

                    ymm256_AA_0 = _mm256_mul_ps(ymm_input_v0, ymm256_BB_0);
                    ymm256_AA_1 = _mm256_mul_ps(ymm_input_v1, ymm256_BB_1);
                    ymm256_AA_2 = _mm256_mul_ps(ymm_input_v2, ymm256_BB_2);
                    ymm256_AA_3 = _mm256_mul_ps(ymm_input_v3, ymm256_BB_3);
                    ymm256_AA_4 = _mm256_mul_ps(ymm_input_v4, ymm256_BB_4);

                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_0);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_2);
                    ymm256_AA_3 = _mm256_add_ps(ymm256_AA_3, ymm256_AA_4);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_3);
                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_1);
                    _mm256_storeu_ps(&vecC[midx], ymm256_C);
                }
                __m128 vecBBx4 = _mm_loadu_ps(vecBB);       // vecBB[0] vecBB[1] vecBB[2] vecBB[3]
                __m128 vecBBx4_b = _mm_loadu_ps(vecBB + 1); // vecBB[1] vecBB[2] vecBB[3] vecBB[4]
                vecBBx4_b = _mm_shuffle_ps(vecBBx4_b, vecBBx4_b,
                                           _MM_SHUFFLE(3, 3, 3, 3)); // vecBB[4] vecBB[4] vecBB[4] vecBB[4]
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
                vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
            }
        }
    }

    template <class CONV_PARAM>
    void conv1d_bn_hardswish_ksz5_stride3_avx(float* input, float* output, const float** conv1d_par)
    {
        // std::cout<<"BN_FOLDING: conv1d_bn_hardswish_ksz5_c"<<std::endl;
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
                __m256 ymm256_BB_0 = _mm256_set1_ps(vecBB[0]);
                __m256 ymm256_BB_1 = _mm256_set1_ps(vecBB[1]);
                __m256 ymm256_BB_2 = _mm256_set1_ps(vecBB[2]);
                __m256 ymm256_BB_3 = _mm256_set1_ps(vecBB[3]);
                __m256 ymm256_BB_4 = _mm256_set1_ps(vecBB[4]);
                int midx = 0;
                for (; midx + 7 < output_len; midx = midx + 8)
                {
                    // stride = 3
                    __m256 ymm256_AA_0 = _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride])); // 0,1,2,3,4,5,6,7
                    __m256 ymm256_AA_1 =
                        _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride + 8])); // 8,9,10,11,12,13,14,15
                    __m256 ymm256_AA_2 =
                        _mm256_loadu_ps(&(vecA[midx * CONV_PARAM::stride + 16])); // 16,17,18,19,20,21,22,23

                    __m256 ymm_03 = _mm256_permute2f128_ps(ymm256_AA_0, ymm256_AA_1, 0x30); // 0,1,2,3,12,13,14,15
                    __m256 ymm_14 = _mm256_permute2f128_ps(ymm256_AA_0, ymm256_AA_2, 0x21); // 4,5,6,7,16,17,18,19
                    __m256 ymm_25 = _mm256_permute2f128_ps(ymm256_AA_1, ymm256_AA_2, 0x30); // 8,9,10,11,20,21,22,23

                    __m256 ymm_xy = _mm256_shuffle_ps(ymm_14, ymm_25, _MM_SHUFFLE(2, 1, 3, 2)); // 6,7,9,10, 18,19,
                                                                                                // 21,22
                    __m256 ymm_yz = _mm256_shuffle_ps(ymm_03, ymm_14, _MM_SHUFFLE(1, 0, 2, 1)); // 1,2,4,5,13,14,16,17
                    __m256 ymm_input_v0 =
                        _mm256_shuffle_ps(ymm_03, ymm_xy, _MM_SHUFFLE(2, 0, 3, 0)); // 0,3,6,9,12,15,18,21
                    __m256 ymm_input_v1 =
                        _mm256_shuffle_ps(ymm_yz, ymm_xy, _MM_SHUFFLE(3, 1, 2, 0)); // 1,4,7,10,13,16,19,22
                    __m256 ymm_input_v2 =
                        _mm256_shuffle_ps(ymm_yz, ymm_25, _MM_SHUFFLE(3, 0, 3, 1)); // 2,5,8,11,14,17,20,23

                    __m256 ymm256_AA_3 = _mm256_set1_ps(vecA[midx * CONV_PARAM::stride + 24]); // 24,24...
                    __m256 ymm256_AA_4 = _mm256_set1_ps(vecA[midx * CONV_PARAM::stride + 25]); // 25,25...
                    __m256 t0 =
                        _mm256_permute_ps(ymm_input_v0, 0x39); // [x4  x7  x6  x5  x0  x3  x2  x1] 3,6,9,0,15,18,21,12
                    __m256 t1 =
                        _mm256_permute2f128_ps(t0, t0, 0x81); // [ 0   0   0   0  x4  x7  x6  x5] 15,18,21,12,0,0,0,0
                    __m256 y = _mm256_blend_ps(t0, t1, 0x88); // 3,6,9,12,15,18,21,0
                    __m256 ymm_input_v3 = _mm256_blend_ps(y, ymm256_AA_3, 0x80); // 3,6,9,12,15,18,21,24

                    t0 = _mm256_permute_ps(ymm_input_v1, 0x39); // [x4  x7  x6  x5  x0  x3  x2  x1] 4,7,10,1,16,19,22,13
                    t1 = _mm256_permute2f128_ps(t0, t0, 0x81);  // [ 0   0   0   0  x4  x7  x6  x5] 16,19,22,13,0,0,0,0
                    y = _mm256_blend_ps(t0, t1, 0x88);          // 4,7,10,13,16,19,22,0
                    __m256 ymm_input_v4 = _mm256_blend_ps(y, ymm256_AA_4, 0x80); // 4,7,10,13,16,19,22,25
                    __m256 ymm256_C = _mm256_loadu_ps(&vecC[midx]);

                    ymm256_AA_0 = _mm256_mul_ps(ymm_input_v0, ymm256_BB_0);
                    ymm256_AA_1 = _mm256_mul_ps(ymm_input_v1, ymm256_BB_1);
                    ymm256_AA_2 = _mm256_mul_ps(ymm_input_v2, ymm256_BB_2);
                    ymm256_AA_3 = _mm256_mul_ps(ymm_input_v3, ymm256_BB_3);
                    ymm256_AA_4 = _mm256_mul_ps(ymm_input_v4, ymm256_BB_4);

                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_0);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_2);
                    ymm256_AA_3 = _mm256_add_ps(ymm256_AA_3, ymm256_AA_4);
                    ymm256_AA_1 = _mm256_add_ps(ymm256_AA_1, ymm256_AA_3);
                    ymm256_C = _mm256_add_ps(ymm256_C, ymm256_AA_1);
                    _mm256_storeu_ps(&vecC[midx], ymm256_C);
                }
                __m128 vecBBx4 = _mm_loadu_ps(vecBB);       // vecBB[0] vecBB[1] vecBB[2] vecBB[3]
                __m128 vecBBx4_b = _mm_loadu_ps(vecBB + 1); // vecBB[1] vecBB[2] vecBB[3] vecBB[4]
                vecBBx4_b = _mm_shuffle_ps(vecBBx4_b, vecBBx4_b,
                                           _MM_SHUFFLE(3, 3, 3, 3)); // vecBB[4] vecBB[4] vecBB[4] vecBB[4]
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
                vecC[midx] = cal_hard_swish_relu_avx(vecC[midx]);
            }
        }
    }

    template <class POOL_PARAM>
    int avgpool1d_avx(float* input, float* output)
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

#endif // VIPER_MODULES_LIPSYNC_OP_AVX_H_