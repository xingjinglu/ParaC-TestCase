#include <ClHeader.cl> 
/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global uint16_t* const inSrc,
  int inSrcWidth,
  int inSrcHeight,
  int inSrcStep,
  int inSrcShift,
  __global uint16_t *intermediateDst,
  int intermediateDstWidth,
  int intermediateDstHeight,
  int intermediateDstStep,
  int intermediateDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 4800 || gidy >= 6408 )
    return;

  /* kernel index calculation */
  int inSrcIdx1 = inSrcShift + ((float)gidy) *inSrcStep + ((float)gidx + -1 + 1) *sizeof(uint16_t);
  int inSrcIdx2 = inSrcShift + ((float)gidy) *inSrcStep + ((float)gidx + 1) *sizeof(uint16_t);
  int inSrcIdx3 = inSrcShift + ((float)gidy) *inSrcStep + ((float)gidx + 1 + 1) *sizeof(uint16_t);
  int intermediateDstIdx1 = intermediateDstShift + ((float)gidy) *intermediateDstStep + ((float)gidx + 1) *sizeof(uint16_t);

  /* kernel operands */
  __global uint16_t *inSrcDt1 = (__global char *)inSrc + inSrcIdx1;
  __global uint16_t *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global uint16_t *inSrcDt3 = (__global char *)inSrc + inSrcIdx3;
  __global uint16_t *intermediateDstDt1 = (__global char *)intermediateDst + intermediateDstIdx1;

  /* kernel operation */
  {
    int Op_ans1 = ( *((__global uint16_t*) inSrcDt1)) + (*(((__global uint16_t*) inSrcDt2)));
    *intermediateDstDt1 = (Op_ans1 + *(inSrcDt3)) / 3.;
  }

}

/* kernel function */
__kernel void kernel_2(
  __global uint16_t* const inSrc,
  int inSrcWidth,
  int inSrcHeight,
  int inSrcStep,
  int inSrcShift,
  __global uint16_t *outDst,
  int outDstWidth,
  int outDstHeight,
  int outDstStep,
  int outDstShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 4802 || gidy >= 6406 )
    return;

  /* kernel index calculation */
  int inSrcIdx1 = inSrcShift + ((float)gidy + -1 + 1) *inSrcStep + ((float)gidx) *sizeof(uint16_t);
  int inSrcIdx2 = inSrcShift + ((float)gidy + 1) *inSrcStep + ((float)gidx) *sizeof(uint16_t);
  int inSrcIdx3 = inSrcShift + ((float)gidy + 1 + 1) *inSrcStep + ((float)gidx) *sizeof(uint16_t);
  int outDstIdx1 = outDstShift + ((float)gidy + 1) *outDstStep + ((float)gidx) *sizeof(uint16_t);

  /* kernel operands */
  __global uint16_t *inSrcDt1 = (__global char *)inSrc + inSrcIdx1;
  __global uint16_t *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global uint16_t *inSrcDt3 = (__global char *)inSrc + inSrcIdx3;
  __global uint16_t *outDstDt1 = (__global char *)outDst + outDstIdx1;

  /* kernel operation */
  {
    int Op_ans1 = ( *((__global uint16_t*) inSrcDt1)) + (*(((__global uint16_t*) inSrcDt2)));
    *outDstDt1 = (Op_ans1 + *(inSrcDt3)) / 3.;
  }

}

