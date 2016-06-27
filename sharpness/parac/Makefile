CFLAGS = -DTIME_PROF -DTIME_KERNEL
all: sharpup sharpness_time sharpness_256 sharpness_512 sharpness_1024 sharpness_2048 sharpness_4096
#all: sharpup sharpness_time sharpness_1024
sharpup:sharpness_high_level.c sharpness_high_level.cl
	g++ sharpness_high_level.c -o sharpness -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_time:sharpness_time.c sharpness_opt.cl
	g++ -O3  $(CFLAGS) sharpness_time.c -o sharpness_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_256:sharpness_opt_lxj_256.c sharpness_opt_lxj_256.cl
	g++ -O3 -D_VERIFY  $(CFLAGS) sharpness_opt_lxj_256.c -o sharpness_256 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_512:sharpness_opt_lxj_512.c sharpness_opt_lxj_512.cl
	g++ -O3 -D_VERIFY  $(CFLAGS) sharpness_opt_lxj_512.c -o sharpness_512 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_1024:sharpness_opt_lxj_1024.c sharpness_opt_lxj_1024.cl
	g++ -O3 -D_VERIFY  $(CFLAGS) sharpness_opt_lxj_1024.c -o sharpness_1024 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_2048:sharpness_opt_lxj_2048.c sharpness_opt_lxj_2048.cl
	g++ -O3 -D_VERIFY  $(CFLAGS) sharpness_opt_lxj_2048.c -o sharpness_2048 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_4096:sharpness_opt_lxj_4096.c sharpness_opt_lxj_4096.cl
	g++ -O3 -D_VERIFY  $(CFLAGS) sharpness_opt_lxj_4096.c -o sharpness_4096 -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm sharpness sharpness_time sharpness_1024 sharpness_256 sharpness_512 sharpness_2048 sharpness_4096
	

