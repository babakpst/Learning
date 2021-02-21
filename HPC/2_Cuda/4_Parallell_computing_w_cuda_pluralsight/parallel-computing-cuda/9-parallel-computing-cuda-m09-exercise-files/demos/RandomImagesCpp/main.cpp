#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cuda.h"
#include "curand.h"
#include <Windows.h>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void myReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}    

vector<string> unaryFunctions;
vector<string> binaryFunctions;

void initUnaryFunctions()
{
  unaryFunctions.push_back("sinf(xx)");
  unaryFunctions.push_back("cosf(xx)");
  unaryFunctions.push_back("sinhf(xx)");
  unaryFunctions.push_back("coshf(xx)");
  unaryFunctions.push_back("tanhf(xx)");
  unaryFunctions.push_back("(xx > 0.0f ? log(xx) : -log(-xx))");
  unaryFunctions.push_back("(xx > 0.0f ? sqrt(xx) : -sqrt(-xx))");
  unaryFunctions.push_back("(xx == 0.0f ? x : 1.0f/xx)");
  unaryFunctions.push_back("expf(xx)");
}

void initBinaryFunctions()
{
  binaryFunctions.push_back("(xx+yy)");
  binaryFunctions.push_back("(xx-yy)");
  binaryFunctions.push_back("(xx*yy)");
  binaryFunctions.push_back("(yy == 0.f ? xx : xx/yy)");
  binaryFunctions.push_back("powf(xx,yy)");
  binaryFunctions.push_back("powf(yy,xx)");
  binaryFunctions.push_back("(xx < yy ? xx : yy)");
  binaryFunctions.push_back("(xx > yy ? xx : yy)");
}

void generateRandomFunction(ostringstream& str, int depth)
{
  int r = rand() % 100;
  if (depth < 2)
  {
    if (r > 10)
    {
      int i = rand() % 2;
      str << ((i == 0) ? "x" : "y");
    } 
    else 
    {
      float f = ((float)rand() / (float)RAND_MAX);
      str << f << "f";
    }
  } 
  else 
  {
    if (r < 5)
    {
      int i = rand() % 2;
      str << ((i == 0) ? "x" : "y");
    }
    else if (r > 50)
    {
      ostringstream x;
      generateRandomFunction(x, depth-1);
      // make it unary
      int i = rand() % unaryFunctions.size();
      string f(unaryFunctions[i]);
      myReplace(f, "xx", x.str());
      str << f;
    } else {
      string lhs, rhs;
      do {
        ostringstream x, y;
        generateRandomFunction(x, depth-1);
        generateRandomFunction(y, depth-1);
        lhs = x.str();
        rhs = y.str();
      } while (lhs.compare(rhs) == 0);
      // make it binary
      int i = rand() % binaryFunctions.size();
      string f(binaryFunctions[i]);
      myReplace(f, "xx", lhs);
      myReplace(f, "yy", rhs);
      str << f;
    }
  }
}

void createRandomKernel(char* dir)
{
  // generate a random function
  ostringstream oss;
  generateRandomFunction(oss, 8); // <-- try changing this
  string s = string("double z = ") + oss.str() + string(";");

  // splice it into gen.cu
  ifstream ifs("gen.cu");
  stringstream ss;
  ss << ifs.rdbuf();
  string source = ss.str();
  myReplace(source, "//placeholder", s);

  // write the new kernel
  ofstream ofs("temp.cu");
  ofs << source;
  ofs.flush();
  ofs.close();

  // compile the new kernel
  STARTUPINFO si;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  PROCESS_INFORMATION pi;
  ZeroMemory(&pi, sizeof(pi));
  HANDLE process;
  CreateProcess("maketemp.bat", NULL,
    NULL, NULL, TRUE,
    NORMAL_PRIORITY_CLASS, NULL, dir, &si, &pi);
  WaitForSingleObject(pi.hProcess,INFINITE);
}

extern "C" __declspec(dllexport) void GenerateBitmap(unsigned char* dst)
{
  initUnaryFunctions();
  initBinaryFunctions();

  srand((unsigned)time(0));

  char dir[MAX_PATH];
  GetCurrentDirectory(MAX_PATH, dir);
  
  createRandomKernel(dir);

  CUresult err = cuInit(0);
  CUdevice device;
  err = cuDeviceGet(&device, 0);
  CUcontext ctx;
  err = cuCtxCreate(&ctx, 0, device);

  CUmodule module;
  err = cuModuleLoad(&module, "temp.ptx");

  CUfunction f;
  err = cuModuleGetFunction(&f, module, "_Z6kernelPhPKf");

  int dim = 512;
  int size = dim * dim * 4;

  unsigned char* src;
  cudaMalloc(&src, size);

  float* factors;
  cudaMalloc(&factors, 9 * sizeof(float));
  curandGenerator_t gen;
  curandCreateGenerator(&gen, curandRngType::CURAND_RNG_PSEUDO_MTGP32);
  curandGenerateUniform(gen, factors, 9);

  void *args[2] = { &src, &factors };
  cuLaunchKernel(f, dim, 1, 1, dim, 1, 1, 0, 0, args, 0);

  cudaMemcpy(dst, src, size, cudaMemcpyDeviceToHost);
  cudaFree(src);

  cuCtxDetach(ctx);
}