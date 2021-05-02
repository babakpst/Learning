
/*
Babak Poursartip
02/27/2021

CUDA
topic: stream.

- Instead of using malloc or new to allocation memory on the CPU(host), we use cudaHostAlloc(). This will allocate a pinned memory on the host.

- To free the memory, we use cudaFreeHost, instead of delete to deallocate. 

- The disadvantage is that you cannot swap the memory to the disk & we need to have enough memory to use this memory. 

*/

#include <iostream>
#include <cmath>
#include <ctime>


// ==============================
const int chunkCount = 1 << 20;
const int totalCount = chunkCount << 3;

__global__ void kernel(float *a, float *b, float *c)
{
  int tid = blockDim.x * blockIdx.x+threadIdx.x;
  if (tid < chunkCount)
    c[tid] = erff(a[tid]+b[tid]);
 
}

// ==============================
int main()
{
printf(" starts \n");


cudaDeviceProp prop;
int device;

cudaGetDevice(&device);
cudaGetDeviceProperties(&prop, device);

if (!prop.deviceOverlap)
{
  return 0;
}


cudaEvent_t start, end;
cudaEventCreate(&start);
cudaEventCreate(&end);

cudaStream_t stream;

cudaStreamCreate(&stream);

float *ha, *hb, *hc, *da, *db, *dc;

const int totalSize = totalCount * sizeof(float);
const int chunkSize = chunkCount * sizeof(float);

cudaMalloc(&da, chunkSize);
cudaMalloc(&db, chunkSize);
cudaMalloc(&dc, chunkSize);

cudaHostAlloc(&ha, totalSize, cudaHostAllocDefault);
cudaHostAlloc(&hb, totalSize, cudaHostAllocDefault);
cudaHostAlloc(&hc, totalSize, cudaHostAllocDefault);


srand((unsigned)time(0));

// random numbers for the two input vectors
for (int i = 0; i < totalCount; ++i)
{
  ha[i] = rand() / RAND_MAX;
  hb[i] = rand() / RAND_MAX;
}

cudaEventRecord(start, stream);

for (int i = 0; i < totalCount; i += chunkCount)
{
  cudaMemcpyAsync(da, ha+i, chunkSize, cudaMemcpyHostToDevice, stream);
  cudaMemcpyAsync(db, ha+i, chunkSize, cudaMemcpyHostToDevice, stream);  
  kernel<<<chunkCount/64,64,0,stream>>>(da, db, dc);
  cudaMemcpyAsync(hc+i, dc, chunkSize, cudaMemcpyHostToDevice, stream);    
}

cudaStreamSynchronize(stream);
cudaEventRecord(end, stream);
cudaEventSynchronize(end);

float elapsed;
cudaEventElapsedTime(&elapsed, start, end);

std::cout << " it took(ms): " << elapsed << std::endl;

cudaFreeHost(ha);
cudaFreeHost(hb);
cudaFreeHost(hc);

cudaFree(da);
cudaFree(db);
cudaFree(dc);

cudaStreamDestroy(stream);

printf(" done \n");
return 0;
} 
