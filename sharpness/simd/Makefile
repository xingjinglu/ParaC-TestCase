CC = g++
CFLAGS = -O2
all: sharp  sharpparac seropt #sharp_arm 
#all: x86_orig arm_orig

SSE = -msse4.1
NEON = -mfpu=neon -flax-vector-conversions

sharp: sharpness_x86.cpp
	$(CC) $(CFLAGS) $(SSE) sharpness_x86.cpp -o sharp
sharpparac: sharpness_x86_parac.cpp
	$(CC) $(CFLAGS) $(SSE) sharpness_x86_parac.cpp -o sharpparac
seropt: sharpness_ser_opt.cpp
	$(CC) $(CFLAGS) $(SSE) sharpness_ser_opt.cpp -o seropt
sharp_arm: sharpness_arm.cpp
	$(CC) $(CFLAGS) $(NEON) sharpness_arm.cpp -o sharp_arm

clean:
	rm -rf *.o sharp seropt sharp_arm sharpparac
