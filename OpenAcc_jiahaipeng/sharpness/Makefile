CC = pgc++
CFLAGS = -O3 -ta=tesla:cc35
INCS =
LIBS =
sharpness_acc: sharpness_acc.o
	$(CC) $(CFLAGS) -o sharpness_acc sharpness_acc.o $(LIBS) $(INCS) 
sharpness_acc.o: sharpness_acc.cpp
	$(CC) $(CFLAGS) -c sharpness_acc.cpp -o sharpness_acc.o $(LIBS) $(INCS)
clean:
	rm *.o sharpness_acc -f
