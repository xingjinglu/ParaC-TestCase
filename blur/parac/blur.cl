/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global short* const inSrc,
  int inSrcWidth,
  int inSrcHeight,
  int inSrcStep,
  int inSrcShift,
  __global short* const filter_vSrc,
  int filter_vSrcWidth,
  int filter_vSrcHeight,
  int filter_vSrcStep,
  int filter_vSrcShift,
  __global short *intermediateDst,
  int intermediateDstWidth,
  int intermediateDstHeight,
  int intermediateDstStep,
  int intermediateDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 4800 || gidy >= 6406 )
    return;

  /* kernel index calculation */
  int inSrcIdx2 = inSrcShift + ((float)gidy + -1 + 1) *inSrcStep + ((float)gidx + 1) *sizeof(short);
  int intermediateDstIdx1 = intermediateDstShift + ((float)gidy + 1) *intermediateDstStep + ((float)gidx + 1) *sizeof(short);

  /* kernel operands */
  __global short *filter_vSrcDt1 = (__global char *)filter_vSrc + filter_vSrcShift;
  __global short *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global short *intermediateDstDt1 = (__global char *)intermediateDst + intermediateDstIdx1;

  /* kernel operation */
  {
         int filter_v[3];
     int in[3];
     int R2Next;
     int res1;
    {
      filter_v[0] = ( int) (*((__global short*) ((__global char*) filter_vSrcDt1 + 0 * sizeof(short) + filter_vSrcStep * 0)));
      in[0] = ( int) ( *((__global short*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 0)));
      res1 = filter_v[0] * in[0]; 
      filter_v[0] = ( int) (*((__global short*) ((__global char*) filter_vSrcDt1 + 0 * sizeof(short) + filter_vSrcStep * 1)));
      in[0] = ( int) ( *((__global short*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 1)));
      res1 += filter_v[0] * in[0]; 
      filter_v[0] = ( int) (*((__global short*) ((__global char*) filter_vSrcDt1 + 0 * sizeof(short) + filter_vSrcStep * 2)));
      in[0] = ( int) ( *((__global short*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 2)));
      res1 += filter_v[0] * in[0]; 
    }
    *intermediateDstDt1 = res1 / 3;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global short* const intermediateSrc,
  int intermediateSrcWidth,
  int intermediateSrcHeight,
  int intermediateSrcStep,
  int intermediateSrcShift,
  __global short* const filter_hSrc,
  int filter_hSrcWidth,
  int filter_hSrcHeight,
  int filter_hSrcStep,
  int filter_hSrcShift,
  __global short *outDst,
  int outDstWidth,
  int outDstHeight,
  int outDstStep,
  int outDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= (4800/4) || gidy >= 6406 )
    return;

  /* kernel index calculation */
  int intermediateSrcIdx2 = intermediateSrcShift + ((float)gidy + 1) *intermediateSrcStep + ((float)gidx *4 + -1 + 1) *sizeof(short);
  int outDstIdx1 = outDstShift + ((float)gidy + 1) *outDstStep + ((float)gidx *4 + 1) *sizeof(short);

  /* kernel operands */
  __global short *filter_hSrcDt1 = (__global char *)filter_hSrc + filter_hSrcShift;
  __global short *intermediateSrcDt2 = (__global char *)intermediateSrc + intermediateSrcIdx2;
  __global short *outDstDt1 = (__global char *)outDst + outDstIdx1;

  /* kernel operation */
  {
         int filter_h[3];
    int4 intermediate;
     int R2Next;
    int4 res1;
    {
      filter_h[0] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 0 * sizeof(short) + filter_hSrcStep * 0)));
      filter_h[1] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 1 * sizeof(short) + filter_hSrcStep * 0)));
      filter_h[2] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 2 * sizeof(short) + filter_hSrcStep * 0)));
      intermediate = vload4(0,  (__global char*)(intermediateSrcDt2) + 0 * intermediateSrcStep + 4 * 0 * sizeof(short));
      res1.s0 = filter_h[0] * intermediate.s0 + filter_h[1] * intermediate.s1 + filter_h[2] * intermediate.s2;
      res1.s1 = filter_h[0] * intermediate.s1 + filter_h[1] * intermediate.s2 + filter_h[2] * intermediate.s3;
      res1.s2 = filter_h[0] * intermediate.s2 + filter_h[1] * intermediate.s3;
      R2Next = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 0 * sizeof(short))));
      res1.s2 += filter_h[2]; R2Next; 
      res1.s3 = filter_h[0] * intermediate.s3;
      R2Next = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 0 * sizeof(short))));
      res1.s3 += filter_h[1]; R2Next; 
      R2Next = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 1 * sizeof(short))));
      res1.s3 += filter_h[2]; R2Next; 
    }
    short4 temp0;
    temp0 = convert_short4(res1 / 3);
    *outDstDt1 = temp0.s0;
    *(outDstDt1 + 1) = temp0.s1;
    *(outDstDt1 + 2) = temp0.s2;
    *(outDstDt1 + 3) = temp0.s3;
  }

}

