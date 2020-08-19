
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
  auto l2 = [&](double x){
    phi = 3.14;
    return sin(phi*x);
  };
  printf(" l2: %f \n",l2(2));
  
  //std::cout << "Forward Dsin("<<x<<")="<<func_diff_forward(l2,x,h) <<"\n";
  //std::cout << "Backward Dsin("<<x<<")="<< func_diff_backward( l2, x, h) << "\n";

  // ===============================
  puts("==========");
  int var1 = 10;
  double var2 = 1.1;
  int var3 = 5;

  // pass arg by reference
  auto l3 = [&](int x){
    printf(" lambda 3: %d \n", x);
    printf(" var1: %d \n", var1);
    printf(" var2: %f \n", var2);
    printf(" var3: %d \n", var3);
    var1 = 12;
    printf(" var1: %d \n", var1);
  };

  printf(" var1 ouside before: %d \n", var1);
  l3(6);
  printf(" var1 ouside after: %d \n", var1);

  puts("==========");
  // pass arg by value- without the mutable, there would be an error, bcs vars are constant inside the lambda function. We need to make them non-constant/mutable.
  auto l4 = [=](int x)mutable{
    printf(" lambda 3: %d \n", x);
    printf(" var1: %d \n", var1);
    printf(" var2: %f \n", var2);
    printf(" var3: %d \n", var3);
    var1 = 13;
    printf(" var1: %d \n", var1);
  };

  printf(" var1 ouside before: %d \n", var1);
  l4(6);
  printf(" var1 ouside after: %d \n", var1);

  

return 0;
}
