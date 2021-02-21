#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "curand.h"

#include <iostream>
#include <iomanip>
using namespace std;

__device__ int dCount = 0;

__global__ void countPoints(const float* xs, const float* ys)
{
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	float x = xs[idx] - 0.5f;
	float y = ys[idx] - 0.5f;
	int n = sqrtf(x*x + y*y) > 0.5f ? 0 : 1;
	atomicAdd(&dCount, n);
}

int main(int argc, char* argv[])
{ 
	const int count = 512*512;
	const int size = count * sizeof(float);
	cudaError_t cudaStatus;
	curandStatus_t curandStatus;
	curandGenerator_t gen;
	
	curandStatus = curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);
	curandSetPseudoRandomGeneratorSeed(gen, time(0));

	float *x;
	float *y;
	cudaStatus = cudaMalloc((void**)&x, size);
	cudaStatus = cudaMalloc((void**)&y, size);

	curandStatus = curandGenerateUniform(gen, x, count);
	curandStatus = curandGenerateUniform(gen, y, count);

	countPoints<<<512,512>>>(x, y);

	cudaDeviceSynchronize();
  
	int hCount;
	cudaMemcpyFromSymbol(&hCount, dCount, sizeof(int));


	cudaFree(x);
	cudaFree(y);

	cudaDeviceReset();

	cout << setprecision(12)
		  << "Pi is approximately " 
		  << (4.0f * (float)hCount / (float)count)
		  << endl;

  getchar();

	return 0;
}