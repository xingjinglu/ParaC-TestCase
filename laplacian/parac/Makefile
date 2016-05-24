CFLAGS = -DTIME_PROF
all: laplacian laplacian_time laplacian_opt
laplacian:laplacian.c laplacian.cl
	g++ -O3 laplacian.c -o laplacian -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_time:laplacian_time.c laplacian.cl
	g++ -g  $(CFLAGS) laplacian_time.c -o laplacian_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_opt:laplacian_time_opt.c laplacian_opt_lxj.cl
	g++ -O3  $(CFLAGS) laplacian_time_opt.c -o laplacian_opt -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm laplacian laplacian_time laplacian_opt
	

