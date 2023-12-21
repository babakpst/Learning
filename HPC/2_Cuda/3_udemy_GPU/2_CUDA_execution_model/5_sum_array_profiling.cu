
// Babak Poursartip
// 10/01/2020

// profile/profiling with nvprof
/*

nvprof modes:
1- summary mode
2- GPU and API trace mode
3- event metrics summary mode
4- event, metrics trace mode

- To run nvprof, first create the executable (nvcc file.cu -o file.out). Then,
profile using: nvprof ./file.out (This would be the summary mode)

metrics:
- sm_efficiency
- achieved_occupancy
- branch_efficiency
- gld_efficiency
- gld_throughput
- dram_read_throughput
- inst_per_warp
- stall_sync


arguments :
1 - kernel (0:1D or 1:2D),
2 - input size (2 pow (x))
3 - for 2D kernel nx,
4 - block.x
5 - block.y

- To run with metrics: 

$ nvcc 5_sum_array_profiling.cu -o 5
$ sudo nvprof # ./5 # this runs in the summary mode (default operation)
$ sudo nvprof --metrics gld_efficiency,sm_efficiency,achieved_occupancy ./5 0 22 
$ sudo nvprof --metrics gld_efficiency,sm_efficiency,achieved_occupancy ./5 0 25 0 7
$ sudo nvprof --metrics gld_efficiency,sm_efficiency,achieved_occupancy ./5 1 25 20 7 2 
$ sudo nvprof --metrics gld_efficiency,sm_efficiency,achieved_occupancy ./5 1 25 20 8 2 

*/

#include <cstdio>
#include <iostream>

// =================================
// cuda error check macro
#define gpuErrchk(ans)                                                         \
  { gpuAssert(ans, __FILE__, __LINE__); }

inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort = true) 
{
  if (code != cudaSuccess) 
  {
    fprintf(stderr, "GPUassert: %s. File: %s, line: %d. \n", cudaGetErrorString(code), file, line);
    if (abort) {
      // printf(" Exists from the gpuErrorCheck func.\n");
      exit(code);
    }
  }
}

// ==============================================
void compare_arrays(const float *a, const float *b, const int size) 
{
  for (int i = 0; i < size; ++i) {
    if (a[i] != b[i]) {
      printf("\n Arrays are not equal!! %d %f %f \n", i, a[i], b[i]);
      return;
    }
  }
  printf("\n Arrays are identical!! \n");
}

// ==============================================
void sum_array_cpu(float *a, float *b, float *c, const int size) 
{
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] + b[i];
  }
}

// ==============================================
// 1D grid, and 1D block. Thus, nx = size
__global__ void sum_array_1Dgrid_1Dblock(float *a, float *b, float *c, int nx) 
{
  int gid = blockDim.x * blockIdx.x + threadIdx.x;
  c[gid] = a[gid] + b[gid];
  // printf("inside %d \n", gid);
}
// ==============================================
// 2D grid, and 2D block. Thus, nx*ny = size.
__global__ void sum_arrays_2Dgrid_2Dblock(float *a, float *b, float *c, int nx, int ny) {
  int gidx = blockDim.x * blockIdx.x + threadIdx.x;
  int gidy = blockDim.y * blockIdx.y + threadIdx.y;
  int gid = gidy * nx + gidx;

  if (gidx < nx && gidy < ny)
    c[gid] = a[gid] + b[gid];
}

// ==============================================
void run_sum_array_1d(int argc, char **argv) {

  printf(" Running 1D grid ");

  int size = 1 << 22; // the default size of the array.
  int block_size = 128;
  // int nx, ny = 0;

  if (argc > 2)
    size = 1 << atoi(argv[2]);

  if (argc > 4)
    block_size = 1 << atoi(argv[4]);

  const int byte_size = size * sizeof(float);

  printf(" size of the array: %d, %d \n", size, byte_size);

  float *h_a, *h_b, *h_out, *h_ref;

  h_a = (float *)malloc(byte_size);
  h_b = (float *)malloc(byte_size);
  h_out = (float *)malloc(byte_size);
  h_ref = (float *)malloc(byte_size);

  if (!h_a)
    printf(" host memory allocation error\n");

  for (int i = 0; i < size; ++i) {
    h_a[i] = i % 10;
    h_b[i] = i % 7;
  }

  sum_array_cpu(h_a, h_b, h_out, size);

  dim3 block(block_size);
  dim3 grid((size + block.x - 1) / block.x);

  printf(" launching the Kernel: grid(%d,%d,%d) - block(%d,%d,%d) \n", grid.x,
         grid.y, grid.z, block.x, block.y, block.z);

  float *d_a, *d_b, *d_c;

  gpuErrchk(cudaMalloc((void **)&d_a, byte_size));
  gpuErrchk(cudaMalloc((void **)&d_b, byte_size));
  gpuErrchk(cudaMalloc((void **)&d_c, byte_size));

  gpuErrchk(cudaMemset(d_c, 0, byte_size));

  gpuErrchk(cudaMemcpy(d_a, h_a, byte_size, cudaMemcpyHostToDevice));
  gpuErrchk(cudaMemcpy(d_b, h_b, byte_size, cudaMemcpyHostToDevice));

  sum_array_1Dgrid_1Dblock<<<grid, block>>>(d_a, d_b, d_c, size);
  gpuErrchk(cudaDeviceSynchronize());

  gpuErrchk(cudaMemcpy(h_ref, d_c, byte_size, cudaMemcpyDeviceToHost));

  compare_arrays(h_out, h_ref, size);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  free(h_ref);
  free(h_out);
  free(h_b);
  free(h_a);
}

// ==============================================
void run_sum_array_2d(int argc, char **argv) {

  printf(" Running 2D grid ");

  int size = 1 << 22; // the default size of the array = 4194304
  int block_x = 128;
  int nx = 1 << 14; // 16384
  int ny = size / nx;
  int block_y = 8;

  if (argc > 2)
    size = 1 << atoi(argv[2]);
  if (argc > 3) {
    nx = 1 << atoi(argv[3]);
    ny = size / nx;
  }

  if (argc > 4) {
    int pow = atoi(argv[4]);
    if (pow < 3 || pow > 10) {
      printf("Block size is invalid, default block size used (%d,%d)\n",
             block_x, block_y);
    } else {
      block_x = 1 << pow;
      block_y = 1024 / block_x;
    }
  }

  unsigned int byte_size = size * sizeof(float);

  printf("Input size : %d, nx : %d, ny : %d, block_x : %d, block_y : %d \n",
         size, nx, ny, block_x, block_y);

  float *h_a, *h_b, *h_out, *h_ref;

  h_a = (float *)malloc(byte_size);
  h_b = (float *)malloc(byte_size);
  h_out = (float *)malloc(byte_size);
  h_ref = (float *)malloc(byte_size);

  if (!h_a)
    printf(" host memory allocation error\n");

  for (int i = 0; i < size; ++i) {
    h_a[i] = i % 10;
    h_b[i] = i % 7;
  }

  sum_array_cpu(h_a, h_b, h_out, size);

  dim3 block(block_x, block_y);
  dim3 grid((nx + block_x - 1) / block_x, (ny + block_y - 1) / block_y);

  printf(" launching the Kernel: grid(%d,%d,%d) - block(%d,%d,%d) \n", grid.x,
         grid.y, grid.z, block.x, block.y, block.z);

  float *d_a, *d_b, *d_c;
  gpuErrchk(cudaMalloc((void **)&d_a, byte_size));
  gpuErrchk(cudaMalloc((void **)&d_b, byte_size));
  gpuErrchk(cudaMalloc((void **)&d_c, byte_size));

  gpuErrchk(cudaMemset(d_c, 0, byte_size));

  gpuErrchk(cudaMemcpy(d_a, h_a, byte_size, cudaMemcpyHostToDevice));
  gpuErrchk(cudaMemcpy(d_b, h_b, byte_size, cudaMemcpyHostToDevice));

  sum_arrays_2Dgrid_2Dblock<<<grid, block>>>(d_a, d_b, d_c, nx, ny);

  gpuErrchk(cudaDeviceSynchronize());

  gpuErrchk(cudaMemcpy(h_ref, d_c, byte_size, cudaMemcpyDeviceToHost));

  compare_arrays(h_out, h_ref, size);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  free(h_ref);
  free(h_out);
  free(h_b);
  free(h_a);
}

// ==============================================
////arguments :
////1 - kernel (0:1D or 1:2D),
////2 - input size (2 pow (x))
////3 - for 2D kernel nx,
////4 - block.x
////5 - block.y
// ==============================================
int main(int argc, char **argv) 
{
  printf("Sum array code for nvprof: \n");

  if (argc > 1) 
  {
    if (atoi(argv[1]) > 0)
      run_sum_array_2d(argc, argv);
    else
      run_sum_array_1d(argc, argv);
  } 
  else
    run_sum_array_1d(argc, argv);

  // query_device();
  return 0;
}



