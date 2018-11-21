
// include section
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

double sin_func(double x){
  return (sin(x));
}

double func_diff_forward(double f(double), double x, double h){
  return ((f(x+h)-f(x))/h);
}

double func_diff_backward(double f(double), double x, double h){
  return ((f(x)-f(x-h))/h);
}

double func_diff_central(double f(double), double x, double h){
  return ((f(x+h)-f(x-h))/(2*h));
}


// functor
struct sin_f{
  double operator() (double x) const
  {
    return sin(x);
  };
};

// This is functor (function object)
class scale_sin_f{
public:
scale_sin_f(double alpha):alpha(alpha){}

double operator () (double x) const{
return sin(alpha*x);
};
private:
double alpha;
};



template <typename F, typename T>
T inline func_differential(F f, const T& x, const T& h)
{
  return (f(x+h)-f(x))/h;
}


int main(){

double x= 1.1;
double h= 0.01;
scale_sin_f scale_obj_o(2.2);


std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward(sin_func,x,h) <<"\n";
std::cout << "Backward Dsin("<<x<<")="<<func_diff_backward(sin_func,x,h) <<"\n";
std::cout << "Central Dsin("<<x<<")="<<func_diff_central(sin_func,x,h) <<"\n";
std::cout << "Exact Dsin("<<x<<")="<<cos(x) <<"\n";
std::cout << "Error:" << 100.0*abs((func_diff_forward(sin_func,x,h)  - cos(x) )/cos(x) ) << "\n";
std::cout << "Error:" << 100.0*abs((func_diff_backward(sin_func,x,h) - cos(x) )/cos(x) ) << "\n";
std::cout << "Error:" << 100.0*abs((func_diff_central(sin_func,x,h)  - cos(x) )/cos(x) ) << "\n";

std::cout << "Functor sin("<<x<<")="<< func_differential(scale_obj_o,x,h) <<"\n";
std::cout << "Functor sin("<<x<<")="<< func_differential(scale_obj_o(1.5),x,h) <<"\n";
std::cout << "Functor sin("<<x<<")="<< func_differential(sine_func,x,h) <<"\n";

std::cout << "End of the code"<< "\n";
}