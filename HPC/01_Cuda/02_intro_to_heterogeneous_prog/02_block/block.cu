

/*

Babak Poursartip
05/14/2020

*/

#include <stdio.h>

__global__
void hello(){

printf("I am: %d %d \n",threadIdx.x, blockIdx.x);

}


int main(){

printf(" code start ... \n");

dim3 blocks(16,1,1);
dim3 threads(1,1,1);

hello<<<blocks,threads>>>();
cudaDeviceSynchronize();
printf(" end here. \n");

return 0;
}
