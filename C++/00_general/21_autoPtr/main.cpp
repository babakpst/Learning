
/*

Babak Poursartip

10/2/2021

pointer to a stack var or heap.


*/

#include <iostream>


class node{
  public:
    int var = 5;
};


int main()
{
std::cout << " starts ...\n";

node nd;
std::cout << " node: " << nd.var << std::endl;

node *pnd = nullptr;

pnd = &nd;
std::cout << " pointer node: " << pnd->var << std::endl;

node *pnd2(new node);
pnd2->var = 6;
std::cout << " pointer2 node: " << pnd2->var << std::endl;
delete pnd2;
delete pnd;



std::cout << " ends here \n";
return 0;
}

