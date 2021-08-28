// functor.cpp by Bill Weinman <http://bw.org/>
#include <sstream>


class Multiply{
  int _mult = 1;
  Multiply();
public:
  Multiply(int n):_mult(n){};
  // operator overload: 
  // the overload operator is the function overload operator ()
  int  operator () (int n) const {return _mult*n;}
};

int main(){
  
  const Multiply times4(4);
  const Multiply times11(11);
  const Multiply times12(12);

  printf(" 4 by 4 is: %d \n", times4(4)); 
  printf(" 6 by 4 is: %d \n", times4(6)); 

  printf(" 5 by 11 is: %d \n", times11(5)); 
  printf(" 5 by 12 is: %d \n", times12(5)); 
  return 0; 
}
