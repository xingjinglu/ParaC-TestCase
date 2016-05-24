
#define NBITS 8
#define NBANKS 16
#define NBINS 256


#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

__kernel void hist_atomic(
    __global unsigned char* const SrcImg,
    int SrcWidth,
    int SrcHeight,
    int SrcStep,
    int SrcShift,

    __global int * DstHist,
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



  // kernel index.
  int SrcImgIndex = SrcShift + ((float)gidy)*SrcStep + ((float)gidx*4)*sizeof(unsigned char);
  //int DstIndex = DstShift + ((float)gidy*;

  // kernel operand.


  // kernel operation.
uint gid = get_global_id(0);
uint lid = get_local_id(0);
uint idx;
uint n4VectorsPerThread = 4;

  __local uint subhists[NBANKS*NBINS];

  uint stride = get_global_size(0);
  uint4 temp, temp2;
  const uint shift = (uint) NBITS;
  const uint mask = (uint) (NBINS-1); // work_group_size(NBINS, 1, 1).
  uint offset = (uint) lid % (uint)(NBANKS);

  uint localItems = NBANKS * NBINS;
  uint localItemsPerWorkItem;
  uint localMaxWorkItems;

  // (1, NBINS/(NBANKS*NBINS) ) --> 0 bug??
  localMaxWorkItems = MIN(1, get_local_size(0)/localItems); // ->0
  localMaxWorkItems = MAX(1, localMaxWorkItems/localItems); // ->1

  localMaxWorkItems = localItems/localMaxWorkItems; // localItems.

  localMaxWorkItems = MIN( NBANKS, localMaxWorkItems ); // NBANKS.
  localItemsPerWorkItem = localItems / localMaxWorkItems; // NBINS


  // Init LDS for each work-item.
  __local uint4 *p = (__local uint4*) subhists;
  if( lid < localMaxWorkItems ){
    for( int i = 0, idx = lid; i < localItemsPerWorkItem/4; 
        i++, idx += localMaxWorkItems ){
        p[idx] = 0;
    }
  }

  barrier( CLK_LOCAL_MEM_FENCE);

  // read and scatter phase.
  for( int i = 0, idx = gid; i < n4VectorsPerThread; i++, idx += stride ){

    temp = SrcImg[idx]; // TBD.
    temp2 = (temp & mask) * (uint4)NBANKS + offset;
    (void) atomic_inc(subhists + temp2.x );
    (void) atomic_inc(subhists + temp2.y );
    (void) atomic_inc(subhists + temp2.z);
    (void) atomic_inc(subhists + temp2.w);


      temp = temp >> shift;
      temp2 = (temp & mask) *(uint4) NBANKS + offset;

      (void) atomic_inc( subhists + temp2.x );
      (void) atomic_inc( subhists + temp2.y );
      (void) atomic_inc( subhists + temp2.z );
      (void) atomic_inc( subhists + temp2.w );

      temp = temp >> shift;
      temp2 = (temp & mask) * (uint4) NBANKS + offset;
      (void) atomic_inc( subhists + temp2.x );
      (void) atomic_inc( subhists + temp2.y );
      (void) atomic_inc( subhists + temp2.z );
      (void) atomic_inc( subhists + temp2.w ); 


      temp = temp >> shift;
      temp2 = (temp & mask ) * (uint4) NBANKS + offset;
      (void) atomic_inc( subhists + temp2.x );
      (void) atomic_inc( subhists + temp2.y );
      (void) atomic_inc( subhists + temp2.z );
      (void) atomic_inc( subhists + temp2.w );
  }

  barrier( CLK_LOCAL_MEM_FENCE);


  // reduce __local banks to single histogram per work_group;

  if( lid < NBINS )
  {
    uint bin = 0;
    for(int i = 0; i < NBANKS; i++ )
    {
      bin += subhists[ (lid * NBANKS ) + i ];
    }

    DstHist[ (get_group_id(0)*NBINS) + lid] = bin; // TBD.

  }

}



__kernel void reduceKernel(__global uint *Histogram, uint nSubHists )
{
  uint gid = get_global_id(0);
  uint bin = 0;

  // Reduce work-group histograms into single histogram,
  // one thread for each bin.
  for( int i = 0; i < nSubHists; i++ )
      bin += Histogram[(i*NBINS) + gid ];
  Histogram[gid] = bin;

}
