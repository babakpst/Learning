
// nvcc main.cu -o main
//#define DEBUG 0

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

void computeCpuResults(float *g_data, int dimx, int dimy, int niterations, int nreps) {
  for (int r = 0; r < nreps; r++) {
    printf("Rep: %d\n", r);
#pragma omp parallel for
    for (int iy = 0; iy < dimy; ++iy) {
      for (int ix = 0; ix < dimx; ++ix) {
        int idx = iy * dimx + ix; // row-major

        float value = g_data[idx];
        // if (DEBUG) printf("x: %d, y: %d, idx: %d, val: %f \n", ix, iy, idx, value);
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

// change this-version 2
__global__ void kernel_A(float *g_data, int dimx, int dimy, int niterations) {
  // for (int iy = blockIdx.y * blockDim.y + threadIdx.y; iy < dimy; iy += blockDim.y * gridDim.y) {
    // for (int ix = blockIdx.x * blockDim.x + threadIdx.x; ix < dimx; ix += blockDim.x * gridDim.x) {
      
      int ix = blockIdx.x * blockDim.x + threadIdx.x;
      int iy = blockIdx.y * blockDim.y + threadIdx.y;
      int idx = iy * dimx + ix;
      int sidx = threadIdx.y * blockDim.x + threadIdx.x;

      extern __shared__ float s_data[];
      
      s_data[sidx] = g_data[idx];
      __syncthreads();

      int col_idx = threadIdx.x * blockDim.y + threadIdx.y;
      float value = s_data[col_idx];
      // float value = s_data[sidx];
      // float value = g_data[idx];

      // printf("gpu- x: %d, y: %d, idx: %d, sidx: %d, col_idx: %d, val: %f \n", ix, iy, idx, sidx, col_idx, value);
      // printf("gpu- bIdx.x: %d, bIdx.y: %d, tIdx.x: %d, tIdx.y: %d, x: %d, y: %d, idx: %d, sidx: %d, col_idx: %d, ix mod 4: %d \n", blockIdx.x, blockIdx.y, threadIdx.x, threadIdx.y, ix, iy, idx, sidx, col_idx, ix%4 );
      
      for (int i = 0; i < niterations/4; i++) 
      {
        if (iy % 4 == 0) {
          value += __fsqrt_rn(__logf(value) + 1.f);
          value += __fsqrt_rn(__logf(value) + 1.f);
          value += __fsqrt_rn(__logf(value) + 1.f);
          value += __fsqrt_rn(__logf(value) + 1.f);
        } else if (iy % 4 == 1) {
          value += __fsqrt_rn(__cosf(value) + 1.f);
          value += __fsqrt_rn(__cosf(value) + 1.f);
          value += __fsqrt_rn(__cosf(value) + 1.f);
          value += __fsqrt_rn(__cosf(value) + 1.f);
        } else if (iy % 4 == 2) {
          value += __fsqrt_rn(__sinf(value) + 1.f);
          value += __fsqrt_rn(__sinf(value) + 1.f);
          value += __fsqrt_rn(__sinf(value) + 1.f);
          value += __fsqrt_rn(__sinf(value) + 1.f);
        } else if (iy % 4 == 3) {
          value += __fsqrt_rn(__tanf(value) + 1.f);
          value += __fsqrt_rn(__tanf(value) + 1.f);
          value += __fsqrt_rn(__tanf(value) + 1.f);
          value += __fsqrt_rn(__tanf(value) + 1.f);
        }
      }
      for (int i = 0; i < niterations%4; i++) 
      {  
        if (iy % 4 == 0) {
          value += __fsqrt_rn(__logf(value) + 1.f);
        } else if (iy % 4 == 1) {
          value += __fsqrt_rn(__cosf(value) + 1.f);
        } else if (iy % 4 == 2) {
          value += __fsqrt_rn(__sinf(value) + 1.f);
        } else if (iy % 4 == 3) {
          value += __fsqrt_rn(__tanf(value) + 1.f);
        }
      }

      s_data[col_idx] = value;
      __syncthreads();
      // s_data[sidx] = value;
      // __syncthreads();
      // g_data[idx] = value;
      g_data[idx] = s_data[sidx];
    // }
  // }
}


// // change this-version 1
// __global__ void kernel_A(float *g_data, int dimx, int dimy, int niterations) {
//   // for (int iy = blockIdx.y * blockDim.y + threadIdx.y; iy < dimy; iy += blockDim.y * gridDim.y) {
//     // for (int ix = blockIdx.x * blockDim.x + threadIdx.x; ix < dimx; ix += blockDim.x * gridDim.x) {
      
//       int ix = blockIdx.x * blockDim.x + threadIdx.x;
//       int iy = blockIdx.y * blockDim.y + threadIdx.y;
//       int idx = iy * dimx + ix;

//       float value = g_data[idx];
//       // printf("gpu- x: %d, y: %d, idx: %d, val: %f \n", ix, iy, idx, value);
//       for (int i = 0; i < niterations; i++) 
//       {

//         // value += (ix % 4 == 0 ? sqrtf(logf(value) + 1.f) :  (ix % 4 == 1 ? sqrtf(cosf(value) + 1.f) : (ix % 4 == 2 ? sqrtf(sinf(value) + 1.f) : (ix % 4 == 3 ? sqrtf(tanf(value) + 1.f) : 0))));

//         // value += (ix % 4 == 0 ? sqrtf(logf(value) + 1.f) : 0);
//         // value += (ix % 4 == 1 ? sqrtf(cosf(value) + 1.f) : 0);
//         // value += (ix % 4 == 2 ? sqrtf(sinf(value) + 1.f) : 0);
//         // value += (ix % 4 == 3 ? sqrtf(tanf(value) + 1.f) : 0);

//         if (ix % 4 == 0) {
//           value += sqrtf(logf(value) + 1.f);
//         } else if (ix % 4 == 1) {
//           value += sqrtf(cosf(value) + 1.f);
//         } else if (ix % 4 == 2) {
//           value += sqrtf(sinf(value) + 1.f);
//         } else if (ix % 4 == 3) {
//           value += sqrtf(tanf(value) + 1.f);
//         }
//       }
//       g_data[idx] = value;
//     // }
//   // }
// }


// change this
void launchKernel(float * d_data, int dimx, int dimy, int niterations) {
  // Only change the contents of this function and the kernel(s). You may
  // change the kernel's function signature as you see fit. 

  //query number of SMs
  cudaDeviceProp prop;
  cudaGetDeviceProperties(&prop, 0);
  // int num_sms = prop.multiProcessorCount;
  

  // printf(" SM counts: %d \n", num_sms);
  // dim3 block(1, 32);
  // dim3 grid(1, num_sms);
  
  // dim3 block(128, 128);
  // dim3 grid(64, 64);

  // dim3 block(16, 16);
  // dim3 grid(512, 512);

  // dim3 block(1, 1024);
  // dim3 grid(8192, 8);

  // dim3 block(1024, 1);
  // dim3 grid(8, 8192);

  // dim3 block(2048, 1);
  // dim3 grid(4, 8192);

  dim3 block(32, 32);
  dim3 grid(256, 256);

  // dim3 block(64, 64);
  // dim3 grid(128, 128);
  
  // kernel_A<<<grid, block>>>(d_data, dimx, dimy, niterations);
  kernel_A<<<grid, block,  block.x * block.y * sizeof(float)>>>(d_data, dimx, dimy, niterations);
  cudaDeviceSynchronize();
}


float timing_experiment(float *d_data, int dimx, int dimy, int niterations, int nreps) {
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

  // int dimx = 1 * 1024;
  // int dimy = 1 * 1024;

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
  printf("\n Computing CPU results\n");
  computeCpuResults(h_gold, dimx, dimy, niterations, 1);
  bool pass = checkResults(h_gold, h_data, dimx, dimy, rel_tol);

  if (pass) {
    printf("Results are correct\n");
  } else {
    printf("FAIL:  results are incorrect\n");
  }  

  float elapsed_time_ms = 0.0f;
 
  elapsed_time_ms = timing_experiment(d_data, dimx, dimy, niterations, nreps);
  printf("A:  %8.2f ms\n", elapsed_time_ms);

  printf("CUDA: %s\n", cudaGetErrorString(cudaGetLastError()));

  if (d_data) cudaFree(d_data);
  if (h_data) free(h_data);

  cudaDeviceReset();

  return 0;
}

