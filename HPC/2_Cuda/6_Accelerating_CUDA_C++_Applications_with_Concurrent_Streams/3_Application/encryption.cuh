#pragma once

#include <cstdint>
#include <assert.h>

__host__ __device__ __forceinline__
uint32_t hash (uint32_t x) {

        x ^= x >> 16;
        x *= 0x85ebca6b;
        x ^= x >> 13;
        x *= 0xc2b2ae35;
        x ^= x >> 16;

        return x;
}

// num_iters controls amount of computational work.
__host__ __device__ __forceinline__
uint64_t permute64(uint64_t x, uint64_t num_iters) {

    constexpr uint64_t mask = (1UL << 32)-1;

    for (uint64_t iter = 0; iter < num_iters; iter++) {
        const uint64_t upper = x >> 32;
        const uint64_t lower = x & mask;
        const uint64_t mixer = hash(upper);

        x = upper + ((lower^mixer&mask) << 32);
    }

    return x;
}

// num_iters controls amount of computational work.
// Note symmetry with permute64 above.
__host__ __device__ __forceinline__
uint64_t unpermute64(uint64_t x, uint64_t num_iters) {

    constexpr uint64_t mask = (1UL << 32)-1;
    
    for (uint64_t iter = 0; iter < num_iters; iter++) {
        const uint64_t upper = x & mask;
        const uint64_t lower = x >> 32;
        const uint64_t mixer = hash(upper);

        x = (upper << 32) + (lower^mixer&mask);
    }

    return x;
}

