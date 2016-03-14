/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include<stdlib.h>

#define ROWS 1024
#define COLS 1024
#define M 1024
#define N 1024

struct __MMC_CSE_PARAMETER_PUBLIC {
  float peak;
  float cutoffCoef;
  float cutoff2;
  float cutoff3Coef;
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
int DownScaleNewX16(unsigned char (*pImageSrc)[1024][1024], unsigned char (*pImageDst)[1024 / 4][1024 / 4]) {
    unsigned char **yPlane=allocu(1024,1024);
    unsigned char** yPlaneDown=allocu(256,256);

    for(int i=0;i<1024;i++)
        for(int j=0;j<1024;j++)
            yPlane[i][j]=((unsigned char*)pImageSrc)[i*1024+j];

    printf("ss\n");
    DownScaleNewX16_cpu(yPlane,256, 256,  yPlaneDown);

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
        checkErr(status, "clCreateKernel for kernel_1");
        global_work_size[0] = 256;
        global_work_size[1] = 256;
        size_t pImageSrcSrcWidth = 1024;
        size_t pImageSrcSrcHeight = 1024;
        size_t pImageSrc_srcsz = sizeof(unsigned char);
        size_t pImageSrcSrcStep = pImageSrcSrcWidth * pImageSrc_srcsz;
        pImageSrcSrcStep = (pImageSrcSrcStep % PADDING < 16) ? ((pImageSrcSrcStep / PADDING+1) * PADDING) : ((pImageSrcSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t pImageSrcSrcShift = pImageSrcSrcStep * PADDING_LINE;
        size_t pImageSrc_srcsz0Pad = pImageSrcSrcStep * (pImageSrcSrcHeight + (PADDING_LINE<<1));
        cl_mem pImageSrcsrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, pImageSrc_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = pImageSrcSrcWidth;
        region[1] = pImageSrcSrcHeight;
        buffer_row_pitch = pImageSrcSrcWidth;
        buffer_slice_pitch = pImageSrc_srcsz0Pad;
        host_row_pitch = pImageSrcSrcWidth;
        host_slice_pitch = pImageSrcSrcWidth * pImageSrcSrcHeight;
        unsigned char *pImageSrcSrcBufH = (unsigned char*)malloc(pImageSrc_srcsz0Pad); 
        for(int i = 0; i < pImageSrcSrcHeight; i++){
            memcpy( (unsigned char*)pImageSrcSrcBufH+ (i + PADDING_LINE) * pImageSrcSrcStep, (unsigned char*)pImageSrc+ i * pImageSrcSrcWidth, pImageSrcSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, pImageSrcsrcBuf, CL_TRUE, 0,pImageSrc_srcsz0Pad,pImageSrcSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t pImageDstDstWidth = 256;
        size_t pImageDstDstHeight = 256;
        size_t pImageDst_dstsz = sizeof(unsigned char);
        size_t Readsize = pImageDstDstWidth * pImageDstDstHeight * pImageDst_dstsz;
        size_t pImageDstDstStep = pImageDstDstWidth * pImageDst_dstsz;
        pImageDstDstStep = (pImageDstDstStep % PADDING < 16) ? ((pImageDstDstStep / PADDING+1) * PADDING) : ((pImageDstDstStep + PADDING) / PADDING+1) * PADDING;
        size_t pImageDstDstShift = pImageDstDstStep * PADDING_LINE;
        size_t pImageDst_dstsz0Pad = pImageDstDstStep * (pImageDstDstHeight + (PADDING_LINE<<1));
        cl_mem pImageDstdstBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, pImageDst_dstsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = pImageDstDstWidth;
        region[1] = pImageDstDstHeight;
        buffer_row_pitch = pImageDstDstWidth;
        buffer_slice_pitch = pImageDst_dstsz0Pad;
        host_row_pitch = pImageDstDstWidth;
        host_slice_pitch = pImageDstDstWidth * pImageDstDstHeight;
        unsigned char *pImageDstDstBufH = (unsigned char*)malloc(pImageDst_dstsz0Pad); 
        for(int i = 0; i < pImageDstDstHeight; i++){
            memcpy( (unsigned char*)pImageDstDstBufH+ (i + PADDING_LINE) * pImageDstDstStep,(unsigned char*)pImageDst + i * pImageDstDstWidth,pImageDstDstWidth);
        }
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
        status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_1");
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = pImageDstDstWidth;
        out_region[1] = pImageDstDstHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = pImageDstDstStep;
        size_t out_buffer_slice_pitch = pImageDst_dstsz0Pad;
        size_t out_host_row_pitch = pImageDstDstWidth * pImageDst_dstsz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, pImageDstdstBuf, CL_TRUE, 0,pImageDst_dstsz0Pad,pImageDstDstBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < pImageDstDstHeight; i++){
            memcpy( (unsigned char*)pImageDst+ i *pImageDstDstWidth,(unsigned char*) pImageDstDstBufH+ (i + PADDING_LINE)* pImageDstDstStep,pImageDstDstWidth);
        }

    }

    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            if(yPlaneDown[i][j] !=((unsigned char*) pImageDst)[i* 256 +j])
            {
                    printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneDown[i][j], (int)((unsigned char*) pImageDst)[i* 256 +j]);
                //printf("%u ",yPlaneDown[i][j]);


              //  abort();

            }
        }
        //printf("\n");

    }
    printf("down success\n");
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
  *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=srcImage[height-1][0];
  pDst1=pDst2-2;
  pDst2=pDst3-2;
  pDst3=pDst4-2;
  pDst4=pDst4+dstWidth-2;
  *pDst1=*(pDst1+1)=*pDst2=*(pDst2+1)=*pDst3=*(pDst3+1)=*pDst4=*(pDst4+1)=srcImage[height-1][width-1];
  
  /*
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
*/

	return 0;
}



int UpScaleNewX16(unsigned char (*srcImage)[1024 / 4][1024 / 4], unsigned char (*dstImage)[1024][1024]) {

    unsigned char **yPlane=allocu(256,256);
    unsigned char** yPlaneUp=allocu(1024,1024);

    for(int i=0;i<256;i++)
        for(int j=0;j<256;j++)
            yPlane[i][j]=((unsigned char*)srcImage)[i*256+j];

    printf("ss\n");
    UpScaleNewX16_cpu(yPlane,256, 256, yPlaneUp);


    //TODO // Done
    float border_mp_0[4][1] = { 1., 3 / 4.0f, 2 / 4.0f, 1 / 4.0f };
    float border_mp_1[4][1] = { 0., 1 / 4.0f, 2 / 4.0f, 3 / 4.0f };

    {
        size_t global_work_size[2];
        //TODO delete  // Done
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
        checkErr(status, "clCreateKernel for kernel_2");
        //TODO: *****Done
        global_work_size[0] = 1;
        global_work_size[1] = 256;
        size_t srcImageSrcWidth = 256;
        size_t srcImageSrcHeight = 256;
        size_t srcImage_srcsz = sizeof(unsigned char);
        size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
        srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
        size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
        //TODO:wrong ****Done
        //cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, srcImage_srcsz0Pad, NULL, &status);
        cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, srcImage_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        //TODO delete
        region[0] = srcImageSrcWidth;
        region[1] = srcImageSrcHeight;
        buffer_row_pitch = srcImageSrcWidth;
        buffer_slice_pitch = srcImage_srcsz0Pad;
        host_row_pitch = srcImageSrcWidth;
        host_slice_pitch = srcImageSrcWidth * srcImageSrcHeight;
        unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
        for(int i = 0; i < srcImageSrcHeight; i++){
            memcpy( (unsigned char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (unsigned char*)srcImage+ i * srcImageSrcWidth, srcImageSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        //TODO:
        size_t border_mp_0SrcWidth = 1;
        size_t border_mp_0SrcHeight = 4;
        size_t border_mp_0_srcsz = sizeof(float);
        size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
        border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
        size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
        size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));
        //TODO:wrong   **** Done
        //cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
        cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = border_mp_0SrcWidth;
        region[1] = border_mp_0SrcHeight;
        buffer_row_pitch = border_mp_0SrcWidth;
        buffer_slice_pitch = border_mp_0_srcsz0Pad;
        host_row_pitch = border_mp_0SrcWidth;
        host_slice_pitch = border_mp_0SrcWidth * border_mp_0SrcHeight;
        float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
        //TODO: ****Done.
        //for(int i = 0; i < border_mp_0SrcHeight; i++){
         //   memcpy( (unsigned char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (unsigned char*)border_mp_0+ i * border_mp_0SrcWidth, border_mp_0SrcWidth);
        //}

        for(int i = 0; i < border_mp_0SrcHeight; i++){
            memcpy( (unsigned char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (unsigned char*)border_mp_0+ i * border_mp_0SrcWidth*sizeof(float), border_mp_0SrcWidth*sizeof(float));
        }

       // printf("mpsrc = %f, %f , %f\n", *((float*)border_mp_0),*((float*)border_mp_0 +  border_mp_0SrcWidth),*(( float*)border_mp_0 +  2*border_mp_0SrcWidth));

        for(int i = 0; i < 4; i++)
            printf("mp = %f\n", *((float*)((unsigned char *)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep)));

        status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
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
        size_t border_mp_1SrcWidth = 1;
        size_t border_mp_1SrcHeight = 4;
        size_t border_mp_1_srcsz = sizeof(float);
        size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
        border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
        size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
        size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
        //TODO:wrong ****Done.
        //cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
        cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        //TODO delete ****Done
        region[0] = border_mp_1SrcWidth;
        region[1] = border_mp_1SrcHeight;
        buffer_row_pitch = border_mp_1SrcWidth;
        buffer_slice_pitch = border_mp_1_srcsz0Pad;
        host_row_pitch = border_mp_1SrcWidth;
        host_slice_pitch = border_mp_1SrcWidth * border_mp_1SrcHeight;
        float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
        //TODO:wrong **** Done.
        //for(int i = 0; i < border_mp_1SrcHeight; i++){
         //   memcpy( (unsigned char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (unsigned char*)border_mp_1+ i * border_mp_1SrcWidth, border_mp_1SrcWidth);
        //}

        for(int i = 0; i < border_mp_1SrcHeight; i++){
            memcpy( (unsigned char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (unsigned char*)border_mp_1+ i * border_mp_1SrcWidth*sizeof(float), border_mp_1SrcWidth*sizeof(float));
        }
        status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t dstImageDSWidth = 1024;
        size_t dstImageDSHeight = 1024;
        size_t dstImage_dssz = sizeof(unsigned char);
        size_t Readsize = dstImageDSWidth * dstImageDSHeight * dstImage_dssz;
        size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
        dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
        size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
        size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
        cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, dstImage_dssz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = dstImageDSWidth;
        region[1] = dstImageDSHeight;
        buffer_row_pitch = dstImageDSWidth;
        buffer_slice_pitch = dstImage_dssz0Pad;
        host_row_pitch = dstImageDSWidth;
        host_slice_pitch = dstImageDSWidth * dstImageDSHeight;
        unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
        for(int i = 0; i < dstImageDSHeight; i++){
            memcpy((unsigned char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (unsigned char*)dstImage+ i * dstImageDSWidth, dstImageDSWidth);
        }
        //TODO: delete
        //status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);
        //checkErr(status, "clWriteBuffer");
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
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_2");
        //TODO:delete
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = dstImageDSWidth;
        out_region[1] = dstImageDSHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = dstImageDSStep;
        size_t out_buffer_slice_pitch = dstImage_dssz0Pad;
        size_t out_host_row_pitch = dstImageDSWidth * dstImage_dssz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < dstImageDSHeight; i++){
            memcpy( (unsigned char*)dstImage+ i *dstImageDSWidth,(unsigned char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep,dstImageDSWidth);
        }

    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
       //     if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* 1024 +j])
            {
        //            printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* 1024 +j]);
                printf("%u ",((unsigned char*)srcImage)[i* 256 +j]);


         //       abort();

            }
        }
        printf("\n");

    }
        printf("\n");
        printf("\n");
        printf("\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
       //     if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* 1024 +j])
            {
        //            printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* 1024 +j]);
                printf("%u ",((unsigned char*) dstImage)[i* 1024 +j]);


         //       abort();

            }
        }
        printf("\n");

    }
        printf("\n");
        printf("\n");
        printf("\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
       //     if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* 1024 +j])
            {
        //            printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* 1024 +j]);
                printf("%u ",yPlaneUp[i][j]);


         //       abort();

            }
        }
        printf("\n");

    }

        printf("\n");
        printf("\n");
        printf("\n");

    for(int i = 0; i < 1024; i++)
    {
        for(int j = 0; j < 1024; j++)
        {
            if(yPlaneUp[i][j] !=((unsigned char*) dstImage)[i* 1024 +j])
            {
                    printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)yPlaneUp[i][j], (int)((unsigned char*) dstImage)[i* 1024 +j]);
                //printf("%u ",yPlaneDown[i][j]);


                abort();

            }
        }
        //printf("\n");

    }
    printf("success\n");

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
        checkErr(status, "clCreateKernel for kernel_3");
        global_work_size[0] = 1;
        global_work_size[1] = 256;
        size_t srcImageSrcWidth = 256;
        size_t srcImageSrcHeight = 256;
        size_t srcImage_srcsz = sizeof(unsigned char);
        size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
        srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
        size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
        cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, srcImage_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = srcImageSrcWidth;
        region[1] = srcImageSrcHeight;
        buffer_row_pitch = srcImageSrcWidth;
        buffer_slice_pitch = srcImage_srcsz0Pad;
        host_row_pitch = srcImageSrcWidth;
        host_slice_pitch = srcImageSrcWidth * srcImageSrcHeight;
        unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
        for(int i = 0; i < srcImageSrcHeight; i++){
            memcpy( (unsigned char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (unsigned char*)srcImage+ i * srcImageSrcWidth, srcImageSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t border_mp_0SrcWidth = 1;
        size_t border_mp_0SrcHeight = 4;
        size_t border_mp_0_srcsz = sizeof(float);
        size_t border_mp_0SrcStep = border_mp_0SrcWidth * border_mp_0_srcsz;
        border_mp_0SrcStep = (border_mp_0SrcStep % PADDING < 16) ? ((border_mp_0SrcStep / PADDING+1) * PADDING) : ((border_mp_0SrcStep + PADDING) / PADDING+1) * PADDING;
        size_t border_mp_0SrcShift = border_mp_0SrcStep * PADDING_LINE;
        size_t border_mp_0_srcsz0Pad = border_mp_0SrcStep * (border_mp_0SrcHeight + (PADDING_LINE<<1));
        cl_mem border_mp_0srcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, border_mp_0_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = border_mp_0SrcWidth;
        region[1] = border_mp_0SrcHeight;
        buffer_row_pitch = border_mp_0SrcWidth;
        buffer_slice_pitch = border_mp_0_srcsz0Pad;
        host_row_pitch = border_mp_0SrcWidth;
        host_slice_pitch = border_mp_0SrcWidth * border_mp_0SrcHeight;
        float *border_mp_0SrcBufH = (float*)malloc(border_mp_0_srcsz0Pad); 
        for(int i = 0; i < border_mp_0SrcHeight; i++){
            memcpy( (unsigned char*)border_mp_0SrcBufH+ (i + PADDING_LINE) * border_mp_0SrcStep, (unsigned char*)border_mp_0+ i * border_mp_0SrcWidth, border_mp_0SrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, border_mp_0srcBuf, CL_TRUE, 0,border_mp_0_srcsz0Pad,border_mp_0SrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t border_mp_1SrcWidth = 1;
        size_t border_mp_1SrcHeight = 4;
        size_t border_mp_1_srcsz = sizeof(float);
        size_t border_mp_1SrcStep = border_mp_1SrcWidth * border_mp_1_srcsz;
        border_mp_1SrcStep = (border_mp_1SrcStep % PADDING < 16) ? ((border_mp_1SrcStep / PADDING+1) * PADDING) : ((border_mp_1SrcStep + PADDING) / PADDING+1) * PADDING;
        size_t border_mp_1SrcShift = border_mp_1SrcStep * PADDING_LINE;
        size_t border_mp_1_srcsz0Pad = border_mp_1SrcStep * (border_mp_1SrcHeight + (PADDING_LINE<<1));
        cl_mem border_mp_1srcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, border_mp_1_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = border_mp_1SrcWidth;
        region[1] = border_mp_1SrcHeight;
        buffer_row_pitch = border_mp_1SrcWidth;
        buffer_slice_pitch = border_mp_1_srcsz0Pad;
        host_row_pitch = border_mp_1SrcWidth;
        host_slice_pitch = border_mp_1SrcWidth * border_mp_1SrcHeight;
        float *border_mp_1SrcBufH = (float*)malloc(border_mp_1_srcsz0Pad); 
        for(int i = 0; i < border_mp_1SrcHeight; i++){
            memcpy( (unsigned char*)border_mp_1SrcBufH+ (i + PADDING_LINE) * border_mp_1SrcStep, (unsigned char*)border_mp_1+ i * border_mp_1SrcWidth, border_mp_1SrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, border_mp_1srcBuf, CL_TRUE, 0,border_mp_1_srcsz0Pad,border_mp_1SrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t dstImageDSWidth = 1024;
        size_t dstImageDSHeight = 1024;
        size_t dstImage_dssz = sizeof(unsigned char);
        size_t Readsize = dstImageDSWidth * dstImageDSHeight * dstImage_dssz;
        size_t dstImageDSStep = dstImageDSWidth * dstImage_dssz;
        dstImageDSStep = (dstImageDSStep % PADDING < 16) ? ((dstImageDSStep / PADDING+1) * PADDING) : ((dstImageDSStep + PADDING) / PADDING+1) * PADDING;
        size_t dstImageDSShift = dstImageDSStep * PADDING_LINE;
        size_t dstImage_dssz0Pad = dstImageDSStep * (dstImageDSHeight + (PADDING_LINE<<1));
        cl_mem dstImagedsBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, dstImage_dssz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = dstImageDSWidth;
        region[1] = dstImageDSHeight;
        buffer_row_pitch = dstImageDSWidth;
        buffer_slice_pitch = dstImage_dssz0Pad;
        host_row_pitch = dstImageDSWidth;
        host_slice_pitch = dstImageDSWidth * dstImageDSHeight;
        unsigned char *dstImageDsBufH = (unsigned char*)malloc (dstImage_dssz0Pad); 
        for(int i = 0; i < dstImageDSHeight; i++){
            memcpy((unsigned char*)dstImageDsBufH + (i + PADDING_LINE) * dstImageDSStep, (unsigned char*)dstImage+ i * dstImageDSWidth, dstImageDSWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad, dstImageDsBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_3");
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = dstImageDSWidth;
        out_region[1] = dstImageDSHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = dstImageDSStep;
        size_t out_buffer_slice_pitch = dstImage_dssz0Pad;
        size_t out_host_row_pitch = dstImageDSWidth * dstImage_dssz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, dstImagedsBuf, CL_TRUE, 0,dstImage_dssz0Pad,dstImageDsBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < dstImageDSHeight; i++){
            memcpy( (unsigned char*)dstImage+ i *dstImageDSWidth,(unsigned char*) dstImageDsBufH+ (i + PADDING_LINE)* dstImageDSStep,dstImageDSWidth);
        }

    }
    char mp[4][2] = { 7 / 8, 1 / 8, 5 / 8, 3 / 8, 3 / 8, 5 / 8, 1 / 8, 7 / 8 };

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_4 = clCreateKernel(g_program, "kernel_4", &status);
        checkErr(status, "clCreateKernel for kernel_4");
        global_work_size[0] = 256;
        global_work_size[1] = 256;
        size_t srcImageSrcWidth = 256;
        size_t srcImageSrcHeight = 256;
        size_t srcImage_srcsz = sizeof(unsigned char);
        size_t srcImageSrcStep = srcImageSrcWidth * srcImage_srcsz;
        srcImageSrcStep = (srcImageSrcStep % PADDING < 16) ? ((srcImageSrcStep / PADDING+1) * PADDING) : ((srcImageSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t srcImageSrcShift = srcImageSrcStep * PADDING_LINE;
        size_t srcImage_srcsz0Pad = srcImageSrcStep * (srcImageSrcHeight + (PADDING_LINE<<1));
        cl_mem srcImagesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, srcImage_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = srcImageSrcWidth;
        region[1] = srcImageSrcHeight;
        buffer_row_pitch = srcImageSrcWidth;
        buffer_slice_pitch = srcImage_srcsz0Pad;
        host_row_pitch = srcImageSrcWidth;
        host_slice_pitch = srcImageSrcWidth * srcImageSrcHeight;
        unsigned char *srcImageSrcBufH = (unsigned char*)malloc(srcImage_srcsz0Pad); 
        for(int i = 0; i < srcImageSrcHeight; i++){
            memcpy( (unsigned char*)srcImageSrcBufH+ (i + PADDING_LINE) * srcImageSrcStep, (unsigned char*)srcImage+ i * srcImageSrcWidth, srcImageSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, srcImagesrcBuf, CL_TRUE, 0,srcImage_srcsz0Pad,srcImageSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t mpSrcWidth = 2;
        size_t mpSrcHeight = 4;
        size_t mp_srcsz = sizeof(char);
        size_t mpSrcStep = mpSrcWidth * mp_srcsz;
        mpSrcStep = (mpSrcStep % PADDING < 16) ? ((mpSrcStep / PADDING+1) * PADDING) : ((mpSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t mpSrcShift = mpSrcStep * PADDING_LINE;
        size_t mp_srcsz0Pad = mpSrcStep * (mpSrcHeight + (PADDING_LINE<<1));
        cl_mem mpsrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, mp_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = mpSrcWidth;
        region[1] = mpSrcHeight;
        buffer_row_pitch = mpSrcWidth;
        buffer_slice_pitch = mp_srcsz0Pad;
        host_row_pitch = mpSrcWidth;
        host_slice_pitch = mpSrcWidth * mpSrcHeight;
        char *mpSrcBufH = (char*)malloc(mp_srcsz0Pad); 
        for(int i = 0; i < mpSrcHeight; i++){
            memcpy( (unsigned char*)mpSrcBufH+ (i + PADDING_LINE) * mpSrcStep, (unsigned char*)mp+ i * mpSrcWidth, mpSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, mpsrcBuf, CL_TRUE, 0,mp_srcsz0Pad,mpSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t dstImageDstWidth = 1024;
        size_t dstImageDstHeight = 1024;
        size_t dstImage_dstsz = sizeof(unsigned char);
        size_t Readsize = dstImageDstWidth * dstImageDstHeight * dstImage_dstsz;
        size_t dstImageDstStep = dstImageDstWidth * dstImage_dstsz;
        dstImageDstStep = (dstImageDstStep % PADDING < 16) ? ((dstImageDstStep / PADDING+1) * PADDING) : ((dstImageDstStep + PADDING) / PADDING+1) * PADDING;
        size_t dstImageDstShift = dstImageDstStep * PADDING_LINE;
        size_t dstImage_dstsz0Pad = dstImageDstStep * (dstImageDstHeight + (PADDING_LINE<<1));
        cl_mem dstImagedstBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, dstImage_dstsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = dstImageDstWidth;
        region[1] = dstImageDstHeight;
        buffer_row_pitch = dstImageDstWidth;
        buffer_slice_pitch = dstImage_dstsz0Pad;
        host_row_pitch = dstImageDstWidth;
        host_slice_pitch = dstImageDstWidth * dstImageDstHeight;
        unsigned char *dstImageDstBufH = (unsigned char*)malloc(dstImage_dstsz0Pad); 
        for(int i = 0; i < dstImageDstHeight; i++){
            memcpy( (unsigned char*)dstImageDstBufH+ (i + PADDING_LINE) * dstImageDstStep,(unsigned char*)dstImage + i * dstImageDstWidth,dstImageDstWidth);
        }
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
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_4");
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = dstImageDstWidth;
        out_region[1] = dstImageDstHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = dstImageDstStep;
        size_t out_buffer_slice_pitch = dstImage_dstsz0Pad;
        size_t out_host_row_pitch = dstImageDstWidth * dstImage_dstsz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, dstImagedstBuf, CL_TRUE, 0,dstImage_dstsz0Pad,dstImageDstBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < dstImageDstHeight; i++){
            memcpy( (unsigned char*)dstImage+ i *dstImageDstWidth,(unsigned char*) dstImageDstBufH+ (i + PADDING_LINE)* dstImageDstStep,dstImageDstWidth);
        }

    }
}



void Sharpness(unsigned char (*yPlane)[1024][1024], unsigned char (*yPlaneCSER)[1024][1024], unsigned char (*dst)[1024][1024], MMC_CSE_PARAMETER_PUBLIC &cseParamPublic) {
    unsigned short pEdge[1024][1024];
    char gx[3][3] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    char gy[3][3] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_5 = clCreateKernel(g_program, "kernel_5", &status);
        checkErr(status, "clCreateKernel for kernel_5");
        global_work_size[0] = 256;
        global_work_size[1] = 1024;
        size_t yPlaneSrcWidth = 1024;
        size_t yPlaneSrcHeight = 1024;
        size_t yPlane_srcsz = sizeof(unsigned char);
        size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
        yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
        size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
        cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, yPlane_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = yPlaneSrcWidth;
        region[1] = yPlaneSrcHeight;
        buffer_row_pitch = yPlaneSrcWidth;
        buffer_slice_pitch = yPlane_srcsz0Pad;
        host_row_pitch = yPlaneSrcWidth;
        host_slice_pitch = yPlaneSrcWidth * yPlaneSrcHeight;
        unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
        for(int i = 0; i < yPlaneSrcHeight; i++){
            memcpy( (unsigned char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (unsigned char*)yPlane+ i * yPlaneSrcWidth, yPlaneSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t gxSrcWidth = 3;
        size_t gxSrcHeight = 3;
        size_t gx_srcsz = sizeof(char);
        size_t gxSrcStep = gxSrcWidth * gx_srcsz;
        gxSrcStep = (gxSrcStep % PADDING < 16) ? ((gxSrcStep / PADDING+1) * PADDING) : ((gxSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t gxSrcShift = gxSrcStep * PADDING_LINE;
        size_t gx_srcsz0Pad = gxSrcStep * (gxSrcHeight + (PADDING_LINE<<1));
        cl_mem gxsrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, gx_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = gxSrcWidth;
        region[1] = gxSrcHeight;
        buffer_row_pitch = gxSrcWidth;
        buffer_slice_pitch = gx_srcsz0Pad;
        host_row_pitch = gxSrcWidth;
        host_slice_pitch = gxSrcWidth * gxSrcHeight;
        char *gxSrcBufH = (char*)malloc(gx_srcsz0Pad); 
        for(int i = 0; i < gxSrcHeight; i++){
            memcpy( (unsigned char*)gxSrcBufH+ (i + PADDING_LINE) * gxSrcStep, (unsigned char*)gx+ i * gxSrcWidth, gxSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, gxsrcBuf, CL_TRUE, 0,gx_srcsz0Pad,gxSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t gySrcWidth = 3;
        size_t gySrcHeight = 3;
        size_t gy_srcsz = sizeof(char);
        size_t gySrcStep = gySrcWidth * gy_srcsz;
        gySrcStep = (gySrcStep % PADDING < 16) ? ((gySrcStep / PADDING+1) * PADDING) : ((gySrcStep + PADDING) / PADDING+1) * PADDING;
        size_t gySrcShift = gySrcStep * PADDING_LINE;
        size_t gy_srcsz0Pad = gySrcStep * (gySrcHeight + (PADDING_LINE<<1));
        cl_mem gysrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, gy_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = gySrcWidth;
        region[1] = gySrcHeight;
        buffer_row_pitch = gySrcWidth;
        buffer_slice_pitch = gy_srcsz0Pad;
        host_row_pitch = gySrcWidth;
        host_slice_pitch = gySrcWidth * gySrcHeight;
        char *gySrcBufH = (char*)malloc(gy_srcsz0Pad); 
        for(int i = 0; i < gySrcHeight; i++){
            memcpy( (unsigned char*)gySrcBufH+ (i + PADDING_LINE) * gySrcStep, (unsigned char*)gy+ i * gySrcWidth, gySrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, gysrcBuf, CL_TRUE, 0,gy_srcsz0Pad,gySrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t pEdgeDstWidth = 1024;
        size_t pEdgeDstHeight = 1024;
        size_t pEdge_dstsz = sizeof(unsigned short);
        size_t Readsize = pEdgeDstWidth * pEdgeDstHeight * pEdge_dstsz;
        size_t pEdgeDstStep = pEdgeDstWidth * pEdge_dstsz;
        pEdgeDstStep = (pEdgeDstStep % PADDING < 16) ? ((pEdgeDstStep / PADDING+1) * PADDING) : ((pEdgeDstStep + PADDING) / PADDING+1) * PADDING;
        size_t pEdgeDstShift = pEdgeDstStep * PADDING_LINE;
        size_t pEdge_dstsz0Pad = pEdgeDstStep * (pEdgeDstHeight + (PADDING_LINE<<1));
        cl_mem pEdgedstBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, pEdge_dstsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = pEdgeDstWidth;
        region[1] = pEdgeDstHeight;
        buffer_row_pitch = pEdgeDstWidth;
        buffer_slice_pitch = pEdge_dstsz0Pad;
        host_row_pitch = pEdgeDstWidth;
        host_slice_pitch = pEdgeDstWidth * pEdgeDstHeight;
        unsigned short *pEdgeDstBufH = (unsigned short*)malloc(pEdge_dstsz0Pad); 
        for(int i = 0; i < pEdgeDstHeight; i++){
            memcpy( (unsigned char*)pEdgeDstBufH+ (i + PADDING_LINE) * pEdgeDstStep,(unsigned char*)pEdge + i * pEdgeDstWidth,pEdgeDstWidth);
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
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_5");
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = pEdgeDstWidth;
        out_region[1] = pEdgeDstHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = pEdgeDstStep;
        size_t out_buffer_slice_pitch = pEdge_dstsz0Pad;
        size_t out_host_row_pitch = pEdgeDstWidth * pEdge_dstsz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, pEdgedstBuf, CL_TRUE, 0,pEdge_dstsz0Pad,pEdgeDstBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < pEdgeDstHeight; i++){
            memcpy( (unsigned char*)pEdge+ i *pEdgeDstWidth,(unsigned char*) pEdgeDstBufH+ (i + PADDING_LINE)* pEdgeDstStep,pEdgeDstWidth);
        }

    }

    unsigned short item;

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_6 = clCreateKernel(g_program, "kernel_6", &status);
        checkErr(status, "clCreateKernel for kernel_6");
        size_t pEdgeSrcWidth = 1024;
        size_t pEdgeSrcHeight = 1024;
        global_work_size[0] = 512;
        global_work_size[1] = 1024;
        size_t local_work_size[2];
        local_work_size[0] = 256;
        local_work_size[1] = 1;
        size_t pEdge_srcsz = sizeof(unsigned short);
        size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
        pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
        size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
        cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, pEdge_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = pEdgeSrcWidth;
        region[1] = pEdgeSrcHeight;
        buffer_row_pitch = pEdgeSrcWidth;
        buffer_slice_pitch = pEdge_srcsz0Pad;
        host_row_pitch = pEdgeSrcWidth;
        host_slice_pitch = pEdgeSrcWidth * pEdgeSrcHeight;
        unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
        for(int i = 0; i < pEdgeSrcHeight; i++){
            memcpy( (unsigned char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (unsigned char*)pEdge+ i * pEdgeSrcWidth, pEdgeSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        cl_mem outputBuffer2 = clCreateBuffer(g_context, CL_MEM_READ_WRITE, sizeof(unsigned short), NULL, &status);
        checkErr(status,"clCreateBuffer");
        status = clSetKernelArg(kernel_6, 5, sizeof(cl_mem), (void *)&outputBuffer2);
        checkErr(status,"clSetKernelArg");
        status = clSetKernelArg(kernel_6, 6, sizeof(unsigned short) * local_work_size[0] * local_work_size[1], NULL);
        checkErr(status,"clSetKernelArg");
        status = clEnqueueNDRangeKernel(g_queue, kernel_6, 2, NULL, global_work_size, local_work_size, 0, NULL, &event_kernel);
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_6");
        status = clEnqueueReadBuffer(g_queue, outputBuffer2, CL_TRUE, 0, sizeof(unsigned short), &item, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");

    }
    short mean = item / (1024 * 1024) + 1 / 2;
    cseParamPublic.cutoff2 = 256.F;
    cseParamPublic.cutoff3Coef = 1.F;
    cseParamPublic.cutoffCoef = 1.F;
    cseParamPublic.peak = 2.F;
    float weight_tmp = (1 / cseParamPublic.cutoff2);
    float strength_tmp = 1 / cseParamPublic.cutoffCoef * mean;
    float tmp2 = cseParamPublic.peak - 1.;
    float cutoff2Order = pow(cseParamPublic.cutoff3Coef * mean, 4);

    float m1 = 1. / mean;
    m1 = m1 * m1 * m1 * m1;
    float m2 = 1. / 256;
    m2 = m2 * m2 * m2 * m2;

    {
        size_t global_work_size[2];
        size_t buffer_origin[3] = {1, 1, 0};
        size_t host_origin[3] = {0, 0, 0};
        size_t region[3] = {0, 0, 1};
        size_t buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch;
        cl_event event_kernel;
        cl_kernel kernel_7 = clCreateKernel(g_program, "kernel_7", &status);
        checkErr(status, "clCreateKernel for kernel_7");
        global_work_size[0] = 256;
        global_work_size[1] = 1024;
        size_t yPlaneSrcWidth = 1024;
        size_t yPlaneSrcHeight = 1024;
        size_t yPlane_srcsz = sizeof(unsigned char);
        size_t yPlaneSrcStep = yPlaneSrcWidth * yPlane_srcsz;
        yPlaneSrcStep = (yPlaneSrcStep % PADDING < 16) ? ((yPlaneSrcStep / PADDING+1) * PADDING) : ((yPlaneSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t yPlaneSrcShift = yPlaneSrcStep * PADDING_LINE;
        size_t yPlane_srcsz0Pad = yPlaneSrcStep * (yPlaneSrcHeight + (PADDING_LINE<<1));
        cl_mem yPlanesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, yPlane_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = yPlaneSrcWidth;
        region[1] = yPlaneSrcHeight;
        buffer_row_pitch = yPlaneSrcWidth;
        buffer_slice_pitch = yPlane_srcsz0Pad;
        host_row_pitch = yPlaneSrcWidth;
        host_slice_pitch = yPlaneSrcWidth * yPlaneSrcHeight;
        unsigned char *yPlaneSrcBufH = (unsigned char*)malloc(yPlane_srcsz0Pad); 
        for(int i = 0; i < yPlaneSrcHeight; i++){
            memcpy( (unsigned char*)yPlaneSrcBufH+ (i + PADDING_LINE) * yPlaneSrcStep, (unsigned char*)yPlane+ i * yPlaneSrcWidth, yPlaneSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, yPlanesrcBuf, CL_TRUE, 0,yPlane_srcsz0Pad,yPlaneSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t yPlaneCSERSrcWidth = 1024;
        size_t yPlaneCSERSrcHeight = 1024;
        size_t yPlaneCSER_srcsz = sizeof(unsigned char);
        size_t yPlaneCSERSrcStep = yPlaneCSERSrcWidth * yPlaneCSER_srcsz;
        yPlaneCSERSrcStep = (yPlaneCSERSrcStep % PADDING < 16) ? ((yPlaneCSERSrcStep / PADDING+1) * PADDING) : ((yPlaneCSERSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t yPlaneCSERSrcShift = yPlaneCSERSrcStep * PADDING_LINE;
        size_t yPlaneCSER_srcsz0Pad = yPlaneCSERSrcStep * (yPlaneCSERSrcHeight + (PADDING_LINE<<1));
        cl_mem yPlaneCSERsrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, yPlaneCSER_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = yPlaneCSERSrcWidth;
        region[1] = yPlaneCSERSrcHeight;
        buffer_row_pitch = yPlaneCSERSrcWidth;
        buffer_slice_pitch = yPlaneCSER_srcsz0Pad;
        host_row_pitch = yPlaneCSERSrcWidth;
        host_slice_pitch = yPlaneCSERSrcWidth * yPlaneCSERSrcHeight;
        unsigned char *yPlaneCSERSrcBufH = (unsigned char*)malloc(yPlaneCSER_srcsz0Pad); 
        for(int i = 0; i < yPlaneCSERSrcHeight; i++){
            memcpy( (unsigned char*)yPlaneCSERSrcBufH+ (i + PADDING_LINE) * yPlaneCSERSrcStep, (unsigned char*)yPlaneCSER+ i * yPlaneCSERSrcWidth, yPlaneCSERSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, yPlaneCSERsrcBuf, CL_TRUE, 0,yPlaneCSER_srcsz0Pad,yPlaneCSERSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t pEdgeSrcWidth = 1024;
        size_t pEdgeSrcHeight = 1024;
        size_t pEdge_srcsz = sizeof(unsigned short);
        size_t pEdgeSrcStep = pEdgeSrcWidth * pEdge_srcsz;
        pEdgeSrcStep = (pEdgeSrcStep % PADDING < 16) ? ((pEdgeSrcStep / PADDING+1) * PADDING) : ((pEdgeSrcStep + PADDING) / PADDING+1) * PADDING;
        size_t pEdgeSrcShift = pEdgeSrcStep * PADDING_LINE;
        size_t pEdge_srcsz0Pad = pEdgeSrcStep * (pEdgeSrcHeight + (PADDING_LINE<<1));
        cl_mem pEdgesrcBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, pEdge_srcsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = pEdgeSrcWidth;
        region[1] = pEdgeSrcHeight;
        buffer_row_pitch = pEdgeSrcWidth;
        buffer_slice_pitch = pEdge_srcsz0Pad;
        host_row_pitch = pEdgeSrcWidth;
        host_slice_pitch = pEdgeSrcWidth * pEdgeSrcHeight;
        unsigned short *pEdgeSrcBufH = (unsigned short*)malloc(pEdge_srcsz0Pad); 
        for(int i = 0; i < pEdgeSrcHeight; i++){
            memcpy( (unsigned char*)pEdgeSrcBufH+ (i + PADDING_LINE) * pEdgeSrcStep, (unsigned char*)pEdge+ i * pEdgeSrcWidth, pEdgeSrcWidth);
        }
        status = clEnqueueWriteBuffer(g_queue, pEdgesrcBuf, CL_TRUE, 0,pEdge_srcsz0Pad,pEdgeSrcBufH, 0, NULL, NULL);
        checkErr(status, "clWriteBuffer");
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
        size_t dstDstWidth = 1024;
        size_t dstDstHeight = 1024;
        size_t dst_dstsz = sizeof(unsigned char);
        size_t Readsize = dstDstWidth * dstDstHeight * dst_dstsz;
        size_t dstDstStep = dstDstWidth * dst_dstsz;
        dstDstStep = (dstDstStep % PADDING < 16) ? ((dstDstStep / PADDING+1) * PADDING) : ((dstDstStep + PADDING) / PADDING+1) * PADDING;
        size_t dstDstShift = dstDstStep * PADDING_LINE;
        size_t dst_dstsz0Pad = dstDstStep * (dstDstHeight + (PADDING_LINE<<1));
        cl_mem dstdstBuf = clCreateBuffer(g_context, CL_MEM_WRITE_ONLY, dst_dstsz0Pad, NULL, &status);
        checkErr(status, "clCreateBuffer");
        region[0] = dstDstWidth;
        region[1] = dstDstHeight;
        buffer_row_pitch = dstDstWidth;
        buffer_slice_pitch = dst_dstsz0Pad;
        host_row_pitch = dstDstWidth;
        host_slice_pitch = dstDstWidth * dstDstHeight;
        unsigned char *dstDstBufH = (unsigned char*)malloc(dst_dstsz0Pad); 
        for(int i = 0; i < dstDstHeight; i++){
            memcpy( (unsigned char*)dstDstBufH+ (i + PADDING_LINE) * dstDstStep,(unsigned char*)dst + i * dstDstWidth,dstDstWidth);
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
        checkErr(status, "clEnqueueNDRangeKernel");
        status = clFinish(g_queue);
        checkErr(status,"clFinish of kernel_7");
        size_t out_buffer_origin[3], out_host_origin[3], out_region[3];
        out_buffer_origin[0] = 0;
        out_buffer_origin[1] = 2;
        out_buffer_origin[2] = 0;
        out_host_origin[0] = 0;
        out_host_origin[1] = 0;
        out_host_origin[2] = 0;
        out_region[0] = dstDstWidth;
        out_region[1] = dstDstHeight;
        out_region[2] = 1;
        size_t out_buffer_row_pitch = dstDstStep;
        size_t out_buffer_slice_pitch = dst_dstsz0Pad;
        size_t out_host_row_pitch = dstDstWidth * dst_dstsz;
        size_t out_host_slice_pitch = Readsize;
        status = clEnqueueReadBuffer(g_queue, dstdstBuf, CL_TRUE, 0,dst_dstsz0Pad,dstDstBufH, 0, NULL, NULL);
        checkErr(status,"clEnqueueReadBuffer");
        for(int i = 0; i < dstDstHeight; i++){
            memcpy( (unsigned char*)dst+ i *dstDstWidth,(unsigned char*) dstDstBufH+ (i + PADDING_LINE)* dstDstStep,dstDstWidth);
        }

    }
}



void sharpness_total(unsigned char (*yPlane)[1024][1024], unsigned char (*dst)[1024][1024]) {
    MMC_CSE_PARAMETER_PUBLIC cseParamPublic;
    cseParamPublic.cutoff2 = 256.F;
    cseParamPublic.cutoff3Coef = 1.F;
    cseParamPublic.cutoffCoef = 1.F;
    cseParamPublic.peak = 2.F;
    unsigned char yPlaneCSER[1024][1024];
    unsigned char yPlaneDown[1024 / 4][1024 / 4];
    DownScaleNewX16(yPlane, &yPlaneDown);
    UpScaleNewX16(&yPlaneDown, &yPlaneCSER);
    Sharpness(yPlane, &yPlaneCSER, dst, cseParamPublic);
}



int main() {
    char *inputfile = "sharpness_high_level.cl";
  char *remain = NULL;
  if (-1 == openCLCreate(&g_context, &g_queue, inputfile, remain)) {
    printf("openCL create fail !!!!!!");
    return 0;
  }
  unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * 1024 * 1024);
  unsigned char *dst_data = (unsigned char *)malloc(sizeof(unsigned char) * 1024 * 1024);
  for (int i = 0; i < 1024 * 1024; i++) {
    src_data[i] = rand() % 100 + 1;
  }
  unsigned char (*yPlane)[1024][1024] = (unsigned char (*)[1024][1024])src_data;
  unsigned char (*dst)[1024][1024] = (unsigned char (*)[1024][1024])dst_data;
  sharpness_total(yPlane, dst);
  dst_data = (unsigned char *)dst;
  return 0;
}


