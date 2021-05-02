
/*
Babak Poursartip
02/27/2021

CUDA
topic: pinned memory

- Instead of using malloc or new to allocation memory on the CPU(host), we use cudaHostAlloc(). This will allocate a pinned memory on the host.

- To free the memory, we use cudaFreeHost, instead of delete to deallocate. 

- The disadvantage is that you cannot swap the memory to the disk & we need to have enough memory to use this memory. 

*/

#include <iostream>


// ==============================
float timing(bool pinned, bool toDevice)
{

  std::cout << " p: " << pinned <<" t: " << toDevice << std::endl;
  const int count = 1 << 20;
  const int iterations = 1 << 6;
  const int size = count * sizeof(int);
  
  cudaEvent_t start, end;

  int *d, *h;

  float elapsed;
  cudaError_t status;
  
  cudaEventCreate(&start);
  cudaEventCreate(&end);
  
  cudaMalloc(&d, size);
  if(pinned) 
    cudaHostAlloc(&h, size, cudaHostAllocDefault);
  else 
    h = new int[count];
    
  cudaEventRecord(start);
  
  for (int i = 0; i < iterations; ++i)
  {
    if (toDevice)
      status = cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);
    else
      status = cudaMemcpy(h, d, size, cudaMemcpyDeviceToHost);
  }

  cudaEventRecord(end);
  cudaEventSynchronize(end);
  
  cudaEventElapsedTime(&elapsed, start, end); 
  
  if(pinned)
    cudaFreeHost(h);
  else
    delete[] h;
    
    
  cudaFree(d);
  cudaEventDestroy(start);
  cudaEventDestroy(end);  
  
  return elapsed;
}

// ==============================
int main()
{
printf(" starts \n");

std::cout << "From device - paged memory: \t" << timing(false, false) << std::endl;
std::cout << "To device -   paged memory: \t"   << timing(false, true) << std::endl;
std::cout << "From device - pinned memory: \t" << timing(true, false) << std::endl;
std::cout << "To device -   pinned memory: \t"   << timing(true, true) << std::endl;

printf(" done \n");
return 0;
} 
