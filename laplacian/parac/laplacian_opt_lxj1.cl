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


  int SrcBRIndex0 = SrcSrcShift + ((float)gidy) *SrcSrcStep;
  int SrcBRIndex1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1) *sizeof(unsigned char);
  int SrcBRIndex8 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 1) *sizeof(unsigned char);
  int SrcBRIndex6 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 2) *sizeof(unsigned char);
  int SrcBRIndex10 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 3) *sizeof(unsigned char);
  int SrcBRIndex7 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 4) *sizeof(unsigned char);
  int SrcBRIndex2 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (2) *sizeof(unsigned char);
  int SrcBRIndex3 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (3) *sizeof(unsigned char);
 __global unsigned char * SrcDt0 = SrcSrc + SrcBRIndex0;
    __global unsigned char * SrcDt1 = SrcSrc + SrcBRIndex1;
    __global unsigned char * SrcDt8 = SrcSrc + SrcBRIndex8;
    __global unsigned char * SrcDt6 = SrcSrc + SrcBRIndex6;
    __global unsigned char * SrcDt10 = SrcSrc + SrcBRIndex10;
    __global unsigned char * SrcDt7 = SrcSrc + SrcBRIndex7;
    __global unsigned char * SrcDt2 = SrcSrc + SrcBRIndex2;
    __global unsigned char * SrcDt3 = SrcSrc + SrcBRIndex3;



  /* kernel operation */
  {
         int filter_horizon[5];
    int4 Src;
     int R2Next, R3Next, R4Next, R5Next;
    int4 res1;
    if (gidx == 0 ){ 
#if 0
    int4 filter_horizonMid0 = (convert_int4) (vload4(0, filter_horizonSrcDt2 + 0 * filter_horizonSrcStep + 0 + 0 * sizeof(unsigned char)));
     int filter_horizonMid1 = ( int) (*(filter_horizonSrcDt2 + 0 * filter_horizonSrcStep + 4 + 0 * sizeof(unsigned char)));

#endif

#if 0
    int SrcBRIndex0 = SrcSrcShift + ((float)gidy) *SrcSrcStep;
    int SrcBRIndex1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1) *sizeof(unsigned char);
    int SrcBRIndex8 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 1) *sizeof(unsigned char);
    int SrcBRIndex6 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 2) *sizeof(unsigned char);
    int SrcBRIndex10 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 3) *sizeof(unsigned char);
    int SrcBRIndex7 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 4) *sizeof(unsigned char);
    int SrcBRIndex2 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (2) *sizeof(unsigned char);
    int SrcBRIndex3 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (3) *sizeof(unsigned char);
    __global unsigned char * SrcDt0 = SrcSrc + SrcBRIndex0;
    __global unsigned char * SrcDt1 = SrcSrc + SrcBRIndex1;
    __global unsigned char * SrcDt8 = SrcSrc + SrcBRIndex8;
    __global unsigned char * SrcDt6 = SrcSrc + SrcBRIndex6;
    __global unsigned char * SrcDt10 = SrcSrc + SrcBRIndex10;
    __global unsigned char * SrcDt7 = SrcSrc + SrcBRIndex7;
    __global unsigned char * SrcDt2 = SrcSrc + SrcBRIndex2;
    __global unsigned char * SrcDt3 = SrcSrc + SrcBRIndex3;

#endif

    int4 SrcPreTemp = (convert_int4)(*(__global uchar4*)(SrcDt0));

     //int SrcPre0 = ( int) ((*SrcDt3) * 4 - (*SrcDt1) * 4 + (*SrcDt0) * 2 - (*SrcDt2));
     //int SrcPre1 = ( int) ((*SrcDt1) * 2 - (*SrcDt3));
    int SrcPre0 = SrcPreTemp.s3*4 - SrcPreTemp.s1*4 + SrcPreTemp.s0*2 - SrcPreTemp.s2;
    int SrcPre1 = SrcPreTemp.s1 * 2 - SrcPreTemp.s3;
    int4 SrcMid0 = (convert_int4) (*(__global uchar4*)( SrcSrcDt1 + 0 * SrcSrcStep + 0 + 2 * sizeof(unsigned char)));
    //int4 SrcMid0 = (convert_int4) (vload4(0, SrcSrcDt1 + 0 * SrcSrcStep + 0 + 2 * sizeof(unsigned char)));
    int2 SrcMid1 = (convert_int2) (vload2(0, SrcSrcDt1 + 0 * SrcSrcStep + 4 + 2 * sizeof(unsigned char)));

#if 0
    res1.s0 =  SrcPre0;
    res1.s0 += SrcPre1<<2;
    res1.s0 += SrcMid0.s0<<2 + SrcMid0.s0<<1;
    res1.s0 += SrcMid0.s1<<2;
    res1.s0 += SrcMid0.s2;
#endif

    //res1.s0 = SrcPre0 + SrcPre1<<2 + SrcMid0.s0 << 2 + SrcMid0.s0<<1 + SrcMid0.s1<<2 + SrcMid0.s2;
    res1.s0 = mad24(SrcPre1,4, SrcPre0) + mad24(6, SrcMid0.s0, SrcMid0.s2) + mad24(SrcMid0.S1, 4, 8);

#if 0
    res1.s1 = SrcPre1;
    //res1.s1 += 4 * SrcMid0.s0;
    //res1.s1 += 6 * SrcMid0.s1;
    //res1.s1 += 4 * SrcMid0.s2;
    res1.s1 += SrcMid0.s0 << 2;
    res1.s1 += SrcMid0.s1 << 2 + SrcMid0.s1 << 1;
    res1.s1 += SrcMid0.s2 << 2;
    res1.s1 += SrcMid0.s3;
#endif
    //res1.s1 = SrcPre1 + SrcMid0.s0<<2 + SrcMid0.s1<<2 + SrcMid0.s1<<1 + SrcMid0.s2<< 2 + SrcMid0.s3;
    res1.s1 = mad24(SrcMid0.s0, 4, SrcPre1) + mad24(6, SrcMid0.s1, SrcMid0.s3) + mad24(SrcMid0.s2, 4, 8);

#if 0
    res1.s2 = SrcMid0.s0;
    //res1.s2 += 4 * SrcMid0.s1;
    //res1.s2 += 6 * SrcMid0.s2;
    //res1.s2 += 4 * SrcMid0.s3;
    res1.s2 += SrcMid0.s1 << 2;
    res1.s2 += SrcMid0.s2 << 2 + SrcMid0.s2<<1;;
    res1.s2 += SrcMid0.s3 << 2;
    res1.s2 += SrcMid1.s0;
#endif
  //res1.s2 = SrcMid0.s0  + SrcMid0.s1<<2 + SrcMid0.s2 <<2+SrcMid0.s2<<1 + SrcMid0.s3<<2 + SrcMid1.s0;
    res1.s2 = mad24(SrcMid0.s1, 4, SrcMid0.s0) + mad24(6, SrcMid0.s2, SrcMid1.s0) + mad24(SrcMid0.s3, 4, 8);


#if 0
    res1.s3 = SrcMid0.s1;
    //res1.s3 += 4 * SrcMid0.s2;
    //res1.s3 += 6 * SrcMid0.s3;
    //res1.s3 += 4 * SrcMid1.s0;
    res1.s3 += SrcMid0.s2 << 2;
    res1.s3 += SrcMid0.s3 << 2 + SrcMid0.s3<<1;;
    res1.s3 += SrcMid1.s0 << 2;
    res1.s3 +=  SrcMid1.s1;
#endif
    //res1.s3 = SrcMid0.s1 + SrcMid0.s2<<2 + SrcMid0.s3<<2 + SrcMid0.s3<<1 + SrcMid1.s0 + SrcMid1.s1;
    res1.s3 = mad24(SrcMid0.s2, 4, SrcMid0.s1) + mad24(6, SrcMid0.s3, SrcMid1.s1) + mad24(SrcMid1.s0, 4, 8);


    }
    if (gidx == 255 ){ 
#if 0
    int4 filter_horizonMid2 = (convert_int4) (vload4(0, filter_horizonSrcDt2 + 0 * filter_horizonSrcStep + 0 + 0 * sizeof(unsigned char)));
     int filter_horizonMid3 = ( int) (*(filter_horizonSrcDt2 + 0 * filter_horizonSrcStep + 4 + 0 * sizeof(unsigned char)));

#endif

#if 0
    int SrcBRIndex0 = SrcSrcShift + ((float)gidy) *SrcSrcStep;
    int SrcBRIndex1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1) *sizeof(unsigned char);
    int SrcBRIndex8 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 1) *sizeof(unsigned char);
    int SrcBRIndex6 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 2) *sizeof(unsigned char);
    int SrcBRIndex10 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 3) *sizeof(unsigned char);
    int SrcBRIndex7 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (1024 - 4) *sizeof(unsigned char);
    int SrcBRIndex2 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (2) *sizeof(unsigned char);
    int SrcBRIndex3 = SrcSrcShift + ((float)gidy) *SrcSrcStep + (3) *sizeof(unsigned char);
    __global unsigned char * SrcDt0 = SrcSrc + SrcBRIndex0;
    __global unsigned char * SrcDt1 = SrcSrc + SrcBRIndex1;
    __global unsigned char * SrcDt8 = SrcSrc + SrcBRIndex8;
    __global unsigned char * SrcDt6 = SrcSrc + SrcBRIndex6;
    __global unsigned char * SrcDt10 = SrcSrc + SrcBRIndex10;
    __global unsigned char * SrcDt7 = SrcSrc + SrcBRIndex7;
    __global unsigned char * SrcDt2 = SrcSrc + SrcBRIndex2;
    __global unsigned char * SrcDt3 = SrcSrc + SrcBRIndex3;
#endif

    int4 SrcMid2 = (convert_int4) (vload4(0, SrcSrcDt1 + 0 * SrcSrcStep + 0 + 0 * sizeof(unsigned char)));
    int2 SrcMid3 = (convert_int2) (vload2(0, SrcSrcDt1 + 0 * SrcSrcStep + 4 + 0 * sizeof(unsigned char)));
    int4 SrcLatTemp = (convert_int4)(*(__global uchar4*)(SrcDt6));
    //int4 SrcPreTemp = (convert_int4)(*(__global uchar4*)(SrcDt0));
     //int SrcLat0 = ( int) ((*SrcDt6) * 2 - (*SrcDt7));
     //int SrcLat1 = ( int) ((*SrcDt7) * 4 - (*SrcDt6) * 4 + (*SrcDt8) * 2 - (*SrcDt10));
    int SrcLat0 = SrcLatTemp.s0 * 2 - SrcLatTemp.s1;
    int SrcLat1 = SrcLatTemp.s1* 4  - SrcLatTemp.s0 *4 + SrcLatTemp.s2*2 - SrcLatTemp.s3;



#if 0
    res1.s0 =  SrcMid2.s0;
    //res1.s0 += 4 * SrcMid2.s1;
    //res1.s0 += 6 * SrcMid2.s2;
    //res1.s0 += 4 * SrcMid2.s3;
    res1.s0 += SrcMid2.s1 << 2;
    res1.s0 += SrcMid2.s2 << 2 + SrcMid2.s2<<1;
    res1.s0 += SrcMid2.s3 << 2;
    res1.s0 += SrcMid3.s0;
#endif
    res1.s0 = mad24(SrcMid2.s1, 4, SrcMid2.s0) + mad24(6, SrcMid2.s2, SrcMid3.s0) + mad24(SrcMid2.s3, 4, 8); 

#if 0
    res1.s1 =  SrcMid2.s1;
    //res1.s1 += 4 * SrcMid2.s2;
    //res1.s1 += 6 * SrcMid2.s3;
    //res1.s1 += 4 * SrcMid3.s0;
    res1.s1 += SrcMid2.s2 << 2;
    res1.s1 += SrcMid2.s3 <<2 + SrcMid2.s3<<1;
    res1.s1 += SrcMid3.s0 << 2;
    res1.s1 +=  SrcMid3.s1;
#endif
    res1.s1 = mad24(SrcMid2.s2, 4, SrcMid2.s1) + mad24(6, SrcMid2.s3, SrcMid3.s1) + mad24(SrcMid3.s0, 4, 8);

#if 0
    res1.s2 =  SrcMid2.s2;
    //res1.s2 += 4 * SrcMid2.s3;
    //res1.s2 += 6 * SrcMid3.s0;
    //res1.s2 += 4 * SrcMid3.s1;
    res1.s2 += SrcMid2.s3 << 2;
    res1.s2 += SrcMid3.s0 << 2 + SrcMid3.s0<<1;
    res1.s2 +=  SrcMid3.s1 << 2;
    res1.s2 += SrcLat0;
#endif
    res1.s2 = mad24(SrcMid2.s3, 4, SrcMid2.s2) + mad24(6, SrcMid3.s0, SrcLat0) + mad24(SrcMid3.s1, 4, 8);

#if 0
    res1.s3 =  SrcMid2.s3;
    // res1.s3 += 4 * SrcMid3.s0;
    // res1.s3 += 6 * SrcMid3.s1;
    // res1.s3 += 4 * SrcLat0;
    res1.s3 += SrcMid3.s0 << 2;
    res1.s3 += SrcMid3.s1 << 2 + SrcMid3.s1<<1;
    res1.s3 += SrcLat0 << 2;
    res1.s3 += SrcLat1;
#endif
    res1.s3 = mad24(SrcMid3.s0, 4, SrcMid2.s3) + mad24(6, SrcMid3.s1, SrcLat1) + mad24(SrcLat0, 4, 8);


    }
    else if (gidx >= 1 && gidx <= 254) {
#if 0
      filter_horizon[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_horizonSrcDt2 + 0 + filter_horizonSrcStep * 0)));
      filter_horizon[1] = ( int) (*((__global unsigned char*) ((__global char*) filter_horizonSrcDt2 + 1 + filter_horizonSrcStep * 0)));
      filter_horizon[2] = ( int) (*((__global unsigned char*) ((__global char*) filter_horizonSrcDt2 + 2 + filter_horizonSrcStep * 0)));
      filter_horizon[3] = ( int) (*((__global unsigned char*) ((__global char*) filter_horizonSrcDt2 + 3 + filter_horizonSrcStep * 0)));
      filter_horizon[4] = ( int) (*((__global unsigned char*) ((__global char*) filter_horizonSrcDt2 + 4 + filter_horizonSrcStep * 0)));
#endif
      Src = convert_int4(vload4(0, SrcSrcDt1 + 0 * SrcSrcStep + 4 * 0));



#if 1
#if 0
      R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0)));
      R3Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1)));
      R4Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 2)));
      R5Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 3)));
#endif

#if 0
      R2Next = ( int) ( *( SrcSrcDt1 + 4 ));
      R3Next = ( int) ( *( SrcSrcDt1 + 5 ));
      R4Next = ( int) ( *( SrcSrcDt1 + 6 ));
      R5Next = ( int) ( *( SrcSrcDt1 + 7 ));
#endif
      int4 RTemp = (convert_int4)(*((__global uchar4 *)(SrcSrcDt1+4)));
#if 0
      R2Next = RTemp.s0;
      R3Next = RTemp.s1;
      R4Next = RTemp.s2;
      R5Next = RTemp.s3;
#endif

     

      //res1.s0 =  Src.s0 + 4 * Src.s1 + 6 * Src.s2 + 4  * Src.s3;
      //res1.s0 =  Src.s0 + Src.s1<<2 +  Src.s2<<2 + Src.s2<<1 + Src.s3<<2;
      //R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0)));
      //res1.s0 +=   R2Next; 

      res1.s0 = mad24(Src.s1, 4, Src.s0) + mad24(6, Src.s2, RTemp.s0) + mad24(Src.s3, 4, 8);

      //res1.s1 =   Src.s1 + 4 * Src.s2 + 6 * Src.s3;
      //res1.s1 =   Src.s1 +  Src.s2<<2 + Src.s3<<2 + Src.s3<<1;
      //R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0)));
      //res1.s1 += 4 * R2Next; 
      //res1.s1 +=  R2Next << 2; 
      //R3Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1)));
      //res1.s1 +=  R3Next; 
      res1.s1 = mad24(Src.s2, 4, Src.s1) + mad24(6, Src.s3, RTemp.s1) + mad24(RTemp.s0, 4, 8);

      //res1.s2 =  Src.s2 + 4  * Src.s3;
      //res1.s2 =  Src.s2 +  Src.s3<<2;
      //R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0)));
      //res1.s2 +=  R2Next<<2 + R2Next<<1; 
      //R3Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1)));
      //res1.s2 += 4 * R3Next; 
      //res1.s2 +=  R3Next << 2; 
      //R4Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 2)));
      //res1.s2 += R4Next; 
      res1.s2 = mad24(Src.s3, 4, Src.s2) + mad24(RTemp.s0, 6, R4Next) + mad24(RTemp.s1, 4, 8);


      //res1.s3 =  Src.s3;
      //R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0)));
      //R2Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + 4 )));
      //res1.s3 += 4 * R2Next; 
      //res1.s3 +=  R2Next << 2; 
      //R3Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1)));
      //res1.s3 += 6 * R3Next; 
      //res1.s3 +=  R3Next << 2 + R3Next<<1; 
      //R4Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 2)));
      //res1.s3 += 4 * R4Next; 
      //res1.s3 +=  R4Next << 2; 
      //R5Next = ( int) ( *((__global unsigned char*) ((__global char*) SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 3)));
      //res1.s3 +=  R5Next; 
      res1.s3 = mad24(RTemp.s0, 4, Src.s3) + mad24(6, RTemp.s1, RTemp.s3) + mad24(RTemp.s2, 4, 8);

#endif
    }

    uchar4 temp0;
    //temp0 = convert_uchar4((res1 + 8) / 16);

    temp0 = convert_uchar4(res1 / 16);
#if 0
    *dst_horizonDstDt1 = temp0.s0;
    *(dst_horizonDstDt1 + 1) = temp0.s1;
    *(dst_horizonDstDt1 + 2) = temp0.s2;
    *(dst_horizonDstDt1 + 3) = temp0.s3;
#endif
    *((__global uchar4 *)(dst_horizonDstDt1)) = temp0;
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
  if ( gidx >= 512 || gidy >= 512 )
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
         int filter_vertical[5];
     int dst_horizon[5];
     int R2Next;
     int res1;
    if (gidy == 0 ){ 
     int filter_verticalMid0 = ( int) (*(filter_verticalSrcDt2 + 0 * filter_verticalSrcStep + 0));

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

     int dst_horizonPre0 = ( int) ((*dst_horizonDt3) * 4 - (*dst_horizonDt1) * 4 + (*dst_horizonDt0) * 2 - (*dst_horizonDt2));
    res1 = filter_verticalMid0 * dst_horizonPre0;

     int filter_verticalMid1 = ( int) (*(filter_verticalSrcDt2 + 1 * filter_verticalSrcStep + 0));
     int dst_horizonPre1 = ( int) ((*dst_horizonDt1) * 2 - (*dst_horizonDt3));
    res1 += filter_verticalMid1 * dst_horizonPre1;

     int filter_verticalMid2 = ( int) (*(filter_verticalSrcDt2 + 2 * filter_verticalSrcStep + 0));
     int dst_horizonMid0 = ( int) (*(dst_horizonSrcDt1 + 2 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid2 * dst_horizonMid0;

     int filter_verticalMid3 = ( int) (*(filter_verticalSrcDt2 + 3 * filter_verticalSrcStep + 0));
     int dst_horizonMid1 = ( int) (*(dst_horizonSrcDt1 + 3 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid3 * dst_horizonMid1;

     int filter_verticalMid4 = ( int) (*(filter_verticalSrcDt2 + 4 * filter_verticalSrcStep + 0));
     int dst_horizonMid2 = ( int) (*(dst_horizonSrcDt1 + 4 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid4 * dst_horizonMid2;

    }
    if (gidy == 511 ){ 
     int filter_verticalMid5 = ( int) (*(filter_verticalSrcDt2 + 0 * filter_verticalSrcStep + 0));

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

     int dst_horizonMid3 = ( int) (*(dst_horizonSrcDt1 + 0 * dst_horizonSrcStep + 0));
    res1 = filter_verticalMid5 * dst_horizonMid3;

     int filter_verticalMid6 = ( int) (*(filter_verticalSrcDt2 + 1 * filter_verticalSrcStep + 0));
     int dst_horizonMid4 = ( int) (*(dst_horizonSrcDt1 + 1 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid6 * dst_horizonMid4;

     int filter_verticalMid7 = ( int) (*(filter_verticalSrcDt2 + 2 * filter_verticalSrcStep + 0));
     int dst_horizonMid5 = ( int) (*(dst_horizonSrcDt1 + 2 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid7 * dst_horizonMid5;

     int filter_verticalMid8 = ( int) (*(filter_verticalSrcDt2 + 3 * filter_verticalSrcStep + 0));
     int dst_horizonMid6 = ( int) (*(dst_horizonSrcDt1 + 3 * dst_horizonSrcStep + 0));
    res1 += filter_verticalMid8 * dst_horizonMid6;

     int filter_verticalMid9 = ( int) (*(filter_verticalSrcDt2 + 4 * filter_verticalSrcStep + 0));
     int dst_horizonLat0 = ( int) ((*dst_horizonDt6) * 2 - (*dst_horizonDt7));
    res1 += filter_verticalMid9 * dst_horizonLat0;

    }
    else if (gidy >= 1 && gidy <= 510) {
      filter_vertical[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 0)));
      dst_horizon[0] = ( int) ( *((__global unsigned char*) ((__global char*) dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 0)));
      res1 = filter_vertical[0] * dst_horizon[0]; 
      filter_vertical[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 1)));
      dst_horizon[0] = ( int) ( *((__global unsigned char*) ((__global char*) dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 1)));
      res1 += filter_vertical[0] * dst_horizon[0]; 
      filter_vertical[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 2)));
      dst_horizon[0] = ( int) ( *((__global unsigned char*) ((__global char*) dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 2)));
      res1 += filter_vertical[0] * dst_horizon[0]; 
      filter_vertical[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 3)));
      dst_horizon[0] = ( int) ( *((__global unsigned char*) ((__global char*) dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 3)));
      res1 += filter_vertical[0] * dst_horizon[0]; 
      filter_vertical[0] = ( int) (*((__global unsigned char*) ((__global char*) filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 4)));
      dst_horizon[0] = ( int) ( *((__global unsigned char*) ((__global char*) dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 4)));
      res1 += filter_vertical[0] * dst_horizon[0]; 
    }
    *dst_dsDstDt1 = (res1 + 8) / 16;
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
  int SrcSrcIdx3 = SrcSrcShift + (1024 - 1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx4 = SrcSrcShift + (1024 - 1) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int SrcSrcIdx5 = SrcSrcShift + ((float)gidy * 2 + -1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx6 = SrcSrcShift + ((float)gidy * 2 + -1) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int SrcSrcIdx7 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx8 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int dst_dsSrcIdx9 = dst_dsSrcShift + ((1024 + 1) / 2 - 1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx10 = dst_dsSrcShift + ((1024 + 1) / 2 - 1) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dst_dsSrcIdx11 = dst_dsSrcShift + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx12;
  int dst_dsSrcIdx13 = dst_dsSrcShift + (1024 - 1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx14 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx15 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dst_dsSrcIdx16 = dst_dsSrcShift + ((float)gidy) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx17 = dst_dsSrcShift + ((float)gidy) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int layerDstIdx1;
  int layerDstIdx2;
  int layerDstIdx3 = layerDstShift + (1024 - 1) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  int layerDstIdx4 = layerDstShift + (1024 - 1) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int layerDstIdx5 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  int layerDstIdx6 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  int layerDstIdx7 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2) *sizeof(unsigned char);
  int layerDstIdx8 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1;
  __global unsigned char *SrcSrcDt2;
  __global unsigned char *SrcSrcDt3 = SrcSrc + SrcSrcIdx3;
  __global unsigned char *SrcSrcDt4 = SrcSrc + SrcSrcIdx4;
  __global unsigned char *SrcSrcDt5 = SrcSrc + SrcSrcIdx5;
  __global unsigned char *SrcSrcDt6 = SrcSrc + SrcSrcIdx6;
  __global unsigned char *SrcSrcDt7 = SrcSrc + SrcSrcIdx7;
  __global unsigned char *SrcSrcDt8 = SrcSrc + SrcSrcIdx8;
  __global unsigned char *dst_dsSrcDt9 = dst_dsSrc + dst_dsSrcIdx9;
  __global unsigned char *dst_dsSrcDt10 = dst_dsSrc + dst_dsSrcIdx10;
  __global unsigned char *dst_dsSrcDt11 = dst_dsSrc + dst_dsSrcIdx11;
  __global unsigned char *dst_dsSrcDt12;
  __global unsigned char *dst_dsSrcDt13 = dst_dsSrc + dst_dsSrcIdx13;
  __global unsigned char *dst_dsSrcDt14 = dst_dsSrc + dst_dsSrcIdx14;
  __global unsigned char *dst_dsSrcDt15 = dst_dsSrc + dst_dsSrcIdx15;
  __global unsigned char *dst_dsSrcDt16 = dst_dsSrc + dst_dsSrcIdx16;
  __global unsigned char *dst_dsSrcDt17 = dst_dsSrc + dst_dsSrcIdx17;
  __global unsigned char *layerDstDt1;
  __global unsigned char *layerDstDt2;
  __global unsigned char *layerDstDt3 = layerDst + layerDstIdx3;
  __global unsigned char *layerDstDt4 = layerDst + layerDstIdx4;
  __global unsigned char *layerDstDt5 = layerDst + layerDstIdx5;
  __global unsigned char *layerDstDt6 = layerDst + layerDstIdx6;
  __global unsigned char *layerDstDt7 = layerDst + layerDstIdx7;
  __global unsigned char *layerDstDt8 = layerDst + layerDstIdx8;

  /* kernel operation */
  {
    if (gidy == 0) {
      SrcSrcIdx1 = SrcSrcShift + ((float)gidx * 2) *sizeof(unsigned char);
      SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
      layerDstIdx1 = layerDstShift + ((float)gidx * 2) *sizeof(unsigned char);
      layerDstDt1 = layerDst + layerDstIdx1;
      int Op_ans1 = ( *((__global unsigned char*) SrcSrcDt1)) - (*(((__global unsigned char*) dst_dsSrcDt11)));
      *layerDstDt1 = (__global uchar)Op_ans1;
      SrcSrcIdx2 = SrcSrcShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
      SrcSrcDt2 = SrcSrc + SrcSrcIdx2;
      dst_dsSrcIdx12 = dst_dsSrcShift + ((float)gidx + 1) *sizeof(unsigned char);
      dst_dsSrcDt12 = dst_dsSrc + dst_dsSrcIdx12;
      layerDstIdx2 = layerDstShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
      layerDstDt2 = layerDst + layerDstIdx2;
      int Op_ans2 = ( *((__global unsigned char*) dst_dsSrcDt11)) + (*(((__global unsigned char*) dst_dsSrcDt12)));
      if (gidx != (1024 + 1) / 2 - 1)
        *layerDstDt2 = *(SrcSrcDt2) - (Op_ans2 + 1) / 2;
      SrcSrcIdx2 = SrcSrcShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
      SrcSrcDt2 = SrcSrc + SrcSrcIdx2;
      layerDstIdx2 = layerDstShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
      layerDstDt2 = layerDst + layerDstIdx2;
      int Op_ans3 = ( *((__global unsigned char*) SrcSrcDt2)) - (*(((__global unsigned char*) dst_dsSrcDt11)));
      if (gidx == (1024 + 1) / 2 - 1 && widthOdd == 0)
        *layerDstDt2 = (__global uchar)Op_ans3;
    }
    if (heightOdd == 0 && gidy == (1024 + 1) / 2 - 1) {
      int Op_ans4 = ( *((__global unsigned char*) SrcSrcDt3)) - (*(((__global unsigned char*) dst_dsSrcDt9)));
      *layerDstDt3 = (__global uchar)Op_ans4;
      int Op_ans5 = ( *((__global unsigned char*) dst_dsSrcDt9)) + (*(((__global unsigned char*) dst_dsSrcDt10)));
      if (gidx != (1024 + 1) / 2 - 1)
        *layerDstDt4 = *(SrcSrcDt4) - (Op_ans5 + 1) / 2;
      int Op_ans6 = ( *((__global unsigned char*) SrcSrcDt4)) - (*(((__global unsigned char*) dst_dsSrcDt13)));
      if (gidx == (1024 + 1) / 2 - 1 && widthOdd == 0)
        *layerDstDt4 = (__global uchar)Op_ans6;
    }
    if (gidy != 0) {
      int Op_ans7 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt16)));
      *layerDstDt5 = *(SrcSrcDt5) - (Op_ans7 + 1) / 2;
      int Op_ans8 = ( *((__global unsigned char*) SrcSrcDt7)) - (*(((__global unsigned char*) dst_dsSrcDt16)));
      *layerDstDt7 = (__global uchar)Op_ans8;
      if (gidx != (1024 + 1) / 2 - 1) {
        int Op_ans9 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt15)));
        *layerDstDt6 = *(SrcSrcDt6) - (Op_ans9 + *(dst_dsSrcDt16) + *(dst_dsSrcDt17) + 2) / 4;
        int Op_ans10 = ( *((__global unsigned char*) dst_dsSrcDt16)) + (*(((__global unsigned char*) dst_dsSrcDt17)));
        *layerDstDt8 = *(SrcSrcDt8) - (Op_ans10 + 1) / 2;
      }
      if (widthOdd == 0 && gidx == (1024 + 1) / 2 - 1) {
        int Op_ans11 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt16)));
        *layerDstDt6 = *(SrcSrcDt5) - (Op_ans11 + 1) / 2;
        int Op_ans12 = ( *((__global unsigned char*) SrcSrcDt7)) - (*(((__global unsigned char*) dst_dsSrcDt16)));
        *layerDstDt8 = (__global uchar)Op_ans12;
      }
    }
  }

}

