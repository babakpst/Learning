#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
using namespace std;

float timeMemory(bool pinned, bool toDevice)
{
  const int count = 1 << 20;
  const int iterations = 1 << 6;
  const int size = count * sizeof(int);
  cudaEvent_t start, end;
  int *h, *d;
  float elapsed;
  cudaError_t status;

  cudaEventCreate(&start);
  cudaEventCreate(&end);

  cudaMalloc(&d, size);
  if (pinned)
    cudaHostAlloc(&h, size, cudaHostAllocDefault);
  else
    h = new int[count];

  cudaEventRecord(start);

  for (int i = 0; i < iterations; i++)
  {
    if (toDevice)
      status = cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);
    else
      status = cudaMemcpy(h, d, size, cudaMemcpyDeviceToHost);
  }

  cudaEventRecord(end);
  cudaEventSynchronize(end);
  cudaEventElapsedTime(&elapsed, start, end);

  if (pinned)
    cudaFreeHost(h);
  else
    delete [] h;

  cudaFree(d);
  cudaEventDestroy(start);
  cudaEventDestroy(end);

  return elapsed;
}

int main()
{
  cout << "From device, paged memory:\t" << timeMemory(false, false) << endl;
  cout << "To device,   paged memory:\t" << timeMemory(false, true) << endl;
  cout << "From device, pinned memory:\t" << timeMemory(true, false) << endl;
  cout << "To device,   pinned memory:\t" << timeMemory(true, true) << endl;

  getchar();
  return 0;
}