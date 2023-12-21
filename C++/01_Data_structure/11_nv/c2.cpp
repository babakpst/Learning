
/*
===============================================================================
Developer: Babak Poursartip

Course III:       Greedy algorithm
Assignment IV:    Knapsack
Data:             06/28/2020
===============================================================================
*/

#define DEBUG 0  // 0 FALSE, 1 TRUE

// libraries
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

unsigned int max(unsigned int x, unsigned int y) { return (x > y) ? x : y; }

unsigned int knapsack_max_weight(unsigned int nItems, unsigned int cap,
                                 std::vector<std::pair<unsigned int, unsigned int>> items)
{
  printf(" working on the knapsack algo ... \n");

  // we only need two columns of the AA matrix
  // unsigned int AA[2][cap+1];  // This allocates on the heap which is small.

  // this allocates on the stack
  unsigned int **AA = new unsigned int *[2];
  for (int i = 0; i <= 2; ++i)
  {
    AA[i] = new unsigned int[cap + 1];
  }

  // initialize AA
  for (unsigned int x = 0; x <= cap; ++x)
  {
    AA[0][x] = 0;
  }

  for (unsigned int i = 1; i <= nItems; ++i)
  {
    for (unsigned int x = 0; x <= cap; ++x)
    {
      if (items[i - 1].second <= x)
        AA[1][x] = max(AA[0][x], AA[0][x - items[i - 1].second] + items[i - 1].first);
      else
        AA[1][x] = AA[0][x];
    }
    for (unsigned int x = 0; x <= cap; ++x)
    {
      AA[0][x] = AA[1][x];
    }
  }

  unsigned int output = AA[0][cap];

  for (int i = 0; i < 2; ++i)
  {
    delete[] AA[i];
  }
  delete[] AA;

  return output;
}

// classes
int main()
{
  printf("Start running the code ...\n");

  // reading items from the input file
  std::fstream inp;  // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    if (DEBUG)
    {
      inp.open("knapsack_example.txt", std::ios::in);
      // inp.open("knapsack_example2.txt", std::ios::in);
    }
    else
    {
      inp.open("knapsack_big.txt", std::ios::in);
    }
  }
  catch (std::ifstream::failure &inputerr)
  {  // catch for the input file
    printf(" Error while opening the input file!!! \n");
    printf(" The error message is: \n");
    printf("%s \n", inputerr.what());
    throw inputerr;
  }

  unsigned int nItems;  // no. of items
  unsigned int cap;     // capacity of knapsack bascket
  inp >> cap >> nItems;

  printf("\n no. of items: %d, capacity: %d \n", nItems, cap);

  std::vector<std::pair<unsigned int, unsigned int>> items(nItems);  //

  unsigned int value, weight;
  unsigned int index;

  for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = items.begin(); it != items.end(); ++it)
  {
    inp >> value >> weight;
    index = it - items.begin();
    if (DEBUG) printf("reading item %d: %d - %d \n", index, value, weight);
    *it = std::make_pair(value, weight);
  }

  printf("done reading \n \n");
  if (DEBUG)
    for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = items.begin(); it != items.end(); ++it)
    {
      index = it - items.begin();
      printf("%d: %d - %d \n", index, (*it).first, (*it).second);
    }

  printf(" The maximum value obtained by knapsack is: %d\n", knapsack_max_weight(nItems, cap, items));

  printf("\nEnd of the code!\n");
  return 0;
}
