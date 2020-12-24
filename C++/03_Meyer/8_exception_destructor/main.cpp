
/*

Babak Poursartip
12/24/2020

source: Effective C++, Meyer

Topic: 
item 8: exception in the destructor


Exception should not be thrown OUT of the destructor.  
C++ does not like having more than one exceptions pending at the same time. 

We can have the entire catch statement in the destructor, but the better idea is to have the entire exception in a different function. 
See Bo Qian.

*/


#include <iostream>


class dog{
public:
  std::string m_name;
  dog(std::string name):m_name(name){std::cout << m_name << " is born.\n";}

  ~dog(){
  std::cout << m_name << " is destroyed.\n";
  throw 20;
  }

  void bark(){std::cout << m_name<< " barks\n";}
};


int main(){

std::cout << " starts ...\n";


// barks would not be called. And dogs would be destroyed before throwing the exception.
/*
try{
  dog dog1("bob");
  dog dog2("twinky");
  throw 20;
  dog1.bark();
  dog2.bark(); 
}catch(int e){
  std::cout << e << " is caught.\n";
}
*/

/* At the end of the try block, bob and twinky should be destroyed. When bob is going to be destroyed, one execption would be thrown, and when it comes to twinky, the second exception will be thrown can causes an abortion. */

try{
  dog dog1("bob");
  //dog dog2("twinky");
  dog1.bark();
  //dog2.bark(); 
}catch(int e){
  std::cout << e << " is caught.\n";
}


std::cout << " finished!\n";

return 0;
}
