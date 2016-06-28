#cap and cap_native use the same input file, but with different compiler options
flag = -O3 -DDEBUG

all : clean
	hmpp --openacc-target OPENCL -k g++ $(flag) laplacian_fuse.cpp -o acc_caps_ocl
	hmpp --openacc-target CUDA -k g++ $(flag) laplacian_fuse.cpp -o acc_caps_cuda
	pgc++ -acc -fast -Minfo $(flag) laplacian_fuse.cpp -o acc_pgi_cuda
	g++ $(flag) laplacian_fuse.cpp -o seq
	g++ $(flag) -lOpenCL laplacian_fuse-cap.cpp -o cap_fuse

clean :
	rm *.out *.hmf* -f acc_pgi_cuda cap_fuse seq acc_caps_cuda acc_caps_ocl 

