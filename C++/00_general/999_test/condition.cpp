#include <iostream>

int main(){

int a, b;

(5>6) ? (a=50,b=10):(a=10,b=50);

std::cout << a << " " << b << "  "<< abs(a-b) <<std::endl;
}
