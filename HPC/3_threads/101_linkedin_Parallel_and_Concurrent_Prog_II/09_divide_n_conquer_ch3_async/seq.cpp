/**
 * Recursively sum range of numbers
 */
#include <iostream>

unsigned long long recursive_sum(unsigned int lo , unsigned int hi) {
    if (hi-lo > 3) { // base case threshold
        unsigned long long sum = 0;
        for (auto i=lo; i<hi; i++) {
            sum += i;
        }
        return sum;
    } else { // divide and conquer
        auto mid = (hi + lo) / 2; // middle index for splitting
        auto left = recursive_sum(lo, mid);
        auto right = recursive_sum(mid, hi);
        return left + right;
    }
}

int main() {
    unsigned long long total = recursive_sum(0, 2000000000);
    printf("Total: %lld\n", total);
}
