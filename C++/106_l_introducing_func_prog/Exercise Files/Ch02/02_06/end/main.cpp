#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void demoFunction(){
  cout << "Called demoFunction" << endl;
}

void adder(int a, int b){
  cout << "Called adder, a + b = " << a+b << endl;
}

class functor {
public:
  void operator()() const {
    cout << "Called functor" << endl;
  }
};

int main() {
  vector<function<void()>> funcs;
  funcs.push_back(demoFunction);

  functor functor_instance;
  funcs.push_back(functor_instance);
  funcs.push_back([](){cout << "Called anonymous lambda" << endl;});
  funcs.push_back(std::bind(&adder, 10, 15));

  for(auto &f : funcs){
    f();
  }


  return 0;
}