
// Babak Poursartip
// 02/6/2021

// CUDA
//topic: gather
// y = f(a_m, b_n, ... )

// black scholes (option price) 

#define _USE_MATH_DEFINES
#include "cstdio"
#include "curand.h"
#include <math.h> 

// ====================================
__device__ __host__ __inline__ float N(float x)
{
  return 0.5+0.5*erf(x* M_SQRT1_2);
}

// ====================================
__device__ __host__ void price(float k, float s, float t, float r, float v, float *c, float *p)
{
	float srt = v * sqrtf(t);
	float d1 = (logf(s/k)+(r+0.5*v*v)*t) / srt;
	float d2 = d1 - srt;
	float kert = k * expf(-r*t);
	*c = N(d1)*s - N(d2)*kert;
	*p = kert - s + *c;
}


// ====================================
__global__ void price(float *k, float *s, float *t, float *r, float *v, float *c, float *p )
{
  int idx = threadIdx.x;
  price(k[idx], s[idx], t[idx], r[idx], v[idx], &c[idx], &p[idx]);
}


// ====================================
int main(){

printf(" starts ... \n");

  const int count = 512;  //no of elements
  const int size = count * sizeof(float);
  float *args[5];

  curandGenerator_t gen;
  curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);

    for (int i = 0; i < 5; ++i)
    {
      cudaMalloc(&args[i], size);
      curandGenerateUniform(gen, args[i], count);
    }

  float *dc, *dp;
  cudaMalloc(&dc, size);
  cudaMalloc(&dp, size);

  price<<<1, count>>>(args[0], args[1], args[2], args[3], args[4], dc, dp);


printf(" done. \n");
return 0;
}



