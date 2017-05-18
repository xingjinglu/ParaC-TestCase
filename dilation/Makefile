all: dilation dilation_cuda
dilation: dilation.cpp
	g++ -O3 dilation.cpp -o dilation
dilation_cuda: dilation.cu
	nvcc -O3  dilation.cu -I /usr/local/cuda-7.5/samples/common/inc/ -lcublas -o dilation_cuda 

clean:
	rm dilation dilation_cuda
