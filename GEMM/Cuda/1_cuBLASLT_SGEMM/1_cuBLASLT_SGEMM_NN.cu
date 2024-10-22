
/*
Sample cuBLAS/GEMM code for general matrix multiplication
Babak Poursartip

*/

#include <iostream>
#include <cuda_runtime.h>
#include <cudablaslt.h>

#define CHECK_CUDA_ERROR(call) { \ 
  cudaError_t err = call; \
  if (err != cudaSuccess) { \
    std::cerr << "CUDA error in " << __FILE__ << ":" << __LINE__ << ": " << cudaGetErrorString(err) << std::endl; \
    exit(EXIT_FAILURE); \
  }\


  #define CHECK_CUBLAS_ERROR(call) { \ 
    cublasStatus_t err = call; \
    if (err != CUBLAS_STATUS_SUCCESS) { \
      std::cerr << "cuBLAS error in " << __FILE__ << ":" << __LINE__ << ": " << err << std::endl; \
      exit(EXIT_FAILURE); \
    }\
  }

 
int main() {
  std::cout << " test cublasLtMatmul SGEMM NN" << std::endl;
  // operation: C_MxN = alpha * A_MxK * B_KxN + beta * C_MxN

  // define sizes
  const int M = 1024, N = 1024, K = 1024;
  const int lda = M, ldb = K, ldc = M;

  // allocate host memory/matrices
  float *h_A, *h_B, *h_C;
  h_A = (float *)malloc(M * K * sizeof(float));
  h_B = (float *)malloc(K * N * sizeof(float));
  h_C = (float *)malloc(M * N * sizeof(float));

  // initialize matrices
  for (int i = 0; i < M * K; i++) {
    h_A[i] = 1.0f;
  }

  for (int i = 0; i < K * N; i++) {
    h_B[i] = 2.0f;
  }

  for (int i = 0; i < M * N; i++) {
    h_C[i] = 3.0f;
  }

  // allocate device memory
  CHECK_CUDA_ERROR(cudaMalloc(&d_A, M * K * sizeof(float)));
  CHECK_CUDA_ERROR(cudaMalloc(&d_B, K * N * sizeof(float)));
  CHECK_CUDA_ERROR(cudaMalloc(&d_C, M * N * sizeof(float)));

  // copy data to device
  CHECK_CUDA_ERROR(cudaMemcpy(d_A, h_A, M * K * sizeof(float), cudaMemcpyHostToDevice));
  CHECK_CUDA_ERROR(cudaMemcpy(d_B, h_B, K * N * sizeof(float), cudaMemcpyHostToDevice));
  CHECK_CUDA_ERROR(cudaMemcpy(d_C, h_C, M * N * sizeof(float), cudaMemcpyHostToDevice));

  // GEMM coefficients
  const float alpha = 1.5f, beta = 2.5f;
  

  // set up matrix descriptors
  cuBLASLtMatrixLayout_t Adesc, Bdesc, Cdesc;
  // cublasLtMatrixLayoutCreate: This function creates a matrix layout descriptor by allocating the memory needed to hold its opaque structure.
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutCreate(&Adesc, CUDA_R_32F, M, K, lda));
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutCreate(&Bdesc, CUDA_R_32F, K, N, ldb));
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutCreate(&Cdesc, CUDA_R_32F, M, N, ldc));


  // create cublasLt handle
  cublasLtHandle_t handle;
  CHECK_CUBLAS_ERROR(cublasLtCreate(&handle));

  // create operation descriptor
  cublasLtMatmulDesc_t operationDesc;
  CHECK_CUBLAS_ERROR(cublasLtMatmulDescCreate(&operationDesc, CUBLAS_OP_N, CUBLAS_OP_N, CUDA_R_32F));

  // Perform GEMM operation

  CHECK_CUBLAS_ERROR(cublasLtMatmul(handle, operationDesc, &alpha, d_A, Adesc, d_B, Bdesc, &beta, d_C, Cdesc, d_C, Cdesc, nullptr, nullptr, 0, 0));

  // Copy result back to host
  CHECK_CUDA_ERROR(cudaMemcpy(h_C, d_C, M * N * sizeof(float), cudaMemcpyDeviceToHost));

  // Free resources
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutDestroy(Adesc));
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutDestroy(Bdesc));
  CHECK_CUBLAS_ERROR(cublasLtMatrixLayoutDestroy(Cdesc));
  CHECK_CUBLAS_ERROR(cublasLtMatmulDescDestroy(operationDesc));
  CHECK_CUBLAS_ERROR(cublasLtDestroy(handle));
  CHECK_CUDA_ERROR(cudaFree(d_A));
  CHECK_CUDA_ERROR(cudaFree(d_B));
  CHECK_CUDA_ERROR(cudaFree(d_C));

  std::cout << "Result matrix C:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << C[i * N + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;



}  





