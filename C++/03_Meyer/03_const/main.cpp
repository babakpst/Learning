
/*

Babak Poursartip
11/09/2020

source: Effective C++, Meyer

Topic: const
item2 

*/

#include <iostream>
#include <vector>

int main(){

  std::cout << "starts ... \n";
  
  //identical
  int a = 5;
  int const *pa = &a;
  const int *pb = &a;
  
  std::cout << " pa=" << *pa << std::endl;
  std::cout << " pb=" << *pb << std::endl;
  
  
  //const iterator in STL
  std::vector<int> myV{1,2,3,4,5};
  std::vector<int>::iterator it =myV.begin();
  *it = 6;
  std::cout << " myV1=" << *it << std::endl;  
  ++it; 
  std::cout << " myV2=" << *it << std::endl;  
  
  std::vector<int>::const_iterator cit =myV.begin();
  //*cit = 6; This is a compilation error
  std::cout << " myV1=" << *cit << std::endl;  
  ++cit; 
  std::cout << " myV2=" << *cit << std::endl;  
    
  
  
  
  std::cout << "finished\n";
  return 0;
}
