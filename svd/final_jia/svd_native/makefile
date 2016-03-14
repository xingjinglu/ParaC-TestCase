LDFLAGS = -L/usr/lib
LIBS = -lOpenCL
CFLAGS = -I/opt/AMDAPPSDK/include
svd_cl : svd_cl.cpp kernels.cpp
	g++ svd_cl.cpp kernels.cpp -O2 -o svd_cl -Wall $(LDFLAGS) $(LIBS) $(CFLAGS)

#-O2用于编程优化
