all: blur
blur:blur.c blur.cl
	g++ -I ./ -O3 blur.c -o blur -lOpenCL -I/opt/AMDAPPSDK/include -lfreeimage
clean:
	rm blur
