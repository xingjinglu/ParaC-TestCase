__kernel void simpleMul(
                        __global int* c,
                        __global int *a,
                        int WidthA,
                        int HeightA,
                        __global int *b,
                        int WidthB,
                        int HeightB ){

  // Get global X/Y position.
  int gidx = get_global_id(0); 
  int gidy = get_global_id(1);

  int sum = 0;

  for(int i = 0; i < WidthA; i++){
    sum += a[gidy*WidthA+i] * b[i*WidthB + gidx];
  }

  c[gidy*WidthB+gidx] = sum;
}

