#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <pthread.h>
#include <iostream>
using namespace std;

typedef void *(*func)(void*);

pthread_t startThread(func f, void* data)
{
  pthread_t t;
  pthread_create(&t, NULL, f, data);
  return t;
}

void endThread(pthread_t t)
{
  pthread_join(t, NULL);
}

struct work
{
  int device;
  int offset;
  int count;
  int *a;
  int *b;
  int *c;
};

__global__ void add(const int* a, const int* b, int* c)
{
  int tid = threadIdx.x;
  c[tid] = a[tid] + b[tid];
}

void* doWork(void* spec)
{
  work* w = reinterpret_cast<work*>(spec);

  // set device if not primary
  if (w->device != 0)
  {
    cudaSetDevice(w->device);
    cudaSetDeviceFlags(cudaDeviceMapHost);
  }

  // get device pointers for a..c
  int *da, *db, *dc;
  cudaHostGetDevicePointer(&da, w->a, 0);
  cudaHostGetDevicePointer(&db, w->b, 0);
  cudaHostGetDevicePointer(&dc, w->c, 0);

  da += w->offset;
  db += w->offset;
  dc += w->offset;

  add<<<1,w->count/2>>>(da,db,dc);

  return NULL;
}

int main()
{
  int dc;
  cudaGetDeviceCount(&dc);

  cout << "We have " << dc << " devices" << endl;

  for (int i = 0; i < dc; i++)
  {
    cudaDeviceProp props;
    cudaGetDeviceProperties(&props, i);

    cout << "Device " << i << ": " << props.name << endl;
    cout << "Compute capability " << props.major << "." << props.minor << endl;
    cout << "Can map host memory? " << props.canMapHostMemory << endl;
  }

  // allocate a, b and c as zero-copy
  int count = 128;
  int *a, *b, *c;
  cudaSetDevice(0);
  cudaSetDeviceFlags(cudaDeviceMapHost);
  cudaHostAlloc(&a, count * sizeof(int),
    cudaHostAllocMapped |
    cudaHostAllocPortable |
    cudaHostAllocWriteCombined);
  cudaHostAlloc(&b, count * sizeof(int),
    cudaHostAllocMapped |
    cudaHostAllocPortable |
    cudaHostAllocWriteCombined);
  cudaHostAlloc(&c, count * sizeof(int),
    cudaHostAllocMapped |
    cudaHostAllocPortable |
    cudaHostAllocWriteCombined);

  // write some values to a and b
  for (int i = 0; i < count; i++)
  {
    a[i] = i;
    b[i] = count-i;
  }

  // specify what needs to be done and where
  work tasks[2];
  tasks[0].device = 0;
  tasks[0].offset = 0;
  tasks[1].device = 1;
  tasks[1].offset = count/2;
  tasks[0].count = tasks[1].count = count;
  tasks[0].a = tasks[1].a = a;
  tasks[0].b = tasks[1].b = b;
  tasks[0].c = tasks[1].c = c;

  // start work on this + other thread
  pthread_t t = startThread(doWork, &tasks[1]);
  doWork(&tasks[0]);
  endThread(t);

  // print the results
  for (int i = 0; i < count; i++)
  {
    cout << c[i] << "\t";
  }

  // free up memory
  cudaFreeHost(a);
  cudaFreeHost(b);
  cudaFreeHost(c);

  //getchar();

  return 0;
}
