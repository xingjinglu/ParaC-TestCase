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

/* kernel function */
__kernel void kernel_3(
  __global uint16_t* const inSrc,
  int inSrcWidth,
  int inSrcHeight,
  int inSrcStep,
  int inSrcShift,
  __global uint16_t* const filter_hSrc,
  int filter_hSrcWidth,
  int filter_hSrcHeight,
  int filter_hSrcStep,
  int filter_hSrcShift,
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
  if ( gidx >= (4800/4) || gidy >= 6408 )
    return;

  /* kernel index calculation */
  int inSrcIdx2 = inSrcShift + ((float)gidy) *inSrcStep + ((float)gidx *4 + -1 + 1) *sizeof(uint16_t);
  int intermediateDstIdx1 = intermediateDstShift + ((float)gidy) *intermediateDstStep + ((float)gidx *4 + 1) *sizeof(uint16_t);

  /* kernel operands */
  __global uint16_t *filter_hSrcDt1 = (__global char *)filter_hSrc + filter_hSrcShift;
  __global uint16_t *inSrcDt2 = (__global char *)inSrc + inSrcIdx2;
  __global uint16_t *intermediateDstDt1 = (__global char *)intermediateDst + intermediateDstIdx1;

  /* kernel operation */
  {
         int filter_h[3];
    int4 in;
     int R2Next;
    int4 res1;
    {
      filter_h[0] = ( int) (*((__global uint16_t*) ((__global char*) filter_hSrcDt1 + 0 + filter_hSrcStep * 0)));
      filter_h[1] = ( int) (*((__global uint16_t*) ((__global char*) filter_hSrcDt1 + 1 + filter_hSrcStep * 0)));
      filter_h[2] = ( int) (*((__global uint16_t*) ((__global char*) filter_hSrcDt1 + 2 + filter_hSrcStep * 0)));
      in = vload4(0, inSrcDt2 + 0 * inSrcStep + 4 * 0);
      res1.s0 = filter_h[0] * in.s0 + filter_h[1] * in.s1 + filter_h[2] * in.s2;
      res1.s1 = filter_h[0] * in.s1 + filter_h[1] * in.s2 + filter_h[2] * in.s3;
      res1.s2 = filter_h[0] * in.s2 + filter_h[1] * in.s3;
      R2Next = ( int) ( *((__global uint16_t*) ((__global char*) inSrcDt2 + inSrcStep * 0 + 4 * 1 + 0)));
      res1.s2 += filter_h[2] * R2Next; 
      res1.s3 = filter_h[0] * in.s3;
      R2Next = ( int) ( *((__global uint16_t*) ((__global char*) inSrcDt2 + inSrcStep * 0 + 4 * 1 + 0)));
      res1.s3 += filter_h[1] * R2Next; 
      R2Next = ( int) ( *((__global uint16_t*) ((__global char*) inSrcDt2 + inSrcStep * 0 + 4 * 1 + 1)));
      res1.s3 += filter_h[2] * R2Next; 
    }
    uint16_t4 temp0;
    temp0 = convert_uint16_t4(res1);
    *intermediateDstDt1 = temp0.s0;
    *(intermediateDstDt1 + 1) = temp0.s1;
    *(intermediateDstDt1 + 2) = temp0.s2;
    *(intermediateDstDt1 + 3) = temp0.s3;
  }

}

/* kernel function */
__kernel void kernel_4(
  __global uint16_t* const intermediateSrc,
  int intermediateSrcWidth,
  int intermediateSrcHeight,
  int intermediateSrcStep,
  int intermediateSrcShift,
  __global uint16_t* const filter_vSrc,
  int filter_vSrcWidth,
  int filter_vSrcHeight,
  int filter_vSrcStep,
  int filter_vSrcShift,
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
  int intermediateSrcIdx2 = intermediateSrcShift + ((float)gidy + -1 + 1) *intermediateSrcStep + ((float)gidx) *sizeof(uint16_t);
  int outDstIdx1 = outDstShift + ((float)gidy + 1) *outDstStep + ((float)gidx) *sizeof(uint16_t);

  /* kernel operands */
  __global uint16_t *filter_vSrcDt1 = (__global char *)filter_vSrc + filter_vSrcShift;
  __global uint16_t *intermediateSrcDt2 = (__global char *)intermediateSrc + intermediateSrcIdx2;
  __global uint16_t *outDstDt1 = (__global char *)outDst + outDstIdx1;

  /* kernel operation */
  {
         int filter_v[3];
     int intermediate[3];
     int R2Next;
     int res1;
    {
      filter_v[0] = ( int) (*((__global uint16_t*) ((__global char*) filter_vSrcDt1 + 0 + filter_vSrcStep * 0)));
      intermediate[0] = ( int) ( *((__global uint16_t*) ((__global char*) intermediateSrcDt2 + 0 + intermediateSrcStep * 0)));
      res1 = filter_v[0] * intermediate[0]; 
      filter_v[0] = ( int) (*((__global uint16_t*) ((__global char*) filter_vSrcDt1 + 0 + filter_vSrcStep * 1)));
      intermediate[0] = ( int) ( *((__global uint16_t*) ((__global char*) intermediateSrcDt2 + 0 + intermediateSrcStep * 1)));
      res1 += filter_v[0] * intermediate[0]; 
      filter_v[0] = ( int) (*((__global uint16_t*) ((__global char*) filter_vSrcDt1 + 0 + filter_vSrcStep * 2)));
      intermediate[0] = ( int) ( *((__global uint16_t*) ((__global char*) intermediateSrcDt2 + 0 + intermediateSrcStep * 2)));
      res1 += filter_v[0] * intermediate[0]; 
    }
    *outDstDt1 = (__global uint16_t)(*res1);
  }

}

