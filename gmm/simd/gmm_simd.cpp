#include <emmintrin.h>
#include <iostream>
#include <math.h>
#include <smmintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <xmmintrin.h>

#define GMM_MAX_COMPONT 4	
#define GMM_LEARN_ALPHA 0.005  
#define GMM_THRESHOD_SUMW 0.7
#define HEIGHT 1080
#define WIDTH 1920

using namespace std;

void trainGMM_SIMD(unsigned char *_image, unsigned char *mask, float *modelW, float *modelS, unsigned char *modelM, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
    
    for (int j = 0; j < width; j++)
		{
      float pixelDataF = (float) _imageData[j];
      __m128 *modelWData4;
      __m128 *modelSData4;
      __m128 modelMData4;
      __m128 delm4;
      __m128 dist4;
      __m128 temp4;
      __m128 dist_modelS;
   
      modelWData4 = (__m128*) modelWData;
      modelSData4 = (__m128*) modelSData;
      modelMData4 = _mm_set_ps((float)modelMData[3], (float)modelMData[2], (float)modelMData[1], (float)modelMData[0]);
      delm4 = _mm_set_ps1(pixelDataF);
      delm4 = _mm_sub_ps(delm4, modelMData4);
      dist4 = _mm_mul_ps(delm4, delm4);    
      
      temp4 = _mm_set_ps1(3.0);
      temp4 = _mm_mul_ps(temp4, *modelSData4);
      dist_modelS = _mm_sub_ps(dist4, temp4);
      temp4 = _mm_set_ps1(-GMM_LEARN_ALPHA);
      temp4 = _mm_mul_ps(temp4, *modelWData4);
      *modelWData4 = _mm_add_ps(*modelWData4, temp4);

      float *dist4N = (float *) &dist4;
      float *dist_S4N = (float *) &dist_modelS;
      float *delm4N = (float *) &delm4;
      float *modelWData4N = (float *) modelWData4;
      float *temp4N = (float *) &temp4;

      int num_fit = GMM_MAX_COMPONT;
      for (int k = 0; k < GMM_MAX_COMPONT; k++)
			{ 
        if (dist_S4N[k] < 0) 
        {
        	modelWData4N[k] += GMM_LEARN_ALPHA;
			  	modelMData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * abs(delm4N[k]);
			  	modelSData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * (dist4N[k]- modelSData[k]);
          num_fit--;
        } 
      }

      temp4 = _mm_div_ps(*modelWData4, *modelSData4);

			for (int kk = 0; kk < GMM_MAX_COMPONT - 1; kk++)
			{
				for (int rr = kk + 1; rr < GMM_MAX_COMPONT; rr++)
				{
					if (temp4N[rr] > temp4N[kk])
					{
						float temp_weight = modelWData[rr];
						modelWData[rr] = modelWData[kk];
						modelWData[kk] = temp_weight;

						unsigned char temp_mean = modelMData[rr];
						modelMData[rr] = modelMData[kk];
						modelMData[kk] = temp_mean;

						float temp_sigma = modelSData[rr];
						modelSData[rr] = modelSData[kk];
						modelSData[kk] = temp_sigma;
					}
				}
			}
			
      if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] == 0)
			{
				for (int k = 0; k < GMM_MAX_COMPONT; k++)
				{
					if (0 == modelWData[k])
					{
						if (k == 0)
							modelWData[k] = 1;
						else
							modelWData[k] = GMM_LEARN_ALPHA;
						
            modelMData[k] = _imageData[j];
						modelSData[k] = 15.0;
            
						for (int q = 0; q < GMM_MAX_COMPONT && q != k; q++)
						{
							modelWData[q] *= (1 - GMM_LEARN_ALPHA);
						}
						break;
					}
				}
			}
			else if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] != 0)
			{
				modelMData[GMM_MAX_COMPONT - 1] = _imageData[j];
				modelSData[GMM_MAX_COMPONT - 1] = 15.0;
			}

			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

void testGMM_SIMD(unsigned char* _image, unsigned char* mask, float* modelW, float* modelS, unsigned char* modelM, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
		unsigned char *maskData = mask + i * width;
		
    for (int j = 0; j < width; j++)
		{
/*
      float pixelDataF = (float) _imageData[j];
      __m128 *modelSData4;
      __m128 modelMData4;
      __m128 temp4;
      __m128 temp4_2;

      modelSData4 = (__m128*) modelSData;
      modelMData4 = _mm_set_ps((float)modelMData[3], (float)modelMData[2], (float)modelMData[1], (float)modelMData[0]); 
      temp4 = _mm_set_ps1(2.5);
      temp4 = _mm_mul_ps(temp4, *modelSData4);
      temp4_2 = _mm_set_ps1(pixelDataF);
      temp4_2 = _mm_sub_ps(temp4_2, modelMData4);
      
      float *temp4N = (float *) &temp4;
      float *temp4_2N = (float *) &temp4_2;      
*/
			float sum_w = 0.0;
			for (unsigned char k = 0; k < GMM_MAX_COMPONT; k++)
			{
				//if (abs(temp4[k]) < temp4_2N[k])
				if (abs(_imageData[j] - modelMData[k]) < (unsigned char)(2.5 * modelSData[k]))
        {
          maskData[j] = 0;
					break;
				}
				sum_w += modelWData[k];
				if (sum_w >= GMM_THRESHOD_SUMW)
				{
					maskData[j] = 255;
					break;
				}
			}
			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

void trainGMM(unsigned char *_image, unsigned char *mask, float *modelW, float *modelS, unsigned char *modelM, int height, int width)
{
	/**************************** Train ******************************************/
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
		for (int j = 0; j < width; j++)
		{
			int num_fit = 0;

			/**************************** Update parameters Start ******************************************/
			for (int k = 0; k < GMM_MAX_COMPONT; k++)
			{
				int delm = abs(_imageData[j] - modelMData[k]);
				long dist = delm * delm;
				if (dist < 3.0 * modelSData[k])
				{
					modelWData[k] += GMM_LEARN_ALPHA * (1 - modelWData[k]);
					modelMData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * delm;
					modelSData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * (dist - modelSData[k]);
				}
				else
				{
					modelWData[k] += GMM_LEARN_ALPHA * (0 - modelWData[k]);
					num_fit++;
				}
			}
			/**************************** Update parameters End ******************************************/

			/*********************** Sort Gaussian component by 'weight / sigma' Start ****************************/
			for (int kk = 0; kk < GMM_MAX_COMPONT - 1; kk++)
			{
				for (int rr = kk + 1; rr < GMM_MAX_COMPONT; rr++)
				{
					if (modelWData[rr] / modelSData[rr] > modelWData[kk] / modelSData[kk])
					{
						float temp_weight = modelWData[rr];
						modelWData[rr] = modelWData[kk];
						modelWData[kk] = temp_weight;

						unsigned char temp_mean = modelMData[rr];
						modelMData[rr] = modelMData[kk];
						modelMData[kk] = temp_mean;

						float temp_sigma = modelSData[rr];
						modelSData[rr] = modelSData[kk];
						modelSData[kk] = temp_sigma;
					}
				}
			}
			/*********************** Sort Gaussian model by 'weight / sigma' End ****************************/

			/*********************** Create new Gaussian component Start ****************************/
			if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] == 0)
			{
				//if there is no exit component fit,then start a new component
				for (int k = 0; k < GMM_MAX_COMPONT; k++)
				{
					if (0 == modelWData[k])
					{
						if (k == 0)
							modelWData[k] = 1;
						else
							modelWData[k] = GMM_LEARN_ALPHA;
						
            modelMData[k] = _imageData[j];
						modelSData[k] = 15.0;

						//normalization the weight,let they sum to 1
						for (int q = 0; q < GMM_MAX_COMPONT && q != k; q++)
						{
							/****update the other unfit's weight,u and sigma remain unchanged****/
							modelWData[q] *= (1 - GMM_LEARN_ALPHA);
						}
						break;
					}
				}
			}
			else if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] != 0)
			{
				modelMData[GMM_MAX_COMPONT - 1] = _imageData[j];
				modelSData[GMM_MAX_COMPONT - 1] = 15.0;
			}
			/*********************** Create new Gaussian component End ****************************/

			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

void testGMM(unsigned char* _image, unsigned char* mask, float* modelW, float* modelS, unsigned char* modelM, int height, int width)
{
	/*********************** Predict ****************************/
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
		unsigned char *maskData = mask + i * width;
		for (int j = 0; j < width; j++)
		{
			float sum_w = 0.0;
			for (unsigned char k = 0; k < GMM_MAX_COMPONT; k++)
			{
				if (abs(_imageData[j] - modelMData[k]) < (unsigned char)(2.5 * modelSData[k]))
				{
					maskData[j] = 0;
					break;
				}
				sum_w += modelWData[k];
				if (sum_w >= GMM_THRESHOD_SUMW)
				{
					maskData[j] = 255;
					break;
				}
			}
			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

int main()
{
  float *modelW = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  float *modelW_S = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  float *modelS = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  float *modelS_S = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  unsigned char *modelM = new unsigned char[HEIGHT * GMM_MAX_COMPONT * WIDTH];;
  unsigned char *modelM_S = new unsigned char[HEIGHT * GMM_MAX_COMPONT * WIDTH];;
  unsigned char *frame = new unsigned char[HEIGHT * WIDTH];
  unsigned char *mask = new unsigned char[HEIGHT * WIDTH];
  unsigned char *mask2 = new unsigned char[HEIGHT * WIDTH];
  int height = HEIGHT;
  int width = WIDTH;  

  memset(modelW, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float));
  memset(modelW_S, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float));
  memset(modelS, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float));
  memset(modelS_S, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float));
  memset(modelM, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(unsigned char));
  memset(modelM_S, 0, HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(unsigned char));
  memset(mask, 0, HEIGHT * WIDTH * sizeof(unsigned char));
  memset(mask2, 0, HEIGHT * WIDTH * sizeof(unsigned char));
  clock_t start, end;
  clock_t start2, end2;
	double sum_t_train = 0;
	double sum_t_test = 0;
	double sum_t2_train = 0;
	double sum_t2_test = 0;
	 
  srand(unsigned(time(0)));  

  int frame_num = 50;
  for (int t = 0; t < frame_num; t++)
  {
    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        *(frame + i * width + j) = rand() % 255;
    
    start = clock();  
    trainGMM(frame, mask, modelW, modelS, modelM, height, width);
    end = clock();
    sum_t_train += end - start;
    start = clock();  
    testGMM(frame, mask, modelW, modelS, modelM, height, width);
    end = clock();
    sum_t_test += end - start;

    //trainGMM(frame, mask2, modelW_S, modelS_S, modelM_S, height, width);
    start2 = clock();
    trainGMM_SIMD(frame, mask2, modelW_S, modelS_S, modelM_S, height, width);
    end2 = clock();
    sum_t2_train += end2 - start2;
    start2 = clock();
    testGMM_SIMD(frame, mask2, modelW_S, modelS_S, modelM_S, height, width);
    end2 = clock();
    sum_t2_test += end2 - start2;
  
    // TEST
    /*
    int diff_count = 0;
    for (int i = 0; i < height * width; i++)
      if (mask[i] != mask2[i])
        diff_count++;
    cout <<"Diff: " << diff_count << endl;
    */
  }
	cout <<"CPU Train: " << (sum_t_train / frame_num) / CLOCKS_PER_SEC << endl;
	cout <<"SIMD Train: " << (sum_t2_train / frame_num) / CLOCKS_PER_SEC << endl;
	cout <<"CPU Test: " << (sum_t_test / frame_num) / CLOCKS_PER_SEC << endl;
	cout <<"SIMD Test: " << (sum_t2_test / frame_num) / CLOCKS_PER_SEC << endl;
}
