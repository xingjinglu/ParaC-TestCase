#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<CL/cl.h>
#include<sys/time.h>
#include <iostream>

struct timeval start_cpu[10];
struct timeval end_cpu[10];

#define PADDING 32
#define SIZEM 256
#define SIZEN 1
#define DIFFTIME(s,e) ((double)(((e).tv_sec)-((s).tv_sec))*1000+(double)(((e).tv_usec)-((s).tv_usec))/1000)

#define LOCALSIZE_X 256
#define LOCALSIZE_y 1

//#define TIME_PAR

#ifdef TIME_PAR
#define TIMEDAY_PAR
#define KERNEL_PAR
//#define EXE_PAR
#endif


#define error_len    1024
char BufferError[error_len];
cl_context g_context;
cl_command_queue g_queue;
cl_program g_program;


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

int openCLCreate(cl_context* context,cl_command_queue* queue,const char* inputfile,char * remain)
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
	

	g_program=clCreateProgramWithSource(g_context,1,(const char**)&program_source,NULL,&status);
	checkErr(status,"clCreateProgramWithSource");

	status=clBuildProgram(g_program,1,&device[1],remain,NULL,NULL);

  if(status !=CL_SUCCESS)
	{
		printf("Error: build kernel fails\n");
		size_t len;
		clGetProgramBuildInfo(g_program,*device,CL_PROGRAM_BUILD_LOG,sizeof(BufferError),BufferError,&len);
		BufferError[len]='\0';
		printf("%s",BufferError);
		checkErr(status,"clBuildProgram");
		getchar();
		return -1;
	}
	
	return 0;
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

void pad_yPlane(unsigned char* pSrc,unsigned char* pDst,int width,int height,int stepwide,int shift)
{
  for(int i=0;i<height;i++)
      for(int j=0;j<width;j++)
          pDst[i*stepwide+j+shift]=pSrc[i*width+j];
}

void unpad_yPlane(short* pSrc,short* pDst,int width,int height,int stepwide,int shift)
{
	for(int i=0;i<height;i++)
      for(int j=0;j<width;j++)
          pDst[i*width+j]=*(signed short *)((unsigned char*)pSrc+stepwide*i+shift +j*2);
}



struct TEST_TIME{
  double exe_time;  
  double time_filter_h;
  double time_down;
  double time_up;
  double time_kernel_filter_h;
  double time_kernel_down;
  double time_kernel_up;
};

#ifdef TIME_PAR
TEST_TIME laplacian(unsigned char *pSrc, signed short *pLaplacianPyramid,
                                   int width, int height,int remainder,int remainder8)
#else
static void laplacian(unsigned char *pSrc, signed short *pLaplacianPyramid,int width, int height,int remainder,int remainder8)
#endif
{

#ifdef TIME_PAR
    struct timeval time_h0,time_h1,time_d0,time_d1,time_up0,time_up1,time0,time1;
    cl_ulong startTime,endTime,kernelTimeH,kernelTimeD,kernelTimeUp;
    struct TEST_TIME t;
#endif
    
  int oddx = width%2;
  int oddy = height%2;

	const char* inputfile="laplacian.cl";

  char* remain=(char *)malloc(60*sizeof(char));
  sprintf(remain,"-D VALUE=%d -D VALUEE=%d -D ODDX=%d -D ODDY=%d",remainder,remainder8,oddx,oddy);

	if(-1==openCLCreate(&g_context,&g_queue,inputfile,remain))
	{
		printf("openCL create fail !!!!!!!\n");
	}

  int halfwidth = (width + 1)>>1;
  int halfheight = (height + 1)>>1;
  
  int stepwide,shift;
  stepwide = width*sizeof(unsigned char);
  stepwide = (stepwide%PADDING < 16) ? ((stepwide/PADDING+1)*PADDING) : ((stepwide+PADDING)/PADDING+1)*PADDING;
 

  int stepwideShort,shiftShort;
  stepwideShort = width*sizeof(short);
  stepwideShort = (stepwideShort%PADDING < 16) ? ((stepwideShort/PADDING+1)*PADDING) : ((stepwideShort+PADDING)/PADDING+1)*PADDING;
 
  int downstepwide,downshift;
  downstepwide =halfwidth*sizeof(unsigned char);
  downstepwide =(downstepwide%PADDING <16) ? ((downstepwide/PADDING+1)*PADDING) : ((downstepwide+PADDING)/PADDING+1)*PADDING;
         
  size_t szPad=stepwide*(height+4);
  size_t szShort=stepwideShort*(height+4);
  size_t szdown=downstepwide*(halfheight+4);

  shift    = stepwide << 1;
  shiftShort = stepwideShort<<1;
	downshift = downstepwide << 1;

/******* kernel_1: PyramidFilter_padding *************/
   cl_event event_kernel;
   cl_int status;

   unsigned char* pSrc_padding = new unsigned char[stepwide*(height+4)];
   short * Dst_padding = new short[(stepwideShort>>1)*(height+4)];
   memset(pSrc_padding, 0,szPad);
   pad_yPlane(pSrc,pSrc_padding,width,height,stepwide,shift);
 
#ifdef EXE_PAR
   gettimeofday(&time0,NULL);
#endif

  
   cl_mem buffer_pSrc_pad = clCreateBuffer(g_context,CL_MEM_READ_WRITE,szPad,NULL, &status);
   checkErr(status, "clCreateBuffer()");			
   cl_mem buffer_pBufL = clCreateBuffer(g_context, CL_MEM_READ_WRITE,szPad,NULL, &status);
   checkErr(status, "clCreateBuffer()");	     	
	 cl_mem buffer_pLaplacianPyramid = clCreateBuffer(g_context,CL_MEM_READ_WRITE,szShort,NULL,&status);
	 checkErr(status,"clCreateBuffer()");	
   cl_mem buffer_pDownsampleBuf = clCreateBuffer(g_context,CL_MEM_READ_WRITE,szdown,NULL,&status);
	 checkErr(status,"clCreateBuffer()");
	
	 status=clEnqueueWriteBuffer(g_queue,buffer_pSrc_pad,CL_TRUE,0,szPad,pSrc_padding,0,NULL,NULL);	
   /********1**************************************/

#ifdef TIMEDAY_PAR
   gettimeofday(&time_h0,NULL);
#endif

   int upwidth= (width%4==0) ? (width/4) : (width/4+1);
   size_t local_size[]={LOCALSIZE_X,LOCALSIZE_y};
   int globalx= (upwidth%LOCALSIZE_X==0) ? upwidth : (upwidth/LOCALSIZE_X+1)*LOCALSIZE_X;
   int globaly= (height%LOCALSIZE_y==0) ? height : (height/LOCALSIZE_y+1)*LOCALSIZE_y;


   size_t global_size0[]={globalx,globaly};
	
	cl_kernel kernel_filter_padding = clCreateKernel(g_program,"PyramidFilter_padding",&status);
	checkErr(status,"clCreateKernel()");
   
		
  status = clSetKernelArg(kernel_filter_padding,0, sizeof(cl_mem),(void*)&buffer_pSrc_pad);
  status = clSetKernelArg(kernel_filter_padding,1, sizeof(cl_mem),(void*)&buffer_pBufL);
	checkErr(status,"clSetKernelArg()");
  status = clSetKernelArg(kernel_filter_padding,2, sizeof(int),(void*)&stepwide);
	checkErr(status,"clSetKernelArg()");
	status = clSetKernelArg(kernel_filter_padding,3, sizeof(int),(void*)&shift);
	checkErr(status,"clSetKernelArg()");
  status = clSetKernelArg(kernel_filter_padding,4, sizeof(int),(void*)&width);
	checkErr(status,"clSetKernelArg()");
	status = clSetKernelArg(kernel_filter_padding,5, sizeof(int),(void*)&height);
	checkErr(status,"clSetKernelArg()");


	status = clEnqueueNDRangeKernel(g_queue,kernel_filter_padding, 2,NULL,global_size0,local_size,0,NULL,&event_kernel);

	checkErr(status,"clEnqueueNDRangeKernel()");
#ifndef EXE_PAR
  clFinish(g_queue);
#endif

#ifdef TIMEDAY_PAR
  gettimeofday(&time_h1,NULL);
#endif

#ifdef KERNEL_PAR
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelTimeH = (endTime-startTime)/1000;
#endif
 
 /******** kernel_2: VerticalFilterDownSample***********************/
  
  int upheight = (halfheight%4==0) ? (halfheight/4) : (halfheight/4+1);
  globalx = (halfwidth%LOCALSIZE_X==0) ? halfwidth : (halfwidth/LOCALSIZE_X+1)*LOCALSIZE_X;
  globaly = (upheight%LOCALSIZE_y==0) ? upheight : (upheight/LOCALSIZE_y+1)*LOCALSIZE_y;
  size_t global_size2[]={globalx,globaly}; 
  
#ifdef TIMEDAY_PAR
   gettimeofday(&time_d0,NULL);
#endif

  cl_kernel kernel_filter_v_downsample = clCreateKernel(g_program ,"PyramidFilter_vertical_downsample",&status);
		checkErr(status,"clCreateKernel()");
  status |=clSetKernelArg(kernel_filter_v_downsample,0,sizeof(cl_mem),(void*)&buffer_pBufL);
	checkErr(status,"clSetKernelArg()");
	status |=clSetKernelArg(kernel_filter_v_downsample,1,sizeof(cl_mem),(void*)&buffer_pDownsampleBuf);
	checkErr(status,"clSetKernelArg()");
  status |= clSetKernelArg(kernel_filter_v_downsample,2,sizeof(int),(void*)&stepwide);
  status |= clSetKernelArg(kernel_filter_v_downsample,3,sizeof(int),(void*)&shift);
  status |= clSetKernelArg(kernel_filter_v_downsample,4,sizeof(int),(void*)&downstepwide);
  status |= clSetKernelArg(kernel_filter_v_downsample,5,sizeof(int),(void*)&downshift);
  status |= clSetKernelArg(kernel_filter_v_downsample,6,sizeof(int),(void*)&halfwidth);
  status |= clSetKernelArg(kernel_filter_v_downsample,7,sizeof(int),(void*)&halfheight);
  status |=clEnqueueNDRangeKernel(g_queue,kernel_filter_v_downsample,2,NULL,global_size2,local_size,0,NULL,&event_kernel);
	checkErr(status,"clEnqueueNDRangeKernel()");

#ifndef EXE_PAR
   clFinish(g_queue);
#endif
 
#ifdef TIMEDAY_PAR
  gettimeofday(&time_d1,NULL);
#endif

#ifdef KERNEL_PAR
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelTimeD = (endTime-startTime)/1000;
#endif
	
   /********kernel_3: UpSample *********************/
 
  globalx = (halfwidth%LOCALSIZE_X==0) ? halfwidth : (halfwidth/LOCALSIZE_X+1)*LOCALSIZE_X;
  globaly = (halfheight%LOCALSIZE_y==0) ? halfheight : (halfheight/LOCALSIZE_y+1)*LOCALSIZE_y;
  size_t global_size3[]={globalx,globaly-1};

#ifdef TIMEDAY_PAR
   gettimeofday(&time_up0,NULL);
#endif

   cl_kernel kernel_upsample=clCreateKernel(g_program,"Upsample",&status);
   checkErr(status,"clCreateKernel()");
   status |= clSetKernelArg(kernel_upsample,0,sizeof(cl_mem),(void*)&buffer_pSrc_pad);
   status |= clSetKernelArg(kernel_upsample,1,sizeof(cl_mem),(void*)&buffer_pDownsampleBuf);
   status |= clSetKernelArg(kernel_upsample,2,sizeof(cl_mem),(void*)&buffer_pLaplacianPyramid);
   status |= clSetKernelArg(kernel_upsample,3,sizeof(int),(void*)&stepwide);
   status |= clSetKernelArg(kernel_upsample,4,sizeof(int),(void*)&shift);
   status |= clSetKernelArg(kernel_upsample,5,sizeof(int),(void*)&stepwideShort);
   status |= clSetKernelArg(kernel_upsample,6,sizeof(int),(void*)&shiftShort);
   status |= clSetKernelArg(kernel_upsample,7,sizeof(int),(void*)&downstepwide);
   status |= clSetKernelArg(kernel_upsample,8,sizeof(int),(void*)&downshift);
   status |= clSetKernelArg(kernel_upsample,9,sizeof(int),(void*)&halfwidth);
   status |= clSetKernelArg(kernel_upsample,10,sizeof(int),(void*)&halfheight);

   status = clEnqueueNDRangeKernel(g_queue,kernel_upsample,2,NULL,global_size3,local_size,0,NULL,&event_kernel);
   checkErr(status,"clEnqueueNDRangeKernel()");
#ifndef EXE_PAR  
   clFinish(g_queue);
#endif
#ifdef TIMEDAY_PAR
  gettimeofday(&time_up1,NULL);
#endif

#ifdef KERNEL_PAR
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_START,sizeof(cl_ulong),&startTime,NULL);
  clGetEventProfilingInfo(event_kernel,CL_PROFILING_COMMAND_END,sizeof(cl_ulong),&endTime,NULL);
  kernelTimeUp = (endTime-startTime)/1000;
#endif

   status=clEnqueueReadBuffer(g_queue,buffer_pLaplacianPyramid,CL_TRUE,0,szShort,Dst_padding,0,NULL,NULL);

 	/********End********************************************/
  unpad_yPlane(Dst_padding,pLaplacianPyramid,width,height,stepwideShort,shiftShort);
  
#ifdef EXE_PAR
   gettimeofday(&time1,NULL);

   t.exe_time=(double)(time1.tv_usec-time0.tv_usec)*0.001+(time1.tv_sec-time0.tv_sec)*1000;
#endif

#ifdef TIMEDAY_PAR
   t.time_filter_h=(double)(time_h1.tv_usec-time_h0.tv_usec)*0.001+(time_h1.tv_sec-time_h0.tv_sec)*1000;
   t.time_down=(double)(time_d1.tv_usec-time_d0.tv_usec)*0.001+(time_d1.tv_sec-time_d0.tv_sec)*1000;
   t.time_up=(double)(time_up1.tv_usec-time_up0.tv_usec)*0.001+(time_up1.tv_sec-time_up0.tv_sec)*1000;
#endif

#ifdef KERNEL_PAR
  t.time_kernel_filter_h = (double)(kernelTimeH*0.001);
  t.time_kernel_down = (double)(kernelTimeD*0.001);
  t.time_kernel_up = (double)(kernelTimeUp*0.001);
#endif



	/* clean openCL resources */
  
	clReleaseProgram(g_program);
	clReleaseCommandQueue(g_queue);
	clReleaseContext(g_context);

  clReleaseKernel(kernel_filter_padding);
	clReleaseKernel(kernel_filter_v_downsample);
  clReleaseKernel(kernel_upsample);
  clReleaseMemObject(buffer_pSrc_pad);
  clReleaseMemObject(buffer_pBufL);
  clReleaseMemObject(buffer_pLaplacianPyramid);
  clReleaseMemObject(buffer_pDownsampleBuf);
  
#ifdef TIME_PAR
  return t;
#endif
}


int main(int argc,char* argv[])
{
    int height=256,width=256;
    
    for(int count=0; count<=6; count++)
    {
        int picsize=width*height;
        unsigned char *p,*Source = (unsigned char*)malloc(sizeof(unsigned char)*picsize);

        p=Source;
        srand(0);
        for(int i=0;i<picsize;i++)
        {
            *p++=rand()%100+1;
        }

        signed short * LaplacianLayer = new signed short[width * height];
 
        int remainder=width%4;
        int remainder8=height%8;

        struct TEST_TIME sum = {0,0,0,0,0,0,0};
        struct TEST_TIME avg;

        laplacian(Source,LaplacianLayer,width,height,remainder,remainder8);
#ifndef TIME_PAR
        printf("%d %d \nbingo\n\n",height,width);
#endif

#ifdef TIME_PAR
        int testNumber = 1;
        for(int i=0; i<testNumber;i++)
        {
            struct TEST_TIME temp = laplacian(Source,LaplacianLayer,width,height,remainder,remainder8);

#ifdef TIMEDAY_PAR
            sum.time_filter_h += temp.time_filter_h;
            sum.time_down += temp.time_down;
            sum.time_up += temp.time_up;
#endif

#ifdef EXE_PAR
            sum.exe_time += temp.exe_time;
#endif

#ifdef KERNEL_PAR
            sum.time_kernel_filter_h += temp.time_kernel_filter_h;
            sum.time_kernel_down +=temp.time_kernel_down;
            sum.time_kernel_up += temp.time_kernel_up;
#endif
        }

#ifdef TIMEDAY_PAR
        avg.time_filter_h=sum.time_filter_h/testNumber;
        avg.time_down=sum.time_down/testNumber;
        avg.time_up = sum.time_up/testNumber;
#endif

#ifdef EXE_PAR
        avg.exe_time = sum.exe_time/testNumber;
#endif

#ifdef KERNEL_PAR
        avg.time_kernel_filter_h =sum.time_kernel_filter_h/testNumber;
        avg.time_kernel_down = sum.time_kernel_down/testNumber;
        avg.time_kernel_up = sum.time_kernel_up/testNumber;
#endif

        printf("round%d: %d %d\n",count,height,width);

#ifdef TIMEDAY_PAR
        printf("gettimeofday:\nhost_filter_h=%f\nhost_down=%f\nhost_up%f\n",avg.time_filter_h,avg.time_down,avg.time_up);
#endif

#ifdef EXE_PAR
        printf("exetime:\nexe = %f\n",avg.exe_time);
#endif

#ifdef KERNEL_PAR
        printf("kerneltime:\n kernel_fitler_h = %f\nkernel_down = %f\nkernel_up = %f\n\n",avg.time_kernel_filter_h,avg.time_kernel_down,avg.time_kernel_up);
#endif

#endif

        height*=2; 
        width*=2;
    }
}
