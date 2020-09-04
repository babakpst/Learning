
// Babak Poursartip
// 04/18/2019

// variadic template

#include <iostream>


// ... on the left side means packing and on the right side means unpacking
// typename ...p: pack multiple type arguments into the type pack p
// P...: unpack P when instantiating a class or function temmplate

//=========================================
void print(){
  std::cout << " \n Empty funciton! I call it at the end of the code."<<std::endl;
}

// variadic template
template<typename T, typename ... Types>
void print(T var1, Types ...var2){
  std::cout << var1 << "\n";
  print(var2...);
}

//=========================================
//To terminate the recursion, we overload the function with a one arg function. 
template<typename T>
T sum(T t){ 
  puts(" final sum");
  return t;
}


// The return type is the type of the first arg.
template<typename T, typename ...P>
T sum (T t, P ...p){ 
  std::cout << "number is: " << t << std::endl;
  return t + sum(p...);
}
//=========================================

int main(){

  std::cout << "\n variadic template example\n \n";

  print(1, 2, 3.14, "Pass me any "
                    "number of arguments.",
                    "I will print \n", 123.456);

  print();
  puts(" \n =======================");


  auto s = sum (-7, 3.7f, 9u, -2.6);
  std::cout << "s is: " << s << " and its type is: " << typeid(s).name() << "\n";

  // terrible outcome 
  auto s2 = sum (-7, 3.7f, 9u, -42.6);
  std::cout << "s2 is: " << s2 << " and its type is: " << typeid(s2).name() << "\n";

  return 0;
}
