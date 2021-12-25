
// Babak Poursartip
// 10/13/2020


// reference
// return by reference

#include <iostream>


class AA
{
    public:
    int num;
    AA(int a):num(a){}
    int& ref(){return num;}
    int val(){return num;}
};


int main(){

int &r; // compiler error. should be initialized.

int a = 10;
int &b = a;
int c= 15;
b = c;

std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

a = 12;

std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

//======================
AA obj(5);
cout << obj.val() << endl;

int* ptr=nullptr;
ptr = &obj.ref();
cout << *ptr << endl;

*ptr = 12;
cout << obj.val() << endl;

return 0;

}
