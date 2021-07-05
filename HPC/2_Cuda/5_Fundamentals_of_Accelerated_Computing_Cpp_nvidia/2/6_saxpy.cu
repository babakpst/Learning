#include <stdio.h>

#define N 2048 * 2048 // Number of elements in each vector

/*
 * Optimize this already-accelerated codebase. Work iteratively,
 * and use nsys to support your work.
 *
 * Aim to profile `saxpy` (without modifying `N`) running under
 * 20us.
 *
 * Some bugs have been placed in this codebase for your edification.
 */

// ============================
__global__ void saxpy(int * a, int * b, int * c)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x *gridDim.x;

    for (int i= tid; i< N; i+=stride)
        c[i] = 2 * a[i] + b[i];
}
// ============================
__global__ void init(int * a, int val)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x *gridDim.x;

    for (int i= tid; i< N; i+=stride)
        a[i] = val;
}


int main()
{
    int *a, *b, *c;

    int size = N * sizeof (int); // The total number of bytes per vector

    cudaMallocManaged(&a, size);
    cudaMallocManaged(&b, size);
    cudaMallocManaged(&c, size);

    int deviceId;
    cudaGetDevice(&deviceId);
    int numberOfSMs;
    cudaDeviceGetAttribute(&numberOfSMs, cudaDevAttrMultiProcessorCount, deviceId);

    int threads_per_block = 256;
    //int number_of_blocks = (N / threads_per_block) + 1;
    int number_of_blocks = 32*numberOfSMs;


    cudaMemPrefetchAsync(a, size, deviceId);
    cudaMemPrefetchAsync(b, size, deviceId);
    cudaMemPrefetchAsync(c, size, deviceId);

    init<<<number_of_blocks, threads_per_block>>>( a, 2);
    init<<<number_of_blocks, threads_per_block>>>( b, 1);
    init<<<number_of_blocks, threads_per_block>>>( c, 0);
    cudaDeviceSynchronize();
    saxpy <<< number_of_blocks, threads_per_block >>> ( a, b, c );
    cudaDeviceSynchronize();
    
    // Print out the first and last 5 values of c for a quality check
    for( int i = 0; i < 5; ++i )
        printf("c[%d] = %d, ", i, c[i]);
    printf ("\n");
    for( int i = N-5; i < N; ++i )
        printf("c[%d] = %d, ", i, c[i]);
    printf ("\n");

    cudaFree( a ); cudaFree( b ); cudaFree( c );
}

