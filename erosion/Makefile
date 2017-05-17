all: erosion erosion_cuda
erosion: erosion.cpp
	g++ -O3 erosion.cpp -o erosion
erosion_cuda: erosion.cu
	nvcc -O3  erosion.cu -I /usr/local/cuda-7.5/samples/common/inc/ -lcublas -o erosion_cuda 

clean:
	rm erosion erosion_cuda
