__global__void MorphErosion_cuda(unsigned char*src, 
     unsigned char*dst, int width,int height, 
     int structWidth, int structHeight){

  int x = threadIdx.x + blockIdx.x*blockDim.x;
  int y = threadIdx.y + lbockIdx.y*blockDim.y;

  if(x >= width || y >= height)
    return;

  dst[y*width+x] = src[y*width+x];
  int mid = (structWidth+1)/2 -1 ; // structWidth = structHeight = 3,4.

  if( (y < mid) || (y>=height-mid-1) )
    return;
  if( (x < mid) || (x >= width - mid -1 ))
    return;

  unsigned char val = 255;

  for(int m = 0; m < structWidth; m++){
    for(int n = 0; n < structHeight; n++){
      val &= src[(y+n)*width+x+m];
    }
  }

  dst[y*width+x] = val;
}
