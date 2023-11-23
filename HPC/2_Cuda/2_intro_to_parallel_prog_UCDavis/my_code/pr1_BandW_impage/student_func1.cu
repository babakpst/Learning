// Homework 1
// Color to Greyscale Conversion

//A common way to represent color images is known as RGBA - the color
//is specified by how much Red, Grean and Blue is in it.
//The 'A' stands for Alpha and is used for transparency, it will be
//ignored in this homework.

//Each channel Red, Blue, Green and Alpha is represented by one byte.
//Since we are using one byte for each color there are 256 different
//possible values for each color.  This means we use 4 bytes per pixel.

//Greyscale images are represented by a single intensity value per pixel
//which is one byte in size.

//To convert an image from color to grayscale one simple method is to
//set the intensity to the average of the RGB channels.  But we will
//use a more sophisticated method that takes into account how the eye 
//perceives color and weights the channels unequally.

//The eye responds most strongly to green followed by red and then blue.
//The NTSC (National Television System Committee) recommends the following
//formula for color to greyscale conversion:

//I = .299f * R + .587f * G + .114f * B

//Notice the trailing f's on the numbers which indicate that they are 
//single precision floating point constants and not double precision
//constants.

//You should fill in the kernel as well as set the block and grid sizes
//so that the entire image is processed.

#include "utils.h"

__global__
void rgba_to_greyscale(const uchar4* const rgbaImage,
                       unsigned char* const greyImage,
                       int numRows, int numCols)
{
  //TODO
  //Fill in the kernel to convert from color to greyscale
  //the mapping from components of a uchar4 to RGBA is:
  // .x -> R ; .y -> G ; .z -> B ; .w -> A
  //
  //The output (greyImage) at each pixel should be the result of
  //applying the formula: output = .299f * R + .587f * G + .114f * B;
  //Note: We will be ignoring the alpha channel for this conversion

  //First create a mapping from the 2D block and grid locations
  //to an absolute 2D location in the image, then use that to
  //calculate a 1D offset

  
  size_t threadsPerBlock       = blockDim.x * blockDim.y * blockDim.z;
  size_t threadPositionInBlock = threadIdx.x +
                              blockDim.x * threadIdx.y +
                              blockDim.x * blockDim.y * threadIdx.z;

  size_t blockPositionInGrid   = blockIdx.x +
                              gridDim.x * blockIdx.y +
                              gridDim.x * gridDim.y * blockIdx.z;

  size_t tid = blockPositionInGrid * threadsPerBlock + threadPositionInBlock;
  
  /*
  int tid = threadIdx.x;
  int offset = blockIdx.x * blockDim.x;
  int gid = tid + offset;
  tid = gid;
  */
  /*  
  printf("gridDim.x: %d, gridDim.y: %d, gridDim.z: %d, blockDim.x: %d, blockDim.y: %d, blockDim.z: %d, blockIdx.x: %d, blockIdx.y: %d, blockIdx.z: %d, threadIdx.x: %d, threadIdx.y: %d, threadIdx.z: %d, tid: %d \n",
          gridDim.x, gridDim.y, gridDim.z, 
          blockDim.x, blockDim.y, blockDim.z, 
          blockIdx.x, blockIdx.y, blockIdx.z, 
          threadIdx.x, threadIdx.y, threadIdx.z, 
          tid);
  */
  if (tid<numCols*numRows){
  uchar4 rgba = rgbaImage[tid];
  float channelSum = .299f * rgba.x + .587f * rgba.y + .114f * rgba.z;
  greyImage[tid] = channelSum;
  }
  
}

void your_rgba_to_greyscale(const uchar4 * const h_rgbaImage, uchar4 * const d_rgbaImage,
                            unsigned char* const d_greyImage, size_t numRows, size_t numCols)
{
  //You must fill in the correct sizes for the blockSize and gridSize
  //currently only one block with one thread is being launched
  const dim3 blockSize(128, 1, 1);  //TODO
  const dim3 gridSize(numRows*numCols/128+1, 1, 1);  //TODO
  //const dim3 blockSize(numCols, 1, 1);  //TODO
  //const dim3 gridSize(numRows, 1, 1);  //TODO
  rgba_to_greyscale<<<gridSize, blockSize>>>(d_rgbaImage, d_greyImage, numRows, numCols);
  
  cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());

}
