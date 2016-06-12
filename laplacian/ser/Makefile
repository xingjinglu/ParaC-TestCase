CC = g++
CFLAGS = -O 
INCS = -I/opt/AMDAPP/include
LIBS = -L/usr/lib
laplacian: laplacian.o
	$(CC) $(CFLAGS) -o laplacian laplacian.o $(LIBS) $(INCS) 
laplacian.o: laplacian.cpp 
	$(CC) $(CFLAGS) -c laplacian.cpp $(LIBS) $(INCS)
clean:
	rm -f *.o laplacian
