#include<iostream>
#include<math.h>
#include<stdlib.h>
void erosion(unsigned char * src,
    unsigned char *dst, int width,
    int height, int structWidth, int structHeight)
{

  int mid = (structWidth+1)/2 -1;
  unsigned char val = 255;

  for( int y = 0; y < mid; y++){
    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }


  for( int y = height-mid-1; y < height; y++){
    for( int x = 0; x < mid; x++){
      dst[y*width+x] = src[y*width+x];
    }
    for(int x = width - mid -1; x < width; x++){
      dst[y*width+x] = src[y*width+x];
    }
  }


  for( int y = mid; y < height-mid-1; y++){
    for( int x = mid; x < width-mid-1; x++){

      for( int m = 0; m < structWidth; m++){
        for( int n = 0; n < structHeight; n++){
          val &= src[(y+n)*width+x+m];
        }
      }
      dst[y*width+x] = val;

    }
  }

}

int main(int argc, char *argv[])
{
  if( argc < 3 ){
    std::cout<<"Please input Height and Width \n";
    return 0;
  }

  int Height = atoi(argv[1]);
  int Width = atoi(argv[2]);

  unsigned char *src = (unsigned char*) malloc(sizeof(unsigned char)*Width*Height);
  unsigned char *dst = (unsigned char*) malloc(sizeof(unsigned char)*Width*Height);

  for(int i = 0; i < Height; i++)
    for( int j = 0; j < Width; j++){
      src[i*Width+j] = rand()%255;
      //dst[i*Width+j] = src[i*Width+j];
    }

  erosion(src, dst, Width, Height, 3, 3 );

  return 0;
}
