#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<CL/cl.h>
#include<sys/time.h>
#include <iostream>

#define PADDING      32
#define PADDING_LINE 2
#define error_len    1024

#define MEAN_THREADS_NUMBER_X 16 
#define MEAN_THREADS_NUMBER_Y 16 


#ifdef TIME_PROF
#define TIME_TOTAL
#define TIME_KERNEL
#endif

#define LOCALSIZE_X 16 
#define LOCALSIZE_Y 16 


char BufferError[error_len];
cl_int status;
cl_context g_context;
cl_command_queue g_queue;
cl_program program;

typedef struct MMC_CSE_PARAMETER_PUBLIC
{
	float peak;
	float cutoffCoef;
	float cutoff2;
	float cutoff3Coef;
}MMC_CSE_PARAMETER_PUBLIC;

void checkErr(cl_int err,const char *name)
{
	if(err != CL_SUCCESS)
	{
		printf("Error: %s %d",name,err);
		switch(err)
		{
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

char* ReadSources(const char* fileName)
{
	FILE *file=fopen(fileName,"rb");
	if(!file)
	{
		printf("ERROR:Failed to open file '%s'\n",fileName);
		return NULL;
	}
	
	if(fseek(file,0,SEEK_END))
	{
		printf("ERROR: Failed to open file '%s'\n",fileName);
		fclose(file);
		return NULL;
	}
	
	long size=ftell(file);
	if(size==0)
	{
		printf("ERROR: Failed to check position on file '%s'\n",fileName);
		fclose(file);
		return NULL;
	}
	
	rewind(file);
	
	char *src=(char *)malloc(sizeof(char)*size+1);
	if(!src)
	{
		printf("ERROR: Failed to allocate memory for file '%s'\n",fileName);
		fclose(file);
		return NULL;
	}
	
	size_t res=fread(src,1,sizeof(char) *size,file);
	if(res !=sizeof (char) * size)
	{
		printf("ERROR: Failed to read file '%s'\n",fileName);
		fclose(file);
		free(src);
		return NULL;
	}
	
	src[size]='\0';/*NULL terminated */
	fclose(file);
	
	return src;
}

int openCLCreate(cl_context* context,cl_command_queue* queue,const char* inputfile)
{
	cl_int status;
	cl_platform_id platform=NULL;
	cl_device_id *device;
  cl_uint numPlatforms,numdevices;
	
	status=clGetPlatformIDs(0,NULL,&numPlatforms);
	checkErr(status,"clGetPlatformIDs()");
  if(numPlatforms>0)
    {
        cl_platform_id*  platforms=(cl_platform_id*)malloc(numPlatforms*sizeof(cl_platform_id));
        status =clGetPlatformIDs(numPlatforms,platforms,NULL);
        if(status !=CL_SUCCESS)
        {
            printf("Error:Getting platform Ids.(clGetPlatformsIDs)\n");
            return -1;
        }
        for(unsigned int i=0; i<numPlatforms;++i)
        {
            char pbuff[100];
            status = clGetPlatformInfo(
                    platforms[i],
                    CL_PLATFORM_VENDOR,
                    sizeof(pbuff),
                    pbuff,
                    NULL
                    );
            platform=platforms[i];
            if(!strcmp(pbuff,"Advanced Micro Devices,Inc."))
            {
                break;
            } 
        }
        delete platforms;
    }
	
  status=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,0,NULL,&numdevices);
	checkErr(status,"clGetDeviceIDs()");

	device=(cl_device_id *)malloc(numdevices*sizeof(cl_device_id));
  status=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,numdevices,device,NULL);

  *context=clCreateContext(NULL,numdevices,device,NULL,NULL,&status);
	checkErr(status,"clCreateContext()");
	
	*queue=clCreateCommandQueue(*context,device[1],CL_QUEUE_PROFILING_ENABLE,&status);
	checkErr(status,"clCreateCommandQueue()");
	
	char *program_source=ReadSources((const char*)inputfile);
	
	program=clCreateProgramWithSource(g_context,1,(const char**)&program_source,NULL,&status);
	checkErr(status,"clCreateProgramWithSource");
	
	status=clBuildProgram(program,1,&device[1],NULL,NULL,NULL);
	
	if(status !=CL_SUCCESS)
	{
		printf("Error: build kernel fails\n");
		size_t len;
		clGetProgramBuildInfo(program,*device,CL_PROGRAM_BUILD_LOG,sizeof(BufferError),BufferError,&len);
		BufferError[len]='\0';
		printf("%s",BufferError);
		checkErr(status,"clBuildProgram");
		getchar();
		return -1;
	}
	
	return 0;
}

void pad_yPlane(unsigned char* pSrc,unsigned char* pDst,int width,int height,int stepwide,int shift)
{
	for(int i=0;i<height;i++)
	{
		memcpy(pDst+shift,pSrc,width);
		pSrc +=width;
		pDst +=stepwide;
	}
}

void unpad_yPlane(unsigned char* pSrc,unsigned char* pDst,int width,int height,int stepwide,int shift)
{
	for(int i=0;i<height;i++)
	{
		memcpy(pDst,pSrc+shift,width);
		pDst +=width;
		pSrc +=stepwide;
	}
}


inline void freeu(unsigned char **p)
{
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
}

inline void frees(short **p)
{
	if(p!=NULL)
	{
		free(p[0]);
		free(p);
		p=NULL;
	}
}

struct TEST_TIME{
  double env_init_time;
  double buffer_init_time;
  double down_time;
  double up_col_time;
  double up_row_time;
  double up_time;
  double pad_time;
  double sobel_time;
  double mean_time;
  double sharp_time;
  double exe_time;
  double total_used;
  double kernel_down;
  double kernel_up_row;
  double kernel_up_col;
  double kernel_up;
  double kernel_sobel;
  double kernel_mean;
  double kernel_sharpness;
};
size_t upMultiple(size_t dividend, size_t divisor)
{
    size_t temp0 = dividend%divisor;
    size_t temp1 = dividend/divisor;
    return temp0==0 ? temp1 : (temp1+1);
}

#ifdef TIME_PROF
TEST_TIME all_Sharpness(unsigned char* yuvfile,int height,int width,unsigned char * yPlane0)
#else
void all_Sharpness(unsigned char* yuvfile,int height,int width,unsigned char * yPlane0)
#endif
{

#ifdef TIME_PROF
  struct timeval time,time0,time0_1,time1, time1_1, time2, time2_1,time3, time3_1, time4,time4_1, time5, time5_1, time6, time6_1, time7_1, time7;
  cl_ulong startTime,endTime, kernelExecTime0, kernelExecTime1,kernelExecTime2,kernelExecTime3,kernelExecTime4,kernelExecTime5, kernelExecTime6, kernelExecTime7;;
 	unsigned long start,end;
  struct TEST_TIME t;
#endif
  
  MMC_CSE_PARAMETER_PUBLIC cseParamPublic;

  cseParamPublic.cutoff2     = 256.0f;
	cseParamPublic.cutoff3Coef = 1.0f;
	cseParamPublic.cutoffCoef  = 1.0f;
	cseParamPublic.peak        = 2.0f;

	const char* inputfile="sharpup.cl";

  #ifdef TIME_KERNEL
  gettimeofday(&time,NULL);
  #endif
	if(-1==openCLCreate(&g_context,&g_queue,inputfile))
	{
		printf("openCL create fail !!!!!!!\n");
	}
	int quarterWidth  = width  >> 2;
	int quarterHeight = height >> 2;


  int pSrcStepwide = width*sizeof(char);
  pSrcStepwide=(pSrcStepwide%PADDING<16) ? ((pSrcStepwide/PADDING+1)*PADDING) : ((pSrcStepwide+PADDING)/PADDING+1)*PADDING;
  int pSrcShift=pSrcStepwide*PADDING_LINE;

  int pEdgeStepwide = width*sizeof(short);
  pEdgeStepwide=(pEdgeStepwide%PADDING<16) ? ((pEdgeStepwide/PADDING+1)*PADDING) : ((pEdgeStepwide+PADDING)/PADDING+1)*PADDING;
  int pEdgeShift=pEdgeStepwide*PADDING_LINE;
  
  int downStepwide = quarterWidth*sizeof(char);
  downStepwide  = (downStepwide%PADDING<16) ? ((downStepwide/PADDING+1)*PADDING) : ((downStepwide+PADDING)/PADDING + 0)*PADDING;
  int downShift     = downStepwide * PADDING_LINE;
		
	size_t sz1     = downStepwide*(quarterHeight+(PADDING_LINE<<1));
	size_t szShort = pEdgeStepwide*(height+(PADDING_LINE<<1));
	size_t sz0Pad  = pSrcStepwide*(height+(PADDING_LINE<<1)); 
  unsigned char *pad_yPlane0 = (unsigned char *)malloc(sz0Pad);

  /********Start*****************/
  //---------------padding time----------------
#ifdef TIME_PROF	
  gettimeofday(&time0,NULL);
#endif
  pad_yPlane(yuvfile,pad_yPlane0,width,height,pSrcStepwide,pSrcShift);

#ifdef TIME_TOTAL
  gettimeofday(&time0_1,NULL);
#endif
  
  cl_mem pad_yPlane0Buffer = clCreateBuffer(g_context, CL_MEM_ALLOC_HOST_PTR, sz0Pad,NULL,&status);
  //cl_mem pad_yPlane0Buffer = clCreateBuffer(g_context,CL_MEM_READ_WRITE, sz0Pad,NULL,&status);
	cl_mem yPlaneCSERBuffer  = clCreateBuffer(g_context,CL_MEM_READ_WRITE,sz0Pad,NULL,&status);
	cl_mem yPlaneDownBuffer  = clCreateBuffer(g_context,CL_MEM_READ_WRITE,sz1,NULL,&status);
	cl_mem cacheBuffer       = clCreateBuffer(g_context,CL_MEM_READ_WRITE,sz0Pad,NULL,&status);
	cl_mem pEdgeBuffer       = clCreateBuffer(g_context,CL_MEM_READ_WRITE,szShort,NULL,&status);
	
  status = clEnqueueWriteBuffer(g_queue,pad_yPlane0Buffer,CL_TRUE,0,sz0Pad,pad_yPlane0,0,NULL,NULL);

  /********0.DownScaleX16*************************************/
#ifdef TIME_TOTAL
  gettimeofday(&time1,NULL);
#endif
  cl_event event_kernel;


    size_t global_work_size[2];
    size_t local_work_size[2];
  //for(int i = 0; i <20; i++)
  {
    local_work_size[0]  = LOCALSIZE_X;
    local_work_size[1]  = LOCALSIZE_Y;
    global_work_size[0] = upMultiple((width>>2),local_work_size[0])*local_work_size[0];
    global_work_size[1] = upMultiple((height>>2),local_work_size[1])*local_work_size[1];

    cl_kernel downX16Kernel=clCreateKernel(program,"downKernel",&status);
    checkErr(status,"clCreateKernel() for downKernel");
    status = clSetKernelArg(downX16Kernel,0,sizeof(cl_mem),(void *) &pad_yPlane0Buffer);
    checkErr(status,"clSetKernelArg");
    status = clSetKernelArg(downX16Kernel,1,sizeof(cl_mem),(void *) &yPlaneDownBuffer);
    checkErr(status,"clSetKernelArg");
    status = clSetKernelArg(downX16Kernel,2,sizeof(int),(void *) &width);
    status = clSetKernelArg(downX16Kernel,3,sizeof(int),(void *) &height);
    status = clSetKernelArg(downX16Kernel,4,sizeof(int),(void *) &pSrcStepwide);
    status = clSetKernelArg(downX16Kernel,5,sizeof(int),(void *) &pSrcShift);
    status = clSetKernelArg(downX16Kernel,6,sizeof(int),(void *) &downStepwide);
    status = clSetKernelArg(downX16Kernel,7,sizeof(int),(void *) &downShift);

    status=clEnqueueNDRangeKernel(g_queue,downX16Kernel,2,NULL,global_work_size,local_work_size,0,NULL,&event_kernel);
    checkErr(status,"clEnqueueNDRangeKernel");

#ifdef TIME_PROF
    clFinish(g_queue);
#endif

#ifdef TIME_TOTAL
    gettimeofday(&time1_1,NULL);
#endif

#ifdef TIME_KERNEL
    clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
    clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
    kernelExecTime0 = (endTime-startTime)/1000.0;

  }

#endif

  /*unsigned char *yPlaneDown = (unsigned char *)malloc(sz1);
    status = clEnqueueReadBuffer(g_queue,yPlaneDownBuffer,CL_TRUE,0,sz1,yPlaneDown,0,NULL,NULL);
    for(int i=2;i<height/4+2;i++)
    {
    for(int j=0;j<width/4;j++)
    printf("%d ",yPlaneDown[i*downStepwide+j]);
    printf("\n");
    }*/

  /******** UpCol*******************************/

#ifdef TIME_TOTAL
  gettimeofday(&time2,NULL);
#endif
  global_work_size[0]=2;
  global_work_size[1]=height/4;
  local_work_size[0]=1;
  local_work_size[1]=64;
  cl_kernel UpBorderColumKernel=clCreateKernel(program,"BorderUpColum",&status);
  checkErr(status,"clCreateKernel() for BorderUpColum");
  status=clSetKernelArg(UpBorderColumKernel,0,sizeof(cl_mem),(void*) &yPlaneDownBuffer);
  status=clSetKernelArg(UpBorderColumKernel,1,sizeof(cl_mem),(void*) &yPlaneCSERBuffer);
  status=clSetKernelArg(UpBorderColumKernel,2,(sizeof(unsigned char)*(local_work_size[0]*local_work_size[1]+1)),NULL);
  status=clSetKernelArg(UpBorderColumKernel,3,sizeof(int),(void*) &width);
  status=clSetKernelArg(UpBorderColumKernel,4,sizeof(int),(void*) &height);
  status=clSetKernelArg(UpBorderColumKernel,5,sizeof(int),(void*) &pSrcStepwide);
  status=clSetKernelArg(UpBorderColumKernel,6,sizeof(int),(void*) &pSrcShift);
  status=clSetKernelArg(UpBorderColumKernel,7,sizeof(int),(void*) &downStepwide);
  status=clSetKernelArg(UpBorderColumKernel,8,sizeof(int),(void*) &downShift);

  status=clEnqueueNDRangeKernel(g_queue,UpBorderColumKernel,2,NULL,global_work_size,local_work_size,0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");

#ifdef TIME_PROF
#ifndef EXEC_PAR
  clFinish(g_queue);
#endif
#endif

#ifdef TIME_KERNEL
  gettimeofday(&time2_1,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime1 = (endTime-startTime)/1000;
#endif

  /*------ UpRow------*/
#ifdef TIME_PROF
  gettimeofday(&time3, NULL);
#endif
  global_work_size[0]=width/4;
  global_work_size[1]=2;
  local_work_size[0]=64;
  local_work_size[1]=1;
  cl_kernel UpBorderRowKernel=clCreateKernel(program,"BorderUpRow",&status);
  checkErr(status,"clCreateKernel() for BorderUpRow");
  status=clSetKernelArg(UpBorderRowKernel,0,sizeof(cl_mem),(void*) &yPlaneDownBuffer);
  status=clSetKernelArg(UpBorderRowKernel,1,sizeof(cl_mem),(void*) &yPlaneCSERBuffer);
  status=clSetKernelArg(UpBorderRowKernel,2,(sizeof(unsigned char)*(local_work_size[0]* local_work_size[1]+1)),NULL);
  status=clSetKernelArg(UpBorderRowKernel,3,sizeof(int),(void*) &width);
  status=clSetKernelArg(UpBorderRowKernel,4,sizeof(int),(void*) &height);
  status=clSetKernelArg(UpBorderRowKernel,5,sizeof(int),(void*) &pSrcStepwide);
  status=clSetKernelArg(UpBorderRowKernel,6,sizeof(int),(void*) &pSrcShift);
  status=clSetKernelArg(UpBorderRowKernel,7,sizeof(int),(void*) &downStepwide);
  status=clSetKernelArg(UpBorderRowKernel,8,sizeof(int),(void*) &downShift);

  status=clEnqueueNDRangeKernel(g_queue,UpBorderRowKernel,2,NULL,global_work_size,local_work_size,0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");
#ifdef TIME_PROFKKK
#ifndef EXEC_PAR
  clFinish(g_queue);
#endif
#endif

#ifdef TIME_KERNEL
  gettimeofday(&time3_1, NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime2 = (endTime-startTime)/1000;

#endif


  /*  unsigned char *bordertest=(unsigned char*)malloc(sizeof(unsigned char)*stepwide*(height+4));
      memset(bordertest,0,stepwide*(height+4)*sizeof(unsigned char));
      status=clEnqueueReadBuffer(g_queue,yPlaneCSERBuffer,CL_TRUE,0,stepwide*(height+4),bordertest,0,NULL,NULL);
      for(int i=2;i<height+2;i++)
      {
      for(int j=0;j<width;j++)
      {
  // if(j==0 || j==1 || j==width-2 || j==width-1)
  {
  printf("%d ",bordertest[j+i*stepwide]);
  }
  }
  printf("\n");
  }
   */




  // ------- Up ------

#ifdef TIME_TOTAL
  gettimeofday(&time4,NULL);
#endif

  local_work_size[0]=LOCALSIZE_X;
  local_work_size[1]=LOCALSIZE_Y;
  int boundary_x = width/4; 
  int boundary_y = height/4;
  global_work_size[0]=upMultiple(boundary_x,local_work_size[0])*local_work_size[0];
  global_work_size[1]=upMultiple(boundary_y,local_work_size[1])*local_work_size[1];

  cl_kernel UpScaleKernel=clCreateKernel(program,"UpScale",&status);
  checkErr(status,"clCreateKernel() for UpScaleC16");
  status=clSetKernelArg(UpScaleKernel,0,sizeof(cl_mem),(void *) &yPlaneDownBuffer);
  status|=clSetKernelArg(UpScaleKernel,1,sizeof(cl_mem),(void *) &yPlaneCSERBuffer);
  status|=clSetKernelArg(UpScaleKernel,2,sizeof(int),(void *) &width);
  status|=clSetKernelArg(UpScaleKernel,3,sizeof(int),(void *) &height);
  status|=clSetKernelArg(UpScaleKernel,4,sizeof(int),(void *) &pSrcStepwide);
  status|=clSetKernelArg(UpScaleKernel,5,sizeof(int),(void *) &pSrcShift);
  status|=clSetKernelArg(UpScaleKernel,6,sizeof(int),(void *) &downStepwide);
  status|=clSetKernelArg(UpScaleKernel,7,sizeof(int),(void *) &downShift);
  checkErr(status,"clSetKernelArg of downShift");

  status=clEnqueueNDRangeKernel(g_queue,UpScaleKernel,2,NULL,global_work_size,local_work_size, 0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");

#ifdef TIME_PROF
#ifndef EXEC_PAR
  clFinish(g_queue);
#endif
#endif


#ifdef TIME_PROF
  gettimeofday(&time4_1,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime3 = (endTime-startTime)/1000;
#endif


  /*unsigned char *yPlaneCSER0 = (unsigned char *)malloc(sz0Pad);
    status=clEnqueueReadBuffer(g_queue,yPlaneCSERBuffer,CL_TRUE,0,sz0Pad,yPlaneCSER0,0,NULL,NULL);
    for(int i=2;i<height+2;i++)
    {
    for(int j=0;j<width;j++)
    printf("%d ",yPlaneCSER0[i*stepwide+j]);
    printf("\n");
    }*/

  /********2.Sobel***********************************************/
#ifdef TIME_PROF
  gettimeofday(&time5,NULL);
#endif

  local_work_size[0]=LOCALSIZE_X;
  local_work_size[1]=LOCALSIZE_Y;
  global_work_size[0]=upMultiple((width>>2),local_work_size[0])*local_work_size[0];
  global_work_size[1]=upMultiple(height,local_work_size[1])*local_work_size[1];

  cl_kernel sobelKernel=clCreateKernel(program,"Sobel",&status);
  checkErr(status,"clCreateKernel() for Sobel");

  status=clSetKernelArg(sobelKernel,0,sizeof(cl_mem),(void *) &pad_yPlane0Buffer);
  status=clSetKernelArg(sobelKernel,1,sizeof(cl_mem),(void *) &pEdgeBuffer);
  status=clSetKernelArg(sobelKernel,2,sizeof(int),(void *) &width);
  status=clSetKernelArg(sobelKernel,3,sizeof(int),(void *) &height);
  status=clSetKernelArg(sobelKernel,4,sizeof(int),(void *) &pSrcStepwide);
  status=clSetKernelArg(sobelKernel,5,sizeof(int),(void *) &pSrcShift);
  status=clSetKernelArg(sobelKernel,6,sizeof(int),(void *) &pEdgeStepwide);
  status=clSetKernelArg(sobelKernel,7,sizeof(int),(void *) &pEdgeShift);


  status=clEnqueueNDRangeKernel(g_queue,sobelKernel,2,NULL,global_work_size,local_work_size, 0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");

#ifdef TIME_PROF
#ifndef EXEC_PAR
  clFinish(g_queue);
#endif
#endif



#ifdef TIME_KERNEL 
  gettimeofday(&time5_1,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime4 = (endTime-startTime)/1000;
#endif


  short         *pEdge       = (short *)malloc(szShort);
  status=clEnqueueReadBuffer(g_queue,pEdgeBuffer,CL_TRUE,0,szShort,pEdge,0,NULL,NULL);
#if 0
  for(int i=2;i<height+2;i++)
  {
    for(int j=0;j<width;j++)
      printf("%d ",pEdge[i* pEdgeStepwide/2+j]);
    printf("\n");
  }
#endif
  /********3.mean***********************************************/
  gettimeofday(&time6,NULL);
  short mean;
  local_work_size[0]=MEAN_THREADS_NUMBER_X;
  local_work_size[1]=MEAN_THREADS_NUMBER_Y;
  global_work_size[0]=upMultiple(width,local_work_size[0]*4)*local_work_size[0];
  global_work_size[1]=upMultiple(height,local_work_size[1])*local_work_size[1];

  cl_kernel meanKernel=clCreateKernel(program,"mean",&status);
  checkErr(status,"clCreateKernel() for meanLocalCombine");

  cl_mem pMidEdgeBuffer=clCreateBuffer(g_context,CL_MEM_ALLOC_HOST_PTR,sizeof(unsigned int),NULL,&status);
  checkErr(status,"clCreateBuffer() for pEdgeBuffer");

  const void * local = NULL;
  unsigned int count = width*height >> 2;

  status=clSetKernelArg(meanKernel,0,sizeof(cl_mem),(void *) &pEdgeBuffer);
  status=clSetKernelArg(meanKernel,1,sizeof(cl_mem),(void *) &pMidEdgeBuffer);
  status=clSetKernelArg(meanKernel,2,sizeof(int)*local_work_size[0]*local_work_size[1],(void *) local);
  status=clSetKernelArg(meanKernel,3,sizeof(int),(void *) &width);
  status=clSetKernelArg(meanKernel,4,sizeof(int),(void *) &height);
  status=clSetKernelArg(meanKernel,5,sizeof(int),(void *) &pEdgeStepwide);
  status=clSetKernelArg(meanKernel,6,sizeof(int),(void *) &pEdgeShift);

  uint sum_1 = 0;
  status = clEnqueueWriteBuffer(g_queue, pMidEdgeBuffer, CL_TRUE, 0, sizeof(cl_uint), &sum_1, 0, NULL, NULL);
  status=clEnqueueNDRangeKernel(g_queue,meanKernel,2,NULL,global_work_size,local_work_size, 0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");

#ifdef TIME_PROF
#ifndef EXEC_PAR
  clFinish(g_queue);
#endif
#endif

  status = clEnqueueReadBuffer(g_queue, pMidEdgeBuffer, CL_TRUE, 0, sizeof(cl_uint), &sum_1, 0, NULL, NULL);
  uint temp_1 = (width*height);
  mean = (sum_1 + temp_1/2) / temp_1; 

#ifdef TIME_KERNEL
  gettimeofday(&time6_1,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime5 = (endTime-startTime)/1000;
#endif

  /********4: sharpness****************************************/
  float cutoff=cseParamPublic.cutoffCoef*mean;
  float peak=cseParamPublic.peak;
  float cutoff2=cseParamPublic.cutoff2;
  float order=2;
  float order2=2;
  float strength=1;
  cl_float m=mean;
  m=m*m;
  m=m*m;
  cl_float m1=1.0/mean;
  m1=m1*m1;
  m1=m1*m1;
  cl_float m2=1.0/256.0;
  m2=m2*m2;
  m2=m2*m2;
#ifdef TIME_PROF
  gettimeofday(&time6_1,NULL);
#endif

  local_work_size[0]=LOCALSIZE_X;
  local_work_size[1]=LOCALSIZE_Y;
  global_work_size[0]=upMultiple((width>>2),local_work_size[0])*local_work_size[0];
  global_work_size[1]=upMultiple(height,local_work_size[1])*local_work_size[1];

  cl_kernel SharpnessKernel=clCreateKernel(program,"Sharpness",&status);
  checkErr(status,"clCreatKernel() for sharpnessCL");

  status=clSetKernelArg(SharpnessKernel,0,sizeof(cl_mem),(void *) &yPlaneCSERBuffer);
  status=clSetKernelArg(SharpnessKernel,1,sizeof(cl_mem),(void *) &pad_yPlane0Buffer);
  status=clSetKernelArg(SharpnessKernel,2,sizeof(cl_mem),(void *) &cacheBuffer);
  status=clSetKernelArg(SharpnessKernel,3,sizeof(cl_mem),(void *) &pEdgeBuffer);
  status=clSetKernelArg(SharpnessKernel,4,sizeof(cl_float),(void *) &m);
  status=clSetKernelArg(SharpnessKernel,5,sizeof(float),(void *) &m1);
  status=clSetKernelArg(SharpnessKernel,6,sizeof(float),(void *) &m2);
  status=clSetKernelArg(SharpnessKernel,7,sizeof(int),(void *) &width);
  status=clSetKernelArg(SharpnessKernel,8,sizeof(int),(void *) &height);
  status=clSetKernelArg(SharpnessKernel,9,sizeof(int),(void *) &pSrcStepwide);
  status=clSetKernelArg(SharpnessKernel,10,sizeof(int),(void *) &pSrcShift);
  status=clSetKernelArg(SharpnessKernel,11,sizeof(int),(void *) &pEdgeStepwide);
  status=clSetKernelArg(SharpnessKernel,12,sizeof(int),(void *) &pEdgeShift);



  status=clEnqueueNDRangeKernel(g_queue,SharpnessKernel,2,NULL,global_work_size,local_work_size,0,NULL,&event_kernel);
  checkErr(status,"clEnqueueNDRangeKernel");

  clFinish(g_queue);
  checkErr(status,"clFinish of sharpness");

#ifdef TIME_PROF
  gettimeofday(&time6_1,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelExecTime6 = (endTime-startTime)/1000;
#endif

#ifdef TIME_PROF
  t.down_time=(double)(time1_1.tv_usec-time1.tv_usec)*0.001+(time1_1.tv_sec-time1.tv_sec)*1000;
  t.up_col_time=(double)(time2_1.tv_usec-time2.tv_usec)*0.001+(time2_1.tv_sec-time2.tv_sec)*1000;
  t.up_row_time=(double)(time3_1.tv_usec-time3.tv_usec)*0.001+(time3_1.tv_sec-time3.tv_sec)*1000;
  t.up_time=(double)(time4_1.tv_usec-time4.tv_usec)*0.001+(time4_1.tv_sec-time4.tv_sec)*1000;
  t.sobel_time=(double)(time5_1.tv_usec-time5.tv_usec)*0.001+(time5_1.tv_sec-time5.tv_sec)*1000;
  t.mean_time=(double)(time6_1.tv_usec-time6.tv_usec)*0.001+(time6_1.tv_sec - time6.tv_sec)*1000;
  t.sharp_time=(double)(time7_1.tv_usec-time7.tv_usec)*0.001+(time7_1.tv_sec-time7.tv_sec)*1000;

  t.kernel_down      = (double)(kernelExecTime0*0.001);
  t.kernel_up_col = (double)(kernelExecTime1*0.001);
  t.kernel_up_row        = (double)(kernelExecTime2*0.001);
  t.kernel_up        = (double)(kernelExecTime3*0.001);
  t.kernel_sobel     = (double)(kernelExecTime4*0.001);
  t.kernel_mean      = (double)(kernelExecTime5*0.001);
  t.kernel_sharpness = (double)(kernelExecTime6*0.001);
#endif


  status = clEnqueueReadBuffer(g_queue,cacheBuffer,CL_TRUE,0,sz0Pad,pad_yPlane0,0,NULL,NULL);

  unpad_yPlane(pad_yPlane0,yPlane0,width,height,pSrcStepwide,pSrcShift);

  /* clean openCL resources */
  status=clReleaseCommandQueue(g_queue);
  status=clReleaseProgram(program);
  status=clReleaseContext(g_context);
  //status=clReleaseKernel(downX16Kernel);
  status=clReleaseKernel(UpBorderColumKernel);
  status=clReleaseKernel(UpBorderRowKernel);
  status=clReleaseKernel(UpScaleKernel);
  status=clReleaseKernel(meanKernel);
  status=clReleaseKernel(sobelKernel);
  status=clReleaseKernel(SharpnessKernel);
  status=clReleaseMemObject(cacheBuffer);
  status=clReleaseMemObject(pad_yPlane0Buffer);
  status=clReleaseMemObject(yPlaneCSERBuffer);
  status=clReleaseMemObject(pEdgeBuffer);

#ifdef TIME_PROF
  return t;
#endif
}



void cpu_sharpness(int height, int width, unsigned char * blabla);

int main(int argc,char* argv[])
{
  int height= 512,width= 512;

  for(int count=0; count<=0; count++)
  {
    int picsize=width*height;
    unsigned char *p,*yuvfile = (unsigned char*)malloc(sizeof(unsigned char)*picsize),
                  *dst     = (unsigned char*)malloc(sizeof(unsigned char)*picsize);

    p=yuvfile;
    srand(0);
    for(int i=0;i<picsize;i++)
    {
      *p++=rand()%100+1;
    }

    struct TEST_TIME sum = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    struct TEST_TIME avg = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#ifndef TIME_PROF
    all_Sharpness(yuvfile,height,width,dst);
#endif

#ifdef TIME_PROF
    int testNumber = 20;
    for(int i=0; i<testNumber; i++)
    {
      struct TEST_TIME temp = all_Sharpness(yuvfile,height,width,dst);

#ifdef TIME_TOTAL
      sum.down_time += temp.down_time;
      sum.up_col_time += temp.up_col_time;
      sum.up_row_time += temp.up_row_time;
      sum.up_time += temp.up_time;
      sum.sobel_time += temp.sobel_time;
      sum.mean_time += temp.mean_time;
      sum.sharp_time += temp.sharp_time;
#endif

#ifdef TIME_KERNEL
      sum.kernel_down      += temp.kernel_down;
      sum.kernel_up_col  += temp.kernel_up_col;
      sum.kernel_up_row  += temp.kernel_up_row;
      sum.kernel_up        += temp.kernel_up;
      sum.kernel_sobel     += temp.kernel_sobel;
      sum.kernel_mean      += temp.kernel_mean;
      sum.kernel_sharpness += temp.kernel_sharpness;
#endif
    }
    avg.down_time = sum.down_time/testNumber;
    avg.up_col_time = sum.up_col_time/testNumber;
    avg.up_row_time = sum.up_row_time/testNumber;
    avg.up_time = sum.up_time/testNumber;
    avg.sobel_time = sum.sobel_time/testNumber;
    avg.mean_time = sum.mean_time/testNumber;
    avg.sharp_time = sum.sharp_time/testNumber;
    avg.total_used = sum.total_used/testNumber;
#endif 
    avg.exe_time = sum.exe_time/testNumber;

#ifdef TIME_KERNEL
    avg.kernel_down      = sum.kernel_down/testNumber;
    avg.kernel_up_col  = sum.kernel_up_col/testNumber;
    avg.kernel_up_row  = sum.kernel_up_row/testNumber;
    avg.kernel_up        = sum.kernel_up/testNumber;
    avg.kernel_sobel     = sum.kernel_sobel/testNumber;
    avg.kernel_mean      = sum.kernel_mean/testNumber;
    avg.kernel_sharpness = sum.kernel_sharpness/testNumber;
#endif


#ifdef TIME_PROF
    printf("Input: height = %d Width = %d\n",height,width);
    printf("------Total time(ms)------\ndown = %f\nup_col = %f\nup_row = %f\nup = %f\nsobel = %f\nmean = %f\nsharpness = %f\n",avg.down_time,avg.up_col_time,avg.up_row_time, avg.up_time,avg.sobel_time, avg.mean_time,avg.sharp_time);


    printf("------Kernel time(ms)------\ndown = %f\nupcol = %f\nuprow = %f\nup = %f\nsobel = %f\nmean = %f\nsharpness = %f\n",avg.kernel_down,avg.kernel_up_col,avg.kernel_up_row, avg.kernel_up,avg.kernel_sobel,avg.kernel_mean,avg.kernel_sharpness);
#endif



    //printf("%d %d\n",width,height); 
    unsigned char * cpu_dst = (unsigned char *)malloc(picsize*sizeof(unsigned char));
    cpu_sharpness(height,width,cpu_dst);
    int m;
    for(m=0; m<picsize; m++)
      if(cpu_dst[m] != dst[m])
      {
        printf("the answer is wrong\n\n");
        break;
      }
    if(m == picsize)
      printf("bingo\n\n");



    //printf("\n\n");
    height+=104; 
    width+=104;
  }
}



#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))



float GetStrengthX16(short edge,float cutoff,float order,float peak,float low,float order2,float cutoff2)
{
  float weight=1/(1+pow(edge/cutoff2,2*order2));
  float strength=(peak-low)*(1-1/(1+pow(edge/cutoff,2*order)));
  strength=strength*weight+low;

  return strength;
}	

float GetOSCX16(short edge,float cutoff,float order,float peak,float low)
{
  float cutoff2Order=pow(cutoff,2*order);
  float edge2Order=pow(float(edge),2*order);
  float osc=(peak*cutoff2Order+low*edge2Order)/(cutoff2Order+edge2Order);

  return osc;
}	
void OvershootControlFloatX16(unsigned char *src,short *ySharpen,short *sobelEdge,short meanEdge,int width,int height,MMC_CSE_PARAMETER_PUBLIC *cseParamPublic)
{
  float oscStrength;

  float cutoff=cseParamPublic->cutoff3Coef*meanEdge;
  float order=2;
  float peak=1;
  float low=0.05f;

  unsigned char *pSrc0,*pSrc1,*pSrc2;
  unsigned char *pic;
  int enhanced,maxValue,minValue;
  int size=width*height;
  unsigned char* cache=(unsigned char*)malloc(size);

  pSrc0=src;
  pSrc1=pSrc0+width;
  pSrc2=pSrc1+width;

  pic=cache;

  short* pySharpen=ySharpen;
  short* pEdge=sobelEdge+width;
  //first row
  for(int w=0;w!=width;w++)
  {
    *pic++=(unsigned char)*pySharpen++;
  }


  for(int h=0;h<height-2;h++)
  {
    //第一列不进行osc
    *pic++=(unsigned char)*pySharpen++;
    pEdge++;

    //middle cols
    for(int w=0;w<width-2;w++)
    {
      enhanced=*pySharpen;

      maxValue=MAX2(MAX2(pSrc0[0],pSrc0[1]),pSrc0[2]);
      maxValue=MAX2(maxValue,MAX2(MAX2(pSrc1[0],pSrc1[1]),pSrc1[2]));
      maxValue=MAX2(maxValue,MAX2(MAX2(pSrc2[0],pSrc2[1]),pSrc2[2]));

      minValue=MIN3(pSrc0[0],pSrc0[1],pSrc0[2]);
      minValue=MIN2(minValue,MIN3(pSrc1[0],pSrc1[1],pSrc1[2]));
      minValue=MIN2(minValue,MIN3(pSrc2[0],pSrc2[1],pSrc2[2]));

      oscStrength=GetOSCX16(*pEdge,cutoff,order,peak,low);
      //过冲控制
      if(enhanced>maxValue)
      {
        *pic=MIN2(maxValue+oscStrength*(enhanced-maxValue),255);
      }
      else if(enhanced<minValue)
      {
        *pic=MAX2(0,minValue-(oscStrength*(minValue-enhanced)));
      }
      else
      {
        *pic=MIN2(MAX2(enhanced,0),255);
      }

      pic++;
      pEdge++;
      pySharpen++;
      pSrc0++;
      pSrc1++;
      pSrc2++;
    }

    pSrc0 +=2;
    pSrc1 +=2;
    pSrc2 +=2;

    //最后一列不进行osc
    *pic++=*pySharpen++;
    pEdge++;
  }

  short tmp;
  for(int w=0;w<width;w++)
  {
    tmp=*pySharpen++;

    *pic++=MAX2(0,MIN2(tmp,255));
  }
  for(int i=0;i<size;i++)
  {
    ySharpen[i]=cache[i];
  }
}



void SobelX16(unsigned char *pSrc,short *pEdge,int width,int height,int stride,int edgeStride)
{
  unsigned char *pSrcL0,*pSrcL1,*pSrcL2/*,*pSrcL*/;
  short *pEdgeL;

  int gx,gy;
  int srcPad = stride-width + 2;
  int dstPad = edgeStride - width;
  int edgeV;
  int x, y;

  memset(pEdge, 0, width * sizeof(short));//memset(pDst,0,width );

  pEdgeL = pEdge + (height-1) * edgeStride;

  memset(pEdgeL, 0, width * sizeof(short));//memset(pEdgeL,0,width );

  pSrcL0 = pSrc;
  pSrcL1=pSrcL0 + stride;
  pSrcL2=pSrcL1 + stride;
  pEdgeL=pEdge + edgeStride;
  for(y = 0; y < height-2; y++)
  {
    *pEdgeL++ = 0;
    for(x = 0; x < width-2; x++)
    {
      gx=(pSrcL0[2]+((int)pSrcL1[2]<<1) + pSrcL2[2]) - (pSrcL0[0] + ((int)pSrcL1[0]<<1) + pSrcL2[0]);
      gy=(pSrcL0[0]+((int)pSrcL0[1]<<1) + pSrcL0[2]) - (pSrcL2[0] + ((int)pSrcL2[1]<<1) + pSrcL2[2]);

      edgeV=(abs(gx)+abs(gy));

      *pEdgeL++=edgeV;

      pSrcL0++;
      pSrcL1++;
      pSrcL2++;
    }

    *pEdgeL++=0;

    pSrcL0 +=srcPad;
    pSrcL1 +=srcPad;
    pSrcL2 +=srcPad;
    pEdgeL +=dstPad;
  }

}


short MeanX16(short *pEdge,int width ,int height)
{
  short mean;
  long long sum = 0;
  int size=height*width;
  short* p=pEdge;

  for(int i=0;i!=size;i++)
  {
    sum +=*p++;
  }

  mean=(sum+size/2)/size;

  return mean;
}

void Sharpness(unsigned char** yPlane,unsigned char** yPlaneCSER,short** pError,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic)
{
  short* pEdge=(short*)malloc(width*height*sizeof(short));
  short* pSharpness=(short*)malloc(width*height*sizeof(short));

  SobelX16(yPlane[0],pEdge,width,height,width,width);

  /*  for(int i=0;i<width*height;i++)
      {
      printf("%d ",pEdge[i]);
      }*/

  short mean=MeanX16(pEdge,width,height);
  float cutoff=cseParamPublic->cutoffCoef*mean;
  float peak=cseParamPublic->peak;
  float cutoff2=cseParamPublic->cutoff2;
  struct timeval time1,time2;
  gettimeofday(&time1,NULL);

  float order=2;
  float order2=2;

  float strength=1;
  for(int h=0;h<height;h++)
  {
    for(int w=0;w<width;w++)
    {
      strength=GetStrengthX16(pEdge[h*width+w],cutoff,order,peak,1.0,order2,cutoff2);
      pSharpness[h*width+w]=yPlaneCSER[h][w]+(float)(pError[h][w])*strength;
    }
  }
  //输出存储在pSharpness中
  OvershootControlFloatX16(yPlane[0],pSharpness,pEdge,mean,width,height,cseParamPublic);
  for(int h =0;h<height;h++)
  {
    for(int w=0;w<width;w++)
    {
      if(pSharpness[h*width+w]>255)
      {
        yPlane[h][w]=255;
      }
      else if (pSharpness[h*width+w]<0)
      {
        yPlane[h][w]=0;
      }
      else
        yPlane[h][w]=pSharpness[h*width+w];
      //   printf("%d ",yPlane[h][w]);
    }
  }

  gettimeofday(&time2,NULL);
  double tem=(double)(time2.tv_usec-time1.tv_usec)*0.001+(time2.tv_sec-time1.tv_sec)*1000;
  //printf("CPU used %f ms.\n",tem);


  free(pSharpness);
  free(pEdge);
}

int DownScaleNewX16(unsigned char *pImageSrc,int nHeight, int nWidth, unsigned char *pImageDst)
{
  int i=0,j=0;

  unsigned char *pSrc1=pImageSrc;
  unsigned char*pSrc2=pSrc1+nWidth;
  unsigned char*pSrc3=pSrc2+nWidth;
  unsigned char*pSrc4=pSrc3+nWidth;

  unsigned char *pDst = pImageDst;

  //隔行隔列遍历大图
  for(i=0;i!=nHeight;i +=4)
  {
    for(j=0;j!=nWidth;j +=4)
    {
      //biliner interpolation1
      *pDst=(*pSrc1+*(pSrc1+1)+*(pSrc1+2)+*(pSrc1+3)
          +*pSrc2+*(pSrc2+1)+*(pSrc2+2)+*(pSrc2+3)
          +*pSrc3+*(pSrc3+1)+*(pSrc3+2)+*(pSrc3+3)
          +*pSrc4+*(pSrc4+1)+*(pSrc4+2)+*(pSrc4+3)+8)>>4;

      pDst++;

      pSrc1 += 4;
      pSrc2 += 4;
      pSrc3 += 4;
      pSrc4 += 4;
    }

    pSrc1 += 3*nWidth;
    pSrc2 += 3*nWidth;
    pSrc3 += 3*nWidth;
    pSrc4 += 3*nWidth;
  }

  return 0;
}


int UpScaleNewX16(unsigned char* srcImage,int height,int width ,unsigned char *dstImage)
{
  int h,w;
  int dstWidth=width<<2;
  int dstHeight=height<<2;
  unsigned char* p1=srcImage;
  unsigned char* p2=srcImage+width;

  unsigned char* testpp=dstImage;
  unsigned char* pDst1=dstImage+dstWidth*2+2;
  unsigned char* pDst2=pDst1+dstWidth;
  unsigned char* pDst3=pDst2+dstWidth;
  unsigned char* pDst4=pDst3+dstWidth;

  unsigned char* pTmp1=dstImage;
  unsigned char* pTmp2=dstImage+dstWidth-1;

  /**************************/
  /* 插值法              */
  /**************************/
  pTmp1=dstImage;
  //第一列
  for(int h=0;h<height;h++)
  {
    *pTmp1=srcImage[h*width];
    pTmp1 +=(dstWidth*4);
  }
  pTmp1=dstImage;
  pTmp2=dstImage+dstWidth*4;
  for(int h=0;h<height-1;h++)
  {
    *(pTmp1+dstWidth)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
    *(pTmp1+2*dstWidth)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
    *(pTmp1+3*dstWidth)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;

    pTmp1 +=(dstWidth*4);
    pTmp2 +=(dstWidth*4);
  }
  *(pTmp1+dstWidth)=*pTmp1;

  //第二列
  pTmp1=dstImage;
  for(int h=0;h<dstHeight;h++)
  {
    *(pTmp1+1)=*pTmp1;
    pTmp1 +=dstWidth;
  }

  //第一行
  pTmp1=dstImage;
  for(int w=0;w<width;w++)
  {
    *pTmp1=srcImage[w];
    pTmp1 +=4;
  }
  pTmp1=dstImage;
  pTmp2=dstImage+4;
  for(int w=0;w<width-1;w++)
  {
    *(pTmp1+1)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
    *(pTmp1+2)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
    *(pTmp1+3)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;

    pTmp1 +=4;
    pTmp2 +=4;
  }
  *(pTmp1+1)=*pTmp1;
  //第二行
  pTmp1=dstImage;
  pTmp2=dstImage+dstWidth;
  for(int w=0;w<dstWidth;w++)
  {
    *pTmp2++=*pTmp1++;
  }

  //倒数第二行
  pTmp1=dstImage+(dstHeight-2)*dstWidth;
  for(int w=0;w<width;w++)
  {
    *pTmp1=srcImage[(height-1)*width+w];
    pTmp1+=4;
  }
  pTmp1=dstImage+(dstHeight-2)*dstWidth;
  pTmp2=pTmp1+4;
  for(int w=0;w<width-1;w++)
  {
    *(pTmp1+1)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
    *(pTmp1+2)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
    *(pTmp1+3)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;

    pTmp1 +=4;
    pTmp2 +=4;
  }
  *(pTmp1+1)=*pTmp1;

  //倒数第一行
  pTmp1=dstImage+(dstHeight-2)*dstWidth;
  pTmp2=dstImage+(dstHeight-1)*dstWidth;
  for(int w=0;w<dstWidth;w++)
  {
    *pTmp2++=*pTmp1++;
  }

  //倒数第二列
  pTmp1=dstImage+dstWidth-2;
  for(int h=0;h<height;h++)
  {
    *pTmp1=srcImage[h*width+width-1];
    pTmp1 +=(dstWidth*4);
  }
  pTmp1=dstImage+dstWidth-2;
  pTmp2=pTmp1+dstWidth*4;
  for(int h=0;h<height-1;h++)
  {
    *(pTmp1+dstWidth)=(*pTmp1)*3/4.0+(*pTmp2)*1/4.0;
    *(pTmp1+2*dstWidth)=(*pTmp1)*2/4.0+(*pTmp2)*2/4.0;
    *(pTmp1+3*dstWidth)=(*pTmp1)*1/4.0+(*pTmp2)*3/4.0;

    pTmp1 +=(dstWidth*4);
    pTmp2 +=(dstWidth*4);
  }
  *(pTmp1+dstWidth)=*pTmp1;
  *(pTmp1+2*dstWidth)=*pTmp1;
  *(pTmp1+3*dstWidth)=*pTmp1;

  //倒数第一列
  pTmp1=dstImage+dstWidth-2;
  for(int h=0;h<dstHeight;h++)
  {	
    *(pTmp1+1)=*pTmp1;
    pTmp1 +=dstWidth;
  }
  /*
     for(int i=0;i<width*height*16;i++)
     {
     printf("%d ",testpp[i]);
     if((i+1)%(width*4)==0)
     printf("\n");
     }
   */
  //主体
  for(h=0;h<height-1;h++)
  {
    for(w=0;w<width-1;w++)
    {
      *pDst1=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(7/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(1/8.0);
      *(pDst1+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(7/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(1/8.0);
      *(pDst1+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(7/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(1/8.0);
      *(pDst1+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(7/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(1/8.0);

      *pDst2=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(5/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(3/8.0);
      *(pDst2+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(5/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(3/8.0);
      *(pDst2+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(5/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(3/8.0);
      *(pDst2+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(5/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(3/8.0);

      *pDst3=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(3/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(5/8.0);
      *(pDst3+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(3/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(5/8.0);
      *(pDst3+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(3/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(5/8.0);
      *(pDst3+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(3/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(5/8.0);

      *pDst4=((*p1)*(7/8.0)+(*(p1+1))*(1/8.0))*(1/8.0)+((*p2)*(7/8.0)+(*(p2+1))*(1/8.0))*(7/8.0);
      *(pDst4+1)=((*p1)*(5/8.0)+(*(p1+1))*(3/8.0))*(1/8.0)+((*p2)*(5/8.0)+(*(p2+1))*(3/8.0))*(7/8.0);
      *(pDst4+2)=((*p1)*(3/8.0)+(*(p1+1))*(5/8.0))*(1/8.0)+((*p2)*(3/8.0)+(*(p2+1))*(5/8.0))*(7/8.0);
      *(pDst4+3)=((*p1)*(1/8.0)+(*(p1+1))*(7/8.0))*(1/8.0)+((*p2)*(1/8.0)+(*(p2+1))*(7/8.0))*(7/8.0);

      p1++;
      p2++;

      pDst1 += 4;
      pDst2 += 4;
      pDst3 += 4;
      pDst4 += 4;
    }
    p1++;
    p2++;

    pDst1 = pDst1 + 3*dstWidth + 4;
    pDst2 = pDst2 + 3*dstWidth + 4;
    pDst3 = pDst3 + 3*dstWidth + 4;
    pDst4 = pDst4 + 3*dstWidth + 4;

  }
  /*
     for(int i=0;i<width*height*16;i++)
     {
     printf("%d ",testpp[i]);
     if((i+1)%(width*4)==0)
     printf("\n");
     }
   */
  return 0;
}









inline unsigned char** allocu(int r,int c)
{
  unsigned char *a ,**p;
  int padding=10;
  a=(unsigned char*)malloc(sizeof(unsigned char)*(r*c+padding));
  if(a==NULL)
    exit(0);

  p=(unsigned char**)malloc(sizeof(unsigned char*)*r);
  for(int i=0;i<r;i++)
    p[i]=&a[i*c];

  return(p);
}



inline short** allocs(int r,int c ,int padding=10)
{
  short *a,**p;
  a=(short*)malloc(sizeof(short)*(r*c+padding));
  if(a==NULL)
  {
    printf("allocs() fail,Memory is too huge,fail.\n");
    getchar();
    exit(0);
  }

  p=(short**)malloc(sizeof(short*)*r);
  for(int i=0;i<r;i++)
    p[i]=&a[i*c];
  return(p);
}











void cpu_sharpness(int height, int width, unsigned char * blabla)
{
  unsigned long start,end;
  unsigned char *yuvfile=(unsigned char*)malloc(sizeof(unsigned char)*width*height);
  memset(yuvfile,0,width*height*sizeof(unsigned char));
  unsigned char *p,*q;
  p=yuvfile;
  q=yuvfile;
  srand(0);
  for(int i=0;i<width*height;i++)
  {
    *p++=rand()%100+1;
  }

  struct timeval time1,time2;
  gettimeofday(&time1,NULL);

  char output_file[128];
  MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
  int  quarterWidth=width/4;
  int quarterHeight=height/4;

  cseParamPublic.cutoff2=256.0f;
  cseParamPublic.cutoff3Coef=1.0f;
  cseParamPublic.cutoffCoef=1.0f;
  cseParamPublic.peak=2.0f;



  unsigned char **yPlane=allocu(height,width);
  unsigned char** yPlaneCSE=allocu(quarterHeight,quarterWidth);
  unsigned char **yPlaneCSER=allocu(height,width);
  unsigned char** yPlaneDown=allocu(quarterHeight,quarterWidth);
  short** pError=allocs(height,width);

  /*读取YUV图片，只使用Y分量*/
  unsigned char *qqq=yuvfile;
  for(int i=0;i<height;i++)
  {
    yPlane[i]=qqq;
    qqq=qqq+width;
  }



  /*下采样*/
  DownScaleNewX16(yPlane[0],height,width,yPlaneDown[0]);

  /*计算误差*/
  UpScaleNewX16(yPlaneDown[0],quarterHeight,quarterWidth,yPlaneCSER[0]);

  for(int h=0;h<height;h++)
  {
    for(int w=0;w<width;w++)
    {
      pError[h][w]=yPlane[h][w]-yPlaneCSER[h][w];
    }		
  }

  Sharpness(yPlane,yPlaneCSER,pError,width,height,&cseParamPublic);

  gettimeofday(&time2,NULL);

  /*double tem=(double)(time2.tv_usec-time1.tv_usec)*0.001+(time2.tv_sec-time1.tv_sec)*1000;
    printf("%f ms.\n",tem);
   */

  //unsigned char *blabla=(unsigned char*)malloc(sizeof(unsigned char)*width*height);
  memset(blabla,0,width*height*sizeof(unsigned char));
  for(int i=0; i<width*height; i++)
    blabla[i] = yuvfile[i];

  /* 
     printf("out: \n");
     for(int i=0;i<height*width;i++)
     {
  //for(int j=0;j<width;j++)
  {
  if(*blabla<10)
  printf("%d   ",*blabla);
  else if (*blabla<100)
  printf("%d  ",*blabla);
  else
  printf("%d ",*blabla);
  blabla++;
  }
  if((i+1)%24==0)
  printf("\n");
  }
  printf("\n");
   */

  /*dump 结果到文件上*/
  /*	memset(output_file,0,sizeof(output_file));
      strcpy(output_file,yuvfile);
      strcpy(output_file+strlen(output_file)-4,"_out_cpu.y");
      dump_to_file(output_file,yPlane[0],width*height);
   */
  //	freeu(yPlane);
  freeu(yPlaneCSE);
  freeu(yPlaneCSER);
  freeu(yPlaneDown);
  frees(pError);
  free(yuvfile);

  return ;
}
