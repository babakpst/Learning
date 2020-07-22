#include <stdio.h>

#define NUM_THREADS 1000000
#define ARRAY_SIZE 10
#define BLOCK_WIDTH 1000

__global__ void increment_naive(int *g){

int i =blockIdx.x*blockDim.x +threadIdx.x;

i = i%ARRAY_SIZE;
g[i] = g[i]+1;

}

__global__ void increment_atomic(int *g){
int i =blockIdx.x*blockDim.x +threadIdx.x;

i = i%ARRAY_SIZE;
atomicAdd(&g[i],1); //guarantees that only one thread can do read/modify/write operation.

}



int main(){

printf(" %d of threads in %d blocks writing in %d-element array. \n", NUM_THREADS, NUM_THREADS/BLOCK_WIDTH, ARRAY_SIZE);

float h_arr[ARRAY_SIZE];
const int ARRAY_BYTE = ARRAY_SIZE * sizeof(int);

float *d_arr;
cudaMalloc((void **) &d_arr, ARRAY_BYTE);
cudaMemset((void *) d_arr, 0, ARRAY_BYTE);

increment_naive<<<NUM_THREADS/BLOCK_WIDTH,BLOCK_WIDTH>>>(d_arr);

cudaMemcpy(h_arr, d_arr, ARRAY_BYTE, cudaMemcpyDeviceToHost);

cudaFree(d_arr);

for (int i = 0; i < ARRAY_SIZE; ++i){
printf(" %d ", h_arr[i] );
}
printf("\n");


float *d_arr;
cudaMalloc((void **) &d_arr, ARRAY_BYTE);
cudaMemset((void *) d_arr, 0, ARRAY_BYTE);

increment_atomic<<<NUM_THREADS/BLOCK_WIDTH,BLOCK_WIDTH>>>(d_arr);

cudaMemcpy(h_arr, d_arr, ARRAY_BYTE, cudaMemcpyDeviceToHost);

cudaFree(d_arr);

for (int i = 0; i < ARRAY_SIZE; ++i){
printf(" %d ", h_arr[i] );
}
printf("\n");

return 0;
}