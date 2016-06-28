#cap and cap_native use the same input file, but with different compiler options
flag = -O3 -DDEBUG

all : clean
	hmpp --openacc-target OPENCL -k g++ $(flag) laplacian.cpp -o acc_caps_ocl
	hmpp --openacc-target CUDA -k g++ $(flag) laplacian.cpp -o acc_caps_cuda
	pgc++ -acc -fast -Minfo $(flag) laplacian.cpp -o acc_pgi_cuda
	g++ $(flag) laplacian.cpp -o seq
	g++ $(flag) -lOpenCL laplacian-cap.cpp -o cap

clean :
	rm *.out *.hmf* -f acc_pgi_cuda cap seq acc_caps_cuda acc_caps_ocl 

