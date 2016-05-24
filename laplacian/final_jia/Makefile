CFLAGS = -DTIME_PAR
lap:lap.cpp laplacian.cl
	g++ lap.cpp $(CFLAGS) -o lap -lOpenCL -I/opt/AMDAPPSDK/include 

clean:rm lap
