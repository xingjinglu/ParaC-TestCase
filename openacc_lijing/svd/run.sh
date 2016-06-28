#!/bin/sh
echo "make"
make

EXES=("seq" "acc_caps_ocl" "acc_caps_cuda" "acc_pgi_cuda" "cap")
Niter=3

for exe in ${EXES[@]}
do
	echo "rm log_"${exe}
	rm log_${exe}

	for ((i=0; i<${Niter}; ++i))  
	do  
		echo "./"${exe}"256 256 >> log_"${exe}
		./${exe} 256 256 >> log_${exe}
	done
done

