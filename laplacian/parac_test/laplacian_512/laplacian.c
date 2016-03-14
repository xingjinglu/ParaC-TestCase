/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

#include"CL/cl.h"
#include"ClHost.h"
#include <stdlib.h>

#define ROWS 512
#define COLS 512
#define M 512
#define N 512

 struct timeval t11,t12;
 double tem;

static int PyramidFilterh(unsigned char *pSrc,unsigned char *pDst,int width ,int height)
{
    int h,w;

    for(h=0;h<height;h++)
    {
        *(pDst+h*width)=((short)pSrc[h*width]*2-pSrc[h*width+1]*4-pSrc[h*width+2]+pSrc[h*width+3]*4 
                + (pSrc[h*width+1]*2-pSrc[h*width+3])*4 
                + pSrc[h*width]*6 
                + pSrc[h*width+1]*4
                + pSrc[h*width+2] + 8)>>4;
        *(pDst+h*width+1)=((short)pSrc[h*width+1]*2-pSrc[h*width+3] 
                + pSrc[h*width]*4
                + pSrc[h*width+1]*6
                + pSrc[h*width+2]*4
                + pSrc[h*width+3] + 8)>>4;
        *(pDst+(h+1)*width-2)=((short)pSrc[(h+1)*width-4]
                + pSrc[(h+1)*width-3]*4
                + pSrc[(h+1)*width-2]*6
                + pSrc[(h+1)*width-1]*4
                + pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4] + 8)>>4;
        *(pDst+(h+1)*width-1)=((short)pSrc[(h+1)*width-3]
                + pSrc[(h+1)*width-2]*4
                + pSrc[(h+1)*width-1]*6
                + (pSrc[(h+1)*width-2]*2-pSrc[(h+1)*width-4])*4
                + pSrc[(h+1)*width-1]*2-pSrc[(h+1)*width-2]*4-pSrc[(h+1)*width-3]+pSrc[(h+1)*width-4]*4 + 8)>>4;
        for(w=2;w<width-2;w++)
        {
            *(pDst+h*width+w) = ((short)pSrc[h*width+w-2] + pSrc[h*width+w-1]*4 + pSrc[h*width+w]*6 + pSrc[h*width+w+1]*4 + pSrc[h*width+w+2] + 8)>>4;
        }
    }

}

static void Downsample(unsigned char *pSrc ,unsigned  char *pDst ,int width ,int height)
{
    int h,w;
    int halfWidth = (width +1)>>1;
    int halfHeight = (height +1)>>1;
    h=height;
    for(w=0;w<halfWidth;w++)
    {
        pDst[w]=(pSrc[w*2]*2-pSrc[width+w*2]*4-pSrc[2*width+w*2]+pSrc[3*width+w*2]*4
                + (pSrc[width+w*2]*2-pSrc[3*width+w*2])*4
                + pSrc[w*2]*6
                + pSrc[width+w*2]*4
                + pSrc[2*width+w*2] + 8)>>4;

        if(height%2==0)
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2]
                    + pSrc[(h-1)*width+w*2]*4
                    + pSrc[(h-2)*width+w*2]*6
                    + pSrc[(h-3)*width+w*2]*4
                    + pSrc[(h-4)*width+w*2] + 8)>>4;
        }
        else
        {
            pDst[(halfHeight-1)*halfWidth+w]=(pSrc[(h-1)*width+w*2]*2-pSrc[(h-2)*width+w*2]*4-pSrc[(h-3)*width+w*2]+pSrc[(h-4)*width+w*2]*4
                    + (pSrc[(h-2)*width+w*2]*2-pSrc[(h-4)*width+w*2])*4
                    + pSrc[(h-1)*width+w*2]*6
                    + pSrc[(h-2)*width+w*2]*4
                    + pSrc[(h-3)*width+w*2] + 8)>>4;
        }
    }

    for(w=0;w<halfWidth;w++)
        for(h=1;h<halfHeight-1;h++)
        {
            pDst[h*halfWidth+w]=((short)pSrc[(h*2-2)*width+w*2] + pSrc[(h*2-1)*width+w*2]*4 + pSrc[h*2*width+w*2]*6 + pSrc[(h*2+1)*width+w*2]*4 + pSrc[(h*2+2)*width+w*2] + 8)>>4;

        }

}

static void UpsampleX4_reverse(unsigned char *pSrc ,signed short*pDst,unsigned char *Source,int width ,int height)
{
    int h,w;
    int halfWidth=(width+1)>>1;
    int halfHeight=(height+1)>>1;
    int wodd=width%2;
    int hodd=height%2;

    //first row
    for(w=0;w<halfWidth-1;w++)
    {
        pDst[w*2]=(signed short)(Source[w*2]-pSrc[w]);
        pDst[w*2+1]=(signed short)(Source[w*2+1]-((pSrc[w]+pSrc[w+1]+1)>>1));
    }
    if(wodd==0)
    {
        pDst[width-2]=(signed short)(Source[width-2]-pSrc[halfWidth-1]);
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);
    }else
        pDst[width-1]=(signed short)(Source[width-1]-pSrc[halfWidth-1]);

    //last row
    h=halfHeight;
    if(hodd==0)
    {
        for(w=0;w<halfWidth-1;w++)
        {
            pDst[(h*2-1)*width+w*2]=(signed short)(Source[(h*2-1)*width+w*2]-pSrc[(h-1)*halfWidth+w]);
            pDst[(h*2-1)*width+w*2+1]=(signed short)(Source[(h*2-1)*width+w*2+1]-((pSrc[(h-1)*halfWidth+w]+pSrc[(h-1)*halfWidth+w+1]+1)>>1));
        }
        if(wodd==0)
        {
            pDst[h*2*width-2]=(signed short)(Source[h*2*width-2]-pSrc[h*halfWidth-1]);
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
        }else
            pDst[h*2*width-1]=(signed short)(Source[h*2*width-1]-pSrc[h*halfWidth-1]);
    }

    //body
    for(h=0;h<halfHeight-1;h++)
    {
        for(w=0;w<halfWidth-1;w++)
        {
            pDst[(h*2+1)*width+w*2]=(signed short)(Source[(h*2+1)*width+w*2]-((pSrc[h*halfWidth+w]+pSrc[(h+1)*halfWidth+w]+1)>>1));
            pDst[(h*2+1)*width+w*2+1]=(signed short)(Source[(h*2+1)*width+w*2+1]-((pSrc[h*halfWidth+w]+pSrc[h*halfWidth+w+1]+pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+2)>>2));

            pDst[(h*2+2)*width+w*2]=(signed short)(Source[(h*2+2)*width+w*2]-pSrc[(h+1)*halfWidth+w]);
            pDst[(h*2+2)*width+w*2+1]=(signed short)(Source[(h*2+2)*width+w*2+1]-((pSrc[(h+1)*halfWidth+w]+pSrc[(h+1)*halfWidth+w+1]+1)>>1));
        }

        if(wodd==0)
        {
            pDst[(h*2+2)*width-2]=(signed short)(Source[(h*2+2)*width-2]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+3)*width-2]=(signed short)(Source[(h*2+3)*width-2]-pSrc[(h+2)*halfWidth-1]);
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }else
        {
            pDst[(h*2+2)*width-1]=(signed short)(Source[(h*2+2)*width-1]-((pSrc[(h+1)*halfWidth-1]+pSrc[(h+2)*halfWidth-1]+1)>>1));
            pDst[(h*2+3)*width-1]=(signed short)(Source[(h*2+3)*width-1]-pSrc[(h+2)*halfWidth-1]);
        }
    }
}


int Laplacian(unsigned char (*Src)[512][512], short (*layer)[512][512]) {
  unsigned char filter_horizon[1][5] = { 1, 4, 6, 4, 1 };
  unsigned char filter_vertical[5][1] = { 1, 4, 6, 4, 1 };
  unsigned char dst_horizon[512][512];
  unsigned char dst_vertical[512][512];
  unsigned char dst_ds[(512 + 1) / 2][(512 + 1) / 2];

  unsigned char *src_cpu= (unsigned char *)malloc(512 * 512*sizeof(unsigned char*));
  unsigned char *filter_cpu= (unsigned char *)malloc(512 * 512*sizeof(unsigned char*));
  unsigned char *down_cpu= (unsigned char *)malloc(256 * 256*sizeof(unsigned char*));
  short *laplacian_cpu= (short *)malloc(512 * 512*sizeof(short*));

  {
      for(int i=0;i<512;i++)
          for(int j=0;j<512;j++)
              *(src_cpu+i*512+j)= ((unsigned char*)Src)[i*512+j];

      printf("ss\n");
      PyramidFilterh(src_cpu,filter_cpu, 512, 512);

      tem = 0;
      for(int i = 0; i< 20; i++)
      {

          size_t SrcSrcWidth = 512;
          size_t SrcSrcHeight = 512;
          size_t Src_srcsz = sizeof(unsigned char);
          size_t SrcSrcStep = SrcSrcWidth * Src_srcsz;
          SrcSrcStep = (SrcSrcStep % PADDING < 16) ? ((SrcSrcStep / PADDING+1) * PADDING) : ((SrcSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t SrcSrcShift = SrcSrcStep * PADDING_LINE;
          size_t Src_srcsz0Pad = SrcSrcStep * (SrcSrcHeight + (PADDING_LINE<<1));
          cl_mem SrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, Src_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *SrcSrcBufH = (unsigned char*)malloc(Src_srcsz0Pad); 
          for(int i = 0; i < SrcSrcHeight; i++){
              memcpy( (char*)SrcSrcBufH+ (i + PADDING_LINE) * SrcSrcStep, (char*)Src+ i * SrcSrcWidth* sizeof(unsigned char), SrcSrcWidth * sizeof(unsigned char) );
          }
          status = clEnqueueWriteBuffer(g_queue, SrcsrcBuf, CL_TRUE, 0,Src_srcsz0Pad,SrcSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          size_t dst_horizonDstWidth = 512;
          size_t dst_horizonDstHeight = 512;
          size_t dst_horizon_dstsz = sizeof(unsigned char);
          size_t Readsize = dst_horizonDstWidth * dst_horizonDstHeight * dst_horizon_dstsz;
          size_t dst_horizonDstStep = dst_horizonDstWidth * dst_horizon_dstsz;
          dst_horizonDstStep = (dst_horizonDstStep % PADDING < 16) ? ((dst_horizonDstStep / PADDING+1) * PADDING) : ((dst_horizonDstStep + PADDING) / PADDING+1) * PADDING;
          size_t dst_horizonDstShift = dst_horizonDstStep * PADDING_LINE;
          size_t dst_horizon_dstsz0Pad = dst_horizonDstStep * (dst_horizonDstHeight + (PADDING_LINE<<1));
          cl_mem dst_horizondstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_horizon_dstsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *dst_horizonDstBufH = (unsigned char*)malloc(dst_horizon_dstsz0Pad); 
          for(int i = 0; i < dst_horizonDstHeight; i++){
              memcpy( (char*)dst_horizonDstBufH+ (i + PADDING_LINE) * dst_horizonDstStep,(char*)dst_horizon + i * dst_horizonDstWidth* sizeof(unsigned char),dst_horizonDstWidth* sizeof(unsigned char) );
          }

          gettimeofday(&t11,NULL);

          size_t filter_horizonSrcWidth = 5;
          size_t filter_horizonSrcHeight = 1;
          size_t filter_horizon_srcsz = sizeof(unsigned char);
          size_t filter_horizonSrcStep = filter_horizonSrcWidth * filter_horizon_srcsz;
          filter_horizonSrcStep = (filter_horizonSrcStep % PADDING < 16) ? ((filter_horizonSrcStep / PADDING+1) * PADDING) : ((filter_horizonSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t filter_horizonSrcShift = filter_horizonSrcStep * PADDING_LINE;
          size_t filter_horizon_srcsz0Pad = filter_horizonSrcStep * (filter_horizonSrcHeight + (PADDING_LINE<<1));
          cl_mem filter_horizonsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_horizon_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *filter_horizonSrcBufH = (unsigned char*)malloc(filter_horizon_srcsz0Pad); 
          for(int i = 0; i < filter_horizonSrcHeight; i++){
              memcpy( (char*)filter_horizonSrcBufH+ (i + PADDING_LINE) * filter_horizonSrcStep, (char*)filter_horizon+ i * filter_horizonSrcWidth* sizeof(unsigned char), filter_horizonSrcWidth * sizeof(unsigned char) );
          }
          status = clEnqueueWriteBuffer(g_queue, filter_horizonsrcBuf, CL_TRUE, 0,filter_horizon_srcsz0Pad,filter_horizonSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          size_t global_work_size[2];
          size_t transe;
          cl_event event_kernel;
          cl_kernel kernel_1 = clCreateKernel(g_program, "kernel_1", &status);
          checkErr(status, "clCreateKernel for kernel_1");
          global_work_size[0] = 256;
          global_work_size[1] = 512;
          status = clSetKernelArg(kernel_1, 0, sizeof(cl_mem), (void *)&SrcsrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 1, sizeof(int), (void *)&SrcSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 2, sizeof(int), (void *)&SrcSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 3, sizeof(int), (void *)&SrcSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 4, sizeof(int), (void *)&SrcSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 5, sizeof(cl_mem), (void *)&filter_horizonsrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 6, sizeof(int), (void *)&filter_horizonSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 7, sizeof(int), (void *)&filter_horizonSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 8, sizeof(int), (void *)&filter_horizonSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 9, sizeof(int), (void *)&filter_horizonSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 10, sizeof(cl_mem), (void *)&dst_horizondstBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 11, sizeof(int), (void *)&dst_horizonDstWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 12, sizeof(int), (void *)&dst_horizonDstHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 13, sizeof(int), (void *)&dst_horizonDstStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_1, 14, sizeof(int), (void *)&dst_horizonDstShift);
          checkErr(status, "clSetKernelArg");
          status = clEnqueueNDRangeKernel(g_queue, kernel_1, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
          checkErr(status, "clEnqueueNDRangeKernel");
          status = clFinish(g_queue);
          checkErr(status,"clFinish of kernel_1");

          gettimeofday(&t12,NULL);
          tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

          status = clEnqueueReadBuffer(g_queue, dst_horizondstBuf, CL_TRUE, 0,dst_horizon_dstsz0Pad,dst_horizonDstBufH, 0, NULL, NULL);
          checkErr(status,"clEnqueueReadBuffer");
          for(int i = 0; i < dst_horizonDstHeight; i++){
              memcpy( (char*)dst_horizon+ i *dst_horizonDstWidth* sizeof(unsigned char),(char*) dst_horizonDstBufH+ (i + PADDING_LINE)* dst_horizonDstStep,dst_horizonDstWidth* sizeof(unsigned char) );
          }

      }
  }

  printf("filter : %f ms\n",tem/20);

  for(int i = 0; i < 512; i++)
  {
      for(int j = 0; j < 512; j++)
      {
          if(filter_cpu[i*512+j] !=((unsigned char*) dst_horizon)[i* 512 +j])
          {
              printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)filter_cpu[i*512+j], (int)((unsigned char*) dst_horizon)[i* 512 +j]);
              //printf("%u ",yPlaneDown[i][j]);


              abort();

          }
      }
      //printf("\n");

  }
  printf("filter success\n");

  Downsample(filter_cpu, down_cpu, 512,512); 

  {


      tem = 0;
      for(int i = 0; i< 20; i++)
      {

          size_t dst_horizonSrcWidth = 512;
          size_t dst_horizonSrcHeight = 512;
          size_t dst_horizon_srcsz = sizeof(unsigned char);
          size_t dst_horizonSrcStep = dst_horizonSrcWidth * dst_horizon_srcsz;
          dst_horizonSrcStep = (dst_horizonSrcStep % PADDING < 16) ? ((dst_horizonSrcStep / PADDING+1) * PADDING) : ((dst_horizonSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t dst_horizonSrcShift = dst_horizonSrcStep * PADDING_LINE;
          size_t dst_horizon_srcsz0Pad = dst_horizonSrcStep * (dst_horizonSrcHeight + (PADDING_LINE<<1));
          cl_mem dst_horizonsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, dst_horizon_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *dst_horizonSrcBufH = (unsigned char*)malloc(dst_horizon_srcsz0Pad); 
          for(int i = 0; i < dst_horizonSrcHeight; i++){
              memcpy( (char*)dst_horizonSrcBufH+ (i + PADDING_LINE) * dst_horizonSrcStep, (char*)dst_horizon+ i * dst_horizonSrcWidth* sizeof(unsigned char), dst_horizonSrcWidth * sizeof(unsigned char) );
          }
          status = clEnqueueWriteBuffer(g_queue, dst_horizonsrcBuf, CL_TRUE, 0,dst_horizon_srcsz0Pad,dst_horizonSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          size_t dst_dsDstWidth = 256;
          size_t dst_dsDstHeight = 256;
          size_t dst_ds_dstsz = sizeof(unsigned char);
          size_t Readsize = dst_dsDstWidth * dst_dsDstHeight * dst_ds_dstsz;
          size_t dst_dsDstStep = dst_dsDstWidth * dst_ds_dstsz;
          dst_dsDstStep = (dst_dsDstStep % PADDING < 16) ? ((dst_dsDstStep / PADDING+1) * PADDING) : ((dst_dsDstStep + PADDING) / PADDING+1) * PADDING;
          size_t dst_dsDstShift = dst_dsDstStep * PADDING_LINE;
          size_t dst_ds_dstsz0Pad = dst_dsDstStep * (dst_dsDstHeight + (PADDING_LINE<<1));
          cl_mem dst_dsdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, dst_ds_dstsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *dst_dsDstBufH = (unsigned char*)malloc(dst_ds_dstsz0Pad); 
          for(int i = 0; i < dst_dsDstHeight; i++){
              memcpy( (char*)dst_dsDstBufH+ (i + PADDING_LINE) * dst_dsDstStep,(char*)dst_ds + i * dst_dsDstWidth* sizeof(unsigned char),dst_dsDstWidth* sizeof(unsigned char) );
          }



          gettimeofday(&t11,NULL);

          size_t filter_verticalSrcWidth = 1;
          size_t filter_verticalSrcHeight = 5;
          size_t filter_vertical_srcsz = sizeof(unsigned char);
          size_t filter_verticalSrcStep = filter_verticalSrcWidth * filter_vertical_srcsz;
          filter_verticalSrcStep = (filter_verticalSrcStep % PADDING < 16) ? ((filter_verticalSrcStep / PADDING+1) * PADDING) : ((filter_verticalSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t filter_verticalSrcShift = filter_verticalSrcStep * PADDING_LINE;
          size_t filter_vertical_srcsz0Pad = filter_verticalSrcStep * (filter_verticalSrcHeight + (PADDING_LINE<<1));
          cl_mem filter_verticalsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, filter_vertical_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *filter_verticalSrcBufH = (unsigned char*)malloc(filter_vertical_srcsz0Pad); 
          for(int i = 0; i < filter_verticalSrcHeight; i++){
              memcpy( (char*)filter_verticalSrcBufH+ (i + PADDING_LINE) * filter_verticalSrcStep, (char*)filter_vertical+ i * filter_verticalSrcWidth* sizeof(unsigned char), filter_verticalSrcWidth * sizeof(unsigned char) );
          }

          status = clEnqueueWriteBuffer(g_queue, filter_verticalsrcBuf, CL_TRUE, 0,filter_vertical_srcsz0Pad,filter_verticalSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");



          size_t global_work_size[2];
          size_t transe;
          cl_event event_kernel;
          cl_kernel kernel_2 = clCreateKernel(g_program, "kernel_2", &status);
          checkErr(status, "clCreateKernel for kernel_2");
          global_work_size[0] = 256;
          global_work_size[1] = 256;
          status = clSetKernelArg(kernel_2, 0, sizeof(cl_mem), (void *)&filter_verticalsrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 1, sizeof(int), (void *)&filter_verticalSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 2, sizeof(int), (void *)&filter_verticalSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 3, sizeof(int), (void *)&filter_verticalSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 4, sizeof(int), (void *)&filter_verticalSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 5, sizeof(cl_mem), (void *)&dst_horizonsrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 6, sizeof(int), (void *)&dst_horizonSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 7, sizeof(int), (void *)&dst_horizonSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 8, sizeof(int), (void *)&dst_horizonSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 9, sizeof(int), (void *)&dst_horizonSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 10, sizeof(cl_mem), (void *)&dst_dsdstBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 11, sizeof(int), (void *)&dst_dsDstWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 12, sizeof(int), (void *)&dst_dsDstHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 13, sizeof(int), (void *)&dst_dsDstStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_2, 14, sizeof(int), (void *)&dst_dsDstShift);
          checkErr(status, "clSetKernelArg");
          status = clEnqueueNDRangeKernel(g_queue, kernel_2, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
          checkErr(status, "clEnqueueNDRangeKernel");
          status = clFinish(g_queue);
          checkErr(status,"clFinish of kernel_2");

          gettimeofday(&t12,NULL);
          tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

          status = clEnqueueReadBuffer(g_queue, dst_dsdstBuf, CL_TRUE, 0,dst_ds_dstsz0Pad,dst_dsDstBufH, 0, NULL, NULL);
          checkErr(status,"clEnqueueReadBuffer");
          for(int i = 0; i < dst_dsDstHeight; i++){
              memcpy( (char*)dst_ds+ i *dst_dsDstWidth* sizeof(unsigned char),(char*) dst_dsDstBufH+ (i + PADDING_LINE)* dst_dsDstStep,dst_dsDstWidth* sizeof(unsigned char) );
          }

      }
  }

  printf("down : %f ms\n",tem/20);

  for(int i = 0; i < 256; i++)
  {
      for(int j = 0; j < 256; j++)
      {
          if(down_cpu[i*256+j] !=((unsigned char*) dst_ds)[i* 256 +j])
          {
              printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)down_cpu[i*256+j], (int)((unsigned char*) dst_ds)[i* 256 +j]);
              //printf("%u ",yPlaneDown[i][j]);


              abort();

          }
      }
      //printf("\n");

  }
  printf("down success\n");


  UpsampleX4_reverse(down_cpu, laplacian_cpu, src_cpu, 512,512);


  int halfWidth = 512 / 2;
  int halfHeight = 512 / 2;
  int widthOdd = 512 - (halfWidth * 2);
  int heightOdd = 512 - (halfHeight * 2);

  {
      tem = 0;
      for(int i = 0; i< 20; i++)
      {

          size_t SrcSrcWidth = 512;
          size_t SrcSrcHeight = 512;
          size_t Src_srcsz = sizeof(unsigned char);
          size_t SrcSrcStep = SrcSrcWidth * Src_srcsz;
          SrcSrcStep = (SrcSrcStep % PADDING < 16) ? ((SrcSrcStep / PADDING+1) * PADDING) : ((SrcSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t SrcSrcShift = SrcSrcStep * PADDING_LINE;
          size_t Src_srcsz0Pad = SrcSrcStep * (SrcSrcHeight + (PADDING_LINE<<1));
          cl_mem SrcsrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, Src_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *SrcSrcBufH = (unsigned char*)malloc(Src_srcsz0Pad); 
          for(int i = 0; i < SrcSrcHeight; i++){
              memcpy( (char*)SrcSrcBufH+ (i + PADDING_LINE) * SrcSrcStep, (char*)Src+ i * SrcSrcWidth* sizeof(unsigned char), SrcSrcWidth * sizeof(unsigned char) );
          }
          status = clEnqueueWriteBuffer(g_queue, SrcsrcBuf, CL_TRUE, 0,Src_srcsz0Pad,SrcSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          size_t dst_dsSrcWidth = 256;
          size_t dst_dsSrcHeight = 256;
          size_t dst_ds_srcsz = sizeof(unsigned char);
          size_t dst_dsSrcStep = dst_dsSrcWidth * dst_ds_srcsz;
          dst_dsSrcStep = (dst_dsSrcStep % PADDING < 16) ? ((dst_dsSrcStep / PADDING+1) * PADDING) : ((dst_dsSrcStep + PADDING) / PADDING+1) * PADDING;
          size_t dst_dsSrcShift = dst_dsSrcStep * PADDING_LINE;
          size_t dst_ds_srcsz0Pad = dst_dsSrcStep * (dst_dsSrcHeight + (PADDING_LINE<<1));
          cl_mem dst_dssrcBuf = clCreateBuffer(g_context, CL_MEM_READ_ONLY, dst_ds_srcsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *dst_dsSrcBufH = (unsigned char*)malloc(dst_ds_srcsz0Pad); 
          for(int i = 0; i < dst_dsSrcHeight; i++){
              memcpy( (char*)dst_dsSrcBufH+ (i + PADDING_LINE) * dst_dsSrcStep, (char*)dst_ds+ i * dst_dsSrcWidth* sizeof(unsigned char), dst_dsSrcWidth * sizeof(unsigned char) );
          }
          status = clEnqueueWriteBuffer(g_queue, dst_dssrcBuf, CL_TRUE, 0,dst_ds_srcsz0Pad,dst_dsSrcBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          size_t layerDstWidth = 512;
          size_t layerDstHeight = 512;
          size_t layer_dstsz = sizeof(short);
          size_t Readsize = layerDstWidth * layerDstHeight * layer_dstsz;
          size_t layerDstStep = layerDstWidth * layer_dstsz;
          layerDstStep = (layerDstStep % PADDING < 16) ? ((layerDstStep / PADDING+1) * PADDING) : ((layerDstStep + PADDING) / PADDING+1) * PADDING;
          size_t layerDstShift = layerDstStep * PADDING_LINE;
          size_t layer_dstsz0Pad = layerDstStep * (layerDstHeight + (PADDING_LINE<<1));
          cl_mem layerdstBuf = clCreateBuffer(g_context, CL_MEM_READ_WRITE, layer_dstsz0Pad, NULL, &status);
          checkErr(status, "clCreateBuffer");
          unsigned char *layerDstBufH = (unsigned char*)malloc(layer_dstsz0Pad); 
          for(int i = 0; i < layerDstHeight; i++){
              memcpy( (char*)layerDstBufH+ (i + PADDING_LINE) * layerDstStep,(char*)layer + i * layerDstWidth* sizeof(short),layerDstWidth* sizeof(short) );
          }
          status = clEnqueueWriteBuffer(g_queue, layerdstBuf, CL_TRUE, 0,layer_dstsz0Pad,layerDstBufH, 0, NULL, NULL);
          checkErr(status, "clWriteBuffer");

          gettimeofday(&t11,NULL);

          size_t global_work_size[2];
          global_work_size[0] = 256;
          global_work_size[1] = 256;
          size_t transe;
          cl_event event_kernel;
          cl_kernel kernel_3 = clCreateKernel(g_program, "kernel_3", &status);
          checkErr(status, "clCreateKernel for kernel_3");
          status = clSetKernelArg(kernel_3, 0, sizeof(cl_mem), (void *)&SrcsrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 1, sizeof(int), (void *)&SrcSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 2, sizeof(int), (void *)&SrcSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 3, sizeof(int), (void *)&SrcSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 4, sizeof(int), (void *)&SrcSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 5, sizeof(cl_mem), (void *)&dst_dssrcBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 6, sizeof(int), (void *)&dst_dsSrcWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 7, sizeof(int), (void *)&dst_dsSrcHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 8, sizeof(int), (void *)&dst_dsSrcStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 9, sizeof(int), (void *)&dst_dsSrcShift);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 10, sizeof(int), (void *)&widthOdd);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 11, sizeof(int), (void *)&heightOdd);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 12, sizeof(cl_mem), (void *)&layerdstBuf);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 13, sizeof(int), (void *)&layerDstWidth);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 14, sizeof(int), (void *)&layerDstHeight);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 15, sizeof(int), (void *)&layerDstStep);
          checkErr(status, "clSetKernelArg");
          status = clSetKernelArg(kernel_3, 16, sizeof(int), (void *)&layerDstShift);
          checkErr(status, "clSetKernelArg");
          status = clEnqueueNDRangeKernel(g_queue, kernel_3, 2, NULL, global_work_size, NULL, 0, NULL, &event_kernel);
          checkErr(status, "clEnqueueNDRangeKernel");
          status = clFinish(g_queue);
          checkErr(status,"clFinish of kernel_3");

          gettimeofday(&t12,NULL);
          tem+=(double)(t12.tv_usec-t11.tv_usec)*0.001+(t12.tv_sec-t11.tv_sec)*1000;

          status = clEnqueueReadBuffer(g_queue, layerdstBuf, CL_TRUE, 0,layer_dstsz0Pad,layerDstBufH, 0, NULL, NULL);
          checkErr(status,"clEnqueueReadBuffer");


          for(int i = 0; i < layerDstHeight; i++){
              memcpy( (char*)layer+ i *layerDstWidth* sizeof(short),(char*) layerDstBufH+ (i + PADDING_LINE)* layerDstStep,layerDstWidth* sizeof(short) );
          }

      }
  }

  printf("up : %f ms\n",tem/20);

  for(int i = 0; i < 512; i++)
  {
      for(int j = 0; j < 512; j++)
      {
          if(laplacian_cpu[i*512+j] !=((short*) layer)[i* 512 +j])
          {
              printf("i= %d, j = %d, a = %d, b=%d\n",i, j,(int)laplacian_cpu[i*512+j], (int)((short*) layer)[i* 512 +j]);
              //printf("%u ",yPlaneDown[i][j]);


              abort();

          }
      }
      //printf("\n");

  }
  printf("all success\n");
  return 0;
}



int main() {
    char inputfile[] = "laplacian.cl";
    char *remain = NULL;
    if (-1 == openCLCreate(inputfile, remain)) {
        printf("openCL create fail !!!!!!");
        return 0;
    }

    unsigned char *src_data = (unsigned char *)malloc(sizeof(unsigned char) * 512 * 512);
    short *dst_data = (short *)malloc(sizeof(short) * 512 * 512);

    unsigned char (*src)[512][512] = (unsigned char (*)[512][512])src_data;
    short (*Layer)[512][512] = (short (*)[512][512])dst_data;
    for (int i = 0; i < 512 * 512; i++) {
        src_data[i] = rand() % 100 + 1;
    }
    Laplacian(src, Layer);
    return 0;
}


