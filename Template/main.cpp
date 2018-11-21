
#include <iostream>

namespace main_ns{

template<class T1>
class calc_cls{
  T1 var1, results1;

  public:
    calc_cls(T1);

};
}

template<class T1>
main_ns::calc_cls<T1>::calc_cls(T1 a){
std::cout<< " Yes, we are inside the constructor!" << std::endl << std::endl;
var1 = a;
}





//=======================================
int main(){

std::cout<< " OK, Lets get started:" << std::endl;

main_ns::calc_cls<double> object(3.0);

return 0;
}



