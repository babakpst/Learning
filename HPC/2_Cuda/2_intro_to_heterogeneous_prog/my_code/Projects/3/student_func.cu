
/* Udacity Homework 3
   HDR Tone-mapping

  Background HDR
  ==============

  A High Dynamic Range (HDR) image contains a wider variation of intensity
  and color than is allowed by the RGB format with 1 byte per channel that we
  have used in the previous assignment.  

  To store this extra information we use single precision floating point for
  each channel.  This allows for an extremely wide range of intensity values.

  In the image for this assignment, the inside of church with light coming in
  through stained glass windows, the raw input floating point values for the
  channels range from 0 to 275.  But the mean is .41 and 98% of the values are
  less than 3!  This means that certain areas (the windows) are extremely bright
  compared to everywhere else.  If we linearly map this [0-275] range into the
  [0-255] range that we have been using then most values will be mapped to zero!
  The only thing we will be able to see are the very brightest areas - the
  windows - everything else will appear pitch black.

  The problem is that although we have cameras capable of recording the wide
  range of intensity that exists in the real world our monitors are not capable
  of displaying them.  Our eyes are also quite capable of observing a much wider
  range of intensities than our image formats / monitors are capable of
  displaying.

  Tone-mapping is a process that transforms the intensities in the image so that
  the brightest values aren't nearly so far away from the mean.  That way when
  we transform the values into [0-255] we can actually see the entire image.
  There are many ways to perform this process and it is as much an art as a
  science - there is no single "right" answer.  In this homework we will
  implement one possible technique.

  Background Chrominance-Luminance
  ================================

  The RGB space that we have been using to represent images can be thought of as
  one possible set of axes spanning a three dimensional space of color.  We
  sometimes choose other axes to represent this space because they make certain
  operations more convenient.

  Another possible way of representing a color image is to separate the color
  information (chromaticity) from the brightness information.  There are
  multiple different methods for doing this - a common one during the analog
  television days was known as Chrominance-Luminance or YUV.

  We choose to represent the image in this way so that we can remap only the
  intensity channel and then recombine the new intensity values with the color
  information to form the final image.

  Old TV signals used to be transmitted in this way so that black & white
  televisions could display the luminance channel while color televisions would
  display all three of the channels.
  

  Tone-mapping
  ============

  In this assignment we are going to transform the luminance channel (actually
  the log of the luminance, but this is unimportant for the parts of the
  algorithm that you will be implementing) by compressing its range to [0, 1].
  To do this we need the cumulative distribution of the luminance values.

  Example
  -------

  input : [2 4 3 3 1 7 4 5 7 0 9 4 3 2]
  min / max / range: 0 / 9 / 9

  histo with 3 bins: [4 7 3]

  cdf : [4 11 14]


  Your task is to calculate this cumulative distribution by following these
  steps.

*/

#include "utils.h"
#include <stdlib.h>

__global__ void reduce_kernel(const float* const d_in, float* d_out, int type)
{

   // sdata is allocated in the kernel call: 3rd arg to <<<b, t, shmem>>>
   extern __shared__ float sdata[];

   int myId = threadIdx.x + blockDim.x * blockIdx.x;
   int tid  = threadIdx.x;

   // load shared mem from global mem
   sdata[tid] = d_in[myId];
   __syncthreads();            // make sure entire block is loaded!

   // do reduction in shared mem
   for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1)
   {
      if (tid < s)
      {
        if (type == 0)
          sdata[tid] = min(sdata[tid], sdata[tid + s]);
        else if (type == 1)
          sdata[tid] = max(sdata[tid], sdata[tid + s]);
      }
      __syncthreads();        // make sure all adds at one stage are done!
   }

   // only thread 0 writes result for this block back to global mem
   if (tid == 0)
   {
      d_out[blockIdx.x] = sdata[0];
   }  

}


__global__ void simple_histo(int *d_bins, const float* const d_in, const int numBins, 
   const float lumMin, const float lumRange)
{
      int myId = threadIdx.x + blockDim.x * blockIdx.x;
      float myItem = d_in[myId];
      int bin = (d_in[myId] - lumMin) / lumRange * numBins;
      int myBin  = min(numBins-1, bin);
      //printf(" MYID: %d- mybin: %d- myItem: %f, lumMin: %f, lumRange: %f \n", myId, myBin, myItem, lumMin, lumRange);
      atomicAdd(&(d_bins[myBin]), 1);
}

// Step efficient scan
__global__ void hillis_steele_algo(unsigned int* d_out, const int* d_in, int size) 
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


void your_histogram_and_prefixsum(const float* const d_logLuminance,
                                  unsigned int* const d_cdf,
                                  float &min_logLum,
                                  float &max_logLum,
                                  const size_t numRows,
                                  const size_t numCols,
                                  const size_t numBins)
{
  //TODO
  /*Here are the steps you need to implement
    1) find the minimum and maximum value in the input logLuminance channel
       store in min_logLum and max_logLum
    2) subtract them to find the range
    3) generate a histogram of all the values in the logLuminance channel using
       the formula: bin = (lum[i] - lumMin) / lumRange * numBins
    4) Perform an exclusive scan (prefix sum) on the histogram to get
       the cumulative distribution of luminance values (this should go in the
       incoming d_cdf pointer which already has been allocated for you)       */

  
  const int maxThreadPerBlock = 1024;
  int threads = maxThreadPerBlock;
  int size = numCols*numRows;
  int size_byte = size * sizeof(float);
  float* d_intermediate, *d_min, *d_max;
  
  checkCudaErrors(cudaMalloc(&d_intermediate, size_byte));
  checkCudaErrors(cudaMalloc(&d_min, sizeof(float)));
  checkCudaErrors(cudaMalloc(&d_max, sizeof(float)));

  dim3 block(threads, 1, 1);
  dim3 grid(size / threads, 1, 1);
  
  // 1 =============================================================================================
  reduce_kernel <<<grid, block, threads*sizeof(float)>>> (d_logLuminance, d_intermediate, 0);
  reduce_kernel <<<grid, block, threads*sizeof(float)>>> (d_intermediate, d_min, 0);
  reduce_kernel <<<grid, block, threads*sizeof(float)>>> (d_logLuminance, d_intermediate, 1);
  reduce_kernel <<<grid, block, threads*sizeof(float)>>> (d_intermediate, d_max, 1);
  cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());
  checkCudaErrors(cudaMemcpy(&min_logLum, d_min, sizeof(float), cudaMemcpyDeviceToHost));
  checkCudaErrors(cudaMemcpy(&max_logLum, d_max, sizeof(float), cudaMemcpyDeviceToHost));
  printf(" cuda min: %f, max: %f \n", min_logLum, max_logLum); 
 
  checkCudaErrors(cudaFree(d_intermediate));

  // 2 =============================================================================================
  float lumRange =  max_logLum - min_logLum;

  // 3 =============================================================================================
  int* d_histogram;
  size_byte = numBins * sizeof(int);
  checkCudaErrors(cudaMalloc(&d_histogram, size_byte));
  checkCudaErrors(cudaMemset(d_histogram, 0, numBins * sizeof(int)));
  simple_histo<<<grid, block>>>(d_histogram, d_logLuminance, numBins, min_logLum, lumRange);
  cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());
  
  int *h_histogram=(int *) malloc(sizeof( int)*numBins);
  checkCudaErrors(cudaMemcpy(h_histogram, d_histogram, sizeof( int)*numBins, cudaMemcpyDeviceToHost));
  
  printf("histogram \n");
  for (size_t i = 0; i < numBins; ++i) {
   printf(" %4ld: %d-",  i, h_histogram[i]);
   if (i%10==0) printf(" \n");
 }
 printf(" \n");

  // 4 =============================================================================================
  // scan
  hillis_steele_algo <<<1, numBins, 2*numBins*sizeof(int) >>> (d_cdf, d_histogram, numBins);
  
  unsigned int *h_cdf=(unsigned int *) malloc(sizeof(unsigned int)*numBins);
  checkCudaErrors(cudaMemcpy(h_cdf, d_cdf, sizeof(unsigned int)*numBins, cudaMemcpyDeviceToHost));
  
  printf("bin \n");
  for (size_t i = 1; i < numBins; ++i) {
   printf(" %4ld: %d-",  i, h_cdf[i]);
   if (i%10==0) printf(" \n");
 }
 printf(" \n");

}
