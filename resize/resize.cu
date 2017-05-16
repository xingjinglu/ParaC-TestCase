__global__ void  change_size_c3_cuda(unsigned char* dst,
    unsigned char* src, int width, int height,
    float rate){

  int x = threadIdx.x + blockIdx.x * blockDim.x;
  int y = threadIdx.y + blockIdx.y * blockDim.y;


  if( x >= width || y >= height)
    return;

  int new_x = (int)(x/rate);
  int new_y = (int)(y/rate);

  for( int k = 0; k < 3; k++){
    dst[ (y*width+x)*3+k] = src[((int)(new_y*(width/rate) + new_x))*3+k];
  }

}

__global__ void change_size_c1_cuda(unsigned char*dst,
    unsigned char *src, int width, int height, float rate){

  int x = threadIdx.x + blockIdx.x * blockDim.x;
  int y = threadIdx.y + blockIdx.y * blockDim.y;

  if( x >= width || y >= height)
    return;

  int new_x = (int)(x/rate);
  int new_y = (int)(y/rate);
  dst[y*width+x] = src[(int)(new_y * width/rate) + new_x)];


}






