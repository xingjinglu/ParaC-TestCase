/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/
#pragma OPENCL EXTENSION cl_amd_printf : enable

/* kernel function */
__kernel void kernel_1(
  __global unsigned char* const SrcSrc,
  int SrcSrcWidth,
  int SrcSrcHeight,
  int SrcSrcStep,
  int SrcSrcShift,
  __global unsigned char* const filter_horizonSrc,
  int filter_horizonSrcWidth,
  int filter_horizonSrcHeight,
  int filter_horizonSrcStep,
  int filter_horizonSrcShift,
  __global unsigned char *dst_horizonDst,
  int dst_horizonDstWidth,
  int dst_horizonDstHeight,
  int dst_horizonDstStep,
  int dst_horizonDstShift)
{
  /* kernel thread ID */

  int width = get_global_size(0);
  int height = get_global_size(1);
  //if( height == 1024 )
  //printf("width = %d, height = %d", width, height);
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  /* kernel boundary check */
  if ( gidx >= width || gidy >= height )
    return;

  /* kernel index calculation */
  int SrcSrcIdx1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + ((float)gidx *4 + -2) *sizeof(unsigned char);
  int dst_horizonDstIdx1 = dst_horizonDstShift + ((float)gidy) *dst_horizonDstStep + ((float)gidx *4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  __global unsigned char *filter_horizonSrcDt2 = filter_horizonSrc + filter_horizonSrcShift;
 __global unsigned char *dst_horizonDstDt1 = dst_horizonDst + dst_horizonDstIdx1;

#if 0
  int SrcBRIndex0 = SrcSrcShift + ((float)gidy) *SrcSrcStep;
  int SrcBRIndex1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1) *sizeof(unsigned char);
  int SrcBRIndex8 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 1) *sizeof(unsigned char);
  int SrcBRIndex6 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 2) *sizeof(unsigned char);
  int SrcBRIndex10 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 3) *sizeof(unsigned char);
  int SrcBRIndex7 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 4) *sizeof(unsigned char);
  int SrcBRIndex2 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (2) *sizeof(unsigned char);
  int SrcBRIndex3 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (3) *sizeof(unsigned char);
#endif

#if 0
 __global unsigned char * SrcDt0 = SrcSrc + SrcBRIndex0;
    __global unsigned char * SrcDt1 = SrcSrc + SrcBRIndex1;
    __global unsigned char * SrcDt8 = SrcSrc + SrcBRIndex8;
    __global unsigned char * SrcDt6 = SrcSrc + SrcBRIndex6;
    __global unsigned char * SrcDt10 = SrcSrc + SrcBRIndex10;
    __global unsigned char * SrcDt7 = SrcSrc + SrcBRIndex7;
    __global unsigned char * SrcDt2 = SrcSrc + SrcBRIndex2;
    __global unsigned char * SrcDt3 = SrcSrc + SrcBRIndex3;
#endif



  /* kernel operation */
  {
    int4 res1;

    int4 SrcMid0 = convert_int4 (*(__global uchar4*)( SrcSrcDt1 ));
    int4 SrcMid1 = convert_int4 (*(__global uchar4*)( SrcSrcDt1 +   4 ));
    //int2 Pre, Lat;
    //int SrcPre0 = SrcMid0.s3<<2 - SrcMid0.s1<<2 + SrcMid0.s0<<1 - SrcMid0.s2;
    //int SrcPre1 = SrcMid0.s1 <<1 - SrcMid0.s3;
    //int SrcLat0 = SrcMid0.s2 << 1 - SrcMid0.s3;
    //int SrcLat1 = SrcMid0.s3 << 2  - SrcMid0.s2 << 2 + SrcMid1.s0<<2 - SrcMid1.s1;
    //Pre.s0 = SrcMid0.s3<<2 - SrcMid0.s1<<2 + SrcMid0.s0<<1 - SrcMid0.s2;
    //Pre.s1 = SrcMid0.s1 <<1 - SrcMid0.s3;
    //Lat.s0 = SrcMid0.s2 << 1 - SrcMid0.s3;
    //Lat.s1 = SrcMid0.s3 << 2  - SrcMid0.s2 << 2 + SrcMid1.s0<<2 - SrcMid1.s1;
    if (gidx == 0 ){ 
      //int SrcPre0 = SrcMid0.s3<<2 - SrcMid0.s1<<2 + SrcMid0.s0<<1 - SrcMid0.s2;
      //int SrcPre1 = SrcMid0.s1 <<1 - SrcMid0.s3;
      //SrcMid0.s0 = SrcPre0;
      //SrcMid0.s1 = SrcPre1;
      //SrcMid0.s0 = Pre.s0;
      //SrcMid0.s1 = Pre.s1;
      SrcMid0.s0 = SrcMid0.s3*4 - SrcMid0.s1*4 + SrcMid0.s0*2 - SrcMid0.s2;
      SrcMid1.s1 = SrcMid0.s1 *2 - SrcMid0.s3;

    }
    if (gidx == 255 ){ 
      //int SrcLat0 = SrcMid0.s2 << 1 - SrcMid0.s3;
      //int SrcLat1 = SrcMid0.s3 << 2  - SrcMid0.s2 << 2 + SrcMid1.s0<<2 - SrcMid1.s1;
      //SrcMid1.s2 = SrcLat0;
      //SrcMid1.s3 = SrcLat1;
      SrcMid1.s2 = SrcMid0.s2 << 1 - SrcMid0.s3;
      SrcMid1.s3 = SrcMid0.s3 << 2  - SrcMid0.s2 << 2 + SrcMid1.s0<<2 - SrcMid1.s1;
      //SrcMid1.s2 = Lat.s0;
      //SrcMid1.s3 = Lat.s1;
      //SrcMid1.s2 = SrcMid0.s2 *2 - SrcMid0.s3;
      //SrcMid1.s3 = SrcMid0.s3 *2   - SrcMid0.s2 * 4 + SrcMid1.s0*4 - SrcMid1.s1;
    }

    res1.s0 = mad24(SrcMid0.s1, 4, SrcMid0.s0) + mad24(6, SrcMid0.s2, SrcMid0.s3) + mad24(SrcMid0.s2, 4, 8);
    res1.s1 = mad24(SrcMid0.s2, 4, SrcMid0.s1) + mad24(6, SrcMid0.s3, SrcMid1.s1) + mad24(SrcMid1.s0, 4, 8);
    res1.s2 = mad24(SrcMid0.s3, 4, SrcMid0.s2) + mad24(SrcMid1.s0, 6, SrcMid1.s2) + mad24(SrcMid1.s1, 4, 8);
    res1.s3 = mad24(SrcMid1.s0, 4, SrcMid0.s3) + mad24(6, SrcMid1.s1, SrcMid1.s3) + mad24(SrcMid1.s2, 4, 8);

    //uchar4 temp0;
    //temp0 = convert_uchar4((res1 + 8) / 16);

    int4 temp0 = res1 >> 4;
    //uchar4 temp0 = convert_uchar4(res1 >> 4);
#if 0
    *dst_horizonDstDt1 = temp0.s0;
    *(dst_horizonDstDt1 + 1) = temp0.s1;
    *(dst_horizonDstDt1 + 2) = temp0.s2;
    *(dst_horizonDstDt1 + 3) = temp0.s3;
#endif
    //*((__global uchar4 *)(dst_horizonDstDt1)) = temp0;
    *((__global uchar4 *)(dst_horizonDstDt1)) =convert_uchar4(temp0);
  }

}

/* kernel function */
__kernel void kernel_2(
  __global unsigned char* const filter_verticalSrc,
  int filter_verticalSrcWidth,
  int filter_verticalSrcHeight,
  int filter_verticalSrcStep,
  int filter_verticalSrcShift,
  __global unsigned char* const dst_horizonSrc,
  int dst_horizonSrcWidth,
  int dst_horizonSrcHeight,
  int dst_horizonSrcStep,
  int dst_horizonSrcShift,
  __global unsigned char *dst_dsDst,
  int dst_dsDstWidth,
  int dst_dsDstHeight,
  int dst_dsDstStep,
  int dst_dsDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 128 || gidy >= 512 )
    return;

  /* kernel index calculation */
  int dst_horizonSrcIdx1 = dst_horizonSrcShift + ((float)gidy * 2 + -2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int dst_dsDstIdx1 = dst_dsDstShift + ((float)gidy) *dst_dsDstStep + ((float)gidx) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *dst_horizonSrcDt1 = dst_horizonSrc + dst_horizonSrcIdx1;
  __global unsigned char *filter_verticalSrcDt2 = filter_verticalSrc + filter_verticalSrcShift;
  __global unsigned char *dst_dsDstDt1 = dst_dsDst + dst_dsDstIdx1;

  /* kernel operation */
  {
    //int filter_vertical[5];
    //int dst_horizon[5];
    //int R2Next;
    int4 res1;

    int8 pre1, pre2, lat1, lat2; 
    int8 mid0, mid1, mid2, mid3, mid4;
    int8 restemp;

// Index and Operand for BorderRule 
    int dst_horizonBRIndex0 = dst_horizonSrcShift + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex1 = dst_horizonSrcShift + (1) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex8 = dst_horizonSrcShift + (1024 - 1) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex6 = dst_horizonSrcShift + (1024 - 2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex10 = dst_horizonSrcShift + (1024 - 3) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex7 = dst_horizonSrcShift + (1024 - 4) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex2 = dst_horizonSrcShift + (2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex3 = dst_horizonSrcShift + (3) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    __global unsigned char * dst_horizonDt0 = dst_horizonSrc + dst_horizonBRIndex0;
    __global unsigned char * dst_horizonDt1 = dst_horizonSrc + dst_horizonBRIndex1;
    __global unsigned char * dst_horizonDt8 = dst_horizonSrc + dst_horizonBRIndex8;
    __global unsigned char * dst_horizonDt6 = dst_horizonSrc + dst_horizonBRIndex6;
    __global unsigned char * dst_horizonDt10 = dst_horizonSrc + dst_horizonBRIndex10;
    __global unsigned char * dst_horizonDt7 = dst_horizonSrc + dst_horizonBRIndex7;
    __global unsigned char * dst_horizonDt2 = dst_horizonSrc + dst_horizonBRIndex2;
    __global unsigned char * dst_horizonDt3 = dst_horizonSrc + dst_horizonBRIndex3;

#if 1
    mid0 = convert_int8(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*0 )));
    mid1 = convert_int8(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*1 )));
    mid2 = convert_int8(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*2)));
    mid3 = convert_int8(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*3 )));
    mid4 = convert_int8(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*4 )));
#endif

    if (gidy == 0 ){ 
#if 1
      mid0 = mid3<<2 - mid1<<2 + mid0<<1 - mid2; 
      mid1 = mid1<<1 - mid3;
      //mid0 = pre1;
      //mid1 = pre2;
#endif
    }
    if (gidy == 511 ){ 
#if 1
      mid4 = mid3<<1 - mid4; 
      //mid4 = lat1;
#endif
    }

    restemp = mid0 + mid1<<2 +  mid2*6 +  mid3<<2 + mid4 + 8;
    res1.s0 = restemp.s0;  
    res1.s1 = restemp.s2;  
    res1.s2 = restemp.s4;  
    res1.s3 = restemp.s6;  
    *((__global uchar4*)(dst_dsDstDt1)) =convert_uchar4( res1 >>  4);
  }

}

/* kernel function */
__kernel void kernel_3(
  __global unsigned char* const SrcSrc,
  int SrcSrcWidth,
  int SrcSrcHeight,
  int SrcSrcStep,
  int SrcSrcShift,
  __global unsigned char* const dst_dsSrc,
  int dst_dsSrcWidth,
  int dst_dsSrcHeight,
  int dst_dsSrcStep,
  int dst_dsSrcShift,
  int widthOdd,
  int heightOdd,
  __global unsigned char *layerDst,
  int layerDstWidth,
  int layerDstHeight,
  int layerDstStep,
  int layerDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 512 || gidy >= 512 )
    return;

  /* kernel index calculation */
  int SrcSrcIdx1;
  int SrcSrcIdx2;
  int SrcSrcIdx3 = SrcSrcShift + 1023 *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx5 = SrcSrcShift + ((float)gidy * 2 + -1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx7 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);

  int dst_dsSrcIdx9 = dst_dsSrcShift + 511 *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx11 = dst_dsSrcShift + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx14 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx16 = dst_dsSrcShift + ((float)gidy) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);

  int layerDstIdx1;
  int layerDstIdx2;
  int layerDstIdx3 = layerDstShift + 1023 *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  //int layerDstIdx4 = layerDstShift + 1023 *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int layerDstIdx5 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  //int layerDstIdx6 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int layerDstIdx7 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  //int layerDstIdx8 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1;
  __global unsigned char *SrcSrcDt3 = SrcSrc + SrcSrcIdx3;
  __global unsigned char *SrcSrcDt5 = SrcSrc + SrcSrcIdx5;
  __global unsigned char *SrcSrcDt7 = SrcSrc + SrcSrcIdx7;

  __global unsigned char *dst_dsSrcDt9 = dst_dsSrc + dst_dsSrcIdx9;
  __global unsigned char *dst_dsSrcDt11 = dst_dsSrc + dst_dsSrcIdx11;
  __global unsigned char *dst_dsSrcDt14 = dst_dsSrc + dst_dsSrcIdx14;
  __global unsigned char *dst_dsSrcDt16 = dst_dsSrc + dst_dsSrcIdx16;
  __global unsigned char *layerDstDt1;
  __global unsigned char *layerDstDt2;
  __global unsigned char *layerDstDt3 = layerDst + layerDstIdx3;
  //__global unsigned char *layerDstDt4 = layerDst + layerDstIdx4;
  __global unsigned char *layerDstDt5 = layerDst + layerDstIdx5;
 // __global unsigned char *layerDstDt6 = layerDst + layerDstIdx6;
  __global unsigned char *layerDstDt7 = layerDst + layerDstIdx7;
 // __global unsigned char *layerDstDt8 = layerDst + layerDstIdx8;

  int2 layer0, layer1, layer2, layer3; 
  int2 src0, src1, src2, src3; 
  int2 dst_ds0, dst_ds1, dst_ds2, dst_ds3;


  SrcSrcIdx1 = SrcSrcShift + ((float)gidx * 2) *sizeof(unsigned char);
  SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  src0 = convert_int2(*((__global uchar2*)(SrcSrcDt1)));
  src1 = convert_int2(*((__global uchar2*)(SrcSrcDt3)));
  src2 = convert_int2(*((__global uchar2*)(SrcSrcDt5)));
  src3 = convert_int2(*((__global uchar2*)(SrcSrcDt7)));
  dst_ds0 = convert_int2(*((__global uchar2*)(dst_dsSrcDt11)));
  dst_ds1 = convert_int2(*((__global uchar2*)(dst_dsSrcDt9)));
  dst_ds2 = convert_int2(*((__global uchar2*)(dst_dsSrcDt14)));
  dst_ds3 = convert_int2(*((__global uchar2*)(dst_dsSrcDt16)));

  layerDstIdx1 = layerDstShift + ((float)gidx * 2) *sizeof(unsigned char);
  layerDstDt1 = layerDst + layerDstIdx1;
  layerDstIdx2 = layerDstShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  layerDstDt2 = layerDst + layerDstIdx2; // layer0.s1

  /* kernel operation */
  {
    if (gidy == 0) {
      layer0.s0 = src0.s0 - dst_ds0.s0;
      //*layerDstDt1 = src0.s0 - dst_ds0.s0;

      //
      if (gidx != 511)
        layer0.s1 = src0.s1 - ( dst_ds0.s0 + dst_ds0.s1 + 1)>>1;
        //*layerDstDt2 = src0.s1 - ( dst_ds0.s0 + dst_ds0.s1 + 1)>>1;
      //
      if (gidx == 511 && widthOdd == 0)
        layer0.s1 = src0.s1 - dst_ds0.s0;
        //*layerDstDt2 = src0.s1 - dst_ds0.s0;

      //
      *((__global uchar2*)(layerDstDt1)) = convert_uchar2(layer0);

    }
    if (heightOdd == 0 && gidy == 511) {
      layer1.s0 = src1.s0 - dst_ds1.s0;
      //*layerDstDt3 = src1.s0 - dst_ds1.s0;


      layer1.s1 =  src1.s1 - ( dst_ds1.s0 + dst_ds1.s1 + 1)>>1;
      //*layerDstDt4 =  src1.s1 - ( dst_ds1.s0 + dst_ds1.s1 + 1)>>1;

      //
      if (gidx == 511 && widthOdd == 0)
        layer1.s1 = src1.s1 - dst_ds1.s0;
        //*layerDstDt4 = src1.s1 - dst_ds1.s0;

      *((__global uchar2*)(layerDstDt3)) = convert_uchar2(layer1);
    }
    if (gidy != 0) {
      layer2.s0 = src2.s0 - (dst_ds2.s0 + dst_ds3.s1 + 1)>>2;
      layer3.s0 = src3.s0 - dst_ds3.s0;
      //*layerDstDt5 = src2.s0 - (dst_ds2.s0 + dst_ds3.s1 + 1)>>2;
      //*layerDstDt7 = src3.s0 - dst_ds3.s0;


      if (gidx != 511) {
        layer2.s1 = src2.s1 - (dst_ds2.s0 + dst_ds2.s1 + dst_ds3.s0 + dst_ds3.s1 + 2 )>>2;
        layer3.s1 = src3.s1 - ( dst_ds3.s0 + dst_ds3.s1 +1 )>>1;
        //*layerDstDt6 = src2.s1 - (dst_ds2.s0 + dst_ds2.s1 + dst_ds3.s0 + dst_ds3.s1 + 2 )>>2;
        //*layerDstDt8 = src3.s1 - ( dst_ds3.s0 + dst_ds3.s1 +1 )>>1;
      }


      //
      if (widthOdd == 0 && gidx == 511) {
        layer2.s1 = src2.s0 - (dst_ds2.s0 + dst_ds3.s1 +1)>>1; 
        layer3.s1 = src3.s0 - dst_ds3.s0;
        //*layerDstDt6 = src2.s0 - (dst_ds2.s0 + dst_ds3.s1 +1)>>1; 
        //*layerDstDt8 = src3.s0 - dst_ds3.s0;
      }

      //*((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer1);
      //*((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);
      *((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer2);
      *((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);
      //*((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer1);
      //*((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);
    }
  }
  // write to layer.


}

