
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

# 98 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_94(hmpprt::s32 height_8, hmpprt::s32 width_11, hmpprt::s32* pSrc_padding2_4, hmpprt::u08* pBufL_cp_4)
;
#endif // __CUDACC__



# 98 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_94_internal_1(hmpprt::s32 height_19, hmpprt::s32 width_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_7)
;
#endif // __CUDACC__



# 75 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_94_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_94_parallel_region_1(hmpprt::s32 height_1, hmpprt::u08* pBufL_cp_1, hmpprt::s32* pSrc_padding2_1, hmpprt::s32 width_1);
#endif // __CUDACC__




# 75 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_80(hmpprt::s32 height_9, hmpprt::s32 width_12, hmpprt::s32* pSrc_padding_3, hmpprt::u08* pBufL_cp_5)
;
#endif // __CUDACC__



# 75 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_80_internal_1(hmpprt::s32 height_20, hmpprt::s32 width_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_8)
;
#endif // __CUDACC__



# 12 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_80_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_80_parallel_region_1(hmpprt::s32 height_2, hmpprt::u08* pBufL_cp_2, hmpprt::s32* pSrc_padding_1, hmpprt::s32 width_2);
#endif // __CUDACC__




# 12 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_55(hmpprt::s32 height_10, hmpprt::s32 width_13, hmpprt::u08* Source_3, hmpprt::s32* pSrc_padding_2)
;
#endif // __CUDACC__



# 12 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_55_internal_1(hmpprt::s32 height_15, hmpprt::s32 width_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_4)
;
#endif // __CUDACC__



# 233 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_55_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_55_parallel_region_1(hmpprt::u08* Source_1, hmpprt::s32 height_3, hmpprt::s32* pSrc_padding, hmpprt::s32 width_3);
#endif // __CUDACC__




# 233 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_239(hmpprt::s32 height_11, hmpprt::s32 width_14, hmpprt::u08* Source_2, hmpprt::s16* LaplacianLayer_1, hmpprt::u08* UpsampleDst_5)
;
#endif // __CUDACC__



# 233 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_239_internal_1(hmpprt::s32 height_16, hmpprt::s32 width_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_9)
;
#endif // __CUDACC__



# 211 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_239_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_239_parallel_region_1(hmpprt::s16* LaplacianLayer, hmpprt::u08* Source, hmpprt::u08* UpsampleDst_1, hmpprt::s32 height_4, hmpprt::s32 width_4);
#endif // __CUDACC__




# 211 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_206(hmpprt::s32 width_15, hmpprt::s32 halfWidth_5, hmpprt::s32 halfHeight_7, hmpprt::u08* DownsampleDst_9, hmpprt::u08* UpsampleDst_6)
;
#endif // __CUDACC__



# 211 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_206_internal_1(hmpprt::s32 width_24, hmpprt::s32 halfWidth_9, hmpprt::s32 halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_10)
;
#endif // __CUDACC__



# 196 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_206_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_206_parallel_region_1(hmpprt::u08* DownsampleDst_1, hmpprt::u08* UpsampleDst_2, hmpprt::s32 halfHeight_1, hmpprt::s32 halfWidth_1, hmpprt::s32 width_5);
#endif // __CUDACC__




# 196 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_192(hmpprt::s32 width_6, hmpprt::s32 halfWidth_6, hmpprt::u08* DownsampleDst_10, hmpprt::u08* UpsampleDst_11)
;
#endif // __CUDACC__



# 196 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_192_internal_1(hmpprt::s32 width_28, hmpprt::s32 halfWidth_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_7)
;
#endif // __CUDACC__



# 169 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_192_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_192_parallel_region_1(hmpprt::u08* DownsampleDst_2, hmpprt::u08* UpsampleDst_3, hmpprt::s32 halfWidth_2);
#endif // __CUDACC__




# 169 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_183(hmpprt::s32 height_12, hmpprt::s32 width_16, hmpprt::s32 halfWidth_11, hmpprt::s32 halfHeight_5, hmpprt::u08* DownsampleDst_7, hmpprt::u08* UpsampleDst_4)
;
#endif // __CUDACC__



# 169 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_183_internal_1(hmpprt::s32 height_17, hmpprt::s32 width_25, hmpprt::s32 halfWidth_7, hmpprt::s32 halfHeight_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_8)
;
#endif // __CUDACC__



# 148 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_183_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_183_parallel_region_1(hmpprt::u08* DownsampleDst_3, hmpprt::u08* UpsampleDst, hmpprt::s32 halfHeight_2, hmpprt::s32 halfWidth_3, hmpprt::s32 height_5, hmpprt::s32 width_7);
#endif // __CUDACC__




# 148 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_153(hmpprt::s32 width_17, hmpprt::s32 halfWidth_4, hmpprt::s32 halfHeight_3, hmpprt::u08* FilterDst_1, hmpprt::u08* DownsampleDst_4)
;
#endif // __CUDACC__



# 148 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_153_internal_1(hmpprt::s32 width_26, hmpprt::s32 halfWidth_8, hmpprt::s32 halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_8)
;
#endif // __CUDACC__



# 126 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_153_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_153_parallel_region_1(hmpprt::u08* DownsampleDst, hmpprt::u08* FilterDst_3, hmpprt::s32 halfHeight, hmpprt::s32 halfWidth, hmpprt::s32 width_8);
#endif // __CUDACC__




# 126 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_130(hmpprt::s32 height_6, hmpprt::s32 width_18, hmpprt::u08* FilterDst_2, hmpprt::s32* pSrc_padding2_8)
;
#endif // __CUDACC__



# 126 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_130_internal_1(hmpprt::s32 height_18, hmpprt::s32 width_27, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_5)
;
#endif // __CUDACC__



# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_130_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_130_parallel_region_1(hmpprt::u08* FilterDst, hmpprt::s32 height_13, hmpprt::s32* pSrc_padding2_2, hmpprt::s32 width_9);
#endif // __CUDACC__




# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_108(hmpprt::s32 height_14, hmpprt::s32 width_10, hmpprt::s32* pSrc_padding2_3, hmpprt::u08* pBufL_cp)
;
#endif // __CUDACC__



# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_108_internal_1(hmpprt::s32 height, hmpprt::s32 width_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_6)
;
#endif // __CUDACC__



# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_108_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_108_parallel_region_1(hmpprt::s32 height_7, hmpprt::u08* pBufL_cp_3, hmpprt::s32* pSrc_padding2, hmpprt::s32 width);
#endif // __CUDACC__




# 114 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_108_parallel_region_1(hmpprt::s32 height_7, hmpprt::u08* pBufL_cp_3, hmpprt::s32* pSrc_padding2, hmpprt::s32 width)
{
 # 116 "laplacian_fuse.cpp"
 {
  # 111 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_10;
  # 111 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_10;
  # 111 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_10;
  # 111 "laplacian_fuse.cpp"
  iter_per_gang_10 = ((1 + (width - 1) / 192) > 256 ? (1 + (width - 1) / 192) : 256);
  # 111 "laplacian_fuse.cpp"
  first_gang_iter_10 = (hmpprt::gr_gbidx()) * iter_per_gang_10;
  # 111 "laplacian_fuse.cpp"
  last_gang_iter_10 = ((first_gang_iter_10 + iter_per_gang_10 - 1) < (width - 1) ? (first_gang_iter_10 + iter_per_gang_10 - 1) : (width - 1));
  # 111 "laplacian_fuse.cpp"
  hmpprt::s32 w_5;
  # 111 "laplacian_fuse.cpp"
  # 112 "laplacian_fuse.cpp"
  for (w_5 = first_gang_iter_10 + (hmpprt::gr_btidy()) ; w_5 <= last_gang_iter_10 ; w_5 = w_5 + (hmpprt::gr_btnumy()))
  {
   # 113 "laplacian_fuse.cpp"
   *(pSrc_padding2 + (width + 4 + (w_5 + 2))) = 2 * (hmpprt::s32 ) (*(pBufL_cp_3 + (width + (w_5 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_3 + (3 * width + (w_5 + 2) - 2)));
   # 114 "laplacian_fuse.cpp"
   *(pSrc_padding2 + (w_5 + 2)) = 4 * (hmpprt::s32 ) (*(pBufL_cp_3 + (3 * width + (w_5 + 2) - 2))) - 4 * (hmpprt::s32 ) (*(pBufL_cp_3 + (width + (w_5 + 2) - 2))) + 2 * (hmpprt::s32 ) (*(pBufL_cp_3 + w_5)) - (hmpprt::s32 ) (*(pBufL_cp_3 + (2 * width + (w_5 + 2) - 2)));
   # 117 "laplacian_fuse.cpp"
   *(pSrc_padding2 + ((height_7 + 2) * (width + 4) + (w_5 + 2))) = 2 * (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 2) * width + (w_5 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 4) * width + (w_5 + 2) - 2)));
   # 118 "laplacian_fuse.cpp"
   *(pSrc_padding2 + ((height_7 + 3) * (width + 4) + (w_5 + 2))) = 4 * (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 4) * width + (w_5 + 2) - 2))) - 4 * (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 2) * width + (w_5 + 2) - 2))) + 2 * (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 1) * width + (w_5 + 2) - 2))) - (hmpprt::s32 ) (*(pBufL_cp_3 + ((height_7 - 3) * width + (w_5 + 2) - 2)));
  }
  # 114 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_108_internal_1(hmpprt::s32 height, hmpprt::s32 width_19, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_6)
{
 # 114 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height), "height_7");
  __hmppcg_call.addLocalParameter(&pBufL_cp_6, 8, "pBufL_cp_3");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_6, 8, "pSrc_padding2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_19), "width");
  __hmppcg_call.launch(hmpp_acc_region_main_108_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 114 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_108(hmpprt::s32 height_14, hmpprt::s32 width_10, hmpprt::s32* pSrc_padding2_3, hmpprt::u08* pBufL_cp)
{
 # 126 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_108_internal_1(height_14, width_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp)));
}
#endif // __CUDACC__



# 126 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_130_parallel_region_1(hmpprt::u08* FilterDst, hmpprt::s32 height_13, hmpprt::s32* pSrc_padding2_2, hmpprt::s32 width_9)
{
 # 128 "laplacian_fuse.cpp"
 {
  # 133 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_9;
  # 133 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_9;
  # 133 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_9;
  # 133 "laplacian_fuse.cpp"
  iter_per_gang_9 = ((1 + (width_9 * height_13 - 1) / 192) > 256 ? (1 + (width_9 * height_13 - 1) / 192) : 256);
  # 133 "laplacian_fuse.cpp"
  first_gang_iter_9 = (hmpprt::gr_gbidx()) * iter_per_gang_9;
  # 133 "laplacian_fuse.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (width_9 * height_13 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (width_9 * height_13 - 1));
  # 133 "laplacian_fuse.cpp"
  hmpprt::s32 w_10;
  # 133 "laplacian_fuse.cpp"
  # 136 "laplacian_fuse.cpp"
  for (w_10 = first_gang_iter_9 + (hmpprt::gr_btidy()) ; w_10 <= last_gang_iter_9 ; w_10 = w_10 + (hmpprt::gr_btnumy()))
  {
   # 133 "laplacian_fuse.cpp"
   hmpprt::s32 w_6;
   # 135 "laplacian_fuse.cpp"
   hmpprt::s32 h_4;
   # 137 "laplacian_fuse.cpp"
   h_4 = w_10 % height_13;
   # 137 "laplacian_fuse.cpp"
   w_6 = w_10 / height_13;
   # 137 "laplacian_fuse.cpp"
   *(FilterDst + (h_4 * width_9 + w_6)) = (hmpprt::u08 ) (*(pSrc_padding2_2 + (h_4 * (width_9 + 4) + (w_6 + 2))) + (*(pSrc_padding2_2 + ((h_4 + 1) * (width_9 + 4) + (w_6 + 2))) << 2) + 6 * *(pSrc_padding2_2 + ((h_4 + 2) * (width_9 + 4) + (w_6 + 2))) + (*(pSrc_padding2_2 + ((h_4 + 3) * (width_9 + 4) + (w_6 + 2))) << 2) + *(pSrc_padding2_2 + ((h_4 + 4) * (width_9 + 4) + (w_6 + 2))) + 8 >> 4);
  }
  # 126 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 126 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_130_internal_1(hmpprt::s32 height_18, hmpprt::s32 width_27, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_5)
{
 # 126 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&FilterDst_5, 8, "FilterDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_13");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_5, 8, "pSrc_padding2_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_27), "width_9");
  __hmppcg_call.launch(hmpp_acc_region_main_130_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 126 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_130(hmpprt::s32 height_6, hmpprt::s32 width_18, hmpprt::u08* FilterDst_2, hmpprt::s32* pSrc_padding2_8)
{
 # 148 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_130_internal_1(height_6, width_18, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (FilterDst_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_8)));
}
#endif // __CUDACC__



# 148 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_153_parallel_region_1(hmpprt::u08* DownsampleDst, hmpprt::u08* FilterDst_3, hmpprt::s32 halfHeight, hmpprt::s32 halfWidth, hmpprt::s32 width_8)
{
 # 150 "laplacian_fuse.cpp"
 {
  # 156 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_8;
  # 156 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_8;
  # 156 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_8;
  # 156 "laplacian_fuse.cpp"
  iter_per_gang_8 = ((1 + (halfHeight * halfWidth - 1) / 192) > 256 ? (1 + (halfHeight * halfWidth - 1) / 192) : 256);
  # 156 "laplacian_fuse.cpp"
  first_gang_iter_8 = (hmpprt::gr_gbidx()) * iter_per_gang_8;
  # 156 "laplacian_fuse.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (halfHeight * halfWidth - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (halfHeight * halfWidth - 1));
  # 156 "laplacian_fuse.cpp"
  hmpprt::s32 y_6;
  # 156 "laplacian_fuse.cpp"
  # 160 "laplacian_fuse.cpp"
  for (y_6 = first_gang_iter_8 + (hmpprt::gr_btidy()) ; y_6 <= last_gang_iter_8 ; y_6 = y_6 + (hmpprt::gr_btnumy()))
  {
   # 156 "laplacian_fuse.cpp"
   hmpprt::s32 y_3;
   # 159 "laplacian_fuse.cpp"
   hmpprt::s32 x_5;
   # 161 "laplacian_fuse.cpp"
   x_5 = y_6 % halfWidth;
   # 161 "laplacian_fuse.cpp"
   y_3 = y_6 / halfWidth;
   # 161 "laplacian_fuse.cpp"
   *(DownsampleDst + (y_3 * halfWidth + x_5)) = *(FilterDst_3 + ((y_3 << 1) * width_8 + (x_5 << 1)));
  }
  # 148 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 148 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_153_internal_1(hmpprt::s32 width_26, hmpprt::s32 halfWidth_8, hmpprt::s32 halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_8)
{
 # 148 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_8, 8, "DownsampleDst");
  __hmppcg_call.addLocalParameter(&FilterDst_4, 8, "FilterDst_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_6), "halfHeight");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_8), "halfWidth");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_26), "width_8");
  __hmppcg_call.launch(hmpp_acc_region_main_153_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 148 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_153(hmpprt::s32 width_17, hmpprt::s32 halfWidth_4, hmpprt::s32 halfHeight_3, hmpprt::u08* FilterDst_1, hmpprt::u08* DownsampleDst_4)
{
 # 169 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_153_internal_1(width_17, halfWidth_4, halfHeight_3, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (FilterDst_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_4)));
}
#endif // __CUDACC__



# 169 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_183_parallel_region_1(hmpprt::u08* DownsampleDst_3, hmpprt::u08* UpsampleDst, hmpprt::s32 halfHeight_2, hmpprt::s32 halfWidth_3, hmpprt::s32 height_5, hmpprt::s32 width_7)
{
 # 171 "laplacian_fuse.cpp"
 {
  # 186 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_7;
  # 186 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_7;
  # 186 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_7;
  # 186 "laplacian_fuse.cpp"
  iter_per_gang_7 = ((1 + (halfWidth_3 - 2) / 192) > 256 ? (1 + (halfWidth_3 - 2) / 192) : 256);
  # 186 "laplacian_fuse.cpp"
  first_gang_iter_7 = (hmpprt::gr_gbidx()) * iter_per_gang_7;
  # 186 "laplacian_fuse.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (halfWidth_3 - 2) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (halfWidth_3 - 2));
  # 186 "laplacian_fuse.cpp"
  hmpprt::s32 x_6;
  # 186 "laplacian_fuse.cpp"
  # 187 "laplacian_fuse.cpp"
  for (x_6 = first_gang_iter_7 + (hmpprt::gr_btidy()) ; x_6 <= last_gang_iter_7 ; x_6 = x_6 + (hmpprt::gr_btnumy()))
  {
   # 188 "laplacian_fuse.cpp"
   *(UpsampleDst + ((height_5 - 1) * width_7 + 2 * (x_6 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_3 + ((halfHeight_2 - 1) * halfWidth_3 + (x_6 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_3 + ((halfHeight_2 - 1) * halfWidth_3 + (x_6 + 1)))) + 1 >> 1);
   # 189 "laplacian_fuse.cpp"
   *(UpsampleDst + ((height_5 - 1) * width_7 + 2 * (x_6 + 1))) = *(DownsampleDst_3 + ((halfHeight_2 - 1) * halfWidth_3 + (x_6 + 1)));
  }
  # 169 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 169 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_183_internal_1(hmpprt::s32 height_17, hmpprt::s32 width_25, hmpprt::s32 halfWidth_7, hmpprt::s32 halfHeight_8, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_8)
{
 # 169 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_11, 8, "DownsampleDst_3");
  __hmppcg_call.addLocalParameter(&UpsampleDst_8, 8, "UpsampleDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_8), "halfHeight_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_7), "halfWidth_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_17), "height_5");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_25), "width_7");
  __hmppcg_call.launch(hmpp_acc_region_main_183_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 169 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_183(hmpprt::s32 height_12, hmpprt::s32 width_16, hmpprt::s32 halfWidth_11, hmpprt::s32 halfHeight_5, hmpprt::u08* DownsampleDst_7, hmpprt::u08* UpsampleDst_4)
{
 # 196 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_183_internal_1(height_12, width_16, halfWidth_11, halfHeight_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_7), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_4)));
}
#endif // __CUDACC__



# 196 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_192_parallel_region_1(hmpprt::u08* DownsampleDst_2, hmpprt::u08* UpsampleDst_3, hmpprt::s32 halfWidth_2)
{
 # 198 "laplacian_fuse.cpp"
 {
  # 201 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_6;
  # 201 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_6;
  # 201 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_6;
  # 201 "laplacian_fuse.cpp"
  iter_per_gang_6 = ((1 +  - (1 - (halfWidth_2 - 1)) / 192) > 256 ? (1 +  - (1 - (halfWidth_2 - 1)) / 192) : 256);
  # 201 "laplacian_fuse.cpp"
  first_gang_iter_6 = (hmpprt::gr_gbidx()) * iter_per_gang_6;
  # 201 "laplacian_fuse.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < ( - (1 - (halfWidth_2 - 1))) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : ( - (1 - (halfWidth_2 - 1))));
  # 201 "laplacian_fuse.cpp"
  hmpprt::s32 x_7;
  # 201 "laplacian_fuse.cpp"
  # 202 "laplacian_fuse.cpp"
  for (x_7 = first_gang_iter_6 + (hmpprt::gr_btidy()) ; x_7 <= last_gang_iter_6 ; x_7 = x_7 + (hmpprt::gr_btnumy()))
  {
   # 203 "laplacian_fuse.cpp"
   *(UpsampleDst_3 + 2 * (halfWidth_2 - 1 - x_7)) = *(DownsampleDst_2 + (halfWidth_2 - 1 - x_7));
   # 204 "laplacian_fuse.cpp"
   *(UpsampleDst_3 + (2 * (halfWidth_2 - 1 - x_7) - 1)) = (hmpprt::u08 ) (((hmpprt::s32 ) (*(DownsampleDst_2 + (halfWidth_2 - 1 - x_7 - 1))) + (hmpprt::s32 ) (*(DownsampleDst_2 + (halfWidth_2 - 1 - x_7))) + 1) / 2);
  }
  # 196 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 196 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_192_internal_1(hmpprt::s32 width_28, hmpprt::s32 halfWidth_10, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_7)
{
 # 196 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_6, 8, "DownsampleDst_2");
  __hmppcg_call.addLocalParameter(&UpsampleDst_7, 8, "UpsampleDst_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_10), "halfWidth_2");
  __hmppcg_call.launch(hmpp_acc_region_main_192_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 196 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_192(hmpprt::s32 width_6, hmpprt::s32 halfWidth_6, hmpprt::u08* DownsampleDst_10, hmpprt::u08* UpsampleDst_11)
{
 # 211 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_192_internal_1(width_6, halfWidth_6, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_10), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_11)));
}
#endif // __CUDACC__



# 211 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_206_parallel_region_1(hmpprt::u08* DownsampleDst_1, hmpprt::u08* UpsampleDst_2, hmpprt::s32 halfHeight_1, hmpprt::s32 halfWidth_1, hmpprt::s32 width_5)
{
 # 213 "laplacian_fuse.cpp"
 {
  # 209 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_5;
  # 209 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_5;
  # 209 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_5;
  # 209 "laplacian_fuse.cpp"
  iter_per_gang_5 = 1 +  - (1 - (halfHeight_1 - 1)) / 192;
  # 209 "laplacian_fuse.cpp"
  first_gang_iter_5 = (hmpprt::gr_gbidx()) * iter_per_gang_5;
  # 209 "laplacian_fuse.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < ( - (1 - (halfHeight_1 - 1))) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : ( - (1 - (halfHeight_1 - 1))));
  # 209 "laplacian_fuse.cpp"
  hmpprt::s32 y_4;
  # 209 "laplacian_fuse.cpp"
  # 210 "laplacian_fuse.cpp"
  for (y_4 = first_gang_iter_5 ; y_4 <= last_gang_iter_5 ; y_4 = y_4 + 1)
  {
   # 213 "laplacian_fuse.cpp"
   hmpprt::u08 tmp_18;
   # 213 "laplacian_fuse.cpp"
   hmpprt::u08 tmp_19;
   # 213 "laplacian_fuse.cpp"
   hmpprt::u08 tmp_20;
   # 213 "laplacian_fuse.cpp"
   hmpprt::u08 tmp_21;
   # 213 "laplacian_fuse.cpp"
   hmpprt::s32 end_6;
   # 213 "laplacian_fuse.cpp"
   hmpprt::s32 x_8;
   # 213 "laplacian_fuse.cpp"
   # 214 "laplacian_fuse.cpp"
   # 214 "laplacian_fuse.cpp"
   for (x_8 = (hmpprt::gr_btidy()), end_6 = halfWidth_1 - 2 ; x_8 <= end_6 ; x_8 = x_8 + (hmpprt::gr_btnumy()))
   {
    # 215 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_8 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1)))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_1 + (x_8 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_1 + (x_8 + 1)))) + 2 >> 2);
    # 216 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_8 + 1))) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1)))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_1 + (x_8 + 1)))) + 1 >> 1);
    # 218 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_8 + 1) - 1)) = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1) - 1))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1)))) + 1 >> 1);
    # 219 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_8 + 1))) = *(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + (x_8 + 1)));
   }
   # 211 "laplacian_fuse.cpp"
   # 211 "laplacian_fuse.cpp"
   tmp_18 = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + halfWidth_1 - 1))) + (hmpprt::s32 ) (*(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_1 + halfWidth_1 - 1))) + 1 >> 1);
   # 211 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 211 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + width_5 - 1)) = tmp_18;
   }
   # 211 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 211 "laplacian_fuse.cpp"
   tmp_19 = *(DownsampleDst_1 + ((halfHeight_1 - 1 - y_4) * halfWidth_1 + halfWidth_1 - 1));
   # 211 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 211 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + width_5 - 1)) = tmp_19;
   }
   # 211 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 211 "laplacian_fuse.cpp"
   tmp_20 = (hmpprt::u08 ) ((hmpprt::s32 ) (*(DownsampleDst_1 + (halfHeight_1 - 1 - y_4) * halfWidth_1)) + (hmpprt::s32 ) (*(DownsampleDst_1 + (halfHeight_1 - 1 - y_4 - 1) * halfWidth_1)) + 1 >> 1);
   # 211 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 211 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + (2 * (halfHeight_1 - 1 - y_4) - 1) * width_5) = tmp_20;
   }
   # 211 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 211 "laplacian_fuse.cpp"
   tmp_21 = *(DownsampleDst_1 + (halfHeight_1 - 1 - y_4) * halfWidth_1);
   # 211 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 211 "laplacian_fuse.cpp"
    *(UpsampleDst_2 + 2 * (halfHeight_1 - 1 - y_4) * width_5) = tmp_21;
   }
   # 211 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
  }
  # 211 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 211 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_206_internal_1(hmpprt::s32 width_24, hmpprt::s32 halfWidth_9, hmpprt::s32 halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  DownsampleDst_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_10)
{
 # 211 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&DownsampleDst_5, 8, "DownsampleDst_1");
  __hmppcg_call.addLocalParameter(&UpsampleDst_10, 8, "UpsampleDst_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_4), "halfHeight_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_9), "halfWidth_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_24), "width_5");
  __hmppcg_call.launch(hmpp_acc_region_main_206_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 211 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_206(hmpprt::s32 width_15, hmpprt::s32 halfWidth_5, hmpprt::s32 halfHeight_7, hmpprt::u08* DownsampleDst_9, hmpprt::u08* UpsampleDst_6)
{
 # 233 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_206_internal_1(width_15, halfWidth_5, halfHeight_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (DownsampleDst_9), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_6)));
}
#endif // __CUDACC__



# 233 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_239_parallel_region_1(hmpprt::s16* LaplacianLayer, hmpprt::u08* Source, hmpprt::u08* UpsampleDst_1, hmpprt::s32 height_4, hmpprt::s32 width_4)
{
 # 235 "laplacian_fuse.cpp"
 {
  # 242 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_4;
  # 242 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_4;
  # 242 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_4;
  # 242 "laplacian_fuse.cpp"
  iter_per_gang_4 = ((1 + (height_4 * width_4 - 1) / 192) > 256 ? (1 + (height_4 * width_4 - 1) / 192) : 256);
  # 242 "laplacian_fuse.cpp"
  first_gang_iter_4 = (hmpprt::gr_gbidx()) * iter_per_gang_4;
  # 242 "laplacian_fuse.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < (height_4 * width_4 - 1) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : (height_4 * width_4 - 1));
  # 242 "laplacian_fuse.cpp"
  hmpprt::s32 y_7;
  # 242 "laplacian_fuse.cpp"
  # 246 "laplacian_fuse.cpp"
  for (y_7 = first_gang_iter_4 + (hmpprt::gr_btidy()) ; y_7 <= last_gang_iter_4 ; y_7 = y_7 + (hmpprt::gr_btnumy()))
  {
   # 242 "laplacian_fuse.cpp"
   hmpprt::s32 y_5;
   # 245 "laplacian_fuse.cpp"
   hmpprt::s32 x_9;
   # 247 "laplacian_fuse.cpp"
   x_9 = y_7 % width_4;
   # 247 "laplacian_fuse.cpp"
   y_5 = y_7 / width_4;
   # 247 "laplacian_fuse.cpp"
   *(LaplacianLayer + (y_5 * width_4 + x_9)) = (hmpprt::s16 ) ((hmpprt::s32 ) ((hmpprt::s16 ) (*(Source + (y_5 * width_4 + x_9)))) - (hmpprt::s32 ) ((hmpprt::s16 ) (*(UpsampleDst_1 + (y_5 * width_4 + x_9)))));
  }
  # 233 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 233 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_239_internal_1(hmpprt::s32 height_16, hmpprt::s32 width_23, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_4, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  UpsampleDst_9)
{
 # 233 "laplacian_fuse.cpp"
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
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_16), "height_4");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_23), "width_4");
  __hmppcg_call.launch(hmpp_acc_region_main_239_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 233 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_239(hmpprt::s32 height_11, hmpprt::s32 width_14, hmpprt::u08* Source_2, hmpprt::s16* LaplacianLayer_1, hmpprt::u08* UpsampleDst_5)
{
 # 12 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_239_internal_1(height_11, width_14, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (Source_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s16> (LaplacianLayer_1), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (UpsampleDst_5)));
}
#endif // __CUDACC__



# 12 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_55_parallel_region_1(hmpprt::u08* Source_1, hmpprt::s32 height_3, hmpprt::s32* pSrc_padding, hmpprt::s32 width_3)
{
 # 14 "laplacian_fuse.cpp"
 {
  # 58 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_3;
  # 58 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_3;
  # 58 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_3;
  # 58 "laplacian_fuse.cpp"
  iter_per_gang_3 = 1 + (height_3 - 1) / 192;
  # 58 "laplacian_fuse.cpp"
  first_gang_iter_3 = (hmpprt::gr_gbidx()) * iter_per_gang_3;
  # 58 "laplacian_fuse.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 - 1));
  # 58 "laplacian_fuse.cpp"
  hmpprt::s32 h_5;
  # 58 "laplacian_fuse.cpp"
  # 59 "laplacian_fuse.cpp"
  for (h_5 = first_gang_iter_3 ; h_5 <= last_gang_iter_3 ; h_5 = h_5 + 1)
  {
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 tmp_22;
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 tmp_23;
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 tmp_24;
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 tmp_25;
   # 67 "laplacian_fuse.cpp"
   tmp_22 = 2 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + 1))) - (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + 3)));
   # 67 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian_fuse.cpp"
    *(pSrc_padding + ((h_5 + 2) * (width_3 + 4) + 1)) = tmp_22;
   }
   # 67 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian_fuse.cpp"
   tmp_23 = 4 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + 3))) - 4 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + 1))) + 2 * (hmpprt::s32 ) (*(Source_1 + h_5 * width_3)) - (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + 2)));
   # 67 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian_fuse.cpp"
    *(pSrc_padding + (h_5 + 2) * (width_3 + 4)) = tmp_23;
   }
   # 67 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian_fuse.cpp"
   tmp_24 = 2 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 2))) - (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 4)));
   # 67 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian_fuse.cpp"
    *(pSrc_padding + ((h_5 + 2) * (width_3 + 4) + width_3 + 2)) = tmp_24;
   }
   # 67 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian_fuse.cpp"
   tmp_25 = 4 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 4))) - 4 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 2))) + 2 * (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 1))) - (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + width_3 - 3)));
   # 67 "laplacian_fuse.cpp"
   if ((hmpprt::gr_btidy()) == 0)
   {
    # 67 "laplacian_fuse.cpp"
    *(pSrc_padding + ((h_5 + 2) * (width_3 + 4) + width_3 + 3)) = tmp_25;
   }
   # 67 "laplacian_fuse.cpp"
   (hmpprt::gr_barrier());
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 end_9;
   # 67 "laplacian_fuse.cpp"
   hmpprt::s32 w_7;
   # 67 "laplacian_fuse.cpp"
   # 68 "laplacian_fuse.cpp"
   # 68 "laplacian_fuse.cpp"
   for (w_7 = (hmpprt::gr_btidy()), end_9 = width_3 - 1 ; w_7 <= end_9 ; w_7 = w_7 + (hmpprt::gr_btnumy()))
   {
    # 68 "laplacian_fuse.cpp"
    *(pSrc_padding + ((h_5 + 2) * (width_3 + 4) + w_7 + 2)) = (hmpprt::s32 ) (*(Source_1 + (h_5 * width_3 + w_7)));
   }
   # 12 "laplacian_fuse.cpp"
  }
  # 12 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 12 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_55_internal_1(hmpprt::s32 height_15, hmpprt::s32 width_22, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  Source_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_4)
{
 # 12 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&Source_5, 8, "Source_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_15), "height_3");
  __hmppcg_call.addLocalParameter(&pSrc_padding_4, 8, "pSrc_padding");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_22), "width_3");
  __hmppcg_call.launch(hmpp_acc_region_main_55_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 12 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_55(hmpprt::s32 height_10, hmpprt::s32 width_13, hmpprt::u08* Source_3, hmpprt::s32* pSrc_padding_2)
{
 # 75 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_55_internal_1(height_10, width_13, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (Source_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding_2)));
}
#endif // __CUDACC__



# 75 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_80_parallel_region_1(hmpprt::s32 height_2, hmpprt::u08* pBufL_cp_2, hmpprt::s32* pSrc_padding_1, hmpprt::s32 width_2)
{
 # 77 "laplacian_fuse.cpp"
 {
  # 83 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_2;
  # 83 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_2;
  # 83 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_2;
  # 83 "laplacian_fuse.cpp"
  iter_per_gang_2 = ((1 + (height_2 * width_2 - 1) / 192) > 256 ? (1 + (height_2 * width_2 - 1) / 192) : 256);
  # 83 "laplacian_fuse.cpp"
  first_gang_iter_2 = (hmpprt::gr_gbidx()) * iter_per_gang_2;
  # 83 "laplacian_fuse.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 * width_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 * width_2 - 1));
  # 83 "laplacian_fuse.cpp"
  hmpprt::s32 h_8;
  # 83 "laplacian_fuse.cpp"
  # 86 "laplacian_fuse.cpp"
  for (h_8 = first_gang_iter_2 + (hmpprt::gr_btidy()) ; h_8 <= last_gang_iter_2 ; h_8 = h_8 + (hmpprt::gr_btnumy()))
  {
   # 83 "laplacian_fuse.cpp"
   hmpprt::s32 h_6;
   # 85 "laplacian_fuse.cpp"
   hmpprt::s32 w_8;
   # 87 "laplacian_fuse.cpp"
   w_8 = h_8 % width_2;
   # 87 "laplacian_fuse.cpp"
   h_6 = h_8 / width_2;
   # 87 "laplacian_fuse.cpp"
   *(pBufL_cp_2 + (h_6 * width_2 + w_8)) = (hmpprt::u08 ) (*(pSrc_padding_1 + ((h_6 + 2) * (width_2 + 4) + w_8)) + (*(pSrc_padding_1 + ((h_6 + 2) * (width_2 + 4) + w_8 + 1)) << 2) + 6 * *(pSrc_padding_1 + ((h_6 + 2) * (width_2 + 4) + (w_8 + 2))) + (*(pSrc_padding_1 + ((h_6 + 2) * (width_2 + 4) + (w_8 + 3))) << 2) + *(pSrc_padding_1 + ((h_6 + 2) * (width_2 + 4) + (w_8 + 4))) + 8 >> 4);
  }
  # 75 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 75 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_80_internal_1(hmpprt::s32 height_20, hmpprt::s32 width_21, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_8)
{
 # 75 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_20), "height_2");
  __hmppcg_call.addLocalParameter(&pBufL_cp_8, 8, "pBufL_cp_2");
  __hmppcg_call.addLocalParameter(&pSrc_padding_5, 8, "pSrc_padding_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_21), "width_2");
  __hmppcg_call.launch(hmpp_acc_region_main_80_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 75 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_80(hmpprt::s32 height_9, hmpprt::s32 width_12, hmpprt::s32* pSrc_padding_3, hmpprt::u08* pBufL_cp_5)
{
 # 98 "laplacian_fuse.cpp"
 (hmpp_acc_region_main_80_internal_1(height_9, width_12, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding_3), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp_5)));
}
#endif // __CUDACC__



# 98 "laplacian_fuse.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_94_parallel_region_1(hmpprt::s32 height_1, hmpprt::u08* pBufL_cp_1, hmpprt::s32* pSrc_padding2_1, hmpprt::s32 width_1)
{
 # 100 "laplacian_fuse.cpp"
 {
  # 103 "laplacian_fuse.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 103 "laplacian_fuse.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 103 "laplacian_fuse.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 103 "laplacian_fuse.cpp"
  iter_per_gang_1 = ((1 + (height_1 * width_1 - 1) / 192) > 256 ? (1 + (height_1 * width_1 - 1) / 192) : 256);
  # 103 "laplacian_fuse.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 103 "laplacian_fuse.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < (height_1 * width_1 - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : (height_1 * width_1 - 1));
  # 103 "laplacian_fuse.cpp"
  hmpprt::s32 h_9;
  # 103 "laplacian_fuse.cpp"
  # 107 "laplacian_fuse.cpp"
  for (h_9 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; h_9 <= last_gang_iter_1 ; h_9 = h_9 + (hmpprt::gr_btnumy()))
  {
   # 103 "laplacian_fuse.cpp"
   hmpprt::s32 h_7;
   # 106 "laplacian_fuse.cpp"
   hmpprt::s32 w_9;
   # 107 "laplacian_fuse.cpp"
   w_9 = h_9 % width_1;
   # 107 "laplacian_fuse.cpp"
   h_7 = h_9 / width_1;
   # 107 "laplacian_fuse.cpp"
   *(pSrc_padding2_1 + ((h_7 + 2) * (width_1 + 4) + w_9 + 2)) = (hmpprt::s32 ) (*(pBufL_cp_1 + (h_7 * width_1 + w_9)));
  }
  # 98 "laplacian_fuse.cpp"
 }
}
#endif // __CUDACC__



# 98 "laplacian_fuse.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_94_internal_1(hmpprt::s32 height_19, hmpprt::s32 width_20, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  pSrc_padding2_7, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08>  pBufL_cp_7)
{
 # 98 "laplacian_fuse.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_1");
  __hmppcg_call.addLocalParameter(&pBufL_cp_7, 8, "pBufL_cp_1");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_7, 8, "pSrc_padding2_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_1");
  __hmppcg_call.launch(hmpp_acc_region_main_94_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 98 "laplacian_fuse.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_94(hmpprt::s32 height_8, hmpprt::s32 width_11, hmpprt::s32* pSrc_padding2_4, hmpprt::u08* pBufL_cp_4)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_94_internal_1(height_8, width_11, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (pSrc_padding2_4), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::u08> (pBufL_cp_4)));
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
      hmpp_acc_region_main_108_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_108_parallel_region_1");
      hmpp_acc_region_main_130_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_130_parallel_region_1");
      hmpp_acc_region_main_153_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_153_parallel_region_1");
      hmpp_acc_region_main_183_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_183_parallel_region_1");
      hmpp_acc_region_main_192_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_192_parallel_region_1");
      hmpp_acc_region_main_206_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_206_parallel_region_1");
      hmpp_acc_region_main_239_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_239_parallel_region_1");
      hmpp_acc_region_main_55_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_55_parallel_region_1");
      hmpp_acc_region_main_80_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_80_parallel_region_1");
      hmpp_acc_region_main_94_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_94_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_108", "prototype hmpp_acc_region_main_108(height: s32, width: s32, pSrc_padding2: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_130", "prototype hmpp_acc_region_main_130(height: s32, width: s32, FilterDst: ^cudaglob u8, pSrc_padding2: ^cudaglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_153", "prototype hmpp_acc_region_main_153(width: s32, halfWidth: s32, halfHeight: s32, FilterDst: ^cudaglob u8, DownsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_183", "prototype hmpp_acc_region_main_183(height: s32, width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_192", "prototype hmpp_acc_region_main_192(width: s32, halfWidth: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_206", "prototype hmpp_acc_region_main_206(width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^cudaglob u8, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_239", "prototype hmpp_acc_region_main_239(height: s32, width: s32, Source: ^cudaglob u8, LaplacianLayer: ^cudaglob s16, UpsampleDst: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_55", "prototype hmpp_acc_region_main_55(height: s32, width: s32, Source: ^cudaglob u8, pSrc_padding: ^cudaglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_80", "prototype hmpp_acc_region_main_80(height: s32, width: s32, pSrc_padding: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_94", "prototype hmpp_acc_region_main_94(height: s32, width: s32, pSrc_padding2: ^cudaglob s32, pBufL_cp: ^cudaglob u8)");

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
      delete hmpp_acc_region_main_108_parallel_region_1;
      delete hmpp_acc_region_main_130_parallel_region_1;
      delete hmpp_acc_region_main_153_parallel_region_1;
      delete hmpp_acc_region_main_183_parallel_region_1;
      delete hmpp_acc_region_main_192_parallel_region_1;
      delete hmpp_acc_region_main_206_parallel_region_1;
      delete hmpp_acc_region_main_239_parallel_region_1;
      delete hmpp_acc_region_main_55_parallel_region_1;
      delete hmpp_acc_region_main_80_parallel_region_1;
      delete hmpp_acc_region_main_94_parallel_region_1;

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
