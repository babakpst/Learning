#include <iostream>
#include <math.h>
// Kernel function to add the elements of two arrays
__global__
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
    y[i] = x[i] + y[i];
}

int main(void)
{

  std::cout << " code begins \n";

  int N = 1<<20;
  float *x, *y;

  std::cout << " size of the vecotr: " << N << "\n";

  // Allocate Unified Memory – accessible from CPU or GPU
  cudaMallocManaged(&x, N*sizeof(float));
  cudaMallocManaged(&y, N*sizeof(float));

  std::cout << " memory allocated. \n";

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    std::cout << " Counter: " << i << "\n";
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  std::cout << " vector filled. \n";

  // Run kernel on 1M elements on the GPU
  add<<<1, 1>>>(N, x, y);
  
  std::cout << " done with the summation. \n";

  // Wait for GPU to finish before accessing on host
  cudaDeviceSynchronize();

  std::cout << " synchronization \n";

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << std::endl;

  std::cout << " error calculated \n";

  // Free memory
  cudaFree(x);
  cudaFree(y);
 
  std::cout << " End successfully. \n";
 
  return 0;
}
