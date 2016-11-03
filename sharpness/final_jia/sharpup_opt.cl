#pragma OPENCL EXTENSION cl_amd_printf : enable
#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable

__kernel void Sharpness(
__global unsigned char* const yPlaneCSER,
__global unsigned char* const padSrc,
__global unsigned char* cache,
__global short*         const pEdge,
float mean_p4,
float Power4InvMean,
float Power4Rec256,
int   width,
int   height,
int   pSrcStepwide,
int   pSrcShift,
int   pEdgeStepwide,
int   pEdgeShift)
{
  int gidx = get_global_id(0);
  int gidy = get_global_id(1);
  
  if(gidx >= (width>>2)|| gidy >= height)
      return ;

  int    outputIndex,inputIndex,pEdgeIndex;
  uchar4 pSrc,pSrctemp,tmax,tmin,tu4;
  uchar  pSrcPre,pSrcNext;
  float4 src_float4,yPlaneCSER4,pEdgeF4,maxValueF,minValueF,pError_float4,edge2Order,strength,enhancedF;

  outputIndex = mad24(gidy,pSrcStepwide,(gidx<<2)) + pSrcShift;  // gidx*4+gidy*pSrcStepwide+pSrcShift
  inputIndex  = (gidx<<2) + mad24(gidy,pSrcStepwide,pSrcStepwide);
  pEdgeIndex  = mad24(gidy,pEdgeStepwide,(gidx<<2)*sizeof(short)) + pEdgeShift;

  pSrcPre  = *(padSrc + inputIndex - 1);
  pSrc     = *((__global uchar4*) (padSrc + inputIndex));
  pSrcNext = *(padSrc + inputIndex + 4);

  tmax = pSrc;
  tmin = pSrc;

  pSrctemp    = pSrc;
  pSrctemp.s3 = pSrcPre;
  tu4         = pSrctemp.s3012;
  tmax        = max(tmax,tu4);
  tmin        = min(tmin,tu4);

  pSrc.s0 = pSrcNext;
  tu4     = pSrc.s1230;
  tmax    = max(tmax,tu4);
  tmin    = min(tmin,tu4);

  inputIndex += pSrcStepwide; 
  pSrcPre     = *(padSrc + inputIndex - 1);
  pSrc        = *((__global uchar4*) (padSrc + inputIndex));
  pSrcNext    = *(padSrc + inputIndex + 4);

  tmax = max(tmax,pSrc);
  tmin = min(tmin,pSrc);

  src_float4  = convert_float4(pSrc);
  pSrctemp    = pSrc;
  pSrctemp.s3 = pSrcPre;
  tu4         = pSrctemp.s3012;
  tmax        = max(tmax,tu4);
  tmin        = min(tmin,tu4);

  pSrc.s0 = pSrcNext;
  tu4     = pSrc.s1230;
  tmax    = max(tmax,tu4);
  tmin    = min(tmin,tu4);

  inputIndex += pSrcStepwide;
  pSrcPre     = *(padSrc + inputIndex - 1);
  pSrc        = *((__global uchar4*) (padSrc + inputIndex));
  pSrcNext    = *(padSrc + inputIndex + 4);

  tmax = max(tmax,pSrc);
  tmin = min(tmin,pSrc);

  pSrctemp    = pSrc;
  pSrctemp.s3 = pSrcPre;
  tu4         = pSrctemp.s3012;
  tmax        = max(tmax,tu4);
  tmin        = min(tmin,tu4);

  pSrc.s0 = pSrcNext;
  tu4     = pSrc.s1230;
  tmax    = max(tmax,tu4);
  tmin    = min(tmin,tu4);

  yPlaneCSER4 = convert_float4(*((__global uchar4*)(yPlaneCSER + outputIndex)));
  pEdgeF4     = convert_float4(*((__global short4*)((__global uchar*)pEdge + pEdgeIndex)));
 
  maxValueF     = convert_float4(tmax);
  minValueF     = convert_float4(tmin);
  pError_float4 = src_float4 - yPlaneCSER4;

  edge2Order = pEdgeF4*pEdgeF4*pEdgeF4*pEdgeF4;
  enhancedF  = mad(edge2Order,Power4InvMean,1);
  strength   = mad(edge2Order,Power4Rec256,1);
  strength   = (enhancedF - 1)/(enhancedF * strength) + 1;

  enhancedF = convert_float4(convert_int4(mad(pError_float4,strength,yPlaneCSER4)));
  strength  = mad(0.05f,edge2Order,mean_p4) / (mean_p4 + edge2Order);    //strength=oscStrength

  pError_float4 = clamp(enhancedF,(convert_float4)0,(convert_float4)255);  //pError_float4=tt_enhanced 
  edge2Order    = mad(-strength,minValueF-enhancedF,minValueF);   //strength=oscStrength
  strength      = min(mad(strength,enhancedF - maxValueF,maxValueF),255);  //strength=oscStrength
  edge2Order    = select(pError_float4,max(0,edge2Order),enhancedF < minValueF);//pError_float4=tt_enhanced
  
  *((__global uchar4*)(cache + outputIndex)) = convert_uchar4(select(edge2Order,strength,enhancedF > maxValueF));
}


__kernel void Sobel(
__global unsigned char* const pPadSrc,
__global short* pEdge,
int width,
int height,
int pSrcStepwide,
int pSrcShift,
int pEdgeStepwide,
int pEdgeShift)
{
	int gidx = get_global_id(0);
	int gidy = get_global_id(1);
	
  if(gidx >= (width>>2) || gidy >= height )
      return ;

  int inputIndex   = (gidx << 2) + mad24(gidy,pSrcStepwide,pSrcShift - pSrcStepwide);
	int outputIndex  = (gidx << 2)*sizeof(short) + mad24(gidy,pEdgeStepwide,pEdgeShift);

  int4   pSrcL0,res0,res1;
	int    uc1,uc2;
  short4 edgeV; 

  if(gidy==0 || gidy==height-1)
      *((__global short4*)((__global uchar*)pEdge + outputIndex)) = (short4)0;
  else
  {
      uc1     = (int)*(pPadSrc + inputIndex - 1);
	    pSrcL0  = convert_int4(*((__global uchar4*)(pPadSrc + inputIndex)));
      uc2     = (int)*(pPadSrc + inputIndex + 4);

      res0.s0 = uc1 + (pSrcL0.s0<<1) + pSrcL0.s1;
      res0.s1 = pSrcL0.s0 + (pSrcL0.s1<<1) + pSrcL0.s2;
      res0.s2 = pSrcL0.s1 + (pSrcL0.s2<<1) + pSrcL0.s3;
      res0.s3 = pSrcL0.s2 + (pSrcL0.s3<<1) + uc2;

      res1.s0 = pSrcL0.s1 - uc1;
      res1.s1 = pSrcL0.s2 - pSrcL0.s0;
      res1.s2 = pSrcL0.s3 - pSrcL0.s1;
      res1.s3 = uc2 - pSrcL0.s2;
      
	    inputIndex += pSrcStepwide;
      uc1     = (int) *(pPadSrc + inputIndex - 1);
      pSrcL0  = convert_int4(*((__global uchar4*)(pPadSrc + inputIndex)));
      uc2     = (int) *(pPadSrc + inputIndex + 4);

      res1.s0 += (pSrcL0.s1 - uc1)<<1;
      res1.s1 += (pSrcL0.s2 - pSrcL0.s0)<<1;
      res1.s2 += (pSrcL0.s3 - pSrcL0.s1)<<1;
      res1.s3 += (uc2 - pSrcL0.s2)<<1;
	    
	    inputIndex += pSrcStepwide;
      uc1     = (int)*(pPadSrc + inputIndex - 1);
	    pSrcL0  = convert_int4(*((__global uchar4*)(pPadSrc + inputIndex)));
      uc2     = (int)*(pPadSrc + inputIndex + 4);

      res0.s0 -= uc1 + (pSrcL0.s0<<1) + pSrcL0.s1;
      res0.s1 -= pSrcL0.s0 + (pSrcL0.s1<<1) + pSrcL0.s2;
      res0.s2 -= pSrcL0.s1 + (pSrcL0.s2<<1) + pSrcL0.s3;
      res0.s3 -= pSrcL0.s2 + (pSrcL0.s3<<1) + uc2;

      res1.s0 += pSrcL0.s1 - uc1;
      res1.s1 += pSrcL0.s2 - pSrcL0.s0;
      res1.s2 += pSrcL0.s3 - pSrcL0.s1;
      res1.s3 += uc2 - pSrcL0.s2;
 
	    edgeV = convert_short4(abs(res0) + abs(res1));
	    
	    edgeV.s0 = select((int)edgeV.s0,0,gidx == 0);
      edgeV.s3 = select((int)edgeV.s3,0,gidx == (width>>2)-1);
	    
      *((__global short4*)((__global uchar*)pEdge + outputIndex)) = edgeV;
  }
}

__kernel void downKernel(
__global unsigned char* const pPadSrc,
__global unsigned char* pDownTemp,
int width,
int height,
int stepwide,
int shift,
int downStepwide,
int downShift)
{
    size_t gidx=get_global_id(0);
    size_t gidy=get_global_id(1);
    
    if(gidx >= (width>>2) || gidy >= (height>>2))
        return ;

    int inputIndex,outputIndex,temp=8;
    uchar4 src1,src2,src3,src4;


    inputIndex  = (mad24(gidy,stepwide,gidx)<<2) + shift; //gidy*stepwide*4+gidx*4++shift;
    //__global unsigned char*  addr = pPadSrc + inputIndex;
    //inputIndex = gidy*stepwide*4 + gidx*4 + shift;
    outputIndex = mad24(gidy,downStepwide,gidx) + downShift; //gidx+gidy*downStepwide+downShift;
    //outputIndex = gidx + gidy*downStepwide + downShift;

#if 0
    src1  = vload4(0, addr);
    temp += src1.s0+src1.s1+src1.s2+src1.s3;

    src2  = vload4(0, addr + stepwide);
    //temp += src1.s0+src1.s1+src1.s2+src1.s3;
    temp += src2.s0+src2.s1+src2.s2+src2.s3;

    src3  = vload4(0, addr+2*stepwide);
    //temp += src1.s0+src1.s1+src1.s2+src1.s3;
    temp += src3.s0+src3.s1+src3.s2+src3.s3;

    src4  = vload4(0, addr + 3*stepwide);
    //temp += src1.s0+src1.s1+src1.s2+src1.s3;
    temp += src4.s0+src4.s1+src4.s2+src4.s3;
#endif

#if 0
    src1  = *((__global uchar4*)(pPadSrc+inputIndex));
    temp += src1.s0+src1.s1+src1.s2+src1.s3;
    src1  = *((__global uchar4*)(pPadSrc+inputIndex + stepwide));
    temp += src1.s0+src1.s1+src1.s2+src1.s3;
    src1  = *((__global uchar4*)(pPadSrc+inputIndex +2* stepwide));
    temp += src1.s0+src1.s1+src1.s2+src1.s3;
    src1  = *((__global uchar4*)(pPadSrc+inputIndex +3* stepwide));
    temp += src1.s0+src1.s1+src1.s2+src1.s3;
#endif

#if 1
    src1  = *((__global uchar4*)(pPadSrc+inputIndex));
    temp += src1.s0+src1.s1+src1.s2+src1.s3;

    src2  = *((__global uchar4*)(pPadSrc+inputIndex+stepwide));
    temp += src2.s0+src2.s1+src2.s2+src2.s3;

    src3  = *((__global uchar4*)(pPadSrc+mad24(2,stepwide,inputIndex)));
    temp += src3.s0+src3.s1+src3.s2+src3.s3;

    src4  = *((__global uchar4*)(pPadSrc+mad24(3,stepwide,inputIndex)));
    temp += src4.s0+src4.s1+src4.s2+src4.s3;

#endif

    *(pDownTemp +outputIndex) = (uchar)(temp >> 4);
}

__kernel void UpScale(
__global unsigned char* const pDownTemp,
__global unsigned char* pUpTemp,
int width,
int height,
int stepwide,
int shift,
int downStepwide,
int downShift)
{
    int gidx = get_global_id(0);
    int gidy = get_global_id(1);

    if(gidx >= (width>>2) -1 || gidy >= (height>>2) - 1)
        return ;

    int inputIndex = gidx + mad24(gidy,downStepwide,downShift);
    int outputIndex = shift + (stepwide<<1) + 2 + mad24(gidy<<2,stepwide,gidx<<2);

    float a0,a1,b0,b1;
    __global unsigned char *pDst1,*pDst2,*pDst3,*pDst4;

    a0 = (float)(*(pDownTemp+inputIndex));
    a1 = (float)(*(pDownTemp+inputIndex+1));
    b0 = (float)(*(pDownTemp+inputIndex+downStepwide));
    b1 = (float)(*(pDownTemp+inputIndex+downStepwide+1));
  
    pDst1 = pUpTemp + outputIndex; 
    pDst2 = pDst1 + stepwide;
    pDst3 = pDst2 + stepwide;
    pDst4 = pDst3 + stepwide;


#if 1 
    *(pDst1)   = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(7/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(1/8.0));
    *(pDst1+1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(7/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(1/8.0));
    *(pDst1+2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(7/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(1/8.0));
    *(pDst1+3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(7/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(1/8.0));

    *pDst2     = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(5/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(3/8.0));
    *(pDst2+1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(5/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(3/8.0));
    *(pDst2+2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(5/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(3/8.0));
    *(pDst2+3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(5/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(3/8.0));
    
    *pDst3     = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(3/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(5/8.0));
    *(pDst3+1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(3/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(5/8.0));
    *(pDst3+2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(3/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(5/8.0));
    *(pDst3+3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(3/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(5/8.0));

    *pDst4     = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(1/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(7/8.0));
    *(pDst4+1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(1/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(7/8.0));
    *(pDst4+2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(1/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(7/8.0));
    *(pDst4+3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(1/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(7/8.0));
#endif

#ifdef _OPT_LXJ 
    float result0[4][4];
    float *r00;
    float *r01;
    float *r02;
    float *r03;
    r00 = (float*)result0;
    r01 = (float*)r00 + 4;
    r02 = (float*)r01 + 4;
    r03 = (float*)r02 + 4;

    *r00 = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(7/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(1/8.0));
    *(r00 + 1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(7/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(1/8.0));
    *(r00 + 2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(7/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(1/8.0));
    *(r00 + 3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(7/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(1/8.0));

    *(r01)     = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(5/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(3/8.0));
    *(r01 + 1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(5/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(3/8.0));
    *(r01 + 2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(5/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(3/8.0));
    *(r01 + 3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(5/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(3/8.0));

    *(r02) = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(3/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(5/8.0));
    *(r02 + 1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(3/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(5/8.0));
    *(r02 + 2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(3/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(5/8.0));
    *(r02 + 3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(3/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(5/8.0));

    *(r03)     = (unsigned char)(((a0)*(7/8.0)+(a1)*(1/8.0))*(1/8.0)+((b0)*(7/8.0)+(b1)*(1/8.0))*(7/8.0));
    *(r03 + 1) = (unsigned char)(((a0)*(5/8.0)+(a1)*(3/8.0))*(1/8.0)+((b0)*(5/8.0)+(b1)*(3/8.0))*(7/8.0));
    *(r03 + 2) = (unsigned char)(((a0)*(3/8.0)+(a1)*(5/8.0))*(1/8.0)+((b0)*(3/8.0)+(b1)*(5/8.0))*(7/8.0));
    *(r03 + 3) = (unsigned char)(((a0)*(1/8.0)+(a1)*(7/8.0))*(1/8.0)+((b0)*(1/8.0)+(b1)*(7/8.0))*(7/8.0));

   *pDst1 = (uchar) (*r00);
   *(pDst1+1 ) = (uchar) (*(r00+1));
   *(pDst1+2 ) = (uchar) (*(r00+2));
   *(pDst1+3 ) = (uchar) (*(r00+3));
   
   *pDst2 = (uchar) (*r01);
   *(pDst2+1 ) = (uchar) (*(r01+1));
   *(pDst2+2 ) = (uchar) (*(r01+2));
   *(pDst2+3 ) = (uchar) (*(r01+3));

   *pDst3 = (uchar) (*r02);
   *(pDst3+1 ) = (uchar) (*(r02+1));
   *(pDst3+2 ) = (uchar) (*(r02+2));
   *(pDst3+3 ) = (uchar) (*(r02+3));

   *pDst4 = (uchar) (*r03);
   *(pDst4+1 ) = (uchar) (*(r03+1));
   *(pDst4+2 ) = (uchar) (*(r03+2 ));
   *(pDst4+3 ) = (uchar) (*(r03+3));

#endif



}

//this one's input is short type, and have the count can be divided by 16.
//in this function , we define MEAN_THREADS_NUMBER 128 and define MEAN_PROCESS_PER_THREADS 4
__kernel void mean(
__global short const  *pEdge,
__global unsigned int *pMidEdge,
__local  unsigned int *local_sum,
int width,
int height,
int stepwide,
int shift)
{
    int lidx    = get_local_id(0);
    int lidy    = get_local_id(1);
    int gidx    = get_global_id(0);
    int gidy    = get_global_id(1);
    int gridx   = get_group_id(0);
    int gridy   = get_group_id(1);
    int lsizex  = get_local_size(0);
    int grsizex = get_num_groups(0);

    int    lid = mad24(lidy,lsizex,lidx);
    short4 edgeDate = {0,0,0,0};
    
    if(gidx < (width >> 2) && gidy < height )
        edgeDate = *((__global short4*)((__global uchar*)pEdge+mad24(gidy,stepwide,shift)+(gidx<<2)*sizeof(short)));

    *(local_sum + lid) = edgeDate.s0 + edgeDate.s1 + edgeDate.s2 + edgeDate.s3;


    barrier(CLK_LOCAL_MEM_FENCE);
    if(gidx < (width >> 2) && gidy < height )
    {
       if(lid < 128)
          *(local_sum + lid) += *(local_sum + lid + 128);
    }
       barrier(CLK_LOCAL_MEM_FENCE);

    if(gidx < (width >> 2) && gidy < height )
    {

       if(lid < 64)
          *(local_sum + lid) += *(local_sum + lid + 64); 
       if(lid < 32)
          *(local_sum + lid) += *(local_sum + lid + 32); 
       if(lid < 16)
          *(local_sum + lid) += *(local_sum + lid + 16); 
       if(lid < 8)
          *(local_sum + lid) += *(local_sum + lid + 8); 
       if(lid < 4)
          *(local_sum + lid) += *(local_sum + lid + 4); 
       if(lid < 2)
          *(local_sum + lid) += *(local_sum + lid + 2); 
       if(lid < 1)
       {
          *(local_sum + lid) += *(local_sum + lid + 1); 
          atom_add(pMidEdge, local_sum[0]);
       }
    }
}

__kernel void BorderUpRow(
__global unsigned char* const pDownTemp,
__global unsigned char* pUpTemp,
__local  unsigned char* tile,
int width,
int height,
int stepwide,
int shift,
int downStepwide,
int downShift)
{
    int gidx   = get_global_id(0);
    int gidy   = get_global_id(1);
    int lidx   = get_local_id(0);
    int lidy   = get_local_id(1);
    int gsizx  = get_global_size(0);
    int gsizy  = get_global_size(1);
    int lsizex = get_local_size(0);

    uchar4 vpUpt;
    uchar  temp1;
    int outputIndex,inputIndex,lput;

    if(gidx < width>>2 && gidy < 2)
    {
        outputIndex = mad24(gidy*(height-2),stepwide,gidx<<2)+shift;
        inputIndex  = mad24(gidy*((height>>2)-1),downStepwide,gidx)+downShift;
        lput        = mad24(lidy,lsizex,lidx);

        tile[lput] = *(pDownTemp+inputIndex);
        temp1 = tile[lput];
        
        if((lidx == lsizex-1) && (width >>1 )>64)
            tile[lput+1] = *(pDownTemp+inputIndex+1);
    }

    barrier(CLK_LOCAL_MEM_FENCE);
   
    if(gidx < width>>2 && gidy < 2)
    {
        if(gidx == gsizx-1)
        {
            *((__global uchar2*) (pUpTemp+outputIndex         )) = (uchar2)temp1;
            *((__global uchar2*) (pUpTemp+outputIndex+stepwide)) = (uchar2)temp1;
        }
        else
        {
            uchar temp2 = tile[lput+1];
            vpUpt = convert_uchar4((float4)temp1*(float4)(1.0,3/4.0,2/4.0,1/4.0)+(float4)temp2*(float4)(0.0,1/4.0,2/4.0,3/4.0));
            *((__global uchar4*) (pUpTemp+outputIndex         )) = vpUpt;
            *((__global uchar4*) (pUpTemp+outputIndex+stepwide)) = vpUpt; 
        }
    }
}


__kernel void BorderUpColum(
__global unsigned char* const pDownTemp,
__global unsigned char* pUpTemp,
__local  unsigned char* tile,
int width,
int height,
int stepwide,
int shift,
int downStepwide,
int downShift)
{
    int gidx   = get_global_id(0);
    int gidy   = get_global_id(1);
    int gsizx  = get_global_size(0);
    int gsizy  = get_global_size(1);
    int lidx   = get_local_id(0);
    int lidy   = get_local_id(1);
    int lsizey = get_local_size(1);
    int lsizex = get_local_size(0);

    int outputIndex,inputIndex,lput;
    uchar4 vpUpt;
    uchar temp1, temp2;

    if(gidx < 2 && gidy < (height>>2))
    {
        outputIndex = mad24(gidy,stepwide<<2,gidx*(width-2))+shift;
        inputIndex  = mad24(gidy,downStepwide,gidx*((width>>2)-1))+downShift;
        lput = lidy; //mad((float)lidx,(float)lsizey,(float)lidy);

        tile[lput] = *(pDownTemp + inputIndex);
        temp1 = tile[lput]; 

        if((lidy == lsizey-1) && (height >> 1)>64)
            tile[lput+1] = *(pDownTemp+inputIndex+downStepwide);
    }

    barrier(CLK_LOCAL_MEM_FENCE);
    
    if(gidx < 2 && gidy < (height>>2))
    {
        temp2 = tile[lput + 1];
        vpUpt = convert_uchar4((float4)temp1*(float4)(1.0,3/4.0,2/4.0,1/4.0)+(float4)temp2*(float4)(0.0,1/4.0,2/4.0,3/4.0));
        
        *((__global uchar2*) (pUpTemp + outputIndex               ))  = (gidy == gsizy-1)? (uchar2)temp1 : (uchar2)(vpUpt.s0);
        *((__global uchar2*) (pUpTemp + outputIndex + stepwide    ))  = (gidy == gsizy-1)? (uchar2)temp1 : (uchar2)(vpUpt.s1);
        *((__global uchar2*) (pUpTemp + outputIndex + (stepwide<<1))) = (gidy == gsizy-1)? (uchar2)temp1 : (uchar2)(vpUpt.s2);
        *((__global uchar2*) (pUpTemp + outputIndex + stepwide * 3))  = (gidy == gsizy-1)? (uchar2)temp1 : (uchar2)(vpUpt.s3);
    }
}

