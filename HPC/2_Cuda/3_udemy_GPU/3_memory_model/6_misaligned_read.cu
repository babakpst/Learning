#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

/* 

with L1 cache
To enable L1 cache read, use this flag: -Xptxas -dlcm=ca. So, memory access word length is 128 Bytes.
$ nvcc -Xptxas -dlcm=ca -o 6_misaligned_read 6_misaligned_read.cu
$ sudo nvprof --metrics gld_efficiency,gld_transactions ./6_misaligned_read

>>>> output with offset 0:
Invocations                               Metric Name                        Metric Description         Min         Max         Avg
Device "NVIDIA GeForce GT 1030 (0)"
    Kernel: misaligned_read_test(float*, float*, float*, int, int)
          1                            gld_efficiency             Global Memory Load Efficiency     100.00%     100.00%     100.00%
          1                          gld_transactions                  Global Load Transactions    33554434    33554434    33554434

>>>> output with offset 22:
Invocations                               Metric Name                        Metric Description         Min         Max         Avg
Device "NVIDIA GeForce GT 1030 (0)"
    Kernel: misaligned_read_test(float*, float*, float*, int, int)
          1                            gld_efficiency             Global Memory Load Efficiency      80.00%      80.00%      80.00%
          1                          gld_transactions                  Global Load Transactions    33554418    33554418    33554418

without L1 cache:

/* To disable L1 cache read, use this flag: -Xptxas -dlcm=ca. So, memory access word length is 32 Bytes.
$ nvcc -Xptxas -dlcm=cg -o 6_misaligned_read 6_misaligned_read.cu
$  sudo nvprof --metrics gld_efficiency,gld_transactions ./6_misaligned_read

>>>> output with offset 0:
Invocations                               Metric Name                        Metric Description         Min         Max         Avg
Device "NVIDIA GeForce GT 1030 (0)"
    Kernel: misaligned_read_test(float*, float*, float*, int, int)
          1                            gld_efficiency             Global Memory Load Efficiency     100.00%     100.00%     100.00%
          1                          gld_transactions                  Global Load Transactions    33554434    33554434    33554434

>>>> output with offset 22:
Invocations                               Metric Name                        Metric Description         Min         Max         Avg
Device "NVIDIA GeForce GT 1030 (0)"
    Kernel: misaligned_read_test(float*, float*, float*, int, int)
          1                            gld_efficiency             Global Memory Load Efficiency      80.00%      80.00%      80.00%
          1                          gld_transactions                  Global Load Transactions    33554418    33554418    33554418

*/

__global__ void misaligned_read_test(float* a, float* b, float *c, int size, int offset)
{
  int gid = blockIdx.x * blockDim.x + threadIdx.x;
  int k = gid + offset;

  if (k < size)
    c[gid] = a[k]+ b[k]; // here global read is misalighned by offset

  //c[gid] = a[gid];
}

int main(int argc, char** argv)
{
  printf("Runing 1D grid \n");
  int size = 1 << 25;
  int block_size = 128;
  unsigned int byte_size = size * sizeof(float);
  int offset = 0;

  if (argc > 1)
    offset = atoi(argv[1]);

  printf("Input size : %d \n", size);

  float * h_a, *h_b, *h_ref;
  h_a = (float*)malloc(byte_size);
  h_b = (float*)malloc(byte_size);
  h_ref = (float*)malloc(byte_size);


  if (!h_a)
    printf("host memory allocation error \n");

  for (size_t i = 0; i < size; i++)
  {
    h_a[i] = i % 10;
    h_b[i] = i % 7;
  }

  dim3 block(block_size);
  dim3 grid((size + block.x - 1) / block.x);

  printf("Kernel is lauch with grid(%d,%d,%d) and block(%d,%d,%d) \n",grid.x, grid.y, grid.z, block.x, block.y, block.z);

  float *d_a, *d_b, *d_c;

  cudaMalloc((void**)&d_a, byte_size);
  cudaMalloc((void**)&d_b, byte_size);
  cudaMalloc((void**)&d_c, byte_size);
  cudaMemset(d_c, 0, byte_size);

  cudaMemcpy(d_a, h_a, byte_size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, byte_size, cudaMemcpyHostToDevice);

  misaligned_read_test <<<grid, block >>> (d_a, d_b, d_c, size, offset);

  cudaDeviceSynchronize();
  cudaMemcpy(h_ref, d_c, byte_size, cudaMemcpyDeviceToHost);

  cudaFree(d_c);
  cudaFree(d_b);
  cudaFree(d_a);
  free(h_ref);
  free(h_b);
  free(h_a);
}