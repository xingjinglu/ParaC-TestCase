CXX=g++
CXXFLAGS=-fopenmp -O3 -lrt
all:bilateral_ser bilateral_omp

bilateral_ser:bilateral_ser.cpp
	$(CXX) $(CXXFLAGS) bilateral_ser.cpp -o bilateral_ser
bilateral_omp:bilateral_omp.cpp
	$(CXX) $(CXXFLAGS) bilateral_omp.cpp -o bilateral_omp

clean:
	rm bilateral_ser bilateral_omp
