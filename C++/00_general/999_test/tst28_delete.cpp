

#include "iostream"

int main(){

std::cout << " starts ... \n";

typedef std::string addressline[4];

std::string *ps = new addressline;

//std::cout << " size " << sizeof(ps) << std::endl;

delete[] ps;



return  0;
}
