// ====================
__global__
void deviceKernel(int *a, int N)
{
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  int stride = blockDim.x * gridDim.x;

  for (int i = idx; i < N; i += stride)
  {
    a[i] = 1;
  }
}

// ====================
void hostFunction(int *a, int N)
{
  for (int i = 0; i < N; ++i)
  {
    a[i] = 1;
  }
}

// ====================
int main()
{

  int N = 2<<24;
  size_t size = N * sizeof(int);
  int *a;
  cudaMallocManaged(&a, size);

    /*
   * Conduct experiments to learn more about the behavior of
   * `cudaMallocManaged`.
   *
   *1- What happens when unified memory is accessed only by the GPU?
   *2- What happens when unified memory is accessed only by the CPU?
   *3- What happens when unified memory is accessed first by the GPU then the CPU?
   *4- What happens when unified memory is accessed first by the CPU then the GPU?
   *
   * Hypothesize about UM behavior, page faulting specificially, before each
   * experiment, and then verify by running `nsys`.
   */

  
  //1  
  //deviceKernel<<<120,128>>>(a,N);
  //cudaDeviceSynchronize();
  
  //2
  //hostFunction(a,N);

  //3
  hostFunction(a,N);
  deviceKernel<<<120,128>>>(a,N);
  cudaDeviceSynchronize();
  
  //4
  deviceKernel<<<12,512>>>(a,N);
  cudaDeviceSynchronize();
  hostFunction(a,N);

  cudaFree(a);
}

