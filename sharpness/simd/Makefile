CC = g++
CFLAGS = -O3
all: x86_orig
#all: x86_orig arm_orig

SSE = -msse4.1
NEON = -mfpu=neon -flax-vector-conversions

x86_orig: sharpness_x86.cpp
	$(CC) $(CFLAGS) $(SSE) sharpness_x86.cpp -o x86_orig
arm_orig: sharpness_arm.cpp
	$(CC) $(CFLAGS) $(NEON) sharpness_arm.cpp -o arm_orig

clean:
	rm -rf *.o arm_orig x86_orig
