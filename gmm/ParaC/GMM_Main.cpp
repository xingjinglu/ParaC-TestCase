#include <iostream>
#include "GMM_TEST2.h"
#include <cstdio>
#include <time.h>
#include <malloc.h>
#include <cstring>
#define MAX 256
using namespace std;

int main(int argc, char* argv[])
{
	clock_t  start, end;
	double t = 0, sum_t = 0;
	int width = 0, height = 0;
	std::cin >>  width >> height;
	int _image_size = width * height;
	unsigned char* _image = (unsigned char*)malloc(_image_size * sizeof(unsigned char));

	if(!_image)
		std::cout << "_image malloc failer" << std::endl;

	memset(_image, 0, _image_size);
    unsigned char* mask;
	MOG_BGS Mog_Bgs;
	int count = 0;
	long frameno = 0;
	long frameno2 = 0;

	// loop time n = 100;
	int n = 100;
	while(n--)
	{
		++count;
		//random to init _image;
		for(int i = 0; i < _image_size; ++i)
			_image[i] = rand() % MAX;

        //将生成的_image 输出
        for(int i = 0; i < _image_size; ++i)
            std::cout << (int)_image[i] << ", ";
        std::cout << endl;

		if(count == 1)
		{
			Mog_Bgs.init(_image, _image_size);
			Mog_Bgs.processFirstFrame(_image, _image_size);
		}
		else
		{
			++frameno;
			start = clock();
			Mog_Bgs.trainGMM(_image, _image_size);
			Mog_Bgs.testGMM(_image, _image_size);
			end = clock();
			t = end-start;
			sum_t += t;
			mask = Mog_Bgs.getMask();


			//输出mask
			for(int i = 0; i < _image_size; ++i)
                std::cout << (int)mask[i] << ", ";
            cout << std::endl;
		}
	}
	std::cout << (sum_t / frameno) / CLOCKS_PER_SEC << std::endl;
	system("pause");
	return 0;
}
