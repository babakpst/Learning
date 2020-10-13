
// Babak Poursartip
// 10/13/2020


// reference
#include <iostream>

int main(){

int &r; // compiler error. should be initialized.

int a = 10;
int &b = a;
int c= 15;
b = c;

std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

a = 12;

std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

return 0;

}
