/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdlib.h>

//#define ROWS 1024
//#define COLS 1024
//#define M 1024
//#define N 1024
#define RUNS 1

#define MIN2(a,b)  ((a)<(b) ? (a):(b))
#define MAX2(a,b)  ((a)>(b) ? (a):(b))
#define MAX3(a,b,c)   (MAX2((a),MAX2((b),(c))))
#define MIN3(a,b,c)   (MIN2((a),MIN2((b),(c))))

 struct timeval t11,t12;
#ifdef TIME_PROF
 double tem, tem1;
 ulong startTime, endTime;
#endif

#pragma OPENCL EXTENSION cl_amd_printf : enable

struct TEST_TIME{
  double env_init_time;
  double buffer_init_time;
  double down_time;
  double up_CPU_time;
  double up_GPU_time;
  double up_row_time;
  double up_col_time;
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

#ifdef TIME_PROF
  struct TEST_TIME total, kernel;
#endif

struct __MMC_CSE_PARAMETER_PUBLIC {
  float peak;
  float cutoffCoef;
  float cutoff2;
  float cutoff3Coef;
  float low;
};
typedef struct __MMC_CSE_PARAMETER_PUBLIC MMC_CSE_PARAMETER_PUBLIC;

int DownScaleNewX16_cpu(unsigned char** pImageSrc,int height, int width, unsigned char** pImageDst)
{
  unsigned char *p=pImageSrc[0],*p1=pImageSrc[1],*p2=pImageSrc[2],*p3=pImageSrc[3];
  unsigned char *d=pImageDst[0];

  for(int j=0;j<height;j++)
  {
      for(int i=0;i<width;i++)
      {
          *d=(*(p)+*(p+1)+*(p+2)+*(p+3)+
                           *(p1)+*(p1+1)+*(p1+2)+*(p1+3)+
                           *(p2)+*(p2+1)+*(p2+2)+*(p2+3)+
                           *(p3)+*(p3+1)+*(p3+2)+*(p3+3)+8)>>4;
          d++;
          p+=4;
          p1+=4;
          p2+=4;
          p3+=4;
      }

      p +=3*width*4;
      p1+=3*width*4;
      p2+=3*width*4;
      p3+=3*width*4;

  } 

	return 0;
}

inline unsigned char** allocu(int r,int c)
{
	unsigned char *a ,**p;
	int padding=0;
	a=(unsigned char*)malloc(sizeof(unsigned char)*(r*c+padding));
	if(a==NULL)
		exit(0);
		
		p=(unsigned char**)malloc(sizeof(unsigned char*)*r);
		for(int i=0;i<r;i++)
			p[i]=&a[i*c];
			
			return(p);
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



//M is height, N is width
int DownScaleNewX16(int height, int width, unsigned char *pImageSrc1, unsigned char *pImageDst1) 
{

  unsigned char (*pImageSrc)[height][width] = (unsigned char(*)[height][width])(pImageSrc1);
  unsigned char (*pImageDst)[height / 4][width / 4] = (unsigned char(*)[height/4][width/4])(pImageDst1);

  unsigned char **yPlane=allocu(height,width);
  unsigned char **yPlaneDown=allocu(height/4,width/4);

  // Verify correctness. 
#ifdef _VERIFY
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      yPlane[i][j]=((unsigned char*)pImageSrc)[i*width+j];
  DownScaleNewX16_cpu(yPlane, height/4, width/4,  yPlaneDown);
#endif


  {
#ifdef TIME_PROF
    tem = 0, tem1 = 0;;
#endif
    for(int q = 0; q< RUNS; q++)
    {
      size_t pImageSrcSrcWidth = width;
      size_t pImageSrcSrcHeight = height;
      size_t pImageSrc_srcsz = sizeof(unsigned char);
      size_t pImageSrcSrcStep = pImageSrcSrcWidth * pImageSrc_srcsz;
      pImageSrcSrcStep = (pImageSrcSrcStep % PADDING < 16) ? ((pImageSrcSrcStep / PADDING+1) * PADDING) : ((pImageSrcSrcStep + PADDING) / PADDING+1) * PADDING;
      size_t pImageSrcSrcShift = pImageSrcSrcStep * PADDING_LINE;
      size_t pImageSrc_srcsz0Pad = pImageSrcSrcStep * (pImageSrcSrcHeight + (PADDING_LINE<<1));

      unsigned char *pImageSrcSrcBufH = (unsigned char*)malloc(pImageSrc_srcsz0Pad); 
      //------ Padding time--------
#ifdef TIME_PROF
      //gettimeofday(&time0,NULL);
#endif
      for(int i = 0; i < pImageSrcSrcHeight; i++){
        memcpy( (char*)pImageSrcSrcBufH+ (i + PADDING_LINE) * pImageSrcSrcStep, (char*)pImageSrc+ i * pImageSrcSrcWidth* sizeof(unsigned char), pImageSrcSrcWidth * sizeof(unsigned char) );
      }
#ifdef TIME_PROF
      //gettimeofday(&time0_1,NULL);
#endif

      cl_mem pImageSrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pImageSrc_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      status = clEnqueueWriteBuffer(g_queue, pImageSrcsrcBuf, CL_TRUE, 0,pImageSrc_srcsz0Pad,pImageSrcSrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

#ifdef TIME_PROF
      //gettimeofday(&time1,NULL); // buffer_init = time1 - time0_1;
#endif

      /*--------------- Downscale time.-----------------*/
      size_t global_work_size[2];
      cl_event event_kernel;
      cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
      checkErr(status, "clCreateKernel for kernel_1");
      //global_work_size[0] = 256;
      //global_work_size[1] = 256;
      global_work_size[0] = width/4;
      global_work_size[1] = height/4;

      size_t local_work_size[2];
      local_work_size[0] = 16;
      local_work_size[1] = 4;

      status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&pImageSrcsrcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&pImageSrcSrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&pImageSrcSrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&pImageSrcSrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&pImageSrcSrcShift);
      checkErr(status, "clSetKernelArg");
      size_t pImageDstDstWidth = width/4;
      size_t pImageDstDstHeight = height/4;
      size_t pImageDst_dstsz = sizeof(unsigned char);
      size_t Readsize = pImageDstDstWidth * pImageDstDstHeight * pImageDst_dstsz;
#if 0  // padding off.
      size_t pImageDstDstStep = pImageDstDstWidth * pImageDst_dstsz;
      size_t pImageDstDstShift = 0;
      size_t pImageDst_dstsz0Pad = pImageDstDstStep * pImageDstDstHeight;
#endif
#if 1  // padding on.
      size_t pImageDstDstStep = pImageDstDstWidth * pImageDst_dstsz;
      pImageDstDstStep = (pImageDstDstStep % PADDING < 16) ? ((pImageDstDstStep / PADDING+1) * PADDING) : ((pImageDstDstStep + PADDING) / PADDING+1) * PADDING;
      size_t pImageDstDstShift = pImageDstDstStep * PADDING_LINE;
      size_t pImageDst_dstsz0Pad = pImageDstDstStep * (pImageDstDstHeight + (PADDING_LINE<<1));
#endif

      cl_mem pImageDstdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, pImageDst_dstsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");


#if 1 // padding on, not need.
      unsigned char *pImageDstDstBufH = (unsigned char*)malloc(pImageDst_dstsz0Pad); 
      for(int i = 0; i < pImageDstDstHeight; i++){
        memcpy( (char*)pImageDstDstBufH+ (i + PADDING_LINE) * pImageDstDstStep,(char*)pImageDst + i * pImageDstDstWidth* sizeof(unsigned char),pImageDstDstWidth* sizeof(unsigned char) );
      }
#endif
      status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&pImageDstdstBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&pImageDstDstWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&pImageDstDstHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&pImageDstDstStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&pImageDstDstShift);
      checkErr(status, "clSetKernelArg");
      //status = clSetKernelArg(kernel_1, 10, sizeof(unsigned int) * local_work_size[0] * local_work_size[1], NULL);
      //checkErr(status, "clSetKernelArg");


      status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
      checkErr(status, "clEnqueueNDRangeKernel of kernel_1");
      status = clFinish(g_queue);
      checkErr(status,"clFinish of kernel_1");

#ifdef TIME_PROF
      gettimeofday(&t12,NULL);
      tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
      tem1 += (endTime - startTime)/1000.0;
#endif

      // Tobe opt.
#if 0 // pading off
      status = clEnqueueReadBuffer(g_queue, pImageDstdstBuf, CL_TRUE, 0,pImageDst_dstsz0Pad,pImageDstDstBufH, 0, NULL, NULL);
      checkErr(status,"clEnqueueReadBuffer");
      for(int i = 0; i < pImageDstDstHeight; i++){
        memcpy( (char*)pImageDst+ i *pImageDstDstWidth* sizeof(unsigned char),(char*) pImageDstDstBufH+ i  * pImageDstDstStep,pImageDstDstWidth* sizeof(unsigned char) );
      }
#endif

#if 1 // Padding on.
      status = clEnqueueReadBuffer(g_queue, pImageDstdstBuf, CL_TRUE, 0,pImageDst_dstsz0Pad,pImageDstDstBufH, 0, NULL, NULL);
      checkErr(status,"clEnqueueReadBuffer");
      for(int i = 0; i < pImageDstDstHeight; i++){
        memcpy( (char*)pImageDst+ i *pImageDstDstWidth* sizeof(unsigned char),(char*) pImageDstDstBufH+ (i + PADDING_LINE)* pImageDstDstStep,pImageDstDstWidth* sizeof(unsigned char) );
      }
#endif
    }

  }

#if TIME_PROF
  total.down_time = tem / RUNS;
  total.kernel_down = double(tem1 / (1000.0*RUNS));
  //printf("Total: Down = %f ms\n",tem/20);
#endif

#ifdef _VERIFY
  // Correctness verify.
  for(int i = 0; i < (height/4); i++)
  {
    for(int j = 0; j < (width/4); j++)
    {
      if(yPlaneDown[i][j] !=((unsigned char*) pImageDst)[i* (width/4) +j])
      {
        printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneDown[i][j], (int)(((unsigned char*) pImageDst)[i* (width/4) +j]));
        abort();

      }
    }
    //printf("\n");

  }
  printf("down success\n");
#endif

}


inline short** allocs(int r,int c ,int padding=0)
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

inline void frees(short **p)
{
    if(p!=NULL)
    {
        free(p[0]);
        free(p);
        p=NULL;
    }
}


int UpScaleNewX16_cpu(unsigned char** srcImage,int height,int width ,unsigned char** dstImage)
{
  int dstWidth=width<<2;
  int dstHeight=height<<2;

  unsigned char *p1=srcImage[0];
  unsigned char *p2=srcImage[1];
  unsigned char* pDst1=dstImage[0];
  unsigned char* pDst2=dstImage[1];
  unsigned char* pDst3=dstImage[2];
  unsigned char* pDst4=dstImage[3];

  //column
  for(int h=0;h<height-1;h++)
  {
    *pDst1=*(pDst1+1)=*p1;
    *pDst2=*(pDst2+1)=*p1*3/4.0+*p2*1/4.0;
    *pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
    *pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;

    pDst1 +=dstWidth-2;
    pDst2 +=dstWidth-2;
    pDst3 +=dstWidth-2;
    pDst4 +=dstWidth-2;
    p1 +=width-1;
    p2 +=width-1;


    *pDst1=*(pDst1+1)=*p1;
    *pDst2=*(pDst2+1)=*p1*3/4.0+*p2*1/4.0;
    *pDst3=*(pDst3+1)=*p1*2/4.0+*p2*2/4.0;
    *pDst4=*(pDst4+1)=*p1*1/4.0+*p2*3/4.0;


    pDst1 =pDst4+2;
    pDst2 =pDst1+dstWidth;
    pDst3 =pDst2+dstWidth;
    pDst4 =pDst3+dstWidth;
    p1++;
    p2++;
  }
  *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=*pDst3=*(pDst3+1)=*pDst4=*(pDst4+1)=srcImage[height-1][0];
  pDst1=pDst2-2;
  pDst2=pDst3-2;
  pDst3=pDst4-2;
  pDst4=pDst4+dstWidth-2;
  *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=*pDst3=*(pDst3+1)=*pDst4=*(pDst4+1)=srcImage[height-1][width-1];

  //row
  p1=srcImage[0];
  p2=p1+1;
  pDst1=dstImage[0];
  pDst2=pDst1+1;
  pDst3=pDst2+1;
  pDst4=pDst3+1;
  for(int w=0;w<width-1;w++)
  {
    *pDst1=*(pDst1+dstWidth)=*p1;
    *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
    *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
    *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;

    pDst1+=4;
    pDst2+=4;
    pDst3+=4;
    pDst4+=4;
    p1++;
    p2++;
  }
  *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[0][width-1];

  pDst1 =dstImage[dstHeight-2];
  pDst2 =pDst1+1;
  pDst3 =pDst2+1;
  pDst4 =pDst3+1;
  p1 =srcImage[height-1];
  p2 =p1+1;
  for(int w=0;w<width-1;w++)
  {
    *pDst1=*(pDst1+dstWidth)=*p1;
    *pDst2=*(pDst2+dstWidth)=*p1*3/4.0+*p2*1/4.0;
    *pDst3=*(pDst3+dstWidth)=*p1*2/4.0+*p2*2/4.0;
    *pDst4=*(pDst4+dstWidth)=*p1*1/4.0+*p2*3/4.0;


    pDst1 +=4;
    pDst2 +=4;
    pDst3 +=4;
    pDst4 +=4;
    p1++;
    p2++;
  }
  *pDst1=*(pDst1+dstWidth)=*pDst2=*(pDst2+dstWidth)=srcImage[height-1][width-1];


  //body
  pDst1=dstImage[2]+2;
  pDst2=dstImage[3]+2;
  pDst3=dstImage[4]+2;
  pDst4=dstImage[5]+2;
  p1=srcImage[0];
  p2=srcImage[1];
  for(int h=0;h<height-1;h++)
  {
    for(int w=0;w<width-1;w++)
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

  return 0;
}



int UpScaleNewX16(int height, int width, unsigned char *srcImage1, unsigned char *dstImage1) 
{
  unsigned char (*srcImage)[height / 4][width / 4] = (unsigned char(*)[height/4][width/4])(srcImage1);
  unsigned char (*dstImage)[height][width] = (unsigned char(*)[height][width])(dstImage1);

  unsigned char **yPlane=allocu(height/4,width/4);
  unsigned char** yPlaneUp=allocu(height, width);

#ifdef _VERIFY
  // correctness verification.
  for(int i=0; i < height/4; i++)
    for(int j=0; j < width/4; j++)
      yPlane[i][j]=((unsigned char*)srcImage)[i*(width/4)+j];
  UpScaleNewX16_cpu(yPlane, height/4, width/4, yPlaneUp);
#endif

  float border_mp_0[4][1] = { 1., 3 / 4.f, 2 / 4.f, 1 / 4.f };
  float border_mp_1[4][1] = { 0., 1 / 4.f, 2 / 4.f, 3 / 4.f };


  {
#ifdef TIME_PROF
    tem = 0, tem1 = 0;
#endif
    for(int q = 0; q < RUNS ; q++)
    {
      size_t srcImageSrcWidth = width/4;
      size_t srcImageSrcHeight = height/4;
      size_t srcImage_srcsz = sizeof(unsigned char);
      size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
      srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
      size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
      size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));

      // ---------Padding.-------------- TBD. Opt.
      unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
      for(int i = 0; i < srcImageSrcHeight; i++){
        memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
      }

      cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      size_t border_mp_0SrcWidth = 1;
      size_t border_mp_0SrcHeight = 4;
      size_t border_mp_0_srcsz = sizeof(float);
      size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
      border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
      size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
      size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));

      // -------------Padding border_mp-----TBD. remove.
      float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
      for(int i = 0; i < border_mp_0SrcHeight; i++){
        memcpy( (char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (char*)border_mp_0+ i * border_mp_0SrcWidth* sizeof(float), border_mp_0SrcWidth * sizeof(float) );
      }
      cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      size_t border_mp_1SrcWidth = 1;
      size_t border_mp_1SrcHeight = 4;
      size_t border_mp_1_srcsz = sizeof(float);
      size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
      border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
      size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
      size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
      float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
      for(int i = 0; i < border_mp_1SrcHeight; i++){
        memcpy( (char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (char*)border_mp_1+ i * border_mp_1SrcWidth* sizeof(float), border_mp_1SrcWidth * sizeof(float) );
      }
      cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      size_t dstImageDSWidth = width;
      size_t dstImageDSHeight = height;
      size_t dstImage_dssz = sizeof(unsigned char);
      size_t Readsize = dstImageDSWidth * dstImageDSHeight * dstImage_dssz;
      size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
      dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
      size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
      size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
      unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
      for(int i = 0; i < dstImageDSHeight; i++){
        memcpy((char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (char*)dstImage+ i * dstImageDSWidth * sizeof(unsigned char), dstImageDSWidth* sizeof(unsigned char) );
      }
      cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dssz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);


      /*--------- Upcol-------------------------*/
      gettimeofday(&t11,NULL);
      size_t global_work_size[2];
      size_t local_work_size[2];
      cl_event event_kernel;
      cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
      checkErr(status, "clCreateKernel for kernel_2");
#if 0
      global_work_size[0] = 256;
      global_work_size[1] = 2;
#endif
#if 1  // AMD work.
      global_work_size[0] =  2;
      global_work_size[1] = height/4;
#endif
      local_work_size[0] = 64;
      local_work_size[1] = 1;

      status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&srcImageSrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&srcImageSrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&srcImageSrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&srcImageSrcShift);
      checkErr(status, "clSetKernelArg");
      checkErr(status, "clWriteBuffer");
      status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&border_mp_0srcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&border_mp_0SrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&border_mp_0SrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&border_mp_0SrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&border_mp_0SrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&border_mp_1srcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&border_mp_1SrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&border_mp_1SrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&border_mp_1SrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&border_mp_1SrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 15, sizeof(cl_mem), (void *)&dstImagedsBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 16, sizeof(int), (void *)&dstImageDSWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 17, sizeof(int), (void *)&dstImageDSHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 18, sizeof(int), (void *)&dstImageDSStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_2, 19, sizeof(int), (void *)&dstImageDSShift);
      checkErr(status, "clSetKernelArg");

      status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
      //status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);

      checkErr(status, "clEnqueueNDRangeKernel of kernel_2");
      status = clFinish(g_queue);
      checkErr(status,"clFinish of kernel_2");

#ifdef TIME_PROF
      gettimeofday(&t12,NULL);
      tem +=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
      tem1 += (double)((endTime - startTime)/1000.0);
#endif
      status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
      checkErr(status,"clEnqueueReadBuffer");
      for(int i = 0; i < dstImageDSHeight; i++){
        memcpy( (char*)dstImage+ i *dstImageDSWidth* sizeof(unsigned char),(char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep,dstImageDSWidth* sizeof(unsigned char) );
      }
    }

  }
  //
#ifdef TIME_PROF
  //printf("total: up_col = %f ms\n",tem/20);
  total.up_col_time = tem / RUNS;
  total.kernel_up_col = (double)(tem1 / (1000.0*RUNS));
#endif

#ifdef _VERIFY1
  for(int i = 0; i < (height-2); i++)
  {
    for(int j = 0; j < 2; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("First Two UpCol: i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);
        abort();
      }
    }
    //printf("\n");

  }

  for(int i = 0; i < (height-2); i++)
  {
    for(int j = (width-2); j < width; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("Last UpCol: i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);
        abort();
      }
    }
    //printf("\n");
  }
  printf("up col success\n");
#endif

  {
#ifdef TIME_PROF
    tem = 0, tem1 = 0;
#endif
    //for(int i = 0; i< RUNS; i++)
    for(int q = 0; q< 1; q++)
    {
      size_t border_mp_0SrcWidth = 4;
      size_t border_mp_0SrcHeight = 1;
      size_t border_mp_0_srcsz = sizeof(float);
      size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
      border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
      size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
      size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));
      cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
      for(int i = 0; i < border_mp_0SrcHeight; i++){
        memcpy( (char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (char*)border_mp_0+ i * border_mp_0SrcWidth* sizeof(float), border_mp_0SrcWidth * sizeof(float) );
      }
      status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      //size_t srcImageSrcWidth = 256;
      //size_t srcImageSrcHeight = 256;
      size_t srcImageSrcWidth = width/4;
      size_t srcImageSrcHeight = height/4;
      size_t srcImage_srcsz = sizeof(unsigned char);
      size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
      srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
      size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
      size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
      cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
      for(int i = 0; i < srcImageSrcHeight; i++){
        memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
      }
      status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      size_t border_mp_1SrcWidth = 4;
      size_t border_mp_1SrcHeight = 1;
      size_t border_mp_1_srcsz = sizeof(float);
      size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
      border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
      size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
      size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
      cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
      for(int i = 0; i < border_mp_1SrcHeight; i++){
        memcpy( (char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (char*)border_mp_1+ i * border_mp_1SrcWidth* sizeof(float), border_mp_1SrcWidth * sizeof(float) );
      }

      size_t dstImageDSWidth = width;
      size_t dstImageDSHeight = height;
      size_t dstImage_dssz = sizeof(unsigned char);
      size_t Readsize = dstImageDSWidth * dstImageDSHeight * dstImage_dssz;
      size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
      dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
      size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
      size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
      cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dssz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
      for(int i = 0; i < dstImageDSHeight; i++){
        memcpy((char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (char*)dstImage+ i * dstImageDSWidth * sizeof(unsigned char), dstImageDSWidth* sizeof(unsigned char) );
      }
      status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");
      status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      /* ------ Uprow ------*/
      gettimeofday(&t11,NULL);
      size_t global_work_size[2];
      size_t local_work_size[2];
      cl_event event_kernel;
      cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
      checkErr(status, "clCreateKernel for kernel_3");
      //global_work_size[0] = 256;
      //global_work_size[1] = 2;
      global_work_size[0] =  width/4;
      global_work_size[1] = 2;
      local_work_size[0] = 64;
      local_work_size[1] = 1;
      status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&srcImageSrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 2, sizeof(int), (void *)&srcImageSrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 3, sizeof(int), (void *)&srcImageSrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 4, sizeof(int), (void *)&srcImageSrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 5, sizeof(cl_mem), (void *)&border_mp_0srcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 6, sizeof(int), (void *)&border_mp_0SrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 7, sizeof(int), (void *)&border_mp_0SrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 8, sizeof(int), (void *)&border_mp_0SrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 9, sizeof(int), (void *)&border_mp_0SrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 10, sizeof(cl_mem), (void *)&border_mp_1srcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 11, sizeof(int), (void *)&border_mp_1SrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 12, sizeof(int), (void *)&border_mp_1SrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 13, sizeof(int), (void *)&border_mp_1SrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 14, sizeof(int), (void *)&border_mp_1SrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 15, sizeof(cl_mem), (void *)&dstImagedsBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 16, sizeof(int), (void *)&dstImageDSWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 17, sizeof(int), (void *)&dstImageDSHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 18, sizeof(int), (void *)&dstImageDSStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_3, 19, sizeof(int), (void *)&dstImageDSShift);
      checkErr(status, "clSetKernelArg");

      status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
      //status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
      checkErr(status, "clEnqueueNDRangeKernel of kernel_3");

      status = clReleaseKernel(kernel_3);
      checkErr(status, "clReleaseKernel of kernel_3");

      status = clFinish(g_queue);
      checkErr(status,"clFinish of kernel_3");

      gettimeofday(&t12,NULL);


#ifdef TIME_PROF
      tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
      tem1 += (endTime - startTime)/1000.0;
#endif
      status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
      checkErr(status,"clEnqueueReadBuffer");
      for(int i = 0; i < dstImageDSHeight; i++){
        memcpy( (char*)dstImage+ i *dstImageDSWidth* sizeof(unsigned char),(char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep,dstImageDSWidth* sizeof(unsigned char) );
      }
    }

  }

#ifdef TIME_PROF
  //printf("Total up_row = %f ms\n",tem/20);
  total.up_row_time = (double)tem / RUNS;
  total.kernel_up_row = double(tem1 / 1000.0);
  total.kernel_up_row = double(total.kernel_up_row / RUNS);
#endif


#ifdef _VERIFY1
  for(int i = 0; i < (height-2); i++)
  {
    for(int j = 0; j < 2; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("UpRow: i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);


        abort();

      }
    }
    //printf("\n");
  }
  for(int i = 0; i < (height -2); i++)
  {
    for(int j = (width-2); j < width; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("UpRow: i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);


        abort();

      }
    }
    //printf("\n");
  }


  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < width; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);
        abort();

      }
    }
    //printf("\n");
  }


  for(int i = (height-2); i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);


        abort();

      }
    }
    //printf("\n");

  }
  //printf("up row success\n");
#endif


  float mp[4][2] = { 7 / 8.0f, 1 / 8.0f, 5 / 8.0f, 3 / 8.0f, 3 / 8.0f, 5 / 8.0f, 1 / 8.0f, 7 / 8.0f };

  {
#ifdef TIME_PROF 
    tem = 0, tem1 = 0;
#endif
    for(int q = 0; q < 20; q++)
    {
      //size_t srcImageSrcWidth = 256;
      //size_t srcImageSrcHeight = 256;
      size_t srcImageSrcWidth = width/4;
      size_t srcImageSrcHeight = height/4;

      size_t srcImage_srcsz = sizeof(unsigned char);
      size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
      srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
      size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
      size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
      cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
      for(int i = 0; i < srcImageSrcHeight; i++){
        memcpy( (char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (char*)srcImage+ i * srcImageSrcWidth* sizeof(unsigned char), srcImageSrcWidth * sizeof(unsigned char) );
      }
      status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");

      size_t mpSrcWidth = 2;
      size_t mpSrcHeight = 4;
      size_t mp_srcsz = sizeof(float);
      size_t mpSrcStep = mpSrcWidth * mp_srcsz;
      mpSrcStep = (mpSrcStep % PADDING < 16) ? ((mpSrcStep / PADDING+1) * PADDING) : ((mpSrcStep + PADDING) / PADDING+1) * PADDING;
      size_t mpSrcShift = mpSrcStep * PADDING_LINE;
      size_t mp_srcsz0Pad = mpSrcStep * (mpSrcHeight + (PADDING_LINE<<1));
      cl_mem mpsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, mp_srcsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      char *mpSrcBufH = (char*)malloc(mp_srcsz0Pad); 
      for(int i = 0; i < mpSrcHeight; i++){
        memcpy( (char*)mpSrcBufH+ (i + PADDING_LINE) * mpSrcStep, (char*)mp+ i * mpSrcWidth* sizeof(float), mpSrcWidth * sizeof(float) );
      }
      status = clEnqueueWriteBuffer(g_queue, mpsrcBuf, CL_TRUE, 0,mp_srcsz0Pad,mpSrcBufH, 0, NULL, NULL);
      checkErr(status, "clWriteBuffer");
      size_t global_work_size[2];
      cl_event event_kernel;
      cl_kernel kernel_4 = clCreateKernel(g_program, "kernel_4", &status);
      checkErr(status, "clCreateKernel for kernel_4");

      gettimeofday(&t11,NULL);
      //global_work_size[0] = 256;
      //global_work_size[1] = 256;
      global_work_size[0] = width/4;
      global_work_size[1] = height/4;
      status = clSetKernelArg(kernel_4, 0, sizeof(cl_mem), (void *)&srcImagesrcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 1, sizeof(int), (void *)&srcImageSrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 2, sizeof(int), (void *)&srcImageSrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 3, sizeof(int), (void *)&srcImageSrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 4, sizeof(int), (void *)&srcImageSrcShift);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 5, sizeof(cl_mem), (void *)&mpsrcBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 6, sizeof(int), (void *)&mpSrcWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 7, sizeof(int), (void *)&mpSrcHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 8, sizeof(int), (void *)&mpSrcStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 9, sizeof(int), (void *)&mpSrcShift);
      checkErr(status, "clSetKernelArg");
      size_t dstImageDstWidth = width;
      size_t dstImageDstHeight = height;
      size_t dstImage_dstsz = sizeof(unsigned char);
      size_t Readsize = dstImageDstWidth * dstImageDstHeight * dstImage_dstsz;
      size_t dstImageDstStep = dstImageDstWidth * dstImage_dstsz;
      dstImageDstStep = (dstImageDstStep % PADDING < 16) ? ((dstImageDstStep / PADDING+1) * PADDING) : ((dstImageDstStep + PADDING) / PADDING+1) * PADDING;
      size_t dstImageDstShift = dstImageDstStep * PADDING_LINE;
      size_t dstImage_dstsz0Pad = dstImageDstStep * (dstImageDstHeight + (PADDING_LINE<<1));
      cl_mem dstImagedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dstImage_dstsz0Pad, NULL, &status);
      checkErr(status, "clCreateBuffer");
      unsigned char *dstImageDstBufH = (unsigned char*)malloc(dstImage_dstsz0Pad); 
      for(int i = 0; i < dstImageDstHeight; i++){
        memcpy( (char*)dstImageDstBufH+ (i + PADDING_LINE) * dstImageDstStep,(char*)dstImage + i * dstImageDstWidth* sizeof(unsigned char),dstImageDstWidth* sizeof(unsigned char) );
      }

      status = clEnqueueWriteBuffer(g_queue, dstImagedstBuf, CL_TRUE, 0,dstImage_dstsz0Pad, dstImageDstBufH, 0, NULL, NULL);
      status = clSetKernelArg(kernel_4, 10, sizeof(cl_mem), (void *)&dstImagedstBuf);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 11, sizeof(int), (void *)&dstImageDstWidth);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 12, sizeof(int), (void *)&dstImageDstHeight);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 13, sizeof(int), (void *)&dstImageDstStep);
      checkErr(status, "clSetKernelArg");
      status = clSetKernelArg(kernel_4, 14, sizeof(int), (void *)&dstImageDstShift);
      checkErr(status, "clSetKernelArg");

      status = clEnqueueNDRangeKernel(g_queue, kernel_4, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
      checkErr(status, "clEnqueueNDRangeKernel of kernel_4");
      status = clFinish(g_queue);

      gettimeofday(&t12,NULL);

#ifdef TIME_PROF
      tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
      clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
      tem1 += (endTime - startTime)/1000.0;
#endif

      checkErr(status,"clFinish of kernel_4");
      status = clEnqueueReadBuffer(g_queue, dstImagedstBuf, CL_TRUE, 0,dstImage_dstsz0Pad,dstImageDstBufH, 0, NULL, NULL);
      checkErr(status,"clEnqueueReadBuffer");
      for(int i = 0; i < dstImageDstHeight; i++){
        memcpy( (char*)dstImage+ i *dstImageDstWidth* sizeof(unsigned char),(char*) dstImageDstBufH+ (i + PADDING_LINE)* dstImageDstStep,dstImageDstWidth* sizeof(unsigned char) );
      }

    }
  }

#ifdef TIME_PROF
  //printf("total: up = %f ms\n",tem/20);
  total.up_time = tem /RUNS;
  total.kernel_up = (double)(tem1 / (1000.0*RUNS));
#endif

#ifdef _VERIFY1
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      //if(i == 1020)
      if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* width +j])
      {
        printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* width +j]);
        //printf("%u ",yPlaneDown[i][j]);


        abort();

      }
    }
    //printf("\n");

  }
  printf("up success\n");
#endif
}

void Sharpness_cpu(unsigned char** yPlane,unsigned char** yPlaneCSER,int width,int height,MMC_CSE_PARAMETER_PUBLIC* cseParamPublic,unsigned char** dstImage, short **pEdge)
{
    //short** pEdge=allocs(height,width);
    short** pSharpness=allocs(height,width);
#ifdef TIME_PAR
    struct timeval t11,t12,t22,t21,t32,t31;
#endif

#ifdef TIME_PAR
    gettimeofday(&t11,NULL);
#endif

    short *pEdgeL=pEdge[1];
    memset(pEdge[0],0,width*sizeof(short));
    memset(pEdge[height-1],0,width*sizeof(short));
    int edgeV=0;
    unsigned char *pSrcL0=yPlane[0],*pSrcL1=yPlane[1],*pSrcL2=yPlane[2];
    for(int y = 0; y < height-2; y++)
    {

        *pEdgeL++ =0;
        for(int x = 0; x < width-2; x++)
        {
            int gx=(pSrcL0[2]+((int)pSrcL1[2]<<1) + pSrcL2[2]) - (pSrcL0[0] + ((int)pSrcL1[0]<<1) + pSrcL2[0]);
            int gy=(pSrcL0[0]+((int)pSrcL0[1]<<1) + pSrcL0[2]) - (pSrcL2[0] + ((int)pSrcL2[1]<<1) + pSrcL2[2]);

            edgeV=(abs(gx)+abs(gy));

            *pEdgeL++=edgeV;

            pSrcL0++;
            pSrcL1++;
            pSrcL2++;
        }

        *pEdgeL++=0;

        pSrcL0 +=2;
        pSrcL1 +=2;
        pSrcL2 +=2;
    }


#ifdef TIME_PAR
    gettimeofday(&t12,NULL);
#endif

#ifdef TIME_PAR
    gettimeofday(&t21,NULL);
#endif
    int sum=0;
    short mean=0;

    int size=width*height;
    short *p=pEdge[0];
    for(int i=0;i<size;i++)
        sum +=*p++;
    mean=(sum+size/2)/size;

    printf("sum = %d, mean = %d\n", sum, mean);


#ifdef TIME_PAR
    gettimeofday(&t22,NULL);
#endif

    cseParamPublic->cutoff2=256.0f;
    cseParamPublic->cutoff3Coef=1.0f;
    cseParamPublic->cutoffCoef=1.0f;
    cseParamPublic->peak=2.0f;
    cseParamPublic->low=0.05f;

    float weight,strength;
    float weight_tmp=pow(1/cseParamPublic->cutoff2,4);
    float cutoff=cseParamPublic->cutoffCoef*mean;
    float tmp2=cseParamPublic->peak-1.0f;
    float cutoff2Order=pow(cseParamPublic->cutoff3Coef*mean,4);
#ifdef TIME_PAR
    gettimeofday(&t31,NULL);
#endif
    unsigned char *p0=yPlane[0],*p1=p0,*p2=p0;
    unsigned char b0[3],b1[3],b2[3];
    for(int i=0;i<height;i++)
    {

        if(i!=0)
            p0=yPlane[i-1];
        p1=yPlane[i];
        if(i==height-1)
            p2=yPlane[i];
        else
            p2=yPlane[i+1];

        for(int j=0;j<width;j++)
        {

            b0[0]=(i==0 || j==0) ? 0 : *(p0-1);
            b0[1]=(i==0)?0:p0[0];
            b0[2]=(i==0 || j==width-1)?0:p0[1];

            b1[0]=(j==0)?0:*(p1-1);
            b1[1]=p1[0];
            b1[2]=(j==width-1)?0:p1[1];

            b2[0]=(i==height-1 || j==0)?0:*(p2-1);
            b2[1]=(i==height-1)?0:p2[0];
            b2[2]=(i==height-1 || j==width-1)?0:p2[1];

            unsigned char maxValue,minValue;
            maxValue=minValue=yPlane[i][j];

            maxValue=MAX3(b0[0],b0[1],b0[2]);
            maxValue=MAX2(maxValue,MAX3(b1[0],b1[1],b1[2]));
            maxValue=MAX2(maxValue,MAX3(b2[0],b2[1],b2[2]));

            minValue=MIN3(b0[0],b0[1],b0[2]);
            minValue=MIN2(minValue,MIN3(b1[0],b1[1],b1[2]));
            minValue=MIN2(minValue,MIN3(b2[0],b2[1],b2[2]));

            p0++;
            p1++;
            p2++;

            float pError=yPlane[i][j]-yPlaneCSER[i][j];
            float edge2Order=pow(float(pEdge[i][j]),4);
            weight=1/(1+edge2Order*weight_tmp);
            strength=tmp2*(1-1/(1+edge2Order/(pow(cutoff,4))))*weight+1.0f;

            int enhancedF=pError*strength+yPlaneCSER[i][j];
            strength=(0.05f*edge2Order+cutoff2Order)/(cutoff2Order+edge2Order);

            float pSharpness_value=enhancedF>255 ? 255 : (enhancedF<0 ? 0 : enhancedF);

            edge2Order=minValue-strength*(minValue-enhancedF);
            strength=maxValue+strength*(enhancedF-maxValue);
            strength=strength<255 ? strength:255;
            edge2Order=enhancedF<minValue ? (edge2Order>0 ? edge2Order : 0) : pSharpness_value;
            dstImage[i][j]=enhancedF>maxValue ? strength : edge2Order;

        }
    }

#ifdef TIME_PAR
    gettimeofday(&t32,NULL);

    double tem=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
    double tem1=(double)(t22.tv_usec-t21.tv_usec)*0.001+(t22.tv_sec-t21.tv_sec)*1000;
    double tem2=(double)(t32.tv_usec-t31.tv_usec)*0.001+(t32.tv_sec-t31.tv_sec)*1000;

    printf("Sobel : %f ms\nMean : %f ms\nSharpness : %fms\n",tem,tem1,tem2);
#endif

    //frees(pSharpness);
    //frees(pEdge);
}


void Sharpness(int height, int width, unsigned char *yPlane1, unsigned char *yPlaneCSER1, unsigned char *dst3, MMC_CSE_PARAMETER_PUBLIC &cseParamPublic) 
{
  unsigned char (*yPlane)[height][width] = (unsigned char(*)[height][width])(yPlane1);;
  unsigned char (*yPlaneCSER)[height][width] = (unsigned char(*)[height][width])(yPlaneCSER1);
  unsigned char (*dst)[height][width] = (unsigned char(*)[height][width])(dst3);

    short** pEdge1=allocs(height,width);
    unsigned char **src=allocu(height,width);
    unsigned char **srcCSER=allocu(height,width);
    unsigned char **dst1=allocu(height,width);
    //unsigned char** yPlaneUp=allocu(1024,1024);

#ifdef _VERIFY 
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            src[i][j]=((unsigned char*)yPlane)[i*width+j];
            srcCSER[i][j]= ((unsigned char*)yPlaneCSER)[i*width+j]; 
        }

    printf("ss\n");
    Sharpness_cpu(src, srcCSER,height,width,&cseParamPublic, dst1, pEdge1);
#endif

    unsigned short pEdge[height][width];
    char gx[3][3] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    char gy[3][3] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };

    {
#ifdef TIME_PROF
        tem = 0, tem1 = 0;
#endif
        for(int q = 0; q < RUNS; q++)
        {

            size_t yPlaneSrcWidth = width;
            size_t yPlaneSrcHeight = height;
            size_t yPlane_srcsz = sizeof(unsigned char);
            size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
            yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
            size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
            cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlane_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
            for(int i = 0; i < yPlaneSrcHeight; i++){
                memcpy( (char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (char*)yPlane+ i * yPlaneSrcWidth* sizeof(unsigned char), yPlaneSrcWidth * sizeof(unsigned char) );
            }

            status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            size_t gxSrcWidth = 3;
            size_t gxSrcHeight = 3;
            size_t gx_srcsz = sizeof(char);
            size_t gxSrcStep = gxSrcWidth * gx_srcsz;
            gxSrcStep = (gxSrcStep % PADDING < 16) ? ((gxSrcStep / PADDING+1) * PADDING) : ((gxSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t gxSrcShift = gxSrcStep * PADDING_LINE;
            size_t gx_srcsz0Pad = gxSrcStep * (gxSrcHeight + (PADDING_LINE<<1));
            cl_mem gxsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, gx_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            char *gxSrcBufH = (char*)malloc(gx_srcsz0Pad); 
            for(int i = 0; i < gxSrcHeight; i++){
                memcpy( (char*)gxSrcBufH+ (i + PADDING_LINE) * gxSrcStep, (char*)gx+ i * gxSrcWidth* sizeof(char), gxSrcWidth * sizeof(char) );
            }
            status = clEnqueueWriteBuffer(g_queue, gxsrcBuf, CL_TRUE, 0,gx_srcsz0Pad,gxSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            size_t gySrcWidth = 3;
            size_t gySrcHeight = 3;
            size_t gy_srcsz = sizeof(char);
            size_t gySrcStep = gySrcWidth * gy_srcsz;
            gySrcStep = (gySrcStep % PADDING < 16) ? ((gySrcStep / PADDING+1) * PADDING) : ((gySrcStep + PADDING) / PADDING+1) * PADDING;
            size_t gySrcShift = gySrcStep * PADDING_LINE;
            size_t gy_srcsz0Pad = gySrcStep * (gySrcHeight + (PADDING_LINE<<1));
            cl_mem gysrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, gy_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            char *gySrcBufH = (char*)malloc(gy_srcsz0Pad); 
            for(int i = 0; i < gySrcHeight; i++){
                memcpy( (char*)gySrcBufH+ (i + PADDING_LINE) * gySrcStep, (char*)gy+ i * gySrcWidth* sizeof(char), gySrcWidth * sizeof(char) );
            }
            status = clEnqueueWriteBuffer(g_queue, gysrcBuf, CL_TRUE, 0,gy_srcsz0Pad,gySrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            gettimeofday(&t11,NULL);

            size_t global_work_size[2], local_work_size[2];
            cl_event event_kernel;
            cl_kernel kernel_5 = clCreateKernel(g_program, "kernel_5", &status);
            checkErr(status, "clCreateKernel for kernel_5");
            //global_work_size[0] = 256;
            //global_work_size[1] = 1024; //
            global_work_size[0] = width/4;
            global_work_size[1] = height; //
            //local_work_size[0] = 256;
            //local_work_size[1] = 1;
            status = clSetKernelArg(kernel_5, 0, sizeof(cl_mem), (void *)&yPlanesrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 1, sizeof(int), (void *)&yPlaneSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 2, sizeof(int), (void *)&yPlaneSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 3, sizeof(int), (void *)&yPlaneSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 4, sizeof(int), (void *)&yPlaneSrcShift);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 5, sizeof(cl_mem), (void *)&gxsrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 6, sizeof(int), (void *)&gxSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 7, sizeof(int), (void *)&gxSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 8, sizeof(int), (void *)&gxSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 9, sizeof(int), (void *)&gxSrcShift);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 10, sizeof(cl_mem), (void *)&gysrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 11, sizeof(int), (void *)&gySrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 12, sizeof(int), (void *)&gySrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 13, sizeof(int), (void *)&gySrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 14, sizeof(int), (void *)&gySrcShift);
            checkErr(status, "clSetKernelArg");
            size_t pEdgeDstWidth = width;
            size_t pEdgeDstHeight = height;
            size_t pEdge_dstsz = sizeof(unsigned short);
            size_t Readsize = pEdgeDstWidth * pEdgeDstHeight * pEdge_dstsz;
            size_t pEdgeDstStep = pEdgeDstWidth * pEdge_dstsz;
            pEdgeDstStep = (pEdgeDstStep % PADDING < 16) ? ((pEdgeDstStep / PADDING+1) * PADDING) : ((pEdgeDstStep + PADDING) / PADDING+1) * PADDING;
            size_t pEdgeDstShift = pEdgeDstStep * PADDING_LINE;
            size_t pEdge_dstsz0Pad = pEdgeDstStep * (pEdgeDstHeight + (PADDING_LINE<<1));
            cl_mem pEdgedstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, pEdge_dstsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned short *pEdgeDstBufH = (unsigned short*)malloc(pEdge_dstsz0Pad); 
            for(int i = 0; i < pEdgeDstHeight; i++){
                memcpy( (char*)pEdgeDstBufH+ (i + PADDING_LINE) * pEdgeDstStep,(char*)pEdge + i * pEdgeDstWidth* sizeof(unsigned short),pEdgeDstWidth* sizeof(unsigned short) );
            }
            status = clSetKernelArg(kernel_5, 15, sizeof(cl_mem), (void *)&pEdgedstBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 16, sizeof(int), (void *)&pEdgeDstWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 17, sizeof(int), (void *)&pEdgeDstHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 18, sizeof(int), (void *)&pEdgeDstStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_5, 19, sizeof(int), (void *)&pEdgeDstShift);
            checkErr(status, "clSetKernelArg");

            status = clEnqueueNDRangeKernel(g_queue, kernel_5, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
            checkErr(status, "clEnqueueNDRangeKernel of kernel_5");
            status = clFinish(g_queue);
            checkErr(status,"clFinish of kernel_5");
#ifdef TIME_PROF
            gettimeofday(&t12,NULL);
            tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

            clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
            clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
            tem1 += (double)((endTime - startTime)/1000.0);

#endif

            status = clEnqueueReadBuffer(g_queue, pEdgedstBuf, CL_TRUE, 0,pEdge_dstsz0Pad,pEdgeDstBufH, 0, NULL, NULL);
            checkErr(status,"clEnqueueReadBuffer");
            for(int i = 0; i < pEdgeDstHeight; i++){
                memcpy( (char*)pEdge+ i *pEdgeDstWidth* sizeof(unsigned short),(char*) pEdgeDstBufH+ (i + PADDING_LINE)* pEdgeDstStep,pEdgeDstWidth* sizeof(unsigned short) );
            }

        }
    }

#ifdef TIME_PROF
    //printf("total: sobel = %f ms\n",tem/20);
    total.sobel_time = (double)(tem/RUNS);
    total.kernel_sobel = (double)(tem1/(1000.0*RUNS));

#endif

#ifdef _VERIFY1
    for(int i = 0; i <height ; i++)
    {
        for(int j = 0; j < height; j++)
        {
            //if(i == 1020)
            if(pEdge1[i][j] !=((unsigned short*) pEdge)[i* width +j])
            {
                printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)pEdge1[i][j], (int)((unsigned short*) pEdge)[i* width +j]);
                //printf("%u ",yPlaneDown[i][j]);


                abort();

            }
        }
        //printf("\n");

    }
    //printf("Sobel success\n");

 #endif
   
    //unsigned short item;
    int* item= (int *)malloc(sizeof(4));;
    {
        tem = 0, tem1 = 0;
        for(int q = 0; q <RUNS; q++)
        {

            size_t pEdgeSrcWidth = width;
            size_t pEdgeSrcHeight = height;
            size_t pEdge_srcsz = sizeof(unsigned short);
            size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
            pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
            size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
            cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pEdge_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
            for(int i = 0; i < pEdgeSrcHeight; i++){
                memcpy( (char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (char*)pEdge+ i * pEdgeSrcWidth* sizeof(unsigned short), pEdgeSrcWidth * sizeof(unsigned short) );
            }
            status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            item[0] =0;
            size_t global_work_size[2];
            cl_event event_kernel;
            cl_kernel kernel_6 = clCreateKernel(g_program, "kernel_6", &status);
            checkErr(status, "clCreateKernel for kernel_6");
            
            gettimeofday(&t11,NULL);
            //global_work_size[0] = 256;
            //global_work_size[1] = 1024;
            global_work_size[0] = width/4;
            global_work_size[1] = height;
            size_t local_work_size[2];
            local_work_size[0] = 16;
            local_work_size[1] = 16;

            status = clSetKernelArg(kernel_6, 0, sizeof(cl_mem), (void *)&pEdgesrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_6, 1, sizeof(int), (void *)&pEdgeSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_6, 2, sizeof(int), (void *)&pEdgeSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_6, 3, sizeof(int), (void *)&pEdgeSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_6, 4, sizeof(int), (void *)&pEdgeSrcShift);
            checkErr(status, "clSetKernelArg");

            cl_mem outputBuffer2 = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(int), NULL, &status);
            checkErr(status,"clCreateBuffer");
            status = clEnqueueWriteBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(int), item, 0, NULL, NULL);
            checkErr(status,"clwriteBuffer");
            status = clSetKernelArg(kernel_6, 5, sizeof(cl_mem), (void *)&outputBuffer2);
            checkErr(status,"clSetKernelArg");
            //        status = clSetKernelArg(kernel_6, 6, sizeof(unsigned short) * local_work_size[0] * local_work_size[1], NULL);
            status = clSetKernelArg(kernel_6, 6, sizeof(unsigned int) * local_work_size[0] * local_work_size[1], NULL);

            checkErr(status,"clSetKernelArg");
            status = clEnqueueNDRangeKernel(g_queue, kernel_6, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
            checkErr(status, "clEnqueueNDRangeKernel of kernel_6");
            status = clFinish(g_queue);
            checkErr(status,"clFinish of kernel_6");

            //status = clEnqueueReadBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(unsigned short), &item, 0, NULL, NULL);
            status = clEnqueueReadBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(int), item, 0, NULL, NULL);
            checkErr(status,"clEnqueueReadBuffer");

#ifdef TIME_PROF
            gettimeofday(&t12,NULL);

            tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
    clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
    tem1 += (endTime - startTime)/1000.0;
#endif
        }
    }

#ifdef TIME_PROF
    total.mean_time = tem / RUNS;
    total.kernel_mean =(double)( tem1 / (1000.0*RUNS) );
    // printf("total: mean = %f ms\n",tem/20);
#endif

    short mean = (item[0]+ height*(width/2)) / (height * width);;

    //printf("sum1 = %d, mean1 = %d\n", item[0], mean);

    cseParamPublic.cutoff2 = 256.F;
    cseParamPublic.cutoff3Coef = 1.F;
    cseParamPublic.cutoffCoef = 1.F;
    cseParamPublic.peak = 2.F;

    float weight_tmp = (1 / cseParamPublic.cutoff2);
    float strength_tmp = 1 / cseParamPublic.cutoffCoef * mean;
    float tmp2 = cseParamPublic.peak - 1.;
    float cutoff2Order = pow(cseParamPublic.cutoff3Coef * mean, 4);

    float m1 = 1.0f / mean;
    m1 = m1 * m1 * m1 * m1;
    float m2 = 1.0f / 256.0f;
    m2 = m2 * m2 * m2 * m2;

    {
#ifdef TIME_PROF
        tem = 0, tem1 = 0;
#endif
        for(int q = 0; q < RUNS; q++)
        {

            size_t yPlaneSrcWidth = width;
            size_t yPlaneSrcHeight = height;
            size_t yPlane_srcsz = sizeof(unsigned char);
            size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
            yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
            size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
            cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlane_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
            for(int i = 0; i < yPlaneSrcHeight; i++){
                memcpy( (char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (char*)yPlane+ i * yPlaneSrcWidth* sizeof(unsigned char), yPlaneSrcWidth * sizeof(unsigned char) );
            }
            status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            size_t yPlaneCSERSrcWidth = width;
            size_t yPlaneCSERSrcHeight = height;
            size_t yPlaneCSER_srcsz = sizeof(unsigned char);
            size_t yPlaneCSERSrcStep = yPlaneCSERSrcWidth * yPlaneCSER_srcsz;
            yPlaneCSERSrcStep = (yPlaneCSERSrcStep % PADDING < 16) ? ((yPlaneCSERSrcStep / PADDING+1) * PADDING) : ((yPlaneCSERSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t yPlaneCSERSrcShift = yPlaneCSERSrcStep * PADDING_LINE;
            size_t yPlaneCSER_srcsz0Pad = yPlaneCSERSrcStep * (yPlaneCSERSrcHeight + (PADDING_LINE<<1));
            cl_mem yPlaneCSERsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, yPlaneCSER_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned char *yPlaneCSERSrcBufH = (unsigned char*)malloc(yPlaneCSER_srcsz0Pad); 
            for(int i = 0; i < yPlaneCSERSrcHeight; i++){
                memcpy( (char*)yPlaneCSERSrcBufH+ (i + PADDING_LINE) * yPlaneCSERSrcStep, (char*)yPlaneCSER+ i * yPlaneCSERSrcWidth* sizeof(unsigned char), yPlaneCSERSrcWidth * sizeof(unsigned char) );
            }
            status = clEnqueueWriteBuffer(g_queue, yPlaneCSERsrcBuf, CL_TRUE, 0,yPlaneCSER_srcsz0Pad,yPlaneCSERSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            size_t pEdgeSrcWidth = width;
            size_t pEdgeSrcHeight = height;
            size_t pEdge_srcsz = sizeof(unsigned short);
            size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
            pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
            size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
            size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
            cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, pEdge_srcsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
            for(int i = 0; i < pEdgeSrcHeight; i++){
                memcpy( (char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (char*)pEdge+ i * pEdgeSrcWidth* sizeof(unsigned short), pEdgeSrcWidth * sizeof(unsigned short) );
            }
            status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
            checkErr(status, "clWriteBuffer");

            gettimeofday(&t11,NULL);

            size_t global_work_size[2];
            cl_event event_kernel;
            cl_kernel kernel_7 = clCreateKernel(g_program, "kernel_7", &status);
            checkErr(status, "clCreateKernel for kernel_7");
            //global_work_size[0] = 256;
            //global_work_size[1] = 1024;
            global_work_size[0] = width/4;
            global_work_size[1] = height;
            status = clSetKernelArg(kernel_7, 0, sizeof(cl_mem), (void *)&yPlanesrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 1, sizeof(int), (void *)&yPlaneSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 2, sizeof(int), (void *)&yPlaneSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 3, sizeof(int), (void *)&yPlaneSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 4, sizeof(int), (void *)&yPlaneSrcShift);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 5, sizeof(cl_mem), (void *)&yPlaneCSERsrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 6, sizeof(int), (void *)&yPlaneCSERSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 7, sizeof(int), (void *)&yPlaneCSERSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 8, sizeof(int), (void *)&yPlaneCSERSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 9, sizeof(int), (void *)&yPlaneCSERSrcShift);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 10, sizeof(cl_mem), (void *)&pEdgesrcBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 11, sizeof(int), (void *)&pEdgeSrcWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 12, sizeof(int), (void *)&pEdgeSrcHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 13, sizeof(int), (void *)&pEdgeSrcStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 14, sizeof(int), (void *)&pEdgeSrcShift);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 15, sizeof(float), (void *)&cutoff2Order);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 16, sizeof(float), (void *)&m1);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 17, sizeof(float), (void *)&m2);
            checkErr(status, "clSetKernelArg");
            size_t dstDstWidth = width;
            size_t dstDstHeight = height;
            size_t dst_dstsz = sizeof(unsigned char);
            size_t Readsize = dstDstWidth * dstDstHeight * dst_dstsz;
            size_t dstDstStep = dstDstWidth * dst_dstsz;
            dstDstStep = (dstDstStep % PADDING < 16) ? ((dstDstStep / PADDING+1) * PADDING) : ((dstDstStep + PADDING) / PADDING+1) * PADDING;
            size_t dstDstShift = dstDstStep * PADDING_LINE;
            size_t dst_dstsz0Pad = dstDstStep * (dstDstHeight + (PADDING_LINE<<1));
            cl_mem dstdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_dstsz0Pad, NULL, &status);
            checkErr(status, "clCreateBuffer");
            unsigned char *dstDstBufH = (unsigned char*)malloc(dst_dstsz0Pad); 
            for(int i = 0; i < dstDstHeight; i++){
                memcpy( (char*)dstDstBufH+ (i + PADDING_LINE) * dstDstStep,(char*)dst + i * dstDstWidth* sizeof(unsigned char),dstDstWidth* sizeof(unsigned char) );
            }
            status = clSetKernelArg(kernel_7, 18, sizeof(cl_mem), (void *)&dstdstBuf);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 19, sizeof(int), (void *)&dstDstWidth);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 20, sizeof(int), (void *)&dstDstHeight);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 21, sizeof(int), (void *)&dstDstStep);
            checkErr(status, "clSetKernelArg");
            status = clSetKernelArg(kernel_7, 22, sizeof(int), (void *)&dstDstShift);
            checkErr(status, "clSetKernelArg");

            status = clEnqueueNDRangeKernel(g_queue, kernel_7, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
            checkErr(status, "clEnqueueNDRangeKernel of kernel_7");
            status = clFinish(g_queue);
            checkErr(status,"clFinish of kernel_7");

            gettimeofday(&t12,NULL);

#ifdef TIME_PROF
            tem += (double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

            clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
            clGetEventProfilingInfo(event_kernel, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
            tem1 += (endTime - startTime)/1000.0;
#endif
            status = clEnqueueReadBuffer(g_queue, dstdstBuf, CL_TRUE, 0,dst_dstsz0Pad,dstDstBufH, 0, NULL, NULL);
            checkErr(status,"clEnqueueReadBuffer");
            for(int i = 0; i < dstDstHeight; i++){
                memcpy( (char*)dst+ i *dstDstWidth* sizeof(unsigned char),(char*) dstDstBufH+ (i + PADDING_LINE)* dstDstStep,dstDstWidth* sizeof(unsigned char) );
            }
        }

    }

#ifdef TIME_PROF
     //       printf("total: sub_sharpness = %f ms\n",tem/20);
    total.sharp_time = tem / RUNS;
    total.kernel_sharpness = (double)(tem1 / (1000.0*RUNS));

#endif

#ifdef _VERIFY1
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //if(i == 1020)
            if(abs(dst1[i][j] -((unsigned char*) dst)[i* width +j]) > 1)
            {
                printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)dst1[i][j], (int)((unsigned char*) dst)[i* width +j]);
                //printf("%u ",yPlaneDown[i][j]);


                abort();

            }
        }
        //printf("\n");

    }
    printf("all success\n");
#endif

}



void sharpness_total(int height, int width, unsigned char *yPlane1, unsigned char *dst1) 
{
  unsigned char (*yPlane)[height][width] = (unsigned char(*)[height][width])(yPlane1); 
  unsigned char (*dst)[height][width] = (unsigned char(*)[height][width])(dst1);
  MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
  cseParamPublic.cutoff2 = 256.F;
  cseParamPublic.cutoff3Coef = 1.F;
  cseParamPublic.cutoffCoef = 1.F;
  cseParamPublic.peak = 2.F;

  unsigned char yPlaneCSER[height][width];
  unsigned char yPlaneDown[height / 4][width / 4];
  DownScaleNewX16(height, width, (unsigned char*)yPlane, (unsigned char*)(&yPlaneDown[0][0]));
  //UpScaleNewX16(&yPlaneDown, &yPlaneCSER);
  UpScaleNewX16(height, width, (unsigned char*) (&yPlaneDown[0][0]), (unsigned char*)(&yPlaneCSER[0][0]));
  Sharpness(height, width, (unsigned char*) yPlane, (unsigned char*)(&yPlaneCSER[0][0]), dst1, cseParamPublic);
}



int main() {
    char *inputfile = "sharpness_opt_lxj_256.cl";
    char *remain = NULL;
    if (-1 == openCLCreate(inputfile, remain)) {
        printf("openCL create fail !!!!!!");
        return 0;
    }
    int width = 256, height = 256;
    //int width = 512, height = 512; 
    unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
    unsigned char *dst_data = (unsigned char *)malloc(sizeof(unsigned char) * width * height);
    for (int i = 0; i < width * height; i++) {
        src_data[i] = rand() % 100 + 1;
    }

    unsigned char (*yPlane)[height][width] = (unsigned char (*)[height][width])src_data;
    unsigned char (*dst)[height][width] = (unsigned char (*)[height][width])dst_data;

#ifdef TIME_PROF
    //total = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif
    sharpness_total(height, width,(unsigned char*) yPlane,(unsigned char*) dst);

    //sharpness_total(yPlane, dst);
    sharpness_total(height, width, (unsigned char*) yPlane,(unsigned char*) dst);



#ifdef TIME_PROF
    printf("------Total time(ms)------\ndown = %f\nup_gpu = %f\nup_row=%f\nup_col=%f\nsobel = %f\nmean = %f\nsharpness = %f\n",total.down_time, total.up_time, total.up_row_time, total.up_col_time, total.sobel_time, total.mean_time, total.sharp_time);
    printf("------Kernel time(ms)------\ndown = %f\nup_col = %f\nup_row=%f\nup=%f\nsobel = %f\nmean = %f\nsharpness = %f\n",total.kernel_down, total.kernel_up_col, total.kernel_up_row, total.kernel_up, total.kernel_sobel, total.kernel_mean, total.kernel_sharpness);



#endif


    dst_data = (unsigned char *)dst;

    return 0;
}

