/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/
#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable 

/* kernel function */
__kernel void kernel_1(
  __global unsigned char* const pImageSrcSrc,
  int pImageSrcSrcWidth,
  int pImageSrcSrcHeight,
  int pImageSrcSrcStep,
  int pImageSrcSrcShift,
  __global unsigned char *pImageDstDst,
  int pImageDstDstWidth,
  int pImageDstDstHeight,
  int pImageDstDstStep,
  int pImageDstDstShift)
{
  /* kernel thread ID */
  int width = get_global_size(0); // 256
  int height = get_global_size(1); // 256
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (width) | gidy >= (height) )
    return;

  /* kernel index calculation */
#if 0
  int pImageSrcSrcIdx1 = pImageSrcSrcShift + ((float)gidy * 4) *pImageSrcSrcStep + ((float)gidx * 4) *sizeof(unsigned char);
  int pImageDstDstIdx1 = pImageDstDstShift + ((float)gidy * 1/4 * 4) *pImageDstDstStep + ((float)gidx * 1/4 * 4) *sizeof(unsigned char);
#endif

#if 0
  int pImageSrcSrcIdx1 = pImageSrcSrcShift + (float)(gidy << 2) *pImageSrcSrcStep + (float)(gidx << 2) *sizeof(unsigned char);
  int pImageDstDstIdx1 = pImageDstDstShift + ((float)gidy ) *pImageDstDstStep + ((float)gidx ) *sizeof(unsigned char);
#endif

#if 1
  int pImageSrcSrcIdx1 = pImageSrcSrcShift + (mad24(gidy, pImageSrcSrcStep, gidx) << 2);
  int pImageDstDstIdx1 = pImageDstDstShift + (mad24(gidy ,pImageDstDstStep, gidx)) ;
#endif


#if 0 // vector parallel.
  int pImageSrcSrcIdx1 = pImageSrcSrcShift + (float)(gidy << 2) *pImageSrcSrcStep + (float)(gidx << 4) *sizeof(unsigned char);
  int pImageDstDstIdx1 = pImageDstDstShift + ((float)gidy ) *pImageDstDstStep + ((float)(gidx << 2) ) *sizeof(unsigned char);
#endif

  /* kernel operands */
  __global unsigned char *pImageSrcSrcDt1 = pImageSrcSrc + pImageSrcSrcIdx1;
  __global unsigned char *pImageDstDstDt1 = pImageDstDst + pImageDstDstIdx1;

  /* kernel operation */
  {
#if 0
    short _sum = 0;
    uchar4 _rtemp0;
    __global uchar *_base = pImageSrcSrcDt1;
    _rtemp0 = vload4(0, _base);
    _sum  +=  _rtemp0.s0  + _rtemp0.s1  +  _rtemp0.s2 +_rtemp0.s3;
    _base = pImageSrcSrcDt1 + 1 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=  _rtemp0.s0 + _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3;
    _base = pImageSrcSrcDt1 + 2 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=  _rtemp0.s0 + _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3;
    _base = pImageSrcSrcDt1 + 3 * pImageSrcSrcStep;
    _rtemp0 = vload4(0, _base);
    _sum  +=  _rtemp0.s0     +     _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3  ;
    *pImageDstDstDt1 = _sum  >> 4;
    //*pImageDstDstDt1 = (_sum + 8) >> 4;
#endif

#if 1 // opt-1: vload -> pointer

    short _sum = 0;
    uchar4 _rtemp0;
    _rtemp0 = *((__global uchar4*)(pImageSrcSrcDt1));
    _sum  =  _rtemp0.s0  + _rtemp0.s1  +  _rtemp0.s2 +_rtemp0.s3;

    _rtemp0 = *((__global uchar4*)(pImageSrcSrcDt1 + pImageSrcSrcStep));
    _sum  +=  _rtemp0.s0 + _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3;

    _rtemp0 = *((__global uchar4*)(mad24(2, pImageSrcSrcStep, pImageSrcSrcDt1)));
    _sum  +=  _rtemp0.s0 + _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3;

    _rtemp0 = *((__global uchar4*)(mad24(3, pImageSrcSrcStep, pImageSrcSrcDt1)));
    _sum  +=  _rtemp0.s0     +     _rtemp0.s1 + _rtemp0.s2 + _rtemp0.s3  ;
    *pImageDstDstDt1 = (_sum + 8)  >> 4;
#endif

#if 0
#if 0
    int4 _sum = 0;
    int16 _rtemp0, _rtemp1, _rtemp2, _rtemp3;
    int16 _rtemp4;
    _rtemp0 =convert_int16( *((__global uchar16*)(pImageSrcSrcDt1)));
    _rtemp1 =convert_int16( *((__global uchar16*)(pImageSrcSrcDt1 + pImageSrcSrcStep)));
    _rtemp2 = convert_int16(*((__global uchar16*)(mad24(2, pImageSrcSrcStep, pImageSrcSrcDt1))));
    _rtemp3 = convert_int16(*((__global uchar16*)(mad24(3, pImageSrcSrcStep, pImageSrcSrcDt1))));

    _rtemp4 =_rtemp0  +  _rtemp1 + _rtemp2 + _rtemp3;
    //_rtemp4 =convert_int16(_rtemp0)  +  convert_int16(_rtemp1) +
      convert_int16(_rtemp2)  + convert_int16(_rtemp3);
    _sum.s0  =  _rtemp4.s0  + _rtemp4.s1  +  _rtemp4.s2 + _rtemp4.s3;
    _sum.s1  =  _rtemp4.s4  + _rtemp4.s5  +  _rtemp4.s6 + _rtemp4.s7;
    _sum.s2  =  _rtemp4.s8  + _rtemp4.s9  +  _rtemp4.sa + _rtemp4.sb;
    _sum.s3  =  _rtemp4.sc  + _rtemp4.sd  +  _rtemp4.se + _rtemp4.sf;
#endif

#if 0
    uchar16 _rtemp0, _rtemp1, _rtemp2, _rtemp3;
    int4 _sum;
    _rtemp0 = *((__global uchar16*)(pImageSrcSrcDt1));
    _sum.s0  =  _rtemp0.s0  + _rtemp0.s1  +  _rtemp0.s2 +  _rtemp0.s3;
    _sum.s1  =  _rtemp0.s4  + _rtemp0.s5  +  _rtemp0.s6 +  _rtemp0.s7;
    _sum.s2  =  _rtemp0.s8  + _rtemp0.s9  +  _rtemp0.sa + _rtemp0.sb;
    _sum.s3  =  _rtemp0.sc  + _rtemp0.sd  +  _rtemp0.se + _rtemp0.sf;

    _rtemp1 = *((__global uchar16*)(pImageSrcSrcDt1 + pImageSrcSrcStep));
    _sum.s0  +=  _rtemp1.s0  + _rtemp1.s1  +  _rtemp1.s2 + _rtemp1.s3;
    _sum.s1  +=  _rtemp1.s4  + _rtemp1.s5  +  _rtemp1.s6 + _rtemp1.s7;
    _sum.s2  +=  _rtemp1.s8  + _rtemp1.s9  +  _rtemp1.sa + _rtemp1.sb;
    _sum.s3  +=  _rtemp1.sc  + _rtemp1.sd  +  _rtemp1.se + _rtemp1.sf;

    _rtemp2 = *((__global uchar16*)(mad24(2, pImageSrcSrcStep, pImageSrcSrcDt1)));
    _sum.s0  +=  _rtemp2.s0  + _rtemp2.s1  +  _rtemp2.s2 + _rtemp2.s3;
    _sum.s1  +=  _rtemp2.s4  + _rtemp2.s5  +  _rtemp2.s6 + _rtemp2.s7;
    _sum.s2  +=  _rtemp2.s8  + _rtemp2.s9  +  _rtemp2.sa + _rtemp2.sb;
    _sum.s3  +=  _rtemp2.sc  + _rtemp2.sd  +  _rtemp2.se + _rtemp2.sf;

    _rtemp3 = *((__global uchar16*)(mad24(3, pImageSrcSrcStep, pImageSrcSrcDt1)));
    _sum.s0  +=  _rtemp3.s0  + _rtemp3.s1  +  _rtemp3.s2 + _rtemp3.s3;
    _sum.s1  +=  _rtemp3.s4  + _rtemp3.s5  +  _rtemp3.s6 + _rtemp3.s7;
    _sum.s2  +=  _rtemp3.s8  + _rtemp3.s9  +  _rtemp3.sa + _rtemp3.sb;
    _sum.s3  +=  _rtemp3.sc  + _rtemp3.sd  +  _rtemp3.se + _rtemp3.sf;
#endif

    int4 temp;
    temp = (_sum + 8) >> 4; 
    *((__global uchar4*)(pImageDstDstDt1)) =convert_uchar4( temp);
#if 0
    *(pImageDstDstDt1+1) = temp.s1;
    *(pImageDstDstDt1 + 2) = temp.s2;
    *(pImageDstDstDt1 + 3) = temp.s3;
#endif
#endif

  }

}

/* kernel function */
__kernel void kernel_2(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const border_mp_0Src,
  int border_mp_0SrcWidth,
  int border_mp_0SrcHeight,
  int border_mp_0SrcStep,
  int border_mp_0SrcShift,
  __global float* const border_mp_1Src,
  int border_mp_1SrcWidth,
  int border_mp_1SrcHeight,
  int border_mp_1SrcStep,
  int border_mp_1SrcShift,
  __global unsigned char *dstImageDS,
  int dstImageDSWidth,
  int dstImageDSHeight,
  int dstImageDSStep,
  int dstImageDSShift)
{
  /* kernel thread ID */
  int width = get_global_size(0); // 2
  int height = get_global_size(1); // 256
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  //printf("lid0 = %d, lid1 = %d, gidx = %d, gidy  = %d wid0 = %d, wid1 = %d\n",get_local_id(0), get_local_id(1), gidx, gidy, get_group_id(0), get_group_id(1) );
  //if ( gidx >=2 || gidy >= 256 )
  if ( gidx >=2 || gidy >= height )
    return;
  /* kernel index calculation */
  // srcImage[itx1][0], srcImage[it1x][M/4-1].
  //int srcImageSrcIdx1 = srcImageSrcShift + ((float)gidy) * srcImageSrcStep + gidx * (1024/4-1);  
  int srcImageSrcIdx1 = srcImageSrcShift + ((float)gidy) * srcImageSrcStep + gidx * (height-1);   // ?

  // srcImage[it1x+1][0], [it1x+1][M/4-1].
  //int srcImageSrcIdx2 = srcImageSrcShift + ((float)gidy + 1) *srcImageSrcStep + gidx * (1024/4-1);
  int srcImageSrcIdx2 = srcImageSrcShift + ((float)gidy + 1) *srcImageSrcStep + gidx * (height-1);

  
  // dstImage[it1x*4 + y][M-2], [it1x*4+y][0]
  // + 1 ---> 1, M-1
  //int dstImageDSIdx1 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep + gidx *(1024-2);
  //int dstImageDSIdx2 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep + gidx *(1024-2);
  //int dstImageDSIdx3 = dstImageDSShift + ((float)gidy * 4 + 2) *dstImageDSStep + gidx *(1024-2);
  //int dstImageDSIdx4 = dstImageDSShift + ((float)gidy * 4 + 3) *dstImageDSStep + gidx *(1024-2);
  int dstImageDSIdx1 = dstImageDSShift + ((float)gidy * 4) *dstImageDSStep + gidx *(height*4-2);
  int dstImageDSIdx2 = dstImageDSShift + ((float)gidy * 4 + 1) *dstImageDSStep + gidx *(height*4-2);
  int dstImageDSIdx3 = dstImageDSShift + ((float)gidy * 4 + 2) *dstImageDSStep + gidx *(height*4-2);
  int dstImageDSIdx4 = dstImageDSShift + ((float)gidy * 4 + 3) *dstImageDSStep + gidx *(height*4-2);



  /* kernel operands */
  __global unsigned char *srcImageSrcDt1 = srcImageSrc + srcImageSrcIdx1;
  __global unsigned char *srcImageSrcDt2 = srcImageSrc + srcImageSrcIdx2;

  __global unsigned char *dstImageDSDt1 = dstImageDS + dstImageDSIdx1;
  __global unsigned char *dstImageDSDt2 = dstImageDS + dstImageDSIdx2;
  __global unsigned char *dstImageDSDt3 = dstImageDS + dstImageDSIdx3;
  __global unsigned char *dstImageDSDt4 = dstImageDS + dstImageDSIdx4;

  // srcImage[it1x][0], srcImage[it1x][M/4-1];
  uchar srcImageSrcDt1Temp = *srcImageSrcDt1;   
  // srcImage[it1x+1][0], srcImage[it1x+1][M/4-1];
  uchar srcImageSrcDt2Temp = *srcImageSrcDt2;   

  // dstImage[it1x*4+ y][0], [it1x*4+y][1];


  /* kernel operation */
  {
    //if ( gidy == 255 ) 
    if ( gidy == height-1) 
    {
      // dstImage[it1x*4+ y][0], [it1x*4+y][1]; 
      *((__global uchar2*)(dstImageDSDt1)) = (srcImageSrcDt1Temp, srcImageSrcDt1Temp);
      *((__global uchar2*)(dstImageDSDt2)) = (srcImageSrcDt1Temp, srcImageSrcDt1Temp);
      *((__global uchar2*)(dstImageDSDt3)) = (srcImageSrcDt1Temp, srcImageSrcDt1Temp);
      *((__global uchar2*)(dstImageDSDt4)) = (srcImageSrcDt1Temp, srcImageSrcDt1Temp);

    } 
    else {
      float4 Temp1, Temp0; 
      float4 AddTemp0;

      //float border_mp_0Result1 [4][1] ; 
      // unrolled.
      Temp0.s0 = 1.0f * srcImageSrcDt1Temp; 
      Temp0.s1 = 3/4.0f  * srcImageSrcDt1Temp; 
      Temp0.s2 = 2/4.0f  * srcImageSrcDt1Temp; 
      Temp0.s3 = 1/4.0f * srcImageSrcDt1Temp; 

      // border_mp_1 * srcImage[it1x+1][0], [][M/4-1];
      Temp1.s0 = 0.0f * srcImageSrcDt2Temp; 
      Temp1.s1 = 1/4.0f * srcImageSrcDt2Temp; 
      Temp1.s2 = 2/4.0f * srcImageSrcDt2Temp; 
      Temp1.s3 = 3/4.0f * srcImageSrcDt2Temp; 


            // add 
      //float border_mp_0Result1Result1[4][1];
      AddTemp0.s0 = Temp0.s0 + Temp1.s0;
      AddTemp0.s1 = Temp0.s1 + Temp1.s1;
      AddTemp0.s2 = Temp0.s2 + Temp1.s2;
      AddTemp0.s3 = Temp0.s3 + Temp1.s3;

      // dstImage[it1x*4:4:1][0] = add;
      *((__global uchar2*)(dstImageDSDt1)) = ( (uchar)(AddTemp0.s0), (uchar)(AddTemp0.s0));
      *((__global uchar2*)(dstImageDSDt2)) = ( (uchar)AddTemp0.s1, (uchar) AddTemp0.s1);
      *((__global uchar2*)(dstImageDSDt3)) = ( (uchar)AddTemp0.s2, (uchar) AddTemp0.s2);
      *((__global uchar2*)(dstImageDSDt4)) = ( (uchar)AddTemp0.s3, (uchar) AddTemp0.s3);

    }
  }

}

/* kernel function */
__kernel void kernel_3(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const border_mp_0Src,
  int border_mp_0SrcWidth,
  int border_mp_0SrcHeight,
  int border_mp_0SrcStep,
  int border_mp_0SrcShift,
  __global float* const border_mp_1Src,
  int border_mp_1SrcWidth,
  int border_mp_1SrcHeight,
  int border_mp_1SrcStep,
  int border_mp_1SrcShift,
  __global unsigned char *dstImageDS,
  int dstImageDSWidth,
  int dstImageDSHeight,
  int dstImageDSStep,
  int dstImageDSShift)
{
  /* kernel thread ID */
  int height = get_global_size(1); //  2
  int width = get_global_size(0); // 256
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  //if ( gidy >= 256 )
  if ( gidy >= width )
    return;

  /* kernel index calculation */
  int srcImageSrcIdx3 = srcImageSrcShift + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx4;
  //int srcImageSrcIdx5 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int srcImageSrcIdx5 = srcImageSrcShift + (width - 1) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  //int srcImageSrcIdx6 = srcImageSrcShift + (1024 / 4 - 1) *srcImageSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int srcImageSrcIdx6 = srcImageSrcShift + (width - 1) *srcImageSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dstImageDSIdx1;
  int dstImageDSIdx2;
  int dstImageDSIdx3;
  int dstImageDSIdx4;

  int dstImageDSIdx5 = dstImageDSShift + (width*4 - 1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx6 = dstImageDSShift + (width*4 - 1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
  int dstImageDSIdx7 = dstImageDSShift + (width*4 - 2) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
  int dstImageDSIdx8 = dstImageDSShift + (width*4 - 2) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *srcImageSrcDt3 = srcImageSrc + srcImageSrcIdx3;
  __global unsigned char *srcImageSrcDt4;
  __global unsigned char *srcImageSrcDt5 = srcImageSrc + srcImageSrcIdx5;
  __global unsigned char *srcImageSrcDt6 = srcImageSrc + srcImageSrcIdx6;
  __global unsigned char *dstImageDSDt1;
  __global unsigned char *dstImageDSDt2;
  __global unsigned char *dstImageDSDt3;
  __global unsigned char *dstImageDSDt4;
  __global unsigned char *dstImageDSDt5 = dstImageDS + dstImageDSIdx5;
  __global unsigned char *dstImageDSDt6 = dstImageDS + dstImageDSIdx6;
  __global unsigned char *dstImageDSDt7 = dstImageDS + dstImageDSIdx7;
  __global unsigned char *dstImageDSDt8 = dstImageDS + dstImageDSIdx8;

  /* kernel operation */
  {


      srcImageSrcIdx4 = srcImageSrcShift + ((float)gidx + 1) *sizeof(unsigned char);
      srcImageSrcDt4 = srcImageSrc + srcImageSrcIdx4;

      dstImageDSIdx1 = dstImageDSShift + ((float)gidx * 4) *sizeof(unsigned char);
      dstImageDSDt1 = dstImageDS + dstImageDSIdx1;
      dstImageDSIdx3 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4) *sizeof(unsigned char);
      dstImageDSDt3 = dstImageDS + dstImageDSIdx3;

      dstImageDSIdx2 = dstImageDSShift + ((float)gidx * 4 + 1) *sizeof(unsigned char);
      dstImageDSDt2 = dstImageDS + dstImageDSIdx2;

      dstImageDSIdx4 = dstImageDSShift + (1) *dstImageDSStep + ((float)gidx * 4 + 1) *sizeof(unsigned char);
      dstImageDSDt4 = dstImageDS + dstImageDSIdx4;



    // Load operations.
      uchar4 Temp;
    Temp.s0 = *srcImageSrcDt3;
    Temp.s1 = *srcImageSrcDt5;
    Temp.s2 = *srcImageSrcDt4;
    Temp.s3 = *srcImageSrcDt6;
    //uchar srcImageSrcDt3Temp = *srcImageSrcDt3;
    //uchar srcImageSrcDt5Temp = *srcImageSrcDt5;
    //uchar srcImageSrcDt4Temp = *srcImageSrcDt4;
    //uchar srcImageSrcDt6Temp = *srcImageSrcDt6;

    if (gidx == width - 1) 
    {
      
      *((__global uchar2*)(dstImageDSDt3)) = (Temp.s0, Temp.s0);
      *((__global uchar2*)(dstImageDSDt2)) = (Temp.s0, Temp.s0);
      *((__global uchar2*)(dstImageDSDt5)) = (Temp.s1, Temp.s1);
      *((__global uchar2*)(dstImageDSDt7)) = (Temp.s1, Temp.s1);
      //*((__global uchar2*)(dstImageDSDt3)) = (srcImageSrcDt3Temp, srcImageSrcDt3Temp);
      //*((__global uchar2*)(dstImageDSDt2)) = (srcImageSrcDt3Temp, srcImageSrcDt3Temp);
      //*((__global uchar2*)(dstImageDSDt5)) = (srcImageSrcDt5Temp, srcImageSrcDt5Temp);
      //*((__global uchar2*)(dstImageDSDt7)) = (srcImageSrcDt5Temp, srcImageSrcDt5Temp);

    } else {
            //float border_mp_1Result1 [1][4] ;
      float4 Temp0, Temp1, Temp2, Temp3, AddTemp0, AddTemp1;

#if 0
      Temp0.s0 = 0.0     *  srcImageSrcDt4Temp; 
      Temp0.s1 = 1/4.0f  *  srcImageSrcDt4Temp; 
      Temp0.s2 = 2/4.0f  *  srcImageSrcDt4Temp; 
      Temp0.s3 = 3/4.0f  *  srcImageSrcDt4Temp; 

      Temp1.s0 = 1.0f    *  srcImageSrcDt3Temp; 
      Temp1.s1 = 3/4.0f  *  srcImageSrcDt3Temp; 
      Temp1.s2 = 2/4.0f  *  srcImageSrcDt3Temp; 
      Temp1.s3 = 1/4.0f  *  srcImageSrcDt3Temp; 
#endif

      Temp0.s0 = 0.0     *  Temp.s2; 
      Temp0.s1 = 1/4.0f  *  Temp.s2; 
      Temp0.s2 = 2/4.0f  *  Temp.s2; 
      Temp0.s3 = 3/4.0f  *  Temp.s2; 
      Temp1.s0 = 1.0f    *  Temp.s0; 
      Temp1.s1 = 3/4.0f  *  Temp.s0; 
      Temp1.s2 = 2/4.0f  *  Temp.s0; 
      Temp1.s3 = 1/4.0f  *  Temp.s0; 

       AddTemp0.s0 = Temp0.s0 + Temp1.s0;
       AddTemp0.s1 = Temp0.s1 + Temp1.s1;
       AddTemp0.s2 = Temp0.s2 + Temp1.s2;
       AddTemp0.s3 = Temp0.s3 + Temp1.s3;
    //   AddTemp0 = Temp0 + Temp1;

        *( (__global uchar4*)(dstImageDSDt3 )) = convert_uchar4(AddTemp0); 
        *( (__global uchar4*)(dstImageDSDt1 )) = convert_uchar4(AddTemp0);;


#if 0
          Temp2.s0 = 0.0f   * srcImageSrcDt6Temp; 
          Temp2.s1 = 1/4.0f * srcImageSrcDt6Temp; 
          Temp2.s2 = 2/4.0f * srcImageSrcDt6Temp; 
          Temp2.s3 = 3/4.0f * srcImageSrcDt6Temp; 
        
          Temp3.s0 = 1.0     * srcImageSrcDt5Temp; 
          Temp3.s1 = 3/4.0f  * srcImageSrcDt5Temp; 
          Temp3.s2 = 2/4.0f  * srcImageSrcDt5Temp; 
          Temp3.s3 = 1/4.0f  * srcImageSrcDt5Temp; 
#endif

          Temp2.s0 = 0.0f   * Temp.s3; 
          Temp2.s1 = 1/4.0f * Temp.s3; 
          Temp2.s2 = 2/4.0f * Temp.s3; 
          Temp2.s3 = 3/4.0f * Temp.s3; 
        
          Temp3.s0 = 1.0     * Temp.s1; 
          Temp3.s1 = 3/4.0f  * Temp.s1; 
          Temp3.s2 = 2/4.0f  * Temp.s1; 
          Temp3.s3 = 1/4.0f  * Temp.s1; 
          AddTemp1 = Temp2 + Temp3;

          *( (__global uchar4*)(dstImageDSDt5) ) = convert_uchar4(AddTemp1);
          *( (__global uchar4*)(dstImageDSDt7) ) = convert_uchar4(AddTemp1);
    }
  }

}

/* kernel function */
__kernel void kernel_4(
  __global unsigned char* const srcImageSrc,
  int srcImageSrcWidth,
  int srcImageSrcHeight,
  int srcImageSrcStep,
  int srcImageSrcShift,
  __global float* const mpSrc,
  int mpSrcWidth,
  int mpSrcHeight,
  int mpSrcStep,
  int mpSrcShift,
  __global unsigned char *dstImageDst,
  int dstImageDstWidth,
  int dstImageDstHeight,
  int dstImageDstStep,
  int dstImageDstShift)
{
  /* kernel thread ID */
  int width = get_global_size(0);
  int height = get_global_size(1);
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (width-1) || gidy >= (height -1) )
    return;

  /* kernel index calculation */
  int srcImageSrcIdx2 = srcImageSrcShift + ((float)gidy) *srcImageSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dstImageDstIdx1 = dstImageDstShift + ((float)gidy * 4 + 2) *dstImageDstStep + ((float)gidx * 4 + 2) *sizeof(unsigned char);

  /* kernel operands */
  __global float *mpSrcDt1 = (__global char *)mpSrc + mpSrcShift;
  __global unsigned char *srcImageSrcDt2 = srcImageSrc + srcImageSrcIdx2;
  __global unsigned char *dstImageDstDt1 = dstImageDst + dstImageDstIdx1;

  /* kernel operation */
  {
        float result0[4][4];
    float *result0_0;
    float *result0_1;
    float *result0_2;
    float *result0_3;
       result0_0 = (float*)result0;
       result0_1 = (float*)result0_0 + 4;
       result0_2 = (float*)result0_1 + 4;
       result0_3 = (float*)result0_2 + 4;
       uchar a00 = *(srcImageSrcDt2+0+0*srcImageSrcStep);
       uchar a10 = *(srcImageSrcDt2+0+1*srcImageSrcStep); 
       uchar a01 = *(srcImageSrcDt2+1+0*srcImageSrcStep);
       uchar a11 = *(srcImageSrcDt2+1+1*srcImageSrcStep);

       *(result0_0+0) = (float)((7/8.0f * a00 + (1/8.0f  * a10 )) * 7/8.0f + (7/8.0f * a01 + (1/8.0f * a11 )) * 1/8.0f);
       *(result0_0+1) = (float)((7/8.0f * a00 + (1/8.0f * a10 ))  * 5/8.0f +  (7/8.0f * a01 +     (1/8.0f * a11 )) * 3/8.0f);
       *(result0_0+2) = (float)(    (7/8.0f * a00 + (1/8.0f * a10)) * 3/8.0f + (7/8.0f *  a01 + (1/8.0f * a11 )) *  5/8.0f);
       *(result0_0+3) = (float)(    (7/8.0f * a00 +     (1/8.0f * a10 )) * 1/8.0f +  (7/8.0f * a01 +     (1/8.0f * a11 ))     * 7/8.0f);

       *(result0_1+0) = (float)(    (5/8.0f * a00 +     (3/8.0f * a10 ))  * 7/8.0f +   (5/8.0f * a01 +     (3/8.0f * a11 )) * 1/8.0f);
       *(result0_1+1) = (float)(    (5/8.0f * a00 +     (3/8.0f * a10 ))  * 5/8.0f +   (5/8.0f * a01 +     (3/8.0f * a11 )) * 3/8.0f);
       *(result0_1+2) = (float)(    (5/8.0f * a00 +     (3/8.0f * a10 ))     * 3/8.0f +     (5/8.0f * a01 +     (3/8.0f * a11 ))     * 5/8.0f);
       *(result0_1+3) = (float)(    (5/8.0f * a00 +     (3/8.0f * a10 ))     * 1/8.0f +     (5/8.0f * a01 +     (3/8.0f * a11 ))     * 7/8.0f);

       *(result0_2+0) = (float)(    (3/8.0f * a00 +     (5/8.0f * a10 ))     * 7/8.0f +     (3/8.0f * a01 +     (5/8.0f * a11 ))     * 1/8.0f);
       *(result0_2+1) = (float)(    (3/8.0f * a00 +     (5/8.0f * a10 ))     * 5/8.0f +     (3/8.0f * a01 +     (5/8.0f * a11 ))     * 3/8.0f);
       *(result0_2+2) = (float)(    (3/8.0f * a00 +     (5/8.0f * a10 ))     * 3/8.0f +     (3/8.0f * a01 +     (5/8.0f * a11 ))     * 5/8.0f);
       *(result0_2+3) = (float)(    (3/8.0f * a00 +     (5/8.0f * a10 )) * 1/8.0f +     (3/8.0f * a01 + (5/8.0f * a11 ))  * 7/8.0f);

       *(result0_3+0) = (float)(    (1/8.0f * a00 +     (7/8.0f * a10 ))     * 7/8.0f +     (1/8.0f * a01 +     (7/8.0f * a11 ))     * 1/8.0f);
       *(result0_3+1) = (float)(    (1/8.0f * a00 +     (7/8.0f * a10 ))     * 5/8.0f +     (1/8.0f * a01 +     (7/8.0f * a11 ))     * 3/8.0f);
       *(result0_3+2) = (float)(    (1/8.0f * a00 +     (7/8.0f * a10 ))     * 3/8.0f +     (1/8.0f * a01 +     (7/8.0f * a11 ))     * 5/8.0f);
       *(result0_3+3) = (float)(    (1/8.0f * a00 +     (7/8.0f * a10 ))     * 1/8.0f +     (1/8.0f * a01 +     (7/8.0f * a11 ))     * 7/8.0f);
    
#if 1 
    //for(int i=0;i<4;i++)
      //for(int j=0;j<4;j++)
    {
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 0 * dstImageDstStep ) ) = *( ( float*)( ( char*)result0 + 0 * sizeof(float)  + 0 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 0 * dstImageDstStep + 1) ) = *( ( float*)( ( char*)result0 + 1 * sizeof(float)  + 0 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 0 * dstImageDstStep + 2) ) = *( ( float*)( ( char*)result0 + 2 * sizeof(float)  + 0 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 0 * dstImageDstStep + 3) ) = *( ( float*)( ( char*)result0 + 3 * sizeof(float)  + 0 * 4 * sizeof(float)));


    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 1 * dstImageDstStep ) ) = *( ( float*)( ( char*)result0 + 0 * sizeof(float)  + 1 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 1 * dstImageDstStep + 1) ) = *( ( float*)( ( char*)result0 + 1 * sizeof(float)  + 1 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 1 * dstImageDstStep + 2) ) = *( ( float*)( ( char*)result0 + 2 * sizeof(float)  + 1 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 1 * dstImageDstStep + 3) ) = *( ( float*)( ( char*)result0 + 3 * sizeof(float)  + 1 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 2 * dstImageDstStep ) ) = *( ( float*)( ( char*)result0 + 0 * sizeof(float)  + 2 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 2 * dstImageDstStep + 1) ) = *( ( float*)( ( char*)result0 + 1 * sizeof(float)  + 2 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 2 * dstImageDstStep + 2) ) = *( ( float*)( ( char*)result0 + 2 * sizeof(float)  + 2 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 2 * dstImageDstStep + 3) ) = *( ( float*)( ( char*)result0 + 3 * sizeof(float)  + 2 * 4 * sizeof(float)));

    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 3 * dstImageDstStep ) ) = *( ( float*)( ( char*)result0 + 0 * sizeof(float)  + 3 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 3 * dstImageDstStep + 1) ) = *( ( float*)( ( char*)result0 + 1 * sizeof(float)  + 3 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 3 * dstImageDstStep + 2) ) = *( ( float*)( ( char*)result0 + 2 * sizeof(float)  + 3 * 4 * sizeof(float)));
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + 3 * dstImageDstStep + 3) ) = *( ( float*)( ( char*)result0 + 3 * sizeof(float)  + 3 * 4 * sizeof(float)));
    }      
  }
#endif

#if 0
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
    *( (__global unsigned char*)( (__global char*)dstImageDstDt1 + i * dstImageDstStep + j ) ) = *( ( float*)( ( char*)result0 + j * sizeof(float)  + i * 4 * sizeof(float)));
    }      }
#endif


}

/* kernel function */
__kernel void kernel_5(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global char* const gxSrc,
  int gxSrcWidth,
  int gxSrcHeight,
  int gxSrcStep,
  int gxSrcShift,
  __global char* const gySrc,
  int gySrcWidth,
  int gySrcHeight,
  int gySrcStep,
  int gySrcShift,
  __global unsigned short *pEdgeDst,
  int pEdgeDstWidth,
  int pEdgeDstHeight,
  int pEdgeDstStep,
  int pEdgeDstShift)
{
  /* kernel thread ID */
  int width = get_global_size(0); // 256
  int height = get_global_size(1); // 1024
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= width || gidy >= height )
    return;

  /* kernel index calculation */
  //int yPlaneSrcIdx3 = yPlaneSrcShift + ((float)gidy + -1) *yPlaneSrcStep + ((float)(gidx*4) + -1) *sizeof(unsigned char);
  int yPlaneSrcIdx3 = mad24( (gidy  -1) , yPlaneSrcStep, yPlaneSrcShift) + mad24(gidx, 4 , -1);
  //int pEdgeDstIdx1 = pEdgeDstShift + ((float)gidy) *pEdgeDstStep + 4* ((float)gidx) *sizeof(unsigned short);
  int pEdgeDstIdx1 = mad24(gidy, pEdgeDstStep, pEdgeDstShift)+  (gidx<<3);

  /* kernel operands */
  __global char *gxSrcDt1 = gxSrc + gxSrcShift;
  __global char *gySrcDt2 = gySrc + gySrcShift;
  __global unsigned char *yPlaneSrcDt3 = yPlaneSrc + yPlaneSrcIdx3;
  __global unsigned short *pEdgeDstDt1 = (__global char *)pEdgeDst + pEdgeDstIdx1;

#define OPT3
  /* kernel operation */
  {

    // opt-2: vector load.
#if 1
     int4 yPlane, yPlane2, yPlane3;
     int Pre, Next, Pre2, Next2, Pre3, Next3;
     int4 res, res2;
     //short4 edgeV; 
     short4 edgeV; 

     __global char* Addr = yPlaneSrcDt3;
     Pre = (int) (*((__global uchar*)( Addr )));
     yPlane = (convert_int4)(*(__global uchar4*)(Addr + 1));
     Next = (int) (*((__global uchar*)( Addr + 5 )));

      Addr += yPlaneSrcStep;
      Pre2 = (int) (*((__global uchar*)(Addr)));
      yPlane2 = (convert_int4)(*(__global uchar4*)( Addr + 1 ));
      Next2 = (int) (*((__global uchar*)(Addr + 5)));

Addr += yPlaneSrcStep;
      Pre3 = (int) (*((__global uchar*)(Addr)));
      yPlane3 = (convert_int4)(*(__global uchar4*)(Addr + 1));
      Next3 = (int) (*((__global uchar*)(Addr + 5 )));


      if ( gidy == 0 ||  gidy == height - 1 ){
        *((__global short4*)( pEdgeDstDt1)) = (short4)0;
      }
     else
     {

       res.s0 =  Pre +  ( yPlane.s0 << 1) +  yPlane.s1;
       res.s1 =  yPlane.s0 + ( yPlane.s1 << 1 ) +  yPlane.s2;
       res.s2 =  yPlane.s1 + (yPlane.s2 << 1)  + yPlane.s3 ; 
       res.s3 =  yPlane.s2 + (yPlane.s3 << 1) +  Next ; 

#ifdef OPT3
       res2.s0 = -Pre       +  yPlane.s1;
       res2.s1 = -yPlane.s0 +   yPlane.s2;
       res2.s2 = -yPlane.s1 +  yPlane.s3 ; 
       res2.s3 = -yPlane.s2 +   Next ; 
#endif


#ifdef OPT3
       res2.s0 +=  ( -Pre2   +  yPlane2.s1) << 1;
       res2.s1 +=  (-yPlane2.s0  + yPlane2.s2) << 1;
       res2.s2 +=  (-yPlane2.s1  + yPlane2.s3) << 1  ; 
       res2.s3 +=  (-yPlane2.s2   +  Next2) << 1 ; 
#endif

       res.s0 += -Pre3        -  (yPlane3.s0 << 1) -yPlane3.s1;
       res.s1 += -yPlane3.s0 - (yPlane3.s1 << 1)  -yPlane3.s2;
       res.s2 += -yPlane3.s1 - (yPlane3.s2 << 1)  -yPlane3.s3 ; 
       res.s3 += -yPlane3.s2 - (yPlane3.s3 << 1)   -Next3 ; 

#ifdef OPT3 
       res2.s0 +=   yPlane3.s1-Pre3 ;
       res2.s1 +=   yPlane3.s2-yPlane3.s0 ;
       res2.s2 +=   yPlane3.s3 -yPlane3.s1 ; 
       res2.s3 +=    Next3 -yPlane3.s2; 
#endif

#ifndef OPT3 
       Pre = (int) (*((__global uchar*) ( yPlaneSrcDt3 + 0 + yPlaneSrcStep * 0)));
       yPlane = (convert_int4) (*((__global uchar4*) ( yPlaneSrcDt3 + 1 + yPlaneSrcStep * 0)));
       Next = (int) (*((__global uchar*)   ( yPlaneSrcDt3 + 5 + yPlaneSrcStep * 0)));
       res2.s0 = -1 * Pre       + 0 * yPlane.s0 + 1 * yPlane.s1;
       res2.s1 = -1 * yPlane.s0 + 0 * yPlane.s1 + 1 * yPlane.s2;
       res2.s2 = -1 * yPlane.s1 + 0 *yPlane.s2  + 1 * yPlane.s3 ; 
       res2.s3 = -1 * yPlane.s2 + 0 *yPlane.s3  + 1 * Next ; 

       Pre = (int) (*((__global uchar*) ( yPlaneSrcDt3 + 0 + yPlaneSrcStep * 1)));
       yPlane = (convert_int4) (*((__global uchar4*) ( yPlaneSrcDt3 + 1 + yPlaneSrcStep * 1)));
       Next = (int) (*((__global uchar*)   ( yPlaneSrcDt3 + 5 + yPlaneSrcStep * 1)));
       res2.s0 += -2 * Pre + 0 * yPlane.s0 + 2 * yPlane.s1;
       res2.s1 += -2 * yPlane.s0 + 0 * yPlane.s1 + 2 * yPlane.s2;
       res2.s2 += -2 * yPlane.s1 + 0 *yPlane.s2 + 2* yPlane.s3 ; 
       res2.s3 += -2 * yPlane.s2 + 0 *yPlane.s3 + 2* Next ; 

       Pre = (int) (*((__global uchar*)   (yPlaneSrcDt3 + 0 + yPlaneSrcStep * 2)));
       yPlane = (convert_int4) (*((__global uchar4*) ( yPlaneSrcDt3 + 1 + yPlaneSrcStep * 2)));
       Next = (int) (*((__global uchar*) (yPlaneSrcDt3 + 5 + yPlaneSrcStep * 2)));
       res2.s0 += -1 * Pre       + 0 * yPlane.s0 + 1 * yPlane.s1;
       res2.s1 += -1 * yPlane.s0 + 0 * yPlane.s1 + 1 * yPlane.s2;
       res2.s2 += -1 * yPlane.s1 + 0 * yPlane.s2 + 1 * yPlane.s3 ; 
       res2.s3 += -1 * yPlane.s2 + 0 * yPlane.s3 + 1 * Next ; 
#endif

       {
         edgeV = convert_short4(abs(res) + abs(res2));
         edgeV.s0 = select((int)edgeV.s0, 0, gidx == 0 );
         edgeV.s3 = select((int)edgeV.s3, 0, gidx == (width-1) );

         *((__global short4*)( (global uchar*)pEdgeDstDt1)) = edgeV;
       }

     }

#endif

#if 0
         int gy[3];
     int yPlane[3];
     int R2Next;
     int res1;
    {

      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 0)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 0)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 0)));
      res1 = 1 * yPlane[0]; 
      res1 += 2 * yPlane[1]; 
      res1 += 1 * yPlane[2]; 


      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 1)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 1)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 1)));
      res1 += 0 * yPlane[0]; 
      res1 += 0 * yPlane[1]; 
      res1 += 0 * yPlane[2]; 


      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 2)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 2)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 2)));
      res1 += -1 * yPlane[0]; 
      res1 += -2 * yPlane[1]; 
      res1 += -1 * yPlane[2]; 
    }
         int gx[3];
     int res2;
    {
      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 0)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 0)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 0)));
      res2 = -1 * yPlane[0]; 
      res2 += 0 * yPlane[1]; 
      res2 += 1 * yPlane[2]; 

      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 1)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 1)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 1)));
      res2 += -2 * yPlane[0]; 
      res2 += 0 * yPlane[1]; 
      res2 += 2 * yPlane[2]; 

      yPlane[0] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 0 + yPlaneSrcStep * 2)));
      yPlane[1] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 1 + yPlaneSrcStep * 2)));
      yPlane[2] = ( int) ( *((__global unsigned char*) ((__global char*) yPlaneSrcDt3 + 2 + yPlaneSrcStep * 2)));
      res2 += -1 * yPlane[0]; 
      res2 += 0 * yPlane[1]; 
      res2 += 1 * yPlane[2]; 
    }
    if (gidy == 0 || (gidx) == 0 || gidy == height - 1 || gidx == height - 1)
      *pEdgeDstDt1 = 0;
    else
      *pEdgeDstDt1 = abs(res2) + abs(res1);
#endif
  }

}

/* kernel function */
__kernel void kernel_6(
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  __global unsigned int * _gtmpDst,
  __local unsigned int * _ltmp0)
{
  /* kernel thread ID */
  int width = get_global_size(0); // 256
  int height = get_global_size(1); // 1024

  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int gridx = get_group_id(0);
  const int gridy = get_group_id(1);
  const int lsizex = get_local_size(0);
  const int lsize = lsizex * get_local_size(1);
  const int grsizex = get_num_groups(0);
  const int lid= mad24(lidy, lsizex, lidx);

  /* kernel boundary check */

  /* kernel index calculation */
 // int pEdgeSrcIdx1 = pEdgeSrcShift+ ( gidx << 2 ) * sizeof(unsigned short)+ (float)gidy * pEdgeSrcStep;
  //int pEdgeSrcIdx1 =  mad24( gidx, 8, pEdgeSrcShift) + (float)gidy * pEdgeSrcStep;
  //int pEdgeSrcIdx1 =  mad24( gidx, 8, pEdgeSrcShift) + (float)gidy * pEdgeSrcStep;
  int pEdgeSrcIdx1 =   mad24((float)gidy,  pEdgeSrcStep, mad24( gidx, 8, pEdgeSrcShift));

  /* kernel operands */
  __global unsigned short *pEdgeSrcDt1 = (__global char *)pEdgeSrc + pEdgeSrcIdx1;

#define OPT1
  /* kernel operation */
  uint4 _rtmp0;
  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  
    _rtmp0 =convert_uint4( *( ( __global ushort4* )pEdgeSrcDt1 ));
    *( _ltmp0 + lid) =    _rtmp0.s0   +    _rtmp0.s1   +    _rtmp0.s2   +    _rtmp0.s3  ;
  
  barrier(CLK_LOCAL_MEM_FENCE);

  if ((gidx   < (pEdgeSrcWidth >> 2))  && gidy < pEdgeSrcHeight)
  {
    if (lid < 128)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 128);
  }
  barrier(CLK_LOCAL_MEM_FENCE);

  if ((gidx << 2 ) < pEdgeSrcWidth && gidy < pEdgeSrcHeight)
  {
#if 0
if (lid < 64)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 64);
    if (lid < 32)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 32);
    if (lid < 16)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 16);
    if (lid < 8)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 8);
    if (lid < 4)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 4);
    if (lid < 2)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 2);
#endif
#ifdef OPT1
    if (lid < 64)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 64);
    if (lid < 32)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 32);
    if (lid < 16)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 16);
    if (lid < 8)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 8);
    if (lid < 4)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 4);
    if (lid < 2)
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 2);
#endif

    if (lid < 1)
    {
      *(_ltmp0 + lid) += *(_ltmp0 + lid + 1);
     atomic_add((__global int*) _gtmpDst, (int)_ltmp0[0]);
     //atom_add(_gtmpDst, _ltmp0[0]);
    }
  }

}

/* kernel function */
__kernel void kernel_7(
  __global unsigned char* const yPlaneSrc,
  int yPlaneSrcWidth,
  int yPlaneSrcHeight,
  int yPlaneSrcStep,
  int yPlaneSrcShift,
  __global unsigned char* const yPlaneCSERSrc,
  int yPlaneCSERSrcWidth,
  int yPlaneCSERSrcHeight,
  int yPlaneCSERSrcStep,
  int yPlaneCSERSrcShift,
  __global unsigned short* const pEdgeSrc,
  int pEdgeSrcWidth,
  int pEdgeSrcHeight,
  int pEdgeSrcStep,
  int pEdgeSrcShift,
  float cutoff2Order,
  float m1,
  float m2,
  __global unsigned char *dstDst,
  int dstDstWidth,
  int dstDstHeight,
  int dstDstStep,
  int dstDstShift)
{
  /* kernel thread ID */
  int width = get_global_size(0);
  int height = get_global_size(1);
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (width) || gidy >= height )
    return;

  /* kernel index calculation */
  int pEdgeSrcIdx4 = pEdgeSrcShift + ((float)gidy) *pEdgeSrcStep + ((float)gidx *4) *sizeof(unsigned short);
  int yPlaneSrcIdx5 = yPlaneSrcShift + ((float)gidy + -1) *yPlaneSrcStep + ((float)gidx *4 + -1) *sizeof(unsigned char);
  int yPlaneSrcIdx6 = yPlaneSrcShift + ((float)gidy) *yPlaneSrcStep + ((float)gidx *4) *sizeof(unsigned char);
  int yPlaneCSERSrcIdx7 = yPlaneCSERSrcShift + ((float)gidy) *yPlaneCSERSrcStep + ((float)gidx *4) *sizeof(unsigned char);
  int dstDstIdx1 = dstDstShift + ((float)gidy) *dstDstStep + ((float)gidx *4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned short *pEdgeSrcDt4 = (__global char *)pEdgeSrc + pEdgeSrcIdx4;
  __global unsigned char *yPlaneSrcDt5 = yPlaneSrc + yPlaneSrcIdx5;
  __global unsigned char *yPlaneSrcDt6 = yPlaneSrc + yPlaneSrcIdx6;
  __global unsigned char *yPlaneCSERSrcDt7 = yPlaneCSERSrc + yPlaneCSERSrcIdx7;
  __global unsigned char *dstDstDt1 = dstDst + dstDstIdx1;

  /* kernel operation */
  {

    uchar pre;
    uchar4 tans, tmin;
    uchar4 pSrctemp;
    uchar4 temp;
    uchar pSrcnext;
    __global uchar *yPlaneSrcDt5Ptr = yPlaneSrcDt5; 
    
    pre = *yPlaneSrcDt5Ptr;
    tans = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1));
    pSrcnext = *(yPlaneSrcDt5Ptr +     5);


    pSrctemp = tans;
    temp = tans; // 1,2,3,4
    temp.s3 = pre;
    temp = temp.s3012; // 0,1,2,3

    tmin = tans;

    tans = max(tans, temp); // 0,1,2,3 --> 1,2,3,4
    tmin = min(tmin, temp); // 0,1,2,3 --> 1,2,3,4

    pSrctemp.s0 = pSrcnext;
    temp = pSrctemp.s1230;
    tans = max(tans, temp);
    tmin = min(tmin, temp);


    yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep ;
    pre = *yPlaneSrcDt5Ptr;
    pSrctemp = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1 )); // 1,2,3,4
    pSrcnext = *(yPlaneSrcDt5Ptr + 5);

    temp = pSrctemp;

    temp.s3 = pre;
    temp = temp.s3012;
    tans = max(tans, temp);
    tmin = min(tmin, temp);

    //temp = pSrctemp;
    tans = max(tans, pSrctemp);
    tmin = min(tmin, pSrctemp);

    temp = pSrctemp;
    temp.s0 = pSrcnext;
    temp   = temp.s1230;
    tans = max(tans, temp);
    tmin = min(tmin, temp);



    yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep ;
    pre = *yPlaneSrcDt5Ptr;
    pSrctemp = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1 )); // 1,2,3,4
    pSrcnext = *(yPlaneSrcDt5Ptr + 5);

    temp = pSrctemp;
    temp.s3 = pre;
    temp = temp.s3012;
    tans = max(tans, temp);
    tmin = min(tmin, temp);

    //temp = pSrctemp;
    tans = max(tans, pSrctemp);
    tmin = min(tmin, pSrctemp);

    temp = pSrctemp;
    temp.s0= pSrcnext;
    temp     = temp.s1230;
    tans = max(tans, temp);
    tmin = min(tmin, temp);

    uchar4 max_ans1 = tans;
    uchar4 maxValue;
    maxValue = convert_uchar4( max_ans1 );


#if 0
    yPlaneSrcDt5Ptr = yPlaneSrcDt5; 
    pre = *yPlaneSrcDt5Ptr;
    tans = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1));
    pSrcnext = *(yPlaneSrcDt5Ptr +     5);

    pSrctemp = tans;
    temp = tans; // 1,2,3,4
    temp.s3 = pre;
    temp = temp.s3012; // 0,1,2,3
    tans = min(tans, temp); // 0,1,2,3 --> 1,2,3,4

    pSrcnext = *(yPlaneSrcDt5Ptr +     5);
    pSrctemp.s0 = pSrcnext;
    temp = pSrctemp.s1230;
    tans = min(tans, temp);


    yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;
    pre = *yPlaneSrcDt5Ptr;
    pSrctemp = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1 )); // 1,2,3,4
    pSrcnext = *(yPlaneSrcDt5Ptr + 5);

    temp = pSrctemp;
    temp.s3 = pre;
    temp = temp.s3012;
    tans = min(tans, temp);

    temp = pSrctemp;
    tans = min(tans, temp);

    temp = pSrctemp;
    temp.s0 = pSrcnext;
    temp   = temp.s1230;
    tans = min(tans, temp);



    yPlaneSrcDt5Ptr = yPlaneSrcDt5Ptr + yPlaneSrcStep * 1;
    pre = *yPlaneSrcDt5Ptr;
    pSrctemp = *((__global uchar4*)(yPlaneSrcDt5Ptr + 1 )); // 1,2,3,4
    pSrcnext = *(yPlaneSrcDt5Ptr + 5);

    temp = pSrctemp;
    temp.s3 = pre;
    temp = temp.s3012;
    tans = min(tans, temp);

    temp = pSrctemp;
    tans = min(tans, temp);

    temp = pSrctemp;
    temp.s0= pSrcnext;
    temp     = temp.s1230;
    tans = min(tans, temp);

#endif



    uchar4 min_ans1 = tmin;
    uchar4 minValue;
    minValue = convert_uchar4( min_ans1 );
    int4 Op_ans1 = ((convert_int4)  (*((__global uchar4*) yPlaneSrcDt6))) - ( (convert_int4) (*((__global uchar4*) yPlaneCSERSrcDt7)));
    float4 pError;
    pError = convert_float4( Op_ans1 );
    float4 Op_ans2 = (convert_float4) ((convert_int4)  (*((__global ushort4*) pEdgeSrcDt4))) * (convert_float4) ( (convert_int4) (*((__global ushort4*) pEdgeSrcDt4)));
    float4 MatrixSub_ans1 = (convert_float4) (*((__global ushort4*) pEdgeSrcDt4));
    float4 MatrixSub_ans2 = (convert_float4) (*((__global ushort4*) pEdgeSrcDt4));
    float4 edge2Order = convert_float4(Op_ans2 * convert_float4(MatrixSub_ans1) * convert_float4(MatrixSub_ans2));
    float4 enhancedF = convert_float4(edge2Order * m1 + 1);
    float4 strength = convert_float4(edge2Order * m2 + 1);
    strength = convert_float4((enhancedF - 1) / (enhancedF * strength) + 1);
    float4 MatrixSub_ans3 = (convert_float4) (*((__global uchar4*) yPlaneCSERSrcDt7));
    enhancedF = convert_float4(pError * strength + convert_float4(MatrixSub_ans3));
    strength = convert_float4((0.0500000007F * edge2Order + cutoff2Order) / (cutoff2Order + edge2Order));
    float4 pSharpness_value = convert_float4(enhancedF > 255 ? 255 : (enhancedF < 0 ? 0 : enhancedF));
    edge2Order = convert_float4(convert_float4(minValue) - strength * (convert_float4(minValue) - enhancedF));
    strength = convert_float4(convert_float4(maxValue) + strength * (enhancedF - convert_float4(maxValue)));
    strength = convert_float4(strength < 255 ? strength : 255);
    edge2Order = convert_float4(enhancedF < convert_float4(minValue) ? (edge2Order > 0 ? edge2Order : 0) : pSharpness_value);
    uchar4 temp7;
    temp7 = convert_uchar4(enhancedF > convert_float4(maxValue) ? strength : edge2Order);
#if 0
    *dstDstDt1 = temp7.s0;
    *(dstDstDt1 + 1) = temp7.s1;
    *(dstDstDt1 + 2) = temp7.s2;
    *(dstDstDt1 + 3) = temp7.s3;
#endif
  *((__global uchar4*)(dstDstDt1)) = temp7;
  }

}

