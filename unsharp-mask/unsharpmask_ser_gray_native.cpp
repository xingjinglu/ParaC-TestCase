/*
  Copyright (c) 2015 Indian Institute of Science
  All rights reserved.
  
  Written and provided by:
  Ravi Teja Mullapudi, Vinay Vasista, Uday Bondhugula
  Dept of Computer Science and Automation
  Indian Institute of Science
  Bangalore 560012 
  India
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  
  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  
  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
  
  3. Neither the name of the Indian Institute of Science nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.
  
  THIS MATERIAL IS PROVIDED BY Ravi Teja Mullapudi, Vinay Vasista, and Uday
  Bondhugula, Indian Institute of Science ''AS IS'' AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
  EVENT SHALL Ravi Teja Mullapudi, Vinay Vasista, CSA Indian Institute of Science
  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cmath>
#include <string.h>

#define M 2048
#define N 2048
#define O 3

#define isl_min(x,y) ((x) < (y) ? (x) : (y))
#define isl_max(x,y) ((x) > (y) ? (x) : (y))
#define isl_floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))

extern "C" void  pipeline_mask(int  C, int  R, float  threshold, float  weight, void * img_void_arg, void * mask_void_arg)
{
  float * img, *mask, *blurx, *blury, *sharpen;
  img = (float *) (img_void_arg);
  mask = (float *) (mask_void_arg);
  blurx = (float *) (malloc((sizeof(float ) * ((3 * R) * (4 + C)))));
  blury = (float *) (malloc((sizeof(float ) * ((3 * R) * C))));
  sharpen = (float *) (malloc((sizeof(float ) * ((3 * R) * C))));

    #pragma omp parallel for schedule(static)
    for (int  _i1 = 2; (_i1 <= (R + 1)); _i1 = (_i1 + 1))
    {
      #pragma ivdep
      for (int  _i2 = 0; (_i2 <= (C + 3)); _i2 = (_i2 + 1))
      {
        blurx[((((_i1 - 2) * (4 + C))) + _i2)] 
          = (img[(((-2 + _i1) * (C + 4))) + _i2] * 0.0625f) 
          + (img[(((-1 + _i1) * (C + 4))) + _i2] * 0.25f) 
          + (img[((_i1 * (C + 4))) + _i2] * 0.375f) 
          + (img[(((1 + _i1) * (C + 4))) + _i2] * 0.25f) 
          + (img[(((2 + _i1) * (C + 4))) + _i2] * 0.0625f);
      }
    }

    #pragma omp parallel for schedule(static)
    for (int  _i1 = 2; (_i1 <= (R + 1)); _i1 = (_i1 + 1))
    {
#pragma ivdep
      for (int  _i2 = 2; (_i2 <= (C + 1)); _i2 = (_i2 + 1))
      {
        blury[((((_i1 - 2) * C)) + (_i2 - 2))] 
          = (blurx[( ((-2 + _i1) * (4 + C))) + (-2 + _i2)] * 0.0625f) 
          + (blurx[( ((-2 + _i1) * (4 + C))) + (-1 + _i2)] * 0.25f)
          + (blurx[( ((-2 + _i1) * (4 + C))) + _i2] * 0.375f) 
          + (blurx[( ((-2 + _i1) * (4 + C))) + (1 + _i2)] * 0.25f) 
          + (blurx[( ((-2 + _i1) * (4 + C))) + (2 + _i2)] * 0.0625f);
      }
    }


    #pragma omp parallel for schedule(static)
    for (int  _i1 = 2; (_i1 <= (R + 1)); _i1 = (_i1 + 1))
    {
#pragma ivdep
      for (int  _i2 = 2; (_i2 <= (C + 1)); _i2 = (_i2 + 1))
      {
        sharpen[((((_i1 - 2) * C)) + (_i2 - 2))] 
          = (img[(((_i1 * (C + 4))) + _i2)] * (1 + weight)) 
          + (blury[((((-2 + _i1) * C)) + (-2 + _i2))] * -(weight));
      }
    }

  
  
    #pragma omp parallel for schedule(static)
    for (int  _i1 = 2; (_i1 <= (R + 1)); _i1 = (_i1 + 1))
    {
      #pragma ivdep
      for (int  _i2 = 2; (_i2 <= (C + 1)); _i2 = (_i2 + 1))
      {
        float  _ct0 = img[(((_i1 * (C + 4))) + _i2)];
        float  _ct1 = sharpen[((((-2 + _i1) * C)) + (-2 + _i2))];
        float  _ct2 = ((std::abs((img[(( (_i1 * (C + 4))) + _i2)] 
                  - blury[((((-2 + _i1) * C)) + (-2 + _i2))])) < threshold)? _ct0: _ct1);
        mask[((((_i1 - 2) * C)) + (_i2 - 2))] = _ct2;
      }
    }
  
  free(blurx);
  free(blury);
  free(sharpen);
}




int main()
{
  int nruns = 6, rows = 0, cols = 0, c = 0, channel = 3;
  int row_base, col_base;
  float *image, *image_ghost, *res;
  float threshold = 0.000001;
  int weight = 4;

  image = (float*) malloc( sizeof(float)*M*N);
  res = (float*) malloc( sizeof(float)*M*N);
  rows = M;
  cols = N;
  channel = O;
  
  // get image roi, not needed.
  row_base = (M - rows)/2;
  col_base = (N - cols)/2;

  // create ghost zones.
 int total_pad = 4;
 image_ghost = (float*) malloc ( sizeof(float) * (rows+4) * (cols+4) );
   for( int i = 0; i < M; i++){
     memcpy( image_ghost + (i+2)*(cols+4) + 2, image+i*cols, cols );
   }


 // init data of image.
  for( int i = 0; i < M; i++ )
    for( int j = 0; j < N; j++ ){
      image[i*cols+j] = (float)(rand()%255);
      image_ghost[i*(cols+4)+j+2] =  image[i*cols+j];
    }


  pipeline_mask(cols, rows, threshold, weight, image_ghost, res);


  return 0;
}
