
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// unique index calculation
#include <cstdio>


// ===========================================
// 2d grid, 2d block
__global__ void unique_gid_calculation_3d_3d(int *input) {


  int threadsPerBlock       = blockDim.x * blockDim.y * blockDim.z;
  int threadPositionInBlock = threadIdx.x +
                              blockDim.x * threadIdx.y +
                              blockDim.x * blockDim.y * threadIdx.z;

  int blockPositionInGrid   = blockIdx.x +
                              gridDim.x * blockIdx.y +
                              gridDim.x * gridDim.y * blockIdx.z;

  int tid = blockPositionInGrid * threadsPerBlock + threadPositionInBlock;

  printf("gridDim.x: %d, gridDim.y: %d, gridDim.z: %d, blockDim.x: %d, blockDim.y: %d, blockDim.z: %d, blockIdx.x: %d, blockIdx.y: %d, blockIdx.z: %d, threadIdx.x: %d, threadIdx.y: %d, threadIdx.z: %d, tid: %d \n",
          gridDim.x, gridDim.y, gridDim.z, 
          blockDim.x, blockDim.y, blockDim.z, 
          blockIdx.x, blockIdx.y, blockIdx.z, 
          threadIdx.x, threadIdx.y, threadIdx.z, 
          tid);


}

// ===========================================
// 2d grid, 2d block
__global__ void unique_gid_calculation_2d_2d(int *input) {

  int tid = blockDim.x * threadIdx.y + threadIdx.x;

  int num_threads_in_a_block = blockDim.x * blockDim.y;
  int block_offset = blockIdx.x * num_threads_in_a_block;

  int num_threads_in_a_row = num_threads_in_a_block * gridDim.x;
  int row_offset = num_threads_in_a_row * blockIdx.y;

  int gid = tid + block_offset + row_offset;

  printf("gridDim.x: %d,  gridDim.y: %d,  gridDim.z: %d, blockDim.x: %d, blockDim.y: %d, blockDim.z: %d, blockIdx.x: %d, blockIdx.y: %d, blockIdx.z: %d, threadIdx.x: %d, threadIdx.y: %d, threadIdx.z: %d, gid: %d \n",
          gridDim.x, gridDim.y, gridDim.z, 
          blockDim.x, blockDim.y, blockDim.z, 
          blockIdx.x, blockIdx.y, blockIdx.z, 
          threadIdx.x, threadIdx.y, threadIdx.z, 
          gid);
}

// ===========================================
int main() {
  printf(" starts ...");

  int nCol = 6;
  int nRow = 8;
  int array_size = nCol*nRow;
  int array_byte_size = sizeof(int) * array_size;
  int h_data[array_size]; 
  
  for (int i = 0; i< array_size; ++i)
  {
    h_data[i] = i;
  }
  
  

  printf(" data on the host: \n");
  for (int i = 0; i < array_size; ++i)
  {
    printf(" %d", h_data[i]);
    if((i%8)==0) printf("\n");
  }  
  printf("\n\n");

  int *d_data; // array on the device

  cudaMalloc((void **)&d_data, array_byte_size);
  cudaMemcpy(d_data, h_data, array_byte_size, cudaMemcpyHostToDevice);

  dim3 grid(nCol, 1, 1);
  dim3 block(nRow, 1, 1);


  printf(" data on the device: \n");
  //unique_gid_calculation_2d_2d<<<grid, block>>>(d_data);
  unique_gid_calculation_3d_3d<<<grid, block>>>(d_data);

  cudaDeviceSynchronize();

  cudaDeviceReset();
  printf(" finished.");
  return 0;
}
