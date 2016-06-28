#!/bin/sh
echo "make"
make

EXES=("seq" "acc_caps_ocl" "acc_caps_cuda" "acc_pgi_cuda" "cap_fuse")
Niter=3

for exe in ${EXES[@]}
do
	echo "rm log_"${exe}
	rm log_${exe}

	for ((i=0; i<${Niter}; ++i))  
	do  
		echo "./"${exe}"8192 8192 >> log_"${exe}
		./${exe} 8192 8192 >> log_${exe}
	done
done

