//Udacity HW 4
//Radix Sorting

#include "utils.h"
#include <thrust/host_vector.h>
#include <cstddef>

/* Red Eye Removal
   ===============
   
   For this assignment we are implementing red eye removal.  This is
   accomplished by first creating a score for every pixel that tells us how
   likely it is to be a red eye pixel.  We have already done this for you - you
   are receiving the scores and need to sort them in ascending order so that we
   know which pixels to alter to remove the red eye.

   Note: ascending order == smallest to largest

   Each score is associated with a position, when you sort the scores, you must
   also move the positions accordingly.

   Implementing Parallel Radix Sort with CUDA
   ==========================================

   The basic idea is to construct a histogram on each pass of how many of each
   "digit" there are.   
   
   Then we scan this histogram so that we know where to put
   the output of each digit.  For example, the first 1 must come after all the
   0s so we have to know how many 0s there are to be able to start moving 1s
   into the correct position.

   1) Histogram of the number of occurrences of each digit
   2) Exclusive Prefix Sum of Histogram
   3) Determine relative offset of each digit
        For example [0 0 1 1 0 0 1]
                ->  [0 1 0 1 2 3 2]
   4) Combine the results of steps 2 & 3 to determine the final
      output location for each element and move it there

   LSB Radix sort is an out-of-place sort and you will need to ping-pong values
   between the input and output buffers we have provided.  Make sure the final
   sorted results end up in the output buffer!  Hint: You may need to do a copy
   at the end.

 */

// =================================================================================================
__global__ void generatePredicate(const int *d_in, int *d_predicate, 
                                  const int size, const int digit)
{
  int myId = threadIdx.x + blockDim.x * blockIdx.x;
  int myItem = d_in[myId];
  int val = myItem>>digit;
  
  d_predicate[myId] = (val & 1);

}

// =================================================================================================
// Step efficient scan
__global__ void hillis_steele_algo(unsigned int* d_out, const int* d_in, size_t size) 
{
	extern __shared__ unsigned int temp[];
   
   int tid = threadIdx.x;
   
   int pout = 0, pin=1;
   
   temp[tid] = tid>0? d_in[tid-1]:0; //exclusive scan
	__syncthreads();

	//double buffered
	for (int offset = 1; offset < size; offset <<= 1) {
		pout = 1 - pout;
		pin = 1 - pout;
      if (tid >= offset) 
        temp[size*pout + tid] = temp[size*pin + tid]+temp[size*pin + tid - offset];
      else 
        temp[size*pout + tid] = temp[size*pin + tid];
		__syncthreads();
	}
	d_out[tid] = temp[pout*size + tid];
}


int hillis_steele_scan(unsigned int *d_scan, unsigned int *d_predicate, size_t numElems, const int BLOCK_SIZE)
{
  int threads = BLOCK_SIZE;
  int size = numElems;
  
  dim3 block(threads, 1, 1);
  dim3 grid(size/threads, 1, 1);  
  
  hillis_steele_algo <<<grid, block, 2 * BLOCK_SIZE*sizeof(unsigned int)>>>
                    (d_scan, d_predicate, numElems);
	cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());
  
  int *h_sum;
  cudaMemcpy(*h_sum, *d_scan[numElems-1], sizeof(unsigned int), cudaMemcpyDeviceToHost);



  return *h_sum;
}




// =================================================================================================
void your_sort(unsigned int* const d_inputVals,
               unsigned int* const d_inputPos,
               unsigned int* const d_outputVals,
               unsigned int* const d_outputPos,
               const size_t numElems)
{ 
  //TODO
  //PUT YOUR SORT HERE
  
  const int ARRAY_SIZE = numElems;
  
  const int maxThreadPerBlock = 1024;
  const int threads = maxThreadPerBlock;
  const int size = numElems;
  const int SIZE_BYTES = size * sizeof(unsigned int);
  
  const int BIN_COUNT = 2;
  const int BIN_BYTES = BIN_COUNT * sizeof(unsigned int);


    
  unsigned int *h_histogram[2];
  h_histogram[0]=0,h_histogram[1]=0;

  unsigned int *d_histogram;
  unsigned int *d_predicate;
  unsigned int *d_scan_0;
  unsigned int *d_scan_1;

  checkCudaErrors(cudaMalloc(&d_histogram, BIN_BYTES));
  checkCudaErrors(cudaMalloc(&d_predicate, SIZE_BYTES));
  checkCudaErrors(cudaMalloc(&d_scan_0, SIZE_BYTES));
  checkCudaErrors(cudaMalloc(&d_scan_1, SIZE_BYTES));
  
  
  dim3 block(threads, 1, 1);
  dim3 grid(size/threads, 1, 1);  
  
  for (size_t d = 0; d< sizeof(unsigned int); ++d)
  {
    
    
    // fill the predicate for COMPACT operation.
    // we alternate btw input and output
    if (d%2==0)
      generatePredicate<<<grid,block>>>(d_inputVals, d_predicate, size, d);
    else if (d%2==1)
      generatePredicate<<<grid,block>>>(d_outputVals, d_predicate, size, d);      
    cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());    

    // histogram to find number of 0s.
    
    // scan to find the position of 0s and 1s.
    unsigned int nOnes = hillis_steele_scan(unsigned int* d_out, const int* d_in, int size);




    // Create the histogram
    simple_histo<<<grid, block>>>(d_inputVals, val, nZeros);
       
    for (size_t i = 0; i< numElems; ++i)
    {
      Radix_sort<<<grid, block>>>(d_inputVals, d_inputPos, val, nZeros);
    }


  }


}
