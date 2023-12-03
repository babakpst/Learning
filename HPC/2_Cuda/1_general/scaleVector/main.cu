
// scale a vector on CPU and GPU
// Babak
// 12/01/2023

#include <stdio.h>
#include <time.h>

__global__ void scale(float* d_in, float *d_out, int size, int scaler)
{
  int tid = blockIdx.x*blockDim.x + threadIdx.x;
  if (tid < size)
    d_out[tid] = scaler * d_in[tid];
}

__global__ void scale2(float* d_in, float *d_out, int size, int scaler)
{
  extern __shared__  float arr[];

  int tid = blockIdx.x*blockDim.x + threadIdx.x;
  if (tid < size)
  {
    arr[tid] = scaler * d_in[tid];
    d_out[tid] = arr[tid];
  }
}

int main(int argc, char* argv[])
{

  printf(" scale a vector \n");

  int size = 1<<12;
  int sizeByte = size * sizeof(float);
  int scaler = 3.0f;

  // host memory allocation
  float *h_in, *h_out, *h_ref;
  
  h_in  = (float*)malloc(sizeByte);
  h_out = (float*)malloc(sizeByte);
  h_ref = (float*)malloc(sizeByte);
  
  // device memory allocation 
  float *d_in, *d_out;
  cudaMalloc((void **)&d_in, sizeByte);
  cudaMalloc((void **)&d_out, sizeByte);
  
  // initilize input vector
  for (int i = 0; i< size; ++i)
    h_in[i] = 1.1f*i;

  // scale on CPU
  for (int i = 0; i< size; ++i)
  { 
    h_ref[i] = h_in[i]*scaler;
  }
    
  dim3 block(128);
  dim3 grid(size/128+(size%128!=0));
  printf("block: %d, grid: %d \n", block.x, grid.x);

  cudaEvent_t cstart, cHtoD, cfunc, cDtoH;
  cudaEventCreate(&cstart);
  cudaEventCreate(&cHtoD);
  cudaEventCreate(&cDtoH);
  cudaEventCreate(&cfunc);
  
  // double  accum=0.0;
  // for (int i = 0; i<20;++i)
  // {
    // clock_t start = clock();
    cudaEventRecord(cstart,0);
    cudaMemcpy(d_in, h_in, sizeByte, cudaMemcpyHostToDevice);
    // clock_t HtoD=clock();
    cudaEventRecord(cHtoD,0);
    cudaEventSynchronize(cHtoD);
    // accum+= (double)( HtoD-start);
    // }
    
    // printf(" HtoD average: %4.6f (ms)\n",(double)( accum*1000.0f / CLOCKS_PER_SEC/20));
    
    // scale<<<grid, block>>>(d_in, d_out, size, 3);
    scale2<<<grid, block, sizeByte>>>(d_in, d_out, size, 3);
    
    cudaDeviceSynchronize();
    cudaEventRecord(cfunc,0);
    cudaEventSynchronize(cfunc);
    // clock_t func=clock();
    
    cudaMemcpy(h_out, d_out, sizeByte, cudaMemcpyDeviceToHost);
    // clock_t DtoH=clock();
    cudaEventRecord(cDtoH,0);
    cudaEventSynchronize(cDtoH);

    float time1, time2, time3;
    cudaEventElapsedTime(&time1, cstart, cHtoD);
    cudaEventElapsedTime(&time1, cHtoD, cfunc);
    cudaEventElapsedTime(&time1, cfunc, cDtoH);
  
  // printf(" HtoD: %4.6f (ms)\n",(double)((double)(HtoD - start)*1000.0f / CLOCKS_PER_SEC));
  // printf(" func: %4.6f (ms)\n",(double)((double)(func- HtoD)*1000.0f / CLOCKS_PER_SEC));
  // printf(" DtoH: %4.6f (ms)\n",(double)((double)(DtoH-func)*1000.0f / CLOCKS_PER_SEC));

  printf(" HtoD: %4.6f (ms)\n",time1);
  printf(" func: %4.6f (ms)\n",time2);
  printf(" DtoH: %4.6f (ms)\n",time3);


  // check the output
  for (int i = 0; i< size; ++i)
    // if (abs(h_out[i] - h_ref[i] )>0.001) printf(" error at %d: %f %f\n", i, h_in[i], h_ref[i]);
    if ((h_out[i] != h_ref[i] )) printf(" error at %d: %f %f\n", i, h_in[i], h_ref[i]);

  printf(" end successfully \n");

  cudaFree(d_in);
  cudaFree(d_out);
  free(h_in);
  free(h_out);
  free(h_ref);

  cudaDeviceReset();
  return 0;
}