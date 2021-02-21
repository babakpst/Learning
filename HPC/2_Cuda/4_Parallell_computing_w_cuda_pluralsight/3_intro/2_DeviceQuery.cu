
//#include <iostream>
#include <cstdio>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

int main(){
printf("\n Let's start ... \n");

int count;
cudaGetDeviceCount(&count);

cudaDeviceProp prop;
for (int i = 0; i < count; ++ i)
{
  cudaGetDeviceProperties(&prop,i);
  printf(" Device: %d, %s\n", i,  prop.name);

  printf(" Compute Capability: %d.%d\n", prop.major, prop.minor);  
  

  printf(" Max grid dimensions: (%dx%dx%d)\n", prop.maxGridSize[0],
                                               prop.maxGridSize[1],
                                               prop.maxGridSize[2]);

  printf(" Max block dimensions: (%dx%dx%d)\n", prop.maxThreadsDim[0],
                                                prop.maxThreadsDim[1],
                                                prop.maxThreadsDim[2]);
  /*
  std::cout << " Device: " << i << prop.name << std::endl;
  std::cout << " Compute Capability: " << prop.major << "." << prop.minor << std::endl;  
  std::cout << " Max grid dimensions: (" << prop.maxGridSize[0] << "x" 
                                         << prop.maxGridSize[1] << "x"
                                         << prop.maxGridSize[2] << ")\n";
  std::cout << " Max block dimensions: (" << prop.maxThreadsDim[0] << "x" 
                                          << prop.maxThreadsDim[1] << "x"
                                          << prop.maxThreadsDim[2] << ")\n";
  */
}


printf("\n done \n");
return 0;
}
