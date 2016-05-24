#include<stdio.h>
#include<string.h>
#include<CL/cl.h>



static cl_context g_context;
static cl_command_queue g_queue;
static cl_program g_program;
static cl_int status;

unsigned char VendorType; // 0->NoGPU, 1->AMD, 2->Nvidia.


static inline void checkErr(cl_int err,const char *name)
{
  if(err != CL_SUCCESS){
    printf("Error: %s %d",name,err);
    switch(err){
      case CL_DEVICE_NOT_FOUND :printf("(CL_DEVICE_NOT_FOUND)");break;
      case CL_DEVICE_NOT_AVAILABLE :printf("(CL_DEVICE_NOT_AVAILABLE)");break;
      case CL_COMPILER_NOT_AVAILABLE :printf("(CL_COMPILER_NOT_AVAILABLE)");break;
      case CL_MEM_OBJECT_ALLOCATION_FAILURE :printf("(CL_MEM_OBJECT_ALIOCATION_FAILURE)");break;
      case CL_OUT_OF_RESOURCES :printf("(CL_OUT_OF_RESOURCES)");break;
      case CL_OUT_OF_HOST_MEMORY :printf("(CL_OUT_OF_HOST_MEMORY)");break;
      case CL_MEM_COPY_OVERLAP :printf("(CL_MEM_COPY_OVERLAP)");break;
      case CL_BUILD_PROGRAM_FAILURE:printf("(CL_BUILD_PROGRAM_FAILURE)");break;
      case CL_INVALID_VALUE:printf("(CL_INVALID_VALUE)");break;
      case CL_INVALID_DEVICE_TYPE:printf("(CL_INVALID_DEVICE_TYPE)");break;
      case CL_INVALID_DEVICE:printf("(CL_INVALID_DEVICE)");break;
      case CL_INVALID_CONTEXT:printf("(CL_INVALID_CONTEXT)");break;
      case CL_INVALID_BINARY:printf("(CL_INVALID_BINARY)");break;
      case CL_INVALID_BUILD_OPTIONS:printf("(CL_INVALID_BUILD_OPTIONS)");break;
      case CL_INVALID_PROGRAM:printf("(CL_INVALID_PROGRAM)");break;
      case CL_INVALID_PROGRAM_EXECUTABLE:printf("(CL_INVALID_PROGRAM_EXECUTABLE)");break;
      case CL_INVALID_KERNEL_DEFINITION:printf("(CL_INVALID_KERNEL_DEFINITION)");break;
      case CL_INVALID_KERNEL:printf("(CL_INVALID_KERNEL)");break;
      case CL_INVALID_KERNEL_ARGS:printf("(CL_INVALID_KERNEL_ARGS)");break;
      case CL_INVALID_OPERATION:printf("(CL_INVALID_OPERATION)");break;
      case CL_INVALID_COMMAND_QUEUE:printf("(CL_INVALID_COMMAND_QUEUE)");break;
      case CL_INVALID_WORK_DIMENSION:printf("(CL_INVALID_WORK_DIMENSION)");break;
      case CL_INVALID_WORK_GROUP_SIZE:printf("(CL_INVALID_WORK_GROUP_SIZE)");break;
      case CL_INVALID_WORK_ITEM_SIZE:printf("(CL_INVALID_WORK_ITEM_SIZE)");break;
      case CL_INVALID_GLOBAL_WORK_SIZE:printf("(CL_INVALID_GLOBAL_WORK_SIZE)");break;
      case CL_INVALID_GLOBAL_OFFSET:printf("(CL_INVALID_GLOBAL_OFFSET)");break;
      case CL_INVALID_IMAGE_SIZE:printf("(CL_INVALID_IMAGE_SIZE)");break;
      case CL_INVALID_EVENT_WAIT_LIST:printf("(CL_INVALID_EVENT_WAIT_LIST)");break;
      case CL_MISALIGNED_SUB_BUFFER_OFFSET:printf("(CL_MISALIGNED_SUB_BUFFER_OFFSET)");break;

      default:
        break;
    }
    printf("\n");
    exit(1);
  }
}




int  Query()
{
  cl_platform_id platform = NULL;
  cl_device_id *devices;
  cl_uint numplatforms, numdevices;

  // 1) Check the platforms.
  // Get the total number of platforms.
  status = clGetPlatformIDs(0 , NULL, &numplatforms);
  if( status != CL_SUCCESS ){
     printf("Error: Getting platform IDs.(clGetPlatformIDs)\n");
     return -1;
  }
  //printf("numplatforms = %d \n", numplatforms);
  if( numplatforms > 0 ){
    cl_platform_id * platforms = (cl_platform_id*)malloc(numplatforms * 
         sizeof(cl_platform_id) );

    status = clGetPlatformIDs(numplatforms, platforms, NULL);
    for( int i = 0; i < numplatforms; i++){
      char pbuff[100];
      status = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, sizeof(pbuff), pbuff, NULL);
      platform = platforms[i];
      printf("Vendor: %s\n", pbuff);
      if( !strcmp(pbuff, "Advanced Micro Devices, Inc.") ){
        VendorType = 1;
        break;
      }else if(strcmp(pbuff, "Nvidia , Inc.") ){
         VendorType = 2;
         break;
      }
      else VendorType  = 0;

    }
    delete platforms;
  }

  // 
  status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, NULL, &numdevices);
  checkErr(status, "clGetDeviceIDs()");

  devices = (cl_device_id*) malloc( numdevices * sizeof(cl_device_id) );
  status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, numdevices, devices, NULL);
  checkErr(status, "clGetDeviceIDs()");

  //
  for( int i = 0; i < numdevices; i++){
     unsigned long clSize;
     unsigned int  clMaxCUs, clMaxWIDims;
     size_t clWGSize, clMaxWISize[3];
    // CL_DEVICE_MAX_COMPUTE_UNITS, MAX_WORK_GROUP_SIZE, MAX_WORK_ITEM_DIMENSIONS,
    // MAX_WORK_ITEM_SIZES
    status = clGetDeviceInfo(devices[i], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(clSize), &clSize, NULL);
    status = clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(clMaxCUs), &clMaxCUs, NULL);
    status = clGetDeviceInfo(devices[i], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(clWGSize), &clWGSize, NULL);
    status = clGetDeviceInfo(devices[i], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(clMaxWIDims), &clMaxWIDims, NULL);
    status = clGetDeviceInfo(devices[i], CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(clMaxWISize), clMaxWISize, NULL);

    printf("LocalMemSize = %d, MaxCUs = %d, WorkGroupSize = %d \n", clSize, clMaxCUs, clWGSize);
    printf("ItemDims = %d, X-ItemSize = %d, Y-ItemSize = %d, Z-ItemSize = %d\n", clWGSize, clMaxWISize[0], clMaxWISize[1], clMaxWISize[2] );
  }

  g_context = clCreateContext(NULL, numdevices, devices, NULL, NULL, &status);
  checkErr(status, "clCreateContext()");

  g_queue = clCreateCommandQueue(g_context, devices[0], CL_QUEUE_PROFILING_ENABLE, &status);
  checkErr(status, "clCreateCommandQueue()");








  return 0;
}


int main()
{

   Query();
  return 0;
}
