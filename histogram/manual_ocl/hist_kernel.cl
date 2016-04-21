
__kernel void hist_atomic(
    __global unsigned char* const SrcImg,
    int SrcWidth,
    int SrcHeight,
    int SrcStep,
    int SrcShift,

    __global short * DstHist,
    int DstWidth,
    int DstHeight,
    int DstStep,
    int DstShift
    )
{

// Kernel thread ID.
const int gidx = get_global_id(0);
const int gidy = get_global_id(1);

if( gidx >= 256 || gidy >= 256 )
   return;





}
