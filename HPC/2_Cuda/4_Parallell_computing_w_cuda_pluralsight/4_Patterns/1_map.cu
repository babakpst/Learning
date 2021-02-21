
#include <cstdio>
#include <ctime>
#include <iostream>

#include "curand.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

// ==============================
__global__ void add10(float *d, int count)
{
int threadsPerBlock        = blockDim.x * blockDim.y * blockDim.z;
int threadPositionInBlock = threadIdx.x +
                            blockDim.x * threadIdx.y +
                            blockDim.x * blockDim.y * threadIdx.z;

int blockPositionInGrid   = blockIdx.x +
                            gridDim.x * blockIdx.y +
                            gridDim.x * gridDim.y * blockIdx.z;

int tid = blockPositionInGrid * threadsPerBlock + threadPositionInBlock;
if (tid < count)
  d[tid] += 11;

}

// ==============================
int main()
{
printf(" starts \n");

curandGenerator_t gen;
curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);
curandSetPseudoRandomGeneratorSeed(gen, time(0));

const int count = 123456;
const int size = count * sizeof(float);
float *d;
float h[count];

cudaMalloc(&d, size);
curandGenerateUniform(gen, d, count);

dim3 block(8,8,8); 
dim3 grid(16,16);

add10<<<grid,block>>>(d, count);

cudaMemcpy(h, d, size, cudaMemcpyDeviceToHost);
cudaFree(d);

for (int i = 0; i < 100; ++i)
  printf(" %f ", h[i]);

printf(" done \n");
return 0;
}
