
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

cudaStream_t stream1, stream2;

cudaStreamCreate(&stream1);
cudaStreamCreate(&stream2);

float *ha, *hb, *hc, *da1, *db1, *dc1, *da2, *db2, *dc2;

const int totalSize = totalCount * sizeof(float);
const int chunkSize = chunkCount * sizeof(float);

cudaMalloc(&da1, chunkSize);
cudaMalloc(&db1, chunkSize);
cudaMalloc(&dc1, chunkSize);
cudaMalloc(&da2, chunkSize);
cudaMalloc(&db2, chunkSize);
cudaMalloc(&dc2, chunkSize);

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

cudaEventRecord(start, stream1);

for (int i = 0; i < totalCount; i += chunkCount*2)
{

  /*
  if ((i%2) == 0)
  {
  cudaMemcpyAsync(da1, ha+i, chunkSize, cudaMemcpyHostToDevice, stream1);
  cudaMemcpyAsync(db1, ha+i, chunkSize, cudaMemcpyHostToDevice, stream1);  
  kernel<<<chunkCount/64,64,0,stream1>>>(da1, db1, dc1);
  cudaMemcpyAsync(hc+i, dc1, chunkSize, cudaMemcpyHostToDevice, stream1);  
  }
  else
  {
  cudaMemcpyAsync(da2, ha+i, chunkSize, cudaMemcpyHostToDevice, stream2);
  cudaMemcpyAsync(db2, ha+i, chunkSize, cudaMemcpyHostToDevice, stream2);  
  kernel<<<chunkCount/64,64,0,stream2>>>(da2, db2, dc2);
  cudaMemcpyAsync(hc+i, dc2, chunkSize, cudaMemcpyHostToDevice, stream2);  
  }
  */
  cudaMemcpyAsync(da1, ha+i, chunkSize, cudaMemcpyHostToDevice, stream1);
  cudaMemcpyAsync(da2, ha+i+chunkCount, chunkSize, cudaMemcpyHostToDevice, stream2);
  cudaMemcpyAsync(db1, ha+i, chunkSize, cudaMemcpyHostToDevice, stream1);  
  cudaMemcpyAsync(db2, ha+i+chunkCount, chunkSize, cudaMemcpyHostToDevice, stream2);  
  kernel<<<chunkCount/64,64,0,stream1>>>(da1, db1, dc1);
  kernel<<<chunkCount/64,64,0,stream2>>>(da2, db2, dc2);
  cudaMemcpyAsync(hc+i, dc1, chunkSize, cudaMemcpyHostToDevice, stream1);
  cudaMemcpyAsync(hc+i+chunkCount, dc2, chunkSize, cudaMemcpyHostToDevice, stream2);

}

cudaStreamSynchronize(stream1);
cudaStreamSynchronize(stream2);

cudaEventRecord(end, stream1);
cudaEventSynchronize(end);

float elapsed;
cudaEventElapsedTime(&elapsed, start, end);

std::cout << " it took(ms): " << elapsed << std::endl;

cudaFreeHost(ha);
cudaFreeHost(hb);
cudaFreeHost(hc);

cudaFree(da1);
cudaFree(db1);
cudaFree(dc1);

cudaFree(da2);
cudaFree(db2);
cudaFree(dc2);

cudaStreamDestroy(stream1);
cudaStreamDestroy(stream2);

printf(" done \n");
return 0;
} 
