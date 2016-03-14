/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

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
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx   >=  (512/4) || gidy >= 512)
   return;

  /* kernel index calculation */
  int SrcSrcIdx1 = SrcSrcShift + ((float)gidy) *SrcSrcStep + ((float)gidx *4 + -2) *sizeof(unsigned char);
  int dst_horizonDstIdx1 = dst_horizonDstShift + ((float)gidy) *dst_horizonDstStep + ((float)gidx *4) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  __global unsigned char *filter_horizonSrcDt2 = filter_horizonSrc + filter_horizonSrcShift;
  __global unsigned char *dst_horizonDstDt1 = dst_horizonDst + dst_horizonDstIdx1;

  /* kernel operation */
  {
         int filter_horizon[5];
    int4 Src;
     int R2Next;
    int4 res1;
        int SrcIndex_Pre00 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (0) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre0 = SrcSrc + SrcIndex_Pre00;
    int SrcIndex_Pre01 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (1) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre1 = SrcSrc + SrcIndex_Pre01;
    int SrcIndex_Pre02 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (2) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre2 = SrcSrc + SrcIndex_Pre02;
    int SrcIndex_Pre03 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (3) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre3 = SrcSrc + SrcIndex_Pre03;
     int pre00 = *SrcRepDt_Pre3 * 4 - *SrcRepDt_Pre1 * 4 + *SrcRepDt_Pre0 * 2 - *SrcRepDt_Pre2;
     int pre01 = *SrcRepDt_Pre1 * 2 - *SrcRepDt_Pre3;
            int SrcIndex_Lat02 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (512 - 1) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat2 = SrcSrc + SrcIndex_Lat02;
    int SrcIndex_Lat00 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (512 - 2) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat0 = SrcSrc + SrcIndex_Lat00;
    int SrcIndex_Lat03 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (512 - 3) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat3 = SrcSrc + SrcIndex_Lat03;
    int SrcIndex_Lat01 = SrcSrcShift + ((float)gidy) * SrcSrcStep + (512 - 4) * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat1 = SrcSrc + SrcIndex_Lat01;
     int lat10 = *SrcRepDt_Lat0 * 2 - *SrcRepDt_Lat1;
     int lat11 = *SrcRepDt_Lat1 * 4 - *SrcRepDt_Lat0 * 4 + *SrcRepDt_Lat2 * 2 - *SrcRepDt_Lat3;
        if (gidx == 0) {
    filter_horizon[0] = *(filter_horizonSrcShift + filter_horizonSrc + 0 + filter_horizonSrcStep * 0);
    filter_horizon[1] = *(filter_horizonSrcShift + filter_horizonSrc + 1 + filter_horizonSrcStep * 0);
    filter_horizon[2] = *(filter_horizonSrcShift + filter_horizonSrc + 2 + filter_horizonSrcStep * 0);
    filter_horizon[3] = *(filter_horizonSrcShift + filter_horizonSrc + 3 + filter_horizonSrcStep * 0);
    filter_horizon[4] = *(filter_horizonSrcShift + filter_horizonSrc + 4 + filter_horizonSrcStep * 0);
    Src = (convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 2 + SrcSrcStep * 0));
    res1.s0 = pre00 * filter_horizon[0];
    res1.s0 += pre01 * filter_horizon[1];
    res1.s0 += Src.s0 * filter_horizon[2] + Src.s1 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 4 + SrcSrcStep * 0);
    res1.s0 += filter_horizon[4] * R2Next; 
    res1.s1 = pre01 * filter_horizon[0];
    res1.s1 += Src.s0 * filter_horizon[1] + Src.s1 * filter_horizon[2] + Src.s2 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 5 + SrcSrcStep * 0);
    res1.s1 += filter_horizon[4] * R2Next; 
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 2 + SrcSrcStep * 0));
    res1.s2 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2] + Src.s3 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 6 + SrcSrcStep * 0);
    res1.s2 += filter_horizon[4] * R2Next; 
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 3 + SrcSrcStep * 0));
    res1.s3 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2] + Src.s3 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 7 + SrcSrcStep * 0);
    res1.s3 += filter_horizon[4] * R2Next; 
  }
  else if (gidx == 127) {
    filter_horizon[0] = *(filter_horizonSrcShift + filter_horizonSrc + 0 + filter_horizonSrcStep * 0);
    filter_horizon[1] = *(filter_horizonSrcShift + filter_horizonSrc + 1 + filter_horizonSrcStep * 0);
    filter_horizon[2] = *(filter_horizonSrcShift + filter_horizonSrc + 2 + filter_horizonSrcStep * 0);
    filter_horizon[3] = *(filter_horizonSrcShift + filter_horizonSrc + 3 + filter_horizonSrcStep * 0);
    filter_horizon[4] = *(filter_horizonSrcShift + filter_horizonSrc + 4 + filter_horizonSrcStep * 0);
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 0 + SrcSrcStep * 0));
    res1.s0 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2] + Src.s3 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 4 + SrcSrcStep * 0);
    res1.s0 += filter_horizon[4] * R2Next;
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 1 + SrcSrcStep * 0));
    res1.s1 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2] + Src.s3 * filter_horizon[3];
    R2Next = *(SrcSrcDt1 + 4 * 0 + 5 + SrcSrcStep * 0);
    res1.s1 += filter_horizon[4] * R2Next;
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 2 + SrcSrcStep * 0));
    res1.s2 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2] + Src.s3 * filter_horizon[3];
    res1.s2 += lat10 * filter_horizon[4];
    Src =(convert_int4) (vload4(0, SrcSrcDt1 + 4 * 0 + 3 + SrcSrcStep * 0));
    res1.s3 = Src.s0 * filter_horizon[0] + Src.s1 * filter_horizon[1] + Src.s2 * filter_horizon[2];
    res1.s3 += lat10 * filter_horizon[3];
    res1.s3 += lat11 * filter_horizon[4];
  }
  else if (gidx != 0 && gidx != 127) {
    filter_horizon[0] = *(filter_horizonSrcDt2 + 0 + filter_horizonSrcStep * 0);
    filter_horizon[1] = *(filter_horizonSrcDt2 + 1 + filter_horizonSrcStep * 0);
    filter_horizon[2] = *(filter_horizonSrcDt2 + 2 + filter_horizonSrcStep * 0);
    filter_horizon[3] = *(filter_horizonSrcDt2 + 3 + filter_horizonSrcStep * 0);
    filter_horizon[4] = *(filter_horizonSrcDt2 + 4 + filter_horizonSrcStep * 0);
    Src = (convert_int4) (vload4(0, SrcSrcDt1 + 0 * SrcSrcStep + 4 * 0));
    res1.s0 = filter_horizon[0] * Src.s0 + filter_horizon[1] * Src.s1 + filter_horizon[2] * Src.s2 + filter_horizon[3] * Src.s3;
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0);
    res1.s0 += filter_horizon[4] * R2Next; 
    res1.s1 = filter_horizon[0] * Src.s1 + filter_horizon[1] * Src.s2 + filter_horizon[2] * Src.s3;
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0);
    res1.s1 += filter_horizon[3] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1);
    res1.s1 += filter_horizon[4] * R2Next; 
    res1.s2 = filter_horizon[0] * Src.s2 + filter_horizon[1] * Src.s3;
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0);
    res1.s2 += filter_horizon[2] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1);
    res1.s2 += filter_horizon[3] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 2);
    res1.s2 += filter_horizon[4] * R2Next; 
    res1.s3 = filter_horizon[0] * Src.s3;
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 0);
    res1.s3 += filter_horizon[1] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 1);
    res1.s3 += filter_horizon[2] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 2);
    res1.s3 += filter_horizon[3] * R2Next; 
    R2Next = *(SrcSrcDt1 + SrcSrcStep * 0 + 4 * 1 + 3);
    res1.s3 += filter_horizon[4] * R2Next; 
  }
    uchar4 temp0;
    temp0 = convert_uchar4((res1 + 8) / 16);
    *dst_horizonDstDt1 = temp0.s0;
    *(dst_horizonDstDt1 + 1) = temp0.s1;
    *(dst_horizonDstDt1 + 2) = temp0.s2;
    *(dst_horizonDstDt1 + 3) = temp0.s3;
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
  if (gidx >= 256 || gidy >= 256)
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

    int SrcIndex_Pre00 = dst_horizonSrcShift + ((float)(0)) * dst_horizonSrcStep + gidx *2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre0 = dst_horizonSrc + SrcIndex_Pre00;

    int SrcIndex_Pre01 = dst_horizonSrcShift + ((float)(1)) * dst_horizonSrcStep + gidx *2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre1 = dst_horizonSrc + SrcIndex_Pre01;

    int SrcIndex_Pre02 = dst_horizonSrcShift + ((float)(2)) * dst_horizonSrcStep + gidx*2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre2 = dst_horizonSrc + SrcIndex_Pre02;

    int SrcIndex_Pre03 = dst_horizonSrcShift + ((float)(3)) * dst_horizonSrcStep + gidx *2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Pre3 = dst_horizonSrc + SrcIndex_Pre03;

     int pre00 = *SrcRepDt_Pre3 * 4 - *SrcRepDt_Pre1 * 4 + *SrcRepDt_Pre0 * 2 - *SrcRepDt_Pre2;
     int pre01 = *SrcRepDt_Pre1 * 2 - *SrcRepDt_Pre3;

     int SrcIndex_Lat02 = dst_horizonSrcShift + ((float)(512 - 1)) * dst_horizonSrcStep + gidx * 2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat2 = dst_horizonSrc + SrcIndex_Lat02;

    int SrcIndex_Lat00 = dst_horizonSrcShift + ((float)(512 - 2)) * dst_horizonSrcStep + gidx * 2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat0 = dst_horizonSrc + SrcIndex_Lat00;

    int SrcIndex_Lat03 = dst_horizonSrcShift + ((float)(512 - 3)) * dst_horizonSrcStep + gidx * 2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat3 = dst_horizonSrc + SrcIndex_Lat03;

    int SrcIndex_Lat01 = dst_horizonSrcShift + ((float)(512 - 4)) * dst_horizonSrcStep + gidx * 2 * sizeof(unsigned char);
    __global unsigned char *SrcRepDt_Lat1 = dst_horizonSrc + SrcIndex_Lat01;

     int lat10 = *SrcRepDt_Lat0 * 2 - *SrcRepDt_Lat1;
     int lat11 = *SrcRepDt_Lat1 * 4 - *SrcRepDt_Lat0 * 4 + *SrcRepDt_Lat2 * 2 - *SrcRepDt_Lat3;

     if (gidy == 0) {
      dst_horizon[0] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 0);
      dst_horizon[1] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 1);
      dst_horizon[2] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 2);
      dst_horizon[3] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 3);
      dst_horizon[4] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 4);

      filter_vertical[0] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 0);
      filter_vertical[1] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 1);
      filter_vertical[2] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 2);
      filter_vertical[3] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 3);
      filter_vertical[4] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 4);

      res1 = filter_vertical[0] * pre00; 
      res1 += filter_vertical[1] * pre01; 
      res1 += filter_vertical[2] * dst_horizon[2]; 
      res1 += filter_vertical[3] * dst_horizon[3]; 
      res1 += filter_vertical[4] * dst_horizon[4]; 

    }
    if (gidy == 1) {
      dst_horizon[0] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 0);
      dst_horizon[1] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 1);
      dst_horizon[2] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 2);
      dst_horizon[3] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 3);
      dst_horizon[4] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 4);


      filter_vertical[0] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 0);
      filter_vertical[1] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 1);
      filter_vertical[2] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 2);
      filter_vertical[3] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 3);
      filter_vertical[4] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 4);

      res1 =  filter_vertical[0] * dst_horizon[0]; 
      res1 += filter_vertical[1] * dst_horizon[1]; 
      res1 += filter_vertical[2] * dst_horizon[2]; 
      res1 += filter_vertical[3] * dst_horizon[3]; 
      res1 += filter_vertical[4] * dst_horizon[4]; 
    }
    if (gidy == 255) {
      dst_horizon[0] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 0);
      dst_horizon[1] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 1);
      dst_horizon[2] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 2);
      dst_horizon[3] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 3);
      dst_horizon[4] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 4);

      filter_vertical[0] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 0);
      filter_vertical[1] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 1);
      filter_vertical[2] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 2);
      filter_vertical[3] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 3);
      filter_vertical[4] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 4);

      res1 = filter_vertical[0] * dst_horizon[0]; 
      res1 += filter_vertical[1] * dst_horizon[1]; 
      res1 += filter_vertical[2] * dst_horizon[2]; 

      res1 += filter_vertical[3] * dst_horizon[3]; 
      res1 += filter_vertical[4] * lat10;; 

    }
    if (gidy == 254) {
      dst_horizon[0] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 0);
      dst_horizon[1] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 1);
      dst_horizon[2] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 2);
      dst_horizon[3] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 3);
      dst_horizon[4] = *(dst_horizonSrcDt1 + 0 + dst_horizonSrcStep * 4);

      filter_vertical[0] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 0);
      filter_vertical[1] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 1);
      filter_vertical[2] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 2);
      filter_vertical[3] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 3);
      filter_vertical[4] = *(filter_verticalSrcDt2 + 0 + filter_verticalSrcStep * 4);

      res1 = filter_vertical[0] * dst_horizon[0]; 
      res1 += filter_vertical[1] * dst_horizon[1]; 
      res1 += filter_vertical[2] * dst_horizon[2]; 
      res1 += filter_vertical[3] * dst_horizon[3]; 
      res1 += filter_vertical[4] * dst_horizon[4]; 
    }
    else if (gidy != 0 && gidy != 1 && gidy != 255 && gidy != 254) {
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
  __global unsigned short *layerDst,
  int layerDstWidth,
  int layerDstHeight,
  int layerDstStep,
  int layerDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if (gidx >= 256 || gidy >= 256)
   return;

  /* kernel index calculation */
  int SrcSrcIdx1 = SrcSrcShift + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx2 = SrcSrcShift + ((float)gidx * 2 + 1) *sizeof(unsigned char);
  
  int SrcSrcIdx3 = SrcSrcShift + (512 - 1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx4 = SrcSrcShift + (512 - 1) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);

  int SrcSrcIdx5 = SrcSrcShift + ((float)gidy * 2 + -1) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx6 = SrcSrcShift + ((float)gidy * 2 + -1) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);

  int SrcSrcIdx7 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2) *sizeof(unsigned char);
  int SrcSrcIdx8 = SrcSrcShift + ((float)gidy * 2) *SrcSrcStep + ((float)gidx * 2 + 1) *sizeof(unsigned char);

  int dst_dsSrcIdx9 = dst_dsSrcShift + ((512 + 1) / 2 - 1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx10 = dst_dsSrcShift + ((512 + 1) / 2 - 1) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);

  int dst_dsSrcIdx11 = dst_dsSrcShift + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx12 = dst_dsSrcShift + ((float)gidx + 1) *sizeof(unsigned char);

  int dst_dsSrcIdx13 = dst_dsSrcShift + (256 - 1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);

  int dst_dsSrcIdx14 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx15 = dst_dsSrcShift + ((float)gidy + -1) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);
  int dst_dsSrcIdx16 = dst_dsSrcShift + ((float)gidy) *dst_dsSrcStep + ((float)gidx) *sizeof(unsigned char);
  int dst_dsSrcIdx17 = dst_dsSrcShift + ((float)gidy) *dst_dsSrcStep + ((float)gidx + 1) *sizeof(unsigned char);

  int layerDstIdx1 = layerDstShift + ((float)gidx * 2) *sizeof(short);
  int layerDstIdx2 = layerDstShift + ((float)gidx * 2 + 1) *sizeof(short);

  int layerDstIdx3 = layerDstShift + (512 - 1) *layerDstStep + ((float)gidx * 2) *sizeof(short);
  int layerDstIdx4 = layerDstShift + (512 - 1) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(short);

  int layerDstIdx5 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2) *sizeof(short);
  int layerDstIdx6 = layerDstShift + ((float)gidy * 2 + -1) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(short);

  int layerDstIdx7 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2) *sizeof(short);
  int layerDstIdx8 = layerDstShift + ((float)gidy * 2) *layerDstStep + ((float)gidx * 2 + 1) *sizeof(short);

  /* kernel operands */
  __global unsigned char *SrcSrcDt1 = SrcSrc + SrcSrcIdx1;
  __global unsigned char *SrcSrcDt2 = SrcSrc + SrcSrcIdx2;
  __global unsigned char *SrcSrcDt3 = SrcSrc + SrcSrcIdx3;
  __global unsigned char *SrcSrcDt4 = SrcSrc + SrcSrcIdx4;
  __global unsigned char *SrcSrcDt5 = SrcSrc + SrcSrcIdx5;
  __global unsigned char *SrcSrcDt6 = SrcSrc + SrcSrcIdx6;
  __global unsigned char *SrcSrcDt7 = SrcSrc + SrcSrcIdx7;
  __global unsigned char *SrcSrcDt8 = SrcSrc + SrcSrcIdx8;
  __global unsigned char *dst_dsSrcDt9 = dst_dsSrc + dst_dsSrcIdx9;
  __global unsigned char *dst_dsSrcDt10 = dst_dsSrc + dst_dsSrcIdx10;
  __global unsigned char *dst_dsSrcDt11 = dst_dsSrc + dst_dsSrcIdx11;
  __global unsigned char *dst_dsSrcDt12 = dst_dsSrc + dst_dsSrcIdx12;
  __global unsigned char *dst_dsSrcDt13 = dst_dsSrc + dst_dsSrcIdx13;
  __global unsigned char *dst_dsSrcDt14 = dst_dsSrc + dst_dsSrcIdx14;
  __global unsigned char *dst_dsSrcDt15 = dst_dsSrc + dst_dsSrcIdx15;
  __global unsigned char *dst_dsSrcDt16 = dst_dsSrc + dst_dsSrcIdx16;
  __global unsigned char *dst_dsSrcDt17 = dst_dsSrc + dst_dsSrcIdx17;
  __global short *layerDstDt1 = (__global char *)layerDst + layerDstIdx1;
  __global short *layerDstDt2 = (__global char *)layerDst + layerDstIdx2;
  __global short *layerDstDt3 = (__global char *)layerDst + layerDstIdx3;
  __global short *layerDstDt4 = (__global char *)layerDst + layerDstIdx4;
  __global short *layerDstDt5 = (__global char *)layerDst + layerDstIdx5;
  __global short *layerDstDt6 = (__global char *)layerDst + layerDstIdx6;
  __global short *layerDstDt7 = (__global char *)layerDst + layerDstIdx7;
  __global short *layerDstDt8 = (__global char *)layerDst + layerDstIdx8;

  /* kernel operation */
  {
    if (gidy == 0) {
      int Op_ans1 = ( *((__global unsigned char*) SrcSrcDt1)) - (*(((__global unsigned char*) dst_dsSrcDt11)));
      *layerDstDt1 = (short)Op_ans1;
      int Op_ans2 = ( *((__global unsigned char*) dst_dsSrcDt11)) + (*(((__global unsigned char*) dst_dsSrcDt12)));
      if (gidx != (512 + 1) / 2 - 1)
        *layerDstDt2 = *(SrcSrcDt2) - (Op_ans2 + 1) / 2;
      int Op_ans3 = ( *((__global unsigned char*) SrcSrcDt2)) - (*(((__global unsigned char*) dst_dsSrcDt11)));
      if (gidx == (512 + 1) / 2 - 1 && widthOdd == 0)
        *layerDstDt2 = (short)Op_ans3;
    }
    if (heightOdd == 0 && gidy == (512 + 1) / 2 - 1) {
      int Op_ans4 = ( *((__global unsigned char*) SrcSrcDt3)) - (*(((__global unsigned char*) dst_dsSrcDt9)));
      *layerDstDt3 = (short)Op_ans4;
      int Op_ans5 = ( *((__global unsigned char*) dst_dsSrcDt9)) + (*(((__global unsigned char*) dst_dsSrcDt10)));
      if (gidx != (512 + 1) / 2 - 1)
        *layerDstDt4 = *(SrcSrcDt4) - (Op_ans5 + 1) / 2;
      int Op_ans6 = ( *((__global unsigned char*) SrcSrcDt4)) - (*(((__global unsigned char*) dst_dsSrcDt13)));
      if (gidx == (512 + 1) / 2 - 1 && widthOdd == 0)
        *layerDstDt4 = (short)Op_ans6;
    }
    if (gidy != 0) {
      int Op_ans7 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt16)));
      *layerDstDt5 = *(SrcSrcDt5) - (Op_ans7 + 1) / 2;
      int Op_ans8 = ( *((__global unsigned char*) SrcSrcDt7)) - (*(((__global unsigned char*) dst_dsSrcDt16)));
      *layerDstDt7 = (short)Op_ans8;
      if (gidx != (512 + 1) / 2 - 1) {
        int Op_ans9 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt15)));
        *layerDstDt6 = *(SrcSrcDt6) - (Op_ans9 + *(dst_dsSrcDt16) + *(dst_dsSrcDt17) + 2) / 4;
        int Op_ans10 = ( *((__global unsigned char*) dst_dsSrcDt16)) + (*(((__global unsigned char*) dst_dsSrcDt17)));
        *layerDstDt8 = *(SrcSrcDt8) - (Op_ans10 + 1) / 2;
      }
      if (widthOdd == 0 && gidx == (512 + 1) / 2 - 1) {
        int Op_ans11 = ( *((__global unsigned char*) dst_dsSrcDt14)) + (*(((__global unsigned char*) dst_dsSrcDt16)));

        *layerDstDt6 = *(SrcSrcDt6) - (Op_ans11 + 1) / 2;
        int Op_ans12 = ( *((__global unsigned char*) SrcSrcDt8)) - (*(((__global unsigned char*) dst_dsSrcDt16)));
        *layerDstDt8 = (short)Op_ans12;
      }
    }
  }

}

