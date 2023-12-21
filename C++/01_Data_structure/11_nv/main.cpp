/*
Babak Poursartip
12/12/2023

Sliding window to find the max consecutive sum less than a target

Time complexity: O(N)
Space complexity: O(1)

Assumptions
- All numbers are non-negative
- The only case that the code writes "Don't go here" is the case that max candy is smaller than all home candies.
- If max candy = 0 and there is a home that gives 0 candy, it finds/prints the home number.
- Total length of the file is (#homes+2), i.e., there is one line for each home in the neighborhood. Problem description
  is not clear.
- This script includes the home number with 0 candy in subarry. To exclude 0-candy houses from the beginning of the
  subarry, uncomenet the condition.
- The openMP parallelizatin is not trivial with this algo, as each iters depends on the previous one. Divide and conquer
  might be a better algo for openMP.
*/

#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> pathfinder(const int size, const int target, const std::vector<int>& numbers)
{
  int maximum = 0;      // largest sum in the subarray ~ max candy
  int winSum = 0;       // current sum in the window/subarray
  int maxStart = size;  // start index of the subarray with max sum
  int maxEnd = size;    // end index of the subarray with max sum
  int pathStart = 0;    // start index of the current subarray

  if (target == 0)  // edge case to handle 0 max candy: if there is a home with 0 candy...
  {
    for (int pathEnd = pathStart; pathEnd < size; ++pathEnd)
      if (numbers[pathEnd] == 0) return {pathEnd, pathEnd, maximum};
  }
  else
  {
    // sliding window: search for the subarray with max sum
    for (int pathEnd = pathStart; pathEnd < size; ++pathEnd)
    {
      winSum += numbers[pathEnd];

      // to remove homes with 0 candies from the begining of the subarry, uncomment the next line, instead.
      // while ((winSum > target || numbers[pathStart] == 0) && pathStart <= pathEnd )
      while (winSum > target && pathStart <= pathEnd)
      {
        winSum -= numbers[pathStart];
        ++pathStart;
      }

      if (winSum > maximum || numbers[pathEnd] == 0)
      {
        maximum = winSum;
        maxStart = pathStart;
        maxEnd = pathEnd;
        if (winSum == target) return {maxStart, maxEnd, maximum};
      }
    }
  }
  return {maxStart, maxEnd, maximum};
}

int main(int argc, char* argv[])
{
  std::fstream inp;
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    inp.open("input.txt", std::ios::in);
    // inp.open("input1.txt", std::ios::in); // edge
    // inp.open("input2.txt", std::ios::in);
    // inp.open("input3.txt", std::ios::in);
  }
  catch (std::ifstream::failure& inputerr)
  {
    std::cout << " Error while opening input file. The error message is: " << inputerr.what() << std::endl;
    throw inputerr;
  }

  int nHouses;
  int maxCandy;  // capacity of basket

  inp >> nHouses;
  inp >> maxCandy;

  std::vector<int> numCandies(nHouses, 0);  // holds the number of candies for each house
  int candies;                              // temp to store number of candies for each house

  for (int i = 0; i < nHouses; ++i)
  {
    inp >> candies;
    numCandies[i] = candies;
  }
  inp.close();

  std::vector<int> result = pathfinder(nHouses, maxCandy, numCandies);
  int pathStart = result[0];
  int pathEnd = result[1];
  int maxCollected = result[2];

  if (pathStart >= nHouses)
    std::cout << "Don't go here" << std::endl;
  else
    std::cout << "Start at home " << pathStart + 1 << " and go to home " << pathEnd + 1 << " getting " << maxCollected
              << " pieces of candy" << std::endl;

  return 0;
}
