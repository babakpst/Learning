

#include <iostream>

namespace main_ns{

template<typename T1>
class calc_cls{
  T1 var1, results;

  public:
    calc_cls(T1);

    T1 square_func();

};
}

template<typename T1>
main_ns::calc_cls<T1>::calc_cls(T1 var1):var1(var1){
std::cout<< " Yes, we are inside the constructor!" << std::endl;
std::cout<< " The value of the variable is: " << var1 << std::endl;
}

template<typename T1>
T1 main_ns::calc_cls<T1>::square_func(){ 
  results= var1*var1;
  return results;
  }



//=======================================
int main(){

std::cout<< " OK, Lets get started:" << std::endl;

main_ns::calc_cls<double> object1(3.1);
std::cout << " The suqare of the number is: " << object1.square_func() << std::endl;

main_ns::calc_cls<int>    object2(3.1);
std::cout << " The suqare of the number is: " << object2.square_func()  << std::endl;

return 0;
}



