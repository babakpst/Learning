

// Babak Poursartip
// 02/21/2021

// CUDA
//topic: shared memory


#include <cstdio>
#include <ctime>
#include <iostream>

#include <curand.h>

// ==============================
__global__ void sumSingleBlock(int *d)
{

  extern __shared__ int dcopy[];

  int tid = threadIdx.x;

  // copy d to dcopy
  dcopy[tid*2] = d[tid*2];
  dcopy[tid*2+1] = d[tid*2+1];


  // tc: number of participating threads
  //for (int tc = blockDim.x; tc > 0; tc >>=1) // changes the number of threads by half(tc>>=1)
  for (int tc = blockDim.x, stepSize = 1; tc > 0; tc /=2, stepSize *=2) // changes the number of threads by half(tc>>=1)
  {
    // thread must be allowed to write
    if (tid < tc)
    {
      int pa =  tid * stepSize * 2;
      int pb = pa + stepSize;
      dcopy[pa] += dcopy[pb];

# if __CUDA_ARCH__>=200
    printf("%d, %d, %d, %d, %d \n", tid, tc, stepSize, pa, pb);
#endif
    }    
  }
  if (tid == 0) d[0] = dcopy[0];
}


// ==============================
int main()
{
printf(" starts \n");

const int count  = 32;
const int size = count * sizeof(int);

int h[count];

for (int i = 0; i < count; ++i)
  h[i] = i + 1;
  
int *d;
cudaMalloc(&d, size);
cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

sumSingleBlock<<<1, count/2, size>>>(d);

int result;
cudaMemcpy(&result, d, sizeof(int), cudaMemcpyDeviceToHost);
std::cout << " sum: "<< result << std::endl;

cudaFree(d);

printf(" done \n");
return 0;
} 