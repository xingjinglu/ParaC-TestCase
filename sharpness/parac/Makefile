CFLAGS = -DTIME_PROF -DTIME_KERNEL
all: sharpup sharpness_time
sharpup:sharpness_high_level.c sharpness_high_level.cl
	g++ sharpness_high_level.c -o sharpness -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_time:sharpness_time.c sharpness_opt.cl
	g++ -O3 $(CFLAGS) sharpness_time.c -o sharpness_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm sharpness sharpness_time
	

