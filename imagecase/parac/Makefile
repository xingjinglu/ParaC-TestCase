CFLAGS = -DTIME_PROF -D_VERIFY
#CFLAGS = -DTIME_PROF 
all: imagecase  imagecase_verify
#all: imagecase imagecase_time imagecase_opt imagecase_256 imagecase_1024  
imagecase:imagecase.c imagecase.cl
	g++ -O3 imagecase.c -o imagecase -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
imagecase_verify:imagecase_verify.c imagecase_verify.cl
	g++ -O3 -D_VERIFY imagecase_verify.c -o imagecase_verify -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm imagecase image_verify


	

