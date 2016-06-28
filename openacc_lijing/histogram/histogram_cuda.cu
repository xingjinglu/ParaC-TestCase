
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

# 15 "histogram.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_103(hmpprt::s32 w_2, hmpprt::s32 h_2, hmpprt::s32* dstData_2, hmpprt::s32* mapPixel_2)
;
#endif // __CUDACC__



# 15 "histogram.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_103_internal_1(hmpprt::s32 w, hmpprt::s32 h, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  dstData_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  mapPixel)
;
#endif // __CUDACC__



# 15 "histogram.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_103_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_103_parallel_region_1(hmpprt::s32* dstData, hmpprt::s32 h_1, hmpprt::s32* mapPixel_1, hmpprt::s32 w_1);
#endif // __CUDACC__




# 15 "histogram.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_103_parallel_region_1(hmpprt::s32* dstData, hmpprt::s32 h_1, hmpprt::s32* mapPixel_1, hmpprt::s32 w_1)
{
 # 17 "histogram.cpp"
 {
  # 107 "histogram.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 107 "histogram.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 107 "histogram.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 107 "histogram.cpp"
  iter_per_gang_1 = ((1 + (h_1 - 1) / 192) > 8LL ? (1 + (h_1 - 1) / 192) : 8LL);
  # 107 "histogram.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 107 "histogram.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < (h_1 - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : (h_1 - 1));
  # 107 "histogram.cpp"
  hmpprt::s32 i_1;
  # 107 "histogram.cpp"
  # 108 "histogram.cpp"
  for (i_1 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; i_1 <= last_gang_iter_1 ; i_1 = i_1 + (hmpprt::gr_btnumy()))
  {
   # 111 "histogram.cpp"
   hmpprt::s32 end_1;
   # 111 "histogram.cpp"
   hmpprt::s32 j_1;
   # 111 "histogram.cpp"
   # 112 "histogram.cpp"
   # 112 "histogram.cpp"
   for (j_1 = (hmpprt::gr_btidx()), end_1 = w_1 - 1 ; j_1 <= end_1 ; j_1 = j_1 + (hmpprt::gr_btnumx()))
   {
    # 113 "histogram.cpp"
    *(dstData + (i_1 * w_1 + j_1)) = *(mapPixel_1 + *(dstData + (i_1 * w_1 + j_1)));
   }
   # 15 "histogram.cpp"
  }
  # 15 "histogram.cpp"
 }
}
#endif // __CUDACC__



# 15 "histogram.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_103_internal_1(hmpprt::s32 w, hmpprt::s32 h, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  dstData_1, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  mapPixel)
{
 # 15 "histogram.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8LL);
  __hmppcg_call.addLocalParameter(&dstData_1, 8, "dstData");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (h), "h_1");
  __hmppcg_call.addLocalParameter(&mapPixel, 8, "mapPixel_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (w), "w_1");
  __hmppcg_call.launch(hmpp_acc_region_main_103_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 15 "histogram.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_103(hmpprt::s32 w_2, hmpprt::s32 h_2, hmpprt::s32* dstData_2, hmpprt::s32* mapPixel_2)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_103_internal_1(w_2, h_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (dstData_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (mapPixel_2)));
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
      hmpp_acc_region_main_103_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_103_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_103", "prototype hmpp_acc_region_main_103(w: s32, h: s32, dstData: ^cudaglob s32, mapPixel: ^cudaglob s32)");

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
      delete hmpp_acc_region_main_103_parallel_region_1;

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
