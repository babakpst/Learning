
/*
Babak Poursartip
07/19/2020
profiling
*/

#include <sstream>

int mult_kid(const int n)
{
  int results;
  for (int i = 0; i < n; ++i)
  {
    results = i;
  }

  return results;
}

int mult(const int n)
{
  int results = 1;
  for (int i = 0; i < n; ++i)
  {
    results += i;
  }
  printf(" mult kid: %d \n", mult_kid(n));

  return results;
}

int mult2(const int n)
{
  int results = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      results += i - j;
    }
  }

  return results;
}

int main()
{
  puts(" Code starts ...");
  int n = 100000;
  int m = 10;
  int j;
  for (int i = 0; i < n; ++i)
  {
    j = i;
  }

  for (int i = 0; i < m; ++i) printf(" here is the result: %d \n", mult(n * 100));

  for (int i = 0; i < m; ++i) printf(" mult kid in main: %d \n", mult_kid(n));

  printf(" here is the result2: %d \n", mult2(n));

  puts(" Terminates successfully!");
  return 0;
}
