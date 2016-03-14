#LDFLAGS = -L/usr/lib
LIBS = -lOpenCL
CFLAGS = -I/opt/AMDAPPSDK/include 
svd : svd_high_level.c svd_high_level.cl
	g++ svd_high_level.c  -O3 -o svd -Wall $(LDFLAGS) $(LIBS) $(CFLAGS)

#-O2用于编程优化
