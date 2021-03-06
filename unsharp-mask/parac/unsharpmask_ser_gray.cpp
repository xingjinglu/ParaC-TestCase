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

  void  
pipeline_mask(int  C, int  R, float  threshold, float  weight, 
    void * img_void_arg, void * mask_void_arg)
{
  float * img, *mask;
  img = (float *) (img_void_arg);
  mask = (float *) (mask_void_arg);

  // for(int _T_i1 = 0; _T_i1 <= 256; _T_i1++) 
  for (int  _T_i1 = 0; (_T_i1 <= ((R + 1) / 8)); _T_i1 = (_T_i1 + 1))  // Tiling.
  {
    float  blurx[8][518];
    float  blury[8][518];
    float  sharpen[8][518];
   // for( int _T_i2 = -1; _T_i2 <= 4; _T_i2++ )
    for (int  _T_i2 = -1; (_T_i2 <= ((C + 3) / 512)); _T_i2 = (_T_i2 + 1))
    {
      // compute blurx. Are the computing order affect the precision or performance?
      // 2049 < ()? 2049 : () 
      int  _ct1083 = (((R + 1) < ((8 * _T_i1) + 7))? (R + 1): ((8 * _T_i1) + 7));
      int  _ct1084 = (2 > (8 * _T_i1))? 2: (8 * _T_i1); // if 1th.val = 2, else = 8 * _T_i1
 
      // [2, 2049]      
      // for( int _i1 = 2 | 8*_T_i1; _i1 <= (8*_T_i1 + 7) | 2049; _i1++)
      for (int  _i1 = _ct1084; (_i1 <= _ct1083); _i1 = (_i1 + 1))
      { 
        // 2051 or 512*_T_i2+517->[5, 517, 1029, 1541, 2053, 2565]
        int  _ct1085 = (((C + 3) < ((512 * _T_i2) + 517))? (C + 3): ((512 * _T_i2) + 517)); 
        int  _ct1086 = ((0 > (512 * _T_i2))? 0: (512 * _T_i2));  // 0 or 512* _T_i2 -->[0, 0, 512, 1024, 1536, 2048]
        //#pragma ivdep
        //for ( int _i2 = 0 | 512*_T_i2; _i2 <= 512*_T_i2 + 517 | 2051; _i2++)
        for (int  _i2 = _ct1086; (_i2 <= _ct1085); _i2 = (_i2 + 1))
        {
          blurx[((-8 * _T_i1) + _i1)][((-512 * _T_i2) + _i2)] 
            = (img[((-2 + _i1) * (C + 4)) + _i2] * 0.0625f) 
            + (img[((-1 + _i1) * (C + 4)) + _i2] * 0.25f)
            + (img[       (_i1 * (C + 4)) + _i2] * 0.375f) 
            + (img[((1 + _i1) * (C + 4)) + _i2] * 0.25f) 
            + (img[((2 + _i1) * (C + 4)) + _i2] * 0.0625f);
        }
      }


      int  _ct1087 = (((R + 1) < ((8 * _T_i1) + 7))? (R + 1): ((8 * _T_i1) + 7));
      int  _ct1088 = ((2 > (8 * _T_i1))? 2: (8 * _T_i1));
      for (int  _i1 = _ct1088; (_i1 <= _ct1087); _i1 = (_i1 + 1))
      {
        int  _ct1089 = (((C + 1) < ((512 * _T_i2) + 516))? (C + 1): ((512 * _T_i2) + 516));
        int  _ct1090 = ((2 > ((512 * _T_i2) + 1))? 2: ((512 * _T_i2) + 1));
#pragma ivdep
        for (int  _i2 = _ct1090; (_i2 <= _ct1089); _i2 = (_i2 + 1))
        {
          blury[(-8 * _T_i1) + _i1][(-512 * _T_i2) + _i2] 
            = ((((blurx[-8 * _T_i1 + _i1][-2 + (-512 * _T_i2) + _i2] * 0.0625f) 
                    + (blurx[-8 * _T_i1 + _i1][-1 + (-512 * _T_i2) + _i2] * 0.25f)) 
                  + (blurx[-8 * _T_i1 + _i1][(-512 * _T_i2) + _i2] * 0.375f)) 
                + (blurx[-8 * _T_i1 + _i1][1 + (-512 * _T_i2) + _i2] * 0.25f)) 
            + (blurx[-8 * _T_i1 + _i1][2 + (-512 * _T_i2) + _i2] * 0.0625f);
        }
      }


      int  _ct1091 = (((R + 1) < ((8 * _T_i1) + 7))? (R + 1): ((8 * _T_i1) + 7));
      int  _ct1092 = ((2 > (8 * _T_i1))? 2: (8 * _T_i1));
      for (int  _i1 = _ct1092; (_i1 <= _ct1091); _i1 = (_i1 + 1))
      {
        int  _ct1093 = (((C + 1) < ((512 * _T_i2) + 515))? (C + 1): ((512 * _T_i2) + 515));
        int  _ct1094 = ((2 > ((512 * _T_i2) + 2))? 2: ((512 * _T_i2) + 2));
#pragma ivdep
        for (int  _i2 = _ct1094; (_i2 <= _ct1093); _i2 = (_i2 + 1))
        {
          sharpen[-8 * _T_i1 + _i1][-512 * _T_i2 + _i2] 
            = img[_i1 * (C + 4) + _i2] * (1 + weight) 
                + (blury[-8 * _T_i1 + _i1][-512 * _T_i2 + _i2] * -(weight));
        }
      }


      int  _ct1095 = (((R + 1) < ((8 * _T_i1) + 7))? (R + 1): ((8 * _T_i1) + 7));
      int  _ct1096 = ((2 > (8 * _T_i1))? 2: (8 * _T_i1));
      for (int  _i1 = _ct1096; (_i1 <= _ct1095); _i1 = (_i1 + 1))
      {
        int  _ct1097 = (((C + 1) < ((512 * _T_i2) + 514))? (C + 1): ((512 * _T_i2) + 514));
        int  _ct1098 = ((2 > ((512 * _T_i2) + 3))? 2: ((512 * _T_i2) + 3));
#pragma ivdep
        for (int  _i2 = _ct1098; (_i2 <= _ct1097); _i2 = (_i2 + 1))
        {
          float  _ct1099 = img[(( (_i1 * (C + 4))) + _i2)];
          float  _ct1100 = sharpen[((-8 * _T_i1) + _i1)][((-512 * _T_i2) + _i2)];
          float  _ct1101 = ((std::abs((img[((_i1 * (C + 4))) + _i2] 
                    - blury[((-8 * _T_i1) + _i1)][((-512 * _T_i2) + _i2)])) 
                < threshold)? _ct1099: _ct1100);
          mask[((_i1 - 2) * C) + _i2 - 2] = _ct1101;
        }
      }



    }
  }
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
  //   ++++++++++++++++++++++++++
  //   ++++++++++++++++++++++++++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++123456789abcdeefghijkl++
  //   ++++++++++++++++++++++++++
  //   ++++++++++++++++++++++++++
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
