

// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// standard function type

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
bool check(string &str) { return str.size() == 3; }

// functor
class Check {
public:
  bool operator()(string &test) { return test.size() == 5; }
} check1;

// standard function
void run(function<bool(string &)> check) {
  string tst = "dog";
  cout << check(tst) << endl;
}

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";
  int size = 5;
  vector<string> vec{"one", "two", "three"};

  int count = count_if(vec.begin(), vec.end(),
                       [size](string a) { return a.size() == size; });
  cout << "equal to size: " << count << "\n";

  count = count_if(vec.begin(), vec.end(), check);
  cout << "equal to size2: " << count << "\n";

  count = count_if(vec.begin(), vec.end(), check1);
  cout << "equal to size3: " << count << "\n";

  auto lambda = [size](string a) { return a.size() == size; };
  run(lambda);
  run(check1);
  run(check);

  function<int(int, int)> add = [](int one, int two) { return one + two; };
  cout << add(7, 3) << endl;

  cout << " \n ends\n";

  return 0;
}
