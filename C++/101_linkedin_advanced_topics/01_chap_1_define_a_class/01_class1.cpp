
// Linkein:  Advanced topics in c++
// Babak Poursartip
// 04/26/2020

#include <cstdio>

// simplest class
class c1{

private: // data encapsulation
  int i = 0;

public: // methods
  void setvalue(const int &value);
  int getvalue() const;// this method member is const saved. 
  
};

void c1::setvalue(const int &value){
  i = value;
}
int c1::getvalue() const {
  return i;
} // this method member is const saved. 


int main(){

  printf(" code starts ... \n");
  const int i=47;
  c1 o1;
  o1.setvalue(i);
  printf(" value is: %d  \n", o1.getvalue() );
  printf(" code ends. \n");

  return 0;
}

