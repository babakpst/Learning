
#include <stdio.h>
#include <assert.h>

// ======================================================
inline cudaError_t checkCuda(cudaError_t result)
{
  if (result != cudaSuccess) {
    fprintf(stderr, "CUDA Runtime Error: %s\n", cudaGetErrorString(result));
    assert(result == cudaSuccess);
  }
  return result;
}

// ======================================================
void initWith(float num, float *a, int N)
{
  for(int i = 0; i < N; ++i)
  {
    a[i] = num;
  }
}

// ======================================================
__global__
void addVectorsInto(float *result, float *a, float *b, int N)
{
  int ind = threadIdx.x + blockDim.x * blockIdx.x; // stride
  int gridSize = blockDim.x * gridDim.x;
  
  for(int i = ind; i < N; i+=gridSize)
  {
    result[i] = a[i] + b[i];
  }
}

// ======================================================
void checkElementsAre(float target, float *array, int N)
{
  for(int i = 0; i < N; i++)
  {
    if(array[i] != target)
    {
      printf("FAIL: array[%d] - %0.0f does not equal %0.0f\n", i, array[i], target);
      exit(1);
    }
  }
  printf("SUCCESS! All values added correctly.\n");
}

// ======================================================
int main()
{
  const int N = 2<<20;
  size_t size = N * sizeof(float);

  float *a;
  float *b;
  float *c;

  //a = (float *)malloc(size);
  //b = (float *)malloc(size);
  //c = (float *)malloc(size);
  
  checkCuda(cudaMallocManaged(&a, size)); 
  checkCuda(cudaMallocManaged(&b, size)); 
  checkCuda(cudaMallocManaged(&c, size)); 
  

  initWith(3, a, N);
  initWith(4, b, N);
  initWith(0, c, N);

  int threadsPerBlock = 1024;
  dim3 grid((N+threadsPerBlock-1)/threadsPerBlock);
  dim3 block(threadsPerBlock);
  addVectorsInto<<<grid, block>>>(c, a, b, N);
  checkCuda(cudaGetLastError());
  checkCuda(cudaDeviceSynchronize());

  checkElementsAre(7, c, N);

  cudaFree(a);
  cudaFree(b);
  cudaFree(c);
}

