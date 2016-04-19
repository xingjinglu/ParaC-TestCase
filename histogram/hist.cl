/**************************************************/
/* This file is generated automatically by clang. */
/**************************************************/

/* kernel function */
__kernel void kernel_1(
)
{
  /* kernel thread ID */
  const int gidx = get_global_id(0);
  const int gidy = get_global_id(1);

  /* kernel boundary check */
  if ( gidx >= 256 || gidy >= 256 )
    return;

  /* kernel index calculation */

  /* kernel operands */

  /* kernel operation */
  {
    out[(*in)[itx][ity]]++;
  }

}

