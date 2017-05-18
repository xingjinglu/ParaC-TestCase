__global__ void MorphDilation_cuda(unsigned char* src, 
    unsigned char *dst, int width, int height, 
    int structWidth, int structHeight){


  int x = threadIdx.x + blockIdx.x * blockDim.x;
  int y = threadIdx.y + blockIdx.y * blockDim.y;

  if(x >= width || y >= height)
    return;

  dst[y*width + x] = src[y*width+x];
  int mid = (structWidth+1)/2-1;

  if( (y < mid) || (Y >= height - mid -1) )
    return;
  if( (x < mid) || (x >= width - mid - 1) )
    return;

  unsigned char val = 0;
  for( int m = 0; m < structWidth; m++){
    for( int n = 0; n < structHeight; n++){
      val |= src[(y+m)*width+x+n];
    }
  }

  dst[y*width+x] = val;
}
