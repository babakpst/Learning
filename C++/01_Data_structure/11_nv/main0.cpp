
/*
Babak Poursartip
12/13/2023
Greedy algorithm/Knapsack problem/Subset sum problem + backtracking
Time complexity:
Space complexity:



TODO
- Shall I switch to long data type?
- rename variable for treat or trick problem.
- try openMP
- try two col approach
- NP hard problem
- change AA to dp


*/

#define DEBUG 1  // 0 FALSE, 1 TRUE

// libraries
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

unsigned int max(unsigned int x, unsigned int y) { return (x > y) ? x : y; }

// unsigned int knapsack_max_weight(unsigned int nItems, unsigned int cap, std::vector<std::pair<unsigned int,unsigned
// int>> items)
unsigned int knapsack_max_weight(unsigned int nItems, unsigned int cap, std::vector<unsigned int> items)
{
  // base cases
  if (nItems == 0 || cap == 0) return 0;  // bbk double check.

  unsigned int AA[nItems + 1][cap + 1];

  // initialize AA
  for (unsigned int x = 0; x <= cap; ++x)
  {
    AA[0][x] = 0;
  }

  for (unsigned int i = 1; i <= nItems; ++i)
  {
    for (unsigned int x = 0; x <= cap; ++x)
    {
      // if (i == 0  || x==0) AA[0][x] = 0; // bbk use this instead of initialize <<<<
      // if (items[i - 1].second <= x)
      if (items[i - 1] <= x)
        // AA[i][x] = max(AA[i - 1][x], AA[i - 1][x - items[i - 1].second]+items[i - 1].first);
        AA[i][x] = max(AA[i - 1][x], AA[i - 1][x - items[i - 1]] + items[i - 1]);
      else
        AA[i][x] = AA[i - 1][x];
    }
  }

  // print table
  for (unsigned int i = 1; i <= nItems; ++i)
  {
    std::cout << i << "-- " << items[i - 1] << ": ";
    for (unsigned int x = 0; x <= cap; ++x)
    {
      std::cout << AA[i][x] << " ";
    }
    std::cout << std::endl;
  }

  int ret = AA[nItems][cap];
  std::cout << "results: " << ret << std::endl;

  int w = cap;
  for (int i = nItems; i > 0 && ret > 0; i--)
  {
    // either the result comes from the top
    // (K[i-1][w]) or from (val[i-1] + K[i-1]
    // [w-wt[i-1]]) as in Knapsack table. If
    // it comes from the latter one/ it means
    // the item is included.
    if (ret == AA[i - 1][w])
      continue;
    else
    {
      // This item is included.
      std::cout << "(" << i << ", " << items[i - 1] << ")";
      // Since this weight is included its value is deducted
      ret = ret - items[i - 1];
      w = w - items[i - 1];
    }
  }
  std::cout << std::endl;
  return AA[nItems][cap];
}

//=========================================
int main(int argc, char* argv[])
{
  printf("Start running the code ...\n");

  // reading items from the input file
  std::fstream inp;  // input file handler
  inp.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    if (DEBUG)
    {
      inp.open("input.txt", std::ios::in);
      // inp.open("input1.txt", std::ios::in);
    }
    else
    {
      inp.open("input.txt", std::ios::in);
    }
  }
  catch (std::ifstream::failure& inputerr)
  {  // catch for the input file
    printf(" Error while opening  input file! \n");
    printf(" The error message is: \n");
    printf("%s \n", inputerr.what());
    throw inputerr;
  }

  unsigned int nItems;  // no. of items
  unsigned int cap;     // capacity of knapsack basket
  inp >> nItems;
  inp >> cap;

  printf("\n no. of items: %d, capacity: %d \n", nItems, cap);

  std::vector<unsigned int> items(nItems);  // both weight and value

  // unsigned int value;
  unsigned int weight;
  unsigned int index;

  for (std::vector<unsigned int>::iterator it = items.begin(); it != items.end(); ++it)
  {
    inp >> weight;
    index = it - items.begin();
    // if (DEBUG) printf("reading item %ld: %ld - %ld \n",index,value, weight);
    if (DEBUG) printf("reading item %d:%d \n", index + 1, weight);
    // *it=std::make_pair(value,weight);
    *it = weight;
  }

  printf("done reading \n \n");

  if (DEBUG)
    // for (std::vector<std::pair<unsigned int,unsigned int>>::iterator it = items.begin(); it != items.end(); ++it) {
    std::cout << " data \n";
  for (std::vector<unsigned int>::iterator it = items.begin(); it != items.end(); ++it)
  {
    index = it - items.begin();
    printf("%d: %d \n", index + 1, *it);
  }
  std::cout << " \n\n";

  printf(" The maximum value obtained by knapsack is: %d\n", knapsack_max_weight(nItems, cap, items));

  printf("\nEnd of the code!\n");
  return 0;
}
