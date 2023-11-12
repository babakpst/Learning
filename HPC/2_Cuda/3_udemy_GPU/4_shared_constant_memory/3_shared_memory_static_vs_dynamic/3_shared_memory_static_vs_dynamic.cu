
#include <stdio.h>
#include <stdlib.h> // why do we need this?
#include <time.h>   
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "common.h"


// profile
// sudo nvprof --metrics shared_load_transactions_per_request,shared_store_transactions_per_request ./bin/main

// we have to use these directive to allocate static shared memory
#define NX 32
#define NY 32

// =============================================================
// kernel to store in shared memore in row major format (no bank conflict), 
// but read in the col major format (bank conflict).
__global__ void storeRow_ReadColDYN(int *out)
{
  extern __shared__ int tile[];  // row major format
  
  int row_idx = threadIdx.y * blockDim.x + threadIdx.x;
  int col_idx = threadIdx.x * blockDim.y + threadIdx.y;

  // store/fill the array on shared memory
  // NOTICE the order of threads in the matrix
  tile[row_idx] = row_idx; // store operation-row major
  // printf("number:  %s\n",tile[threadIdx.y][threadIdx.x]);
  
  __syncthreads();
  // printf("number:  %s\n", idx);
  
  // load from the shared memory and write in the global memory
  // bank conflict: all threads from a warp are loading from one banch.
  out[row_idx] = tile[col_idx];
  // printf("number:  %s\n", out[idx]);
  // __syncthreads;
}

// =============================================================
// wirte in the shared memory in the col major order, 
// and read from the memory in the row major order.
__global__ void storeCol_ReadRowDYN(int *out)
{
  extern __shared__ int tile[];  // row major format
  
  int row_idx = threadIdx.y * blockDim.x + threadIdx.x;
  int col_idx = threadIdx.x * blockDim.y + threadIdx.y;

  // store/fill the array on shared memory
  // NOTICE the order of threads in the matrix
  // all threads from warp are storing from one bank
  tile[col_idx] = row_idx; // store operation-row major

  __syncthreads();

  // load from the shared memory and write in the global memory
  out[row_idx] = tile[row_idx];
}


// =============================================================
// wirte in the shared memory in the row major order, 
// and read from the memory in the row major order.
__global__ void storeRow_ReadRowDYN(int *out)
{
  extern __shared__ int tile[];  // row major format
  
  int row_idx = threadIdx.y * blockDim.x + threadIdx.x;
  int col_idx = threadIdx.x * blockDim.y + threadIdx.y;
  // store/fill the array on shared memory
  // NOTICE the order of threads in the matrix
  tile[row_idx] = row_idx; // store operation-row major

  __syncthreads();

  // load from the shared memory and write in the global memory
  out[row_idx] = tile[row_idx];
}


int main(int argc, char* argv[])
{
  int mem_config = 0; // 0: 32 bit bank width, 1: 64 bank width
  
  if (argc>1) mem_config = atoi(argv[1]);

  if (mem_config==1) // 64 bit bank width
    cudaDeviceSetSharedMemConfig(cudaSharedMemBankSizeEightByte);
  else if (mem_config == 0)  // 32 bit bank width
    cudaDeviceSetSharedMemConfig(cudaSharedMemBankSizeFourByte);

  cudaSharedMemConfig pConfig;
  cudaDeviceGetSharedMemConfig(&pConfig);
  printf("GPU bank setting %s\n", pConfig==1?"4-Byte width":"8-Byte width");

  int nx = 32;
  int ny = 32;

  bool iprintf = 0;

  if (argc > 2) iprintf = atoi(argv[2]);

  int byteSize = nx * ny * sizeof(int);

  dim3 block(nx,ny);
  dim3 grid(1,1);

  printf(" grid block: (%d, %d), thread block: (%d, %d)\n", block.x, block.y, grid.x, grid.y);

  int *ref = (int *)malloc(byteSize);
  
  int *d_C; 
  cudaMalloc((int**)&d_C, byteSize);
  
  clock_t start, end;

  cudaMemset(&d_C, 0, byteSize);
  start = clock();
  storeRow_ReadColDYN<<<grid, block, byteSize>>>(d_C);
  cudaDeviceSynchronize();
  end = clock();
  cudaMemcpy(ref, d_C, byteSize, cudaMemcpyDeviceToHost);
  if (iprintf) printArray(" store row - read col: ", ref, nx*ny, nx);
  printf(" execution time: %4.6f \n", (double)((double)(end - start) / CLOCKS_PER_SEC));

  cudaMemset(&d_C, 0, byteSize);
  start = clock();
  storeCol_ReadRowDYN<<<grid, block, byteSize>>>(d_C);
  cudaDeviceSynchronize();
  end = clock();
  cudaMemcpy(ref, d_C, byteSize, cudaMemcpyDeviceToHost);
  if (iprintf) printArray(" store col - read row: ", ref, nx*ny, nx);
  printf(" execution time: %4.6f \n", (double)((double)(end - start) / CLOCKS_PER_SEC));

  cudaMemset(&d_C, 0, byteSize);
  start = clock();
  storeRow_ReadRowDYN<<<grid, block, byteSize>>>(d_C);
  cudaDeviceSynchronize();
  end = clock();
  cudaMemcpy(ref, d_C, byteSize, cudaMemcpyDeviceToHost);
  if (iprintf) printArray(" store row - read row: ", ref, nx*ny, nx);
  printf(" execution time: %4.6f \n", (double)((double)(end - start) / CLOCKS_PER_SEC));

  cudaFree(d_C);
  free(ref);

  cudaDeviceReset();
  return 0;
}

