#include<iostream>
#include<cstring>
#include<cstdlib>

#define GMM_MAX_COMPONT 3	
#define GMM_LEARN_ALPHA 0.005  
#define GMM_THRESHOD_SUMW 0.7
#define HEIGHT 1080
#define WIDTH 1920

using namespace std;

__global__ void trainGMM_CUDA(unsigned char *_image, unsigned char *mask, float *modelW, float *modelS, unsigned char *modelM, int height, int width)
{
  const int x = blockIdx.x * blockDim.x + threadIdx.x;
  const int y = blockIdx.y * blockDim.y + threadIdx.y;

  if (x >= height || y >= width)
    return; 
 
  unsigned char *_imageData = _image + x * width + y;
 
  float *modelWData = modelW + GMM_MAX_COMPONT * (x * width + y);
  float *modelSData = modelS + GMM_MAX_COMPONT * (x * width + y);
  unsigned char *modelMData = modelM + GMM_MAX_COMPONT * (x * width + y);

	int num_fit = 0;
	
  for (int k = 0; k < GMM_MAX_COMPONT; k++)
	{
		int delm = abs(_imageData[0] - modelMData[k]);
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

	for (int kk = 0; kk < GMM_MAX_COMPONT; kk++)
	{
		for (int rr = kk; rr< GMM_MAX_COMPONT; rr++)
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
				
        modelMData[k] = _imageData[0];
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
		modelMData[GMM_MAX_COMPONT - 1] = _imageData[0];
		modelSData[GMM_MAX_COMPONT - 1] = 15.0;
	}
}

__global__ void testGMM_CUDA(unsigned char *_image, unsigned char *mask, float *modelW, float *modelS, unsigned char *modelM, int height, int width)
{
  const int x = blockIdx.x * blockDim.x + threadIdx.x;
  const int y = blockIdx.y * blockDim.y + threadIdx.y;
  
  if (x >= height || y >= width)
    return; 
 
  unsigned char *_imageData = _image + x * width + y;
  unsigned char *maskData = mask + x * width + y;
 
  float *modelWData = modelW + GMM_MAX_COMPONT * (x * width + y);
  float *modelSData = modelS + GMM_MAX_COMPONT * (x * width + y);
  unsigned char *modelMData = modelM + GMM_MAX_COMPONT * (x * width + y);
	
	float sum_w = 0.0;
	for (unsigned char k = 0; k < GMM_MAX_COMPONT; k++)
	{
		if (abs(_imageData[0] - modelMData[k]) < (unsigned char)(2.5 * modelSData[k]))
		{
			maskData[0] = 0;
			break;
		}
			sum_w += modelWData[k];
		if (sum_w >= GMM_THRESHOD_SUMW)
		{
			maskData[0] = 255;
			break;
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
			for (int kk = 0; kk < GMM_MAX_COMPONT; kk++)
			{
				for (int rr = kk; rr< GMM_MAX_COMPONT; rr++)
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
  float *modelS = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  unsigned char *modelM = new unsigned char[HEIGHT * GMM_MAX_COMPONT * WIDTH];;
  unsigned char *frame = new unsigned char[HEIGHT * WIDTH];
  unsigned char *mask = new unsigned char[HEIGHT * WIDTH];
  unsigned char *mask2 = new unsigned char[HEIGHT * WIDTH];
  int height = HEIGHT;
  int width = WIDTH;  

  memset(modelW, 0, sizeof(modelW));
  memset(modelS, 0, sizeof(modelM));
  memset(modelM, 0, sizeof(modelS));
  memset(mask, 0, sizeof(mask));

  // For GPU  
  float *dev_modelW, *dev_modelS;
  unsigned char *dev_frame, *dev_mask, *dev_modelM;

  cudaMalloc((void**)&dev_modelW, (HEIGHT * GMM_MAX_COMPONT * WIDTH) * sizeof(float));
  cudaMalloc((void**)&dev_modelS, (HEIGHT * GMM_MAX_COMPONT * WIDTH) * sizeof(float));
  cudaMalloc((void**)&dev_modelM, (HEIGHT * GMM_MAX_COMPONT * WIDTH) * sizeof(unsigned char));
  cudaMalloc((void**)&dev_frame, (HEIGHT * WIDTH) * sizeof(unsigned char));
  cudaMalloc((void**)&dev_mask, (HEIGHT * WIDTH) * sizeof(unsigned char));

  cudaMemcpy(dev_modelW,
             modelW,
             HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float),
             cudaMemcpyHostToDevice);
  cudaMemcpy(dev_modelS,
             modelS,
             HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(float),
             cudaMemcpyHostToDevice);
  cudaMemcpy(dev_modelM,
             modelM,
             HEIGHT * GMM_MAX_COMPONT * WIDTH * sizeof(unsigned char),
             cudaMemcpyHostToDevice);
  
  dim3 block(32,8);
  dim3 grid((HEIGHT + block.x - 1) / block.x, 
					  (WIDTH + block.y - 1) / block.y);

  clock_t start, end;
  clock_t start2, end2;
	double sum_t = 0;
	double sum_t2 = 0;
	 
  srand(unsigned(time(0)));  

  int frame_num = 100;
  for (int t = 0; t < frame_num; t++)
  {
    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        *(frame + i * width + j) = rand() % 255;
    
    start = clock();  
    trainGMM(frame, mask, modelW, modelS, modelM, height, width);
    testGMM(frame, mask, modelW, modelS, modelM, height, width);
    end = clock();
    sum_t += end - start;

    start2 = clock();
    cudaMemcpy(dev_frame,
               frame,
               HEIGHT * WIDTH * sizeof(unsigned char),
               cudaMemcpyHostToDevice);
    trainGMM_CUDA<<<grid, block>>>(dev_frame, dev_mask,  dev_modelW, dev_modelS, dev_modelM, height, width);    
    testGMM_CUDA<<<grid, block>>>(dev_frame, dev_mask,  dev_modelW, dev_modelS, dev_modelM, height, width);    
    cudaMemcpy(mask2,
               dev_mask,
               HEIGHT * WIDTH * sizeof(unsigned char),
               cudaMemcpyDeviceToHost);
    end2 = clock();
    sum_t2 += end2 - start2;
  
  // TEST
  /*
  int diff_count = 0;
  for (int i = 0; i < height * width; i++)
    if (mask[i] != mask2[i])
      diff_count++;
  
  cout <<"Diff: " << diff_count << endl;
  */
  }
	cout <<"CPU: " << (sum_t / frame_num) / CLOCKS_PER_SEC << endl;
	cout <<"GPU: " << (sum_t2 / frame_num) / CLOCKS_PER_SEC << endl;
}
