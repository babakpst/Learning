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

  double z = powf(x,powf(sinhf(((((0.546098f < x ? 0.546098f : x) < sinf(x) ? (0.546098f < x ? 0.546098f : x) : sinf(x))-(sinf(y)+(0.205267f > 0.0f ? log(0.205267f) : -log(-0.205267f)))) < (sinhf((y*x)) == 0.0f ? x : 1.0f/sinhf((y*x))) ? (((0.546098f < x ? 0.546098f : x) < sinf(x) ? (0.546098f < x ? 0.546098f : x) : sinf(x))-(sinf(y)+(0.205267f > 0.0f ? log(0.205267f) : -log(-0.205267f)))) : (sinhf((y*x)) == 0.0f ? x : 1.0f/sinhf((y*x))))),sinhf((powf((powf(x,0.285562f) > 0.0f ? sqrt(powf(x,0.285562f)) : -sqrt(-powf(x,0.285562f))),((y-x)+(y == 0.f ? x : x/y)))+(((y > 0.0f ? log(y) : -log(-y)) == 0.f ? coshf(x) : coshf(x)/(y > 0.0f ? log(y) : -log(-y))) < ((y == 0.f ? x : x/y) == 0.f ? (x*y) : (x*y)/(y == 0.f ? x : x/y)) ? ((y > 0.0f ? log(y) : -log(-y)) == 0.f ? coshf(x) : coshf(x)/(y > 0.0f ? log(y) : -log(-y))) : ((y == 0.f ? x : x/y) == 0.f ? (x*y) : (x*y)/(y == 0.f ? x : x/y)))))));

  img[tid*4+0] = trim(poly(z,a[0],a[1],a[2]) * 255.0f);
  img[tid*4+1] = trim(poly(z,a[3],a[4],a[5]) * 255.0f);
  img[tid*4+2] = trim(poly(z,a[6],a[7],a[8]) * 255.0f);
  img[tid*4+3] = 255;
}