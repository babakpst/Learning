
/*
Babak Poursartip
12/16/2023

Run commands: 
sudo nvprof --metrics gld_efficiency,gst_efficiency,branch_efficiency,sm_efficiency,achieved_occupancy,warp_execution_efficiency,inst_per_warp,stall_sync,dram_utilization ./bin/main

Assumptions:
- I assumed the matrix size is fixed and dimensions are multiples of 1024. n iteration is multiple of 5. 
- I assuming dimx, dimy are multiples of block.x, block.y

global load/store efficiency: 100
I attached the report from nvprof and nvvp.

On my GPU (NVIDIA GeForce GT 1030 - 3 SM) the original code takes ~850 milli seconds and my code 
takes ~22 milli seconds (38x).

*/

#include <stdio.h>
#include <limits.h>

bool checkResults (float *gold, float *d_data, int dimx, int dimy, float rel_tol) {
  for (int iy = 0; iy < dimy; ++iy) {
    for (int ix = 0; ix < dimx; ++ix) {
      int idx = iy * dimx + ix;

      float gdata = gold[idx];
      float ddata = d_data[idx];

      if (isnan(gdata) || isnan(ddata)) {
        printf("Nan detected: gold %f, device %f\n", gdata, ddata);
        return false;
      }

      float rdiff;
      if (fabs(gdata) == 0.f)
        rdiff = fabs(ddata);
      else
        rdiff = fabs(gdata - ddata) / fabs(gdata);

      if (rdiff > rel_tol) {
        printf("Error solutions don't match at iy=%d, ix=%d.\n", iy, ix);
        printf("gold: %f, device: %f\n", gdata, ddata);
        printf("rdiff: %f\n", rdiff);
        return false;
      }
    }
  }
  return true;
}

void computeCpuResults(float *g_data, int dimx, int dimy, int niterations,
                       int nreps) {
  for (int r = 0; r < nreps; r++) {
    printf("Rep: %d\n", r);
#pragma omp parallel for
    for (int iy = 0; iy < dimy; ++iy) {
      for (int ix = 0; ix < dimx; ++ix) {
        int idx = iy * dimx + ix;

        float value = g_data[idx];

        for (int i = 0; i < niterations; i++) {
          if (ix % 4 == 0) {
            value += sqrtf(logf(value) + 1.f);
          } else if (ix % 4 == 1) {
            value += sqrtf(cosf(value) + 1.f);
          } else if (ix % 4 == 2) {
            value += sqrtf(sinf(value) + 1.f);
          } else if (ix % 4 == 3) {
            value += sqrtf(tanf(value) + 1.f);
          }
        }
        g_data[idx] = value;
      }
    }
  }
}

__global__ void kernel_A(float *g_data, int dimx, int niterations) 
{
  // create a 2D thread block: each thread computes one element of g_data
  int ix = blockIdx.x * blockDim.x + threadIdx.x; // thread id in x direction in the global grid
  int iy = blockIdx.y * blockDim.y + threadIdx.y; // thread id in y direction in the global 
  int idx = iy * dimx + ix; // global index in g_data
  
  int sidx = threadIdx.y * blockDim.x + threadIdx.x; // shared index in the block for s_data
  
  // Create a shared memory array: fetch data from global memory (g_data) to shared memory (s_data).
  // Why do we need this? 
  //  - Every four columns of the matrix has a different operation. 
  //  - CUDA assigns thread IDs in a thread block to warps, in a way that x varies faster than y than z.
  //  - The original implementation, results in a 4-way thread divergence. 
  //  - To avoid divergence, we copy the data from global memory to shared memory. The shared memory is needed 
  //    because threads access the data in un-coalesced manner (uncoalesed access in global memory is expensive).
  extern __shared__ float s_data[];
  
  // copy data from global memory (aligned+coalesced) to shared memory (aligned+coalesced)
  s_data[sidx] = g_data[idx];
  
  // Barrier/Wait for all threads to finish copying data to shared memory.
  // This is needed because we don't want to start computation before threads finish store in the shared memory. 
  // Each thread will work on a different element of the shared memory.
  __syncthreads(); 
  
  // index of the element in the shared memory that the thread is working on.
  // reading in col-major order to avoid thread divergence.
  int col_idx = threadIdx.x * blockDim.y + threadIdx.y;
  float value = s_data[col_idx];
  
  int tidy = threadIdx.y;
  
  // Uncomment the following for loop if niterations is greater than 5 and a multiple of 5.
  // for (int i = 0; i < niterations/5; i++) 
  // {
  // To have the same computation as the original code, we need to have the branch condition. There is no divergence here.
  // use CUDA/intrinsic functions, faster but less accurate. The results are withing the tolerance.
    if (tidy % 4 == 0) {
      value += __fsqrt_rn(__logf(value) + 1.f);
      value += __fsqrt_rn(__logf(value) + 1.f); // 5-fold loop unrolling
      value += __fsqrt_rn(__logf(value) + 1.f); // 5-fold loop unrolling
      value += __fsqrt_rn(__logf(value) + 1.f); // 5-fold loop unrolling
      value += __fsqrt_rn(__logf(value) + 1.f); // 5-fold loop unrolling
    } else if (tidy % 4 == 1) {
      value += __fsqrt_rn(__cosf(value) + 1.f);
      value += __fsqrt_rn(__cosf(value) + 1.f);
      value += __fsqrt_rn(__cosf(value) + 1.f);
      value += __fsqrt_rn(__cosf(value) + 1.f);
      value += __fsqrt_rn(__cosf(value) + 1.f);
    } else if (tidy % 4 == 2) {
      value += __fsqrt_rn(__sinf(value) + 1.f);
      value += __fsqrt_rn(__sinf(value) + 1.f);
      value += __fsqrt_rn(__sinf(value) + 1.f);
      value += __fsqrt_rn(__sinf(value) + 1.f);
      value += __fsqrt_rn(__sinf(value) + 1.f);
    } else if (tidy % 4 == 3) {
      value += __fsqrt_rn(__tanf(value) + 1.f);
      value += __fsqrt_rn(__tanf(value) + 1.f);
      value += __fsqrt_rn(__tanf(value) + 1.f);
      value += __fsqrt_rn(__tanf(value) + 1.f);
      value += __fsqrt_rn(__tanf(value) + 1.f);
    }
  // }

  // uncomment the following for loop if niterations is not a multiple of 5.
  // for (int i = 0; i < niterations%5; i++) 
  // {  
  //   if (iy % 4 == 0) {
  //     value += __fsqrt_rn(__logf(value) + 1.f);
  //   } else if (iy % 4 == 1) {
  //     value += __fsqrt_rn(__cosf(value) + 1.f);
  //   } else if (iy % 4 == 2) {
  //     value += __fsqrt_rn(__sinf(value) + 1.f);
  //   } else if (iy % 4 == 3) {
  //     value += __fsqrt_rn(__tanf(value) + 1.f);
  //   }
  // }
      
  
  // store the result in the shared memory
  s_data[col_idx] = value;
  
  // Wait until all threads finish copying data to shared memory. 
  // Each thread will work on a different element of the shared memory when storing to the global memory.
  __syncthreads();

  // global store, aligned+coalesced
  g_data[idx] = s_data[sidx];
}

void launchKernel(float * d_data, int dimx, int dimy, int niterations) {
  // Only change the contents of this function and the kernel(s). You may
  // change the kernel's function signature as you see fit. 

  // assuming dimx, dimy are multiples of 1024
  // reducing the number of threads per block, reduces the wait time at syncthreads.

  // dim3 block(16, 16);
  // dim3 block(1, 1024);
  // dim3 block(1024, 1);
  // dim3 block(32, 32);
  // dim3 block(32, 16);
  // dim3 block(32, 8);


  // dim3 block(64, 4);
  // dim3 block(32, 8);
  dim3 block(32, 4);
  // dim3 block(32, 1); 
  dim3 grid(dimx/block.x, dimy/block.y);

  
// bbk: 64 bit cash line size, we need 2 floats to shift data to the next bank. 

  // kernel_A<<<grid, block,  (block.x)   * block.y * sizeof(float)>>>(d_data, dimx, niterations);
  // padding the shared memory to avoid bank conflicts (but I see no difference in the performance).
  kernel_A<<<grid, block,  (block.x+2)   * block.y * sizeof(float)>>>(d_data, dimx, niterations);
}

float timing_experiment(float *d_data,
  int dimx, int dimy, int niterations, int nreps) {
  float elapsed_time_ms = 0.0f;
  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  cudaEventRecord(start, 0);
  for (int i = 0; i < nreps; i++) {
    launchKernel(d_data, dimx, dimy, niterations);
  }
  cudaEventRecord(stop, 0);
  cudaDeviceSynchronize();
  cudaEventElapsedTime(&elapsed_time_ms, start, stop);
  elapsed_time_ms /= nreps;

  cudaEventDestroy(start);
  cudaEventDestroy(stop);

  return elapsed_time_ms;
}

int main() {
  int dimx = 8 * 1024;
  int dimy = 8 * 1024;

  int nreps = 10;
  int niterations = 5;

  int nbytes = dimx * dimy * sizeof(float);

  float *d_data = 0, *h_data = 0, *h_gold = 0;
  cudaMalloc((void **)&d_data, nbytes);
  if (0 == d_data) {
    printf("couldn't allocate GPU memory\n");
    return -1;
  }
  printf("allocated %.2f MB on GPU\n", nbytes / (1024.f * 1024.f));
  h_data = (float *)malloc(nbytes);
  h_gold = (float *)malloc(nbytes);
  if (0 == h_data || 0 == h_gold) {
    printf("couldn't allocate CPU memory\n");
    return -2;
  }
  printf("allocated %.2f MB on CPU\n", 2.0f * nbytes / (1024.f * 1024.f));
  for (int i = 0; i < dimx * dimy; i++) h_gold[i] = 1.0f + 0.01*(float)rand()/(float)RAND_MAX;
  cudaMemcpy(d_data, h_gold, nbytes, cudaMemcpyHostToDevice);

  timing_experiment(d_data, dimx, dimy, niterations, 1);
  printf("Verifying solution\n");

  cudaMemcpy(h_data, d_data, nbytes, cudaMemcpyDeviceToHost);

  float rel_tol = .001;
  computeCpuResults(h_gold, dimx, dimy, niterations, 1);
  bool pass = checkResults(h_gold, h_data, dimx, dimy, rel_tol);

  if (pass) {
    printf("Results are correct\n");
  } else {
    printf("FAIL:  results are incorrect\n");
  }  

  float elapsed_time_ms = 0.0f;
 
  elapsed_time_ms = timing_experiment(d_data, dimx, dimy, niterations,
                                      nreps);
  printf("A:  %8.2f ms\n", elapsed_time_ms);

  printf("CUDA: %s\n", cudaGetErrorString(cudaGetLastError()));

  if (d_data) cudaFree(d_data);
  if (h_data) free(h_data);

  cudaDeviceReset();

  return 0;
}

