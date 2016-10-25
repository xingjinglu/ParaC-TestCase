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
  if ( gidx >= 600 || gidy >= 6406 )
    return;

  /* kernel index calculation */
  int inSrcIdx2 = inSrcShift + (int)(((float)gidy + -1 + 1) *inSrcStep) + (int)(((float)gidx * 8 + 1) *sizeof(short));
  int intermediateDstIdx1 = intermediateDstShift + (int)(((float)gidy + 1) *intermediateDstStep) + (int)(((float)gidx + 1) *sizeof(short));

  /* kernel operands */
  __global short *filter_vSrcDt1 = (__global char *)filter_vSrc + filter_vSrcShift;
  __global short *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global short *intermediateDstDt1 = (__global char *)intermediateDst + intermediateDstIdx1;

  /* kernel operation */
  {
    int filter_v[3];
    int8 in0, in1, in2;
    int8 res1;
    {
      // opt1: horizontal tiling(1,8)
      in0 = ( convert_int8 ) ( *((__global int8*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 0)));
      in1 = ( convert_int8) ( *((__global int8*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 1)));
      in2 = ( convert_int8) ( *((__global int8*) ((__global char*) inSrcDt2 + 0 * sizeof(short) + inSrcStep * 2)));
      res1 =  in0; 
      res1 += in1; 
      res1 += in2; 
    }
    *((__global int8*)(intermediateDstDt1)) = convert_int8(res1 / 3);
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
  int intermediateSrcIdx2 = intermediateSrcShift + (int)(((float)gidy + 1) *intermediateSrcStep) + (int)(((float)gidx *4 + -1 + 1) *sizeof(short));
  int outDstIdx1 = outDstShift + (int)(((float)gidy + 1) *outDstStep) + (int)(((float)gidx *4 + 1) *sizeof(short));

  /* kernel operands */
  __global short *filter_hSrcDt1 = (__global char *)filter_hSrc + filter_hSrcShift;
  __global short *intermediateSrcDt2 = (__global char *)intermediateSrc + intermediateSrcIdx2;
  __global short *outDstDt1 = (__global char *)outDst + outDstIdx1;

  /* kernel operation */
  {
        int filter_h[3];
    int4 intermediate;
    int intermediateNext;
    int4 res1;
    {
    filter_h[0] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 0 * sizeof(short) + filter_hSrcStep * 0)));
    filter_h[1] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 1 * sizeof(short) + filter_hSrcStep * 0)));
    filter_h[2] = ( int) (*((__global short*) ((__global char*) filter_hSrcDt1 + 2 * sizeof(short) + filter_hSrcStep * 0)));
    intermediate = convert_int4(vload4(0, (__global short*) ( (__global char*)(intermediateSrcDt2) + 0 * intermediateSrcStep + 4 * 0 * sizeof(short))));
    res1.s0 = filter_h[0] * intermediate.s0 + filter_h[1] * intermediate.s1 + filter_h[2] * intermediate.s2;
    res1.s1 = filter_h[0] * intermediate.s1 + filter_h[1] * intermediate.s2 + filter_h[2] * intermediate.s3;
    res1.s2 = filter_h[0] * intermediate.s2 + filter_h[1] * intermediate.s3;
    intermediateNext = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 0 * sizeof(short))));
    res1.s2 += filter_h[2] * intermediateNext; 
    res1.s3 = filter_h[0] * intermediate.s3;
    intermediateNext = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 0 * sizeof(short))));
    res1.s3 += filter_h[1] * intermediateNext; 
    intermediateNext = ( int) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 1 * sizeof(short))));
    res1.s3 += filter_h[2] * intermediateNext; 
  }
    short4 temp0;
    temp0 = convert_short4(res1 / 3);
    *outDstDt1 = temp0.s0;
    *(outDstDt1 + 1) = temp0.s1;
    *(outDstDt1 + 2) = temp0.s2;
    *(outDstDt1 + 3) = temp0.s3;
  }

}

