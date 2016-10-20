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
#include<stdint.h>
#include <malloc.h>
#include <cmath>
#include <string.h>
#include <time.h>

#define M 2560
#define N 1536

#define isl_min(x,y) ((x) < (y) ? (x) : (y))
#define isl_max(x,y) ((x) > (y) ? (x) : (y))
#define isl_floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))

struct timespec ts, te;  

void  pipeline_filtered(int  C, int  R, void * input_void_arg, void * filtered_void_arg)
{

  clock_gettime(CLOCK_MONOTONIC, &ts);

  float * input, *filtered;
  float * grid, *blurz, *blurx, *blury, *interpolated;
  input = (float *) (input_void_arg);
  filtered = (float *) (filtered_void_arg);
 // 2* ((R-1)/8-1-1+1) * ((C-1)/8-1-1+1) -> 2*((R-1)/8-1)*((C-1)/8-1)*15 -> 2 * 325* 197*15
 // R == 2616, C = 1592
  grid = (float *) (malloc((sizeof(float ) * ( ( (2 * (((R - 1) / 8) - 1 - 1 + 1)) * (((C - 1) / 8) - 1 - 1 + 1)) * 15) )));
  blurz = (float *) (malloc((sizeof(float ) * (((2 * (((R - 1) / 8) - 1 - 1 + 1)) * (((C - 1) / 8) - 1 - 1 + 1)) * 11))));
  blurx = (float *) (malloc((sizeof(float ) * (((2 * (((R - 1) / 8) - 3 - 3 + 1)) * (((C - 1) / 8) - 1 - 1 + 1)) * 11))));
  blury = (float *) (malloc((sizeof(float ) * (((2 * (((R - 1) / 8) - 3 - 3 + 1)) * (((C - 1) / 8) - 3 - 3 + 1)) * 11))));
  interpolated = (float *) (malloc((sizeof(float ) * ((2 * (-56 + R)) * (-56 + C)))));

  // Fill grid with 0.
  #pragma omp parallel for schedule(static)
  for (int  _i0 = 0; (_i0 <= 1); _i0 = (_i0 + 1)) // 0, 1
  {
    for (int  _i1 = 1; (_i1 <= 325); _i1 = (_i1 + 1)) // 
    {
      for (int  _i2 = 1; (_i2 <= 197); _i2 = (_i2 + 1))
      {
        #pragma ivdep
        for (int  _i3 = 0; (_i3 <= 14); _i3 = (_i3 + 1))
        {
          grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((_i1 - 1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((_i2 - 1) * 15)) 
		  + _i3)] 
		  = 0;
        }
      }
    }
  }


  // Downsampe & 
  #pragma omp parallel for schedule(static)
  for (int  _i0 = 1; (_i0 <= 325); _i0 = (_i0 + 1))
  {
    for (int  _i1 = 1; (_i1 <= 197); _i1 = (_i1 + 1))
    {
      for (int  _i2 = 0; (_i2 <= 8); _i2 = (_i2 + 1))
      {
        for (int  _i3 = 0; (_i3 <= 8); _i3 = (_i3 + 1))
        {

          grid[((((0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i0) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i1) * 15)) 
		  + (2 + (int ) (((input[((((-4 + (8 * _i0)) + _i2) * C) + ((-4 + (8 * _i1)) + _i3))] * 10) + 0.5f))))] 
		  = (grid[((((0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i0) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i1) * 15)) 
		  + (2 + (int ) (((input[((((-4 + (8 * _i0)) + _i2) * C) + ((-4 + (8 * _i1)) + _i3))] * 10) + 0.5f))))] 
		  + input[((((-4 + (8 * _i0)) + _i2) * C) + ((-4 + (8 * _i1)) + _i3))]);
          
		  grid[((((1 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i0) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) + ((-1 + _i1) * 15)) 
		  + (2 + (int ) (((input[((((-4 + (8 * _i0)) + _i2) * C) 
		  + ((-4 + (8 * _i1)) + _i3))] * 10) 
		  + 0.5f))))] 
		  = (grid[((((1 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i0) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15)))
		  + ((-1 + _i1) * 15)) 
		  + (2 + (int ) (((input[((((-4 + (8 * _i0)) + _i2) * C) + ((-4 + (8 * _i1)) + _i3))] * 10) + 0.5f))))] + 1);



        }
      }
    }
  }

  for (int  _i0 = 0; (_i0 <= 1); _i0 = (_i0 + 1))
  {
    #pragma omp parallel for schedule(static)
    for (int  _i1 = 1; (_i1 <= 325); _i1 = (_i1 + 1))
    {
      for (int  _i2 = 1; (_i2 <= 197); _i2 = (_i2 + 1))
      {
        #pragma ivdep
        for (int  _i3 = 2; (_i3 <= 12); _i3 = (_i3 + 1))
        {

          blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) + ((_i1 - 1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) + ((_i2 - 1) * 11)) + (_i3 - 2))] 
		  = ((((grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i2) * 15)) 
		  + (-2 + _i3))] 
		  
		  + (4 * grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i2) * 15)) 
		  + (-1 + _i3))])) 
		  
		  + (6 * grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i2) * 15)) 
		  + _i3)])) 
		  
		  + (4 * grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i2) * 15)) 
		  + (1 + _i3))])) 
		  
		  + grid[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 15)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 15))) 
		  + ((-1 + _i2) * 15)) 
		  + (2 + _i3))]);



        }
      }
    }
  }
  for (int  _i0 = 0; (_i0 <= 1); _i0 = (_i0 + 1))
  {
    #pragma omp parallel for schedule(static)
    for (int  _i1 = 3; (_i1 <= 323); _i1 = (_i1 + 1))
    {
      for (int  _i2 = 1; (_i2 <= 197); _i2 = (_i2 + 1))
      {
        #pragma ivdep
        for (int  _i3 = 2; (_i3 <= 12); _i3 = (_i3 + 1))
        {


          blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((_i1 - 3) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((_i2 - 1) * 11)) 
		  + (_i3 - 2))] 
		  = ((((blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))] 
		  
		  + (4 * blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-2 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))])) 
		  
		  + (6 * blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))])) 
		  
		  + (4 * blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + (_i1 * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))])) 
		  
		  + blurz[((((_i0 * (((((((R - 1) / 8) - 1) - 1) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((1 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))]);




        }
      }
    }
  }
  for (int  _i0 = 0; (_i0 <= 1); _i0 = (_i0 + 1))
  {
    #pragma omp parallel for schedule(static)
    for (int  _i1 = 3; (_i1 <= 323); _i1 = (_i1 + 1))
    {
      for (int  _i2 = 3; (_i2 <= 195); _i2 = (_i2 + 1))
      {
        #pragma ivdep
        for (int  _i3 = 2; (_i3 <= 12); _i3 = (_i3 + 1))
        {
          blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11))
		  + ((_i1 - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		  + ((_i2 - 3) * 11)) + (_i3 - 2))] 
		  = ((((blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-3 + _i2) * 11)) 
		  + (-2 + _i3))] 
		  
		  + (4 * blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-2 + _i2) * 11)) 
		  + (-2 + _i3))])) 
		  
		  + (6 * blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((-1 + _i2) * 11)) 
		  + (-2 + _i3))])) 
		  
		  + (4 * blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + (_i2 * 11)) 
		  + (-2 + _i3))])) 
		  
		  + blurx[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 1) - 1) + 1)) * 11)) 
		  + ((-3 + _i1) * ((((((C - 1) / 8) - 1) - 1) + 1) * 11))) 
		  + ((1 + _i2) * 11)) 
		  + (-2 + _i3))]);


        }
      }
    }
  }
  for (int  _i0 = 0; (_i0 <= 1); _i0 = (_i0 + 1))
  {
    #pragma omp parallel for schedule(static)
    for (int  _i1 = 24; (_i1 <= 2583); _i1 = (_i1 + 1))
    {
      #pragma ivdep
      for (int  _i2 = 24; (_i2 <= 1559); _i2 = (_i2 + 1))
      {

        interpolated[(((_i0 * ((-56 + R) * (-56 + C))) + ((_i1 - 24) * (-56 + C))) + (_i2 - 24))] 
		= (((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) + ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]))) 
		
		+ (((float ) ((_i2 % 8)) / 8) * ((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ ((((_i2 / 8) + 1) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ ((((_i2 / 8) + 1) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]

		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ ((((_i2 / 8) + 1) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))])))
		
		- (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]

		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]

		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))])))))) 
		
		+ (((input[((_i1 * C) + _i2)] * 10) 
		- (int ) ((input[((_i1 * C) + _i2)] * 10))) * (((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) + (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
        + (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 		
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))]))) 
		
		+ (((float ) ((_i2 % 8)) / 8) * ((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + ((((_i2 / 8) + 1) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + ((((_i2 / 8) + 1) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ ((((_i2 / 8) + 1) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))]))) 
		
		- (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11)))
		+ (((_i2 / 8) - 3) * 11)) + (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ (((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) + 1) - 2))])))))) 
		
		- ((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]))) 
		
		+ (((float ) ((_i2 % 8)) / 8) * ((blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ ((((_i2 / 8) + 1) - 3) * 11)) + ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11)))
		+ ((((_i2 / 8) + 1) - 3) * 11)) + ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + ((((_i2 / 8) + 1) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))]))) 
		
		- (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11)) 
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		+ (((float ) ((_i1 % 8)) / 8) * (blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ ((((_i1 / 8) + 1) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) + (((_i2 / 8) - 3) * 11))
		+ ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))] 
		
		- blury[((((_i0 * (((((((R - 1) / 8) - 3) - 3) + 1) * (((((C - 1) / 8) - 3) - 3) + 1)) * 11)) 
		+ (((_i1 / 8) - 3) * ((((((C - 1) / 8) - 3) - 3) + 1) * 11))) 
		+ (((_i2 / 8) - 3) * 11)) + ((2 + (int ) ((input[((_i1 * C) + _i2)] * 10))) - 2))])))))))));


      }
    }
  }
  #pragma omp parallel for schedule(static)
  for (int  _i1 = 24; (_i1 <= 2583); _i1 = (_i1 + 1))
  {
    #pragma ivdep
    for (int  _i2 = 24; (_i2 <= 1559); _i2 = (_i2 + 1))
    {
      float  _ct0 = (interpolated[(((0 * ((-56 + R) * (-56 + C))) + ((-24 + _i1) * (-56 + C))) + (-24 + _i2))] 
          / interpolated[(((1 * ((-56 + R) * (-56 + C))) + ((-24 + _i1) * (-56 + C))) + (-24 + _i2))]);
      float  _ct1 = input[((_i1 * C) + _i2)];
      float  _ct2 = ((interpolated[(((1 * ((-56 + R) * (-56 + C))) + ((-24 + _i1) * (-56 + C))) + (-24 + _i2))] > 0)? _ct0: _ct1);
      filtered[((0 + ((_i1 - 24) * (-56 + C))) + (_i2 - 24))] = _ct2;
    }
  }
#if 1
  free(grid);
  free(blurz);
  free(blurx);
  free(blury);
  free(interpolated);
#endif

   clock_gettime(CLOCK_MONOTONIC, &te);
   printf("hello \n");
}

int main()
{


  // Init memory pool.
  int nruns, rows, cols, row_base, col_base; 
  int R, C;  // Not defined.
  int off_left = 24, total_pad = 56;
  float *image = (float*) malloc ( sizeof(float)*M*N);
  for( int i = 0; i < M; i++)
    for( int j = 0; j < N; j++){
      image[i*N+j] = rand()%256;
    }

  // ROI.
  rows = M;
  cols = N;
  R = M;
  C = N;
  row_base = (R - rows)/2; // 0
  col_base = (C - cols)/2; // 0
  // image_region == image;

  // create ghost zone and copy image roi.
  float *img_ghost = (float*) malloc( sizeof(float) * (rows+total_pad) * (cols+total_pad) );
  for( int i = 0; i < M; i++ ){
    memcpy( img_ghost + (i+off_left)*(cols+total_pad) + off_left,  image+i*cols, sizeof(float)*cols);
  }

  // clamp the boundary portions.
  // image_clamp();
  // 1th and last row.
  for( int i = 0; i < off_left; i++)
    for( int j = 0; j < cols; j++){
      img_ghost[i*(cols+total_pad) + off_left + j] = image[j];
      img_ghost[(i+rows+off_left)*(cols+total_pad)+off_left+j] = image[(rows-1)*cols+j];
    }
 // left and right cols.
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < off_left; j++){
      img_ghost[(i+off_left)*(cols+total_pad) + j] = image[i*cols];
      img_ghost[(i+off_left)*(cols+total_pad) +j+cols] = image[i*cols+cols-1];
    }

 // left_up & right_up
 for(int i = 0; i < off_left; i++)
   for(int j = 0; j < off_left; j++){
     img_ghost[i*(cols+total_pad)+j] = img_ghost[off_left*(cols+total_pad)+j];
     img_ghost[i*(cols+total_pad)+j+cols] = img_ghost[off_left*(cols+total_pad)+j+cols];
   }
 
 // left_bottom & right_bottom
  for(int i = 0; i < off_left; i++)
   for(int j = 0; j < off_left; j++){
     img_ghost[(i+rows)*(cols+total_pad)+j] = img_ghost[(rows+off_left-1)*(cols+total_pad)+j];
     img_ghost[(i+rows)*(cols+total_pad)+j+cols] = img_ghost[(rows+off_left-1)*(cols+total_pad)+j+cols];
   }
 

  float *res =(float*) malloc( sizeof(float)*M*N);
  pipeline_filtered(cols+total_pad, rows+total_pad, img_ghost, res);

  uint64_t  total = (te.tv_sec - ts.tv_sec)*1000000000L + (te.tv_nsec - ts.tv_nsec);
  printf("ttime = %f ms\n", (double)total/1000000.0);

  return 1;
}
