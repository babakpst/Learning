#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

struct ResultWithIndices
{
  int start;
  int end;
  int sum;
};

ResultWithIndices findMaxCrossingSubarray(const std::vector<int>& array, int low, int mid, int high, int limit)
{
  int leftSum = 0;
  int sum = 0;
  int maxLeft = mid;

  for (int i = mid; i >= low; i--)
  {
    if (sum + array[i] > limit) break;
    sum += array[i];
    leftSum = sum;
    maxLeft = i;
  }

  int rightSum = 0;
  sum = 0;
  int maxRight = mid;

  for (int i = mid + 1; i <= high; i++)
  {
    if (sum + array[i] > limit) break;
    sum += array[i];
    rightSum = sum;
    maxRight = i;
  }

  return {maxLeft, maxRight, leftSum + rightSum};
}

ResultWithIndices findMaximumSubarray(const std::vector<int>& array, int low, int high, int limit)
{
  if (high < low)
  {
    return {-1, -1, INT_MIN};
  }

  if (low == high)
  {
    if (array[low] <= limit)
    {
      return {low, high, array[low]};
    }
    else
    {
      return {-1, -1, INT_MIN};
    }
  }

  int mid = (low + high) / 2;

  ResultWithIndices leftResult = findMaximumSubarray(array, low, mid, limit);
  ResultWithIndices rightResult = findMaximumSubarray(array, mid + 1, high, limit);
  ResultWithIndices crossResult = findMaxCrossingSubarray(array, low, mid, high, limit);

  if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossResult.sum)
    return leftResult;
  else if (rightResult.sum > leftResult.sum && rightResult.sum > crossResult.sum)
    return rightResult;
  else
    return crossResult;
}

int main()
{
  // std::vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // int limit = 6;
  std::cout << "Trick or treat \n";  // bbk comment out

  // reading items from the input file
  std::fstream inp;  // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    // inp.open("input.txt", std::ios::in);
    // inp.open("input1.txt", std::ios::in);
    inp.open("input2.txt", std::ios::in);
  }
  catch (std::ifstream::failure& inputerr)
  {
    printf(" Error while opening  input file! \n");
    printf(" The error message is: \n");
    printf("%s \n", inputerr.what());
    throw inputerr;
  }

  unsigned int nHouses;
  unsigned int maxCandy;  // capacity of basket
  inp >> nHouses;
  inp >> maxCandy;
  printf("\n no. of items: %d, capacity: %d \n", nHouses, maxCandy);  // bbk dlt

  if (nHouses == 0 || maxCandy == 0)
  {
    std::cout << "Don't go here" << std::endl;
    return 0;
  }

  std::vector<unsigned int> numCandies(nHouses, 0);  // both weight and value
  std::vector<int> numCandies2(nHouses, 0);          // both weight and value

  unsigned int candies;  // temp to store number of candies for each house

  for (int i = 0; i < nHouses; ++i)
  {
    inp >> candies;
    numCandies[i] = candies;
    numCandies2[i] = candies;
  }
  inp.close();

  std::cout << " data: \n";
  for (unsigned int num : numCandies)
  {
    std::cout << num << std::endl;
  }
  std::cout << " \n\n";

  ResultWithIndices result = findMaximumSubarray(numCandies2, 0, numCandies2.size() - 1, maxCandy);
  std::cout << "The maximum contiguous sum less than or equal to target starts at index " << result.start
            << " and ends at index " << result.end << " with sum " << result.sum;
  return 0;
}
