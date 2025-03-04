
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <numeric>  // required for accumulate
#include <vector>

using namespace std;

class MovingAverage
{
 public:
  vector<int> vec;
  double count = 0;
  int size;
  int head = 0, tail = -1;
  MovingAverage(int size) : size(size), vec(size, 0) {}

  double next(int val)
  {
    vec[(++tail) % size] = val;
    count = count == size ? count : ++count;
    // cout << count << endl;
    // for_each(vec.begin(), vec.end(), [](auto x){cout << x << " "; });
    // cout << endl;
    return accumulate(vec.begin(), vec.end(), 0) / count;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  double param = 0;
  int size = 5;
  MovingAverage* obj = new MovingAverage(size);

  param = obj->next(1);
  cout << " answer: " << param << endl;
  param = obj->next(10);
  cout << " answer: " << param << endl;
  param = obj->next(3);
  cout << " answer: " << param << endl;
  param = obj->next(5);
  cout << " answer: " << param << endl;

  param = obj->next(8);
  cout << " answer: " << param << endl;

  param = obj->next(7);
  cout << " answer: " << param << endl;
  param = obj->next(9);
  cout << " answer: " << param << endl;

  std::cout << " done \n";
  return 0;
}
