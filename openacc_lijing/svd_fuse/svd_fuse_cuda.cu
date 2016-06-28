
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

# 369 "svd_fuse.cpp"

#ifdef __CUDACC__
__device__ double reduce_double_add_x(double priv, double* tmpa, double orig)
;
#endif // __CUDACC__



# 369 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_369(double* A_H_4, double* B_H_1, double* S_H_5)
;
#endif // __CUDACC__



# 369 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_369_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  B_H_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_1)
;
#endif // __CUDACC__



# 330 "svd_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_369_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_369_parallel_region_1(double* A_H_1, double* B_H, double* S_H_3);
#endif // __CUDACC__




# 330 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_338(double* A_H_5, double* S_H, double* ci_3)
;
#endif // __CUDACC__



# 330 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_338_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_5)
;
#endif // __CUDACC__



# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_338_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_338_parallel_region_1(double* A_H_2, double* S_H_2, double* ci_1);
#endif // __CUDACC__




# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_129(hmpprt::s32* pass_3, double* A_H_6, double* V_H_2, hmpprt::s32* rotate_col_idx_2, double* ci_4, double* cj, double* vi_1, double* vj_1, hmpprt::s32 start_index_1)
;
#endif // __CUDACC__



# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_129_internal_1(hmpprt::s32* pass, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  rotate_col_idx_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  cj_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vi_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vj_2, hmpprt::s32 start_index_2)
;
#endif // __CUDACC__



# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_svd_129_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_svd_129_parallel_region_1(double* A_H_3, double* V_H, double* ci, double* cj_1, hmpprt::s32* pass_1, hmpprt::s32* rotate_col_idx, hmpprt::s32 start_index, double* value_2, double* vi, double* vj);
#endif // __CUDACC__




# 60 "svd_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_129_parallel_region_1(double* A_H_3, double* V_H, double* ci, double* cj_1, hmpprt::s32* pass_1, hmpprt::s32* rotate_col_idx, hmpprt::s32 start_index, double* value_2, double* vi, double* vj)
{
 
 double * tmpr_4 = (double *)(((char *)hmpp_sharedmem + 0));
 
 # 62 "svd_fuse.cpp"
 {
  # 132 "svd_fuse.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 132 "svd_fuse.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 132 "svd_fuse.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 132 "svd_fuse.cpp"
  iter_per_gang_3 = ((1 + ((256 - start_index) / 2 - 1) / 192) > 8LL ? (1 + ((256 - start_index) / 2 - 1) / 192) : 8LL);
  # 132 "svd_fuse.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 132 "svd_fuse.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < ((256 - start_index) / 2 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : ((256 - start_index) / 2 - 1));
  # 132 "svd_fuse.cpp"
  hmpprt::s32 j_2;
  # 132 "svd_fuse.cpp"
  # 133 "svd_fuse.cpp"
  for (j_2 = first_gang_iter_3 + (hmpprt::gr_btidy()) ; j_2 <= last_gang_iter_3 ; j_2 = j_2 + (hmpprt::gr_btnumy()))
  {
   # 138 "svd_fuse.cpp"
   hmpprt::s32 col_p;
   # 138 "svd_fuse.cpp"
   col_p = *(rotate_col_idx + (j_2 * 2 + (start_index + 1) - 1));
   # 139 "svd_fuse.cpp"
   hmpprt::s32 col_q;
   # 139 "svd_fuse.cpp"
   col_q = *(rotate_col_idx + (j_2 * 2 + (start_index + 1)));
   # 140 "svd_fuse.cpp"
   double real1;
   # 141 "svd_fuse.cpp"
   double imag1;
   # 147 "svd_fuse.cpp"
   hmpprt::s32 k_18;
   # 147 "svd_fuse.cpp"
   # 148 "svd_fuse.cpp"
   for (k_18 = (hmpprt::gr_btidx()) ; k_18 <= 255 ; k_18 = k_18 + (hmpprt::gr_btnumx()))
   {
    # 149 "svd_fuse.cpp"
    *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_18) = *(A_H_3 + (col_p * 256 + k_18));
    # 150 "svd_fuse.cpp"
    *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_18)) = *(A_H_3 + (65536 + col_p * 256 + k_18));
   }
   # 155 "svd_fuse.cpp"
   # 155 "svd_fuse.cpp"
   hmpprt::s32 k_19;
   # 155 "svd_fuse.cpp"
   # 156 "svd_fuse.cpp"
   for (k_19 = (hmpprt::gr_btidx()) ; k_19 <= 255 ; k_19 = k_19 + (hmpprt::gr_btnumx()))
   {
    # 157 "svd_fuse.cpp"
    *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_19) = *(A_H_3 + (col_q * 256 + k_19));
    # 158 "svd_fuse.cpp"
    *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_19)) = *(A_H_3 + (65536 + col_q * 256 + k_19));
   }
   # 163 "svd_fuse.cpp"
   # 163 "svd_fuse.cpp"
   hmpprt::s32 k_20;
   # 163 "svd_fuse.cpp"
   # 164 "svd_fuse.cpp"
   for (k_20 = (hmpprt::gr_btidx()) ; k_20 <= 255 ; k_20 = k_20 + (hmpprt::gr_btnumx()))
   {
    # 165 "svd_fuse.cpp"
    *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_20) = *(V_H + (col_p * 256 + k_20));
    # 166 "svd_fuse.cpp"
    *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_20)) = *(V_H + (65536 + col_p * 256 + k_20));
   }
   # 171 "svd_fuse.cpp"
   # 171 "svd_fuse.cpp"
   hmpprt::s32 k_21;
   # 171 "svd_fuse.cpp"
   # 172 "svd_fuse.cpp"
   for (k_21 = (hmpprt::gr_btidx()) ; k_21 <= 255 ; k_21 = k_21 + (hmpprt::gr_btnumx()))
   {
    # 173 "svd_fuse.cpp"
    *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_21) = *(V_H + (col_q * 256 + k_21));
    # 174 "svd_fuse.cpp"
    *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_21)) = *(V_H + (65536 + col_q * 256 + k_21));
   }
   # 177 "svd_fuse.cpp"
   # 177 "svd_fuse.cpp"
   hmpprt::s32 skip_trans;
   # 177 "svd_fuse.cpp"
   skip_trans = 0;
   # 141 "svd_fuse.cpp"
   double imag1_1;
   # 140 "svd_fuse.cpp"
   imag1_1 = 0;
   # 140 "svd_fuse.cpp"
   double real1_1;
   # 181 "svd_fuse.cpp"
   real1_1 = 0;
   # 181 "svd_fuse.cpp"
   hmpprt::s32 k_22;
   # 181 "svd_fuse.cpp"
   # 182 "svd_fuse.cpp"
   for (k_22 = (hmpprt::gr_btidx()) ; k_22 <= 255 ; k_22 = k_22 + (hmpprt::gr_btnumx()))
   {
    # 183 "svd_fuse.cpp"
    real1_1 = real1_1 + (*(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_22) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_22) + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_22)));
    # 184 "svd_fuse.cpp"
    imag1_1 = imag1_1 + (*(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_22) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_22)) - *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_22));
   }
   # 186 "svd_fuse.cpp"
   # 186 "svd_fuse.cpp"
   real1 = (reduce_double_add_x(real1_1, tmpr_4, (double) 0.));
   # 186 "svd_fuse.cpp"
   imag1 = (reduce_double_add_x(imag1_1, tmpr_4, (double) 0.));
   # 186 "svd_fuse.cpp"
   *(value_2 + (j_2 * 2 + (start_index + 1)) / 2) = sqrt(real1 * real1 + imag1 * imag1);
   # 188 "svd_fuse.cpp"
   if (*(value_2 + (j_2 * 2 + (start_index + 1)) / 2) < (double) 1.0000000000000000818e-05)
   {
    # 189 "svd_fuse.cpp"
    skip_trans = 1;
   }
   # 191 "svd_fuse.cpp"
   if (skip_trans == 0)
   {
    # 193 "svd_fuse.cpp"
    *pass_1 = 0;
    # 197 "svd_fuse.cpp"
    double result1;
    # 198 "svd_fuse.cpp"
    double result2;
    # 199 "svd_fuse.cpp"
    double result3;
    # 200 "svd_fuse.cpp"
    double result4;
    # 201 "svd_fuse.cpp"
    double result5;
    # 202 "svd_fuse.cpp"
    double result6;
    # 203 "svd_fuse.cpp"
    double result7;
    # 204 "svd_fuse.cpp"
    double result8;
    # 197 "svd_fuse.cpp"
    double result1_1;
    # 207 "svd_fuse.cpp"
    result1_1 = 0;
    # 207 "svd_fuse.cpp"
    hmpprt::s32 k_23;
    # 207 "svd_fuse.cpp"
    # 208 "svd_fuse.cpp"
    for (k_23 = (hmpprt::gr_btidx()) ; k_23 <= 255 ; k_23 = k_23 + (hmpprt::gr_btnumx()))
    {
     # 208 "svd_fuse.cpp"
     result1_1 = result1_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_23) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_23 + 256));
    }
    # 198 "svd_fuse.cpp"
    # 198 "svd_fuse.cpp"
    result1 = (reduce_double_add_x(result1_1, tmpr_4, (double) 0.));
    # 198 "svd_fuse.cpp"
    double result2_1;
    # 213 "svd_fuse.cpp"
    result2_1 = 0;
    # 213 "svd_fuse.cpp"
    hmpprt::s32 k_24;
    # 213 "svd_fuse.cpp"
    # 214 "svd_fuse.cpp"
    for (k_24 = (hmpprt::gr_btidx()) ; k_24 <= 255 ; k_24 = k_24 + (hmpprt::gr_btnumx()))
    {
     # 214 "svd_fuse.cpp"
     result2_1 = result2_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_24 + 256)) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_24);
    }
    # 199 "svd_fuse.cpp"
    # 199 "svd_fuse.cpp"
    result2 = (reduce_double_add_x(result2_1, tmpr_4, (double) 0.));
    # 199 "svd_fuse.cpp"
    double result3_1;
    # 219 "svd_fuse.cpp"
    result3_1 = 0;
    # 219 "svd_fuse.cpp"
    hmpprt::s32 k_25;
    # 219 "svd_fuse.cpp"
    # 220 "svd_fuse.cpp"
    for (k_25 = (hmpprt::gr_btidx()) ; k_25 <= 255 ; k_25 = k_25 + (hmpprt::gr_btnumx()))
    {
     # 220 "svd_fuse.cpp"
     result3_1 = result3_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_25) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_25);
    }
    # 200 "svd_fuse.cpp"
    # 200 "svd_fuse.cpp"
    result3 = (reduce_double_add_x(result3_1, tmpr_4, (double) 0.));
    # 200 "svd_fuse.cpp"
    double result4_1;
    # 225 "svd_fuse.cpp"
    result4_1 = 0;
    # 225 "svd_fuse.cpp"
    hmpprt::s32 k_26;
    # 225 "svd_fuse.cpp"
    # 226 "svd_fuse.cpp"
    for (k_26 = (hmpprt::gr_btidx()) ; k_26 <= 255 ; k_26 = k_26 + (hmpprt::gr_btnumx()))
    {
     # 226 "svd_fuse.cpp"
     result4_1 = result4_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_26 + 256)) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_26 + 256));
    }
    # 229 "svd_fuse.cpp"
    # 229 "svd_fuse.cpp"
    result4 = (reduce_double_add_x(result4_1, tmpr_4, (double) 0.));
    # 229 "svd_fuse.cpp"
    double a;
    # 229 "svd_fuse.cpp"
    a = result1 - result2;
    # 230 "svd_fuse.cpp"
    double b;
    # 230 "svd_fuse.cpp"
    b = result3 + result4;
    # 232 "svd_fuse.cpp"
    double s_a2b2;
    # 50 "svd_fuse.cpp"
    hmpprt::s32 rvalue_1;
    # 50 "svd_fuse.cpp"
    if (b > (double) 0.)
    {
     # 53 "svd_fuse.cpp"
     rvalue_1 = 1;
     # 53 "svd_fuse.cpp"
     goto endf_2;
    }
    # 53 "svd_fuse.cpp"
    if (b == (double) 0.)
    {
     # 232 "svd_fuse.cpp"
     rvalue_1 = 0;
     # 232 "svd_fuse.cpp"
     goto endf_2;
    }
    # 232 "svd_fuse.cpp"
    rvalue_1 =  -1;
    # 232 "svd_fuse.cpp"
    endf_2:;
    # 232 "svd_fuse.cpp"
    s_a2b2 = (double ) (rvalue_1) * sqrt(a * a + b * b);
    # 233 "svd_fuse.cpp"
    double sin_alpha;
    # 233 "svd_fuse.cpp"
    sin_alpha = a / s_a2b2;
    # 234 "svd_fuse.cpp"
    double cos_alpha;
    # 234 "svd_fuse.cpp"
    cos_alpha = b / s_a2b2;
    # 235 "svd_fuse.cpp"
    double m;
    # 235 "svd_fuse.cpp"
    m =  - (b * cos_alpha + a * sin_alpha);
    # 201 "svd_fuse.cpp"
    double result5_1;
    # 240 "svd_fuse.cpp"
    result5_1 = 0;
    # 240 "svd_fuse.cpp"
    hmpprt::s32 k_27;
    # 240 "svd_fuse.cpp"
    # 241 "svd_fuse.cpp"
    for (k_27 = (hmpprt::gr_btidx()) ; k_27 <= 255 ; k_27 = k_27 + (hmpprt::gr_btnumx()))
    {
     # 241 "svd_fuse.cpp"
     result5_1 = result5_1 + *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_27) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_27);
    }
    # 202 "svd_fuse.cpp"
    # 202 "svd_fuse.cpp"
    result5 = (reduce_double_add_x(result5_1, tmpr_4, (double) 0.));
    # 202 "svd_fuse.cpp"
    double result6_1;
    # 246 "svd_fuse.cpp"
    result6_1 = 0;
    # 246 "svd_fuse.cpp"
    hmpprt::s32 k_28;
    # 246 "svd_fuse.cpp"
    # 247 "svd_fuse.cpp"
    for (k_28 = (hmpprt::gr_btidx()) ; k_28 <= 255 ; k_28 = k_28 + (hmpprt::gr_btnumx()))
    {
     # 247 "svd_fuse.cpp"
     result6_1 = result6_1 + *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_28 + 256)) * *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_28 + 256));
    }
    # 203 "svd_fuse.cpp"
    # 203 "svd_fuse.cpp"
    result6 = (reduce_double_add_x(result6_1, tmpr_4, (double) 0.));
    # 203 "svd_fuse.cpp"
    double result7_1;
    # 252 "svd_fuse.cpp"
    result7_1 = 0;
    # 252 "svd_fuse.cpp"
    hmpprt::s32 k_29;
    # 252 "svd_fuse.cpp"
    # 253 "svd_fuse.cpp"
    for (k_29 = (hmpprt::gr_btidx()) ; k_29 <= 255 ; k_29 = k_29 + (hmpprt::gr_btnumx()))
    {
     # 253 "svd_fuse.cpp"
     result7_1 = result7_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_29) * *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_29);
    }
    # 204 "svd_fuse.cpp"
    # 204 "svd_fuse.cpp"
    result7 = (reduce_double_add_x(result7_1, tmpr_4, (double) 0.));
    # 204 "svd_fuse.cpp"
    double result8_1;
    # 258 "svd_fuse.cpp"
    result8_1 = 0;
    # 258 "svd_fuse.cpp"
    hmpprt::s32 k_30;
    # 258 "svd_fuse.cpp"
    # 259 "svd_fuse.cpp"
    for (k_30 = (hmpprt::gr_btidx()) ; k_30 <= 255 ; k_30 = k_30 + (hmpprt::gr_btnumx()))
    {
     # 259 "svd_fuse.cpp"
     result8_1 = result8_1 + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_30 + 256)) * *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_30 + 256));
    }
    # 262 "svd_fuse.cpp"
    # 262 "svd_fuse.cpp"
    result8 = (reduce_double_add_x(result8_1, tmpr_4, (double) 0.));
    # 262 "svd_fuse.cpp"
    double n_1;
    # 262 "svd_fuse.cpp"
    n_1 = (double) 0.5 * (result5 + result6 - result7 - result8);
    # 263 "svd_fuse.cpp"
    double w;
    # 50 "svd_fuse.cpp"
    hmpprt::s32 rvalue_2;
    # 50 "svd_fuse.cpp"
    if (n_1 > (double) 0.)
    {
     # 53 "svd_fuse.cpp"
     rvalue_2 = 1;
     # 53 "svd_fuse.cpp"
     goto endf_3;
    }
    # 53 "svd_fuse.cpp"
    if (n_1 == (double) 0.)
    {
     # 263 "svd_fuse.cpp"
     rvalue_2 = 0;
     # 263 "svd_fuse.cpp"
     goto endf_3;
    }
    # 263 "svd_fuse.cpp"
    rvalue_2 =  -1;
    # 263 "svd_fuse.cpp"
    endf_3:;
    # 263 "svd_fuse.cpp"
    w = (double ) (rvalue_2) * m / sqrt(m * m + n_1 * n_1);
    # 265 "svd_fuse.cpp"
    double sin_x;
    # 265 "svd_fuse.cpp"
    sin_x = w / sqrt((double) 2. * ((double) 1. + sqrt((double) 1. - w * w)));
    # 266 "svd_fuse.cpp"
    double cos_x;
    # 266 "svd_fuse.cpp"
    cos_x = sqrt((double) 1. - sin_x * sin_x);
    # 269 "svd_fuse.cpp"
    double real2;
    # 270 "svd_fuse.cpp"
    double imag2;
    # 271 "svd_fuse.cpp"
    double real3;
    # 272 "svd_fuse.cpp"
    double imag3;
    # 273 "svd_fuse.cpp"
    double real4;
    # 274 "svd_fuse.cpp"
    double imag4;
    # 275 "svd_fuse.cpp"
    double real5;
    # 276 "svd_fuse.cpp"
    double imag5;
    # 279 "svd_fuse.cpp"
    hmpprt::s32 k_31;
    # 279 "svd_fuse.cpp"
    # 280 "svd_fuse.cpp"
    for (k_31 = (hmpprt::gr_btidx()) ; k_31 <= 255 ; k_31 = k_31 + (hmpprt::gr_btnumx()))
    {
     # 281 "svd_fuse.cpp"
     real2 = *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_31) * cos_x + *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_31) * cos_alpha * sin_x + *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_31 + 256)) * sin_alpha * sin_x;
     # 282 "svd_fuse.cpp"
     imag2 = *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_x + *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_alpha * sin_x - *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_31) * sin_alpha * sin_x;
     # 284 "svd_fuse.cpp"
     *(A_H_3 + (col_p * 256 + k_31)) = real2;
     # 285 "svd_fuse.cpp"
     *(A_H_3 + (65536 + col_p * 256 + k_31)) = imag2;
    }
    # 290 "svd_fuse.cpp"
    # 290 "svd_fuse.cpp"
    hmpprt::s32 k_32;
    # 290 "svd_fuse.cpp"
    # 291 "svd_fuse.cpp"
    for (k_32 = (hmpprt::gr_btidx()) ; k_32 <= 255 ; k_32 = k_32 + (hmpprt::gr_btnumx()))
    {
     # 292 "svd_fuse.cpp"
     real3 = *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_32) * cos_x +  - *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_32) * cos_alpha * sin_x + *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_32 + 256)) * sin_alpha * sin_x;
     # 293 "svd_fuse.cpp"
     imag3 = *(cj_1 + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_x +  - *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_alpha * sin_x - *(ci + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_32) * sin_alpha * sin_x;
     # 295 "svd_fuse.cpp"
     *(A_H_3 + (col_q * 256 + k_32)) = real3;
     # 296 "svd_fuse.cpp"
     *(A_H_3 + (65536 + col_q * 256 + k_32)) = imag3;
    }
    # 301 "svd_fuse.cpp"
    # 301 "svd_fuse.cpp"
    hmpprt::s32 k_33;
    # 301 "svd_fuse.cpp"
    # 302 "svd_fuse.cpp"
    for (k_33 = (hmpprt::gr_btidx()) ; k_33 <= 255 ; k_33 = k_33 + (hmpprt::gr_btnumx()))
    {
     # 303 "svd_fuse.cpp"
     real4 = *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_33) * cos_x + *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_33) * cos_alpha * sin_x + *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_33 + 256)) * sin_alpha * sin_x;
     # 304 "svd_fuse.cpp"
     imag4 = *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_x + *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_alpha * sin_x - *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_33) * sin_alpha * sin_x;
     # 306 "svd_fuse.cpp"
     *(V_H + (col_p * 256 + k_33)) = real4;
     # 307 "svd_fuse.cpp"
     *(V_H + (65536 + col_p * 256 + k_33)) = imag4;
    }
    # 312 "svd_fuse.cpp"
    # 312 "svd_fuse.cpp"
    hmpprt::s32 k_34;
    # 312 "svd_fuse.cpp"
    # 313 "svd_fuse.cpp"
    for (k_34 = (hmpprt::gr_btidx()) ; k_34 <= 255 ; k_34 = k_34 + (hmpprt::gr_btnumx()))
    {
     # 314 "svd_fuse.cpp"
     real5 = *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_34) * cos_x +  - *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_34) * cos_alpha * sin_x + *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_34 + 256)) * sin_alpha * sin_x;
     # 315 "svd_fuse.cpp"
     imag5 = *(vj + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_x +  - *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_alpha * sin_x - *(vi + (j_2 * 2 + (start_index + 1)) / 2 * 256 * 2 + k_34) * sin_alpha * sin_x;
     # 317 "svd_fuse.cpp"
     *(V_H + (col_q * 256 + k_34)) = real5;
     # 318 "svd_fuse.cpp"
     *(V_H + (65536 + col_q * 256 + k_34)) = imag5;
    }
    # 322 "svd_fuse.cpp"
   }
   # 322 "svd_fuse.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index + 1) - 1)) = col_q;
   # 323 "svd_fuse.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index + 1))) = col_p;
  }
  # 60 "svd_fuse.cpp"
 }
}
#endif // __CUDACC__



# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_129_internal_1(hmpprt::s32* pass, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  rotate_col_idx_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  cj_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vi_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  vj_2, hmpprt::s32 start_index_2)
{
 # 60 "svd_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pass_2;
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&pass_2), hmpprt::MS_CUDA_GLOB, 4);
 # 60 "svd_fuse.cpp"
 *pass_2 = *pass;
 # 60 "svd_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  value_1;
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&value_1), hmpprt::MS_CUDA_GLOB, 1024uLL);
 # 60 "svd_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,double>  tmpr_2;
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_2), hmpprt::MS_CUDA_SHARED, 2048LL);
 # 60 "svd_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8LL);
  __hmppcg_call.addLocalParameter(&A_H, 8, "A_H_3");
  __hmppcg_call.addLocalParameter(&V_H_1, 8, "V_H");
  __hmppcg_call.addLocalParameter(&ci_2, 8, "ci");
  __hmppcg_call.addLocalParameter(&cj_2, 8, "cj_1");
  __hmppcg_call.addLocalParameter(&pass_2, 8, "pass_1");
  __hmppcg_call.addLocalParameter(&rotate_col_idx_1, 8, "rotate_col_idx");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (start_index_2), "start_index");
  __hmppcg_call.addSharedParameter(tmpr_2, "tmpr_4");
  __hmppcg_call.addLocalParameter(&value_1, 8, "value_2");
  __hmppcg_call.addLocalParameter(&vi_2, 8, "vi");
  __hmppcg_call.addLocalParameter(&vj_2, 8, "vj");
  __hmppcg_call.launch(hmpp_acc_region_svd_129_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 60 "svd_fuse.cpp"
 *pass = *pass_2;
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&pass_2));
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&value_1));
 # 60 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_2));
}
#endif // __CUDACC__



# 60 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_129(hmpprt::s32* pass_3, double* A_H_6, double* V_H_2, hmpprt::s32* rotate_col_idx_2, double* ci_4, double* cj, double* vi_1, double* vj_1, hmpprt::s32 start_index_1)
{
 # 330 "svd_fuse.cpp"
 (hmpp_acc_region_svd_129_internal_1(pass_3, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H_6), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (V_H_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (rotate_col_idx_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (ci_4), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (cj), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (vi_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (vj_1), start_index_1));
}
#endif // __CUDACC__



# 330 "svd_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_338_parallel_region_1(double* A_H_2, double* S_H_2, double* ci_1)
{
 
 double * tmpr_3 = (double *)(((char *)hmpp_sharedmem + 0));
 
 # 332 "svd_fuse.cpp"
 {
  # 341 "svd_fuse.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 341 "svd_fuse.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 341 "svd_fuse.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * 8;
  # 341 "svd_fuse.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + 7) < 255 ? (first_gang_iter_2 + 7) : 255);
  # 341 "svd_fuse.cpp"
  hmpprt::s32 i_2;
  # 341 "svd_fuse.cpp"
  # 342 "svd_fuse.cpp"
  for (i_2 = first_gang_iter_2 + (hmpprt::gr_btidy()) ; i_2 <= last_gang_iter_2 ; i_2 = i_2 + (hmpprt::gr_btnumy()))
  {
   # 343 "svd_fuse.cpp"
   double real;
   # 344 "svd_fuse.cpp"
   double imag;
   # 347 "svd_fuse.cpp"
   hmpprt::s32 k_35;
   # 347 "svd_fuse.cpp"
   # 348 "svd_fuse.cpp"
   for (k_35 = (hmpprt::gr_btidx()) ; k_35 <= 255 ; k_35 = k_35 + (hmpprt::gr_btnumx()))
   {
    # 349 "svd_fuse.cpp"
    *(ci_1 + i_2 * 256 * 2 + k_35) = *(A_H_2 + (i_2 * 256 + k_35));
    # 350 "svd_fuse.cpp"
    *(ci_1 + i_2 * 256 * 2 + (256 + k_35)) = *(A_H_2 + (65536 + i_2 * 256 + k_35));
   }
   # 344 "svd_fuse.cpp"
   # 344 "svd_fuse.cpp"
   double imag_1;
   # 343 "svd_fuse.cpp"
   imag_1 = 0;
   # 343 "svd_fuse.cpp"
   double real_1;
   # 355 "svd_fuse.cpp"
   real_1 = 0;
   # 355 "svd_fuse.cpp"
   hmpprt::s32 l_1;
   # 355 "svd_fuse.cpp"
   # 356 "svd_fuse.cpp"
   for (l_1 = (hmpprt::gr_btidx()) ; l_1 <= 255 ; l_1 = l_1 + (hmpprt::gr_btnumx()))
   {
    # 357 "svd_fuse.cpp"
    real_1 = real_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + l_1) + *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)));
    # 358 "svd_fuse.cpp"
    imag_1 = imag_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) - *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + l_1));
   }
   # 361 "svd_fuse.cpp"
   # 361 "svd_fuse.cpp"
   real = (reduce_double_add_x(real_1, tmpr_3, (double) 0.));
   # 361 "svd_fuse.cpp"
   imag = (reduce_double_add_x(imag_1, tmpr_3, (double) 0.));
   # 361 "svd_fuse.cpp"
   double norm_A;
   # 361 "svd_fuse.cpp"
   norm_A = sqrt(sqrt(real * real + imag * imag));
   # 362 "svd_fuse.cpp"
   *(S_H_2 + i_2) = norm_A;
  }
  # 330 "svd_fuse.cpp"
 }
}
#endif // __CUDACC__



# 330 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_338_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  ci_5)
{
 # 330 "svd_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,double>  tmpr_1;
 # 330 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_1), hmpprt::MS_CUDA_SHARED, 2048LL);
 # 330 "svd_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8LL);
  __hmppcg_call.addLocalParameter(&A_H_8, 8, "A_H_2");
  __hmppcg_call.addLocalParameter(&S_H_4, 8, "S_H_2");
  __hmppcg_call.addLocalParameter(&ci_5, 8, "ci_1");
  __hmppcg_call.addSharedParameter(tmpr_1, "tmpr_3");
  __hmppcg_call.launch(hmpp_acc_region_svd_338_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 330 "svd_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_1));
}
#endif // __CUDACC__



# 330 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_338(double* A_H_5, double* S_H, double* ci_3)
{
 # 369 "svd_fuse.cpp"
 (hmpp_acc_region_svd_338_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (S_H), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (ci_3)));
}
#endif // __CUDACC__



# 369 "svd_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_svd_369_parallel_region_1(double* A_H_1, double* B_H, double* S_H_3)
{
 # 371 "svd_fuse.cpp"
 {
  # 372 "svd_fuse.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 372 "svd_fuse.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 372 "svd_fuse.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * 342;
  # 372 "svd_fuse.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + 341) < 65535 ? (first_gang_iter_1 + 341) : 65535);
  # 372 "svd_fuse.cpp"
  hmpprt::s32 j_4;
  # 372 "svd_fuse.cpp"
  # 375 "svd_fuse.cpp"
  for (j_4 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; j_4 <= last_gang_iter_1 ; j_4 = j_4 + (hmpprt::gr_btnumy()))
  {
   # 372 "svd_fuse.cpp"
   hmpprt::s32 j_3;
   # 374 "svd_fuse.cpp"
   hmpprt::s32 i_3;
   # 376 "svd_fuse.cpp"
   i_3 = j_4 % 256;
   # 376 "svd_fuse.cpp"
   j_3 = j_4 / 256;
   # 376 "svd_fuse.cpp"
   *(B_H + (j_3 * 256 + i_3)) = *(A_H_1 + (j_3 * 256 + i_3)) / *(S_H_3 + j_3);
   # 377 "svd_fuse.cpp"
   *(B_H + (65536 + j_3 * 256 + i_3)) = *(A_H_1 + (65536 + j_3 * 256 + i_3)) / *(S_H_3 + j_3);
  }
  # 369 "svd_fuse.cpp"
 }
}
#endif // __CUDACC__



# 369 "svd_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_svd_369_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  B_H_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  S_H_1)
{
 # 369 "svd_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&A_H_7, 8, "A_H_1");
  __hmppcg_call.addLocalParameter(&B_H_2, 8, "B_H");
  __hmppcg_call.addLocalParameter(&S_H_1, 8, "S_H_3");
  __hmppcg_call.launch(hmpp_acc_region_svd_369_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 369 "svd_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_svd_369(double* A_H_4, double* B_H_1, double* S_H_5)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_svd_369_internal_1(hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (A_H_4), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (B_H_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (S_H_5)));
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
      hmpp_acc_region_svd_129_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_129_parallel_region_1");
      hmpp_acc_region_svd_338_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_338_parallel_region_1");
      hmpp_acc_region_svd_369_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_svd_369_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_129", "prototype hmpp_acc_region_svd_129(pass: ^host s32, A_H: ^cudaglob double, V_H: ^cudaglob double, rotate_col_idx: ^cudaglob s32, ci: ^cudaglob double, cj: ^cudaglob double, vi: ^cudaglob double, vj: ^cudaglob double, start_index: s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_338", "prototype hmpp_acc_region_svd_338(A_H: ^cudaglob double, S_H: ^cudaglob double, ci: ^cudaglob double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_369", "prototype hmpp_acc_region_svd_369(A_H: ^cudaglob double, B_H: ^cudaglob double, S_H: ^cudaglob double)");

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
      delete hmpp_acc_region_svd_129_parallel_region_1;
      delete hmpp_acc_region_svd_338_parallel_region_1;
      delete hmpp_acc_region_svd_369_parallel_region_1;

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
