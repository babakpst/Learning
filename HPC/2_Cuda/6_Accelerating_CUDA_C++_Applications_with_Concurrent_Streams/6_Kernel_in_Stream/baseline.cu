
#include <cstdint>
#include <iostream>
#include "helpers.cuh"
#include "encryption.cuh"

// Host function.
void encrypt_cpu(uint64_t * data, uint64_t num_entries, 
                 uint64_t num_iters, bool parallel=true) {

    // Use OpenMP to use all available CPU cores.
    #pragma omp parallel for if (parallel)
    for (uint64_t entry = 0; entry < num_entries; entry++)
        // Permute each data entry the number of iterations and then write result to data.
        data[entry] = permute64(entry, num_iters);
}

// Device function.
__global__ 
void decrypt_gpu(uint64_t * data, uint64_t num_entries, 
                 uint64_t num_iters) {

    const uint64_t thrdID = blockIdx.x*blockDim.x+threadIdx.x;
    const uint64_t stride = blockDim.x*gridDim.x;

    //printf(" checkpoint i0\n");

    // Utilize grid-stride loop for arbitrary data sizes.
    for (uint64_t entry = thrdID; entry < num_entries; entry += stride)
        // Unpermute each data entry the number of iterations then write result to data.
        data[entry] = unpermute64(data[entry], num_iters);
    //printf(" checkpoint i1\n");

}

// Host function.
bool check_result_cpu(uint64_t * data, uint64_t num_entries,
                      bool parallel=true) {

    uint64_t counter = 0;

    #pragma omp parallel for reduction(+: counter) if (parallel)
    for (uint64_t entry = 0; entry < num_entries; entry++)
    
        // Because we created initial data values by ranging from 0 to N-1,
        // and because encrypting and decrypting is symmetrical,
        // then each data entry should be equal to `entry`.
        counter += data[entry] == entry;

    // True if all values have been correctly decrypted.
    return counter == num_entries;
}

int main (int argc, char * argv[]) {
    // This file will be used to cache encryption results
    // so we don't have to wait on the CPU every time.
    //const char * encrypted_file = "/dli/task/encrypted";
    const char * encrypted_file = "hello";
    //"/home/babak/Codes/Learning/HPC/2_Cuda/6_Accelerating_CUDA_C++_Applications_with_Concurrent_Streams/3_Application/hello";

    // Timer instance to be used for sections of the application.
    Timer timer;
    
    // Timer instance to be used for total time on the GPU(s).
    Timer overall;

    const uint64_t num_entries = 1UL << 26;
    const uint64_t num_iters = 1UL << 10;
    
    // Use all available CPUs in parallel for host calculations.
    //const bool openmp = true;
    const bool openmp = false;

    // This timer start and then stop pattern will be used throughout the application.
    timer.start();
    uint64_t * data_cpu, * data_gpu;
    // cudaMallocHost will be discussed at length later in the course.
    cudaMallocHost(&data_cpu, sizeof(uint64_t)*num_entries);
    cudaMalloc    (&data_gpu, sizeof(uint64_t)*num_entries);
    timer.stop("allocate memory");
    check_last_error();

    timer.start();
    // If encryption cache file does not exist...
    if (!encrypted_file_exists(encrypted_file)) {
        // ...encrypt data in parallel on CPU...
        std::cout << " encrypting... \n ";
        encrypt_cpu(data_cpu, num_entries, num_iters, openmp);
        // ...and make encryption cache file for later.
        write_encrypted_to_file(encrypted_file, data_cpu, sizeof(uint64_t)*num_entries);
    } else {
        std::cout << " reading... \n ";
        // Use encryption cache file if it exists.
        read_encrypted_from_file(encrypted_file, data_cpu, sizeof(uint64_t)*num_entries);
    }
    timer.stop("encrypt data on CPU");

    // Begin timing for total time on GPU(s).
    overall.start();
    timer.start();
    // Data copy from CPU to GPU.
    cudaMemcpy(data_gpu, data_cpu, 
               sizeof(uint64_t)*num_entries, cudaMemcpyHostToDevice);
    timer.stop("copy data from CPU to GPU");
    check_last_error();

    // non-default stream
    cudaStream_t str;
    cudaStreamCreate(&str);

    timer.start();
    // Decrypt data on GPU(s).
    decrypt_gpu<<<80*32, 64, 0, str>>>(data_gpu, num_entries, num_iters);
    timer.stop("decrypt data on GPU");
    //std::cout << " checkpoint 0\n";
    check_last_error();
    //std::cout << " checkpoint 1\n";    

    cudaStreamDestroy(str);

    
    timer.start();
    // Copy data from GPU to CPU.
    cudaMemcpy(data_cpu, data_gpu, 
               sizeof(uint64_t)*num_entries, cudaMemcpyDeviceToHost);
    timer.stop("copy data from GPU to CPU");
    // Stop timer for total time on GPU(s).
    overall.stop("total time on GPU");
    check_last_error();

    timer.start();
    // Check results on CPU.
    const bool success = check_result_cpu(data_cpu, num_entries, openmp);
    std::cout << "STATUS: test " 
              << ( success ? "passed" : "failed")
              << std::endl;
    timer.stop("checking result on CPU");

    timer.start();
    // Free memory.
    cudaFreeHost(data_cpu);
    cudaFree    (data_gpu);
    timer.stop("free memory");
    check_last_error();
}

