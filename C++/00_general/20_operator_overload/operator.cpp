/*

Babak Poursartip
05/04/2020

operator overloading

geeksforgeeks

*/

#include <iostream>

class complex{
private:
int real, imag;

public:
complex();
complex(int, int);
complex operator+(complex const &) const;
void print() const;


};


complex::complex(int real=0, int imag=0):real(real), imag(imag){};

void complex::print() const{std::cout<< real << " + "<< imag << "i\n";};

// This func will be called when '+' appears btw the two complex numbers.
complex complex::operator+(complex const &obj)const{ return complex(real+obj.real, imag+obj.imag);};

int main(){

complex a(4,5), b(2,3), c(0,0);
a.print();
b.print();

c=a+b;
c.print();

return 0; 
}
