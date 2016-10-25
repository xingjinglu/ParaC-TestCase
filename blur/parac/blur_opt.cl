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
  int intermediateDstIdx1 = intermediateDstShift + (int)(((float)gidy + 1) *intermediateDstStep) + (int)(((float)gidx*8 + 1) *sizeof(short));

  /* kernel operands */
  //__global short *filter_vSrcDt1 = (__global char *)filter_vSrc + filter_vSrcShift;
  __global short *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global short *intermediateDstDt1 = (__global char *)intermediateDst + intermediateDstIdx1;

  /* kernel operation */
  {
    short8 in0, in1, in2;
    short8 res1;
    {
      // opt1: horizontal tiling(1,8)
      in0 = ( convert_short8 ) ( *((__global short8*) ((__global char*) inSrcDt2 )));
      in1 = ( convert_short8) ( *((__global short8*) ((__global char*) inSrcDt2  + inSrcStep * 1)));
      in2 = ( convert_short8) ( *((__global short8*) ((__global char*) inSrcDt2 + inSrcStep * 2)));
      res1 =  in0 + in1 + in2; 
    }
    *((__global short8*)(intermediateDstDt1)) = res1 / 3;
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
  if ( gidx >= 600 || gidy >= 6406 )
    return;

  /* kernel index calculation */
  int intermediateSrcIdx2 = intermediateSrcShift + (int)(((float)gidy + 1) *intermediateSrcStep) + (int)(((float)gidx *8 + -1 + 1) *sizeof(short));
  int outDstIdx1 = outDstShift + (int)(((float)gidy + 1) *outDstStep) + (int)(((float)gidx *8 + 1) *sizeof(short));

  /* kernel operands */
  //__global short *filter_hSrcDt1 = (__global char *)filter_hSrc + filter_hSrcShift;
  __global short *intermediateSrcDt2 = (__global char *)intermediateSrc + intermediateSrcIdx2;
  __global short *outDstDt1 = (__global char *)outDst + outDstIdx1;

  /* kernel operation */

#if 0 // tile(4)
  {
    short4 intermediate;
    short intermediateNext;
    short4 res1;
    {
    intermediate = convert_short4(*((__global short4*) ( (__global char*)(intermediateSrcDt2) + 0 * intermediateSrcStep + 4 * 0 * sizeof(short))));
    res1.s0 =  intermediate.s0 + intermediate.s1 +  intermediate.s2;
    res1.s1 =  intermediate.s1 + intermediate.s2 +  intermediate.s3;
    res1.s2 =  intermediate.s2 + intermediate.s3;
    res1.s3 =  intermediate.s3;
    intermediateNext = ( short) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 0 * sizeof(short))));
    res1.s2 += intermediateNext; 
    res1.s3 += intermediate.s3;
    intermediateNext = ( short) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 4 * 1 * sizeof( short) + 1 * sizeof(short))));
    res1.s3 += intermediateNext; 
  }

    *((__global short4*)(outDstDt1)) =  res1/3;
  }
#endif

#if 1 // tile(8)
  {
    short8 intermediate;
    short intermediateNext;
    short8 res1;
    {
    intermediate = convert_short8(*((__global short8*) ( (__global char*)(intermediateSrcDt2) + 0 * intermediateSrcStep + 8 * 0 * sizeof(short))));
    res1.s0 =  intermediate.s0 + intermediate.s1 +  intermediate.s2;
    res1.s1 =  intermediate.s1 + intermediate.s2 +  intermediate.s3;
    res1.s2 =  intermediate.s2 + intermediate.s3 +  intermediate.s4;
    res1.s3 =  intermediate.s3 + intermediate.s4 +  intermediate.s5;
    res1.s4 =  intermediate.s4 + intermediate.s5 +  intermediate.s6;
    res1.s5 =  intermediate.s5 + intermediate.s6 +  intermediate.s7;
    res1.s6 =  intermediate.s6 + intermediate.s7;
    res1.s7 =  intermediate.s7;
    intermediateNext = ( short) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 8 * 1 * sizeof( short) + 0 * sizeof(short))));
    res1.s6 += intermediateNext; 
    res1.s7 += intermediate.s3;
    intermediateNext = ( short) ( *((__global short*) ((__global char*) intermediateSrcDt2 + intermediateSrcStep * 0 + 8 * 1 * sizeof( short) + 1 * sizeof(short))));
    res1.s7 += intermediateNext; 
  }

    *((__global short8*)(outDstDt1)) =  res1/3;
  }
#endif

}

