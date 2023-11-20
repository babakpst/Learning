#include <stdio.h>
#include <stdlib.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "common.h"
#include "cuda_common.cuh"

__global__ void blocking_nonblocking_test1()
{
	int gid = blockDim.x * blockIdx.x + threadIdx.x;
	if (gid == 0)
	{
		for (size_t i = 0; i < 10000; i++)
		{
			printf("kernel 1 \n");
		}
	}
}

int main(int argc, char ** argv)
{
	int size = 1 << 15;
	
	dim3 block(128);
	dim3 grid(size / block.x);

	//  1 --
	cudaStream_t stm1,stm2,stm3;
	
	// gpuErrchk(cudaStreamCreate(&stm1));  // blocking stream
	// gpuErrchk(cudaStreamCreate(&stm2));  // blocking stream
	// gpuErrchk(cudaStreamCreate(&stm3));  // blocking stream
	
	
	// // even though streams are blocking, but there is no null stream, so all three kernels start in parallel.
	// blocking_nonblocking_test1 <<<grid, block, 0 , stm1 >>> ();
	// blocking_nonblocking_test1 <<<grid, block, 0 , stm2  >>> ();
	// // blocking_nonblocking_test1 <<<grid, block >>> ();
	// blocking_nonblocking_test1 <<<grid, block, 0, stm3 >>> ();

	// //  2 -- blocking
	// gpuErrchk(cudaStreamCreate(&stm1));
	// gpuErrchk(cudaStreamCreate(&stm2));
	// gpuErrchk(cudaStreamCreate(&stm3));
		
	// // there is a null stream. CUDA waits on all operations previously issued to all blocking streams before starting 
	// // that operation. So, here, the three kernels run in serial. 
	// blocking_nonblocking_test1 <<<grid, block, 0 , stm1 >>> ();
	// // blocking_nonblocking_test1 <<<grid, block, 0 , stm2  >>> ();
	// blocking_nonblocking_test1 <<<grid, block >>> ();
	// blocking_nonblocking_test1 <<<grid, block, 0, stm3 >>> ();
	
	// gpuErrchk(cudaStreamDestroy(stm1));
	// gpuErrchk(cudaStreamDestroy(stm2));
	// gpuErrchk(cudaStreamDestroy(stm3));

	
	// //  3 -- to void blocking nature of null stream, we can create non-blocking streams with Flags.
	// gpuErrchk(cudaStreamCreateWithFlags(&stm1, cudaStreamNonBlocking));
	// gpuErrchk(cudaStreamCreate(&stm2));
	// gpuErrchk(cudaStreamCreateWithFlags(&stm3,cudaStreamNonBlocking));

	// blocking_nonblocking_test1 <<<grid, block, 0 , stm1 >>> ();
	// // blocking_nonblocking_test1 <<<grid, block, 0 , stm2  >>> ();
	// blocking_nonblocking_test1 <<<grid, block >>> ();
	// blocking_nonblocking_test1 <<<grid, block, 0, stm3 >>> ();

	// gpuErrchk(cudaStreamDestroy(stm1));
	// gpuErrchk(cudaStreamDestroy(stm2));
	// gpuErrchk(cudaStreamDestroy(stm3));

	
	// //  4 -- blockin 
	gpuErrchk(cudaStreamCreateWithFlags(&stm1, cudaStreamDefault));
	gpuErrchk(cudaStreamCreate(&stm2));
	gpuErrchk(cudaStreamCreateWithFlags(&stm3, cudaStreamDefault));

	blocking_nonblocking_test1 <<<grid, block, 0 , stm1 >>> ();
	// blocking_nonblocking_test1 <<<grid, block, 0 , stm2  >>> ();
	blocking_nonblocking_test1 <<<grid, block >>> ();
	blocking_nonblocking_test1 <<<grid, block, 0, stm3 >>> ();


	gpuErrchk(cudaStreamDestroy(stm1));
	gpuErrchk(cudaStreamDestroy(stm2));
	gpuErrchk(cudaStreamDestroy(stm3));
	gpuErrchk(cudaDeviceSynchronize());

	gpuErrchk(cudaDeviceReset());
	return 0;
}