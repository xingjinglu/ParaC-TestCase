CFLAGS = -O3 -DTIME_PROF -D_VERIFY -D_OPTBANK 
all: unsharp unsharp-time
unsharp:unsharpmask_native.c unsharpmask_native.cl
	g++ -O3 unsharpmask_native.c -o unsharp -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
unsharp-time:unsharpmask_native_time.c unsharpmask_native.cl
	g++  $(CFLAGS) unsharpmask_native_time.c -o unsharp-time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm unsharp unsharp-time


	

