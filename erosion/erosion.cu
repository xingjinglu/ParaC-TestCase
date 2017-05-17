#include <stdio.h>

#include <cuda_runtime.h>

#include <helper_cuda.h>
#include <helper_functions.h>

const char *sSDKname = "erosion";
cudaStream_t stream;

__global__ void MorphErosion_cuda(unsigned char*src, 
     unsigned char*dst, int width,int height, 
     int structWidth, int structHeight){

  int x = threadIdx.x + blockIdx.x*blockDim.x;
  int y = threadIdx.y + blockIdx.y*blockDim.y;

  if(x >= width || y >= height)
    return;

  dst[y*width+x] = src[y*width+x];
  int mid = (structWidth+1)/2 -1 ; // structWidth = structHeight = 3,4.

  if( (y < mid) || (y>=height-mid-1) )
    return;
  if( (x < mid) || (x >= width - mid -1 ))
    return;

  unsigned char val = 255;

#if 1
  for(int m = 0; m < structWidth; m++){
    for(int n = 0; n < structHeight; n++){
      val &= src[(y+n)*width+x+m];
    }
  }
#endif
#if 0
  val = val & src[y*width+x];
  val = val & src[y*width+x+1];
  val = val & src[y*width+x+2];
  val = val & src[(y+1)*width+x];
  val = val & src[(y+1)*width+x+1];
  val = val & src[(y+1)*width+x+2];
  val = val & src[(y+2)*width+x];
  val = val & src[(y+2)*width+x+1];
  val = val & src[(y+2)*width+x+2];
  val = val & src[(y+1)*width+x+2];
#endif

  dst[y*width+x] = val;
}
//
#define VEC 1
#define TYPE char
#define STYPE char
#define MAKETYPE char

#define STREAM_COUNT 4





cudaEvent_t start, stop;




int N = 1 << 22;
int nreps = 10;
int inner_reps = 5;
int memsize;

dim3 block(1024);
dim3 grid;

int thread_blocks;

void cudaDeviceInfoSetup(int argc, char *argv[]);

main(int argc, char *argv[])
{
  
  cudaDeviceInfoSetup(argc, argv);

  if( argc < 3 ){
    std::cout<<"Please input Height and Width \n";
    return 0;
  }

  int Height = atoi(argv[1]);
  int Width = atoi(argv[2]);

  memsize = sizeof(unsigned char)*Width*Height;

  // Init on the host.
  unsigned char *src = (unsigned char*) malloc(memsize);
  unsigned char *dst = (unsigned char*) malloc(memsize);

  for(int i = 0; i < Height; i++)
    for( int j = 0; j < Width; j++){
      src[i*Width+j] = rand()%255;
    }


  unsigned char *d_src, *d_dst;

  //
  checkCudaErrors(cudaStreamCreate(&stream));

  //


  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  checkCudaErrors(cudaMalloc(&d_src, memsize)); 
  checkCudaErrors(cudaMalloc(&d_dst, memsize));

  // Time copies and kernel.
  checkCudaErrors( cudaMemcpy(d_src, src, memsize, cudaMemcpyHostToDevice ) );

  thread_blocks = N / block.x;
  dim3 threadPerBlock(16, 16);
  dim3 numBlocks(Width/threadPerBlock.x, Height/threadPerBlock.y);

  // Kernel wazrmup.
  MorphErosion_cuda<<<numBlocks, threadPerBlock>>>(d_src, d_dst, Width, Height, 3, 3);

  // Real do.
  float kernel_time;
  float total_time = 0.0;
  for( int i = 0; i < 10; i++){
    cudaEventRecord(start, 0);
    MorphErosion_cuda<<<numBlocks, threadPerBlock>>>(d_src, d_dst, Width, Height, 3, 3);
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&kernel_time, start, stop);
    total_time += kernel_time;
  }

  printf(" Kernel\t\t\t: %f ms \n", total_time/10);


  checkCudaErrors( cudaMemcpy(dst, d_dst, memsize, cudaMemcpyDeviceToHost ) );

    // verify the results, we will use the results for final output.
   // bool bResults ; //= test();

    // Free resources

      cudaFree(d_src);
      cudaFree(d_dst);
      free(src);
      free(dst);


      cudaStreamDestroy(stream);
      cudaEventDestroy(start);
      cudaEventDestroy(stop);


      cudaDeviceReset();
      //if(bResults) printf("OK\n");
      //else printf("Error \n");
}


void cudaDeviceInfoSetup(int argc, char *argv[] )
{

  int cuda_device = 0;
  float scale_factor;
  cudaDeviceProp deviceProp;

  printf("[%s] - Starting ...\n", sSDKname);

  if(checkCmdLineFlag(argc, (const char**)argv, "device"))
  {
    cuda_device = getCmdLineArgumentInt(argc, (const char**)argv, "device=");

    if(cuda_device < 0){
      printf("Invalid command line parameters\n");
      exit(EXIT_FAILURE);
    }
    else{
      printf("cuda_device  %d\n", cuda_device);
      cuda_device = gpuDeviceInit(cuda_device);
      if(cuda_device < 0 ){
        printf("No CUDA  Capable devices found, exiting ...\n");
        exit(EXIT_SUCCESS);
      }

    }
  }
  else{

    // Otherwise pick the device with the highest Gflops/s
    cuda_device = gpuGetMaxGflopsDeviceId();
    checkCudaErrors(cudaSetDevice(cuda_device));
    checkCudaErrors(cudaGetDeviceProperties(&deviceProp, cuda_device));
    printf("> Using CUDA device [ %d ]: %s \n", cuda_device, deviceProp.name);
  }

  checkCudaErrors(cudaGetDeviceProperties(&deviceProp, cuda_device));
  printf("[ %s] has %d MP(s) x %d (Cores/MP) = %d (Cores)\n",
      deviceProp.name, deviceProp.multiProcessorCount,
      _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
      _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) * deviceProp.multiProcessorCount);

  // Anything that is less that 32 Cores will have scaled down workload.
  scale_factor = max((32.0f /(_ConvertSMVer2Cores(deviceProp.major, deviceProp.minor)*(float)deviceProp.multiProcessorCount)), 1.0f);
  N = (int)((float)N/scale_factor);
  printf("> Device name: %s\n", deviceProp.name);
  printf("> CUDA Capability %d.%d hardware with %d multi-processors\n",
      deviceProp.major, deviceProp.minor,
      deviceProp.multiProcessorCount);
  printf("> scale_factor = %.2f\n", 1.0f/scale_factor);
  printf("> array_size = %d\n\n", N);

  // --------------- End Platform information --------------

}

