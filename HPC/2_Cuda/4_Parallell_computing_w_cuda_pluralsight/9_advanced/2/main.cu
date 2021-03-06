#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <pthread.h>

#include <cmath>
#include <iostream>


// ===================
typedef void *(*func)(void*); // bbk what is it?

// ===================
pthread_t startThread(func f, void *data)
{
  pthread_t t;
  pthread_create(&t, NULL, f, data);
  return t;
}

// ===================
void endThread(pthread_t t)
{
  pthread_join(t, NULL);
}

// ===================
struct work
{
  int device;
  int offset;
  int count;
  int *a, *b, *c;
};

// ===================
__global__ void add(const int *a, const int *b, int *c)
{
  int tid = threadIdx.x;
  c[tid] = a[tid] + b[tid];
}
 
// ===================
void* dowork(void* spec)
{
  work *w= reinterpret_cast<work*>(spec); 


  if(w->device != 0)
  {
    cudaSetDevice(w->device);
    cudaSetDeviceFlags(cudaDeviceMapHost);
  }


  int *da, *db, *dc;
  cudaHostGetDevicePointer(&da, w->a, 0);
  cudaHostGetDevicePointer(&db, w->b, 0);
  cudaHostGetDevicePointer(&dc, w->c, 0);

  da += w->offset;
  db += w->offset;
  dc += w->offset;

  add<<<1,w->count/2>>>(da, db, dc);

return NULL;

}

// ===================
int main(){

std::cout << "starts ...\n";

  int dc;
  cudaGetDeviceCount(&dc);

  std::cout << "no. of devices: " << dc << std::endl;

  for (int i = 0; i < dc; ++i)
  {
    cudaDeviceProp props;
    cudaGetDeviceProperties(&props, i);

    std::cout << "Device: " << i << " - " << props.name;
    std::cout << "compute capability: " << props.major << "." << props.minor << std::endl;
    std::cout << " map history memory? " << props.canMapHostMemory << std::endl;
  }

  // allocate
  int count = 128;
  int *a, *b, *c;
  cudaSetDevice(0);
  cudaSetDeviceFlags(cudaDeviceMapHost);
  cudaHostAlloc(&a, count*sizeof(int), cudaHostAllocMapped | cudaHostAllocPortable | cudaHostAllocWriteCombined);
  cudaHostAlloc(&b, count*sizeof(int), cudaHostAllocMapped | cudaHostAllocPortable | cudaHostAllocWriteCombined);
  cudaHostAlloc(&c, count*sizeof(int), cudaHostAllocMapped | cudaHostAllocPortable | cudaHostAllocWriteCombined);

//
  for (int i = 0; i < count; ++i)
  {
      a[i] = i;
      b[i] = count-i;
  }

  // 
  work task[2];
  task[0].device = 0;
  task[0].offset = 0;
  task[1].device = 1;
  task[1].offset = count/2;
  task[0].count = task[1].count = count;
  task[0].a = task[1].a = a;
  task[0].b = task[1].b = b;
  task[0].c = task[1].c = c;

  // creating two threads for each task.
  pthread_t t = startThread(dowork, &task[1]);
  dowork(&task[0]);
  endThread(t);


  // output
  for (int i = 0; i<count; ++i)
  {
  std::cout << c[i] << "\t";
  }

  cudaFreeHost(a);
  cudaFreeHost(b);
  cudaFreeHost(c);


std::cout << "\nends \n";
return 0;


}




































