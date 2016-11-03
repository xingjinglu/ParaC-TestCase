#include "Halide.h"
#include <stdio.h>
#include <emmintrin.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include "clock.h"

#include "../support/benchmark.h"
#include "HalideBuffer.h"


using namespace Halide;

#include "halide_image_io.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif


bool have_opencl_or_metal() {
#ifdef _WIN32
    return LoadLibrary("OpenCL.dll") != NULL;
#elif __APPLE__
    return dlopen("/System/Library/Frameworks/Metal.framework/Versions/Current/Metal", RTLD_LAZY) != NULL;
#else
    return dlopen("libOpenCL.so", RTLD_LAZY) != NULL;
#endif
}



double t;

//class HalideBlur : public Halide::Generator<HalideBlur> {
class HalideBlur {
public:
    Func blur_x, blur_y;
    Image<uint16_t> input;
    Var x, y, xi, yi, i, y_inner,y_outer, x_inner, x_outer;
    // ImageParam input{UInt(16), 2, "input"};

   HalideBlur( Image<uint16_t> in) : input(in) {
        //Func blur_x("blur_x"), blur_y("blur_y");
        //Var x("x"), y("y"), xi("xi"), yi("yi");

        // The algorithm
        blur_x(x, y) = (input(x, y) + input(x+1, y) + input(x+2, y))/3;
        blur_y(x, y) = (blur_x(x, y) + blur_x(x, y+1) + blur_x(x, y+2))/3;


        //return blur_y;
    }


   void schedule_for_cpu(){

     blur_x.compute_root();

     blur_y.split(y, y, yi, 8).parallel(y).vectorize(x, 8);
     blur_x.store_at(blur_y, y).compute_at(blur_y, yi).vectorize(x, 8);

     blur_y.compile_jit();

   }

   void schedule_for_gpu(){

     //blur_x.compute_root();

     // 16-wide one-dimensional thread blocks. First we split the 
     // index into blocks of size 16.
     Var block, thread;

#if 1
     //blur_x.compute_root().vectorize(y,8); // works.
     //blur_x.vectorize(y_outer, 4); // works.

    // blur_x.compute_root().vectorize(x, 8).gpu_tile(x, y, 4, 8);

#if 1
     // Best schedule until now.
     blur_x.compute_root().gpu_tile(x, y, 8, 8); 
     blur_y.gpu_tile(x, y, 8, 8);
#endif

#if 0
     // Schedule advised by Adams.
     blur_y.gpu_tile(x, y, 8, 8);
#endif

#endif

      //blur_x.gpu_threads(x, y);
     //

      Target target = get_host_target();

      if( target.os == Target::OSX ){
        target.set_feature(Target::Metal);
      }else{
         target.set_feature(Target::OpenCL);
      }
      
      blur_y.compile_jit(target);
   }


   void test_performance(){
     Image<uint16_t> output(input.width()-8, input.height()-2);
     blur_y.realize(output);

     // Now take the best of 3 runs for timing.
     double best_time;
     int runs = 5;
     for (int i = 0; i < 3; i++) {

       double t1 = current_time();

       // Run the filter 100 times.
       for (int j = 0; j < runs; j++) {
         blur_y.realize(output);
       }

       // Force any GPU code to finish by copying the buffer back to the CPU.
       output.copy_to_host();

       double t2 = current_time();

       double elapsed = (t2 - t1)/runs;
       if (i == 0 || elapsed < best_time) {
         best_time = elapsed;
       }
     }
     printf("%1.4f milliseconds\n", best_time);

   }

};


int main(int argc, char **argv) {

    Image<uint16_t> input(6408, 4802);

    for (int y = 0; y < input.height(); y++) {
        for (int x = 0; x < input.width(); x++) {
            input(x, y) = rand() & 0xfff;
        }
    }

    // Allocated an image that will store the correct output
    Image<uint16_t> reference_output(input.width()-8, input.height()-2);

     HalideBlur HB(input);
     HB.schedule_for_cpu();
     HB.test_performance();
     HB.blur_y.realize(reference_output);

     if( have_opencl_or_metal() ){
       printf("Testing performance on GPU: \n");
       HalideBlur HB(input);
       HB.schedule_for_gpu();
       HB.test_performance();
       HB.blur_y.realize(reference_output);
     }else{
       printf("No OpenCL test \n");
     }


    return 0;
}


