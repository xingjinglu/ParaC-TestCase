all: sharpness sharpness_time sharpness_orig sharpness_icpp
sharpness:sharpup.cpp sharpup.cl
	g++ -O3 -DTIME_PAR sharpup.cpp -o sharpness -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_time:sharpness_time.cpp sharpup.cl
	g++ -O3 -DTIME_PROF sharpness_time.cpp -o sharpness_time -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_icpp:sharpness_time_icpp.cpp sharpup.cl
	g++ -O3 -DTIME_PROF sharpness_time_icpp.cpp -o sharpness_icpp -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
sharpness_orig:sharpness_orig.cpp sharpup_orig.cl
	g++ -O3 -DTIME_PROF sharpness_orig.cpp -o sharpness_orig -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm sharpness sharpness_time sharpness_orig
	

