
#include <iostream>

namespace main_ns{

template<class T1, class T2>
class calc_cls{
  T1 var1, results1;
  T2 var2, results2;

  public:
    calc_cls(T1, T2);
    void calc1_fn();
    void calc2_fn();
    void print_fn();
};
}

/*
template<class T1, class T2>
main_ns::calc_cls<T1, T2>::calc_cls(T1 a, T2 b){
std::cout<< " Yes, we are inside the constructor!" << std::endl << std::endl;
var1 = a;
var2 = b;
}
*/


template<class T1, class T2>
main_ns::calc_cls<T1, T2>::calc_cls(T1 var1, T2 var2):var1(var1), var2(var2){
std::cout<< " Yes, we are inside the constructor!" << std::endl << std::endl;
}

template<class T1, class T2>
void main_ns::calc_cls<T1, T2>::calc1_fn(){
std::cout << " inside calc1" << std::endl;
results1 = 2* var1;
}

template<class T1, class T2>
void main_ns::calc_cls<T1, T2>::calc2_fn(){
std::cout << " inside calc2" << std::endl;
results2 = 2* var2;
}

template<class T1, class T2>
void main_ns::calc_cls<T1, T2>::print_fn(){
std::cout << " printing ..." << std::endl;
std::cout << " The first var is: " << results1 << std::endl;
std::cout << " The second var is: " << results2 << std::endl;


}


//=======================================
int main(){

std::cout<< " OK, Lets get started:" << std::endl;

main_ns::calc_cls<double, int> object(3.0, 3);
object.calc1_fn();
object.calc2_fn();
object.print_fn();

std::cout<< " Alright. Done." << std::endl;

return 0;
}



