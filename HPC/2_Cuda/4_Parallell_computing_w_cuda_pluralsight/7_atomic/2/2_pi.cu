
/*
Babak Poursartip
02/27/2021

CUDA
topic: Monte Carlo method to calculate Pi.
For a circle of radius r, surrounded by a square:

Area of circle = pi*r^2
Area of square = 4*r^2

Thus, 
pi = 4* area of circle / area of square.

which is equivalent to: 
pi = 4 * (number of pionts in the circle)/ number of points outside the square(=total number).

*/

#include <iostream>
#include "curand.h"
#include <iomanip>
#include "sm_20_atomic_functions.h"


// ==============================
__device__ int dCount = 0;

__global__ void countPoints(const float* xs, const float* ys)
{
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  
  float x = xs[idx] - 0.5f;
  float y = ys[idx] - 0.5f;
  int n = sqrtf(x*x + y*y) > 0.5f ?0:1;
  atomicAdd(&dCount, n);
}


// ==============================
int main()
{
printf(" starts \n");

const int count = 512*512;
const int size = count * sizeof(float);

cudaError_t cudaStatus;
curandStatus_t curandStatus;

curandGenerator_t gen;

curandStatus = curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);
curandSetPseudoRandomGeneratorSeed(gen, time(0));

float* x;
float* y;

cudaStatus = cudaMalloc(&x, size);
cudaStatus = cudaMalloc(&y, size);

curandStatus = curandGenerateUniform(gen, x, count);
curandStatus = curandGenerateUniform(gen, y, count);

countPoints<<<512,512>>>(x,y);

int hCount;
cudaMemcpyFromSymbol(&hCount, dCount, sizeof(int));

cudaFree(x);
cudaFree(y);

std::cout << std::setprecision(12) << " Pi is: " << (4.0f * (float)hCount/ (float)count) << std::endl;

printf(" done \n");
return 0;
} 
