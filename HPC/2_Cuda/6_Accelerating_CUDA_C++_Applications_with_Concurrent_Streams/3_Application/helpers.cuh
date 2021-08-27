#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

uint64_t sdiv (uint64_t a, uint64_t b) {
    return (a+b-1)/b;
}

// We will use this throughout for error checking.
void check_last_error ( ) {

    cudaError_t err;
    if ((err = cudaGetLastError()) != cudaSuccess) {
        std::cout << "CUDA error: " << cudaGetErrorString(err) << " : "
                  << __FILE__ << ", line " << __LINE__ << std::endl;
            exit(1);
    }
}

// To avoid waiting on the CPU every time we need to encrypt, we will cache
// the encrypted data in a file to read from disk. This helper is used to
// check if the cache exists.
bool encrypted_file_exists(const char * encrypted_file) {

    FILE *file;
    file = fopen(encrypted_file, "r");
    if (file) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// This helper will be used to write encrypted values to file.
void write_encrypted_to_file(const char * encrypted_file, uint64_t * data, size_t size) {
    std::ofstream encrypted(encrypted_file, std::ios::binary);
    encrypted.write(reinterpret_cast<char*>(data), size);
    encrypted.close();
}

// This helper will be used to read encrypted values from file so we do not
// need to wait for the CPU to do the work every time.
void read_encrypted_from_file(const char * encrypted_file, uint64_t * data, size_t size) {
    std::ifstream encrypted(encrypted_file, std::ios::binary);
    encrypted.read(reinterpret_cast<char*>(data), size);
    encrypted.close();
}

// Timer will be used throughout to benchmarks sections of the application,
// as well as total time on the GPU(s).
class Timer {

    float time;
    const uint64_t gpu;
    cudaEvent_t ying, yang;

public:

    Timer (uint64_t gpu=0) : gpu(gpu) {
        cudaSetDevice(gpu);
        cudaEventCreate(&ying);
        cudaEventCreate(&yang);
    }

    ~Timer ( ) {
        cudaSetDevice(gpu);
        cudaEventDestroy(ying);
        cudaEventDestroy(yang);
    }

    void start ( ) {
        cudaSetDevice(gpu);
        cudaEventRecord(ying, 0);
    }

    void stop (std::string label) {
        cudaSetDevice(gpu);
        cudaEventRecord(yang, 0);
        cudaEventSynchronize(yang);
        cudaEventElapsedTime(&time, ying, yang);
        std::cout << "TIMING: " << time << " ms (" << label << ")" << std::endl;
    }
};

