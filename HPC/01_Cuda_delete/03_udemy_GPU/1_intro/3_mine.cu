
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// unique index calculation

#include <cstdio>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime_api.h>
#include <driver_types.h>
#include <vector>

__global__ void unique_idx_calc_threadIdx(std::vector<int> *input) {

  int tid = threadIdx.x;
  // printf(" my threadIdx: %d,value: %d \n", tid, (*input)[tid]);
  input->set(0, 100);
  // printf(" my threadIdx: %d,value: %d \n", tid, input->at(tid));
}

int main() {
  printf(" starts ...");

  // int array_size = 8;
  // int array_byte_size = sizeof(int) * array_size;
  // int h_data[] = {1, 2, 3, 4, 5, 6, 7, 8}; // array on the host
  // std::vector<int> h_data(array_size);
  std::vector<int> h_data{1, 2, 3, 4, 5, 6, 7, 8};
  // h_data = {1, 2, 3, 4, 5, 6, 7, 8};

  printf(" data on the host: \n");
  for (auto c : h_data)
    printf(" %d", c);
  printf("\n\n");

  std::vector<int> *d_data; // array on the device

  cudaMalloc((void **)&d_data, h_data.size() * sizeof(std::vector<int>));

  cudaMemcpy(d_data, &h_data[0], h_data.size() * sizeof(std::vector<int>),
             cudaMemcpyHostToDevice);

  dim3 block(8);
  dim3 grid(1);

  printf(" data on the device: \n");
  unique_idx_calc_threadIdx<<<grid, block>>>(d_data);
  cudaDeviceSynchronize();

  cudaDeviceReset();

  printf(" finished.\n");
  return 0;
}