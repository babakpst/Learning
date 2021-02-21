
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <curand.h>
using namespace std;







__device__ __host__ __inline__ float N(float x)
{
	return 0.5 + 0.5*erf(x*M_SQRT1_2);
}


__device__ __host__ void price(float k, float s, float t, float r, float v, float* c, float* p)
{
	float srt = v * sqrtf(t);
	float d1 = (logf(s/k)+(r+0.5*v*v)*t) / srt;
	float d2 = d1 - srt;
	float kert = k * expf(-r*t);
	*c = N(d1)*s - N(d2)*kert;
	*p = kert - s + *c;
}



__global__ void price(float* k, float* s, float* t, float* r, float* v, float* c, float* p)
{
	int idx = threadIdx.x;
	price(k[idx], s[idx], t[idx], r[idx], v[idx], &c[idx], &p[idx]);
}



int main()
{


	const int count = 512;
	curandStatus_t curandStatus;
	cudaError_t cudaError;
	float* args[5];
	curandGenerator_t gen;
	curandStatus = curandCreateGenerator(&gen, curandRngType_t::CURAND_RNG_PSEUDO_MTGP32);
	for (int i = 0; i < 5; ++i) 
	{
		cudaMalloc(&args[i], sizeof(float)*1024);
		curandStatus = curandGenerateUniform(gen, args[i], count);
	}

	float *dc, *dp;
	cudaError = cudaMalloc(&dc, count*sizeof(float));
	cudaError = cudaMalloc(&dp, count*sizeof(float));

	price<<<1,count>>>(args[0], args[1], args[2], args[3], args[4], dc, dp);

	float hc[count] = { 0 };
	float hp[count] = { 0 };
	cudaMemcpy(hc, dc, sizeof(float)*count, cudaMemcpyKind::cudaMemcpyDeviceToHost);
	cudaMemcpy(hp, dp, sizeof(float)*count, cudaMemcpyKind::cudaMemcpyDeviceToHost);

	cudaFree(dc);
	cudaFree(dp);
	for (int i = 0; i < 5; ++i)
		cudaFree(&args[i]);
	cudaDeviceReset();
  return 0;
}

