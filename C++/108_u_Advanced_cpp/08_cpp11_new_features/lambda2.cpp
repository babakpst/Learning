
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// lambda this

#include <iostream>

using namespace std;

class test {
private:
  int one{1}, two{2};

public:
  void run() {
    int three{3}, four{4};

    // we cannot capture instances of class in the class, i.e. [one, two],
    // instead we can use this. The instance variables then are captured by
    // reference and can be changed inside the lambda function.

    // this is also not acceptable: [=, this]
    auto plambda2 = [=]() mutable {
      three = 7;
      cout << three << endl;
    };
    auto plambda = [three, this, four]() {
      one = 111;

      cout << one << endl;
      cout << three << endl;
      cout << four << endl;
    };
    plambda();
    cout << " one outside of the lambda function: " << one << endl;
  }
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";
  test tst;
  tst.run();
  cout << " \n endsn\n";

  return 0;
}
