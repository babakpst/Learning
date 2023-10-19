
/*
Babak Poursartip
05/14/2020

based on Intro to parallel programming cuda

remarks:

- data on the host, starts with h (h_in)
- data on the device, starts with d (d_in)


*/

#include <stdio.h>

__global__ void cube(float*d_out, float * d_in)
{
  int idx = threadIdx.x;
  float f = d_in[idx];
  d_out[idx] = f*f*f;
}


int main(){

printf(" code starts ... \n");

const int ARRAY_SIZE = 96;
const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);

// fill the input array on the host
float h_in[ARRAY_SIZE];
for (int ii = 0; ii < ARRAY_SIZE; ii++)
  h_in[ii] = float(ii);

float h_out[ARRAY_SIZE];

// declare gpu memory pointers
float *d_in;
float *d_out;

// allocate gpu memory
cudaMalloc((void **) &d_in, ARRAY_BYTES);
cudaMalloc((void **) &d_out, ARRAY_BYTES);

// transfer the array to the GPU
cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpyHostToDevice);

// launch the kernel
cube<<<1, ARRAY_SIZE>>>(d_out, d_in);

// copy back the results in the CPU
cudaMemcpy(h_out,d_out, ARRAY_BYTES,cudaMemcpyDeviceToHost);

// print out the results
for (int ii = 0; ii < ARRAY_SIZE; ++ii)
{
  printf(" %f", h_out[ii]);
  printf( ( (ii%5) !=4 ) ? "\t":"\n" );
}

// free gpu
cudaFree(d_in);
cudaFree(d_out);

return 0;
}

