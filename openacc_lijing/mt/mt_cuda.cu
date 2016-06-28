
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

# 12 "mt.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_44(hmpprt::s32 n_2, float* A_2, float* B_2)
;
#endif // __CUDACC__



# 12 "mt.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_44_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  A, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  B)
;
#endif // __CUDACC__



# 12 "mt.cpp"

#ifndef __CUDACC__
static hmpprt::CUDAGrid * hmpp_acc_region_main_44_parallel_region_1 = 0;
#else

extern "C" __global__ void hmpp_acc_region_main_44_parallel_region_1(float* A_1, float* B_1, hmpprt::s32 n_1);
#endif // __CUDACC__




# 12 "mt.cpp"

#ifdef __CUDACC__

extern "C" __global__ void hmpp_acc_region_main_44_parallel_region_1(float* A_1, float* B_1, hmpprt::s32 n_1)
{
 # 14 "mt.cpp"
 {
  # 45 "mt.cpp"
  hmpprt::s32 iter_per_gang_1;
  # 45 "mt.cpp"
  hmpprt::s32 first_gang_iter_1;
  # 45 "mt.cpp"
  hmpprt::s32 last_gang_iter_1;
  # 45 "mt.cpp"
  iter_per_gang_1 = ((1 + (n_1 * n_1 - 1) / 192) > 256 ? (1 + (n_1 * n_1 - 1) / 192) : 256);
  # 45 "mt.cpp"
  first_gang_iter_1 = (hmpprt::gr_gbidx()) * iter_per_gang_1;
  # 45 "mt.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < (n_1 * n_1 - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : (n_1 * n_1 - 1));
  # 45 "mt.cpp"
  hmpprt::s32 i_2;
  # 45 "mt.cpp"
  # 49 "mt.cpp"
  for (i_2 = first_gang_iter_1 + (hmpprt::gr_btidy()) ; i_2 <= last_gang_iter_1 ; i_2 = i_2 + (hmpprt::gr_btnumy()))
  {
   # 45 "mt.cpp"
   hmpprt::s32 i_1;
   # 48 "mt.cpp"
   hmpprt::s32 j_1;
   # 50 "mt.cpp"
   j_1 = i_2 % n_1;
   # 50 "mt.cpp"
   i_1 = i_2 / n_1;
   # 50 "mt.cpp"
   *(B_1 + (j_1 * n_1 + i_1)) = *(A_1 + (i_1 * n_1 + j_1));
  }
  # 12 "mt.cpp"
 }
}
#endif // __CUDACC__



# 12 "mt.cpp"

#ifndef __CUDACC__
void hmpp_acc_region_main_44_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  A, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  B)
{
 # 12 "mt.cpp"
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.addLocalParameter(&A, 8, "A_1");
  __hmppcg_call.addLocalParameter(&B, 8, "B_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (n), "n_1");
  __hmppcg_call.launch(hmpp_acc_region_main_44_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
}
#endif // __CUDACC__



# 12 "mt.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  void hmpp_acc_region_main_44(hmpprt::s32 n_2, float* A_2, float* B_2)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_44_internal_1(n_2, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float> (A_2), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float> (B_2)));
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
      hmpp_acc_region_main_44_parallel_region_1 = new hmpprt::CUDAGrid(hmpprt_module, "hmpp_acc_region_main_44_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_44", "prototype hmpp_acc_region_main_44(n: s32, A: ^cudaglob float, B: ^cudaglob float)");

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
      delete hmpp_acc_region_main_44_parallel_region_1;

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
