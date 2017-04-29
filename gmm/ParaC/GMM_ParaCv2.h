#include <stdio.h>
#include <malloc.h>


#define GMM_MAX_COMPONT 4
#define GMM_LEARN_ALPHA 0.005
#define GMM_THRESHOD_SUMW 0.7

private	float* modelW;
private	float* modelS;
private	unsigned char* modelM;
private	unsigned char* m_mask;


void init(const unsigned char* _image, int  _image_size)
{
	m_mask = (unsigned char*)malloc(_image_size);
	if(!m_mask)
		printf("m_mask malloc fail \n");
	memset(m_mask, 0, _image_size);
	//为GMM模型的权重modelW，均值，modelM，方差modelS分配内存，并初始化为0
	modelW = (float*)malloc(_image_size*GMM_MAX_COMPONT*sizeof(float));
	modelS = (float*)malloc(_image_size*GMM_MAX_COMPONT*sizeof(float));
	modelM = (unsigned char*)malloc(_image_size*GMM_MAX_COMPONT*sizeof(unsigned char));

	if(!(modelW && modelS && modelM))
		printf( "GMM modelW or modelS or modelM malloc fail" );

	memset(modelW, 0, _image_size*GMM_MAX_COMPONT*sizeof(float));
	memset(modelS, 0, _image_size*GMM_MAX_COMPONT*sizeof(float));
	memset(modelM, 0, _image_size*GMM_MAX_COMPONT*sizeof(unsigned char));
}

void processFirstFrame(const unsigned char* _image, int row, int col)
{
	parac_matrix unsigned char imageIData[row][col] = _image;
	parac_matrix float modelWData[row][col][GMM_MAX_COMPONT] = modelW;
	parac_matrix float modelSData[row][col][GMM_MAX_COMPONT] = modelS;
	parac_matrix unsigned char modelMData[row][col][GMM_MAX_COMPONT] = modelM;
	
	parac_iterator it(iter_element;0: row: 1; 0: col : 1)
	{
		const unsigned char _imageData = imageIData[itx][ity];
		modelWData[itx][ity][0] = 1.0f;
		modelSData[itx][ity][0] = 15.0f;
		modelMData[itx][ity][0] = _imageData;
		
		modelWData[itx][ity][1: 4: 1] = {0.0f, 0.0f, 0.0f};
		modelSData[itx][ity][1: 4: 1] = {0.0f, 0.0f, 0.0f};
		modelMData[itx][ity][1: 4: 1] = {0, 0, 0};
	}
	
}
//后续可以扩展成+ - * / 通用的  现在只用到-  暂时为了简便 只扩展-

/* void matrix_multi(parac_matrix unsigned char& matrix_first[M][N], parac_matrix unsigned char& matrix_second[M][N][K], parac_matrix long& matrix_res[M][N][K])
{
	parac_iterator it(iter_element; 0: M -1: 1; 0: N - 1: 1)
	{
		matrix_res[itx][ity][0: K - 1: 1] = abs(matrix_first[itx][ity] - matrix_second[itx][ity][0: l - 1: 1]);	
	}
	matrix_res = matrix_res .* matrix_res;
} */
//q1:矩阵转换的时候 ，是 直接用第二维不同的2维矩阵进行操作，还是一个2维，一个3维，转换成统一维度之后 可否用以前的基本操作。
//q2:这个数据需要重新分配空间 进行存储。
//q3:算子的粒度，是针对整个过程进行不同维度的矩阵进行+-*/运算。
//q4: 如果直接使用矩阵-运算之后，还需要再遍历一遍整个矩阵进行 条件判断，这个开销是否值得
void trainGMM(const unsigned char* _image, int row, int col)
{
	parac_matrix unsigned char imageIData[row][col] = _image;
	parac_matrix float modelWData[row][col][GMM_MAX_COMPONT] = modelW;
	parac_matrix float modelSData[row][col][GMM_MAX_COMPONT] = modelS;
	parac_matrix unsigned char modelMData[row][col][GMM_MAX_COMPONT] = modelM;
	parac_vector long dist[GMM_MAX_COMPONENT];
	parac_iterator it(it_element; 0: row: 1; 0: col: 1)
	{
		
		////训练时更新每个高斯模型的权重，均值，方差数据。
		const unsigned char _imagData = imageIData[itx][ity];
		int num_fit = 0;
		
		dist[0:4:1] = abs(imageIData[itx][ity] - modelMData[itx][ity][0:4:1]); //
		//int delm = abs(_imagData - modelMData[itx][ity][0])
		//long dist = delm * delm;
		dist[0:4:1] = dist[0:4:1].*dist[0:4:1];
		
		if( dist[0:4:1] < 3.0 * modelSdata[itx][ity][0:4:1]){
			modelWData[itx][ity][0:4:1] += GMM_LEARN_ALPHA * (1 - modelWData[itx][ity][0:4:1]);
			modelMData[itx][ity][0:4:1] += (GMM_LEARN_ALPHA / modelWData[itx][ity][0:4:1]) * delm;
			modelSData[itx][ity][0:4:1] += (GMM_LEARN_ALPHA / modelWData[itx][ity][0:4:1]) * (dist - modelSData[itx][ity][0:4:1]);
		}
		else
		{
			modelWData[itx][ity][0:4:1] += GMM_LEARN_ALPHA * (0 - modelWData[itx][ity][0:4:1]);
			++num_fit;
		}
		
		
		// sort Gaussian componet by weight / sigma  start
		for(int kk = 0; kk < GMM_MAX_COMPONT; ++kk)
		{
			for(int rr = kk; rr < GMM_MAX_COMPONT; ++rr)
			{
				if(modelWData[itx][ity][rr] / modelSData[itx][ity][rr] > modelWData[itx][ity][kk] / modelSData[itx][ity][kk])
				{
					float temp_weight = modelWData[itx][ity][rr];
					modelWData[itx][ity][rr] = modelWData[itx][ity][kk];
					modelWData[itx][ity][kk] = temp_weight;

					unsigned char temp_mean = modelMData[itx][ity][rr];
					modelMData[itx][ity][rr] = modelMData[itx][ity][kk];
					modelMData[itx][ity][kk] = temp_mean;

					float temp_sigma = modelSData[itx][ity][rr];
					modelSData[itx][ity][rr] = modelSData[itx][ity][kk];
					modelSData[itx][ity][kk] = temp_sigma;

				}
			}
		}
		
		// create new Gaussian componet start
		if(num_fit == GMM_MAX_COMPONT && modelWData[itx][ity][GMM_MAX_COMPONT - 1] == 0)
		{
			// if there is no exit componetg fit ,then start a new componet
			for(int k = 0; k < GMM_MAX_COMPONT; ++k)
			{
				if(0 == modelWData[itx][ity][k])  // ?
				{
					modelWData[itx][ity][k] = GMM_LEARN_ALPHA;
					modelMData[itx][ity][k] = _imageData;
					modelSData[itx][ity][k] = 15.0;

					//normalization the weight, let they sum to 15
					for(int q = 0; q < GMM_MAX_COMPONT && q != k; q++)
					{
						// update the other unfit`s weight , u and sigma remain unchanged
						modelWData[itx][ity][q] *= (1 - GMM_LEARN_ALPHA);
					}
					break;
				}
			}
		}
		else if(num_fit == GMM_MAX_COMPONT && modelWData[itx][ity][GMM_MAX_COMPONT - 1] != 0)
		{
            modelMData[itx][ity][GMM_MAX_COMPONT - 1] = _imageData;
			modelSData[itx][ity][GMM_MAX_COMPONT - 1] = 15.0;
		}
	}
}

void testGMM(const unsigned char* _image, int row, int col)
{
	parac_matrix unsigned char imageIData[row][col] = _image;
	parac_matrix unsigned char m_maskData[row][col] = m_mask;
	parac_matrix float modelWData[row][col][GMM_MAX_COMPONT] = modelW;
	parac_matrix float modelSData[row][col][GMM_MAX_COMPONT] = modelS;
	parac_matrix unsigned char modelMData[row][col][GMM_MAX_COMPONT] = modelM;
	
	parac_iterator it(it_element; 0: row: 1; 0: col: 1)
	{
		const unsigned char _imageData = imageIData[itx][ity];
		float sum_w = 0.0;
		
		if(abs(_imagData - modelMData[itx][ity][0])) < (unsigned char)(2.5 * modelSData[itx][ity][0])
		{
			m_maskData[itx][ity] = 0;
			break;
		}
		sum_w += modelWData[itx][ity][0];
		if(sum_w >= GMM_THRESHOD_SUMW)
		{
			m_maskData[itx][ity] = 255;
			break;
		}
		
		if(abs(_imagData - modelMData[itx][ity][1])) < (unsigned char)(2.5 * modelSData[itx][ity][1])
		{
			m_maskData[itx][ity] = 0;
			break;
		}
		sum_w += modelWData[itx][ity][1];
		if(sum_w >= GMM_THRESHOD_SUMW)
		{
			m_maskData[itx][ity] = 255;
			break;
		}
		
		if(abs(_imagData - modelMData[itx][ity][2])) < (unsigned char)(2.5 * modelSData[itx][ity][2])
		{
			m_maskData[itx][ity] = 0;
			break;
		}
		sum_w += modelWData[itx][ity][2];
		if(sum_w >= GMM_THRESHOD_SUMW)
		{
			m_maskData[itx][ity] = 255;
			break;
		}
		
		if(abs(_imagData - modelMData[itx][ity][3])) < (unsigned char)(2.5 * modelSData[itx][ity][3])
		{
			m_maskData[itx][ity] = 0;
			break;
		}
		sum_w += modelWData[itx][ity][3];
		if(sum_w >= GMM_THRESHOD_SUMW)
		{
			m_maskData[itx][ity] = 255;
			break;
		}
	}
}