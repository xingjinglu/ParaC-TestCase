
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

#define HMPPCG_SIMD_LENGTH 1

# 23 "sharpness_fuse.cpp"

#ifdef __CUDACC__
__device__ hmpprt::s64 reduce_s64_add_y(hmpprt::s64 priv, hmpprt::s64* tmpa_1, hmpprt::s64 orig)
;
#endif // __CUDACC__



# 23 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_82(hmpprt::s32 width_32, hmpprt::s32 height_16, hmpprt::s32 quarterWidth_9, hmpprt::u08* yPlane_6, hmpprt::u08* yPlaneDown_7)
;
#endif // __CUDACC__



# 23 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_82_internal_1(hmpprt::s32 width_60, hmpprt::s32 height_30, hmpprt::s32 quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_15)
;
#endif // __CUDACC__



# 458 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_82_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_82_parallel_region_1(hmpprt::s32 height_1, hmpprt::s32 quarterWidth_1, hmpprt::s32 width_1, hmpprt::u08* yPlaneDown_1, hmpprt::u08* yPlane_1);
#endif // __CUDACC__




# 458 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_462(hmpprt::s32 width_34, hmpprt::s32 height_20, hmpprt::u08* yPlane_7, hmpprt::s16* pSharpness_4)
;
#endif // __CUDACC__



# 458 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_462_internal_1(hmpprt::s32 width_61, hmpprt::s32 height_31, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_8)
;
#endif // __CUDACC__



# 417 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_462_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_462_parallel_region_1(hmpprt::s32 height_2, hmpprt::s16* pSharpness_1, hmpprt::s32 width_2, hmpprt::u08* yPlane_2);
#endif // __CUDACC__




# 417 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_408(hmpprt::s32 width_43, hmpprt::s32 height_21, hmpprt::u08* yPlane_8, hmpprt::s16* pEdge_5, hmpprt::s16* pSharpness_2, float cutoff3_1, float order3_2, float peak3, float low3_1)
;
#endif // __CUDACC__



# 417 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_408_internal_1(hmpprt::s32 width_62, hmpprt::s32 height_32, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_6, float cutoff3_2, float order3_1, float peak3_2, float low3_2)
;
#endif // __CUDACC__



# 392 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_408_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_408_parallel_region_1(float cutoff3, hmpprt::s32 height_3, float low3, float order3, hmpprt::s16* pEdge_1, hmpprt::s16* pSharpness_5, float peak3_1, hmpprt::s32 width_3, hmpprt::u08* yPlane_3);
#endif // __CUDACC__




# 392 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_389(hmpprt::s32 width_45, hmpprt::s32 height_22, hmpprt::u08* yPlaneCSER_16, hmpprt::s16* pError_3, hmpprt::s16* pEdge_6, hmpprt::s16* pSharpness_3, double cutoff_1, double peak_1, double cutoff2_1, double order_1, double order2_1, double low_1)
;
#endif // __CUDACC__



# 392 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_389_internal_1(hmpprt::s32 width_63, hmpprt::s32 height_33, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_7, double cutoff_2, double peak_2, double cutoff2_2, double order_2, double order2_2, double low_2)
;
#endif // __CUDACC__



# 361 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_389_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_389_parallel_region_1(double cutoff, double cutoff2, hmpprt::s32 height_4, double low, double order, double order2, hmpprt::s16* pEdge_2, hmpprt::s16* pError_1, hmpprt::s16* pSharpness, double peak, hmpprt::s32 width_4, hmpprt::u08* yPlaneCSER_1);
#endif // __CUDACC__




# 361 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_376(hmpprt::s32 width_46, hmpprt::s32 height_23, hmpprt::u08* yPlane_9, hmpprt::u08* yPlaneCSER_22, hmpprt::s16* pError_2)
;
#endif // __CUDACC__



# 361 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_376_internal_1(hmpprt::s32 width_64, hmpprt::s32 height_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_4)
;
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_376_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_376_parallel_region_1(hmpprt::s32 height_5, hmpprt::s16* pError, hmpprt::s32 width_5, hmpprt::u08* yPlaneCSER_2, hmpprt::u08* yPlane_4);
#endif // __CUDACC__




# 342 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_339(hmpprt::s32 width_47, hmpprt::s32 height_24, hmpprt::s16* pEdge_7, hmpprt::s64* sum)
;
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_339_internal_1(hmpprt::s32 width_65, hmpprt::s32 height_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  sum_4)
;
#endif // __CUDACC__



# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_339_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_339_parallel_region_1(hmpprt::s64* gang_prv_red_sum_1, hmpprt::s32 height_6, hmpprt::s16* pEdge_3, hmpprt::s32 width_6);
#endif // __CUDACC__




# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * reduce_s64_add_xy = 0;
#else

extern "C" __global__ void reduce_s64_add_xy(hmpprt::s64 neutral, hmpprt::s64* scalar, hmpprt::s32 size, hmpprt::s64* array);
#endif // __CUDACC__




# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_316(hmpprt::s32 width_48, hmpprt::s32 height_25, hmpprt::u08* yPlane_5, hmpprt::s16* pEdge_4)
;
#endif // __CUDACC__



# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_316_internal_1(hmpprt::s32 width_66, hmpprt::s32 height_36, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_8)
;
#endif // __CUDACC__



# 279 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_316_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_316_parallel_region_1(hmpprt::s32 height_7, hmpprt::s16* pEdge, hmpprt::s32 width_7, hmpprt::u08* yPlane);
#endif // __CUDACC__




# 279 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_279(hmpprt::s32* width_8, hmpprt::s32 quarterWidth_17, hmpprt::s32 quarterHeight_7, hmpprt::u08* yPlaneCSER_23, hmpprt::u08* yPlaneDown_8)
;
#endif // __CUDACC__



# 279 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_279_internal_1(hmpprt::s32* width_67, hmpprt::s32 quarterWidth_10, hmpprt::s32 quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_16)
;
#endif // __CUDACC__



# 267 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_279_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_279_loop1D_1(hmpprt::s32 quarterWidth_2, hmpprt::s32 quarterHeight_1, hmpprt::u08* yPlaneCSER_3, hmpprt::u08* yPlaneDown_2, hmpprt::s32 width_30);
#endif // __CUDACC__




# 267 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_267(hmpprt::s32* width_9, hmpprt::s32 height_8, hmpprt::u08* yPlaneCSER_4)
;
#endif // __CUDACC__



# 267 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_267_internal_1(hmpprt::s32* width_68, hmpprt::s32 height_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_44)
;
#endif // __CUDACC__



# 244 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_267_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_267_loop1D_1(hmpprt::s32 width_42, hmpprt::s32 height_26, hmpprt::u08* yPlaneCSER_24);
#endif // __CUDACC__




# 244 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_244(hmpprt::s32* width_10, hmpprt::s32 quarterHeight_16, hmpprt::u08* yPlaneCSER_39)
;
#endif // __CUDACC__



# 244 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_244_internal_1(hmpprt::s32* width_50, hmpprt::s32 quarterHeight_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_25)
;
#endif // __CUDACC__



# 238 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_244_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_244_loop1D_1(hmpprt::s32 quarterHeight_2, hmpprt::u08* yPlaneCSER_5, hmpprt::s32 width_28);
#endif // __CUDACC__




# 238 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_232(hmpprt::s32* width_11, hmpprt::s32 quarterWidth_3, hmpprt::s32 quarterHeight_9, hmpprt::u08* yPlaneCSER_26, hmpprt::u08* yPlaneDown_9)
;
#endif // __CUDACC__



# 238 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_232_internal_1(hmpprt::s32* width_51, hmpprt::s32 quarterWidth_21, hmpprt::s32 quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_40, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_17)
;
#endif // __CUDACC__



# 223 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_232_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_232_loop1D_1(hmpprt::s32 quarterWidth_11, hmpprt::s32 quarterHeight_3, hmpprt::u08* yPlaneCSER_6, hmpprt::u08* yPlaneDown_3, hmpprt::s32 width_27);
#endif // __CUDACC__




# 223 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_220(hmpprt::s32* width_12, hmpprt::s32* height_38, hmpprt::u08* yPlaneCSER_27)
;
#endif // __CUDACC__



# 223 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_220_internal_1(hmpprt::s32* width_52, hmpprt::s32* height_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_41)
;
#endif // __CUDACC__



# 216 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_220_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_220_loop1D_1(hmpprt::u08* yPlaneCSER_7, hmpprt::s32 width_26, hmpprt::s32 height_14);
#endif // __CUDACC__




# 216 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_211(hmpprt::s32* width_13, hmpprt::u08* yPlaneCSER_28)
;
#endif // __CUDACC__



# 216 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_211_internal_1(hmpprt::s32* width_53, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_42)
;
#endif // __CUDACC__



# 193 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_211_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_211_loop1D_1(hmpprt::u08* yPlaneCSER_8, hmpprt::s32 width_25);
#endif // __CUDACC__




# 193 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_189(hmpprt::s32* width_14, hmpprt::s32* height_10, hmpprt::s32 quarterWidth_12, hmpprt::u08* yPlaneCSER_29)
;
#endif // __CUDACC__



# 193 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_189_internal_1(hmpprt::s32* width_54, hmpprt::s32* height_28, hmpprt::s32 quarterWidth_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_43)
;
#endif // __CUDACC__



# 177 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_189_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_189_loop1D_1(hmpprt::s32 quarterWidth_4, hmpprt::u08* yPlaneCSER_9, hmpprt::s32 width_24, hmpprt::s32 height_13);
#endif // __CUDACC__




# 177 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_172(hmpprt::s32* width_55, hmpprt::s32 quarterWidth_13, hmpprt::u08* yPlaneCSER_31)
;
#endif // __CUDACC__



# 177 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_172_internal_1(hmpprt::s32* width_15, hmpprt::s32 quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_10)
;
#endif // __CUDACC__



# 163 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_172_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_172_loop1D_1(hmpprt::s32 quarterWidth_5, hmpprt::u08* yPlaneCSER_17);
#endif // __CUDACC__




# 163 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_159(hmpprt::s32* width_56, hmpprt::s32* height_29, hmpprt::s32 quarterWidth_14, hmpprt::s32 quarterHeight_13, hmpprt::u08* yPlaneCSER_36, hmpprt::u08* yPlaneDown_13)
;
#endif // __CUDACC__



# 163 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_159_internal_1(hmpprt::s32* width_16, hmpprt::s32* height_11, hmpprt::s32 quarterWidth_20, hmpprt::s32 quarterHeight_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_4)
;
#endif // __CUDACC__



# 150 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_159_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_159_loop1D_1(hmpprt::s32 width_22, hmpprt::s32 height_12, hmpprt::s32 quarterWidth_6, hmpprt::s32 quarterHeight_4, hmpprt::u08* yPlaneCSER_11, hmpprt::u08* yPlaneDown_10);
#endif // __CUDACC__




# 150 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_151(hmpprt::s32* width_57, hmpprt::s32 quarterWidth_22, hmpprt::u08* yPlaneCSER_32, hmpprt::u08* yPlaneDown_14)
;
#endif // __CUDACC__



# 150 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_151_internal_1(hmpprt::s32* width_17, hmpprt::s32 quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_5)
;
#endif // __CUDACC__



# 138 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_151_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_151_loop1D_1(hmpprt::s32 quarterWidth_15, hmpprt::u08* yPlaneCSER_19, hmpprt::u08* yPlaneDown_11);
#endif // __CUDACC__




# 138 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_138(hmpprt::s32* width_18, hmpprt::s32 height_27, hmpprt::u08* yPlaneCSER_33)
;
#endif // __CUDACC__



# 138 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_138_internal_1(hmpprt::s32* width_58, hmpprt::s32 height, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_13)
;
#endif // __CUDACC__



# 117 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_138_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_138_loop1D_1(hmpprt::s32 width_35, hmpprt::s32 height_15, hmpprt::u08* yPlaneCSER_20);
#endif // __CUDACC__




# 117 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_117(hmpprt::s32 width_19, hmpprt::s32 quarterHeight_5, hmpprt::u08* yPlaneCSER_34)
;
#endif // __CUDACC__



# 117 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_117_internal_1(hmpprt::s32 width_59, hmpprt::s32 quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_14)
;
#endif // __CUDACC__



# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_117_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_117_parallel_region_1(hmpprt::s32 quarterHeight_11, hmpprt::s32 width_33, hmpprt::u08* yPlaneCSER_21);
#endif // __CUDACC__




# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_105(hmpprt::s32 width, hmpprt::s32 quarterWidth, hmpprt::s32 quarterHeight, hmpprt::u08* yPlaneCSER_30, hmpprt::u08* yPlaneDown)
;
#endif // __CUDACC__



# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_105_internal_1(hmpprt::s32 width_49, hmpprt::s32 quarterWidth_16, hmpprt::s32 quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_12)
;
#endif // __CUDACC__



# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_105_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_105_parallel_region_1(hmpprt::s32 quarterHeight_6, hmpprt::s32 quarterWidth_8, hmpprt::s32 width_31, hmpprt::u08* yPlaneCSER_15, hmpprt::u08* yPlaneDown_6);
#endif // __CUDACC__




# 101 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_105_parallel_region_1(hmpprt::s32 quarterHeight_6, hmpprt::s32 quarterWidth_8, hmpprt::s32 width_31, hmpprt::u08* yPlaneCSER_15, hmpprt::u08* yPlaneDown_6)
{
 # 103 "sharpness_fuse.cpp"
 {
  # 108 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_9;
  # 108 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_9;
  # 108 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_9;
  # 108 "sharpness_fuse.cpp"
  iter_per_gang_9 = ((1 + (quarterHeight_6 - 1) / 192) > 256 ? (1 + (quarterHeight_6 - 1) / 192) : 256);
  # 108 "sharpness_fuse.cpp"
  first_gang_iter_9 = (hmpprt::gr_gbidx()) * iter_per_gang_9;
  # 108 "sharpness_fuse.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (quarterHeight_6 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (quarterHeight_6 - 1));
  # 108 "sharpness_fuse.cpp"
  hmpprt::s32 h_11;
  # 108 "sharpness_fuse.cpp"
  # 109 "sharpness_fuse.cpp"
  for (h_11 = first_gang_iter_9 + (hmpprt::gr_btidy()) ; h_11 <= last_gang_iter_9 ; h_11 = h_11 + (hmpprt::gr_btnumy()))
  {
   # 110 "sharpness_fuse.cpp"
   *(yPlaneCSER_15 + h_11 * 4 * width_31) = *(yPlaneDown_6 + h_11 * quarterWidth_8);
  }
  # 101 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_105_internal_1(hmpprt::s32 width_49, hmpprt::s32 quarterWidth_16, hmpprt::s32 quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_12)
{
 # 101 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_12), "quarterHeight_6");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_16), "quarterWidth_8");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_49), "width_31");
  __hmppcg_call.addLocalParameter(&yPlaneCSER, 8, "yPlaneCSER_15");
  __hmppcg_call.addLocalParameter(&yPlaneDown_12, 8, "yPlaneDown_6");
  __hmppcg_call.launch(hmpp_acc_region_main_105_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 101 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_105(hmpprt::s32 width, hmpprt::s32 quarterWidth, hmpprt::s32 quarterHeight, hmpprt::u08* yPlaneCSER_30, hmpprt::u08* yPlaneDown)
{
 # 117 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_105_internal_1(width, quarterWidth, quarterHeight, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_30), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown)));
}
#endif // __CUDACC__



# 117 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_117_parallel_region_1(hmpprt::s32 quarterHeight_11, hmpprt::s32 width_33, hmpprt::u08* yPlaneCSER_21)
{
 # 119 "sharpness_fuse.cpp"
 {
  # 120 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_8;
  # 120 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_8;
  # 120 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_8;
  # 120 "sharpness_fuse.cpp"
  iter_per_gang_8 = ((1 + (quarterHeight_11 - 1) / 192) > 256 ? (1 + (quarterHeight_11 - 1) / 192) : 256);
  # 120 "sharpness_fuse.cpp"
  first_gang_iter_8 = (hmpprt::gr_gbidx()) * iter_per_gang_8;
  # 120 "sharpness_fuse.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (quarterHeight_11 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (quarterHeight_11 - 1));
  # 120 "sharpness_fuse.cpp"
  hmpprt::s32 h_12;
  # 120 "sharpness_fuse.cpp"
  # 121 "sharpness_fuse.cpp"
  for (h_12 = first_gang_iter_8 + (hmpprt::gr_btidy()) ; h_12 <= last_gang_iter_8 ; h_12 = h_12 + (hmpprt::gr_btnumy()))
  {
   # 122 "sharpness_fuse.cpp"
   if (h_12 < quarterHeight_11 - 1)
   {
    # 124 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33))) / 4);
    # 125 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 2) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 2) / 4);
    # 126 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 3) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 3) / 4);
   }
   else
   {
    # 130 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = *(yPlaneCSER_21 + h_12 * 4 * width_33);
   }
  }
  # 117 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 117 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_117_internal_1(hmpprt::s32 width_59, hmpprt::s32 quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_14)
{
 # 117 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_14), "quarterHeight_11");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_59), "width_33");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_14, 8, "yPlaneCSER_21");
  __hmppcg_call.launch(hmpp_acc_region_main_117_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 117 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_117(hmpprt::s32 width_19, hmpprt::s32 quarterHeight_5, hmpprt::u08* yPlaneCSER_34)
{
 # 138 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_117_internal_1(width_19, quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_34)));
}
#endif // __CUDACC__



# 138 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_138_loop1D_1(hmpprt::s32 width_35, hmpprt::s32 height_15, hmpprt::u08* yPlaneCSER_20)
{
 # 141 "sharpness_fuse.cpp"
 hmpprt::s32 h_13;
 # 143 "sharpness_fuse.cpp"
 h_13 = (hmpprt::gr_atidf());
 # 143 "sharpness_fuse.cpp"
 if (h_13 > height_15 - 1)
 {
  # 143 "sharpness_fuse.cpp"
  goto __hmppcg_label_1;
 }
 # 143 "sharpness_fuse.cpp"
 *(yPlaneCSER_20 + (h_13 * width_35 + 1)) = *(yPlaneCSER_20 + h_13 * width_35);
 # 138 "sharpness_fuse.cpp"
 __hmppcg_label_1:;
}
#endif // __CUDACC__



# 138 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_138_internal_1(hmpprt::s32* width_58, hmpprt::s32 height, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_13)
{
 # 140 "sharpness_fuse.cpp"
 hmpprt::s32 width_20;
 # 140 "sharpness_fuse.cpp"
 width_20 = *width_58;
 # 140 "sharpness_fuse.cpp"
 {
  # 138 "sharpness_fuse.cpp"
  if (height - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_35");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height), "height_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_13, 8, "yPlaneCSER_20");
   __hmppcg_call.launch(hmpp_acc_region_main_138_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 138 "sharpness_fuse.cpp"
 *width_58 = width_20;
}
#endif // __CUDACC__



# 138 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_138(hmpprt::s32* width_18, hmpprt::s32 height_27, hmpprt::u08* yPlaneCSER_33)
{
 # 150 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_138_internal_1(width_18, height_27, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_33)));
}
#endif // __CUDACC__



# 150 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_151_loop1D_1(hmpprt::s32 quarterWidth_15, hmpprt::u08* yPlaneCSER_19, hmpprt::u08* yPlaneDown_11)
{
 # 154 "sharpness_fuse.cpp"
 hmpprt::s32 w_11;
 # 156 "sharpness_fuse.cpp"
 w_11 = (hmpprt::gr_atidf());
 # 156 "sharpness_fuse.cpp"
 if (w_11 > quarterWidth_15 - 1)
 {
  # 156 "sharpness_fuse.cpp"
  goto __hmppcg_label_2;
 }
 # 156 "sharpness_fuse.cpp"
 *(yPlaneCSER_19 + w_11 * 4) = *(yPlaneDown_11 + w_11);
 # 150 "sharpness_fuse.cpp"
 __hmppcg_label_2:;
}
#endif // __CUDACC__



# 150 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_151_internal_1(hmpprt::s32* width_17, hmpprt::s32 quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_5)
{
 # 152 "sharpness_fuse.cpp"
 hmpprt::s32 width_21;
 # 152 "sharpness_fuse.cpp"
 width_21 = *width_17;
 # 152 "sharpness_fuse.cpp"
 {
  # 150 "sharpness_fuse.cpp"
  if (quarterWidth_7 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_7 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_7), "quarterWidth_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_12, 8, "yPlaneCSER_19");
   __hmppcg_call.addLocalParameter(&yPlaneDown_5, 8, "yPlaneDown_11");
   __hmppcg_call.launch(hmpp_acc_region_main_151_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 150 "sharpness_fuse.cpp"
 *width_17 = width_21;
}
#endif // __CUDACC__



# 150 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_151(hmpprt::s32* width_57, hmpprt::s32 quarterWidth_22, hmpprt::u08* yPlaneCSER_32, hmpprt::u08* yPlaneDown_14)
{
 # 163 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_151_internal_1(width_57, quarterWidth_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_32), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_14)));
}
#endif // __CUDACC__



# 163 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_159_loop1D_1(hmpprt::s32 width_22, hmpprt::s32 height_12, hmpprt::s32 quarterWidth_6, hmpprt::s32 quarterHeight_4, hmpprt::u08* yPlaneCSER_11, hmpprt::u08* yPlaneDown_10)
{
 # 168 "sharpness_fuse.cpp"
 hmpprt::s32 w_12;
 # 170 "sharpness_fuse.cpp"
 w_12 = (hmpprt::gr_atidf());
 # 170 "sharpness_fuse.cpp"
 if (w_12 > quarterWidth_6 - 1)
 {
  # 170 "sharpness_fuse.cpp"
  goto __hmppcg_label_3;
 }
 # 170 "sharpness_fuse.cpp"
 *(yPlaneCSER_11 + ((height_12 - 2) * width_22 + w_12 * 4)) = *(yPlaneDown_10 + ((quarterHeight_4 - 1) * quarterWidth_6 + w_12));
 # 163 "sharpness_fuse.cpp"
 __hmppcg_label_3:;
}
#endif // __CUDACC__



# 163 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_159_internal_1(hmpprt::s32* width_16, hmpprt::s32* height_11, hmpprt::s32 quarterWidth_20, hmpprt::s32 quarterHeight_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_4)
{
 # 165 "sharpness_fuse.cpp"
 hmpprt::s32 height_17;
 # 165 "sharpness_fuse.cpp"
 height_17 = *height_11;
 # 165 "sharpness_fuse.cpp"
 hmpprt::s32 width_36;
 # 165 "sharpness_fuse.cpp"
 width_36 = *width_16;
 # 165 "sharpness_fuse.cpp"
 {
  # 163 "sharpness_fuse.cpp"
  if (quarterWidth_20 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_20 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_36), "width_22");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_17), "height_12");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_20), "quarterWidth_6");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_10), "quarterHeight_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_18, 8, "yPlaneCSER_11");
   __hmppcg_call.addLocalParameter(&yPlaneDown_4, 8, "yPlaneDown_10");
   __hmppcg_call.launch(hmpp_acc_region_main_159_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 163 "sharpness_fuse.cpp"
 *width_16 = width_36;
 # 163 "sharpness_fuse.cpp"
 *height_11 = height_17;
}
#endif // __CUDACC__



# 163 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_159(hmpprt::s32* width_56, hmpprt::s32* height_29, hmpprt::s32 quarterWidth_14, hmpprt::s32 quarterHeight_13, hmpprt::u08* yPlaneCSER_36, hmpprt::u08* yPlaneDown_13)
{
 # 177 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_159_internal_1(width_56, height_29, quarterWidth_14, quarterHeight_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_36), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_13)));
}
#endif // __CUDACC__



# 177 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_172_loop1D_1(hmpprt::s32 quarterWidth_5, hmpprt::u08* yPlaneCSER_17)
{
 # 175 "sharpness_fuse.cpp"
 hmpprt::s32 w_13;
 # 177 "sharpness_fuse.cpp"
 w_13 = (hmpprt::gr_atidf());
 # 177 "sharpness_fuse.cpp"
 if (w_13 > quarterWidth_5 - 1)
 {
  # 177 "sharpness_fuse.cpp"
  goto __hmppcg_label_4;
 }
 # 177 "sharpness_fuse.cpp"
 if (w_13 < quarterWidth_5 - 1)
 {
  # 179 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_17 + w_13 * 4)) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_17 + (w_13 * 4 + 4)))) / 4);
  # 180 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_17 + w_13 * 4)) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_17 + (w_13 * 4 + 4))) * 2) / 4);
  # 181 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_17 + w_13 * 4)) + (hmpprt::s32 ) (*(yPlaneCSER_17 + (w_13 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 185 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 1)) = *(yPlaneCSER_17 + w_13 * 4);
 }
 # 177 "sharpness_fuse.cpp"
 __hmppcg_label_4:;
}
#endif // __CUDACC__



# 177 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_172_internal_1(hmpprt::s32* width_15, hmpprt::s32 quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_10)
{
 # 179 "sharpness_fuse.cpp"
 hmpprt::s32 width_23;
 # 179 "sharpness_fuse.cpp"
 width_23 = *width_15;
 # 179 "sharpness_fuse.cpp"
 {
  # 177 "sharpness_fuse.cpp"
  if (quarterWidth_19 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_19 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_19), "quarterWidth_5");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_10, 8, "yPlaneCSER_17");
   __hmppcg_call.launch(hmpp_acc_region_main_172_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 177 "sharpness_fuse.cpp"
 *width_15 = width_23;
}
#endif // __CUDACC__



# 177 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_172(hmpprt::s32* width_55, hmpprt::s32 quarterWidth_13, hmpprt::u08* yPlaneCSER_31)
{
 # 193 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_172_internal_1(width_55, quarterWidth_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_31)));
}
#endif // __CUDACC__



# 193 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_189_loop1D_1(hmpprt::s32 quarterWidth_4, hmpprt::u08* yPlaneCSER_9, hmpprt::s32 width_24, hmpprt::s32 height_13)
{
 # 198 "sharpness_fuse.cpp"
 hmpprt::s32 w_14;
 # 200 "sharpness_fuse.cpp"
 w_14 = (hmpprt::gr_atidf());
 # 200 "sharpness_fuse.cpp"
 if (w_14 > quarterWidth_4 - 1)
 {
  # 200 "sharpness_fuse.cpp"
  goto __hmppcg_label_5;
 }
 # 200 "sharpness_fuse.cpp"
 if (w_14 < quarterWidth_4 - 1)
 {
  # 202 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4)))) / 4);
  # 203 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4))) * 2) / 4);
  # 204 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) + (hmpprt::s32 ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 208 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 1)) = *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4));
 }
 # 193 "sharpness_fuse.cpp"
 __hmppcg_label_5:;
}
#endif // __CUDACC__



# 193 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_189_internal_1(hmpprt::s32* width_54, hmpprt::s32* height_28, hmpprt::s32 quarterWidth_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_43)
{
 # 195 "sharpness_fuse.cpp"
 hmpprt::s32 height_18;
 # 195 "sharpness_fuse.cpp"
 height_18 = *height_28;
 # 195 "sharpness_fuse.cpp"
 hmpprt::s32 width_37;
 # 195 "sharpness_fuse.cpp"
 width_37 = *width_54;
 # 195 "sharpness_fuse.cpp"
 {
  # 193 "sharpness_fuse.cpp"
  if (quarterWidth_18 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_18 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_18), "quarterWidth_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_43, 8, "yPlaneCSER_9");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_37), "width_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_13");
   __hmppcg_call.launch(hmpp_acc_region_main_189_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 193 "sharpness_fuse.cpp"
 *width_54 = width_37;
 # 193 "sharpness_fuse.cpp"
 *height_28 = height_18;
}
#endif // __CUDACC__



# 193 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_189(hmpprt::s32* width_14, hmpprt::s32* height_10, hmpprt::s32 quarterWidth_12, hmpprt::u08* yPlaneCSER_29)
{
 # 216 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_189_internal_1(width_14, height_10, quarterWidth_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_29)));
}
#endif // __CUDACC__



# 216 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_211_loop1D_1(hmpprt::u08* yPlaneCSER_8, hmpprt::s32 width_25)
{
 # 214 "sharpness_fuse.cpp"
 hmpprt::s32 w_15;
 # 216 "sharpness_fuse.cpp"
 w_15 = (hmpprt::gr_atidf());
 # 216 "sharpness_fuse.cpp"
 if (w_15 > width_25 - 1)
 {
  # 216 "sharpness_fuse.cpp"
  goto __hmppcg_label_6;
 }
 # 216 "sharpness_fuse.cpp"
 *(yPlaneCSER_8 + (width_25 + w_15)) = *(yPlaneCSER_8 + w_15);
 # 216 "sharpness_fuse.cpp"
 __hmppcg_label_6:;
}
#endif // __CUDACC__



# 216 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_211_internal_1(hmpprt::s32* width_53, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_42)
{
 # 218 "sharpness_fuse.cpp"
 hmpprt::s32 width_38;
 # 218 "sharpness_fuse.cpp"
 width_38 = *width_53;
 # 218 "sharpness_fuse.cpp"
 {
  # 216 "sharpness_fuse.cpp"
  if (width_38 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_38 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_42, 8, "yPlaneCSER_8");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_38), "width_25");
   __hmppcg_call.launch(hmpp_acc_region_main_211_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 216 "sharpness_fuse.cpp"
 *width_53 = width_38;
}
#endif // __CUDACC__



# 216 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_211(hmpprt::s32* width_13, hmpprt::u08* yPlaneCSER_28)
{
 # 223 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_211_internal_1(width_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_28)));
}
#endif // __CUDACC__



# 223 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_220_loop1D_1(hmpprt::u08* yPlaneCSER_7, hmpprt::s32 width_26, hmpprt::s32 height_14)
{
 # 229 "sharpness_fuse.cpp"
 hmpprt::s32 w_16;
 # 231 "sharpness_fuse.cpp"
 w_16 = (hmpprt::gr_atidf());
 # 231 "sharpness_fuse.cpp"
 if (w_16 > width_26 - 1)
 {
  # 231 "sharpness_fuse.cpp"
  goto __hmppcg_label_7;
 }
 # 231 "sharpness_fuse.cpp"
 *(yPlaneCSER_7 + ((height_14 - 1) * width_26 + w_16)) = *(yPlaneCSER_7 + ((height_14 - 2) * width_26 + w_16));
 # 223 "sharpness_fuse.cpp"
 __hmppcg_label_7:;
}
#endif // __CUDACC__



# 223 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_220_internal_1(hmpprt::s32* width_52, hmpprt::s32* height_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_41)
{
 # 225 "sharpness_fuse.cpp"
 hmpprt::s32 height_19;
 # 225 "sharpness_fuse.cpp"
 height_19 = *height_9;
 # 225 "sharpness_fuse.cpp"
 hmpprt::s32 width_39;
 # 225 "sharpness_fuse.cpp"
 width_39 = *width_52;
 # 225 "sharpness_fuse.cpp"
 {
  # 223 "sharpness_fuse.cpp"
  if (width_39 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_39 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_41, 8, "yPlaneCSER_7");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_39), "width_26");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_14");
   __hmppcg_call.launch(hmpp_acc_region_main_220_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 223 "sharpness_fuse.cpp"
 *width_52 = width_39;
 # 223 "sharpness_fuse.cpp"
 *height_9 = height_19;
}
#endif // __CUDACC__



# 223 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_220(hmpprt::s32* width_12, hmpprt::s32* height_38, hmpprt::u08* yPlaneCSER_27)
{
 # 238 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_220_internal_1(width_12, height_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_27)));
}
#endif // __CUDACC__



# 238 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_232_loop1D_1(hmpprt::s32 quarterWidth_11, hmpprt::s32 quarterHeight_3, hmpprt::u08* yPlaneCSER_6, hmpprt::u08* yPlaneDown_3, hmpprt::s32 width_27)
{
 # 235 "sharpness_fuse.cpp"
 hmpprt::s32 h_14;
 # 237 "sharpness_fuse.cpp"
 h_14 = (hmpprt::gr_atidf());
 # 237 "sharpness_fuse.cpp"
 if (h_14 > quarterHeight_3 - 1)
 {
  # 237 "sharpness_fuse.cpp"
  goto __hmppcg_label_8;
 }
 # 237 "sharpness_fuse.cpp"
 *(yPlaneCSER_6 + (h_14 * 4 * width_27 + width_27 - 2)) = *(yPlaneDown_3 + (h_14 * quarterWidth_11 + quarterWidth_11 - 1));
 # 238 "sharpness_fuse.cpp"
 __hmppcg_label_8:;
}
#endif // __CUDACC__



# 238 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_232_internal_1(hmpprt::s32* width_51, hmpprt::s32 quarterWidth_21, hmpprt::s32 quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_40, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_17)
{
 # 240 "sharpness_fuse.cpp"
 hmpprt::s32 width_40;
 # 240 "sharpness_fuse.cpp"
 width_40 = *width_51;
 # 240 "sharpness_fuse.cpp"
 {
  # 238 "sharpness_fuse.cpp"
  if (quarterHeight_17 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_21), "quarterWidth_11");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_17), "quarterHeight_3");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_40, 8, "yPlaneCSER_6");
   __hmppcg_call.addLocalParameter(&yPlaneDown_17, 8, "yPlaneDown_3");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_40), "width_27");
   __hmppcg_call.launch(hmpp_acc_region_main_232_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 238 "sharpness_fuse.cpp"
 *width_51 = width_40;
}
#endif // __CUDACC__



# 238 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_232(hmpprt::s32* width_11, hmpprt::s32 quarterWidth_3, hmpprt::s32 quarterHeight_9, hmpprt::u08* yPlaneCSER_26, hmpprt::u08* yPlaneDown_9)
{
 # 244 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_232_internal_1(width_11, quarterWidth_3, quarterHeight_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_26), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_9)));
}
#endif // __CUDACC__



# 244 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_244_loop1D_1(hmpprt::s32 quarterHeight_2, hmpprt::u08* yPlaneCSER_5, hmpprt::s32 width_28)
{
 # 247 "sharpness_fuse.cpp"
 hmpprt::s32 h_15;
 # 249 "sharpness_fuse.cpp"
 h_15 = (hmpprt::gr_atidf());
 # 249 "sharpness_fuse.cpp"
 if (h_15 > quarterHeight_2 - 1)
 {
  # 249 "sharpness_fuse.cpp"
  goto __hmppcg_label_9;
 }
 # 249 "sharpness_fuse.cpp"
 if (h_15 < quarterHeight_2 - 1)
 {
  # 251 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2)))) / 4);
  # 252 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 2) / 4);
  # 253 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) + (hmpprt::s32 ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 3) / 4);
 }
 else
 {
  # 257 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
  # 258 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
  # 259 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
 }
 # 244 "sharpness_fuse.cpp"
 __hmppcg_label_9:;
}
#endif // __CUDACC__



# 244 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_244_internal_1(hmpprt::s32* width_50, hmpprt::s32 quarterHeight_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_25)
{
 # 246 "sharpness_fuse.cpp"
 hmpprt::s32 width_41;
 # 246 "sharpness_fuse.cpp"
 width_41 = *width_50;
 # 246 "sharpness_fuse.cpp"
 {
  # 244 "sharpness_fuse.cpp"
  if (quarterHeight_8 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_8 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_8), "quarterHeight_2");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_25, 8, "yPlaneCSER_5");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_41), "width_28");
   __hmppcg_call.launch(hmpp_acc_region_main_244_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 244 "sharpness_fuse.cpp"
 *width_50 = width_41;
}
#endif // __CUDACC__



# 244 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_244(hmpprt::s32* width_10, hmpprt::s32 quarterHeight_16, hmpprt::u08* yPlaneCSER_39)
{
 # 267 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_244_internal_1(width_10, quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_39)));
}
#endif // __CUDACC__



# 267 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_267_loop1D_1(hmpprt::s32 width_42, hmpprt::s32 height_26, hmpprt::u08* yPlaneCSER_24)
{
 # 270 "sharpness_fuse.cpp"
 hmpprt::s32 h_16;
 # 272 "sharpness_fuse.cpp"
 h_16 = (hmpprt::gr_atidf());
 # 272 "sharpness_fuse.cpp"
 if (h_16 > height_26 - 1)
 {
  # 272 "sharpness_fuse.cpp"
  goto __hmppcg_label_10;
 }
 # 272 "sharpness_fuse.cpp"
 *(yPlaneCSER_24 + (h_16 * width_42 + width_42 - 1)) = *(yPlaneCSER_24 + (h_16 * width_42 + width_42 - 2));
 # 267 "sharpness_fuse.cpp"
 __hmppcg_label_10:;
}
#endif // __CUDACC__



# 267 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_267_internal_1(hmpprt::s32* width_68, hmpprt::s32 height_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_44)
{
 # 269 "sharpness_fuse.cpp"
 hmpprt::s32 width_29;
 # 269 "sharpness_fuse.cpp"
 width_29 = *width_68;
 # 269 "sharpness_fuse.cpp"
 {
  # 267 "sharpness_fuse.cpp"
  if (height_37 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_37 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_29), "width_42");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_37), "height_26");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_44, 8, "yPlaneCSER_24");
   __hmppcg_call.launch(hmpp_acc_region_main_267_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 267 "sharpness_fuse.cpp"
 *width_68 = width_29;
}
#endif // __CUDACC__



# 267 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_267(hmpprt::s32* width_9, hmpprt::s32 height_8, hmpprt::u08* yPlaneCSER_4)
{
 # 279 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_267_internal_1(width_9, height_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_4)));
}
#endif // __CUDACC__



# 279 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_279_loop1D_1(hmpprt::s32 quarterWidth_2, hmpprt::s32 quarterHeight_1, hmpprt::u08* yPlaneCSER_3, hmpprt::u08* yPlaneDown_2, hmpprt::s32 width_30)
{
 # 282 "sharpness_fuse.cpp"
 hmpprt::s32 h_17;
 # 285 "sharpness_fuse.cpp"
 hmpprt::s32 w_17;
 # 282 "sharpness_fuse.cpp"
 hmpprt::s32 h_22;
 # 287 "sharpness_fuse.cpp"
 h_22 = (hmpprt::gr_atidf());
 # 287 "sharpness_fuse.cpp"
 if (h_22 > (quarterHeight_1 +  -1) * (quarterWidth_2 - 1) - 1)
 {
  # 287 "sharpness_fuse.cpp"
  goto __hmppcg_label_11;
 }
 # 287 "sharpness_fuse.cpp"
 w_17 = h_22 % (quarterWidth_2 +  -1);
 # 287 "sharpness_fuse.cpp"
 h_17 = h_22 / (quarterWidth_2 +  -1);
 # 287 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) / 8 / 8);
 # 288 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8);
 # 289 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8);
 # 290 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8);
 # 292 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8);
 # 293 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8);
 # 294 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8);
 # 295 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8);
 # 297 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8);
 # 298 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8);
 # 299 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8);
 # 300 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8);
 # 302 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8);
 # 303 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8);
 # 304 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8);
 # 305 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8);
 # 279 "sharpness_fuse.cpp"
 __hmppcg_label_11:;
}
#endif // __CUDACC__



# 279 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_279_internal_1(hmpprt::s32* width_67, hmpprt::s32 quarterWidth_10, hmpprt::s32 quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_16)
{
 # 281 "sharpness_fuse.cpp"
 hmpprt::s32 width_44;
 # 281 "sharpness_fuse.cpp"
 width_44 = *width_67;
 # 281 "sharpness_fuse.cpp"
 {
  # 279 "sharpness_fuse.cpp"
  if ((quarterHeight_15 +  -1) * (quarterWidth_10 - 1) - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX(((quarterHeight_15 +  -1) * (quarterWidth_10 - 1) - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_10), "quarterWidth_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_15), "quarterHeight_1");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_38, 8, "yPlaneCSER_3");
   __hmppcg_call.addLocalParameter(&yPlaneDown_16, 8, "yPlaneDown_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_44), "width_30");
   __hmppcg_call.launch(hmpp_acc_region_main_279_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 279 "sharpness_fuse.cpp"
 *width_67 = width_44;
}
#endif // __CUDACC__



# 279 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_279(hmpprt::s32* width_8, hmpprt::s32 quarterWidth_17, hmpprt::s32 quarterHeight_7, hmpprt::u08* yPlaneCSER_23, hmpprt::u08* yPlaneDown_8)
{
 # 313 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_279_internal_1(width_8, quarterWidth_17, quarterHeight_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_23), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_8)));
}
#endif // __CUDACC__



# 313 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_316_parallel_region_1(hmpprt::s32 height_7, hmpprt::s16* pEdge, hmpprt::s32 width_7, hmpprt::u08* yPlane)
{
 # 315 "sharpness_fuse.cpp"
 {
  # 319 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_7;
  # 319 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_7;
  # 319 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_7;
  # 319 "sharpness_fuse.cpp"
  iter_per_gang_7 = ((1 + (height_7 * width_7 - 1) / 192) > 256 ? (1 + (height_7 * width_7 - 1) / 192) : 256);
  # 319 "sharpness_fuse.cpp"
  first_gang_iter_7 = (hmpprt::gr_gbidx()) * iter_per_gang_7;
  # 319 "sharpness_fuse.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (height_7 * width_7 - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (height_7 * width_7 - 1));
  # 319 "sharpness_fuse.cpp"
  hmpprt::s32 y_2;
  # 319 "sharpness_fuse.cpp"
  # 323 "sharpness_fuse.cpp"
  for (y_2 = first_gang_iter_7 + (hmpprt::gr_btidy()) ; y_2 <= last_gang_iter_7 ; y_2 = y_2 + (hmpprt::gr_btnumy()))
  {
   # 319 "sharpness_fuse.cpp"
   hmpprt::s32 y_1;
   # 322 "sharpness_fuse.cpp"
   hmpprt::s32 x_1;
   # 324 "sharpness_fuse.cpp"
   x_1 = y_2 % width_7;
   # 324 "sharpness_fuse.cpp"
   y_1 = y_2 / width_7;
   # 324 "sharpness_fuse.cpp"
   if (y_1 == 0 || y_1 == height_7 - 1 || x_1 == 0 || x_1 == width_7 - 1)
   {
    # 326 "sharpness_fuse.cpp"
    *(pEdge + (y_1 * width_7 + x_1)) = (hmpprt::s16) 0;
   }
   else
   {
    # 330 "sharpness_fuse.cpp"
    hmpprt::s32 gx;
    # 330 "sharpness_fuse.cpp"
    gx = (hmpprt::s32 ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 + 1))) + ((hmpprt::s32 ) (*(yPlane + (y_1 * width_7 + x_1 + 1))) << 1) + (hmpprt::s32 ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 + 1))) - ((hmpprt::s32 ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane + (y_1 * width_7 + x_1 - 1))) << 1) + (hmpprt::s32 ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 - 1))));
    # 331 "sharpness_fuse.cpp"
    hmpprt::s32 gy;
    # 331 "sharpness_fuse.cpp"
    gy = (hmpprt::s32 ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane + ((y_1 - 1) * width_7 + x_1))) << 1) + (hmpprt::s32 ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 + 1))) - ((hmpprt::s32 ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane + ((y_1 + 1) * width_7 + x_1))) << 1) + (hmpprt::s32 ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 + 1))));
    # 332 "sharpness_fuse.cpp"
    hmpprt::s32 edgeV;
    # 332 "sharpness_fuse.cpp"
    edgeV = ((gx) > 0 ? (gx) : -(gx)) + ((gy) > 0 ? (gy) : -(gy));
    # 333 "sharpness_fuse.cpp"
    *(pEdge + (y_1 * width_7 + x_1)) = (hmpprt::s16 ) (edgeV);
   }
  }
  # 313 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_316_internal_1(hmpprt::s32 width_66, hmpprt::s32 height_36, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_8)
{
 # 313 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_36), "height_7");
  __hmppcg_call.addLocalParameter(&pEdge_8, 8, "pEdge");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_66), "width_7");
  __hmppcg_call.addLocalParameter(&yPlane_10, 8, "yPlane");
  __hmppcg_call.launch(hmpp_acc_region_main_316_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 313 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_316(hmpprt::s32 width_48, hmpprt::s32 height_25, hmpprt::u08* yPlane_5, hmpprt::s16* pEdge_4)
{
 # 342 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_316_internal_1(width_48, height_25, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_4)));
}
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void reduce_s64_add_xy(hmpprt::s64 neutral, hmpprt::s64* scalar, hmpprt::s32 size, hmpprt::s64* array)
{
 
 hmpprt::s64 * tmpa = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0));
 
 # 342 "sharpness_fuse.cpp"
 hmpprt::s64 var;
 # 342 "sharpness_fuse.cpp"
 var = neutral;
 # 342 "sharpness_fuse.cpp"
 hmpprt::s32 end_4;
 # 342 "sharpness_fuse.cpp"
 hmpprt::s32 i;
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 for (i = (hmpprt::gr_btidf()), end_4 = size - 1 ; i <= end_4 ; i = i + 512)
 {
  # 342 "sharpness_fuse.cpp"
  var = var + *(array + i);
 }
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 *(tmpa + (hmpprt::gr_btidf())) = var;
 # 342 "sharpness_fuse.cpp"
 hmpprt::s32 n_1;
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 for (n_1 = (511 >> 1) + 1 ; n_1 > 0 ; n_1 = (n_1 >> 1))
 {
  # 342 "sharpness_fuse.cpp"
  hmpprt::s32 next_1;
  # 342 "sharpness_fuse.cpp"
  next_1 = (hmpprt::gr_btidf()) + n_1;
  # 342 "sharpness_fuse.cpp"
  (hmpprt::gr_barrier());
  # 342 "sharpness_fuse.cpp"
  if ((hmpprt::gr_btidf()) < n_1 && next_1 < 512)
  {
   # 342 "sharpness_fuse.cpp"
   *(tmpa + (hmpprt::gr_btidf())) = *(tmpa + (hmpprt::gr_btidf())) + *(tmpa + next_1);
  }
 }
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 if ((hmpprt::gr_btidf()) == 0)
 {
  # 342 "sharpness_fuse.cpp"
  *scalar = *tmpa + *scalar;
 }
}
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_339_parallel_region_1(hmpprt::s64* gang_prv_red_sum_1, hmpprt::s32 height_6, hmpprt::s16* pEdge_3, hmpprt::s32 width_6)
{
 
 hmpprt::s64 * sum_1 = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0));
 
 hmpprt::s64 * tmpr_3 = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0+8));
 
 # 344 "sharpness_fuse.cpp"
 hmpprt::s64 tmp_27;
 # 344 "sharpness_fuse.cpp"
 if ((hmpprt::gr_btidf()) == 0)
 {
  # 344 "sharpness_fuse.cpp"
  *sum_1 = 0;
 }
 # 344 "sharpness_fuse.cpp"
 (hmpprt::gr_barrier());
 # 344 "sharpness_fuse.cpp"
 {
  # 342 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_6;
  # 342 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_6;
  # 342 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_6;
  # 342 "sharpness_fuse.cpp"
  iter_per_gang_6 = ((1 + (height_6 * width_6 - 1) / 192) > 256 ? (1 + (height_6 * width_6 - 1) / 192) : 256);
  # 342 "sharpness_fuse.cpp"
  first_gang_iter_6 = (hmpprt::gr_gbidx()) * iter_per_gang_6;
  # 342 "sharpness_fuse.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (height_6 * width_6 - 1) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (height_6 * width_6 - 1));
  # 342 "sharpness_fuse.cpp"
  hmpprt::s64 sum_2;
  # 348 "sharpness_fuse.cpp"
  sum_2 = 0;
  # 348 "sharpness_fuse.cpp"
  hmpprt::s32 i_4;
  # 348 "sharpness_fuse.cpp"
  # 352 "sharpness_fuse.cpp"
  for (i_4 = first_gang_iter_6 + (hmpprt::gr_btidy()) ; i_4 <= last_gang_iter_6 ; i_4 = i_4 + (hmpprt::gr_btnumy()))
  {
   # 348 "sharpness_fuse.cpp"
   hmpprt::s32 i_2;
   # 351 "sharpness_fuse.cpp"
   hmpprt::s32 j_2;
   # 353 "sharpness_fuse.cpp"
   j_2 = i_4 % width_6;
   # 353 "sharpness_fuse.cpp"
   i_2 = i_4 / width_6;
   # 353 "sharpness_fuse.cpp"
   sum_2 = sum_2 + (hmpprt::s64 ) (*(pEdge_3 + (i_2 * width_6 + j_2)));
  }
  # 342 "sharpness_fuse.cpp"
  # 342 "sharpness_fuse.cpp"
  *sum_1 = (reduce_s64_add_y(sum_2, tmpr_3, *sum_1));
 }
 # 342 "sharpness_fuse.cpp"
 tmp_27 = *sum_1;
 # 342 "sharpness_fuse.cpp"
 if ((hmpprt::gr_btidy()) == 0)
 {
  # 342 "sharpness_fuse.cpp"
  *(gang_prv_red_sum_1 + (hmpprt::gr_gbidx())) = tmp_27;
 }
 # 342 "sharpness_fuse.cpp"
 (hmpprt::gr_barrier());
}
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_339_internal_1(hmpprt::s32 width_65, hmpprt::s32 height_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  sum_4)
{
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  sum_3;
 # 342 "sharpness_fuse.cpp"
 hmpprt::s64 tmp_28;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&sum_3), hmpprt::MS_CUDA_SHARED, 8);
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  gang_prv_red_sum_2;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&gang_prv_red_sum_2), hmpprt::MS_CUDA_GLOB, 1536);
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  tmpr_2;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_2), hmpprt::MS_CUDA_SHARED, 2048);
 # 342 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_2, 8, "gang_prv_red_sum_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_35), "height_6");
  __hmppcg_call.addLocalParameter(&pEdge_11, 8, "pEdge_3");
  __hmppcg_call.addSharedParameter(sum_3, "sum_1");
  __hmppcg_call.addSharedParameter(tmpr_2, "tmpr_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_65), "width_6");
  __hmppcg_call.launch(hmpp_acc_region_main_339_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  tmpr_1;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_1), hmpprt::MS_CUDA_SHARED, 4096);
 # 342 "sharpness_fuse.cpp"
 tmp_28 = 0LL;
 # 342 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(1);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(512);
  __hmppcg_call.setBlockSizeY(1);
  __hmppcg_call.addLocalParameter(&tmp_28, 8, "neutral");
  __hmppcg_call.addLocalParameter(&sum_4, 8, "scalar");
  __hmppcg_call.addSharedParameter(tmpr_1, "tmpa");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (192), "size");
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_2, 8, "array");
  __hmppcg_call.launch(reduce_s64_add_xy, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_2));
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_1));
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&gang_prv_red_sum_2));
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) (&sum_3));
}
#endif // __CUDACC__



# 342 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_339(hmpprt::s32 width_47, hmpprt::s32 height_24, hmpprt::s16* pEdge_7, hmpprt::s64* sum)
{
 # 361 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_339_internal_1(width_47, height_24, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64> (sum)));
}
#endif // __CUDACC__



# 361 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_376_parallel_region_1(hmpprt::s32 height_5, hmpprt::s16* pError, hmpprt::s32 width_5, hmpprt::u08* yPlaneCSER_2, hmpprt::u08* yPlane_4)
{
 # 363 "sharpness_fuse.cpp"
 {
  # 379 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_5;
  # 379 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_5;
  # 379 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_5;
  # 379 "sharpness_fuse.cpp"
  iter_per_gang_5 = ((1 + (height_5 * width_5 - 1) / 192) > 256 ? (1 + (height_5 * width_5 - 1) / 192) : 256);
  # 379 "sharpness_fuse.cpp"
  first_gang_iter_5 = (hmpprt::gr_gbidx()) * iter_per_gang_5;
  # 379 "sharpness_fuse.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < (height_5 * width_5 - 1) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : (height_5 * width_5 - 1));
  # 379 "sharpness_fuse.cpp"
  hmpprt::s32 h_23;
  # 379 "sharpness_fuse.cpp"
  # 383 "sharpness_fuse.cpp"
  for (h_23 = first_gang_iter_5 + (hmpprt::gr_btidy()) ; h_23 <= last_gang_iter_5 ; h_23 = h_23 + (hmpprt::gr_btnumy()))
  {
   # 379 "sharpness_fuse.cpp"
   hmpprt::s32 h_18;
   # 382 "sharpness_fuse.cpp"
   hmpprt::s32 w_18;
   # 384 "sharpness_fuse.cpp"
   w_18 = h_23 % width_5;
   # 384 "sharpness_fuse.cpp"
   h_18 = h_23 / width_5;
   # 384 "sharpness_fuse.cpp"
   *(pError + (h_18 * width_5 + w_18)) = (hmpprt::s16 ) ((hmpprt::s32 ) (*(yPlane_4 + (h_18 * width_5 + w_18))) - (hmpprt::s32 ) (*(yPlaneCSER_2 + (h_18 * width_5 + w_18))));
  }
  # 361 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 361 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_376_internal_1(hmpprt::s32 width_64, hmpprt::s32 height_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_4)
{
 # 361 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_34), "height_5");
  __hmppcg_call.addLocalParameter(&pError_4, 8, "pError");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_64), "width_5");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_37, 8, "yPlaneCSER_2");
  __hmppcg_call.addLocalParameter(&yPlane_14, 8, "yPlane_4");
  __hmppcg_call.launch(hmpp_acc_region_main_376_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 361 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_376(hmpprt::s32 width_46, hmpprt::s32 height_23, hmpprt::u08* yPlane_9, hmpprt::u08* yPlaneCSER_22, hmpprt::s16* pError_2)
{
 # 392 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_376_internal_1(width_46, height_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_9), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_22), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pError_2)));
}
#endif // __CUDACC__



# 392 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_389_parallel_region_1(double cutoff, double cutoff2, hmpprt::s32 height_4, double low, double order, double order2, hmpprt::s16* pEdge_2, hmpprt::s16* pError_1, hmpprt::s16* pSharpness, double peak, hmpprt::s32 width_4, hmpprt::u08* yPlaneCSER_1)
{
 # 394 "sharpness_fuse.cpp"
 {
  # 398 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_4;
  # 398 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_4;
  # 398 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_4;
  # 398 "sharpness_fuse.cpp"
  iter_per_gang_4 = ((1 + (height_4 * width_4 - 1) / 192) > 256 ? (1 + (height_4 * width_4 - 1) / 192) : 256);
  # 398 "sharpness_fuse.cpp"
  first_gang_iter_4 = (hmpprt::gr_gbidx()) * iter_per_gang_4;
  # 398 "sharpness_fuse.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < (height_4 * width_4 - 1) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : (height_4 * width_4 - 1));
  # 398 "sharpness_fuse.cpp"
  hmpprt::s32 h_24;
  # 398 "sharpness_fuse.cpp"
  # 402 "sharpness_fuse.cpp"
  for (h_24 = first_gang_iter_4 + (hmpprt::gr_btidy()) ; h_24 <= last_gang_iter_4 ; h_24 = h_24 + (hmpprt::gr_btnumy()))
  {
   # 403 "sharpness_fuse.cpp"
   hmpprt::s16 edge;
   # 398 "sharpness_fuse.cpp"
   hmpprt::s32 h_19;
   # 401 "sharpness_fuse.cpp"
   hmpprt::s32 w_19;
   # 403 "sharpness_fuse.cpp"
   w_19 = h_24 % width_4;
   # 403 "sharpness_fuse.cpp"
   h_19 = h_24 / width_4;
   # 403 "sharpness_fuse.cpp"
   edge = *(pEdge_2 + (h_19 * width_4 + w_19));
   # 404 "sharpness_fuse.cpp"
   double weight;
   # 404 "sharpness_fuse.cpp"
   weight = (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff2, (double) 2. * order2));
   # 405 "sharpness_fuse.cpp"
   double strength;
   # 405 "sharpness_fuse.cpp"
   strength = (peak - low) * ((double) 1. - (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff, (double) 2. * order)));
   # 406 "sharpness_fuse.cpp"
   strength = strength * weight + low;
   # 408 "sharpness_fuse.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = (hmpprt::s16 ) (*(yPlaneCSER_1 + (h_19 * width_4 + w_19)));
   # 409 "sharpness_fuse.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = *(pSharpness + (h_19 * width_4 + w_19)) + (double ) (*(pError_1 + (h_19 * width_4 + w_19))) * strength;
  }
  # 392 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 392 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_389_internal_1(hmpprt::s32 width_63, hmpprt::s32 height_33, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_7, double cutoff_2, double peak_2, double cutoff2_2, double order_2, double order2_2, double low_2)
{
 # 392 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&cutoff_2, 8, "cutoff");
  __hmppcg_call.addLocalParameter(&cutoff2_2, 8, "cutoff2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_33), "height_4");
  __hmppcg_call.addLocalParameter(&low_2, 8, "low");
  __hmppcg_call.addLocalParameter(&order_2, 8, "order");
  __hmppcg_call.addLocalParameter(&order2_2, 8, "order2");
  __hmppcg_call.addLocalParameter(&pEdge_10, 8, "pEdge_2");
  __hmppcg_call.addLocalParameter(&pError_5, 8, "pError_1");
  __hmppcg_call.addLocalParameter(&pSharpness_7, 8, "pSharpness");
  __hmppcg_call.addLocalParameter(&peak_2, 8, "peak");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_63), "width_4");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_35, 8, "yPlaneCSER_1");
  __hmppcg_call.launch(hmpp_acc_region_main_389_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 392 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_389(hmpprt::s32 width_45, hmpprt::s32 height_22, hmpprt::u08* yPlaneCSER_16, hmpprt::s16* pError_3, hmpprt::s16* pEdge_6, hmpprt::s16* pSharpness_3, double cutoff_1, double peak_1, double cutoff2_1, double order_1, double order2_1, double low_1)
{
 # 417 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_389_internal_1(width_45, height_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_16), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pError_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_6), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_3), cutoff_1, peak_1, cutoff2_1, order_1, order2_1, low_1));
}
#endif // __CUDACC__



# 417 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_408_parallel_region_1(float cutoff3, hmpprt::s32 height_3, float low3, float order3, hmpprt::s16* pEdge_1, hmpprt::s16* pSharpness_5, float peak3_1, hmpprt::s32 width_3, hmpprt::u08* yPlane_3)
{
 # 419 "sharpness_fuse.cpp"
 {
  # 423 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 423 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 423 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 423 "sharpness_fuse.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 423 "sharpness_fuse.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 423 "sharpness_fuse.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 423 "sharpness_fuse.cpp"
  hmpprt::s32 h_25;
  # 423 "sharpness_fuse.cpp"
  # 427 "sharpness_fuse.cpp"
  for (h_25 = first_gang_iter_3 + (hmpprt::gr_btidy()) ; h_25 <= last_gang_iter_3 ; h_25 = h_25 + (hmpprt::gr_btnumy()))
  {
   # 423 "sharpness_fuse.cpp"
   hmpprt::s32 h_20;
   # 426 "sharpness_fuse.cpp"
   hmpprt::s32 w_20;
   # 428 "sharpness_fuse.cpp"
   w_20 = h_25 % width_3;
   # 428 "sharpness_fuse.cpp"
   h_20 = h_25 / width_3;
   # 428 "sharpness_fuse.cpp"
   if (!(h_20 == 0 || h_20 == height_3 - 1 || w_20 == 0 || w_20 == width_3 - 1))
   {
    # 430 "sharpness_fuse.cpp"
    hmpprt::s32 enhanced;
    # 430 "sharpness_fuse.cpp"
    hmpprt::s32 maxValue;
    # 430 "sharpness_fuse.cpp"
    hmpprt::s32 minValue;
    # 431 "sharpness_fuse.cpp"
    double oscStrength;
    # 432 "sharpness_fuse.cpp"
    enhanced = (hmpprt::s32 ) (*(pSharpness_5 + (h_20 * width_3 + w_20)));
    # 434 "sharpness_fuse.cpp"
    maxValue = (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))));
    # 423 "sharpness_fuse.cpp"
    maxValue = ( (maxValue > (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? maxValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))));
    # 424 "sharpness_fuse.cpp"
    maxValue = ( (maxValue > (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? maxValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))));
    # 426 "sharpness_fuse.cpp"
    minValue = (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))));
    # 427 "sharpness_fuse.cpp"
    minValue = ( (minValue < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))) ? minValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))));
    # 428 "sharpness_fuse.cpp"
    minValue = ( (minValue < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))) ? minValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))));
    # 432 "sharpness_fuse.cpp"
    double cutoff2Order;
    # 432 "sharpness_fuse.cpp"
    cutoff2Order = pow((double ) (cutoff3), (double ) ((float) 2. * order3));
    # 433 "sharpness_fuse.cpp"
    double edge2Order;
    # 433 "sharpness_fuse.cpp"
    edge2Order = pow((double ) (*(pEdge_1 + (h_20 * width_3 + w_20))), (double) 2. * (double ) (order3));
    # 434 "sharpness_fuse.cpp"
    oscStrength = ((double ) (peak3_1) * cutoff2Order + (double ) (low3) * edge2Order) / (cutoff2Order + edge2Order);
    # 438 "sharpness_fuse.cpp"
    if (enhanced > maxValue)
    {
     # 440 "sharpness_fuse.cpp"
     *(pSharpness_5 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue) < (double) 255.) ? ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue)) : ((double) 255.));
    }
    else
    {
     # 442 "sharpness_fuse.cpp"
     if (enhanced < minValue)
     {
      # 444 "sharpness_fuse.cpp"
      *(pSharpness_5 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( ((double) 0. > (double ) (minValue) - oscStrength * (double ) (minValue - enhanced)) ? ((double) 0.) : ((double ) (minValue) - oscStrength * (double ) (minValue - enhanced)));
     }
     else
     {
      # 448 "sharpness_fuse.cpp"
      *(pSharpness_5 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( (( (enhanced > 0) ? enhanced : 0) < 255) ? ( (enhanced > 0) ? enhanced : 0) : 255);
     }
    }
   }
  }
  # 417 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 417 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_408_internal_1(hmpprt::s32 width_62, hmpprt::s32 height_32, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_6, float cutoff3_2, float order3_1, float peak3_2, float low3_2)
{
 # 417 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((float) (cutoff3_2) , "cutoff3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_32), "height_3");
  __hmppcg_call.addLocalParameter((float) (low3_2) , "low3");
  __hmppcg_call.addLocalParameter((float) (order3_1) , "order3");
  __hmppcg_call.addLocalParameter(&pEdge_9, 8, "pEdge_1");
  __hmppcg_call.addLocalParameter(&pSharpness_6, 8, "pSharpness_5");
  __hmppcg_call.addLocalParameter((float) (peak3_2) , "peak3_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_62), "width_3");
  __hmppcg_call.addLocalParameter(&yPlane_13, 8, "yPlane_3");
  __hmppcg_call.launch(hmpp_acc_region_main_408_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 417 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_408(hmpprt::s32 width_43, hmpprt::s32 height_21, hmpprt::u08* yPlane_8, hmpprt::s16* pEdge_5, hmpprt::s16* pSharpness_2, float cutoff3_1, float order3_2, float peak3, float low3_1)
{
 # 458 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_408_internal_1(width_43, height_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_8), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_2), cutoff3_1, order3_2, peak3, low3_1));
}
#endif // __CUDACC__



# 458 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_462_parallel_region_1(hmpprt::s32 height_2, hmpprt::s16* pSharpness_1, hmpprt::s32 width_2, hmpprt::u08* yPlane_2)
{
 # 460 "sharpness_fuse.cpp"
 {
  # 465 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_2;
  # 465 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 465 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 465 "sharpness_fuse.cpp"
  iter_per_gang_2 = ((1 + (height_2 * width_2 - 1) / 192) > 256 ? (1 + (height_2 * width_2 - 1) / 192) : 256);
  # 465 "sharpness_fuse.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * iter_per_gang_2;
  # 465 "sharpness_fuse.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 * width_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 * width_2 - 1));
  # 465 "sharpness_fuse.cpp"
  hmpprt::s32 h_26;
  # 465 "sharpness_fuse.cpp"
  # 469 "sharpness_fuse.cpp"
  for (h_26 = first_gang_iter_2 + (hmpprt::gr_btidy()) ; h_26 <= last_gang_iter_2 ; h_26 = h_26 + (hmpprt::gr_btnumy()))
  {
   # 465 "sharpness_fuse.cpp"
   hmpprt::s32 h_21;
   # 468 "sharpness_fuse.cpp"
   hmpprt::s32 w_21;
   # 470 "sharpness_fuse.cpp"
   w_21 = h_26 % width_2;
   # 470 "sharpness_fuse.cpp"
   h_21 = h_26 / width_2;
   # 470 "sharpness_fuse.cpp"
   *(yPlane_2 + (h_21 * width_2 + w_21)) = (hmpprt::u08 ) ( ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) > 255) ? 255 : ( ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) < 0) ? 0 : ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))))));
  }
  # 458 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 458 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_462_internal_1(hmpprt::s32 width_61, hmpprt::s32 height_31, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_8)
{
 # 458 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_31), "height_2");
  __hmppcg_call.addLocalParameter(&pSharpness_8, 8, "pSharpness_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_61), "width_2");
  __hmppcg_call.addLocalParameter(&yPlane_12, 8, "yPlane_2");
  __hmppcg_call.launch(hmpp_acc_region_main_462_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 458 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_462(hmpprt::s32 width_34, hmpprt::s32 height_20, hmpprt::u08* yPlane_7, hmpprt::s16* pSharpness_4)
{
 # 23 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_462_internal_1(width_34, height_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_4)));
}
#endif // __CUDACC__



# 23 "sharpness_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_82_parallel_region_1(hmpprt::s32 height_1, hmpprt::s32 quarterWidth_1, hmpprt::s32 width_1, hmpprt::u08* yPlaneDown_1, hmpprt::u08* yPlane_1)
{
 # 25 "sharpness_fuse.cpp"
 {
  # 85 "sharpness_fuse.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 85 "sharpness_fuse.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 85 "sharpness_fuse.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 85 "sharpness_fuse.cpp"
  iter_per_gang_1 = ((1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) > 256 ? (1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) : 256);
  # 85 "sharpness_fuse.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 85 "sharpness_fuse.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1));
  # 85 "sharpness_fuse.cpp"
  hmpprt::s32 i_5;
  # 85 "sharpness_fuse.cpp"
  # 89 "sharpness_fuse.cpp"
  for (i_5 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; i_5 <= last_gang_iter_1 ; i_5 = i_5 + (hmpprt::gr_btnumy()))
  {
   # 85 "sharpness_fuse.cpp"
   hmpprt::u08 tbt_1;
   # 85 "sharpness_fuse.cpp"
   hmpprt::s32 tbt_2;
   # 85 "sharpness_fuse.cpp"
   hmpprt::s32 tbt_3;
   # 85 "sharpness_fuse.cpp"
   hmpprt::s32 i_3;
   # 88 "sharpness_fuse.cpp"
   hmpprt::s32 j_3;
   # 90 "sharpness_fuse.cpp"
   j_3 = i_5 % ((width_1 + 3) / 4);
   # 90 "sharpness_fuse.cpp"
   i_3 = i_5 / ((width_1 + 3) / 4);
   # 90 "sharpness_fuse.cpp"
   tbt_1 = *(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 3));
   # 90 "sharpness_fuse.cpp"
   tbt_2 = (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 2)));
   # 90 "sharpness_fuse.cpp"
   tbt_3 = (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 3))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 1)));
   # 90 "sharpness_fuse.cpp"
   *(yPlaneDown_1 + (i_3 * 4 / 4 * quarterWidth_1 + j_3 * 4 / 4)) = (hmpprt::u08 ) (tbt_3 + tbt_2 + (hmpprt::s32 ) (tbt_1) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 3))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 3))) + 8 >> 4);
  }
  # 23 "sharpness_fuse.cpp"
 }
}
#endif // __CUDACC__



# 23 "sharpness_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_82_internal_1(hmpprt::s32 width_60, hmpprt::s32 height_30, hmpprt::s32 quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_15)
{
 # 23 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_30), "height_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_23), "quarterWidth_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_60), "width_1");
  __hmppcg_call.addLocalParameter(&yPlaneDown_15, 8, "yPlaneDown_1");
  __hmppcg_call.addLocalParameter(&yPlane_11, 8, "yPlane_1");
  __hmppcg_call.launch(hmpp_acc_region_main_82_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 23 "sharpness_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_82(hmpprt::s32 width_32, hmpprt::s32 height_16, hmpprt::s32 quarterWidth_9, hmpprt::u08* yPlane_6, hmpprt::u08* yPlaneDown_7)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_82_internal_1(width_32, height_16, quarterWidth_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_6), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_7)));
}
#endif // __CUDACC__



# 1 "<preprocessor>"

#ifdef __CUDACC__
__device__ hmpprt::s64 reduce_s64_add_y(hmpprt::s64 priv, hmpprt::s64* tmpa_1, hmpprt::s64 orig)
{
 # 1 "<preprocessor>"
 (hmpprt::gr_barrier());
 # 1 "<preprocessor>"
 *(tmpa_1 + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) = priv;
 # 1 "<preprocessor>"
 hmpprt::s32 n;
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 for (n = ((hmpprt::gr_btnumy()) - 1 >> 1) + 1 ; n > 0 ; n = (n >> 1))
 {
  # 1 "<preprocessor>"
  hmpprt::s32 next;
  # 1 "<preprocessor>"
  next = (hmpprt::gr_btidy()) + n;
  # 1 "<preprocessor>"
  (hmpprt::gr_barrier());
  # 1 "<preprocessor>"
  if ((hmpprt::gr_btidy()) < n && next < (hmpprt::gr_btnumy()))
  {
   # 1 "<preprocessor>"
   *(tmpa_1 + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) = *(tmpa_1 + (hmpprt::gr_btidy()) + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) + *(tmpa_1 + next + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx()));
  }
 }
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 (hmpprt::gr_barrier());
 # 1 "<preprocessor>"
 return *(tmpa_1 + (hmpprt::gr_btnumy()) * (hmpprt::gr_btidx())) + orig;
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
      hmpp_acc_region_main_105_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_105_parallel_region_1");
      hmpp_acc_region_main_117_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_117_parallel_region_1");
      hmpp_acc_region_main_138_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_138_loop1D_1");
      hmpp_acc_region_main_151_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_151_loop1D_1");
      hmpp_acc_region_main_159_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_159_loop1D_1");
      hmpp_acc_region_main_172_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_172_loop1D_1");
      hmpp_acc_region_main_189_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_189_loop1D_1");
      hmpp_acc_region_main_211_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_211_loop1D_1");
      hmpp_acc_region_main_220_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_220_loop1D_1");
      hmpp_acc_region_main_232_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_232_loop1D_1");
      hmpp_acc_region_main_244_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_244_loop1D_1");
      hmpp_acc_region_main_267_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_267_loop1D_1");
      hmpp_acc_region_main_279_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_279_loop1D_1");
      hmpp_acc_region_main_316_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_316_parallel_region_1");
      reduce_s64_add_xy = new hmpprt::CUDAGrid(hmpprt_module, "reduce_s64_add_xy");
      hmpp_acc_region_main_339_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_339_parallel_region_1");
      hmpp_acc_region_main_376_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_376_parallel_region_1");
      hmpp_acc_region_main_389_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_389_parallel_region_1");
      hmpp_acc_region_main_408_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_408_parallel_region_1");
      hmpp_acc_region_main_462_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_462_parallel_region_1");
      hmpp_acc_region_main_82_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_82_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_105", "prototype hmpp_acc_region_main_105(width: s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_117", "prototype hmpp_acc_region_main_117(width: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_138", "prototype hmpp_acc_region_main_138(width: ^host s32, height: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_151", "prototype hmpp_acc_region_main_151(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_159", "prototype hmpp_acc_region_main_159(width: ^host s32, height: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_172", "prototype hmpp_acc_region_main_172(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_189", "prototype hmpp_acc_region_main_189(width: ^host s32, height: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_211", "prototype hmpp_acc_region_main_211(width: ^host s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_220", "prototype hmpp_acc_region_main_220(width: ^host s32, height: ^host s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_232", "prototype hmpp_acc_region_main_232(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_244", "prototype hmpp_acc_region_main_244(width: ^host s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_267", "prototype hmpp_acc_region_main_267(width: ^host s32, height: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_279", "prototype hmpp_acc_region_main_279(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_316", "prototype hmpp_acc_region_main_316(width: s32, height: s32, yPlane: ^cudaglob u8, pEdge: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_339", "prototype hmpp_acc_region_main_339(width: s32, height: s32, pEdge: ^cudaglob s16, sum: ^cudaglob s64)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_376", "prototype hmpp_acc_region_main_376(width: s32, height: s32, yPlane: ^cudaglob u8, yPlaneCSER: ^cudaglob u8, pError: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_389", "prototype hmpp_acc_region_main_389(width: s32, height: s32, yPlaneCSER: ^cudaglob u8, pError: ^cudaglob s16, pEdge: ^cudaglob s16, pSharpness: ^cudaglob s16, cutoff: double, peak: double, cutoff2: double, order: double, order2: double, low: double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_408", "prototype hmpp_acc_region_main_408(width: s32, height: s32, yPlane: ^cudaglob u8, pEdge: ^cudaglob s16, pSharpness: ^cudaglob s16, cutoff3: float, order3: float, peak3: float, low3: float)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_462", "prototype hmpp_acc_region_main_462(width: s32, height: s32, yPlane: ^cudaglob u8, pSharpness: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_82", "prototype hmpp_acc_region_main_82(width: s32, height: s32, quarterWidth: s32, yPlane: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");

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
      delete hmpp_acc_region_main_105_parallel_region_1;
      delete hmpp_acc_region_main_117_parallel_region_1;
      delete hmpp_acc_region_main_138_loop1D_1;
      delete hmpp_acc_region_main_151_loop1D_1;
      delete hmpp_acc_region_main_159_loop1D_1;
      delete hmpp_acc_region_main_172_loop1D_1;
      delete hmpp_acc_region_main_189_loop1D_1;
      delete hmpp_acc_region_main_211_loop1D_1;
      delete hmpp_acc_region_main_220_loop1D_1;
      delete hmpp_acc_region_main_232_loop1D_1;
      delete hmpp_acc_region_main_244_loop1D_1;
      delete hmpp_acc_region_main_267_loop1D_1;
      delete hmpp_acc_region_main_279_loop1D_1;
      delete hmpp_acc_region_main_316_parallel_region_1;
      delete reduce_s64_add_xy;
      delete hmpp_acc_region_main_339_parallel_region_1;
      delete hmpp_acc_region_main_376_parallel_region_1;
      delete hmpp_acc_region_main_389_parallel_region_1;
      delete hmpp_acc_region_main_408_parallel_region_1;
      delete hmpp_acc_region_main_462_parallel_region_1;
      delete hmpp_acc_region_main_82_parallel_region_1;

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
