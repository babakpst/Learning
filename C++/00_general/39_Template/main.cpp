
//


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


// ==================================
template<typename T=int, typename K=double> class myClass{
private:
T ivar;
K dvar;
public:
myClass(T ivar, K dvar):ivar(ivar),dvar(dvar){ 
std::cout << " constructor \n"; 
std::cout << "ivar: " << ivar << " dvar: " << dvar << std::endl;}

};

//=======================================
//=======================================
template<typename T>
T sum(const T &a, const T &b){return (a+b);}

//=======================================
int main(){

std::cout<< " OK, Lets get started:" << std::endl;

main_ns::calc_cls<double> object1(3.1);
std::cout << " The suqare of the number is: " << object1.square_func() << std::endl;

main_ns::calc_cls<int> object2(3);
std::cout << " The suqare of the number is: " << object2.square_func()  << std::endl;

main_ns::calc_cls<int> object3(3.1);
std::cout << " The suqare of the number is: " << object3.square_func()  << std::endl;

main_ns::calc_cls<float> object4(6.1);
std::cout << " The suqare of the number is: " << object3.square_func()  << std::endl;

std::cout << "-----------------\n";
myClass<int,double> o1(5,5.1);
myClass<> o2(5,5.1); // this <> should be here, otherwise it is an error.
myClass<int> o3(5.1,5);


std::cout << "-----------------\n";


return 0;
}



