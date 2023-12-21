#include <time.h> 
#include <cstdio>

struct padding
{
  // float x,y,z,w;
  float x[128];
  float padding; // this avoids bank conclict
};

__global__ void test_bank_conflict()
{
  int idx = threadIdx.y*blockDim.x + threadIdx.x;
  
  extern __shared__ padding smem[];
  smem[idx].x[0]++; 

  // unsigned long long start, end;
  // extern __shared__ int smem[];

  // start = clock();
  // no bank conflict
  // __syncthreads();
  // end = clock();
  // if (idx==0) printf(" elapsed time-no bank conflict: %llu \n", end-start); // 150
  // printf(" elapsed time-no bank conflict: %llu \n", end-start); // 150
  
  // __syncthreads();
  // printf("\n");
  // start = clock();
  // // no bank conflict
  // smem[idx] = 4; 
  // __syncthreads();
  // end = clock();
  // // if (idx==0) printf(" elapsed time-no bank conflict: %llu \n", end-start);  // 184
  // printf(" elapsed time-no bank conflict: %llu \n", end-start);  // 184

  // __syncthreads();
  // printf("\n");
  // start = clock();
  // // 2-way bank conflict
  // smem[idx*2] = 4;
  // __syncthreads();
  // end = clock();
  // // if (idx==0) printf(" elapsed time- 2-way: %llu \n", end-start); // 94
  // printf(" elapsed time- 2-way: %llu \n", end-start); // 94

  // __syncthreads();
  // printf("\n");
  // start = clock();
  // // 8-way bank conflict
  // smem[idx*8] = 4;
  // __syncthreads();
  // end = clock();
  // // if (idx==0) printf(" elapsed time- 8-way: %llu \n", end-start);  // 93
  // printf(" elapsed time- 8-way: %llu \n", end-start);  // 93

  // __syncthreads();
  // printf("\n");
  // start = clock();
  // // 32-way bank conflict
  // smem[idx*32] = 4;
  // __syncthreads();
  // end = clock();
  // // if (idx==0) printf(" elapsed time- 32-way: %llu \n", end-start); // 244
  // printff(" elapsed time- 32-way: %llu \n", end-start); // 244


}

int main()
{
  printf("code starts\n"); 
  int iters = 20000;
  // float  elapsedTime;
  // cudaEvent_t start, end; 
  // cudaEventCreate(&start); 
  // cudaEventCreate(&end); 

  // cudaEventRecord(start,0); 

  clock_t start = clock(); 
  for (int i = 0; i<iters; ++i)
    test_bank_conflict<<<1,1024,32*1024*sizeof(int)>>>();
  cudaDeviceSynchronize();
  clock_t end = clock(); 
  printf(" elapsed time: %4.6f (ms)\n",(double)((double)(end - start)*1000.0f / CLOCKS_PER_SEC)); 
  
  // cudaEventRecord(end,0); 
  // cudaEventSynchronize(end); 
  // cudaEventElapsedTime(&elapsedTime, start, end);  // in millisecond 
  // // printf("Kernel execution time using events : %f (ms)\n",elapsedTime/iters);
  // printf("Kernel execution time using events : %f (ms)\n",elapsedTime);
  // cudaEventDestroy(start); 
  // cudaEventDestroy(end); 
  

  printf("end of the code\n"); 
  return 0;
}