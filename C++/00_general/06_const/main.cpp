
/*

Babak Poursartip
04/30/2020

Bo Qian- Advaced c++: const

- if const is on the left of *, data is const
- if const is on the right of *, pointer is cosnt

benefits of const:
- Guard against inadvertent write.
- self documentation
- enables compiler to do more optimization

*/

#include <iostream>

// ============================================================
class check_const_in_class{
public:
  mutable int var = 0; // by putting mutable here, we allow const function to change the content of var.
  int var2=4;

  check_const_in_class(int _x, int _y):_x{_x},_y{_y}{printf(" constructor\n");}

  int get_x() const{
    //_y++; error
    int ii;
    ii++;
    var = 10;
    //var2++;// increment of member ‘check_const_in_class::var2’ in read-only object
    return _x;
  }

  void set_y (int y){_y=y;}

  const int* const get_y() const{
    //_y++; error
    return &_y;
  }


private:
  int _x, _y;

};

// ============================================================
int main(){

std::cout << "------ The code starts ------ \n\n";

// compile time constraint that an object cannot be modified.

// const var ----------------------------------------------------
puts("1 ======= const data");
const int ii = 10;
int jj = 3;
//ii = 12; error i is a constant

// data the pointer is pointing is const, but pointer is not a constant ------------
puts("2 =======  const data");
const int *p1 = &ii;
//int const *p1 = &ii; // the same as before
std::cout << " pointer1: " << *p1 << "\n";
//*p1= 5; error.
p1++;
std::cout << " pointer1: " << *p1 << "\n";

puts("3 =======  const data");
p1 = &jj;
std::cout << " const data pointer to non-const var: " << *p1 << "\n";
jj++; // ok 
std::cout << " const data pointer to non-const var change: " << *p1 << "\n";
//*p1=5; // error

// const pointer not data the pointer is pointing ------------------
puts("4 =======  const pointer");
//int* const p2= &ii; // compilation error: invalid conversion from const int* to int*
int* const p2= &jj;
std::cout << " pointer2: " << *p2 << "\n";
*p2 = 5;
//p2 = &ii; error
std::cout << " pointer2: " << *p2 << "\n";


// data and pointer are both constants ---------------------------------------
const int* const p3  = &ii;
std::cout << " pointer3: " << p3 << " "<<*p3 << "\n";
//p3=&jj; error
//p3++; //error


//=============================================================================
puts("5 =======");
const char *p10 = "123456";
char *p11 = "123456";//compilation warning,"123456" is "const char*", but p11 is char*.
std::cout << " P10: " << p10 << " "<<p11 << "\n";
std::cout << " P10: " << *p10 << " "<<*p11 << "\n";

p10 = "Babak";
p11 = "Babak"; //compilation warning, "Babak" is "const char*", but p11 is char*.

std::cout << " P10: " << p10 << " "<<p11 << "\n";

//=============================================================================
// remove the constantness of a constant
puts("6 ======= const_cast");
const int a = 20;
const int* b = &a;
//int* pc = &a; // error: cannot convert "const int*" to "int*"<<<<< important

std::cout<<"old value is "<<*b<<"\n";
int* c=const_cast<int *>(b);
*c=40;
std::cout<<"new value is "<<*b << std::endl;

puts("6 ======= ??");
//make a var constant in the middle of the code.
int j=4;
std::cout << " var is: " << j << "\n";
//static_cast<const int&>(j) = 13;  Not working !
std::cout << " var is: " << j << "\n";  


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
