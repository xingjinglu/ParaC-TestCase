all: gmm gmm_prof
gmm:
	g++ -O3 -msse4.1 gmm_simd.cpp -o gmm
gmm_prof:
	g++ -O3 -msse4.1 gmm_simd_prof.cpp -o gmm_prof

clean:
	rm gmm gmm_prof
