all: blur blur_ty
blur: blur.c
	gcc -fopenmp -O2 -std=gnu11 -msse4 blur.c -lrt -o blur
	
blur_ty: blur_ty.c
	gcc -O2 -std=gnu11 -msse4 blur_ty.c -lrt -o blur_ty


clean:
	rm blur
