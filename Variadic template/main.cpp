#include <iostream>


void print(){
std::cout << " This is an empty funciton and I am called at last \n \n";
}

template<typename T, typename ... Types>
void print(T var1, Types... var2){
  std::cout << var1 << "\n";
  print(var2...);
}


template<typename T>
T sum(T t){ return t;}

template<typename T, typename ... P>
T sum (T t, P... p){ return t + sum(p...);}


int main(){

  std::cout << "\n variadic template example\n \n";

  print(1, 2, 3.14, "Pass me any "
                    "number of arguments.",
                    "I will print \n", 123.456);


  print();

  auto s = sum (-7, 3.7f, 9u, -2.6);
  std::cout << "s is: " << s << " and its type is: " << typeid(s).name() << "\n";

  auto s2 = sum (-7, 3.7f, 9u, -42.6);
  std::cout << "s2 is: " << s2 << " and its type is: " << typeid(s2).name() << "\n";

  return 0;
}