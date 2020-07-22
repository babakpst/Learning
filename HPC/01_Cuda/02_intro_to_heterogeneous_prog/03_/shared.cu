
//=================================================
__global__ void local_memory(float in){

float f; // f in local memory and private to each thread.
f=in;    // "in" is in local memory and private to each thread.

}

//=================================================
__global__ void global_memory(float *array){

array[threadIdx.x] = 2.0f* (float) threadIdx.x;

}

//=================================================
__global__ void  shared_memory(float *array){

// local var, private to each thread
int i, index=threadIdx.x;
float average, sum = 0.0f;

// __shared__ variables are visible to all threads in the threads block 
// and have the lifetime of the thread block.
__shared__ float sh_arr[128];

// copy datda from array in global memory to sh_arr in shared memory.
sh_arr[128] = array[index];

__syncthreads();  // ensures all the writes to shared memory have completed.

// find the average of all previous elements
for(i=0; i < index; ++i) sum+= sh_arr[i] ; // it is faster to do the computation on the shared memory (sh_arr) rather than the global memory (array).
average = sum/(index+1.0f);

//if array[index] is greater than the average of array[0...index-1], replace it with the average.
// since array{} is in global memory, this change will be seen by the host!!! ( and potentially by other thread blocks!!!!)

if (array[index]>average) array[index]=average;

// the following piece of code has no effect bcs it modifies shared memory but the resulting modified data is never copied back to the global memory and vanishes when the thread block completes.
sh_arr[index] = 3.14;

}

//=================================================
int main(){

// for local memory
local_memory<<<1,128>>>(2.0);

// for global memory
float h_arr[128];
float *d_arr;

// allocate global memory on the device, 
cudaMalloc((void **) &d_arr, 128*sizeof(float));

// copy data from the host memory to the device memory
cudaMemcpy((void*)d_arr, (void*)h_arr, 128*sizeof(float), cudaMemcpyHostToDivice);

// launch the kernel
global_memory<<<1,128>>>(d_arr);

// copy back from the device memory to the host memory
cudaMemcpy((void*)h_arr, (void*)d_arr, 128*sizeof(float), cudaMemcpyDeviceToHost);


// shared memory
shared_memory<<<1,128>>>(d_arr);

return 0;
}