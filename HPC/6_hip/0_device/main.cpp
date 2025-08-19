

#include <hip/hip_runtime.h>
#include <iostream>


int main(){

  std::cout << " hip device commands " << std::endl;

  // querry device count
  int numberOfDevices;
  hipGetDeviceCount(&numberOfDevices);
  std::cout << " number of devices: " << numberOfDevices << std::endl;
  
  int device;
  hipGetDevice(&device);
  std::cout << " current device: " << device << std::endl;

  int deviceID = 1;
  hipSetDevice(deviceID);
  
  
  hipGetDevice(&device);
  std::cout << " current device: " << device << std::endl;

  hipDeviceProp_t devProp;
  hipGetDeviceProperties(&devProp, deviceID);
  std::cout << "    name: " << devProp.name << std::endl <<
    "    gcn arch: " << devProp.gcnArchName << std::endl <<
    
    std::endl;


  return 0;
}
