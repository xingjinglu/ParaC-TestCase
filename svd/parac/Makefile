#LDFLAGS = -L/usr/lib
LIBS = -lOpenCL
CFLAGS = -I/opt/AMDAPPSDK/include 
svd : svd_high_level.cl svd_high_level.c
	g++ svd_high_level.c -o svd -Wall $(LDFLAGS) $(LIBS) $(CFLAGS)
clean:
	rm svd 

#-O2用于编程优化
