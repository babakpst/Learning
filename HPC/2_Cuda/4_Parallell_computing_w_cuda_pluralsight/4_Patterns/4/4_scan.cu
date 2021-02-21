
// Babak Poursartip
// 02/14/2021

// CUDA
//topic: scan


#include <cstdio>
#include <ctime>
#include <iostream>



// ==============================
__global__ void sum(int *d)
{
  int tds = blockDim.x;
  int tid = threadIdx.x;
  // tc: total number of threads

  for (int tc = tds, stepSize = 1; tc > 0; tc /=2, stepSize *=2) // changes the number of threads by half(tc>>=1)
  {
    // thread must be allowed to write
    if (tid < tc)
    {
      d[tid+stepSize] += d[tid];

# if __CUDA_ARCH__>=200
      printf("%d, %d, %d, %d \n", tds, tid, stepSize, tc);
#endif
    }    
    tc -=stepSize;
  }
}


// ==============================
int main()
{
printf(" starts \n");

const int count  = 16;
const int size = count * sizeof(int);

int h[count];

for (int i = 0; i < count; ++i)
  h[i] = i + 1;
  
int *d;
cudaMalloc(&d, size);
cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

sum<<<1, count-1>>>(d);


cudaMemcpy(h, d, size, cudaMemcpyDeviceToHost);

for (int i = 0; i < count;  ++i)
  std::cout << h[i] << " ";
  std::cout << std::endl;

cudaFree(d);

printf(" done \n");
return 0;
} 
