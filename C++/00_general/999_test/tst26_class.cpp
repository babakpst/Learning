
#include <iostream>

class b1{
public:
int aa;
};

class b2{
public:
char aa;
};

class d1:public b1, public b2{};

int main(){
d1 d;

//d.aa = 'a';
//d.b2::aa = 5;

d.b1::aa = 5;
d.b2::aa = '4';

std::cout << " b1: " << d.b1::aa<< " b2: " << d.b2::aa << std::endl;

return 0;
}
