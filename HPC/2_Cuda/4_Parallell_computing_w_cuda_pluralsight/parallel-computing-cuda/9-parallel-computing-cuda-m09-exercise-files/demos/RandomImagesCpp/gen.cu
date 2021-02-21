#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cmath>
using namespace std;

__device__ __inline__ float trim(unsigned char value)
{
  return fminf((unsigned char)255, fmaxf(value, (unsigned char)0));
}

__device__ __inline__ float poly(float x, float a, float b, float c)
{
  return a*x*x*x+b*x*x+c*x;
}

__global__ void kernel(unsigned char* img, const float* a)
{
  int ix = blockIdx.x;
  int iy = threadIdx.x;
  int tid = iy*blockDim.x + ix;

  float x = (float)ix / blockDim.x;
  float y = (float)iy / gridDim.x;

  //placeholder

  img[tid*4+0] = trim(poly(z,a[0],a[1],a[2]) * 255.0f);
  img[tid*4+1] = trim(poly(z,a[3],a[4],a[5]) * 255.0f);
  img[tid*4+2] = trim(poly(z,a[6],a[7],a[8]) * 255.0f);
  img[tid*4+3] = 255;
}