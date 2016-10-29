CXX=g++
CXXFLAGS= -fopenmp -O3 -lrt

all: umgray_ser um_ser
umgray_ser:unsharpmask_ser_gray.cpp
	$(CXX) $(CXXFLAGS) unsharpmask_ser_gray.cpp -o umgray_ser
um_ser:unsharp_mask_ser.cpp
	$(CXX) $(CXXFLAGS) unsharp_mask_ser.cpp -o um_ser

clean:
	rm umgray_ser um_ser

