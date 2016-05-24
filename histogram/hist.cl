/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
  __global unsigned char* const inSrc,
  int inSrcWidth,
  int inSrcHeight,
  int inSrcStep,
  int inSrcShift)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 256 || gidy >= 256 )
    return;

  /* kernel index calculation */
  int inSrcIdx1 = inSrcShift + ((float)gidy) *inSrcStep + ((float)gidx) *sizeof(unsigned char);

  /* kernel operands */
  __global unsigned char *inSrcDt1 = inSrc + inSrcIdx1;

  /* kernel operation */
  {
    unsigned char temp = in[itx][ity];
  }

}

