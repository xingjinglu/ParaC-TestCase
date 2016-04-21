#include<stdio.h>
#include<<CL/cl.h>



static cl_context g_context;
static cl_command_queue g_queue;
static cl_program g_program;
static cl_int status;


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




void Query()
{
  cl_platform_id platform = NULL;
  cl_device_id *devide;
  cl_uint numplatforms, numdevices;

  status = clGetPlatformIDs(0 , NULL, &numplatforms);





  return ;
}


int main()
{

  return 0;
}
