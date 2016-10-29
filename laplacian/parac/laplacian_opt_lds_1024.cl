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
  if ( gidx >= width || gidy >= height ) // Width = 256, height=1024
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
    //int pre0, pre1, lat0, lat1;
    int2 pre, lat;

    // 2-1-2 --> 2-4-2
    //int4 SrcMid0 = (convert_int4) (*(__global uchar4*)( SrcSrcDt1 + 2 ));
    //pre0 = (int)(*SrcSrcDt1);
    //pre1 = (int)(*(SrcSrcDt1+1));
    pre = (convert_int2)(*(__global uchar2*)(SrcSrcDt1 ) );
    SrcMid0 = (convert_int4)(*(__global uchar4*)( SrcSrcDt1 + 2 ));
    lat = (convert_int2)(*(__global uchar2*)(SrcSrcDt1 + 6) );
    //lat0 = (int)(*(SrcSrcDt1 + 6));
    //lat1 = (int)(*(SrcSrcDt1 + 7));

    if ( gidx == 0 ){ 
      // SrcMid0 ==>{(*, 0), (*, 1), (*, 2), (*, 3)}; 
      //pre0 = SrcMid0.s3*4 - SrcMid0.s1*4 + SrcMid0.s0*2 - SrcMid0.s2;
      //pre1 = SrcMid0.s1 *2 - SrcMid0.s3;
      pre.s0 = SrcMid0.s3*4 - SrcMid0.s1*4 + SrcMid0.s0*2 - SrcMid0.s2;
      pre.s1 = SrcMid0.s1 *2 - SrcMid0.s3;
    }
    else if (gidx == 255 ){ 
      // SrcMid0 ==>{(*, N-4)->s0, (*, N-3)->s1, (*, N-2)->s2, (*, N-1)->s3; 
      //lat0 = SrcMid0.s2 * 2 - SrcMid0.s0;
      //lat1 = SrcMid0.s0 * 4 - SrcMid0.s2*4+ SrcMid0.s3*2 - SrcMid0.s1;
      lat.s0 = SrcMid0.s2 * 2 - SrcMid0.s0;
      lat.s1 = SrcMid0.s0 * 4 - SrcMid0.s2*4+ SrcMid0.s3*2 - SrcMid0.s1;
    }

    // pre0, pre1, s0, s1, s2, s3, lat0, lat1
    res1.s0 = mad24(pre.s1, 4, pre.s0) + mad24(6, SrcMid0.s0, SrcMid0.s2) + mad24(SrcMid0.s1, 4, 8);
    res1.s1 = mad24(SrcMid0.s0, 4, pre.s1) + mad24(6, SrcMid0.s1, SrcMid0.s3) + mad24(SrcMid0.s2, 4, 8);
    res1.s2 = mad24(SrcMid0.s1, 4, SrcMid0.s0) + mad24(6, SrcMid0.s2,  lat.s0) + mad24(SrcMid0.s3, 4, 8);
    res1.s3 = mad24(SrcMid0.s2, 4, SrcMid0.s1) + mad24(6, SrcMid0.s3, lat.s1) + mad24(lat.s0, 4, 8);

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
  const int lidx = get_local_id(0);
  const int lidy = get_local_id(1);
  const int lsizex = get_local_size(0);
  const int lsizey = get_local_size(1);
  //const int gridx = get_group_id(0);
  //const int gridy = get_group_id(1);

  const int num = (lsizey-1)*2 + 5;
  int average = num / lsizey;
  int remain =  num % lsizey;

#ifdef _OPTBANK
  __local int dsth[1030];
#else
  __local int dsth[515];
#endif


  /* kernel boundary check */
  if ( gidx >= 512 || gidy >= 512)
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
    int restemp;
    int pre0, pre1, mid0, lat0, lat1, mid5; 
    int res1;


    // 1. Read data into LDS first.
    int lid;
#ifdef _OPTBANK
    lid = lidy * average *2;
#else
     lid = lidy * average;
#endif
    dsth[lid] = (int) (*((__global uchar*)(dst_horizonSrcDt1 )));
    dsth[lid+1] =(int)  (*((__global uchar*)(dst_horizonSrcDt1 + dst_horizonSrcStep)));
    if( lidy == lsizey-1){
      dsth[lid+2] =(int)  (*((__global uchar*)(dst_horizonSrcDt1 + dst_horizonSrcStep*2 )));
      dsth[lid+3] =(int)  (*((__global uchar*)(dst_horizonSrcDt1 + dst_horizonSrcStep*3 )));
      dsth[lid+4] =(int)  (*((__global uchar*)(dst_horizonSrcDt1 + dst_horizonSrcStep*4 )));
    }
    barrier(CLK_LOCAL_MEM_FENCE);

    // 2. Do computation.

    if (gidy == 0 ){ 
      //mid5 = (convert_int)(*((__global uchar*)(dst_horizonSrcDt1 + dst_horizonSrcStep*3 ))); // [3][*]
      mid5 = dsth[lid+4+3];
      // pre0--> (-2, *),  pre1 --> (-1, *), mid0-->0, lat0 --> 1, lat1--> 2
      // mid5--> (3, *)
      // dsth[0] --> pre0, dsth[1] --> pre1, dsth[2] --> mid0, dsth[3] = lat0, dsth[4]= lat1
      //pre0 = mid5*4 - lat0*4 + mid0 * 2 - lat1; 
      //pre1 = lat0*2 - mid5;
      dsth[0] = ((mid5 - dsth[3])<<2) + (dsth[2]<<1) - dsth[4]; 
      dsth[1] = (dsth[3]<<1) - mid5;
    }
    if (gidy ==  511){ 
      // pre0->1020 --> M-4 -> 510, pre1->1021 --> M-3 -> 511,
      // mid0->1022-->M-2 -> 512, 
      // lat0-1023 --> M-1-> 513, lat1-1024(+1) -> 514
      //lat1 = (mid0 << 1) - pre0; 
      dsth[lid+4] = (dsth[lid+2] << 1) - dsth[lid]; 
    }

    //restemp = pre0 + pre1 * 4 +  mid0*6 +  lat0 * 4 + lat1 + 8;
    //__local int*ptr = dsth + lid;
    restemp = dsth[lid] + dsth[lid+1] * 4 + dsth[lid+2]*6 +  dsth[lid+3] * 4 + dsth[lid+4] + 8;
    //restemp = *ptr + (*(ptr+1)) * 4 + (*(ptr+2))*6 + (*(ptr+3))*4 + *(ptr+4) + 8;
    //res1 = restemp;  
    *((__global uchar*)(dst_dsDstDt1)) =convert_uchar( restemp >> 4 );
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
  //int layerDstIdx3 = layerDstShift + 1023 *layerDstStep + (gidx * 2);
  //__global unsigned char *layerDstDt3 = layerDst + layerDstIdx3;
  __global unsigned char *layerDstDt3 = mad24(1023, layerDstStep, layerDstShift) + mad24(gidx, 2 , layerDst) ;



  // layer[2*itx-1][ity*2], [ity*2+1] --> layer2
  int layerDstIdx5 = layerDstShift + (gidy * 2 + -1) *layerDstStep + (gidx * 2);
  __global unsigned char *layerDstDt5 = layerDst + layerDstIdx5;


  // layer[2*itx][2*ity] --> layer3
  //int layerDstIdx7 = layerDstShift + (gidy * 2) *layerDstStep + (gidx * 2) ;
  int layerDstIdx7 =  layerDstStep + layerDstIdx5 ;
  __global unsigned char *layerDstDt7 = layerDst + layerDstIdx7;


  short2 layer0, layer1, layer2, layer3; 
  short2 src0, src1, src2, src3; 
  short2 dst_ds0, dst_ds1, dst_ds2, dst_ds3;


  // Src[0][ity*2], Src[0][ity*2+1]
  SrcSrcIdx1 = SrcSrcShift + (gidx * 2);
  SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  src0 = (convert_short2)(*((__global uchar2*)(SrcSrcDt1)));
  //src0.s0 =(short) *((__global uchar*)(SrcSrcDt1));
  //src0.s1 =(short) *((__global uchar*)(SrcSrcDt1+1));

  // Src[M-1][ity*2], [ity*2+1]
  int SrcSrcIdx3 = SrcSrcShift + 1023 *SrcSrcStep + (gidx * 2) ;
  __global unsigned char *SrcSrcDt3 = SrcSrc + SrcSrcIdx3;
  src1 = (convert_short2)(*((__global uchar2*)(SrcSrcDt3)));
  //src1.s0 = (short)*((__global uchar*)(SrcSrcDt3));
  //src1.s1 = (short)*((__global uchar*)(SrcSrcDt3+1));

  // Src[2*itx-1][2*ity], Src[2*itx-1][2*ity+1]
  int SrcSrcIdx5 = SrcSrcShift + (gidy * 2  -1) *SrcSrcStep + (gidx * 2) ;
  __global unsigned char *SrcSrcDt5 = SrcSrc + SrcSrcIdx5;
  src2 = (convert_short2)(*((__global uchar2*)(SrcSrcDt5)));
  //src2.s0 = (short)*((__global uchar*)(SrcSrcDt5));
  //src2.s1 = (short)*((__global uchar*)(SrcSrcDt5+1));

  // Src[2*itx][2*ity]
  int SrcSrcIdx7 = SrcSrcShift + (gidy * 2) *SrcSrcStep + (gidx * 2) ;
  __global unsigned char *SrcSrcDt7 = SrcSrc + SrcSrcIdx7;
  src3 = (convert_short2)(*((__global uchar2*)(SrcSrcDt7)));
  //src3.s0 = (short)*((__global uchar*)(SrcSrcDt7));
  //src3.s1 = (short)*((__global uchar*)(SrcSrcDt7+1));

  // dst_ds[0][ity], dst_ds[0][ity+1];
  int dst_dsSrcIdx11 = dst_dsSrcShift + (gidx);
  __global unsigned char *dst_dsSrcDt11 = dst_dsSrc + dst_dsSrcIdx11;
  //dst_ds0 = (convert_short2)(*((__global uchar2*)(dst_dsSrcDt11)));
  dst_ds0.s0 =(short) *((__global uchar*)(dst_dsSrcDt11));
  dst_ds0.s1 =(short) *((__global uchar*)(dst_dsSrcDt11+1));

  // dst_ds[(M+1)/2-1][ity]
  int dst_dsSrcIdx9 = dst_dsSrcShift + 511 *dst_dsSrcStep + (gidx);
  __global unsigned char *dst_dsSrcDt9 = dst_dsSrc + dst_dsSrcIdx9;
  //dst_ds1 = convert_short2(*((__global uchar2*)(dst_dsSrcDt9)));
  dst_ds1.s0 = (short) *((dst_dsSrcDt9));
  dst_ds1.s1 = (short)*((dst_dsSrcDt9+1));

  int dst_dsSrcIdx14 = dst_dsSrcShift + (gidy + -1) *dst_dsSrcStep + (gidx) ;
  __global unsigned char *dst_dsSrcDt14 = dst_dsSrc + dst_dsSrcIdx14;
  //dst_ds2 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt14)));
  dst_ds2.s0 =(short) *((dst_dsSrcDt14));
  dst_ds2.s1 =(short) *((dst_dsSrcDt14+1));

  //dst_ds3 = (convert_int2)(*((__global uchar2*)(dst_dsSrcDt16)));
  //int dst_dsSrcIdx16 = dst_dsSrcShift + gidy *dst_dsSrcStep + gidx;
  int dst_dsSrcIdx16 =  dst_dsSrcStep + dst_dsSrcIdx14;
  __global unsigned char *dst_dsSrcDt16 = dst_dsSrc + dst_dsSrcIdx16;
  dst_ds3.s0 = (short)*((dst_dsSrcDt16));
  dst_ds3.s1 = (short)*((dst_dsSrcDt16+1));


  // layer[0][ity*2], layer[0][ity*2+1]
  layerDstIdx1 = layerDstShift + (gidx * 2) ;
  layerDstDt1 = layerDst + layerDstIdx1;

  // layer[0][ity*2+1] 
  //layerDstIdx2 = layerDstShift + (gidx * 2 + 1) ;
  layerDstDt2 = layerDstDt1 + 1; // layer0.s1
  //layerDstDt2 = layerDst + layerDstIdx2; // layer0.s1

  /* kernel operation */
  {
    // First line.
    if (gidy == 0) {
      layer0.s0 = src0.s0 - dst_ds0.s0;
      if (gidx != 511)
        layer0.s1 = src0.s1 - ((dst_ds0.s0 + dst_ds0.s1 + 1)>>1);
      if (gidx == 511 &&  widthOdd == 0)
        layer0.s1 = src0.s1 - dst_ds0.s0;

      *((__global uchar2*)(layerDstDt1)) = convert_uchar2(layer0);
      //*(layerDstDt1) = (char)(layer0.s0);
      //*(layerDstDt1+1) = (char)(layer0.s1);
    }

    // Last Line.
    if (heightOdd == 0 && gidy == 511) {
      layer1.s0 = src1.s0 - dst_ds1.s0;
      if( gidx != 511 )
        layer1.s1 =  src1.s1 - ((dst_ds1.s0 + dst_ds1.s1 + 1)>>1);
      if (gidx == 511 && widthOdd == 0)
        layer1.s1 = src1.s1 - dst_ds1.s0; // bug?

      *((__global uchar2*)(layerDstDt3)) = convert_uchar2(layer1);
      //*((__global uchar*)(layerDstDt3)) = (char)(layer1.s0);
      //*((__global uchar*)(layerDstDt3+1)) = (char)(layer1.s1);
    }

    // body.
    if (gidy != 0) {
      src2 = (convert_short2)(*((__global uchar2*)(SrcSrcDt5)));
      //src2.s0 = (short)*((__global uchar*)(SrcSrcDt5));
      //src2.s1 = (short)*((__global uchar*)(SrcSrcDt5+1));
      dst_ds2.s0 =(short) *((__global uchar*)(dst_dsSrcDt14));
      dst_ds2.s1 =(short) *((__global uchar*)(dst_dsSrcDt14+1));

      layer2.s0 = src2.s0 - ((dst_ds2.s0 + dst_ds3.s0+1)>>1);
      layer3.s0 = src3.s0 - dst_ds3.s0;
      if (gidx != 511) {
        layer2.s1 = src2.s1 - ((dst_ds2.s0 + dst_ds2.s1 + dst_ds3.s0 + dst_ds3.s1 + 2 )>>2);
        layer3.s1 = src3.s1 - ((dst_ds3.s0 + dst_ds3.s1 +1 )>>1);
      }

      if (widthOdd == 0 && gidx == 511) {
        layer2.s1 = src2.s1 - ((dst_ds2.s0 + dst_ds3.s0 +1)>>1); 
        layer3.s1 = src3.s1 - dst_ds3.s0;
      }
      *((__global uchar2*)(layerDstDt5)) = convert_uchar2(layer2);
      *((__global uchar2*)(layerDstDt7)) = convert_uchar2(layer3);

#if 0
      *((__global uchar*)(layerDstDt5)) = (char)(layer2.s0);
      *((__global uchar*)(layerDstDt5+1)) =(char)(layer2.s1);
      *((__global uchar*)(layerDstDt7)) = (char)(layer3.s0);
      *((__global uchar*)(layerDstDt7+1)) = (char)(layer3.s1);
#endif

    }
  }
  // write to layer.
}

