
// Babak Poursartip
// based on Discovering modern c++ - section 3.9: lambda

#include <iostream>
//#include <sstream>
#include <math.h>

// =====================================================
double func_diff_forward(double f(double), double x, double h){
  return ((f(x+h)-f(x))/h);
}


//double func_diff_backward(std::function<void()> f(double), double x, double h){
//  return ((f(x)-f(x-h))/h);
//}

int main(){

  double x = 1.1;
  double h = 0.01;
  double phi = 2.0;

  std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward(sin,x,h) <<"\n";


  std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward([](double x){return sin(x);},x,h) <<"\n";

  std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward([](double x){return sin(x)+cos(x);},x,h) <<"\n";

  auto l1= [](double x){return sin(x)+cos(x);};
  std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward(l1,x,h) <<"\n";

  // this is capturing lambda: not working ???
  auto l2 = [phi](double x)->auto{return sin(phi*x);};
  std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward(l2,x,h) <<"\n";
  //std::cout << "Backward Dsin("<<x<<")="<< func_diff_backward( l2, x, h) << "\n";
  

return 0;
}
