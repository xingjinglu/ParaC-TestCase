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
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);
  /* kernel boundary check */
  if ( gidx >= width || gidy >= height )
    return;

  /* kernel index calculation */
  int SrcSrcIdx1 = SrcSrcShift + (gidy) *SrcSrcStep + (gidx *4 + -2) *sizeof(unsigned char);
  int dst_horizonDstIdx1 = dst_horizonDstShift + (gidy) *dst_horizonDstStep + (gidx *4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  __global unsigned char *filter_horizonSrcDt2 = filter_horizonSrc + filter_horizonSrcShift;
  __global unsigned char *dst_horizonDstDt1 = dst_horizonDst + dst_horizonDstIdx1;


  /* kernel operation */
  {
    int4 res1, SrcMid0;
    int pre0, pre1, lat0, lat1;

    // 2-1-2 --> 2-4-2
    //int4 SrcMid0 = (convert_int4) (*(__global uchar4*)( SrcSrcDt1 + 2 ));
    pre0 = (int)(*SrcSrcDt1);
    pre1 = (int)(*(SrcSrcDt1+1));
    SrcMid0 = (convert_int4)(*(__global uchar4*)( SrcSrcDt1 + 2 ));
    lat0 = (int)(*(SrcSrcDt1 + 6));
    lat1 = (int)(*(SrcSrcDt1 + 7));

    if ( gidx == 0 ){ 
      // SrcMid0 ==>{(*, 0), (*, 1), (*, 2), (*, 3)}; 
      pre0 = SrcMid0.s3*4 - SrcMid0.s1*4 + SrcMid0.s0*2 - SrcMid0.s2;
      pre1 = SrcMid0.s1 *2 - SrcMid0.s3;
    }
    if (gidx == 255 ){ 
      // SrcMid0 ==>{(*, N-4)->s0, (*, N-3)->s1, (*, N-2)->s2, (*, N-1)->s3; 
      lat0 = SrcMid0.s2 * 2 - SrcMid0.s0;
      lat1 = SrcMid0.s0 * 4 - SrcMid0.s2*4+ SrcMid0.s3*2 - SrcMid0.s1;
    }

    // pre0, pre1, s0, s1, s2, s3, lat0, lat1
    res1.s0 = mad24(pre1, 4, pre0) + mad24(6, SrcMid0.s0, SrcMid0.s2) + mad24(SrcMid0.s1, 4, 8);
    res1.s1 = mad24(SrcMid0.s0, 4, pre1) + mad24(6, SrcMid0.s1, SrcMid0.s3) + mad24(SrcMid0.s2, 4, 8);
    res1.s2 = mad24(SrcMid0.s1, 4, SrcMid0.s0) + mad24(6, SrcMid0.s2,  lat0) + mad24(SrcMid0.s3, 4, 8);
    res1.s3 = mad24(SrcMid0.s2, 4, SrcMid0.s1) + mad24(6, SrcMid0.s3, lat1) + mad24(lat0, 4, 8);

    int4 temp0 = res1 >> 4;


#if 0
    *dst_horizonDstDt1 = temp0.s0;
    *(dst_horizonDstDt1 + 1) = temp0.s1;
    *(dst_horizonDstDt1 + 2) = temp0.s2;
    *(dst_horizonDstDt1 + 3) = temp0.s3;
#endif

#if 1
    *((__global uchar4 *)(dst_horizonDstDt1)) = convert_uchar4(temp0);
#endif
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
  //int dst_horizonSrcIdx1 = dst_horizonSrcShift + ((float)gidy * 2 + -2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  // Vector parallel on the X-axis.
  int dst_horizonSrcIdx1 = dst_horizonSrcShift + ((float)gidy * 2 + -2) *dst_horizonSrcStep + ((float)gidx * 8) *sizeof(unsigned char);

  // Vector parallel on the X-axis.
  int dst_dsDstIdx1 = dst_dsDstShift + ((float)gidy) *dst_dsDstStep + ((float)gidx) *4*sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *dst_horizonSrcDt1 = dst_horizonSrc + dst_horizonSrcIdx1;
  __global unsigned char *filter_verticalSrcDt2 = filter_verticalSrc + filter_verticalSrcShift;
  __global unsigned char *dst_dsDstDt1 = dst_dsDst + dst_dsDstIdx1;

  /* kernel operation */
  {
    int8 restemp;
    int8 pre0, pre1, mid0, lat0, lat1, mid5; 
    int4 res1;

// Index and Operand for BorderRule 
    int dst_horizonBRIndex0 = dst_horizonSrcShift + ((float)gidx * 2) *sizeof(unsigned char); // dst_horizon[0][*]
    int dst_horizonBRIndex1 = dst_horizonSrcShift + (1) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char); // dst_horizon[1][*]
    int dst_horizonBRIndex3 = dst_horizonSrcShift + (3) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char); // dst_horizon[3][*]
    int dst_horizonBRIndex2 = dst_horizonSrcShift + (2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char); // dst_horizon[2][*]

    int dst_horizonBRIndex8 = dst_horizonSrcShift + (1024 - 1) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex6 = dst_horizonSrcShift + (1024 - 2) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex10 = dst_horizonSrcShift + (1024 - 3) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
    int dst_horizonBRIndex7 = dst_horizonSrcShift + (1024 - 4) *dst_horizonSrcStep + ((float)gidx * 2) *sizeof(unsigned char);

    __global unsigned char * dst_horizonDt0 = dst_horizonSrc + dst_horizonBRIndex0;
    __global unsigned char * dst_horizonDt1 = dst_horizonSrc + dst_horizonBRIndex1;
    __global unsigned char * dst_horizonDt3 = dst_horizonSrc + dst_horizonBRIndex3;
    __global unsigned char * dst_horizonDt2 = dst_horizonSrc + dst_horizonBRIndex2;

    __global unsigned char * dst_horizonDt8 = dst_horizonSrc + dst_horizonBRIndex8;
    __global unsigned char * dst_horizonDt6 = dst_horizonSrc + dst_horizonBRIndex6;
    __global unsigned char * dst_horizonDt10 = dst_horizonSrc + dst_horizonBRIndex10;
    __global unsigned char * dst_horizonDt7 = dst_horizonSrc + dst_horizonBRIndex7;


    // Padding to avoid accessing illegal address.
    pre0 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*0 ))); // maybe border.
    pre1 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*1 )));
    mid0 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*2)));
    lat0 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*3 )));
    // Padding to avoid accessing illegal address.
    lat1 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*4 )));

    if (gidy == 0 ){ 
      mid5 = (convert_int8)(*((__global uchar8*)(dst_horizonSrcDt1 + dst_horizonSrcStep*5 ))); // [3][*]
      // pre0--> (-2, *),  pre1 --> (-1, *), mid0-->0, lat0 --> 1, lat1--> 2
      // mid5--> (3, *)
      pre0 = mid5*4 - lat0*4 + mid0 * 2 - lat1; 
      pre1 = lat0*2 - mid5;
    }
    if (gidy ==  511){ 
      // pre0-2044 --> M-4, pre1-2045 --> M-3, mid0-2046-->M-2, 
      // lat0-2047 --> M-1, lat1-2048(+1)
      lat1 = (mid0 << 1) - pre0; 
    }

    restemp = pre0 + pre1 * 4 +  mid0*6 +  lat0 * 4 + lat1 + 8;
#if  0

    if( gidx == 0 && gidy == 0 ){
       printf("input-0: 0 = %d, 1 = %d, 2 = %d, 3 = %d\n", pre0.s0, pre0.s1, pre0.s2, pre0.s3);
       printf("input-1: 0 = %d, 1 = %d, 2 = %d, 3 = %d\n", pre1.s0, pre1.s1, pre1.s2, pre1.s3);
       printf("input-2: 0 = %d, 1 = %d, 2 = %d, 3 = %d\n", mid0.s0, mid0.s1, mid0.s2, mid0.s3);
       printf("input-3: 0 = %d, 1 = %d, 2 = %d, 3 = %d\n", lat0.s0, lat0.s1, lat0.s2, lat0.s3);
       printf("input-4: 0 = %d, 1 = %d, 2 = %d, 3 = %d\n", lat1.s0, lat1.s1, lat1.s2, lat1.s3);
    }

    if( gidx == 0 && gidy == 0 ){
      printf("res: 0 = %d, 1 = %d, 2 = %d, 3 = %d \n", 
          restemp.s0, restemp.s2, restemp.s4, restemp.s6 );
    }
#endif
#if 1
    res1.s0 = restemp.s0;  
    res1.s1 = restemp.s2;  
    res1.s2 = restemp.s4;  
    res1.s3 = restemp.s6;  
#endif
    *((__global uchar4*)(dst_dsDstDt1)) =convert_uchar4( res1 / 16 );
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
  int layerDstIdx1;
  int layerDstIdx2;

  /* kernel operands */
  __global unsigned char *SrcSrcDt1;
    __global unsigned char *layerDstDt1;
  __global unsigned char *layerDstDt2;

  // layer[M-1][ity*2]
  int layerDstIdx3 = layerDstShift + 1023 *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *layerDstDt3 = layerDst + layerDstIdx3;


  // layer[2*itx-1][ity*2], [ity*2+1] --> layer2
  int layerDstIdx5 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *layerDstDt5 = layerDst + layerDstIdx5;

  // layer[2*itx][2*ity] --> layer3
  int layerDstIdx7 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *layerDstDt7 = layerDst + layerDstIdx7;


  short2 layer0, layer1, layer2, layer3; 
  short2 src0, src1, src2, src3; 
  short2 dst_ds0, dst_ds1, dst_ds2, dst_ds3;


  // Src[0][ity*2], Src[0][ity*2+1]
  SrcSrcIdx1 = SrcSrcShift + ((float)gidx * 2) *sizeof(unsigned char);
  SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  //src0 = (convert_int2)(*((__global uchar2*)(SrcSrcDt1)));
  src0.s0 =(short) *((__global uchar*)(SrcSrcDt1));
  src0.s1 =(short) *((__global uchar*)(SrcSrcDt1+1));

  // Src[M-1][ity*2], [ity*2+1]
  int SrcSrcIdx3 = SrcSrcShift + 1023 *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *SrcSrcDt3 = SrcSrc + SrcSrcIdx3;
  //src1 = (convert_int2)(*((__global uchar2*)(SrcSrcDt3)));
  src1.s0 = (short)*((__global uchar*)(SrcSrcDt3));
  src1.s1 = (short)*((__global uchar*)(SrcSrcDt3+1));

  // Src[2*itx-1][2*ity]
  int SrcSrcIdx5 = SrcSrcShift + ((float)gidy * 2  -1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *SrcSrcDt5 = SrcSrc + SrcSrcIdx5;
  //src2 = (convert_int2)(*((__global uchar2*)(SrcSrcDt5)));
  src2.s0 = (short)*((__global uchar*)(SrcSrcDt5));
  src2.s1 = (short)*((__global uchar*)(SrcSrcDt5+1));

  // Src[2*itx][2*ity]
  int SrcSrcIdx7 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  __global unsigned char *SrcSrcDt7 = SrcSrc + SrcSrcIdx7;
  //src3 = (convert_int2)(*((__global uchar2*)(SrcSrcDt7)));
  src3.s0 = (short)*((__global uchar*)(SrcSrcDt7));
  src3.s1 = (short)*((__global uchar*)(SrcSrcDt7+1));

  // dst_ds[0][ity], dst_ds[0][ity+1];
  int dst_dsSrcIdx11 = dst_dsSrcShift + ((float)gidx) *sizeof(unsigned char);
  __global unsigned char *dst_dsSrcDt11 = dst_dsSrc + dst_dsSrcIdx11;
  //dst_ds0 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt11)));
  dst_ds0.s0 =(short) *((__global uchar*)(dst_dsSrcDt11));
  dst_ds0.s1 =(short) *((__global uchar*)(dst_dsSrcDt11+1));

  // dst_ds[(M+1)/2-1][ity]
  int dst_dsSrcIdx9 = dst_dsSrcShift + 511 *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  __global unsigned char *dst_dsSrcDt9 = dst_dsSrc + dst_dsSrcIdx9;
  //dst_ds1 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt9)));
  dst_ds1.s0 = (short) *((dst_dsSrcDt9));
  dst_ds1.s1 = (short)*((dst_dsSrcDt9+1));

   int dst_dsSrcIdx14 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
    __global unsigned char *dst_dsSrcDt14 = dst_dsSrc + dst_dsSrcIdx14;
  //dst_ds2 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt14)));
  dst_ds2.s0 =(short) *((dst_dsSrcDt14));
  dst_ds2.s1 =(short) *((dst_dsSrcDt14+1));

  //dst_ds3 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt16)));
  int dst_dsSrcIdx16 = dst_dsSrcShift + gidy *dst_dsSrcStep + gidx *sizeof(unsigned char);
  __global unsigned char *dst_dsSrcDt16 = dst_dsSrc + dst_dsSrcIdx16;
  dst_ds3.s0 = (short)*((dst_dsSrcDt16));
  dst_ds3.s1 = (short)*((dst_dsSrcDt16+1));


  // layer[0][ity*2], layer[0][ity*2+1]
  layerDstIdx1 = layerDstShift + ((float)gidx * 2) *sizeof(unsigned char);
  layerDstDt1 = layerDst + layerDstIdx1;

  // layer[0][ity*2+1] 
  layerDstIdx2 = layerDstShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  layerDstDt2 = layerDst + layerDstIdx2; // layer0.s1

  /* kernel operation */
  {
    // First line.
    if (gidy == 0) {
      layer0.s0 = src0.s0 - dst_ds0.s0;
      if (gidx != 511)
        layer0.s1 = src0.s1 - ((dst_ds0.s0 + dst_ds0.s1 + 1)/2);
      if (gidx == 511 &&  widthOdd == 0)
        layer0.s1 = src0.s1 - dst_ds0.s0;

      *(layerDstDt1) = (char)(layer0.s0);
      *(layerDstDt1+1) = (char)(layer0.s1);
    }

    // Last Line.
    if (heightOdd == 0 && gidy == 511) {
      layer1.s0 = src1.s0 - dst_ds1.s0;
      //*layerDstDt3 = src1.s0 - dst_ds1.s0;
      if( gidx != 511 )
        layer1.s1 =  src1.s1 - ((dst_ds1.s0 + dst_ds1.s1 + 1)/2);
      //*layerDstDt4 =  src1.s1 - ((dst_ds1.s0 + dst_ds1.s1 + 1)>>1);
      if (gidx == 511 && widthOdd == 0)
        layer1.s1 = src1.s1 - dst_ds1.s0; // bug?
      
      //*((__global uchar2*)(layerDstDt3)) = convert_uchar2(layer1);
      *((__global uchar*)(layerDstDt3)) = (char)(layer1.s0);
      *((__global uchar*)(layerDstDt3+1)) = (char)(layer1.s1);
    }

    // body.
    if (gidy != 0) {
      src2.s0 = (short)*((__global uchar*)(SrcSrcDt5));
      src2.s1 = (short)*((__global uchar*)(SrcSrcDt5+1));
      dst_ds2.s0 =(short) *((__global uchar*)(dst_dsSrcDt14));
      dst_ds2.s1 =(short) *((__global uchar*)(dst_dsSrcDt14+1));

      layer2.s0 = src2.s0 - ((dst_ds2.s0 + dst_ds3.s0+1)/2);
      layer3.s0 = src3.s0 - dst_ds3.s0;
      //*layerDstDt5 = src2.s0 - ((dst_ds2.s0 + dst_ds3.s1 + 1)>>1);
      //*layerDstDt7 = src3.s0 - dst_ds3.s0;
      if (gidx != 511) {
        layer2.s1 = src2.s1 - ((dst_ds2.s0 + dst_ds2.s1 + dst_ds3.s0 + dst_ds3.s1 + 2 )/4);
        layer3.s1 = src3.s1 - ((dst_ds3.s0 + dst_ds3.s1 +1 )/2);
        //*layerDstDt6 = src2.s1 - (dst_ds2.s0 + dst_ds2.s1 + dst_ds3.s0 + dst_ds3.s1 + 2 )>>2;
        //*layerDstDt8 = src3.s1 - ((dst_ds3.s0 + dst_ds3.s1 +1)>>1);
      }

      if (widthOdd == 0 && gidx == 511) {
        layer2.s1 = src2.s1 - ((dst_ds2.s0 + dst_ds3.s0 +1)/2); 
        layer3.s1 = src3.s1 - dst_ds3.s0;
      }
      //*((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer2);
      //*((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);

#if 1
      *((__global uchar*)(layerDstDt5)) = (char)(layer2.s0);
      *((__global uchar*)(layerDstDt5+1)) =(char)(layer2.s1);
      *((__global uchar*)(layerDstDt7)) = (char)(layer3.s0);
      *((__global uchar*)(layerDstDt7+1)) = (char)(layer3.s1);
#endif

#if 0
      *((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer1);
      *((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);
#endif
    }
  }
  // write to layer.
}

