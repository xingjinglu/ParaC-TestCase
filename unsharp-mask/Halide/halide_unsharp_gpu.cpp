#include <stdio.h>
#include <emmintrin.h>
//#include <cstdlib>
#include <cassert>
//#include<algorithm>

#include "clock.h"
#include "Halide.h"
//#include "unsharp.h"

#include "../support/benchmark.h"
//#include "halide_image.h"
#include "halide_image_io.h"
#include "../support/auto_build.h"
//#include "HalideBuffer.h"



using namespace Halide;
using namespace Halide::Tools;
using namespace std;


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



class HalideUnsharp{
  public:
    //ImageParam in(Float(32), 3);
    Image<float>  in;
    // Define a 7x7 Gaussian Blur with a repeat-edge boundary condition.
    float sigma = 1.5f;
    Var x, y, c;
    Func kernel, in_bounded, gray;
    Func blur_y,  blur_x, sharpen;
    Func ratio,  unsharp;

    HalideUnsharp( Image<float>input ): in(input){

      kernel(x) = exp(-x*x/(2*sigma*sigma)) / (sqrtf(2*M_PI)*sigma);
#if 1
      in_bounded = BoundaryConditions::repeat_edge(in);
      gray(x, y) = 0.299f * in_bounded(x, y) + 0.587f * in_bounded(x, y)
        + 0.114f * in_bounded(x, y);
#endif
#if 0
      gray(x, y) = 0.299f * in(x, y) + 0.587f * in(x, y)
        + 0.114f * in(x, y);
#endif

      blur_y(x, y) = (kernel(0) * gray(x, y) +
          kernel(1) * (gray(x, y-1) +
            gray(x, y+1)) +
          kernel(2) * (gray(x, y-2) +
            gray(x, y+2)) +
          kernel(3) * (gray(x, y-3) +
            gray(x, y+3)));

      blur_x(x, y) = (kernel(0) * blur_y(x, y) +
          kernel(1) * (blur_y(x-1, y) +
            blur_y(x+1, y)) +
          kernel(2) * (blur_y(x-2, y) +
            blur_y(x+2, y)) +
          kernel(3) * (blur_y(x-3, y) +
            blur_y(x+3, y)));

      sharpen(x, y) = 2 * gray(x, y) - blur_x(x, y);

      ratio(x, y) = sharpen(x, y) / gray(x, y);

      unsharp(x, y) = ratio(x, y) * in(x, y);

      //unsharp.bound(x, 0, 1536).bound(y, 0, 2560).bound(c, 0, 3);
      unsharp.estimate(x, 0, 1536).estimate(y, 0, 2560);

    }

    // Pick a schedule
    void schedule_for_gpu(){
      printf("gpu schedule \n");
      Var xi, yi;
#if 1 
      unsharp.compute_root()
        .reorder( x, y)
        .gpu_tile(x, y, 16, 16);
      ratio.compute_at(unsharp, Var::gpu_threads());
      gray.compute_at(unsharp, Var::gpu_blocks())
        .tile(x, y, xi, yi, 2, 2)
        .unroll(xi)
        .unroll(yi)
        .gpu_threads(x, y);
      blur_y.compute_at(unsharp, Var::gpu_blocks())
        .unroll(x, 2)
        .gpu_threads(x, y);
#endif

#if 0
      unsharp.compute_root()
        .gpu_tile(x, y, 16, 16);
      gray.compute_at(unsharp, Var::gpu_blocks())
        .tile(x, y, xi, yi, 2, 2)
        .unroll(xi)
        .unroll(yi)
        .gpu_threads(x, y);
      blur_y.compute_at(unsharp, Var::gpu_blocks())
        .unroll(x, 2)
        .gpu_threads(x, y);
#endif

      Target target = get_host_target();

      if( target.os == Target::OSX ){
        target.set_feature(Target::Metal);
      }else{
        target.set_feature(Target::OpenCL);
      }

      unsharp.compile_jit(target);
    }


    void  schedule_for_cpu(){
      printf("cpu schedule \n");
#if 1
      blur_y.compute_at(unsharp, y).vectorize(x, 8);
      ratio.compute_at(unsharp, y).vectorize(x, 8);
      unsharp.vectorize(x, 8).parallel(y).reorder(x, y);

      unsharp.compile_jit();
#endif
    }


    void test_performance(){
      Image<float> output(in.width(), in.height());
      unsharp.realize(output);

      double best_time;
      int runs = 5;
      for( int i = 0; i < 3; i++){

        double t1 = current_time();

        for( int j = 0; j < runs; j++){
          unsharp.realize(output);
        }

        output.copy_to_host();

        double t2  = current_time();

        double elapsed = (t2-t1)/runs;
        if( i == 0 || elapsed < best_time ){
          best_time = elapsed;
        }

      }

      printf("%1.4f milliseconds \n", best_time);
    }

    //auto_build(unsharp, "unsharp", {in}, target, (schedule == -1 || schedule == -2));
};

int main(int argc, char **argv) {

    //Image<float> input = load_image(argv[1]);
    //Image<float> output(input.width(), input.height(), 3);
     Image<float> input(2048, 2048);

     for (int y = 0; y < input.height(); y++) {
       for (int x = 0; x < input.width(); x++) {
         input(x, y) = rand() & 0xfff;
       }
     }

     Image<float> reference_output(input.width(), input.height());

     HalideUnsharp HU(input);
     HU.schedule_for_cpu();
     HU.test_performance();
     //HU.unsharp.realize(reference_output);

     if( have_opencl_or_metal() ){
       printf("Testing performance on GPU: \n");
       HalideUnsharp HU(input);
       HU.schedule_for_gpu();
       HU.test_performance();
       HU.unsharp.realize(reference_output);
     }else{
       printf("No OpenCL test \n");
     }


    return 0;
}


