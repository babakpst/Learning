/*
Babak Poursartip

12/9/2021

using template as the template parameter

*/

#include <iostream>
#include <vector>

template<typename T>
class node
{
public:

  node(){std::cout << " default ctor \n";}
  node(T val1, T val2):val1{val1}, val2{val2}{std::cout << " ctor \n";}
  ~node(){std::cout << " dctor \n";}
  
  void get()
  {
    std::cout << " values " << val1 << " " << val2 << std::endl;
  }
  
private:
  T val1;
  T val2;
};


int main()
{

  std::cout << " starts ... \n";

  std::vector<node<int>> vecNode(5);
  node<float> myNode(3,5);
  myNode.get();
  std::vector<node<float>> vecNode2(5,myNode);
  vecNode2[1].get();

  std::cout << " Done \n";
  return 0;
}
