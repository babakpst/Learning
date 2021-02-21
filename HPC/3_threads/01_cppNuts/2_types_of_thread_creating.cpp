
/*
Babak Poursartip
10/18/2020
source:
 https://www.youtube.com/watch?v=hCvc9y39RDw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=2


REMARKS: types of thread creation in C++
- There are 5 different types we can create threads:
  1- function pointer (basic form)
  2- lambda function
  3- functor (function object)
  4- non-static member function

*/

#include <iostream>
#include <thread>

// 1: function pointer =================
void func1(int x) {
  while (x-- > 0) {
    std::cout << " x= " << x << std::endl;
  }
}

// 3: functor ===========================
class func3 {
public:
  func3 operator()(int x) {
    while (x-- > 0) {
      std::cout << " x= " << x << std::endl;
    }
  }
};

// 4: non-static member function ========
class func4 {
public:
  void run(int x) {
    while (x-- > 0) {
      std::cout << " x= " << x << std::endl;
    }
  }
};

// 5: static member function ========
class func5 {
public:
  static void run(int x) {
    while (x-- > 0) {
      std::cout << " x= " << x << std::endl;
    }
  }
};

// main =================================
int main() {
  // type 1: function pointer
  std::cout << " type 1: function pointer\n";
  std::thread t1(func1, 5);
  t1.join();

  // type 2: lambda function
  std::cout << " type 2: lambda function \n";

  auto func2 = [](int x) {
    while (x-- > 0) {
      std::cout << " x= " << x << std::endl;
    }
  };

  std::thread t2(func2, 5);
  t2.join();

  // type 3: functor (function object)
  std::cout << " type 3: funcor (function object) \n";
  std::thread t3(func3(), 5);
  t3.join();

  // type 4: non-static member function
  std::cout << " type 4: non-static member function \n";
  func4 obj;
  std::thread t4(&func4::run, &obj, 5);
  t4.join();

  // type 5: static member function
  std::cout << " type 5: static member function \n";
  std::thread t5(&func5::run, 5);
  t5.join();

  return 0;
}