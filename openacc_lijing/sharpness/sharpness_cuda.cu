
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

# 23 "sharpness.cpp"

#ifdef __CUDACC__
__device__ hmpprt::s64 reduce_s64_add_y(hmpprt::s64 priv, hmpprt::s64* tmpa_1, hmpprt::s64 orig)
;
#endif // __CUDACC__



# 23 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_84(hmpprt::s32 width_32, hmpprt::s32 height_16, hmpprt::s32 quarterWidth_9, hmpprt::u08* yPlane_6, hmpprt::u08* yPlaneDown_7)
;
#endif // __CUDACC__



# 23 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_84_internal_1(hmpprt::s32 width_60, hmpprt::s32 height_30, hmpprt::s32 quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_15)
;
#endif // __CUDACC__



# 486 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_84_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_84_parallel_region_1(hmpprt::s32 height_1, hmpprt::s32 quarterWidth_1, hmpprt::s32 width_1, hmpprt::u08* yPlaneDown_1, hmpprt::u08* yPlane_1);
#endif // __CUDACC__




# 486 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_490(hmpprt::s32 width_34, hmpprt::s32 height_20, hmpprt::u08* yPlane_7, hmpprt::s16* pSharpness_4)
;
#endif // __CUDACC__



# 486 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_490_internal_1(hmpprt::s32 width_61, hmpprt::s32 height_31, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_7)
;
#endif // __CUDACC__



# 433 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_490_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_490_parallel_region_1(hmpprt::s32 height_2, hmpprt::s16* pSharpness_1, hmpprt::s32 width_2, hmpprt::u08* yPlane_2);
#endif // __CUDACC__




# 433 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_436(hmpprt::s32 width_43, hmpprt::s32 height_21, hmpprt::u08* yPlane_8, hmpprt::s16* pEdge_5, hmpprt::s16* pSharpness_5, float cutoff3_1, float order3_1, float peak3_1, float low3_1)
;
#endif // __CUDACC__



# 433 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_436_internal_1(hmpprt::s32 width_62, hmpprt::s32 height_32, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_8, float cutoff3_2, float order3_2, float peak3_2, float low3_2)
;
#endif // __CUDACC__



# 391 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_436_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_436_parallel_region_1(float cutoff3, hmpprt::s32 height_3, float low3, float order3, hmpprt::s16* pEdge_1, hmpprt::s16* pSharpness_2, float peak3, hmpprt::s32 width_3, hmpprt::u08* yPlane_3);
#endif // __CUDACC__




# 391 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_411(hmpprt::s32 width_45, hmpprt::s32 height_22, hmpprt::u08* yPlaneCSER_16, hmpprt::s16* pError_3, hmpprt::s16* pEdge_10, hmpprt::s16* pSharpness_3, double cutoff_1, double peak_1, double cutoff2_1, double order_1, double order2_1, double low_1)
;
#endif // __CUDACC__



# 391 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_411_internal_1(hmpprt::s32 width_63, hmpprt::s32 height_33, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_6, double cutoff_2, double peak_2, double cutoff2_2, double order_2, double order2_2, double low_2)
;
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_411_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_411_parallel_region_1(double cutoff, double cutoff2, hmpprt::s32 height_4, double low, double order, double order2, hmpprt::s16* pEdge_2, hmpprt::s16* pError_1, hmpprt::s16* pSharpness, double peak, hmpprt::s32 width_4, hmpprt::u08* yPlaneCSER_1);
#endif // __CUDACC__




# 372 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_375(hmpprt::s32 width_46, hmpprt::s32 height_23, hmpprt::s16* pEdge_7, hmpprt::s64* sum)
;
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_375_internal_1(hmpprt::s32 width_64, hmpprt::s32 height_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  sum_4)
;
#endif // __CUDACC__



# 342 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_375_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_375_parallel_region_1(hmpprt::s64* gang_prv_red_sum_2, hmpprt::s32 height_5, hmpprt::s16* pEdge_3, hmpprt::s32 width_5);
#endif // __CUDACC__




# 342 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * reduce_s64_add_xy = 0;
#else

extern "C" __global__ void reduce_s64_add_xy(hmpprt::s64 neutral, hmpprt::s64* scalar, hmpprt::s32 size, hmpprt::s64* array);
#endif // __CUDACC__




# 342 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_346(hmpprt::s32 width_47, hmpprt::s32 height_24, hmpprt::u08* yPlane_9, hmpprt::s16* pEdge_4)
;
#endif // __CUDACC__



# 342 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_346_internal_1(hmpprt::s32 width_65, hmpprt::s32 height_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_8)
;
#endif // __CUDACC__



# 323 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_346_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_346_parallel_region_1(hmpprt::s32 height_6, hmpprt::s16* pEdge, hmpprt::s32 width_6, hmpprt::u08* yPlane_4);
#endif // __CUDACC__




# 323 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_326(hmpprt::s32 width_48, hmpprt::s32 height_25, hmpprt::u08* yPlane_5, hmpprt::u08* yPlaneCSER_22, hmpprt::s16* pError_2)
;
#endif // __CUDACC__



# 323 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_326_internal_1(hmpprt::s32 width_66, hmpprt::s32 height_36, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_4)
;
#endif // __CUDACC__



# 289 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_326_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_326_parallel_region_1(hmpprt::s32 height_7, hmpprt::s16* pError, hmpprt::s32 width_7, hmpprt::u08* yPlane, hmpprt::u08* yPlaneCSER_2);
#endif // __CUDACC__




# 289 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_289(hmpprt::s32* width_8, hmpprt::s32 quarterWidth_10, hmpprt::s32 quarterHeight_7, hmpprt::u08* yPlaneCSER_23, hmpprt::u08* yPlaneDown_8)
;
#endif // __CUDACC__



# 289 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_289_internal_1(hmpprt::s32* width_67, hmpprt::s32 quarterWidth_16, hmpprt::s32 quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_16)
;
#endif // __CUDACC__



# 277 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_289_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_289_loop1D_1(hmpprt::s32 width_30, hmpprt::s32 quarterWidth_2, hmpprt::s32 quarterHeight_1, hmpprt::u08* yPlaneCSER_3, hmpprt::u08* yPlaneDown_2);
#endif // __CUDACC__




# 277 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_277(hmpprt::s32* width_68, hmpprt::s32 height_8, hmpprt::u08* yPlaneCSER_4)
;
#endif // __CUDACC__



# 277 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_277_internal_1(hmpprt::s32* width_9, hmpprt::s32 height_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_42)
;
#endif // __CUDACC__



# 254 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_277_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_277_loop1D_1(hmpprt::s32 height_26, hmpprt::u08* yPlaneCSER_24, hmpprt::s32 width_29);
#endif // __CUDACC__




# 254 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_254(hmpprt::s32* width_10, hmpprt::s32 quarterHeight_2, hmpprt::u08* yPlaneCSER_5)
;
#endif // __CUDACC__



# 254 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_254_internal_1(hmpprt::s32* width_49, hmpprt::s32 quarterHeight_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_43)
;
#endif // __CUDACC__



# 242 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_254_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_254_loop1D_1(hmpprt::s32 quarterHeight_8, hmpprt::u08* yPlaneCSER_25, hmpprt::s32 width_28);
#endif // __CUDACC__




# 242 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_242(hmpprt::s32* width_11, hmpprt::s32 quarterWidth_3, hmpprt::s32 quarterHeight_9, hmpprt::u08* yPlaneCSER_26, hmpprt::u08* yPlaneDown_9)
;
#endif // __CUDACC__



# 242 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_242_internal_1(hmpprt::s32* width_50, hmpprt::s32 quarterWidth_20, hmpprt::s32 quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_39, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_17)
;
#endif // __CUDACC__



# 230 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_242_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_242_loop1D_1(hmpprt::s32 quarterWidth_11, hmpprt::s32 quarterHeight_3, hmpprt::u08* yPlaneCSER_6, hmpprt::u08* yPlaneDown_3, hmpprt::s32 width_27);
#endif // __CUDACC__




# 230 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_230(hmpprt::s32* width_12, hmpprt::s32* height_9, hmpprt::u08* yPlaneCSER_40)
;
#endif // __CUDACC__



# 230 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_230_internal_1(hmpprt::s32* width_51, hmpprt::s32* height_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_27)
;
#endif // __CUDACC__



# 209 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_230_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_230_loop1D_1(hmpprt::u08* yPlaneCSER_7, hmpprt::s32 width_26, hmpprt::s32 height_14);
#endif // __CUDACC__




# 209 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_209(hmpprt::s32* width_13, hmpprt::s32* height_10, hmpprt::s32 quarterWidth_12, hmpprt::u08* yPlaneCSER_28)
;
#endif // __CUDACC__



# 209 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_209_internal_1(hmpprt::s32* width_52, hmpprt::s32* height_27, hmpprt::s32 quarterWidth_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_41)
;
#endif // __CUDACC__



# 197 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_209_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_209_loop1D_1(hmpprt::s32 quarterWidth_4, hmpprt::u08* yPlaneCSER_8, hmpprt::s32 width_25, hmpprt::s32 height_13);
#endif // __CUDACC__




# 197 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_197(hmpprt::s32* width_53, hmpprt::s32* height_28, hmpprt::s32 quarterWidth_18, hmpprt::s32 quarterHeight_14, hmpprt::u08* yPlaneCSER_9, hmpprt::u08* yPlaneDown_12)
;
#endif // __CUDACC__



# 197 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_197_internal_1(hmpprt::s32* width_14, hmpprt::s32* height_11, hmpprt::s32 quarterWidth_13, hmpprt::s32 quarterHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_44, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_4)
;
#endif // __CUDACC__



# 185 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_197_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_197_loop1D_1(hmpprt::s32 quarterWidth_5, hmpprt::s32 quarterHeight_10, hmpprt::u08* yPlaneCSER_29, hmpprt::u08* yPlaneDown_10, hmpprt::s32 width_24, hmpprt::s32 height_17);
#endif // __CUDACC__




# 185 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_185(hmpprt::s32* width_54, hmpprt::u08* yPlaneCSER_35)
;
#endif // __CUDACC__



# 185 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_185_internal_1(hmpprt::s32* width_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_17)
;
#endif // __CUDACC__



# 164 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_185_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_185_loop1D_1(hmpprt::s32 width_36, hmpprt::u08* yPlaneCSER_10);
#endif // __CUDACC__




# 164 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_164(hmpprt::s32* width_55, hmpprt::s32 quarterWidth_19, hmpprt::u08* yPlaneCSER_36)
;
#endif // __CUDACC__



# 164 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_164_internal_1(hmpprt::s32* width_16, hmpprt::s32 quarterWidth_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_18)
;
#endif // __CUDACC__



# 152 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_164_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_164_loop1D_1(hmpprt::s32 quarterWidth_6, hmpprt::u08* yPlaneCSER_11);
#endif // __CUDACC__




# 152 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_152(hmpprt::s32* width_17, hmpprt::s32 quarterWidth_7, hmpprt::u08* yPlaneCSER_30, hmpprt::u08* yPlaneDown_5)
;
#endif // __CUDACC__



# 152 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_152_internal_1(hmpprt::s32* width_56, hmpprt::s32 quarterWidth_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_13)
;
#endif // __CUDACC__



# 140 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_152_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_152_loop1D_1(hmpprt::s32 quarterWidth_15, hmpprt::u08* yPlaneCSER_19, hmpprt::u08* yPlaneDown_11);
#endif // __CUDACC__




# 140 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_140(hmpprt::s32* width_57, hmpprt::s32 height_29, hmpprt::u08* yPlaneCSER_31)
;
#endif // __CUDACC__



# 140 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_140_internal_1(hmpprt::s32* width_18, hmpprt::s32 height_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_13)
;
#endif // __CUDACC__



# 119 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_140_loop1D_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_140_loop1D_1(hmpprt::s32 width_35, hmpprt::s32 height, hmpprt::u08* yPlaneCSER_20);
#endif // __CUDACC__




# 119 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_119(hmpprt::s32 width_19, hmpprt::s32 quarterHeight_15, hmpprt::u08* yPlaneCSER_14)
;
#endif // __CUDACC__



# 119 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_119_internal_1(hmpprt::s32 width_58, hmpprt::s32 quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_32)
;
#endif // __CUDACC__



# 103 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_119_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_119_parallel_region_1(hmpprt::s32 quarterHeight_11, hmpprt::s32 width_33, hmpprt::u08* yPlaneCSER_21);
#endif // __CUDACC__




# 103 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_107(hmpprt::s32 width_31, hmpprt::s32 quarterWidth_22, hmpprt::s32 quarterHeight, hmpprt::u08* yPlaneCSER_33, hmpprt::u08* yPlaneDown_6)
;
#endif // __CUDACC__



# 103 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_107_internal_1(hmpprt::s32 width_59, hmpprt::s32 quarterWidth_8, hmpprt::s32 quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_14)
;
#endif // __CUDACC__



# 103 "sharpness.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_107_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_107_parallel_region_1(hmpprt::s32 quarterHeight_6, hmpprt::s32 quarterWidth, hmpprt::s32 width, hmpprt::u08* yPlaneCSER, hmpprt::u08* yPlaneDown);
#endif // __CUDACC__




# 103 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_107_parallel_region_1(hmpprt::s32 quarterHeight_6, hmpprt::s32 quarterWidth, hmpprt::s32 width, hmpprt::u08* yPlaneCSER, hmpprt::u08* yPlaneDown)
{
 # 105 "sharpness.cpp"
 {
  # 110 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_9;
  # 110 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_9;
  # 110 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_9;
  # 110 "sharpness.cpp"
  iter_per_gang_9 = ((1 + (quarterHeight_6 - 1) / 192) > 256 ? (1 + (quarterHeight_6 - 1) / 192) : 256);
  # 110 "sharpness.cpp"
  first_gang_iter_9 = (hmpprt::gr_gbidx()) * iter_per_gang_9;
  # 110 "sharpness.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (quarterHeight_6 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (quarterHeight_6 - 1));
  # 110 "sharpness.cpp"
  hmpprt::s32 h_11;
  # 110 "sharpness.cpp"
  # 111 "sharpness.cpp"
  for (h_11 = first_gang_iter_9 + (hmpprt::gr_btidy()) ; h_11 <= last_gang_iter_9 ; h_11 = h_11 + (hmpprt::gr_btnumy()))
  {
   # 112 "sharpness.cpp"
   *(yPlaneCSER + h_11 * 4 * width) = *(yPlaneDown + h_11 * quarterWidth);
  }
  # 103 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 103 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_107_internal_1(hmpprt::s32 width_59, hmpprt::s32 quarterWidth_8, hmpprt::s32 quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_14)
{
 # 103 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_12), "quarterHeight_6");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_8), "quarterWidth");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_59), "width");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_15, 8, "yPlaneCSER");
  __hmppcg_call.addLocalParameter(&yPlaneDown_14, 8, "yPlaneDown");
  __hmppcg_call.launch(hmpp_acc_region_main_107_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 103 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_107(hmpprt::s32 width_31, hmpprt::s32 quarterWidth_22, hmpprt::s32 quarterHeight, hmpprt::u08* yPlaneCSER_33, hmpprt::u08* yPlaneDown_6)
{
 # 119 "sharpness.cpp"
 (hmpp_acc_region_main_107_internal_1(width_31, quarterWidth_22, quarterHeight, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_33), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_6)));
}
#endif // __CUDACC__



# 119 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_119_parallel_region_1(hmpprt::s32 quarterHeight_11, hmpprt::s32 width_33, hmpprt::u08* yPlaneCSER_21)
{
 # 121 "sharpness.cpp"
 {
  # 122 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_8;
  # 122 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_8;
  # 122 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_8;
  # 122 "sharpness.cpp"
  iter_per_gang_8 = ((1 + (quarterHeight_11 - 1) / 192) > 256 ? (1 + (quarterHeight_11 - 1) / 192) : 256);
  # 122 "sharpness.cpp"
  first_gang_iter_8 = (hmpprt::gr_gbidx()) * iter_per_gang_8;
  # 122 "sharpness.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (quarterHeight_11 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (quarterHeight_11 - 1));
  # 122 "sharpness.cpp"
  hmpprt::s32 h_12;
  # 122 "sharpness.cpp"
  # 123 "sharpness.cpp"
  for (h_12 = first_gang_iter_8 + (hmpprt::gr_btidy()) ; h_12 <= last_gang_iter_8 ; h_12 = h_12 + (hmpprt::gr_btnumy()))
  {
   # 124 "sharpness.cpp"
   if (h_12 < quarterHeight_11 - 1)
   {
    # 126 "sharpness.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33))) / 4);
    # 127 "sharpness.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 2) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 2) / 4);
    # 128 "sharpness.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 3) * width_33) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) + (hmpprt::s32 ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 3) / 4);
   }
   else
   {
    # 132 "sharpness.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = *(yPlaneCSER_21 + h_12 * 4 * width_33);
   }
  }
  # 119 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 119 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_119_internal_1(hmpprt::s32 width_58, hmpprt::s32 quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_32)
{
 # 119 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_5), "quarterHeight_11");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_58), "width_33");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_32, 8, "yPlaneCSER_21");
  __hmppcg_call.launch(hmpp_acc_region_main_119_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 119 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_119(hmpprt::s32 width_19, hmpprt::s32 quarterHeight_15, hmpprt::u08* yPlaneCSER_14)
{
 # 140 "sharpness.cpp"
 (hmpp_acc_region_main_119_internal_1(width_19, quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_14)));
}
#endif // __CUDACC__



# 140 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_140_loop1D_1(hmpprt::s32 width_35, hmpprt::s32 height, hmpprt::u08* yPlaneCSER_20)
{
 # 143 "sharpness.cpp"
 hmpprt::s32 h_13;
 # 145 "sharpness.cpp"
 h_13 = (hmpprt::gr_atidf());
 # 145 "sharpness.cpp"
 if (h_13 > height - 1)
 {
  # 145 "sharpness.cpp"
  goto __hmppcg_label_1;
 }
 # 145 "sharpness.cpp"
 *(yPlaneCSER_20 + (h_13 * width_35 + 1)) = *(yPlaneCSER_20 + h_13 * width_35);
 # 140 "sharpness.cpp"
 __hmppcg_label_1:;
}
#endif // __CUDACC__



# 140 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_140_internal_1(hmpprt::s32* width_18, hmpprt::s32 height_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_13)
{
 # 142 "sharpness.cpp"
 hmpprt::s32 width_20;
 # 142 "sharpness.cpp"
 width_20 = *width_18;
 # 142 "sharpness.cpp"
 {
  # 140 "sharpness.cpp"
  if (height_15 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_15 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_35");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_15), "height");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_13, 8, "yPlaneCSER_20");
   __hmppcg_call.launch(hmpp_acc_region_main_140_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 140 "sharpness.cpp"
 *width_18 = width_20;
}
#endif // __CUDACC__



# 140 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_140(hmpprt::s32* width_57, hmpprt::s32 height_29, hmpprt::u08* yPlaneCSER_31)
{
 # 152 "sharpness.cpp"
 (hmpp_acc_region_main_140_internal_1(width_57, height_29, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_31)));
}
#endif // __CUDACC__



# 152 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_152_loop1D_1(hmpprt::s32 quarterWidth_15, hmpprt::u08* yPlaneCSER_19, hmpprt::u08* yPlaneDown_11)
{
 # 155 "sharpness.cpp"
 hmpprt::s32 w_11;
 # 157 "sharpness.cpp"
 w_11 = (hmpprt::gr_atidf());
 # 157 "sharpness.cpp"
 if (w_11 > quarterWidth_15 - 1)
 {
  # 157 "sharpness.cpp"
  goto __hmppcg_label_2;
 }
 # 157 "sharpness.cpp"
 *(yPlaneCSER_19 + w_11 * 4) = *(yPlaneDown_11 + w_11);
 # 152 "sharpness.cpp"
 __hmppcg_label_2:;
}
#endif // __CUDACC__



# 152 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_152_internal_1(hmpprt::s32* width_56, hmpprt::s32 quarterWidth_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_13)
{
 # 154 "sharpness.cpp"
 hmpprt::s32 width_21;
 # 154 "sharpness.cpp"
 width_21 = *width_56;
 # 154 "sharpness.cpp"
 {
  # 152 "sharpness.cpp"
  if (quarterWidth_21 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_21 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_21), "quarterWidth_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_12, 8, "yPlaneCSER_19");
   __hmppcg_call.addLocalParameter(&yPlaneDown_13, 8, "yPlaneDown_11");
   __hmppcg_call.launch(hmpp_acc_region_main_152_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 152 "sharpness.cpp"
 *width_56 = width_21;
}
#endif // __CUDACC__



# 152 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_152(hmpprt::s32* width_17, hmpprt::s32 quarterWidth_7, hmpprt::u08* yPlaneCSER_30, hmpprt::u08* yPlaneDown_5)
{
 # 164 "sharpness.cpp"
 (hmpp_acc_region_main_152_internal_1(width_17, quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_30), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_5)));
}
#endif // __CUDACC__



# 164 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_164_loop1D_1(hmpprt::s32 quarterWidth_6, hmpprt::u08* yPlaneCSER_11)
{
 # 167 "sharpness.cpp"
 hmpprt::s32 w_12;
 # 169 "sharpness.cpp"
 w_12 = (hmpprt::gr_atidf());
 # 169 "sharpness.cpp"
 if (w_12 > quarterWidth_6 - 1)
 {
  # 169 "sharpness.cpp"
  goto __hmppcg_label_3;
 }
 # 169 "sharpness.cpp"
 if (w_12 < quarterWidth_6 - 1)
 {
  # 171 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_11 + w_12 * 4)) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_11 + (w_12 * 4 + 4)))) / 4);
  # 172 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_11 + w_12 * 4)) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_11 + (w_12 * 4 + 4))) * 2) / 4);
  # 173 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_11 + w_12 * 4)) + (hmpprt::s32 ) (*(yPlaneCSER_11 + (w_12 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 177 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 1)) = *(yPlaneCSER_11 + w_12 * 4);
 }
 # 164 "sharpness.cpp"
 __hmppcg_label_3:;
}
#endif // __CUDACC__



# 164 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_164_internal_1(hmpprt::s32* width_16, hmpprt::s32 quarterWidth_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_18)
{
 # 166 "sharpness.cpp"
 hmpprt::s32 width_22;
 # 166 "sharpness.cpp"
 width_22 = *width_16;
 # 166 "sharpness.cpp"
 {
  # 164 "sharpness.cpp"
  if (quarterWidth_14 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_14 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_14), "quarterWidth_6");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_18, 8, "yPlaneCSER_11");
   __hmppcg_call.launch(hmpp_acc_region_main_164_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 164 "sharpness.cpp"
 *width_16 = width_22;
}
#endif // __CUDACC__



# 164 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_164(hmpprt::s32* width_55, hmpprt::s32 quarterWidth_19, hmpprt::u08* yPlaneCSER_36)
{
 # 185 "sharpness.cpp"
 (hmpp_acc_region_main_164_internal_1(width_55, quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_36)));
}
#endif // __CUDACC__



# 185 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_185_loop1D_1(hmpprt::s32 width_36, hmpprt::u08* yPlaneCSER_10)
{
 # 188 "sharpness.cpp"
 hmpprt::s32 w_13;
 # 190 "sharpness.cpp"
 w_13 = (hmpprt::gr_atidf());
 # 190 "sharpness.cpp"
 if (w_13 > width_36 - 1)
 {
  # 190 "sharpness.cpp"
  goto __hmppcg_label_4;
 }
 # 190 "sharpness.cpp"
 *(yPlaneCSER_10 + (width_36 + w_13)) = *(yPlaneCSER_10 + w_13);
 # 185 "sharpness.cpp"
 __hmppcg_label_4:;
}
#endif // __CUDACC__



# 185 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_185_internal_1(hmpprt::s32* width_15, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_17)
{
 # 187 "sharpness.cpp"
 hmpprt::s32 width_23;
 # 187 "sharpness.cpp"
 width_23 = *width_15;
 # 187 "sharpness.cpp"
 {
  # 185 "sharpness.cpp"
  if (width_23 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_23 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_23), "width_36");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_17, 8, "yPlaneCSER_10");
   __hmppcg_call.launch(hmpp_acc_region_main_185_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 185 "sharpness.cpp"
 *width_15 = width_23;
}
#endif // __CUDACC__



# 185 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_185(hmpprt::s32* width_54, hmpprt::u08* yPlaneCSER_35)
{
 # 197 "sharpness.cpp"
 (hmpp_acc_region_main_185_internal_1(width_54, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_35)));
}
#endif // __CUDACC__



# 197 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_197_loop1D_1(hmpprt::s32 quarterWidth_5, hmpprt::s32 quarterHeight_10, hmpprt::u08* yPlaneCSER_29, hmpprt::u08* yPlaneDown_10, hmpprt::s32 width_24, hmpprt::s32 height_17)
{
 # 200 "sharpness.cpp"
 hmpprt::s32 w_14;
 # 202 "sharpness.cpp"
 w_14 = (hmpprt::gr_atidf());
 # 202 "sharpness.cpp"
 if (w_14 > quarterWidth_5 - 1)
 {
  # 202 "sharpness.cpp"
  goto __hmppcg_label_5;
 }
 # 202 "sharpness.cpp"
 *(yPlaneCSER_29 + ((height_17 - 2) * width_24 + w_14 * 4)) = *(yPlaneDown_10 + ((quarterHeight_10 - 1) * quarterWidth_5 + w_14));
 # 197 "sharpness.cpp"
 __hmppcg_label_5:;
}
#endif // __CUDACC__



# 197 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_197_internal_1(hmpprt::s32* width_14, hmpprt::s32* height_11, hmpprt::s32 quarterWidth_13, hmpprt::s32 quarterHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_44, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_4)
{
 # 199 "sharpness.cpp"
 hmpprt::s32 height_12;
 # 199 "sharpness.cpp"
 height_12 = *height_11;
 # 199 "sharpness.cpp"
 hmpprt::s32 width_37;
 # 199 "sharpness.cpp"
 width_37 = *width_14;
 # 199 "sharpness.cpp"
 {
  # 197 "sharpness.cpp"
  if (quarterWidth_13 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_13 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_13), "quarterWidth_5");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_4), "quarterHeight_10");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_44, 8, "yPlaneCSER_29");
   __hmppcg_call.addLocalParameter(&yPlaneDown_4, 8, "yPlaneDown_10");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_37), "width_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_12), "height_17");
   __hmppcg_call.launch(hmpp_acc_region_main_197_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 197 "sharpness.cpp"
 *width_14 = width_37;
 # 197 "sharpness.cpp"
 *height_11 = height_12;
}
#endif // __CUDACC__



# 197 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_197(hmpprt::s32* width_53, hmpprt::s32* height_28, hmpprt::s32 quarterWidth_18, hmpprt::s32 quarterHeight_14, hmpprt::u08* yPlaneCSER_9, hmpprt::u08* yPlaneDown_12)
{
 # 209 "sharpness.cpp"
 (hmpp_acc_region_main_197_internal_1(width_53, height_28, quarterWidth_18, quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_9), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_12)));
}
#endif // __CUDACC__



# 209 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_209_loop1D_1(hmpprt::s32 quarterWidth_4, hmpprt::u08* yPlaneCSER_8, hmpprt::s32 width_25, hmpprt::s32 height_13)
{
 # 212 "sharpness.cpp"
 hmpprt::s32 w_15;
 # 214 "sharpness.cpp"
 w_15 = (hmpprt::gr_atidf());
 # 214 "sharpness.cpp"
 if (w_15 > quarterWidth_4 - 1)
 {
  # 214 "sharpness.cpp"
  goto __hmppcg_label_6;
 }
 # 214 "sharpness.cpp"
 if (w_15 < quarterWidth_4 - 1)
 {
  # 216 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4)))) / 4);
  # 217 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4))) * 2) / 4);
  # 218 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) + (hmpprt::s32 ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 222 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 1)) = *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4));
 }
 # 209 "sharpness.cpp"
 __hmppcg_label_6:;
}
#endif // __CUDACC__



# 209 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_209_internal_1(hmpprt::s32* width_52, hmpprt::s32* height_27, hmpprt::s32 quarterWidth_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_41)
{
 # 211 "sharpness.cpp"
 hmpprt::s32 height_18;
 # 211 "sharpness.cpp"
 height_18 = *height_27;
 # 211 "sharpness.cpp"
 hmpprt::s32 width_38;
 # 211 "sharpness.cpp"
 width_38 = *width_52;
 # 211 "sharpness.cpp"
 {
  # 209 "sharpness.cpp"
  if (quarterWidth_17 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_17), "quarterWidth_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_41, 8, "yPlaneCSER_8");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_38), "width_25");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_13");
   __hmppcg_call.launch(hmpp_acc_region_main_209_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 209 "sharpness.cpp"
 *width_52 = width_38;
 # 209 "sharpness.cpp"
 *height_27 = height_18;
}
#endif // __CUDACC__



# 209 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_209(hmpprt::s32* width_13, hmpprt::s32* height_10, hmpprt::s32 quarterWidth_12, hmpprt::u08* yPlaneCSER_28)
{
 # 230 "sharpness.cpp"
 (hmpp_acc_region_main_209_internal_1(width_13, height_10, quarterWidth_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_28)));
}
#endif // __CUDACC__



# 230 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_230_loop1D_1(hmpprt::u08* yPlaneCSER_7, hmpprt::s32 width_26, hmpprt::s32 height_14)
{
 # 233 "sharpness.cpp"
 hmpprt::s32 w_16;
 # 235 "sharpness.cpp"
 w_16 = (hmpprt::gr_atidf());
 # 235 "sharpness.cpp"
 if (w_16 > width_26 - 1)
 {
  # 235 "sharpness.cpp"
  goto __hmppcg_label_7;
 }
 # 235 "sharpness.cpp"
 *(yPlaneCSER_7 + ((height_14 - 1) * width_26 + w_16)) = *(yPlaneCSER_7 + ((height_14 - 2) * width_26 + w_16));
 # 230 "sharpness.cpp"
 __hmppcg_label_7:;
}
#endif // __CUDACC__



# 230 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_230_internal_1(hmpprt::s32* width_51, hmpprt::s32* height_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_27)
{
 # 232 "sharpness.cpp"
 hmpprt::s32 height_19;
 # 232 "sharpness.cpp"
 height_19 = *height_38;
 # 232 "sharpness.cpp"
 hmpprt::s32 width_39;
 # 232 "sharpness.cpp"
 width_39 = *width_51;
 # 232 "sharpness.cpp"
 {
  # 230 "sharpness.cpp"
  if (width_39 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_39 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_27, 8, "yPlaneCSER_7");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_39), "width_26");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_14");
   __hmppcg_call.launch(hmpp_acc_region_main_230_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 230 "sharpness.cpp"
 *width_51 = width_39;
 # 230 "sharpness.cpp"
 *height_38 = height_19;
}
#endif // __CUDACC__



# 230 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_230(hmpprt::s32* width_12, hmpprt::s32* height_9, hmpprt::u08* yPlaneCSER_40)
{
 # 242 "sharpness.cpp"
 (hmpp_acc_region_main_230_internal_1(width_12, height_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_40)));
}
#endif // __CUDACC__



# 242 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_242_loop1D_1(hmpprt::s32 quarterWidth_11, hmpprt::s32 quarterHeight_3, hmpprt::u08* yPlaneCSER_6, hmpprt::u08* yPlaneDown_3, hmpprt::s32 width_27)
{
 # 245 "sharpness.cpp"
 hmpprt::s32 h_14;
 # 247 "sharpness.cpp"
 h_14 = (hmpprt::gr_atidf());
 # 247 "sharpness.cpp"
 if (h_14 > quarterHeight_3 - 1)
 {
  # 247 "sharpness.cpp"
  goto __hmppcg_label_8;
 }
 # 247 "sharpness.cpp"
 *(yPlaneCSER_6 + (h_14 * 4 * width_27 + width_27 - 2)) = *(yPlaneDown_3 + (h_14 * quarterWidth_11 + quarterWidth_11 - 1));
 # 242 "sharpness.cpp"
 __hmppcg_label_8:;
}
#endif // __CUDACC__



# 242 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_242_internal_1(hmpprt::s32* width_50, hmpprt::s32 quarterWidth_20, hmpprt::s32 quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_39, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_17)
{
 # 244 "sharpness.cpp"
 hmpprt::s32 width_40;
 # 244 "sharpness.cpp"
 width_40 = *width_50;
 # 244 "sharpness.cpp"
 {
  # 242 "sharpness.cpp"
  if (quarterHeight_17 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_20), "quarterWidth_11");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_17), "quarterHeight_3");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_39, 8, "yPlaneCSER_6");
   __hmppcg_call.addLocalParameter(&yPlaneDown_17, 8, "yPlaneDown_3");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_40), "width_27");
   __hmppcg_call.launch(hmpp_acc_region_main_242_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 242 "sharpness.cpp"
 *width_50 = width_40;
}
#endif // __CUDACC__



# 242 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_242(hmpprt::s32* width_11, hmpprt::s32 quarterWidth_3, hmpprt::s32 quarterHeight_9, hmpprt::u08* yPlaneCSER_26, hmpprt::u08* yPlaneDown_9)
{
 # 254 "sharpness.cpp"
 (hmpp_acc_region_main_242_internal_1(width_11, quarterWidth_3, quarterHeight_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_26), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_9)));
}
#endif // __CUDACC__



# 254 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_254_loop1D_1(hmpprt::s32 quarterHeight_8, hmpprt::u08* yPlaneCSER_25, hmpprt::s32 width_28)
{
 # 257 "sharpness.cpp"
 hmpprt::s32 h_15;
 # 259 "sharpness.cpp"
 h_15 = (hmpprt::gr_atidf());
 # 259 "sharpness.cpp"
 if (h_15 > quarterHeight_8 - 1)
 {
  # 259 "sharpness.cpp"
  goto __hmppcg_label_9;
 }
 # 259 "sharpness.cpp"
 if (h_15 < quarterHeight_8 - 1)
 {
  # 261 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) * 3 + (hmpprt::s32 ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2)))) / 4);
  # 262 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) * 2 + (hmpprt::s32 ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 2) / 4);
  # 263 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) + (hmpprt::s32 ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 3) / 4);
 }
 else
 {
  # 267 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
  # 268 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
  # 269 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
 }
 # 254 "sharpness.cpp"
 __hmppcg_label_9:;
}
#endif // __CUDACC__



# 254 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_254_internal_1(hmpprt::s32* width_49, hmpprt::s32 quarterHeight_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_43)
{
 # 256 "sharpness.cpp"
 hmpprt::s32 width_41;
 # 256 "sharpness.cpp"
 width_41 = *width_49;
 # 256 "sharpness.cpp"
 {
  # 254 "sharpness.cpp"
  if (quarterHeight_13 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_13 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_13), "quarterHeight_8");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_43, 8, "yPlaneCSER_25");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_41), "width_28");
   __hmppcg_call.launch(hmpp_acc_region_main_254_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 254 "sharpness.cpp"
 *width_49 = width_41;
}
#endif // __CUDACC__



# 254 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_254(hmpprt::s32* width_10, hmpprt::s32 quarterHeight_2, hmpprt::u08* yPlaneCSER_5)
{
 # 277 "sharpness.cpp"
 (hmpp_acc_region_main_254_internal_1(width_10, quarterHeight_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_5)));
}
#endif // __CUDACC__



# 277 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_277_loop1D_1(hmpprt::s32 height_26, hmpprt::u08* yPlaneCSER_24, hmpprt::s32 width_29)
{
 # 280 "sharpness.cpp"
 hmpprt::s32 h_16;
 # 282 "sharpness.cpp"
 h_16 = (hmpprt::gr_atidf());
 # 282 "sharpness.cpp"
 if (h_16 > height_26 - 1)
 {
  # 282 "sharpness.cpp"
  goto __hmppcg_label_10;
 }
 # 282 "sharpness.cpp"
 *(yPlaneCSER_24 + (h_16 * width_29 + width_29 - 1)) = *(yPlaneCSER_24 + (h_16 * width_29 + width_29 - 2));
 # 277 "sharpness.cpp"
 __hmppcg_label_10:;
}
#endif // __CUDACC__



# 277 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_277_internal_1(hmpprt::s32* width_9, hmpprt::s32 height_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_42)
{
 # 279 "sharpness.cpp"
 hmpprt::s32 width_42;
 # 279 "sharpness.cpp"
 width_42 = *width_9;
 # 279 "sharpness.cpp"
 {
  # 277 "sharpness.cpp"
  if (height_37 - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_37 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_37), "height_26");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_42, 8, "yPlaneCSER_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_42), "width_29");
   __hmppcg_call.launch(hmpp_acc_region_main_277_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 277 "sharpness.cpp"
 *width_9 = width_42;
}
#endif // __CUDACC__



# 277 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_277(hmpprt::s32* width_68, hmpprt::s32 height_8, hmpprt::u08* yPlaneCSER_4)
{
 # 289 "sharpness.cpp"
 (hmpp_acc_region_main_277_internal_1(width_68, height_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_4)));
}
#endif // __CUDACC__



# 289 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_289_loop1D_1(hmpprt::s32 width_30, hmpprt::s32 quarterWidth_2, hmpprt::s32 quarterHeight_1, hmpprt::u08* yPlaneCSER_3, hmpprt::u08* yPlaneDown_2)
{
 # 292 "sharpness.cpp"
 hmpprt::s32 h_17;
 # 295 "sharpness.cpp"
 hmpprt::s32 w_17;
 # 292 "sharpness.cpp"
 hmpprt::s32 h_22;
 # 297 "sharpness.cpp"
 h_22 = (hmpprt::gr_atidf());
 # 297 "sharpness.cpp"
 if (h_22 > (quarterHeight_1 +  -1) * (quarterWidth_2 - 1) - 1)
 {
  # 297 "sharpness.cpp"
  goto __hmppcg_label_11;
 }
 # 297 "sharpness.cpp"
 w_17 = h_22 % (quarterWidth_2 +  -1);
 # 297 "sharpness.cpp"
 h_17 = h_22 / (quarterWidth_2 +  -1);
 # 297 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) / 8 / 8);
 # 298 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8);
 # 299 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8);
 # 300 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8);
 # 302 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8);
 # 303 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8);
 # 304 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8);
 # 305 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8);
 # 307 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8);
 # 308 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8);
 # 309 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8);
 # 310 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8);
 # 312 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 2)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8);
 # 313 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 3)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8);
 # 314 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 4)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8);
 # 315 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 5)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8 + ((hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (hmpprt::s32 ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8);
 # 289 "sharpness.cpp"
 __hmppcg_label_11:;
}
#endif // __CUDACC__



# 289 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_289_internal_1(hmpprt::s32* width_67, hmpprt::s32 quarterWidth_16, hmpprt::s32 quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_16)
{
 # 291 "sharpness.cpp"
 hmpprt::s32 width_44;
 # 291 "sharpness.cpp"
 width_44 = *width_67;
 # 291 "sharpness.cpp"
 {
  # 289 "sharpness.cpp"
  if ((quarterHeight_16 +  -1) * (quarterWidth_16 - 1) - 1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX(((quarterHeight_16 +  -1) * (quarterWidth_16 - 1) - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_44), "width_30");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_16), "quarterWidth_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_16), "quarterHeight_1");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_38, 8, "yPlaneCSER_3");
   __hmppcg_call.addLocalParameter(&yPlaneDown_16, 8, "yPlaneDown_2");
   __hmppcg_call.launch(hmpp_acc_region_main_289_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
 }
 # 289 "sharpness.cpp"
 *width_67 = width_44;
}
#endif // __CUDACC__



# 289 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_289(hmpprt::s32* width_8, hmpprt::s32 quarterWidth_10, hmpprt::s32 quarterHeight_7, hmpprt::u08* yPlaneCSER_23, hmpprt::u08* yPlaneDown_8)
{
 # 323 "sharpness.cpp"
 (hmpp_acc_region_main_289_internal_1(width_8, quarterWidth_10, quarterHeight_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_23), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_8)));
}
#endif // __CUDACC__



# 323 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_326_parallel_region_1(hmpprt::s32 height_7, hmpprt::s16* pError, hmpprt::s32 width_7, hmpprt::u08* yPlane, hmpprt::u08* yPlaneCSER_2)
{
 # 325 "sharpness.cpp"
 {
  # 329 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_7;
  # 329 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_7;
  # 329 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_7;
  # 329 "sharpness.cpp"
  iter_per_gang_7 = ((1 + (height_7 * width_7 - 1) / 192) > 256 ? (1 + (height_7 * width_7 - 1) / 192) : 256);
  # 329 "sharpness.cpp"
  first_gang_iter_7 = (hmpprt::gr_gbidx()) * iter_per_gang_7;
  # 329 "sharpness.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (height_7 * width_7 - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (height_7 * width_7 - 1));
  # 329 "sharpness.cpp"
  hmpprt::s32 h_23;
  # 329 "sharpness.cpp"
  # 333 "sharpness.cpp"
  for (h_23 = first_gang_iter_7 + (hmpprt::gr_btidy()) ; h_23 <= last_gang_iter_7 ; h_23 = h_23 + (hmpprt::gr_btnumy()))
  {
   # 329 "sharpness.cpp"
   hmpprt::s32 h_18;
   # 332 "sharpness.cpp"
   hmpprt::s32 w_18;
   # 334 "sharpness.cpp"
   w_18 = h_23 % width_7;
   # 334 "sharpness.cpp"
   h_18 = h_23 / width_7;
   # 334 "sharpness.cpp"
   *(pError + (h_18 * width_7 + w_18)) = (hmpprt::s16 ) ((hmpprt::s32 ) (*(yPlane + (h_18 * width_7 + w_18))) - (hmpprt::s32 ) (*(yPlaneCSER_2 + (h_18 * width_7 + w_18))));
  }
  # 323 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 323 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_326_internal_1(hmpprt::s32 width_66, hmpprt::s32 height_36, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_4)
{
 # 323 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_36), "height_7");
  __hmppcg_call.addLocalParameter(&pError_4, 8, "pError");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_66), "width_7");
  __hmppcg_call.addLocalParameter(&yPlane_10, 8, "yPlane");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_37, 8, "yPlaneCSER_2");
  __hmppcg_call.launch(hmpp_acc_region_main_326_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 323 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_326(hmpprt::s32 width_48, hmpprt::s32 height_25, hmpprt::u08* yPlane_5, hmpprt::u08* yPlaneCSER_22, hmpprt::s16* pError_2)
{
 # 342 "sharpness.cpp"
 (hmpp_acc_region_main_326_internal_1(width_48, height_25, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_22), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pError_2)));
}
#endif // __CUDACC__



# 342 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_346_parallel_region_1(hmpprt::s32 height_6, hmpprt::s16* pEdge, hmpprt::s32 width_6, hmpprt::u08* yPlane_4)
{
 # 344 "sharpness.cpp"
 {
  # 349 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_6;
  # 349 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_6;
  # 349 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_6;
  # 349 "sharpness.cpp"
  iter_per_gang_6 = ((1 + (height_6 * width_6 - 1) / 192) > 256 ? (1 + (height_6 * width_6 - 1) / 192) : 256);
  # 349 "sharpness.cpp"
  first_gang_iter_6 = (hmpprt::gr_gbidx()) * iter_per_gang_6;
  # 349 "sharpness.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (height_6 * width_6 - 1) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (height_6 * width_6 - 1));
  # 349 "sharpness.cpp"
  hmpprt::s32 y_2;
  # 349 "sharpness.cpp"
  # 353 "sharpness.cpp"
  for (y_2 = first_gang_iter_6 + (hmpprt::gr_btidy()) ; y_2 <= last_gang_iter_6 ; y_2 = y_2 + (hmpprt::gr_btnumy()))
  {
   # 349 "sharpness.cpp"
   hmpprt::s32 y_1;
   # 352 "sharpness.cpp"
   hmpprt::s32 x_1;
   # 354 "sharpness.cpp"
   x_1 = y_2 % width_6;
   # 354 "sharpness.cpp"
   y_1 = y_2 / width_6;
   # 354 "sharpness.cpp"
   if (y_1 == 0 || y_1 == height_6 - 1 || x_1 == 0 || x_1 == width_6 - 1)
   {
    # 356 "sharpness.cpp"
    *(pEdge + (y_1 * width_6 + x_1)) = (hmpprt::s16) 0;
   }
   else
   {
    # 360 "sharpness.cpp"
    hmpprt::s32 gx;
    # 360 "sharpness.cpp"
    gx = (hmpprt::s32 ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 + 1))) + ((hmpprt::s32 ) (*(yPlane_4 + (y_1 * width_6 + x_1 + 1))) << 1) + (hmpprt::s32 ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 + 1))) - ((hmpprt::s32 ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane_4 + (y_1 * width_6 + x_1 - 1))) << 1) + (hmpprt::s32 ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 - 1))));
    # 361 "sharpness.cpp"
    hmpprt::s32 gy;
    # 361 "sharpness.cpp"
    gy = (hmpprt::s32 ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1))) << 1) + (hmpprt::s32 ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 + 1))) - ((hmpprt::s32 ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 - 1))) + ((hmpprt::s32 ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1))) << 1) + (hmpprt::s32 ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 + 1))));
    # 362 "sharpness.cpp"
    hmpprt::s32 edgeV;
    # 362 "sharpness.cpp"
    edgeV = ((gx) > 0 ? (gx) : -(gx)) + ((gy) > 0 ? (gy) : -(gy));
    # 363 "sharpness.cpp"
    *(pEdge + (y_1 * width_6 + x_1)) = (hmpprt::s16 ) (edgeV);
   }
  }
  # 342 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 342 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_346_internal_1(hmpprt::s32 width_65, hmpprt::s32 height_35, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_8)
{
 # 342 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_35), "height_6");
  __hmppcg_call.addLocalParameter(&pEdge_8, 8, "pEdge");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_65), "width_6");
  __hmppcg_call.addLocalParameter(&yPlane_14, 8, "yPlane_4");
  __hmppcg_call.launch(hmpp_acc_region_main_346_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 342 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_346(hmpprt::s32 width_47, hmpprt::s32 height_24, hmpprt::u08* yPlane_9, hmpprt::s16* pEdge_4)
{
 # 372 "sharpness.cpp"
 (hmpp_acc_region_main_346_internal_1(width_47, height_24, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_9), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_4)));
}
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void reduce_s64_add_xy(hmpprt::s64 neutral, hmpprt::s64* scalar, hmpprt::s32 size, hmpprt::s64* array)
{
 
 hmpprt::s64 * tmpa = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0));
 
 # 372 "sharpness.cpp"
 hmpprt::s64 var;
 # 372 "sharpness.cpp"
 var = neutral;
 # 372 "sharpness.cpp"
 hmpprt::s32 end_5;
 # 372 "sharpness.cpp"
 hmpprt::s32 i;
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 for (i = (hmpprt::gr_btidf()), end_5 = size - 1 ; i <= end_5 ; i = i + 512)
 {
  # 372 "sharpness.cpp"
  var = var + *(array + i);
 }
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 *(tmpa + (hmpprt::gr_btidf())) = var;
 # 372 "sharpness.cpp"
 hmpprt::s32 n_1;
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 for (n_1 = (511 >> 1) + 1 ; n_1 > 0 ; n_1 = (n_1 >> 1))
 {
  # 372 "sharpness.cpp"
  hmpprt::s32 next_1;
  # 372 "sharpness.cpp"
  next_1 = (hmpprt::gr_btidf()) + n_1;
  # 372 "sharpness.cpp"
  (hmpprt::gr_barrier());
  # 372 "sharpness.cpp"
  if ((hmpprt::gr_btidf()) < n_1 && next_1 < 512)
  {
   # 372 "sharpness.cpp"
   *(tmpa + (hmpprt::gr_btidf())) = *(tmpa + (hmpprt::gr_btidf())) + *(tmpa + next_1);
  }
 }
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 if ((hmpprt::gr_btidf()) == 0)
 {
  # 372 "sharpness.cpp"
  *scalar = *tmpa + *scalar;
 }
}
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_375_parallel_region_1(hmpprt::s64* gang_prv_red_sum_2, hmpprt::s32 height_5, hmpprt::s16* pEdge_3, hmpprt::s32 width_5)
{
 
 hmpprt::s64 * sum_3 = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0));
 
 hmpprt::s64 * tmpr_2 = (hmpprt::s64 *)(((char *)hmpp_sharedmem + 0+8));
 
 # 374 "sharpness.cpp"
 hmpprt::s64 tmp_27;
 # 374 "sharpness.cpp"
 if ((hmpprt::gr_btidf()) == 0)
 {
  # 374 "sharpness.cpp"
  *sum_3 = 0;
 }
 # 374 "sharpness.cpp"
 (hmpprt::gr_barrier());
 # 374 "sharpness.cpp"
 {
  # 372 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_5;
  # 372 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_5;
  # 372 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_5;
  # 372 "sharpness.cpp"
  iter_per_gang_5 = ((1 + (height_5 * width_5 - 1) / 192) > 256 ? (1 + (height_5 * width_5 - 1) / 192) : 256);
  # 372 "sharpness.cpp"
  first_gang_iter_5 = (hmpprt::gr_gbidx()) * iter_per_gang_5;
  # 372 "sharpness.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < (height_5 * width_5 - 1) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : (height_5 * width_5 - 1));
  # 372 "sharpness.cpp"
  hmpprt::s64 sum_2;
  # 378 "sharpness.cpp"
  sum_2 = 0;
  # 378 "sharpness.cpp"
  hmpprt::s32 i_4;
  # 378 "sharpness.cpp"
  # 382 "sharpness.cpp"
  for (i_4 = first_gang_iter_5 + (hmpprt::gr_btidy()) ; i_4 <= last_gang_iter_5 ; i_4 = i_4 + (hmpprt::gr_btnumy()))
  {
   # 378 "sharpness.cpp"
   hmpprt::s32 i_2;
   # 381 "sharpness.cpp"
   hmpprt::s32 j_2;
   # 383 "sharpness.cpp"
   j_2 = i_4 % width_5;
   # 383 "sharpness.cpp"
   i_2 = i_4 / width_5;
   # 383 "sharpness.cpp"
   sum_2 = sum_2 + (hmpprt::s64 ) (*(pEdge_3 + (i_2 * width_5 + j_2)));
  }
  # 372 "sharpness.cpp"
  # 372 "sharpness.cpp"
  *sum_3 = (reduce_s64_add_y(sum_2, tmpr_2, *sum_3));
 }
 # 372 "sharpness.cpp"
 tmp_27 = *sum_3;
 # 372 "sharpness.cpp"
 if ((hmpprt::gr_btidy()) == 0)
 {
  # 372 "sharpness.cpp"
  *(gang_prv_red_sum_2 + (hmpprt::gr_gbidx())) = tmp_27;
 }
 # 372 "sharpness.cpp"
 (hmpprt::gr_barrier());
}
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_375_internal_1(hmpprt::s32 width_64, hmpprt::s32 height_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  sum_4)
{
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  sum_1;
 # 372 "sharpness.cpp"
 hmpprt::s64 tmp_28;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&sum_1), hmpprt::MS_CUDA_SHARED, 8);
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64>  gang_prv_red_sum_1;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&gang_prv_red_sum_1), hmpprt::MS_CUDA_GLOB, 1536);
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  tmpr_3;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_3), hmpprt::MS_CUDA_SHARED, 2048);
 # 372 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_1, 8, "gang_prv_red_sum_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_34), "height_5");
  __hmppcg_call.addLocalParameter(&pEdge_11, 8, "pEdge_3");
  __hmppcg_call.addSharedParameter(sum_1, "sum_3");
  __hmppcg_call.addSharedParameter(tmpr_3, "tmpr_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_64), "width_5");
  __hmppcg_call.launch(hmpp_acc_region_main_375_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED,hmpprt::s64>  tmpr_1;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) (&tmpr_1), hmpprt::MS_CUDA_SHARED, 4096);
 # 372 "sharpness.cpp"
 tmp_28 = 0LL;
 # 372 "sharpness.cpp"
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
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_1, 8, "array");
  __hmppcg_call.launch(reduce_s64_add_xy, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) (&gang_prv_red_sum_1));
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) (&sum_1));
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_1));
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) (&tmpr_3));
}
#endif // __CUDACC__



# 372 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_375(hmpprt::s32 width_46, hmpprt::s32 height_23, hmpprt::s16* pEdge_7, hmpprt::s64* sum)
{
 # 391 "sharpness.cpp"
 (hmpp_acc_region_main_375_internal_1(width_46, height_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s64> (sum)));
}
#endif // __CUDACC__



# 391 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_411_parallel_region_1(double cutoff, double cutoff2, hmpprt::s32 height_4, double low, double order, double order2, hmpprt::s16* pEdge_2, hmpprt::s16* pError_1, hmpprt::s16* pSharpness, double peak, hmpprt::s32 width_4, hmpprt::u08* yPlaneCSER_1)
{
 # 393 "sharpness.cpp"
 {
  # 414 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_4;
  # 414 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_4;
  # 414 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_4;
  # 414 "sharpness.cpp"
  iter_per_gang_4 = ((1 + (height_4 * width_4 - 1) / 192) > 256 ? (1 + (height_4 * width_4 - 1) / 192) : 256);
  # 414 "sharpness.cpp"
  first_gang_iter_4 = (hmpprt::gr_gbidx()) * iter_per_gang_4;
  # 414 "sharpness.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < (height_4 * width_4 - 1) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : (height_4 * width_4 - 1));
  # 414 "sharpness.cpp"
  hmpprt::s32 h_24;
  # 414 "sharpness.cpp"
  # 418 "sharpness.cpp"
  for (h_24 = first_gang_iter_4 + (hmpprt::gr_btidy()) ; h_24 <= last_gang_iter_4 ; h_24 = h_24 + (hmpprt::gr_btnumy()))
  {
   # 419 "sharpness.cpp"
   hmpprt::s16 edge;
   # 414 "sharpness.cpp"
   hmpprt::s32 h_19;
   # 417 "sharpness.cpp"
   hmpprt::s32 w_19;
   # 419 "sharpness.cpp"
   w_19 = h_24 % width_4;
   # 419 "sharpness.cpp"
   h_19 = h_24 / width_4;
   # 419 "sharpness.cpp"
   edge = *(pEdge_2 + (h_19 * width_4 + w_19));
   # 420 "sharpness.cpp"
   double weight;
   # 420 "sharpness.cpp"
   weight = (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff2, (double) 2. * order2));
   # 421 "sharpness.cpp"
   double strength;
   # 421 "sharpness.cpp"
   strength = (peak - low) * ((double) 1. - (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff, (double) 2. * order)));
   # 422 "sharpness.cpp"
   strength = strength * weight + low;
   # 424 "sharpness.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = (hmpprt::s16 ) (*(yPlaneCSER_1 + (h_19 * width_4 + w_19)));
   # 425 "sharpness.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = *(pSharpness + (h_19 * width_4 + w_19)) + (double ) (*(pError_1 + (h_19 * width_4 + w_19))) * strength;
  }
  # 391 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 391 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_411_internal_1(hmpprt::s32 width_63, hmpprt::s32 height_33, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneCSER_34, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pError_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_6, double cutoff_2, double peak_2, double cutoff2_2, double order_2, double order2_2, double low_2)
{
 # 391 "sharpness.cpp"
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
  __hmppcg_call.addLocalParameter(&pEdge_6, 8, "pEdge_2");
  __hmppcg_call.addLocalParameter(&pError_5, 8, "pError_1");
  __hmppcg_call.addLocalParameter(&pSharpness_6, 8, "pSharpness");
  __hmppcg_call.addLocalParameter(&peak_2, 8, "peak");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_63), "width_4");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_34, 8, "yPlaneCSER_1");
  __hmppcg_call.launch(hmpp_acc_region_main_411_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 391 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_411(hmpprt::s32 width_45, hmpprt::s32 height_22, hmpprt::u08* yPlaneCSER_16, hmpprt::s16* pError_3, hmpprt::s16* pEdge_10, hmpprt::s16* pSharpness_3, double cutoff_1, double peak_1, double cutoff2_1, double order_1, double order2_1, double low_1)
{
 # 433 "sharpness.cpp"
 (hmpp_acc_region_main_411_internal_1(width_45, height_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneCSER_16), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pError_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_10), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_3), cutoff_1, peak_1, cutoff2_1, order_1, order2_1, low_1));
}
#endif // __CUDACC__



# 433 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_436_parallel_region_1(float cutoff3, hmpprt::s32 height_3, float low3, float order3, hmpprt::s16* pEdge_1, hmpprt::s16* pSharpness_2, float peak3, hmpprt::s32 width_3, hmpprt::u08* yPlane_3)
{
 # 435 "sharpness.cpp"
 {
  # 439 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 439 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 439 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 439 "sharpness.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 439 "sharpness.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 439 "sharpness.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 439 "sharpness.cpp"
  hmpprt::s32 h_25;
  # 439 "sharpness.cpp"
  # 443 "sharpness.cpp"
  for (h_25 = first_gang_iter_3 + (hmpprt::gr_btidy()) ; h_25 <= last_gang_iter_3 ; h_25 = h_25 + (hmpprt::gr_btnumy()))
  {
   # 439 "sharpness.cpp"
   hmpprt::s32 h_20;
   # 442 "sharpness.cpp"
   hmpprt::s32 w_20;
   # 444 "sharpness.cpp"
   w_20 = h_25 % width_3;
   # 444 "sharpness.cpp"
   h_20 = h_25 / width_3;
   # 444 "sharpness.cpp"
   if (!(h_20 == 0 || h_20 == height_3 - 1 || w_20 == 0 || w_20 == width_3 - 1))
   {
    # 446 "sharpness.cpp"
    hmpprt::s32 enhanced;
    # 446 "sharpness.cpp"
    hmpprt::s32 maxValue;
    # 446 "sharpness.cpp"
    hmpprt::s32 minValue;
    # 447 "sharpness.cpp"
    double oscStrength;
    # 448 "sharpness.cpp"
    enhanced = (hmpprt::s32 ) (*(pSharpness_2 + (h_20 * width_3 + w_20)));
    # 450 "sharpness.cpp"
    maxValue = (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))));
    # 451 "sharpness.cpp"
    maxValue = ( (maxValue > (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? maxValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))));
    # 452 "sharpness.cpp"
    maxValue = ( (maxValue > (hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? maxValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))));
    # 454 "sharpness.cpp"
    minValue = (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))));
    # 455 "sharpness.cpp"
    minValue = ( (minValue < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))) ? minValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))));
    # 456 "sharpness.cpp"
    minValue = ( (minValue < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))) ? minValue : ((hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (hmpprt::s32 ) ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (hmpprt::s32 ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))));
    # 460 "sharpness.cpp"
    double cutoff2Order;
    # 460 "sharpness.cpp"
    cutoff2Order = pow((double ) (cutoff3), (double ) ((float) 2. * order3));
    # 461 "sharpness.cpp"
    double edge2Order;
    # 461 "sharpness.cpp"
    edge2Order = pow((double ) (*(pEdge_1 + (h_20 * width_3 + w_20))), (double) 2. * (double ) (order3));
    # 462 "sharpness.cpp"
    oscStrength = ((double ) (peak3) * cutoff2Order + (double ) (low3) * edge2Order) / (cutoff2Order + edge2Order);
    # 466 "sharpness.cpp"
    if (enhanced > maxValue)
    {
     # 468 "sharpness.cpp"
     *(pSharpness_2 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue) < (double) 255.) ? ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue)) : ((double) 255.));
    }
    else
    {
     # 470 "sharpness.cpp"
     if (enhanced < minValue)
     {
      # 472 "sharpness.cpp"
      *(pSharpness_2 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( ((double) 0. > (double ) (minValue) - oscStrength * (double ) (minValue - enhanced)) ? ((double) 0.) : ((double ) (minValue) - oscStrength * (double ) (minValue - enhanced)));
     }
     else
     {
      # 476 "sharpness.cpp"
      *(pSharpness_2 + (h_20 * width_3 + w_20)) = (hmpprt::s16 ) ( (( (enhanced > 0) ? enhanced : 0) < 255) ? ( (enhanced > 0) ? enhanced : 0) : 255);
     }
    }
   }
  }
  # 433 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 433 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_436_internal_1(hmpprt::s32 width_62, hmpprt::s32 height_32, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_8, float cutoff3_2, float order3_2, float peak3_2, float low3_2)
{
 # 433 "sharpness.cpp"
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
  __hmppcg_call.addLocalParameter((float) (order3_2) , "order3");
  __hmppcg_call.addLocalParameter(&pEdge_9, 8, "pEdge_1");
  __hmppcg_call.addLocalParameter(&pSharpness_8, 8, "pSharpness_2");
  __hmppcg_call.addLocalParameter((float) (peak3_2) , "peak3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_62), "width_3");
  __hmppcg_call.addLocalParameter(&yPlane_13, 8, "yPlane_3");
  __hmppcg_call.launch(hmpp_acc_region_main_436_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 433 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_436(hmpprt::s32 width_43, hmpprt::s32 height_21, hmpprt::u08* yPlane_8, hmpprt::s16* pEdge_5, hmpprt::s16* pSharpness_5, float cutoff3_1, float order3_1, float peak3_1, float low3_1)
{
 # 486 "sharpness.cpp"
 (hmpp_acc_region_main_436_internal_1(width_43, height_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_8), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pEdge_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_5), cutoff3_1, order3_1, peak3_1, low3_1));
}
#endif // __CUDACC__



# 486 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_490_parallel_region_1(hmpprt::s32 height_2, hmpprt::s16* pSharpness_1, hmpprt::s32 width_2, hmpprt::u08* yPlane_2)
{
 # 488 "sharpness.cpp"
 {
  # 493 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_2;
  # 493 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 493 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 493 "sharpness.cpp"
  iter_per_gang_2 = ((1 + (height_2 * width_2 - 1) / 192) > 256 ? (1 + (height_2 * width_2 - 1) / 192) : 256);
  # 493 "sharpness.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * iter_per_gang_2;
  # 493 "sharpness.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 * width_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 * width_2 - 1));
  # 493 "sharpness.cpp"
  hmpprt::s32 h_26;
  # 493 "sharpness.cpp"
  # 497 "sharpness.cpp"
  for (h_26 = first_gang_iter_2 + (hmpprt::gr_btidy()) ; h_26 <= last_gang_iter_2 ; h_26 = h_26 + (hmpprt::gr_btnumy()))
  {
   # 493 "sharpness.cpp"
   hmpprt::s32 h_21;
   # 496 "sharpness.cpp"
   hmpprt::s32 w_21;
   # 498 "sharpness.cpp"
   w_21 = h_26 % width_2;
   # 498 "sharpness.cpp"
   h_21 = h_26 / width_2;
   # 498 "sharpness.cpp"
   *(yPlane_2 + (h_21 * width_2 + w_21)) = (hmpprt::u08 ) ( ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) > 255) ? 255 : ( ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) < 0) ? 0 : ((hmpprt::s32 ) (*(pSharpness_1 + (h_21 * width_2 + w_21))))));
  }
  # 486 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 486 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_490_internal_1(hmpprt::s32 width_61, hmpprt::s32 height_31, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  pSharpness_7)
{
 # 486 "sharpness.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_31), "height_2");
  __hmppcg_call.addLocalParameter(&pSharpness_7, 8, "pSharpness_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_61), "width_2");
  __hmppcg_call.addLocalParameter(&yPlane_12, 8, "yPlane_2");
  __hmppcg_call.launch(hmpp_acc_region_main_490_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 486 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_490(hmpprt::s32 width_34, hmpprt::s32 height_20, hmpprt::u08* yPlane_7, hmpprt::s16* pSharpness_4)
{
 # 23 "sharpness.cpp"
 (hmpp_acc_region_main_490_internal_1(width_34, height_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (pSharpness_4)));
}
#endif // __CUDACC__



# 23 "sharpness.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_84_parallel_region_1(hmpprt::s32 height_1, hmpprt::s32 quarterWidth_1, hmpprt::s32 width_1, hmpprt::u08* yPlaneDown_1, hmpprt::u08* yPlane_1)
{
 # 25 "sharpness.cpp"
 {
  # 87 "sharpness.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 87 "sharpness.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 87 "sharpness.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 87 "sharpness.cpp"
  iter_per_gang_1 = ((1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) > 256 ? (1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) : 256);
  # 87 "sharpness.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 87 "sharpness.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1));
  # 87 "sharpness.cpp"
  hmpprt::s32 i_5;
  # 87 "sharpness.cpp"
  # 91 "sharpness.cpp"
  for (i_5 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; i_5 <= last_gang_iter_1 ; i_5 = i_5 + (hmpprt::gr_btnumy()))
  {
   # 87 "sharpness.cpp"
   hmpprt::u08 tbt_1;
   # 87 "sharpness.cpp"
   hmpprt::s32 tbt_2;
   # 87 "sharpness.cpp"
   hmpprt::s32 tbt_3;
   # 87 "sharpness.cpp"
   hmpprt::s32 i_3;
   # 90 "sharpness.cpp"
   hmpprt::s32 j_3;
   # 92 "sharpness.cpp"
   j_3 = i_5 % ((width_1 + 3) / 4);
   # 92 "sharpness.cpp"
   i_3 = i_5 / ((width_1 + 3) / 4);
   # 92 "sharpness.cpp"
   tbt_1 = *(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 3));
   # 92 "sharpness.cpp"
   tbt_2 = (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 2)));
   # 92 "sharpness.cpp"
   tbt_3 = (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 3))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 1)));
   # 92 "sharpness.cpp"
   *(yPlaneDown_1 + (i_3 * 4 / 4 * quarterWidth_1 + j_3 * 4 / 4)) = (hmpprt::u08 ) (tbt_3 + tbt_2 + (hmpprt::s32 ) (tbt_1) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 3))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 1))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 2))) + (hmpprt::s32 ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 3))) + 8 >> 4);
  }
  # 23 "sharpness.cpp"
 }
}
#endif // __CUDACC__



# 23 "sharpness.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_84_internal_1(hmpprt::s32 width_60, hmpprt::s32 height_30, hmpprt::s32 quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  yPlaneDown_15)
{
 # 23 "sharpness.cpp"
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
  __hmppcg_call.launch(hmpp_acc_region_main_84_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 23 "sharpness.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_84(hmpprt::s32 width_32, hmpprt::s32 height_16, hmpprt::s32 quarterWidth_9, hmpprt::u08* yPlane_6, hmpprt::u08* yPlaneDown_7)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_84_internal_1(width_32, height_16, quarterWidth_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlane_6), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (yPlaneDown_7)));
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
      hmpp_acc_region_main_107_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_107_parallel_region_1");
      hmpp_acc_region_main_119_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_119_parallel_region_1");
      hmpp_acc_region_main_140_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_140_loop1D_1");
      hmpp_acc_region_main_152_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_152_loop1D_1");
      hmpp_acc_region_main_164_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_164_loop1D_1");
      hmpp_acc_region_main_185_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_185_loop1D_1");
      hmpp_acc_region_main_197_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_197_loop1D_1");
      hmpp_acc_region_main_209_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_209_loop1D_1");
      hmpp_acc_region_main_230_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_230_loop1D_1");
      hmpp_acc_region_main_242_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_242_loop1D_1");
      hmpp_acc_region_main_254_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_254_loop1D_1");
      hmpp_acc_region_main_277_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_277_loop1D_1");
      hmpp_acc_region_main_289_loop1D_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_289_loop1D_1");
      hmpp_acc_region_main_326_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_326_parallel_region_1");
      hmpp_acc_region_main_346_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_346_parallel_region_1");
      reduce_s64_add_xy = new hmpprt::CUDAGrid(hmpprt_module, "reduce_s64_add_xy");
      hmpp_acc_region_main_375_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_375_parallel_region_1");
      hmpp_acc_region_main_411_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_411_parallel_region_1");
      hmpp_acc_region_main_436_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_436_parallel_region_1");
      hmpp_acc_region_main_490_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_490_parallel_region_1");
      hmpp_acc_region_main_84_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_84_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_107", "prototype hmpp_acc_region_main_107(width: s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_119", "prototype hmpp_acc_region_main_119(width: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_140", "prototype hmpp_acc_region_main_140(width: ^host s32, height: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_152", "prototype hmpp_acc_region_main_152(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_164", "prototype hmpp_acc_region_main_164(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_185", "prototype hmpp_acc_region_main_185(width: ^host s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_197", "prototype hmpp_acc_region_main_197(width: ^host s32, height: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_209", "prototype hmpp_acc_region_main_209(width: ^host s32, height: ^host s32, quarterWidth: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_230", "prototype hmpp_acc_region_main_230(width: ^host s32, height: ^host s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_242", "prototype hmpp_acc_region_main_242(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_254", "prototype hmpp_acc_region_main_254(width: ^host s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_277", "prototype hmpp_acc_region_main_277(width: ^host s32, height: s32, yPlaneCSER: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_289", "prototype hmpp_acc_region_main_289(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_326", "prototype hmpp_acc_region_main_326(width: s32, height: s32, yPlane: ^cudaglob u8, yPlaneCSER: ^cudaglob u8, pError: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_346", "prototype hmpp_acc_region_main_346(width: s32, height: s32, yPlane: ^cudaglob u8, pEdge: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_375", "prototype hmpp_acc_region_main_375(width: s32, height: s32, pEdge: ^cudaglob s16, sum: ^cudaglob s64)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_411", "prototype hmpp_acc_region_main_411(width: s32, height: s32, yPlaneCSER: ^cudaglob u8, pError: ^cudaglob s16, pEdge: ^cudaglob s16, pSharpness: ^cudaglob s16, cutoff: double, peak: double, cutoff2: double, order: double, order2: double, low: double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_436", "prototype hmpp_acc_region_main_436(width: s32, height: s32, yPlane: ^cudaglob u8, pEdge: ^cudaglob s16, pSharpness: ^cudaglob s16, cutoff3: float, order3: float, peak3: float, low3: float)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_490", "prototype hmpp_acc_region_main_490(width: s32, height: s32, yPlane: ^cudaglob u8, pSharpness: ^cudaglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_84", "prototype hmpp_acc_region_main_84(width: s32, height: s32, quarterWidth: s32, yPlane: ^cudaglob u8, yPlaneDown: ^cudaglob u8)");

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
      delete hmpp_acc_region_main_107_parallel_region_1;
      delete hmpp_acc_region_main_119_parallel_region_1;
      delete hmpp_acc_region_main_140_loop1D_1;
      delete hmpp_acc_region_main_152_loop1D_1;
      delete hmpp_acc_region_main_164_loop1D_1;
      delete hmpp_acc_region_main_185_loop1D_1;
      delete hmpp_acc_region_main_197_loop1D_1;
      delete hmpp_acc_region_main_209_loop1D_1;
      delete hmpp_acc_region_main_230_loop1D_1;
      delete hmpp_acc_region_main_242_loop1D_1;
      delete hmpp_acc_region_main_254_loop1D_1;
      delete hmpp_acc_region_main_277_loop1D_1;
      delete hmpp_acc_region_main_289_loop1D_1;
      delete hmpp_acc_region_main_326_parallel_region_1;
      delete hmpp_acc_region_main_346_parallel_region_1;
      delete reduce_s64_add_xy;
      delete hmpp_acc_region_main_375_parallel_region_1;
      delete hmpp_acc_region_main_411_parallel_region_1;
      delete hmpp_acc_region_main_436_parallel_region_1;
      delete hmpp_acc_region_main_490_parallel_region_1;
      delete hmpp_acc_region_main_84_parallel_region_1;

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
