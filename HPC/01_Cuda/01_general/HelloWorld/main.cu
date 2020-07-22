// Babak Poursartip
// 30 Oct 2019

#include <sstream>

__global__ void mykernel(void) {
	printf("Hello, World!\n");
}

int main(void){
	mykernel<<<5,1>>>();
	cudaDeviceSynchronize();
	return 0;
}
