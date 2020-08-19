
/*

Babak Poursartip
04/30/2020

Bo Qian- Advaced c++: const

*/

#include <iostream>

class check_const_in_class{

private:
  int _x, _y;



public:
  mutable int var = 0; // by putting mutable here, we all const function to change the content of var.

  check_const_in_class(int _x, int _y):_x{_x},_y{_y}{printf(" constructor\n");}
  int get_x() const{
    //_y++; error
    int ii;
    ii++;
    var = 10;
    return _x;
  }

  void set_y (int y){_y=y;}

  const int* const get_y() const{
    //_y++; error
    return &_y;
  }


};

// ============================================================
int main(){

std::cout << "------ The code starts ------ \n\n";

// compile time constraint that an object cannot be modified.

// const var ------------------------------------------------------------------
const int ii = 10;
int jj = 3;
//ii = 12; error i is a constant

// data the pointer is pointing is const, but pointer is not a constant ------------
const int *p1 = &ii;

std::cout << " pointer1: " << *p1 << "\n";
//*p1= 5; error.
p1++;
std::cout << " pointer1: " << *p1 << "\n";

// const pointer not data the pointer is pointing ------------------
int* const p2= &jj;
std::cout << " pointer2: " << *p2 << "\n";
*p2 = 5;
//p2 = &ii; error
std::cout << " pointer2: " << *p2 << "\n";

// data and pointer are both constants ---------------------------------------
const int* const p3  = &ii;
std::cout << " pointer3: " << p3 << " "<<*p3 << "\n";
//p3=&jj; error


// data cosntant
int const *p4 = &ii; // this is the same as: const int*p4;
std::cout << " pointer4: " << p4 << " "<<*p4 << "\n";


// if const is on the left of *, data is const
// if const is on the right of *, pointer is cosnt

//=============================================================================
// remove the constantness of a constant
const int kk = 10;
std::cout<< " the constant is: " << kk << "\n";
const_cast<int&>(kk) = 12;
std::cout<< " the constant is: " << kk << "\n"; // not actually working.


//make a var constant in the middle of the code.
int j=4;
std::cout << " var is: " << j << "\n";
//static_cast<const int&>(j) = 13;  Not working !
std::cout << " var is: " << j << "\n";  
j = 16;
std::cout << " var is: " << j << "\n";

/*
benefits of const:
- Guard against inadvertent write.
- self documentation
- enables compiler to do more optimization
*/

// ============================================================
// class
check_const_in_class obj(1,2);
printf(" here is x: %d \n",obj.get_x());
obj.set_y(5);

const int* const p5 = obj.get_y();
printf(" here is y: %d \n", *p5);

const int *p6 = obj.get_y();
printf(" here is y: %d \n", *p6);
printf(" here is var: %d \n", obj.var);

std::cout<< " \n ---- Finished successfully ----- \n";

return 0;
}
