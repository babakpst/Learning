

// Babak Poursartip
// 01/28/2021

// CUDA
//topic:


#include "cstdio"
#include <algorithm>
#include <functional>


// =================================
__global__ void addCuda( int *a,  int *b, int *c)
{
  int i = threadIdx.x; 
  c[i] = a[i] + b[i];
}

// =================================
void addIndex( int *a,  int *b, int *c, int i)
{
  c[i] = a[i] + b[i];
}
// =================================
void add( int *a,  int *b, int *c, const int &count)
{
  std::transform(a,a+count, b, c , std::plus<>{});
}

// =================================
int main(){
printf("\n starts ... \n");

const int count = 6;
int ha[]={5,2,5,8,7,6};
int hb[]={15,12,15,18,17,16};

// serial adding
int hc[count];
add(ha, hb, hc, count);
printf(" 1 ================\n");
std::for_each(hc,hc+count, [](int&c){printf("%d, ",c);});
printf("\n");

// add index
for (int i = 0; i < count; ++i)
  addIndex(ha, hb, hc, i);
printf(" 2 ================\n");
std::for_each(hc,hc+count, [](int&c){printf("%d, ",c);});
printf("\n");


// cuda adding
int size = count * sizeof(int);
int * da, *db, * dc;
cudaMalloc(&da, size);
cudaMalloc(&db, size);
cudaMalloc(&dc, size);

cudaMemcpy(da, ha, size, cudaMemcpyHostToDevice);
cudaMemcpy(db, hb, size, cudaMemcpyHostToDevice);

addCuda<<<1,count>>>(da, db, dc);

cudaMemcpy(hc, db, size, cudaMemcpyDeviceToHost);
printf(" 3 ================\n");
std::for_each(hc,hc+count, [](int&c){printf("%d, ",c);});
printf("\n");

cudaDeviceReset();

printf("\n finished. \n");

return 0;
}
