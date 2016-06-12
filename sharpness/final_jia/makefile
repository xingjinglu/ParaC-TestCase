all: sharpness sharpness_time sharpness_orig
sharpness:sharpup.cpp sharpup.cl
	g++ -O3 sharpup.cpp -o sharpness -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_time:sharpness_time.cpp sharpup.cl
	g++ -O3 -DTIME_PROF sharpness_time.cpp -o sharpness_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_orig:sharpness_orig.cpp sharpup_orig.cl
	g++ -O3 -DTIME_PROF sharpness_orig.cpp -o sharpness_orig -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm sharpness sharpness_time sharpness_orig
	

