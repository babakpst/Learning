#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/sort.h>
using namespace thrust;

#include <ctime>
using namespace std;

int myrand()
{
  return rand() % 10;
}

void main()
{
  int count = 1024;
  host_vector<int> h(count);
  generate(begin(h), end(h), myrand);
  device_vector<int> d = h;
  sort(begin(d), end(d));
  h = d;
  for (int i = 0; i < count; i++)
  {
    cout << h[i] << "\t";
  }

  getchar();
}