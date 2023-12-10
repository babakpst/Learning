
#include <cstdio>


__global__ void AKernel(double *d_darr, int *d_iarr, int intSize, int doubleSize) 
{ 
  extern __shared__ int TwoArrays[]; 
  int *iarr = &TwoArrays[0];
  double *darr = (double*) &TwoArrays[intSize];

  int idx = threadIdx.x;
  iarr[idx] = d_iarr[idx] * 2;
  darr[idx] = d_darr[idx] * 2;

  d_iarr[idx] = iarr[idx];
  d_darr[idx] = darr[idx];
} 


int main()
{
  int intSize = 64;
  int doubleSize = 64;
  int size = intSize*sizeof(int) + doubleSize*sizeof(double);

  int *h_iarr = new int[intSize];
  double *h_darr = new double[doubleSize];

  for (int i = 0; i<intSize; ++i)
    h_iarr[i] = i;

  for (int i = 0; i<doubleSize; ++i)
    h_darr[i] = i*0.1;

  printf(" new values \n");
  printf(" integer: \n");
  for (int i = 0; i<intSize; ++i)
    printf( "%d ", h_iarr[i]);
  printf("\n");
  
  printf(" double: \n");
  for (int i = 0; i<doubleSize; ++i)
    printf( "%f ", h_darr[i]);
  printf("\n");

  int *d_iarr;
  cudaMalloc((void**)&d_iarr, intSize*sizeof(int));
  
  double *d_darr;
  cudaMalloc((void**)&d_darr, doubleSize*sizeof(double));

  cudaMemcpy(d_iarr, h_iarr, intSize*sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_darr, h_darr, doubleSize*sizeof(double), cudaMemcpyHostToDevice);

  dim3 blocks(64,1,1);
  dim3 grids(1,1,1);

  AKernel<<<grids,blocks,size>>>(d_darr, d_iarr, intSize, doubleSize);
  cudaDeviceSynchronize();

  cudaMemcpy(h_iarr, d_iarr, intSize*sizeof(int), cudaMemcpyDeviceToHost);
  cudaMemcpy(h_darr, d_darr, doubleSize*sizeof(double), cudaMemcpyDeviceToHost);

  cudaDeviceReset();
  
  printf(" new values \n");
  printf(" integer: \n");
  for (int i = 0; i<intSize; ++i)
    printf( "%d ", h_iarr[i]);
  printf("\n");
  
  printf(" double: \n");
  for (int i = 0; i<doubleSize; ++i)
    printf( "%f ", h_darr[i]);
  printf("\n");

  printf(" end of the code\n");
  return 0; 
}