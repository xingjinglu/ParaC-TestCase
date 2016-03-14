CC = pgc++
CFLAGS = -O3
#-ta=radeon:spectre
INCS =
LIBS =
svd_acc:svd_acc.o
	$(CC) $(CFLAGS) -o svd_acc svd_acc.o $(LIBS) $(INCS) 
svd_acc.o: svd_acc.cpp
	$(CC) $(CFLAGS) -c svd_acc.cpp -o svd_acc.o $(LIBS) $(INCS)
clean:
	rm *.o svd_acc -f
