CC = g++
CFLAGS = -O3 -msse4.1
all: x86_orig x86_act
INCS =
LIBS =
x86_orig: laplacian_x86.cpp
	$(CC) $(CFLAGS) laplacian_x86.cpp  -o x86_orig $(LIBS) $(INCS) 
x86_act: laplacian_x86_act.cpp
	$(CC) $(CFLAGS) laplacian_x86_act.cpp  -o x86_act $(LIBS) $(INCS) 
clean:
	rm -f *.o x86_orig x86_act
