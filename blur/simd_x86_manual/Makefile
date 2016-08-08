all:blur


blur:blur_manual.cpp
#g++ -O3 -fopenmp -msse4 blur_manual.cpp -o blur
	g++ -O2 -fopenmp -msse4 blur_manual.cpp -o blur  # -O2 is better than -O3
clean:
	rm blur
