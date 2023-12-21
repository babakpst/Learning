
/*
===============================================================================
Developer: Babak Poursartip

Course III:       Greedy algorithm
Assignment IV:    Knapsack
Data:             06/28/2020
===============================================================================
*/

#define DEBUG 1  // 0 FALSE, 1 TRUE

// libraries
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

unsigned long max(unsigned long x, unsigned long y) { return (x > y) ? x : y; }

unsigned long knapsack_max_weight(unsigned long nItems, unsigned long cap,
                                  std::vector<std::pair<unsigned long, unsigned long>> items)
{
  unsigned long AA[nItems + 1][cap + 1];

  // initialize AA
  for (unsigned long x = 0; x <= cap; ++x)
  {
    AA[0][x] = 0;
  }

  for (unsigned long i = 1; i <= nItems; ++i)
  {
    for (unsigned long x = 0; x <= cap; ++x)
    {
      if (items[i - 1].second <= x)
        AA[i][x] = max(AA[i - 1][x], AA[i - 1][x - items[i - 1].second] + items[i - 1].first);
      else
        AA[i][x] = AA[i - 1][x];
    }
  }

  return AA[nItems][cap];
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
      inp.open("knapsack1.txt", std::ios::in);
    }
  }
  catch (std::ifstream::failure &inputerr)
  {  // catch for the input file
    printf(" Error while opening the input file!!! \n");
    printf(" The error message is: \n");
    printf("%s \n", inputerr.what());
    throw inputerr;
  }

  unsigned long nItems;  // no. of items
  unsigned long cap;     // capacity of knapsack bascket
  inp >> cap >> nItems;

  printf("\n no. of items: %ld, capacity: %ld \n", nItems, cap);

  std::vector<std::pair<unsigned long, unsigned long>> items(nItems);  //

  unsigned long value, weight;
  unsigned long index;

  for (std::vector<std::pair<unsigned long, unsigned long>>::iterator it = items.begin(); it != items.end(); ++it)
  {
    inp >> value >> weight;
    index = it - items.begin();
    if (DEBUG) printf("reading item %ld: %ld - %ld \n", index, value, weight);
    *it = std::make_pair(value, weight);
  }

  printf("done reading \n \n");
  if (DEBUG)
    for (std::vector<std::pair<unsigned long, unsigned long>>::iterator it = items.begin(); it != items.end(); ++it)
    {
      index = it - items.begin();
      printf("%ld: %ld - %ld \n", index, (*it).first, (*it).second);
    }

  printf(" The maximum value obtained by knapsack is: %ld\n", knapsack_max_weight(nItems, cap, items));

  printf("\nEnd of the code!\n");
  return 0;
}
