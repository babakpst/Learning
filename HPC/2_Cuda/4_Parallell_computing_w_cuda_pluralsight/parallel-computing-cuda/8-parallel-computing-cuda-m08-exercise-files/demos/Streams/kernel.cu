#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int chunkCount = 1 << 20;
const int totalCount = chunkCount << 3;

// does c = erff(a+b)
__global__ void kernel(float* a, float* b, float* c)
{
  int tid = blockDim.x*blockIdx.x + threadIdx.x;
  if (tid < chunkCount)
    c[tid] = erff(a[tid] + b[tid]);
}



// 88 msec
int main1()
{
  cudaDeviceProp prop;
  int device;
  cudaGetDevice(&device);
  cudaGetDeviceProperties(&prop, device);
  if (!prop.deviceOverlap)
  {
    cout << "This won't work" << endl;
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

  // allocate memory
  cudaMalloc(&da, chunkSize);
  cudaMalloc(&db, chunkSize);
  cudaMalloc(&dc, chunkSize);
  cudaHostAlloc(&ha, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hb, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hc, totalSize, cudaHostAllocDefault);

  // fill a and b with noise
  srand((unsigned)time(0));
  for (int i = 0; i < totalCount; i++)
  {
    ha[i] = rand() / RAND_MAX;
    hb[i] = rand() / RAND_MAX;
  }

  cudaEventRecord(start, stream);

  for (int i = 0; i < totalCount; i+= chunkCount)
  {
    cudaMemcpyAsync(da,ha+i,chunkSize,cudaMemcpyHostToDevice,stream);
    cudaMemcpyAsync(db,hb+i,chunkSize,cudaMemcpyHostToDevice,stream);
    kernel<<<chunkCount/64,64,0,stream>>>(da,db,dc);
    cudaMemcpyAsync(hc+i,dc,chunkSize,cudaMemcpyDeviceToHost,stream);
  }

  cudaStreamSynchronize(stream);

  cudaEventRecord(end, 0);
  cudaEventSynchronize(end);
  float elapsed;
  cudaEventElapsedTime(&elapsed, start, end);

  cout << "This took " << elapsed << " msec" << endl;

  cudaFreeHost(ha);
  cudaFreeHost(hb);
  cudaFreeHost(hc);
  cudaFree(da);
  cudaFree(db);
  cudaFree(dc);
  cudaStreamDestroy(stream);

  getchar();
}

int main()
{
  cudaDeviceProp prop;
  int device;
  cudaGetDevice(&device);
  cudaGetDeviceProperties(&prop, device);
  if (!prop.deviceOverlap)
  {
    cout << "This won't work" << endl;
    return 0;
  }

  cudaEvent_t start, end;
  cudaEventCreate(&start);
  cudaEventCreate(&end);

  cudaStream_t stream1, stream2;
  cudaStreamCreate(&stream1);
  cudaStreamCreate(&stream2);

  float *ha, *hb, *hc, *d1a, *d1b, *d1c, *d2a, *d2b, *d2c;
  const int totalSize = totalCount * sizeof(float);
  const int chunkSize = chunkCount * sizeof(float);

  // allocate memory
  cudaMalloc(&d1a, chunkSize);
  cudaMalloc(&d1b, chunkSize);
  cudaMalloc(&d1c, chunkSize);
  cudaMalloc(&d2a, chunkSize);
  cudaMalloc(&d2b, chunkSize);
  cudaMalloc(&d2c, chunkSize);
  cudaHostAlloc(&ha, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hb, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hc, totalSize, cudaHostAllocDefault);

  // fill a and b with noise
  srand((unsigned)time(0));
  for (int i = 0; i < totalCount; i++)
  {
    ha[i] = rand() / RAND_MAX;
    hb[i] = rand() / RAND_MAX;
  }

  cudaEventRecord(start, stream1);

  for (int i = 0; i < totalCount; i += chunkCount*2)
  {
    cudaMemcpyAsync(d1a,ha+i,chunkSize,cudaMemcpyHostToDevice,stream1);
    cudaMemcpyAsync(d1b,hb+i,chunkSize,cudaMemcpyHostToDevice,stream1);
    cudaMemcpyAsync(d2a,ha+i+chunkCount,chunkSize,cudaMemcpyHostToDevice,stream2);
    cudaMemcpyAsync(d2b,hb+i+chunkCount,chunkSize,cudaMemcpyHostToDevice,stream2);
    kernel<<<chunkCount/64,64,0,stream1>>>(d1a,d1b,d1c);
    kernel<<<chunkCount/64,64,0,stream1>>>(d2a,d2b,d2c);
    cudaMemcpyAsync(hc+i,d1c,chunkSize,cudaMemcpyDeviceToHost,stream1);
    cudaMemcpyAsync(hc+i+chunkCount,d2c,chunkSize,cudaMemcpyDeviceToHost,stream2);
  }

  cudaStreamSynchronize(stream1);
  cudaStreamSynchronize(stream2);

  cudaEventRecord(end, 0);
  cudaEventSynchronize(end);
  float elapsed;
  cudaEventElapsedTime(&elapsed, start, end);

  cout << "This took " << elapsed << " msec" << endl;

  cudaFreeHost(ha);
  cudaFreeHost(hb);
  cudaFreeHost(hc);
  cudaFree(d1a);
  cudaFree(d1b);
  cudaFree(d1c);
  cudaFree(d2a);
  cudaFree(d2b);
  cudaFree(d2c);
  cudaStreamDestroy(stream1);
  cudaStreamDestroy(stream2);

  getchar();
}

// also 88 msec :(
int main2()
{
  cudaDeviceProp prop;
  int device;
  cudaGetDevice(&device);
  cudaGetDeviceProperties(&prop, device);
  if (!prop.deviceOverlap)
  {
    cout << "This won't work" << endl;
    return 0;
  }

  cudaEvent_t start, end;
  cudaEventCreate(&start);
  cudaEventCreate(&end);

  cudaStream_t stream1, stream2;
  cudaStreamCreate(&stream1);
  cudaStreamCreate(&stream2);

  float *ha, *hb, *hc, *d1a, *d1b, *d1c, *d2a, *d2b, *d2c;
  const int totalSize = totalCount * sizeof(float);
  const int chunkSize = chunkCount * sizeof(float);

  // allocate memory
  cudaMalloc(&d1a, chunkSize);
  cudaMalloc(&d1b, chunkSize);
  cudaMalloc(&d1c, chunkSize);
  cudaMalloc(&d2a, chunkSize);
  cudaMalloc(&d2b, chunkSize);
  cudaMalloc(&d2c, chunkSize);
  cudaHostAlloc(&ha, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hb, totalSize, cudaHostAllocDefault);
  cudaHostAlloc(&hc, totalSize, cudaHostAllocDefault);

  // fill a and b with noise
  srand((unsigned)time(0));
  for (int i = 0; i < totalCount; i++)
  {
    ha[i] = rand() / RAND_MAX;
    hb[i] = rand() / RAND_MAX;
  }

  cudaEventRecord(start, stream1);

  for (int i = 0; i < totalCount; i+= chunkCount)
  {
    if ((i % 2) == 0)
    {
      cudaMemcpyAsync(d1a,ha+i,chunkSize,cudaMemcpyHostToDevice,stream1);
      cudaMemcpyAsync(d1b,hb+i,chunkSize,cudaMemcpyHostToDevice,stream1);
      kernel<<<chunkCount/64,64,0,stream1>>>(d1a,d1b,d1c);
      cudaMemcpyAsync(hc+i,d1c,chunkSize,cudaMemcpyDeviceToHost,stream1);
    } 
    else 
    {
      cudaMemcpyAsync(d2a,ha+i,chunkSize,cudaMemcpyHostToDevice,stream2);
      cudaMemcpyAsync(d2b,hb+i,chunkSize,cudaMemcpyHostToDevice,stream2);
      kernel<<<chunkCount/64,64,0,stream2>>>(d2a,d2b,d2c);
      cudaMemcpyAsync(hc+i,d2c,chunkSize,cudaMemcpyDeviceToHost,stream2);
    }
  }

  cudaStreamSynchronize(stream1);
  cudaStreamSynchronize(stream2);

  cudaEventRecord(end, 0);
  cudaEventSynchronize(end);
  float elapsed;
  cudaEventElapsedTime(&elapsed, start, end);

  cout << "This took " << elapsed << " msec" << endl;

  cudaFreeHost(ha);
  cudaFreeHost(hb);
  cudaFreeHost(hc);
  cudaFree(d1a);
  cudaFree(d1b);
  cudaFree(d1c);
  cudaFree(d2a);
  cudaFree(d2b);
  cudaFree(d2c);
  cudaStreamDestroy(stream1);
  cudaStreamDestroy(stream2);

  getchar();
}