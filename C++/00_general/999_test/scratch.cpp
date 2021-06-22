
#include <iostream>
#include <vector>
#include <memory>

int main()
{

std::cout << " starts ... \n";


//const int *ptr = &b;
//int *ptr2 = ptr;

char *cp = "babak";

//int *c = &b;
//int const *d = c;


//const char *aa = "shiva";
//aa[0] = 'b'; // error: const

//char *bb = "shiva";
//bb[0] = 'b';


char q = 'a';
std::cout << q << std::endl;

//char qq = "babak";
//std::cout << qq << std::endl;

std::cout << "-----\n";

std::vector<int> check(10);

for (std::vector<int>::iterator it = begin(check); it != end(check);++it)
*it=5;

//for(auto p:check)
// p = 0.1;

//for(auto p:check)
//std::cout<< p << std::endl;

int *ptr = new int(5);
ptr[0] =5;
ptr[2] =50;
std::cout << ptr[0] << " " << ptr[2] << std::endl;

//std::unique_ptr<int> myVec = std::make_unique<int>(5);
std::unique_ptr<int> myVec(new int(5));

//*myVec=5;
myVec(0)=0;
myVec[1]=1;
myVec[2]=2;
myVec[3]=3;
myVec[4]=5;

//for (auto p:myVec)
//std::cout << *p << std::endl;


//std::unique_ptr<std::vector<int>> myVec = std::make_unique<std::vector<int>>();


std::cout << " ends. \n";
return 0;
}
