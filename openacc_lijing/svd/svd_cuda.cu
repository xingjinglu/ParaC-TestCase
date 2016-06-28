
#include <stdio.h>

#ifndef __CUDACC__
#include <stdlib.h>
#include <math.h>

#include <hmpprt/Grouplet.h>
#include <hmpprt/HostTypes.h>
#include <hmpprt/Context.h>
#include <hmpprt/CUDAGrid.h>
#include <hmpprt/CUDAModule.h>
#include <hmpprt/DeviceManager.h>
#include <hmpperr/hmpperr.h>

#include <openacci/openacci_c.h>

#ifdef _WIN32
#  define CDLT_API __declspec(dllexport)
#else /* ! _WIN32 */
#  define CDLT_API
#endif /* _WIN32 */



#else // ! __CUDACC__

#include <hmpprt/HostTypes.h>
#include <hmpprt/CUDAIntrinsics.h>

extern __shared__ int64_t hmpp_sharedmem[];
#endif // __CUDACC__



#ifndef __CUDACC__

#else


#endif

#define HMPPCG_SIMD_LENGTH 32

# 363 "svd.cpp"

#ifdef __CUDACC__
__device__ double reduce_double_add_x(double priv, double* tmpa, double orig)
;
#endif // __CUDACC__



# 363 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_363(double* A_H_1, double* B_H_2, double* S_H_3)
;
#endif // __CUDACC__



# 363 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  B_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_5)
;
#endif // __CUDACC__



# 325 "svd.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_363_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_363_parallel_region_1(double* A_H_4, double* B_H, double* S_H_1);
#endif // __CUDACC__




# 325 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_332(double* A_H_5, double* S_H_4, double* ci_3)
;
#endif // __CUDACC__



# 325 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_5)
;
#endif // __CUDACC__



# 60 "svd.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_332_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_332_parallel_region_1(double* A_H_2, double* S_H, double* ci_1);
#endif // __CUDACC__




# 60 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_124(hmpprt::s32* pass_3, double* A_H, double* V_H_2, hmpprt::s32* rotate_col_idx_1, double* ci_4, double* cj_2, double* vi_2, double* vj_2, hmpprt::s32 start_index)
;
#endif // __CUDACC__



# 60 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_124_internal_1(hmpprt::s32* pass, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  rotate_col_idx_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  cj_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vi_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vj_1, hmpprt::s32 start_index_2)
;
#endif // __CUDACC__



# 60 "svd.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_124_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_124_parallel_region_1(double* A_H_3, double* V_H, double* ci, double* cj, hmpprt::s32* pass_1, hmpprt::s32* rotate_col_idx, hmpprt::s32 start_index_1, double* value_1, double* vi, double* vj);
#endif // __CUDACC__




# 60 "svd.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_124_parallel_region_1(double* A_H_3, double* V_H, double* ci, double* cj, hmpprt::s32* pass_1, hmpprt::s32* rotate_col_idx, hmpprt::s32 start_index_1, double* value_1, double* vi, double* vj)
{
 
 double * tmpr_2 = (double *)(((char *)hmpp_sharedmem + 0));
 
 # 62 "svd.cpp"
 {
  # 127 "svd.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 127 "svd.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 127 "svd.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 127 "svd.cpp"
  iter_per_gang_3 = ((1 + ((256 - start_index_1) / 2 - 1) / 192) > 8LL ? (1 + ((256 - start_index_1) / 2 - 1) / 192) : 8LL);
  # 127 "svd.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 127 "svd.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < ((256 - start_index_1) / 2 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : ((256 - start_index_1) / 2 - 1));
  # 127 "svd.cpp"
  hmpprt::s32 j_2;
  # 127 "svd.cpp"
  # 128 "svd.cpp"
  for (j_2 = first_gang_iter_3 + (hmpprt::gr_btidy()) ; j_2 <= last_gang_iter_3 ; j_2 = j_2 + (hmpprt::gr_btnumy()))
  {
   # 133 "svd.cpp"
   hmpprt::s32 col_p;
   # 133 "svd.cpp"
   col_p = *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1) - 1));
   # 134 "svd.cpp"
   hmpprt::s32 col_q;
   # 134 "svd.cpp"
   col_q = *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1)));
   # 135 "svd.cpp"
   double real1;
   # 136 "svd.cpp"
   double imag1;
   # 142 "svd.cpp"
   hmpprt::s32 k_18;
   # 142 "svd.cpp"
   # 143 "svd.cpp"
   for (k_18 = (hmpprt::gr_btidx()) ; k_18 <= 255 ; k_18 = k_18 + (hmpprt::gr_btnumx()))
   {
    # 144 "svd.cpp"
    *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_18) = *(A_H_3 + (col_p * 256 + k_18));
    # 145 "svd.cpp"
    *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_18)) = *(A_H_3 + (65536 + col_p * 256 + k_18));
   }
   # 150 "svd.cpp"
   # 150 "svd.cpp"
   hmpprt::s32 k_19;
   # 150 "svd.cpp"
   # 151 "svd.cpp"
   for (k_19 = (hmpprt::gr_btidx()) ; k_19 <= 255 ; k_19 = k_19 + (hmpprt::gr_btnumx()))
   {
    # 152 "svd.cpp"
    *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_19) = *(A_H_3 + (col_q * 256 + k_19));
    # 153 "svd.cpp"
    *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_19)) = *(A_H_3 + (65536 + col_q * 256 + k_19));
   }
   # 158 "svd.cpp"
   # 158 "svd.cpp"
   hmpprt::s32 k_20;
   # 158 "svd.cpp"
   # 159 "svd.cpp"
   for (k_20 = (hmpprt::gr_btidx()) ; k_20 <= 255 ; k_20 = k_20 + (hmpprt::gr_btnumx()))
   {
    # 160 "svd.cpp"
    *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_20) = *(V_H + (col_p * 256 + k_20));
    # 161 "svd.cpp"
    *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_20)) = *(V_H + (65536 + col_p * 256 + k_20));
   }
   # 166 "svd.cpp"
   # 166 "svd.cpp"
   hmpprt::s32 k_21;
   # 166 "svd.cpp"
   # 167 "svd.cpp"
   for (k_21 = (hmpprt::gr_btidx()) ; k_21 <= 255 ; k_21 = k_21 + (hmpprt::gr_btnumx()))
   {
    # 168 "svd.cpp"
    *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_21) = *(V_H + (col_q * 256 + k_21));
    # 169 "svd.cpp"
    *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_21)) = *(V_H + (65536 + col_q * 256 + k_21));
   }
   # 172 "svd.cpp"
   # 172 "svd.cpp"
   hmpprt::s32 skip_trans;
   # 172 "svd.cpp"
   skip_trans = 0;
   # 136 "svd.cpp"
   double imag1_1;
   # 135 "svd.cpp"
   imag1_1 = 0;
   # 135 "svd.cpp"
   double real1_1;
   # 176 "svd.cpp"
   real1_1 = 0;
   # 176 "svd.cpp"
   hmpprt::s32 k_22;
   # 176 "svd.cpp"
   # 177 "svd.cpp"
   for (k_22 = (hmpprt::gr_btidx()) ; k_22 <= 255 ; k_22 = k_22 + (hmpprt::gr_btnumx()))
   {
    # 178 "svd.cpp"
    real1_1 = real1_1 + (*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)));
    # 179 "svd.cpp"
    imag1_1 = imag1_1 + (*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22));
   }
   # 181 "svd.cpp"
   # 181 "svd.cpp"
   real1 = (reduce_double_add_x(real1_1, tmpr_2, (double) 0.));
   # 181 "svd.cpp"
   imag1 = (reduce_double_add_x(imag1_1, tmpr_2, (double) 0.));
   # 181 "svd.cpp"
   *(value_1 + (j_2 * 2 + (start_index_1 + 1)) / 2) = sqrt(real1 * real1 + imag1 * imag1);
   # 183 "svd.cpp"
   if (*(value_1 + (j_2 * 2 + (start_index_1 + 1)) / 2) < (double) 1.0000000000000000818e-05)
   {
    # 184 "svd.cpp"
    skip_trans = 1;
   }
   # 186 "svd.cpp"
   if (skip_trans == 0)
   {
    # 188 "svd.cpp"
    *pass_1 = 0;
    # 192 "svd.cpp"
    double result1;
    # 193 "svd.cpp"
    double result2;
    # 194 "svd.cpp"
    double result3;
    # 195 "svd.cpp"
    double result4;
    # 196 "svd.cpp"
    double result5;
    # 197 "svd.cpp"
    double result6;
    # 198 "svd.cpp"
    double result7;
    # 199 "svd.cpp"
    double result8;
    # 192 "svd.cpp"
    double result1_1;
    # 202 "svd.cpp"
    result1_1 = 0;
    # 202 "svd.cpp"
    hmpprt::s32 k_23;
    # 202 "svd.cpp"
    # 203 "svd.cpp"
    for (k_23 = (hmpprt::gr_btidx()) ; k_23 <= 255 ; k_23 = k_23 + (hmpprt::gr_btnumx()))
    {
     # 203 "svd.cpp"
     result1_1 = result1_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_23) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_23 + 256));
    }
    # 193 "svd.cpp"
    # 193 "svd.cpp"
    result1 = (reduce_double_add_x(result1_1, tmpr_2, (double) 0.));
    # 193 "svd.cpp"
    double result2_1;
    # 208 "svd.cpp"
    result2_1 = 0;
    # 208 "svd.cpp"
    hmpprt::s32 k_24;
    # 208 "svd.cpp"
    # 209 "svd.cpp"
    for (k_24 = (hmpprt::gr_btidx()) ; k_24 <= 255 ; k_24 = k_24 + (hmpprt::gr_btnumx()))
    {
     # 209 "svd.cpp"
     result2_1 = result2_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_24 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_24);
    }
    # 194 "svd.cpp"
    # 194 "svd.cpp"
    result2 = (reduce_double_add_x(result2_1, tmpr_2, (double) 0.));
    # 194 "svd.cpp"
    double result3_1;
    # 214 "svd.cpp"
    result3_1 = 0;
    # 214 "svd.cpp"
    hmpprt::s32 k_25;
    # 214 "svd.cpp"
    # 215 "svd.cpp"
    for (k_25 = (hmpprt::gr_btidx()) ; k_25 <= 255 ; k_25 = k_25 + (hmpprt::gr_btnumx()))
    {
     # 215 "svd.cpp"
     result3_1 = result3_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_25) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_25);
    }
    # 195 "svd.cpp"
    # 195 "svd.cpp"
    result3 = (reduce_double_add_x(result3_1, tmpr_2, (double) 0.));
    # 195 "svd.cpp"
    double result4_1;
    # 220 "svd.cpp"
    result4_1 = 0;
    # 220 "svd.cpp"
    hmpprt::s32 k_26;
    # 220 "svd.cpp"
    # 221 "svd.cpp"
    for (k_26 = (hmpprt::gr_btidx()) ; k_26 <= 255 ; k_26 = k_26 + (hmpprt::gr_btnumx()))
    {
     # 221 "svd.cpp"
     result4_1 = result4_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_26 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_26 + 256));
    }
    # 224 "svd.cpp"
    # 224 "svd.cpp"
    result4 = (reduce_double_add_x(result4_1, tmpr_2, (double) 0.));
    # 224 "svd.cpp"
    double a;
    # 224 "svd.cpp"
    a = result1 - result2;
    # 225 "svd.cpp"
    double b;
    # 225 "svd.cpp"
    b = result3 + result4;
    # 227 "svd.cpp"
    double s_a2b2;
    # 50 "svd.cpp"
    hmpprt::s32 rvalue_1;
    # 50 "svd.cpp"
    if (b > (double) 0.)
    {
     # 53 "svd.cpp"
     rvalue_1 = 1;
     # 53 "svd.cpp"
     goto endf_2;
    }
    # 53 "svd.cpp"
    if (b == (double) 0.)
    {
     # 227 "svd.cpp"
     rvalue_1 = 0;
     # 227 "svd.cpp"
     goto endf_2;
    }
    # 227 "svd.cpp"
    rvalue_1 =  -1;
    # 227 "svd.cpp"
    endf_2:;
    # 227 "svd.cpp"
    s_a2b2 = (double ) (rvalue_1) * sqrt(a * a + b * b);
    # 228 "svd.cpp"
    double sin_alpha;
    # 228 "svd.cpp"
    sin_alpha = a / s_a2b2;
    # 229 "svd.cpp"
    double cos_alpha;
    # 229 "svd.cpp"
    cos_alpha = b / s_a2b2;
    # 230 "svd.cpp"
    double m;
    # 230 "svd.cpp"
    m =  - (b * cos_alpha + a * sin_alpha);
    # 196 "svd.cpp"
    double result5_1;
    # 235 "svd.cpp"
    result5_1 = 0;
    # 235 "svd.cpp"
    hmpprt::s32 k_27;
    # 235 "svd.cpp"
    # 236 "svd.cpp"
    for (k_27 = (hmpprt::gr_btidx()) ; k_27 <= 255 ; k_27 = k_27 + (hmpprt::gr_btnumx()))
    {
     # 236 "svd.cpp"
     result5_1 = result5_1 + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_27) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_27);
    }
    # 197 "svd.cpp"
    # 197 "svd.cpp"
    result5 = (reduce_double_add_x(result5_1, tmpr_2, (double) 0.));
    # 197 "svd.cpp"
    double result6_1;
    # 241 "svd.cpp"
    result6_1 = 0;
    # 241 "svd.cpp"
    hmpprt::s32 k_28;
    # 241 "svd.cpp"
    # 242 "svd.cpp"
    for (k_28 = (hmpprt::gr_btidx()) ; k_28 <= 255 ; k_28 = k_28 + (hmpprt::gr_btnumx()))
    {
     # 242 "svd.cpp"
     result6_1 = result6_1 + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_28 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_28 + 256));
    }
    # 198 "svd.cpp"
    # 198 "svd.cpp"
    result6 = (reduce_double_add_x(result6_1, tmpr_2, (double) 0.));
    # 198 "svd.cpp"
    double result7_1;
    # 247 "svd.cpp"
    result7_1 = 0;
    # 247 "svd.cpp"
    hmpprt::s32 k_29;
    # 247 "svd.cpp"
    # 248 "svd.cpp"
    for (k_29 = (hmpprt::gr_btidx()) ; k_29 <= 255 ; k_29 = k_29 + (hmpprt::gr_btnumx()))
    {
     # 248 "svd.cpp"
     result7_1 = result7_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_29) * *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_29);
    }
    # 199 "svd.cpp"
    # 199 "svd.cpp"
    result7 = (reduce_double_add_x(result7_1, tmpr_2, (double) 0.));
    # 199 "svd.cpp"
    double result8_1;
    # 253 "svd.cpp"
    result8_1 = 0;
    # 253 "svd.cpp"
    hmpprt::s32 k_30;
    # 253 "svd.cpp"
    # 254 "svd.cpp"
    for (k_30 = (hmpprt::gr_btidx()) ; k_30 <= 255 ; k_30 = k_30 + (hmpprt::gr_btnumx()))
    {
     # 254 "svd.cpp"
     result8_1 = result8_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_30 + 256)) * *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_30 + 256));
    }
    # 257 "svd.cpp"
    # 257 "svd.cpp"
    result8 = (reduce_double_add_x(result8_1, tmpr_2, (double) 0.));
    # 257 "svd.cpp"
    double n_1;
    # 257 "svd.cpp"
    n_1 = (double) 0.5 * (result5 + result6 - result7 - result8);
    # 258 "svd.cpp"
    double w;
    # 50 "svd.cpp"
    hmpprt::s32 rvalue_2;
    # 50 "svd.cpp"
    if (n_1 > (double) 0.)
    {
     # 53 "svd.cpp"
     rvalue_2 = 1;
     # 53 "svd.cpp"
     goto endf_3;
    }
    # 53 "svd.cpp"
    if (n_1 == (double) 0.)
    {
     # 258 "svd.cpp"
     rvalue_2 = 0;
     # 258 "svd.cpp"
     goto endf_3;
    }
    # 258 "svd.cpp"
    rvalue_2 =  -1;
    # 258 "svd.cpp"
    endf_3:;
    # 258 "svd.cpp"
    w = (double ) (rvalue_2) * m / sqrt(m * m + n_1 * n_1);
    # 260 "svd.cpp"
    double sin_x;
    # 260 "svd.cpp"
    sin_x = w / sqrt((double) 2. * ((double) 1. + sqrt((double) 1. - w * w)));
    # 261 "svd.cpp"
    double cos_x;
    # 261 "svd.cpp"
    cos_x = sqrt((double) 1. - sin_x * sin_x);
    # 264 "svd.cpp"
    double real2;
    # 265 "svd.cpp"
    double imag2;
    # 266 "svd.cpp"
    double real3;
    # 267 "svd.cpp"
    double imag3;
    # 268 "svd.cpp"
    double real4;
    # 269 "svd.cpp"
    double imag4;
    # 270 "svd.cpp"
    double real5;
    # 271 "svd.cpp"
    double imag5;
    # 274 "svd.cpp"
    hmpprt::s32 k_31;
    # 274 "svd.cpp"
    # 275 "svd.cpp"
    for (k_31 = (hmpprt::gr_btidx()) ; k_31 <= 255 ; k_31 = k_31 + (hmpprt::gr_btnumx()))
    {
     # 276 "svd.cpp"
     real2 = *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * cos_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * cos_alpha * sin_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * sin_alpha * sin_x;
     # 277 "svd.cpp"
     imag2 = *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_alpha * sin_x - *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * sin_alpha * sin_x;
     # 279 "svd.cpp"
     *(A_H_3 + (col_p * 256 + k_31)) = real2;
     # 280 "svd.cpp"
     *(A_H_3 + (65536 + col_p * 256 + k_31)) = imag2;
    }
    # 285 "svd.cpp"
    # 285 "svd.cpp"
    hmpprt::s32 k_32;
    # 285 "svd.cpp"
    # 286 "svd.cpp"
    for (k_32 = (hmpprt::gr_btidx()) ; k_32 <= 255 ; k_32 = k_32 + (hmpprt::gr_btnumx()))
    {
     # 287 "svd.cpp"
     real3 = *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * cos_x +  - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * cos_alpha * sin_x + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * sin_alpha * sin_x;
     # 288 "svd.cpp"
     imag3 = *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_x +  - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_alpha * sin_x - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * sin_alpha * sin_x;
     # 290 "svd.cpp"
     *(A_H_3 + (col_q * 256 + k_32)) = real3;
     # 291 "svd.cpp"
     *(A_H_3 + (65536 + col_q * 256 + k_32)) = imag3;
    }
    # 296 "svd.cpp"
    # 296 "svd.cpp"
    hmpprt::s32 k_33;
    # 296 "svd.cpp"
    # 297 "svd.cpp"
    for (k_33 = (hmpprt::gr_btidx()) ; k_33 <= 255 ; k_33 = k_33 + (hmpprt::gr_btnumx()))
    {
     # 298 "svd.cpp"
     real4 = *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * cos_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * cos_alpha * sin_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * sin_alpha * sin_x;
     # 299 "svd.cpp"
     imag4 = *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_alpha * sin_x - *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * sin_alpha * sin_x;
     # 301 "svd.cpp"
     *(V_H + (col_p * 256 + k_33)) = real4;
     # 302 "svd.cpp"
     *(V_H + (65536 + col_p * 256 + k_33)) = imag4;
    }
    # 307 "svd.cpp"
    # 307 "svd.cpp"
    hmpprt::s32 k_34;
    # 307 "svd.cpp"
    # 308 "svd.cpp"
    for (k_34 = (hmpprt::gr_btidx()) ; k_34 <= 255 ; k_34 = k_34 + (hmpprt::gr_btnumx()))
    {
     # 309 "svd.cpp"
     real5 = *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * cos_x +  - *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * cos_alpha * sin_x + *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * sin_alpha * sin_x;
     # 310 "svd.cpp"
     imag5 = *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_x +  - *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_alpha * sin_x - *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * sin_alpha * sin_x;
     # 312 "svd.cpp"
     *(V_H + (col_q * 256 + k_34)) = real5;
     # 313 "svd.cpp"
     *(V_H + (65536 + col_q * 256 + k_34)) = imag5;
    }
    # 317 "svd.cpp"
   }
   # 317 "svd.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1) - 1)) = col_q;
   # 318 "svd.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1))) = col_p;
  }
  # 60 "svd.cpp"
 }
}
#endif // __CUDACC__



# 60 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_124_internal_1(hmpprt::s32* pass, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  rotate_col_idx_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  cj_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vi_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vj_1, hmpprt::s32 start_index_2)
{
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pass_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&pass_2), hmpprt::MS_CUDA_GLOB, 4);
 # 60 "svd.cpp"
 *pass_2 = *pass;
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  value_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&value_2), hmpprt::MS_CUDA_GLOB, 1024uLL);
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,double>  tmpr_4;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_4), hmpprt::MS_CUDA_SHARED, 2048LL);
 # 60 "svd.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8LL);
  __hmppcg_call.addLocalParameter(&A_H_6, 8, "A_H_3");
  __hmppcg_call.addLocalParameter(&V_H_1, 8, "V_H");
  __hmppcg_call.addLocalParameter(&ci_2, 8, "ci");
  __hmppcg_call.addLocalParameter(&cj_1, 8, "cj");
  __hmppcg_call.addLocalParameter(&pass_2, 8, "pass_1");
  __hmppcg_call.addLocalParameter(&rotate_col_idx_2, 8, "rotate_col_idx");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (start_index_2), "start_index_1");
  __hmppcg_call.addSharedParameter(tmpr_4, "tmpr_2");
  __hmppcg_call.addLocalParameter(&value_2, 8, "value_1");
  __hmppcg_call.addLocalParameter(&vi_1, 8, "vi");
  __hmppcg_call.addLocalParameter(&vj_1, 8, "vj");
  __hmppcg_call.launch(hmpp_acc_region_svd_124_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 60 "svd.cpp"
 *pass = *pass_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) (&pass_2));
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) (&value_2));
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_4));
}
#endif // __CUDACC__



# 60 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_124(hmpprt::s32* pass_3, double* A_H, double* V_H_2, hmpprt::s32* rotate_col_idx_1, double* ci_4, double* cj_2, double* vi_2, double* vj_2, hmpprt::s32 start_index)
{
 # 325 "svd.cpp"
 (hmpp_acc_region_svd_124_internal_1(pass_3, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (V_H_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (rotate_col_idx_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (ci_4), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (cj_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (vi_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (vj_2), start_index));
}
#endif // __CUDACC__



# 325 "svd.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_332_parallel_region_1(double* A_H_2, double* S_H, double* ci_1)
{
 
 double * tmpr_1 = (double *)(((char *)hmpp_sharedmem + 0));
 
 # 327 "svd.cpp"
 {
  # 335 "svd.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 335 "svd.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 335 "svd.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * 8;
  # 335 "svd.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + 7) < 255 ? (first_gang_iter_2 + 7) : 255);
  # 335 "svd.cpp"
  hmpprt::s32 i_2;
  # 335 "svd.cpp"
  # 336 "svd.cpp"
  for (i_2 = first_gang_iter_2 + (hmpprt::gr_btidy()) ; i_2 <= last_gang_iter_2 ; i_2 = i_2 + (hmpprt::gr_btnumy()))
  {
   # 337 "svd.cpp"
   double real;
   # 338 "svd.cpp"
   double imag;
   # 341 "svd.cpp"
   hmpprt::s32 k_35;
   # 341 "svd.cpp"
   # 342 "svd.cpp"
   for (k_35 = (hmpprt::gr_btidx()) ; k_35 <= 255 ; k_35 = k_35 + (hmpprt::gr_btnumx()))
   {
    # 343 "svd.cpp"
    *(ci_1 + i_2 * 256 * 2 + k_35) = *(A_H_2 + (i_2 * 256 + k_35));
    # 344 "svd.cpp"
    *(ci_1 + i_2 * 256 * 2 + (256 + k_35)) = *(A_H_2 + (65536 + i_2 * 256 + k_35));
   }
   # 338 "svd.cpp"
   # 338 "svd.cpp"
   double imag_1;
   # 337 "svd.cpp"
   imag_1 = 0;
   # 337 "svd.cpp"
   double real_1;
   # 349 "svd.cpp"
   real_1 = 0;
   # 349 "svd.cpp"
   hmpprt::s32 l_1;
   # 349 "svd.cpp"
   # 350 "svd.cpp"
   for (l_1 = (hmpprt::gr_btidx()) ; l_1 <= 255 ; l_1 = l_1 + (hmpprt::gr_btnumx()))
   {
    # 351 "svd.cpp"
    real_1 = real_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + l_1) + *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)));
    # 352 "svd.cpp"
    imag_1 = imag_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) - *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + l_1));
   }
   # 355 "svd.cpp"
   # 355 "svd.cpp"
   real = (reduce_double_add_x(real_1, tmpr_1, (double) 0.));
   # 355 "svd.cpp"
   imag = (reduce_double_add_x(imag_1, tmpr_1, (double) 0.));
   # 355 "svd.cpp"
   double norm_A;
   # 355 "svd.cpp"
   norm_A = sqrt(sqrt(real * real + imag * imag));
   # 356 "svd.cpp"
   *(S_H + i_2) = norm_A;
  }
  # 325 "svd.cpp"
 }
}
#endif // __CUDACC__



# 325 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_5)
{
 # 325 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,double>  tmpr_3;
 # 325 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_3), hmpprt::MS_CUDA_SHARED, 2048LL);
 # 325 "svd.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8LL);
  __hmppcg_call.addLocalParameter(&A_H_8, 8, "A_H_2");
  __hmppcg_call.addLocalParameter(&S_H_2, 8, "S_H");
  __hmppcg_call.addLocalParameter(&ci_5, 8, "ci_1");
  __hmppcg_call.addSharedParameter(tmpr_3, "tmpr_1");
  __hmppcg_call.launch(hmpp_acc_region_svd_332_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 325 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_3));
}
#endif // __CUDACC__



# 325 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_332(double* A_H_5, double* S_H_4, double* ci_3)
{
 # 363 "svd.cpp"
 (hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (S_H_4), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (ci_3)));
}
#endif // __CUDACC__



# 363 "svd.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_363_parallel_region_1(double* A_H_4, double* B_H, double* S_H_1)
{
 # 365 "svd.cpp"
 {
  # 366 "svd.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 366 "svd.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 366 "svd.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * 342;
  # 366 "svd.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + 341) < 65535 ? (first_gang_iter_1 + 341) : 65535);
  # 366 "svd.cpp"
  hmpprt::s32 j_4;
  # 366 "svd.cpp"
  # 369 "svd.cpp"
  for (j_4 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; j_4 <= last_gang_iter_1 ; j_4 = j_4 + (hmpprt::gr_btnumy()))
  {
   # 366 "svd.cpp"
   hmpprt::s32 j_3;
   # 368 "svd.cpp"
   hmpprt::s32 i_3;
   # 370 "svd.cpp"
   i_3 = j_4 % 256;
   # 370 "svd.cpp"
   j_3 = j_4 / 256;
   # 370 "svd.cpp"
   *(B_H + (j_3 * 256 + i_3)) = *(A_H_4 + (j_3 * 256 + i_3)) / *(S_H_1 + j_3);
   # 371 "svd.cpp"
   *(B_H + (65536 + j_3 * 256 + i_3)) = *(A_H_4 + (65536 + j_3 * 256 + i_3)) / *(S_H_1 + j_3);
  }
  # 363 "svd.cpp"
 }
}
#endif // __CUDACC__



# 363 "svd.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  B_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_5)
{
 # 363 "svd.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&A_H_7, 8, "A_H_4");
  __hmppcg_call.addLocalParameter(&B_H_1, 8, "B_H");
  __hmppcg_call.addLocalParameter(&S_H_5, 8, "S_H_1");
  __hmppcg_call.launch(hmpp_acc_region_svd_363_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 363 "svd.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_363(double* A_H_1, double* B_H_2, double* S_H_3)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (B_H_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (S_H_3)));
}
#endif // __CUDACC__



# 1 "<preprocessor>"

#ifdef __CUDACC__
__device__ double reduce_double_add_x(double priv, double* tmpa, double orig)
{
 # 1 "<preprocessor>"
 *(tmpa + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) = priv;
 # 1 "<preprocessor>"
 hmpprt::s32 n;
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 for (n = ((hmpprt::gr_btnumx()) - 1 >> 1) + 1 ; n > 0 ; n = (n >> 1))
 {
  # 1 "<preprocessor>"
  hmpprt::s32 next;
  # 1 "<preprocessor>"
  next = (hmpprt::gr_btidx()) + n;
  # 1 "<preprocessor>"
  if ((hmpprt::gr_btidx()) < n && next < (hmpprt::gr_btnumx()))
  {
   # 1 "<preprocessor>"
   *(tmpa + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) = *(tmpa + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) + *(tmpa + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * next);
  }
 }
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 return *(tmpa + (hmpprt::gr_btidy())) + orig;
}
#endif // __CUDACC__




#ifndef __CUDACC__
extern "C" const char * hmpprt_cuda_get_gpu_code();

static hmpprt::CUDAModule * hmpprt_module = 0;
static int hmpprt_uses = 0;

extern "C" CDLT_API void * hmpprt_init()
{
  try
  {
    if (hmpprt_uses++ == 0)
    {
      hmpprt_module = new hmpprt::CUDAModule(hmpprt_cuda_get_gpu_code());
      hmpp_acc_region_svd_124_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_124_parallel_region_1");
      hmpp_acc_region_svd_332_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_332_parallel_region_1");
      hmpp_acc_region_svd_363_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_363_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_124", "prototype hmpp_acc_region_svd_124(pass: ^host s32, A_H: ^cudaglob double, V_H: ^cudaglob double, rotate_col_idx: ^cudaglob s32, ci: ^cudaglob double, cj: ^cudaglob double, vi: ^cudaglob double, vj: ^cudaglob double, start_index: s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_332", "prototype hmpp_acc_region_svd_332(A_H: ^cudaglob double, S_H: ^cudaglob double, ci: ^cudaglob double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_363", "prototype hmpp_acc_region_svd_363(A_H: ^cudaglob double, B_H: ^cudaglob double, S_H: ^cudaglob double)");

  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_init()\n");
    abort();
  }
  return 0;
}
#endif // __CUDACC__

#ifndef __CUDACC__
extern "C" CDLT_API void * hmpprt_fini()
{
  try
  {
    if (--hmpprt_uses == 0)
    {
      delete hmpp_acc_region_svd_124_parallel_region_1;
      delete hmpp_acc_region_svd_332_parallel_region_1;
      delete hmpp_acc_region_svd_363_parallel_region_1;

      delete hmpprt_module;
      hmpprt_module = 0;
    }
  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_fini()\n");
    abort();
  }
  return 0;
}
#endif // __CUDACC__

// footer
