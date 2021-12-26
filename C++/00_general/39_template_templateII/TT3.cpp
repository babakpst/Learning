

/*
Babak Poursartip
12/25/2021

Template template argument

*/

#include <iostream>

// =====================================
template <typename T, typename U>
class class_one
{
public:
class_one(){std::cout << " class_one: dafault ctor\n";}
class_one(int a){std::cout << " class_one: ctor\n";}
void operator()(int input){std::cout << " class_one: operator\n";}
};


// =====================================
template <typename T, typename U>
class class_two
{
public:
class_two(){std::cout << " class_two: default ctor\n";}
class_two(int a){std::cout << " class_two: ctor\n";}
void operator()(int input){std::cout << " class_two: operator\n";}
};


// =====================================
template <template <typename...> class TEST>
int func1(int input)
{
  int out = 5;

  if (input < 0)
    //return TEST<int, int>{}(input);
    TEST<int, int>{}(input);
  else
    //return     TEST<float, float>{}(input);  
    TEST<float, float>{}(input);  
  return out;
}



// =====================================
int main()
{
  std::cout << " starts ... \n";

  int input;

  //==
  input = 5;
  func1<class_one>(input);

  //==
  input = -5;
  func1<class_two>(input);

  std::cout << " done. \n";
  return 0;
}
