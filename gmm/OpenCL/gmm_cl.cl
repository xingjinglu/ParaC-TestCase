#pragma OPENCL EXTENSION cl_amd_printf : enable
#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable

#define GMM_MAX_COMPONT 3	
#define GMM_LEARN_ALPHA 0.005  
#define GMM_THRESHOD_SUMW 0.7
#define HEIGHT 1080
#define WIDTH 1920

__kernel void train_kernel(__global unsigned char *_image,
                           __global unsigned char *mask,
                           __global float *modelW,
                           __global float *modelS,
                           __global unsigned char *modelM,
                           int height,
                           int width)
{
  int x = get_global_id(1);
  int y = get_global_id(0);
   
  if(x >= height || y >=width)
    return;
  
  __global unsigned char *_imageData = _image + x * width + y;
  __global unsigned char *maskData = mask + x * width + y;
 
  __global float *modelWData = modelW + GMM_MAX_COMPONT * (x * width + y);
  __global float *modelSData = modelS + GMM_MAX_COMPONT * (x * width + y);
  __global unsigned char *modelMData = modelM + GMM_MAX_COMPONT * (x * width + y);
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

__kernel void test_kernel(__global unsigned char *_image,
                          __global unsigned char *mask,
                          __global float *modelW,
                          __global float *modelS,
                          __global unsigned char *modelM,
                          int height,
                          int width)
{
  int x = get_global_id(1);
  int y = get_global_id(0);
  
  if(x >= height || y >=width)
    return;
  
  __global unsigned char *_imageData = _image + x * width + y;
  __global unsigned char *maskData = mask + x * width + y;
 
  __global float *modelWData = modelW + GMM_MAX_COMPONT * (x * width + y);
  __global float *modelSData = modelS + GMM_MAX_COMPONT * (x * width + y);
  __global unsigned char *modelMData = modelM + GMM_MAX_COMPONT * (x * width + y);
	
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

