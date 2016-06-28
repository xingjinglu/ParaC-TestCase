
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

# 75 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_79(hmpprt::s32 height_8, hmpprt::s32 width_11, hmpprt::s32* pSrc_padding_3, hmpprt::u08* pBufL_cp_4)
;
#endif // __CUDACC__



# 75 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_79_internal_1(hmpprt::s32 height_19, hmpprt::s32 width_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_8)
;
#endif // __CUDACC__



# 12 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_79_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_79_parallel_region_1(hmpprt::s32 height_1, hmpprt::u08* pBufL_cp_1, hmpprt::s32* pSrc_padding_1, hmpprt::s32 width_1);
#endif // __CUDACC__




# 12 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_55(hmpprt::s32 height_9, hmpprt::s32 width_12, hmpprt::u08* Source_3, hmpprt::s32* pSrc_padding_2)
;
#endif // __CUDACC__



# 12 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_55_internal_1(hmpprt::s32 height_20, hmpprt::s32 width_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_4)
;
#endif // __CUDACC__



# 243 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_55_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_55_parallel_region_1(hmpprt::u08* Source_1, hmpprt::s32 height_2, hmpprt::s32* pSrc_padding, hmpprt::s32 width_2);
#endif // __CUDACC__




# 243 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_247(hmpprt::s32 height_10, hmpprt::s32 width_13, hmpprt::u08* Source_2, hmpprt::s16* LaplacianLayer_1, hmpprt::u08* UpsampleDst_5)
;
#endif // __CUDACC__



# 243 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_247_internal_1(hmpprt::s32 height_15, hmpprt::s32 width_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_9)
;
#endif // __CUDACC__



# 229 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_247_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_247_parallel_region_1(hmpprt::s16* LaplacianLayer, hmpprt::u08* Source, hmpprt::u08* UpsampleDst_1, hmpprt::s32 height_3, hmpprt::s32 width_3);
#endif // __CUDACC__




# 229 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_230(hmpprt::s32 width_4, hmpprt::s32 halfWidth_5, hmpprt::u08* DownsampleDst_5, hmpprt::u08* UpsampleDst_6)
;
#endif // __CUDACC__



# 229 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_230_internal_1(hmpprt::s32 width_27, hmpprt::s32 halfWidth_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_10)
;
#endif // __CUDACC__



# 201 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_230_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_230_parallel_region_1(hmpprt::u08* DownsampleDst_1, hmpprt::u08* UpsampleDst_2, hmpprt::s32 halfWidth_1);
#endif // __CUDACC__




# 201 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_202(hmpprt::s32 width_14, hmpprt::s32 halfWidth_10, hmpprt::s32 halfHeight_8, hmpprt::u08* DownsampleDst_10, hmpprt::u08* UpsampleDst_11)
;
#endif // __CUDACC__



# 201 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_202_internal_1(hmpprt::s32 width_23, hmpprt::s32 halfWidth_6, hmpprt::s32 halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_7)
;
#endif // __CUDACC__



# 175 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_202_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_202_parallel_region_1(hmpprt::u08* DownsampleDst_2, hmpprt::u08* UpsampleDst_3, hmpprt::s32 halfHeight_1, hmpprt::s32 halfWidth_2, hmpprt::s32 width_5);
#endif // __CUDACC__




# 175 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_188(hmpprt::s32 height_11, hmpprt::s32 width_15, hmpprt::s32 halfWidth_7, hmpprt::s32 halfHeight_2, hmpprt::u08* DownsampleDst_11, hmpprt::u08* UpsampleDst_4)
;
#endif // __CUDACC__



# 175 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_188_internal_1(hmpprt::s32 height_16, hmpprt::s32 width_24, hmpprt::s32 halfWidth_11, hmpprt::s32 halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_8)
;
#endif // __CUDACC__



# 154 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_188_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_188_parallel_region_1(hmpprt::u08* DownsampleDst_3, hmpprt::u08* UpsampleDst, hmpprt::s32 halfHeight_5, hmpprt::s32 halfWidth_3, hmpprt::s32 height_4, hmpprt::s32 width_6);
#endif // __CUDACC__




# 154 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_159(hmpprt::s32 width_16, hmpprt::s32 halfWidth_4, hmpprt::s32 halfHeight_3, hmpprt::u08* FilterDst_3, hmpprt::u08* DownsampleDst_4)
;
#endif // __CUDACC__



# 154 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_159_internal_1(hmpprt::s32 width_25, hmpprt::s32 halfWidth_8, hmpprt::s32 halfHeight_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_8)
;
#endif // __CUDACC__



# 132 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_159_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_159_parallel_region_1(hmpprt::u08* DownsampleDst, hmpprt::u08* FilterDst_1, hmpprt::s32 halfHeight, hmpprt::s32 halfWidth, hmpprt::s32 width_7);
#endif // __CUDACC__




# 132 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_136(hmpprt::s32 height_5, hmpprt::s32 width_8, hmpprt::u08* FilterDst_2, hmpprt::s32* pSrc_padding2_6)
;
#endif // __CUDACC__



# 132 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_136_internal_1(hmpprt::s32 height_18, hmpprt::s32 width_28, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_1)
;
#endif // __CUDACC__



# 114 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_136_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_136_parallel_region_1(hmpprt::u08* FilterDst, hmpprt::s32 height_12, hmpprt::s32* pSrc_padding2_4, hmpprt::s32 width_17);
#endif // __CUDACC__




# 114 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_114(hmpprt::s32 height_17, hmpprt::s32 width_18, hmpprt::s32* pSrc_padding2_7, hmpprt::u08* pBufL_cp_2)
;
#endif // __CUDACC__



# 114 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_114_internal_1(hmpprt::s32 height_13, hmpprt::s32 width_26, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_6)
;
#endif // __CUDACC__



# 97 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_114_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_114_parallel_region_1(hmpprt::s32 height_6, hmpprt::u08* pBufL_cp_5, hmpprt::s32* pSrc_padding2_5, hmpprt::s32 width_9);
#endif // __CUDACC__




# 97 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_100(hmpprt::s32 height_14, hmpprt::s32 width_10, hmpprt::s32* pSrc_padding2_3, hmpprt::u08* pBufL_cp_7)
;
#endif // __CUDACC__



# 97 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_100_internal_1(hmpprt::s32 height, hmpprt::s32 width_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_3)
;
#endif // __CUDACC__



# 97 "laplacian.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_100_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_100_parallel_region_1(hmpprt::s32 height_7, hmpprt::u08* pBufL_cp, hmpprt::s32* pSrc_padding2, hmpprt::s32 width);
#endif // __CUDACC__




# 97 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_100_parallel_region_1(hmpprt::s32 height_7, hmpprt::u08* pBufL_cp, hmpprt::s32* pSrc_padding2, hmpprt::s32 width)
{
 # 99 "laplacian.cpp"
 {
  # 103 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_10;
  # 103 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_10;
  # 103 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_10;
  # 103 "laplacian.cpp"
  iter_per_gang_10 = ((1 + (height_7 * width - 1) / 192) > 256 ? (1 + (height_7 * width - 1) / 192) : 256);
  # 103 "laplacian.cpp"
  first_gang_iter_10 = (hmpprt::gr_gbidx()) * iter_per_gang_10;
  # 103 "laplacian.cpp"
  last_gang_iter_10 = ((first_gang_iter_10 + iter_per_gang_10 - 1) < (height_7 * width - 1) ? (first_gang_iter_10 + iter_per_gang_10 - 1) : (height_7 * width - 1));
  # 103 "laplacian.cpp"
  hmpprt::s32 h_9;
  # 103 "laplacian.cpp"
  # 107 "laplacian.cpp"
  for (h_9 = first_gang_iter_10 + (hmpprt::gr_btidy()) ; h_9 <= last_gang_iter_10 ; h_9 = h_9 + (hmpprt::gr_btnumy()))
  {
   # 103 "laplacian.cpp"
   hmpprt::s32 h_4;
   # 106 "laplacian.cpp"
   hmpprt::s32 w_5;
   # 107 "laplacian.cpp"
   w_5 = h_9 % width;
   # 107 "laplacian.cpp"
   h_4 = h_9 / width;
   # 107 "laplacian.cpp"
   *(pSrc_padding2 + ((h_4 + 2) * (width + 4) + w_5 + 2)) = (hmpprt::s32 ) (*(pBufL_cp + (h_4 * width + w_5)));
  }
  # 97 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 97 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_100_internal_1(hmpprt::s32 height, hmpprt::s32 width_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_3)
{
 # 97 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height), "height_7");
  __hmppcg_call.addLocalParameter(&pBufL_cp_3, 8, "pBufL_cp");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_8, 8, "pSrc_padding2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_19), "width");
  __hmppcg_call.launch(hmpp_acc_region_main_100_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 97 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_100(hmpprt::s32 height_14, hmpprt::s32 width_10, hmpprt::s32* pSrc_padding2_3, hmpprt::u08* pBufL_cp_7)
{
 # 114 "laplacian.cpp"
 (hmpp_acc_region_main_100_internal_1(height_14, width_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp_7)));
}
#endif // __CUDACC__



# 114 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_114_parallel_region_1(hmpprt::s32 height_6, hmpprt::u08* pBufL_cp_5, hmpprt::s32* pSrc_padding2_5, hmpprt::s32 width_9)
{
 # 116 "laplacian.cpp"
 {
  # 117 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_9;
  # 117 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_9;
  # 117 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_9;
  # 117 "laplacian.cpp"
  iter_per_gang_9 = ((1 + (width_9 - 1) / 192) > 256 ? (1 + (width_9 - 1) / 192) : 256);
  # 117 "laplacian.cpp"
  first_gang_iter_9 = (hmpprt::gr_gbidx()) * iter_per_gang_9;
  # 117 "laplacian.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (width_9 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (width_9 - 1));
  # 117 "laplacian.cpp"
  hmpprt::s32 w_6;
  # 117 "laplacian.cpp"
  # 118 "laplacian.cpp"
  for (w_6 = first_gang_iter_9 + (hmpprt::gr_btidy()) ; w_6 <= last_gang_iter_9 ; w_6 = w_6 + (hmpprt::gr_btnumy()))
  {
   # 119 "laplacian.cpp"
   *(pSrc_padding2_5 + (width_9 + 4 + (w_6 + 2))) = 2 * (hmpprt::s32 ) (*(pBufL_cp_5 + (width_9 + (w_6 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_5 + (3 * width_9 + (w_6 + 2) - 2)));
   # 120 "laplacian.cpp"
   *(pSrc_padding2_5 + (w_6 + 2)) = 4 * (hmpprt::s32 ) (*(pBufL_cp_5 + (3 * width_9 + (w_6 + 2) - 2))) - 4 * (hmpprt::s32 ) (*(pBufL_cp_5 + (width_9 + (w_6 + 2) - 2))) + 2 * (hmpprt::s32 ) (*(pBufL_cp_5 + w_6)) - (hmpprt::s32 ) (*(pBufL_cp_5 + (2 * width_9 + (w_6 + 2) - 2)));
   # 123 "laplacian.cpp"
   *(pSrc_padding2_5 + ((height_6 + 2) * (width_9 + 4) + (w_6 + 2))) = 2 * (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 2) * width_9 + (w_6 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 4) * width_9 + (w_6 + 2) - 2)));
   # 124 "laplacian.cpp"
   *(pSrc_padding2_5 + ((height_6 + 3) * (width_9 + 4) + (w_6 + 2))) = 4 * (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 4) * width_9 + (w_6 + 2) - 2))) - 4 * (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 2) * width_9 + (w_6 + 2) - 2))) + 2 * (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 1) * width_9 + (w_6 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_5 + ((height_6 - 3) * width_9 + (w_6 + 2) - 2)));
  }
  # 114 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 114 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_114_internal_1(hmpprt::s32 height_13, hmpprt::s32 width_26, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_6)
{
 # 114 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_13), "height_6");
  __hmppcg_call.addLocalParameter(&pBufL_cp_6, 8, "pBufL_cp_5");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_2, 8, "pSrc_padding2_5");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_26), "width_9");
  __hmppcg_call.launch(hmpp_acc_region_main_114_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 114 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_114(hmpprt::s32 height_17, hmpprt::s32 width_18, hmpprt::s32* pSrc_padding2_7, hmpprt::u08* pBufL_cp_2)
{
 # 132 "laplacian.cpp"
 (hmpp_acc_region_main_114_internal_1(height_17, width_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp_2)));
}
#endif // __CUDACC__



# 132 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_136_parallel_region_1(hmpprt::u08* FilterDst, hmpprt::s32 height_12, hmpprt::s32* pSrc_padding2_4, hmpprt::s32 width_17)
{
 # 134 "laplacian.cpp"
 {
  # 139 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_8;
  # 139 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_8;
  # 139 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_8;
  # 139 "laplacian.cpp"
  iter_per_gang_8 = ((1 + (width_17 * height_12 - 1) / 192) > 256 ? (1 + (width_17 * height_12 - 1) / 192) : 256);
  # 139 "laplacian.cpp"
  first_gang_iter_8 = (hmpprt::gr_gbidx()) * iter_per_gang_8;
  # 139 "laplacian.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (width_17 * height_12 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (width_17 * height_12 - 1));
  # 139 "laplacian.cpp"
  hmpprt::s32 w_10;
  # 139 "laplacian.cpp"
  # 142 "laplacian.cpp"
  for (w_10 = first_gang_iter_8 + (hmpprt::gr_btidy()) ; w_10 <= last_gang_iter_8 ; w_10 = w_10 + (hmpprt::gr_btnumy()))
  {
   # 139 "laplacian.cpp"
   hmpprt::s32 w_7;
   # 141 "laplacian.cpp"
   hmpprt::s32 h_5;
   # 143 "laplacian.cpp"
   h_5 = w_10 % height_12;
   # 143 "laplacian.cpp"
   w_7 = w_10 / height_12;
   # 143 "laplacian.cpp"
   *(FilterDst + (h_5 * width_17 + w_7)) = (hmpprt::u08 ) (*(pSrc_padding2_4 + (h_5 * (width_17 + 4) + (w_7 + 2))) + (*(pSrc_padding2_4 + ((h_5 + 1) * (width_17 + 4) + (w_7 + 2))) << 2) + 6 * *(pSrc_padding2_4 + ((h_5 + 2) * (width_17 + 4) + (w_7 + 2))) + (*(pSrc_padding2_4 + ((h_5 + 3) * (width_17 + 4) + (w_7 + 2))) << 2) + *(pSrc_padding2_4 + ((h_5 + 4) * (width_17 + 4) + (w_7 + 2))) + 8 >> 4);
  }
  # 132 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 132 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_136_internal_1(hmpprt::s32 height_18, hmpprt::s32 width_28, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_1)
{
 # 132 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&FilterDst_4, 8, "FilterDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_12");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_1, 8, "pSrc_padding2_4");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_28), "width_17");
  __hmppcg_call.launch(hmpp_acc_region_main_136_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 132 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_136(hmpprt::s32 height_5, hmpprt::s32 width_8, hmpprt::u08* FilterDst_2, hmpprt::s32* pSrc_padding2_6)
{
 # 154 "laplacian.cpp"
 (hmpp_acc_region_main_136_internal_1(height_5, width_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (FilterDst_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_6)));
}
#endif // __CUDACC__



# 154 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_159_parallel_region_1(hmpprt::u08* DownsampleDst, hmpprt::u08* FilterDst_1, hmpprt::s32 halfHeight, hmpprt::s32 halfWidth, hmpprt::s32 width_7)
{
 # 156 "laplacian.cpp"
 {
  # 162 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_7;
  # 162 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_7;
  # 162 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_7;
  # 162 "laplacian.cpp"
  iter_per_gang_7 = ((1 + (halfHeight * halfWidth - 1) / 192) > 256 ? (1 + (halfHeight * halfWidth - 1) / 192) : 256);
  # 162 "laplacian.cpp"
  first_gang_iter_7 = (hmpprt::gr_gbidx()) * iter_per_gang_7;
  # 162 "laplacian.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (halfHeight * halfWidth - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (halfHeight * halfWidth - 1));
  # 162 "laplacian.cpp"
  hmpprt::s32 y_7;
  # 162 "laplacian.cpp"
  # 166 "laplacian.cpp"
  for (y_7 = first_gang_iter_7 + (hmpprt::gr_btidy()) ; y_7 <= last_gang_iter_7 ; y_7 = y_7 + (hmpprt::gr_btnumy()))
  {
   # 162 "laplacian.cpp"
   hmpprt::s32 y_3;
   # 165 "laplacian.cpp"
   hmpprt::s32 x_5;
   # 167 "laplacian.cpp"
   x_5 = y_7 % halfWidth;
   # 167 "laplacian.cpp"
   y_3 = y_7 / halfWidth;
   # 167 "laplacian.cpp"
   *(DownsampleDst + (y_3 * halfWidth + x_5)) = *(FilterDst_1 + ((y_3 << 1) * width_7 + (x_5 << 1)));
  }
  # 154 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 154 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_159_internal_1(hmpprt::s32 width_25, hmpprt::s32 halfWidth_8, hmpprt::s32 halfHeight_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_8)
{
 # 154 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_8, 8, "DownsampleDst");
  __hmppcg_call.addLocalParameter(&FilterDst_5, 8, "FilterDst_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_7), "halfHeight");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_8), "halfWidth");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_25), "width_7");
  __hmppcg_call.launch(hmpp_acc_region_main_159_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 154 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_159(hmpprt::s32 width_16, hmpprt::s32 halfWidth_4, hmpprt::s32 halfHeight_3, hmpprt::u08* FilterDst_3, hmpprt::u08* DownsampleDst_4)
{
 # 175 "laplacian.cpp"
 (hmpp_acc_region_main_159_internal_1(width_16, halfWidth_4, halfHeight_3, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (FilterDst_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_4)));
}
#endif // __CUDACC__



# 175 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_188_parallel_region_1(hmpprt::u08* DownsampleDst_3, hmpprt::u08* UpsampleDst, hmpprt::s32 halfHeight_5, hmpprt::s32 halfWidth_3, hmpprt::s32 height_4, hmpprt::s32 width_6)
{
 # 177 "laplacian.cpp"
 {
  # 191 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_6;
  # 191 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_6;
  # 191 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_6;
  # 191 "laplacian.cpp"
  iter_per_gang_6 = ((1 + (halfWidth_3 - 2) / 192) > 256 ? (1 + (halfWidth_3 - 2) / 192) : 256);
  # 191 "laplacian.cpp"
  first_gang_iter_6 = (hmpprt::gr_gbidx()) * iter_per_gang_6;
  # 191 "laplacian.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (halfWidth_3 - 2) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (halfWidth_3 - 2));
  # 191 "laplacian.cpp"
  hmpprt::s32 x_6;
  # 191 "laplacian.cpp"
  # 192 "laplacian.cpp"
  for (x_6 = first_gang_iter_6 + (hmpprt::gr_btidy()) ; x_6 <= last_gang_iter_6 ; x_6 = x_6 + (hmpprt::gr_btnumy()))
  {
   # 193 "laplacian.cpp"
   *(UpsampleDst + ((height_4 - 1) * width_6 + 2 * (x_6 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1)))) + 1 >> 1);
   # 194 "laplacian.cpp"
   *(UpsampleDst + ((height_4 - 1) * width_6 + 2 * (x_6 + 1))) = *(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1)));
  }
  # 175 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 175 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_188_internal_1(hmpprt::s32 height_16, hmpprt::s32 width_24, hmpprt::s32 halfWidth_11, hmpprt::s32 halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_8)
{
 # 175 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_7, 8, "DownsampleDst_3");
  __hmppcg_call.addLocalParameter(&UpsampleDst_8, 8, "UpsampleDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_6), "halfHeight_5");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_11), "halfWidth_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_16), "height_4");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_24), "width_6");
  __hmppcg_call.launch(hmpp_acc_region_main_188_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 175 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_188(hmpprt::s32 height_11, hmpprt::s32 width_15, hmpprt::s32 halfWidth_7, hmpprt::s32 halfHeight_2, hmpprt::u08* DownsampleDst_11, hmpprt::u08* UpsampleDst_4)
{
 # 201 "laplacian.cpp"
 (hmpp_acc_region_main_188_internal_1(height_11, width_15, halfWidth_7, halfHeight_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_11), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_4)));
}
#endif // __CUDACC__



# 201 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_202_parallel_region_1(hmpprt::u08* DownsampleDst_2, hmpprt::u08* UpsampleDst_3, hmpprt::s32 halfHeight_1, hmpprt::s32 halfWidth_2, hmpprt::s32 width_5)
{
 # 203 "laplacian.cpp"
 {
  # 205 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_5;
  # 205 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_5;
  # 205 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_5;
  # 205 "laplacian.cpp"
  iter_per_gang_5 = 1 +  - (1 - (halfHeight_1 - 1)) / 192;
  # 205 "laplacian.cpp"
  first_gang_iter_5 = (hmpprt::gr_gbidx()) * iter_per_gang_5;
  # 205 "laplacian.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < ( - (1 - (halfHeight_1 - 1))) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : ( - (1 - (halfHeight_1 - 1))));
  # 205 "laplacian.cpp"
  hmpprt::s32 y_4;
  # 205 "laplacian.cpp"
  # 206 "laplacian.cpp"
  for (y_4 = first_gang_iter_5 ; y_4 <= last_gang_iter_5 ; y_4 = y_4 + 1)
  {
   # 209 "laplacian.cpp"
   hmpprt::u08 tmp_18;
   # 209 "laplacian.cpp"
   hmpprt::u08 tmp_19;
   # 209 "laplacian.cpp"
   hmpprt::u08 tmp_20;
   # 209 "laplacian.cpp"
   hmpprt::u08 tmp_21;
   # 209 "laplacian.cpp"
   hmpprt::s32 end_6;
   # 209 "laplacian.cpp"
   hmpprt::s32 x_7;
   # 209 "laplacian.cpp"
   # 210 "laplacian.cpp"
   # 210 "laplacian.cpp"
   for (x_7 = (hmpprt::gr_btidy()), end_6 = halfWidth_2 - 2 ; x_7 <= end_6 ; x_7 = x_7 + (hmpprt::gr_btnumy()))
   {
    # 211 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_7 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1)))) + 2 >> 2);
    # 212 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_7 + 1))) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1)))) + 1 >> 1);
    # 214 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_7 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + 1 >> 1);
    # 215 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_7 + 1))) = *(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)));
   }
   # 201 "laplacian.cpp"
   # 201 "laplacian.cpp"
   tmp_18 = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + halfWidth_2 - 1))) + (hmpprt::s32 ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + halfWidth_2 - 1))) + 1 >> 1);
   # 201 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + width_5 - 1)) = tmp_18;
   }
   # 201 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 201 "laplacian.cpp"
   tmp_19 = *(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + halfWidth_2 - 1));
   # 201 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + width_5 - 1)) = tmp_19;
   }
   # 201 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 201 "laplacian.cpp"
   tmp_20 = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_2 + (halfHeight_1 - 1 - y_4) * halfWidth_2)) + (hmpprt::s32 ) (*(DownsampleDst_2 + (halfHeight_1 - 1 - y_4 - 1) * halfWidth_2)) + 1 >> 1);
   # 201 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) - 1) * width_5) = tmp_20;
   }
   # 201 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 201 "laplacian.cpp"
   tmp_21 = *(DownsampleDst_2 + (halfHeight_1 - 1 - y_4) * halfWidth_2);
   # 201 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + 2 * (halfHeight_1 - 1 - y_4) * width_5) = tmp_21;
   }
   # 201 "laplacian.cpp"
   (hmpprt::gr_barrier());
  }
  # 201 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 201 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_202_internal_1(hmpprt::s32 width_23, hmpprt::s32 halfWidth_6, hmpprt::s32 halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_7)
{
 # 201 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_6, 8, "DownsampleDst_2");
  __hmppcg_call.addLocalParameter(&UpsampleDst_7, 8, "UpsampleDst_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_4), "halfHeight_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_6), "halfWidth_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_23), "width_5");
  __hmppcg_call.launch(hmpp_acc_region_main_202_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 201 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_202(hmpprt::s32 width_14, hmpprt::s32 halfWidth_10, hmpprt::s32 halfHeight_8, hmpprt::u08* DownsampleDst_10, hmpprt::u08* UpsampleDst_11)
{
 # 229 "laplacian.cpp"
 (hmpp_acc_region_main_202_internal_1(width_14, halfWidth_10, halfHeight_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_10), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_11)));
}
#endif // __CUDACC__



# 229 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_230_parallel_region_1(hmpprt::u08* DownsampleDst_1, hmpprt::u08* UpsampleDst_2, hmpprt::s32 halfWidth_1)
{
 # 231 "laplacian.cpp"
 {
  # 233 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_4;
  # 233 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_4;
  # 233 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_4;
  # 233 "laplacian.cpp"
  iter_per_gang_4 = ((1 +  - (1 - (halfWidth_1 - 1)) / 192) > 256 ? (1 +  - (1 - (halfWidth_1 - 1)) / 192) : 256);
  # 233 "laplacian.cpp"
  first_gang_iter_4 = (hmpprt::gr_gbidx()) * iter_per_gang_4;
  # 233 "laplacian.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < ( - (1 - (halfWidth_1 - 1))) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : ( - (1 - (halfWidth_1 - 1))));
  # 233 "laplacian.cpp"
  hmpprt::s32 x_8;
  # 233 "laplacian.cpp"
  # 234 "laplacian.cpp"
  for (x_8 = first_gang_iter_4 + (hmpprt::gr_btidy()) ; x_8 <= last_gang_iter_4 ; x_8 = x_8 + (hmpprt::gr_btnumy()))
  {
   # 235 "laplacian.cpp"
   *(UpsampleDst_2 + 2 * (halfWidth_1 - 1 - x_8)) = *(DownsampleDst_1 + (halfWidth_1 - 1 - x_8));
   # 236 "laplacian.cpp"
   *(UpsampleDst_2 + (2 * (halfWidth_1 - 1 - x_8) - 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(DownsampleDst_1 + (halfWidth_1 - 1 - x_8 - 1))) + (hmpprt::s32 ) (*(DownsampleDst_1 + (halfWidth_1 - 1 - x_8))) + 1) / 2);
  }
  # 229 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 229 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_230_internal_1(hmpprt::s32 width_27, hmpprt::s32 halfWidth_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_9, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_10)
{
 # 229 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_9, 8, "DownsampleDst_1");
  __hmppcg_call.addLocalParameter(&UpsampleDst_10, 8, "UpsampleDst_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_9), "halfWidth_1");
  __hmppcg_call.launch(hmpp_acc_region_main_230_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 229 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_230(hmpprt::s32 width_4, hmpprt::s32 halfWidth_5, hmpprt::u08* DownsampleDst_5, hmpprt::u08* UpsampleDst_6)
{
 # 243 "laplacian.cpp"
 (hmpp_acc_region_main_230_internal_1(width_4, halfWidth_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_5), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_6)));
}
#endif // __CUDACC__



# 243 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_247_parallel_region_1(hmpprt::s16* LaplacianLayer, hmpprt::u08* Source, hmpprt::u08* UpsampleDst_1, hmpprt::s32 height_3, hmpprt::s32 width_3)
{
 # 245 "laplacian.cpp"
 {
  # 250 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 250 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 250 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 250 "laplacian.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 250 "laplacian.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 250 "laplacian.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 250 "laplacian.cpp"
  hmpprt::s32 y_6;
  # 250 "laplacian.cpp"
  # 254 "laplacian.cpp"
  for (y_6 = first_gang_iter_3 + (hmpprt::gr_btidy()) ; y_6 <= last_gang_iter_3 ; y_6 = y_6 + (hmpprt::gr_btnumy()))
  {
   # 250 "laplacian.cpp"
   hmpprt::s32 y_5;
   # 253 "laplacian.cpp"
   hmpprt::s32 x_9;
   # 255 "laplacian.cpp"
   x_9 = y_6 % width_3;
   # 255 "laplacian.cpp"
   y_5 = y_6 / width_3;
   # 255 "laplacian.cpp"
   *(LaplacianLayer + (y_5 * width_3 + x_9)) = (hmpprt::s16 ) ((hmpprt::s32 ) ((hmpprt::s16 ) (*(Source + (y_5 * width_3 + x_9)))) - (hmpprt::s32 ) ((hmpprt::s16 ) (*(UpsampleDst_1 + (y_5 * width_3 + x_9)))));
  }
  # 243 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 243 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_247_internal_1(hmpprt::s32 height_15, hmpprt::s32 width_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_9)
{
 # 243 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&LaplacianLayer_2, 8, "LaplacianLayer");
  __hmppcg_call.addLocalParameter(&Source_4, 8, "Source");
  __hmppcg_call.addLocalParameter(&UpsampleDst_9, 8, "UpsampleDst_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_15), "height_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_22), "width_3");
  __hmppcg_call.launch(hmpp_acc_region_main_247_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 243 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_247(hmpprt::s32 height_10, hmpprt::s32 width_13, hmpprt::u08* Source_2, hmpprt::s16* LaplacianLayer_1, hmpprt::u08* UpsampleDst_5)
{
 # 12 "laplacian.cpp"
 (hmpp_acc_region_main_247_internal_1(height_10, width_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (Source_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (LaplacianLayer_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_5)));
}
#endif // __CUDACC__



# 12 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_55_parallel_region_1(hmpprt::u08* Source_1, hmpprt::s32 height_2, hmpprt::s32* pSrc_padding, hmpprt::s32 width_2)
{
 # 14 "laplacian.cpp"
 {
  # 58 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_2;
  # 58 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 58 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 58 "laplacian.cpp"
  iter_per_gang_2 = 1 + (height_2 - 1) / 192;
  # 58 "laplacian.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * iter_per_gang_2;
  # 58 "laplacian.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 - 1));
  # 58 "laplacian.cpp"
  hmpprt::s32 h_6;
  # 58 "laplacian.cpp"
  # 59 "laplacian.cpp"
  for (h_6 = first_gang_iter_2 ; h_6 <= last_gang_iter_2 ; h_6 = h_6 + 1)
  {
   # 67 "laplacian.cpp"
   hmpprt::s32 tmp_22;
   # 67 "laplacian.cpp"
   hmpprt::s32 tmp_23;
   # 67 "laplacian.cpp"
   hmpprt::s32 tmp_24;
   # 67 "laplacian.cpp"
   hmpprt::s32 tmp_25;
   # 67 "laplacian.cpp"
   tmp_22 = 2 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + 1))) - (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + 3)));
   # 67 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + 1)) = tmp_22;
   }
   # 67 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian.cpp"
   tmp_23 = 4 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + 3))) - 4 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + 1))) + 2 * (hmpprt::s32 ) (*(Source_1 + h_6 * width_2)) - (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + 2)));
   # 67 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + (h_6 + 2) * (width_2 + 4)) = tmp_23;
   }
   # 67 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian.cpp"
   tmp_24 = 2 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 2))) - (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 4)));
   # 67 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + width_2 + 2)) = tmp_24;
   }
   # 67 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian.cpp"
   tmp_25 = 4 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 4))) - 4 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 2))) + 2 * (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 1))) - (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + width_2 - 3)));
   # 67 "laplacian.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + width_2 + 3)) = tmp_25;
   }
   # 67 "laplacian.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian.cpp"
   hmpprt::s32 end_10;
   # 67 "laplacian.cpp"
   hmpprt::s32 w_8;
   # 67 "laplacian.cpp"
   # 68 "laplacian.cpp"
   # 68 "laplacian.cpp"
   for (w_8 = (hmpprt::gr_btidy()), end_10 = width_2 - 1 ; w_8 <= end_10 ; w_8 = w_8 + (hmpprt::gr_btnumy()))
   {
    # 68 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + w_8 + 2)) = (hmpprt::s32 ) (*(Source_1 + (h_6 * width_2 + w_8)));
   }
   # 12 "laplacian.cpp"
  }
  # 12 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 12 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_55_internal_1(hmpprt::s32 height_20, hmpprt::s32 width_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_4)
{
 # 12 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&Source_5, 8, "Source_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_20), "height_2");
  __hmppcg_call.addLocalParameter(&pSrc_padding_4, 8, "pSrc_padding");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_21), "width_2");
  __hmppcg_call.launch(hmpp_acc_region_main_55_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 12 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_55(hmpprt::s32 height_9, hmpprt::s32 width_12, hmpprt::u08* Source_3, hmpprt::s32* pSrc_padding_2)
{
 # 75 "laplacian.cpp"
 (hmpp_acc_region_main_55_internal_1(height_9, width_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (Source_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding_2)));
}
#endif // __CUDACC__



# 75 "laplacian.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_79_parallel_region_1(hmpprt::s32 height_1, hmpprt::u08* pBufL_cp_1, hmpprt::s32* pSrc_padding_1, hmpprt::s32 width_1)
{
 # 77 "laplacian.cpp"
 {
  # 82 "laplacian.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 82 "laplacian.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 82 "laplacian.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 82 "laplacian.cpp"
  iter_per_gang_1 = ((1 + (height_1 * width_1 - 1) / 192) > 256 ? (1 + (height_1 * width_1 - 1) / 192) : 256);
  # 82 "laplacian.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 82 "laplacian.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < (height_1 * width_1 - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : (height_1 * width_1 - 1));
  # 82 "laplacian.cpp"
  hmpprt::s32 h_8;
  # 82 "laplacian.cpp"
  # 85 "laplacian.cpp"
  for (h_8 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; h_8 <= last_gang_iter_1 ; h_8 = h_8 + (hmpprt::gr_btnumy()))
  {
   # 82 "laplacian.cpp"
   hmpprt::s32 h_7;
   # 84 "laplacian.cpp"
   hmpprt::s32 w_9;
   # 86 "laplacian.cpp"
   w_9 = h_8 % width_1;
   # 86 "laplacian.cpp"
   h_7 = h_8 / width_1;
   # 86 "laplacian.cpp"
   *(pBufL_cp_1 + (h_7 * width_1 + w_9)) = (hmpprt::u08 ) (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + w_9)) + (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + w_9 + 1)) << 2) + 6 * *(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 2))) + (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 3))) << 2) + *(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 4))) + 8 >> 4);
  }
  # 75 "laplacian.cpp"
 }
}
#endif // __CUDACC__



# 75 "laplacian.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_79_internal_1(hmpprt::s32 height_19, hmpprt::s32 width_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_8)
{
 # 75 "laplacian.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_1");
  __hmppcg_call.addLocalParameter(&pBufL_cp_8, 8, "pBufL_cp_1");
  __hmppcg_call.addLocalParameter(&pSrc_padding_5, 8, "pSrc_padding_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_1");
  __hmppcg_call.launch(hmpp_acc_region_main_79_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 75 "laplacian.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_79(hmpprt::s32 height_8, hmpprt::s32 width_11, hmpprt::s32* pSrc_padding_3, hmpprt::u08* pBufL_cp_4)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_79_internal_1(height_8, width_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp_4)));
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
      hmpp_acc_region_main_100_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_100_parallel_region_1");
      hmpp_acc_region_main_114_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_114_parallel_region_1");
      hmpp_acc_region_main_136_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_136_parallel_region_1");
      hmpp_acc_region_main_159_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_159_parallel_region_1");
      hmpp_acc_region_main_188_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_188_parallel_region_1");
      hmpp_acc_region_main_202_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_202_parallel_region_1");
      hmpp_acc_region_main_230_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_230_parallel_region_1");
      hmpp_acc_region_main_247_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_247_parallel_region_1");
      hmpp_acc_region_main_55_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_55_parallel_region_1");
      hmpp_acc_region_main_79_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_79_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_100", "prototype hmpp_acc_region_main_100(height: s32, width: s32, pSrc_padding2: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_114", "prototype hmpp_acc_region_main_114(height: s32, width: s32, pSrc_padding2: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_136", "prototype hmpp_acc_region_main_136(height: s32, width: s32, FilterDst: ^cudaglob u8, pSrc_padding2: ^cudaglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_159", "prototype hmpp_acc_region_main_159(width: s32, halfWidth: s32, halfHeight: s32, FilterDst: ^cudaglob u8, DownsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_188", "prototype hmpp_acc_region_main_188(height: s32, width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_202", "prototype hmpp_acc_region_main_202(width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_230", "prototype hmpp_acc_region_main_230(width: s32, halfWidth: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_247", "prototype hmpp_acc_region_main_247(height: s32, width: s32, Source: ^cudaglob u8, LaplacianLayer: ^cudaglob s16, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_55", "prototype hmpp_acc_region_main_55(height: s32, width: s32, Source: ^cudaglob u8, pSrc_padding: ^cudaglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_79", "prototype hmpp_acc_region_main_79(height: s32, width: s32, pSrc_padding: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");

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
      delete hmpp_acc_region_main_100_parallel_region_1;
      delete hmpp_acc_region_main_114_parallel_region_1;
      delete hmpp_acc_region_main_136_parallel_region_1;
      delete hmpp_acc_region_main_159_parallel_region_1;
      delete hmpp_acc_region_main_188_parallel_region_1;
      delete hmpp_acc_region_main_202_parallel_region_1;
      delete hmpp_acc_region_main_230_parallel_region_1;
      delete hmpp_acc_region_main_247_parallel_region_1;
      delete hmpp_acc_region_main_55_parallel_region_1;
      delete hmpp_acc_region_main_79_parallel_region_1;

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
