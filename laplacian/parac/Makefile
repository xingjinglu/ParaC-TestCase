CFLAGS = -DTIME_PROF
all: laplacian laplacian_time laplacian_opt laplacian_256 laplacian_512 laplacian_1024 laplacian_2048 laplacian_4096 
#all: laplacian laplacian_time laplacian_opt laplacian_256 laplacian_1024  
laplacian:laplacian.c laplacian.cl
	g++ -O3 laplacian.c -o laplacian -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_time:laplacian_time.c laplacian.cl
	g++ -g  $(CFLAGS) laplacian_time.c -o laplacian_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_opt:laplacian_time_opt.c laplacian_opt_lxj.cl
	g++ -O3  $(CFLAGS) laplacian_time_opt.c -o laplacian_opt -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_256:laplacian_opt_lxj_256.c laplacian_opt_lxj_256.cl
	g++ -O3  $(CFLAGS) laplacian_opt_lxj_256.c -o laplacian_256 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_512:laplacian_opt_lxj_512.c laplacian_opt_lxj_512.cl
	g++ -O3  $(CFLAGS) laplacian_opt_lxj_512.c -o laplacian_512 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_1024:laplacian_opt_lxj_1024.c laplacian_opt_lxj_1024.cl
	g++ -O3  $(CFLAGS) laplacian_opt_lxj_1024.c -o laplacian_1024 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_2048:laplacian_opt_lxj_2048.c laplacian_opt_lxj_2048.cl
	g++ -O0 -g  $(CFLAGS) laplacian_opt_lxj_2048.c -o laplacian_2048 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
laplacian_4096:laplacian_opt_lxj_4096.c laplacian_opt_lxj_4096.cl
	g++ -O3  $(CFLAGS) laplacian_opt_lxj_4096.c -o laplacian_4096 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm laplacian laplacian_time laplacian_opt laplacian_256 laplacian_512 laplacian_1024 laplacian_2048 laplacian_4096


	

