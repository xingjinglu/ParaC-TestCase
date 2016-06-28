CC = pgc++
CFLAGS = -O3 -ta=tesla:cc35
INCS =
LIBS =
LP_ACC: LP_ACC.o
	$(CC) $(CFLAGS) -o LP_ACC LP_ACC.o $(LIBS) $(INCS) 
LP_ACC.o: laplacian_acc.cpp
	$(CC) $(CFLAGS) -c laplacian_acc.cpp -o LP_ACC.o $(LIBS) $(INCS)
clean:
	rm *.o LP_ACC -f
