all: blur blur-time blur-opt
CFLAGS= -O3 -DTIME_PROF
blur:blur.c blur.cl
	g++ -I ./ $(CFLAGS) blur.c -o blur -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
blur-time:blur_time.c blur.cl
	g++ -I ./ $(CFLAGS) blur_time.c -o blur-time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
blur-opt:blur_opt_time.c blur_opt.cl
	g++ -I ./ $(CFLAGS) blur_opt_time.c -o blur-opt -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm blur blur-time blur-opt
	

