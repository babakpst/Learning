#include <omp.h>

#include <iostream>
#include <limits>
#include <vector>

// Struct to store the result with indices
struct ResultWithIndices
{
  int start;
  int end;
  int sum;

  ResultWithIndices() : start(-1), end(-1), sum(std::numeric_limits<int>::lowest()) {}
};

// Function to find the largest subarray sum less than a target in a given range [low, high]
ResultWithIndices findLargestSubarraySumLessThanTarget(const std::vector<int>& array, int low, int high, int target)
{
  ResultWithIndices result;

  int sum = 0;
  int startIndex = -1;

  for (int i = high; i >= low; --i)
  {
    sum += array[i];

    if (sum < target && sum > result.sum)
    {
      result.start = i;
      result.end = high;
      result.sum = sum;
    }

    if (sum >= target)
    {
      sum -= array[i];
      startIndex = i - 1;
    }
  }

  if (startIndex >= low)
  {
    ResultWithIndices subarrayResult = findLargestSubarraySumLessThanTarget(array, low, startIndex, target);

    if (subarrayResult.sum > result.sum)
    {
      result = subarrayResult;
    }
  }

  return result;
}

// Function to find the largest subarray sum less than a target using a parallel divide-and-conquer approach
ResultWithIndices parallelFindLargestSubarraySumLessThanTarget(const std::vector<int>& array, int target)
{
  ResultWithIndices result;

#pragma omp parallel
  {
#pragma omp single nowait
    result = findLargestSubarraySumLessThanTarget(array, 0, array.size() - 1, target);
  }

  return result;
}

int main()
{
  // Example usage
  std::vector<int> data = {1, -2, 3, 10, -5, 2, 7};
  int target = 10;

  ResultWithIndices result = parallelFindLargestSubarraySumLessThanTarget(data, target);

  std::cout << "Largest subarray sum less than " << target << ": " << result.sum << std::endl;
  std::cout << "Indices: [" << result.start << ", " << result.end << "]" << std::endl;

  return 0;
}
