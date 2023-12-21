/*
Babak Poursartip
12/13/2023

Sliding window to find the max consecutive sum less than a target

Time complexity:
Space complexity:

Assumptions
- all numbers are positive


export OMP_NUM_THREADS=8
g++ -fopenmp main_openmp.cpp -o mainmp

TODO
- rename variable for treat or trick problem.
- try openMP
*/

#include <omp.h>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>  // bbk see if we need it.
#include <utility>
#include <vector>

std::vector<unsigned int> pathfinder(unsigned int size, unsigned int target, const std::vector<unsigned int>& numbers)
{
  unsigned int maximum = 0;
  unsigned int maxStart = size;
  unsigned int maxEnd = size;

#pragma omp parallel for
  for (int i = 0; i < size; ++i)
  {
    // int currentSum = 0;
    // int start = i;
    unsigned int winSum = 0;
    unsigned int pathStart = i;

    for (int j = i; j < size; ++j)
    {
      winSum += numbers[j];

      while ((winSum > target || numbers[pathStart] == 0) && pathStart <= j)
      {
        winSum -= numbers[pathStart];
        ++pathStart;
      }

#pragma omp critical
      {
        if (winSum <= target && winSum > maximum)
        {
          maximum = winSum;
          maxStart = pathStart;
          maxEnd = j;
          // if (winSum == target ) return {maxStart, maxEnd, maximum};
        }
      }
    }
  }

  return {maxStart, maxEnd, maximum};
}

// ============================
int main(int argc, char* argv[])
{
  std::cout << "Trick or treat \n";  // bbk comment out

  // reading items from the input file
  std::fstream inp;  // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    // inp.open("input.txt", std::ios::in);
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

  unsigned int candies;  // temp to store number of candies for each house

  for (int i = 0; i < nHouses; ++i)
  {
    inp >> candies;
    numCandies[i] = candies;
  }
  inp.close();

  std::cout << " data: \n";
  for (unsigned int num : numCandies)
  {
    std::cout << num << std::endl;
  }
  std::cout << " \n\n";

  std::vector<unsigned int> result = pathfinder(nHouses, maxCandy, numCandies);
  int pathStart = result[0];
  int pathEnd = result[1];
  int maxCollected = result[2];

  if (pathStart == nHouses)
    std::cout << "Don't go here" << std::endl;
  else
    std::cout << "Start at home " << pathStart + 1 << " and go to home " << pathEnd + 1 << " getting " << maxCollected
              << " pieces of candy" << std::endl;

  return 0;
}
