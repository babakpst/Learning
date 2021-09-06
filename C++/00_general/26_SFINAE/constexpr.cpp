
/*

constexpr allows to evaluate the value of a function or variable at the compile time, thus it can be used where only compile time constant expressions are allowed. 

restrictions:
==variables
- By using the keyword constexpr the variable becomes a constant expression. Therefore, I can use the variable in contexts that require a constant expression. For example, if I want to define the size of an array. This has to be done at compile time.
- constexpr variables should be initialized immediately and the variable can only depend on values that can be evaluated at compile time.
- Only static members of a class can be constexpr, because non-static members of a class instantiate at the runtime, but static members instantiate at the compile time. 


==functions
- The function should not be virtual (because virtual means at the runtime).
- can have control block except goto, label, try block, ... .
- a constexpr function can only call a constexpr function. 
- constexpr function should refer only constant global variables, other it would not be calculated at the compile time.
- It cannot read/write anything outside the function. 
- We can use local variables in a constexpr function only if they are initialized, have no static specifier. The local vars do not need to be of a literal type, they can be of a user-defined type, but the ctor for the user-defined type/class should be constexpr itself. A ctor can be constexpr only if it initializes all class members. It is also possible to not (strictly) initialize a local varialbe of a user-defined type in a function, if the user-defined type/class has a constexpr default ctor.	



- return type should be a literal type (not in c++20, it can be a void (see the example below)). <<<<<<<<<<<<<<<<<



== classes
- A constexpr constructor, should initialize all members of the class. We can have a constexpr default ctor as well, as long as all the members of the class are initialized.

*/

#include <iostream>

// ===============================================
template<typename T>
constexpr T square(T x){return x*x;}

// ===============================================
template<typename T>
constexpr void voidSquare(T &x){x*=x;}

// ===============================================
//  A class with constexpr constructor and function
class Rectangle
{
    int _h, _w;
public:
    // A constexpr constructor
    constexpr Rectangle (int h, int w) : _h(h), _w(w) {}
    constexpr Rectangle () : _h(0), _w(0) {}
    //constexpr Rectangle () {} // error: a constexpr constructor must initialize all members
    //Rectangle () {}

    //constexpr int getArea ()  {   return _h * _w; }
    int getArea ()  {   return _h * _w; }
    
    static const int C1;
    //static constexpr int C2; // error, we should declare it : static data member ‘C2’ must have an initializer
    //constexpr int C3=2; // error non-static data member ‘C3’ declared ‘constexpr’
    static constexpr int C2 =2;

    
};

// ============================================
constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}


// ===============================================
constexpr int product(int x, int y)
{
    //int z1; // error, not initialized   
    int z2 =1; // ok, initialized
    //static int z3; // error cannot be declared as static
    Rectangle z4(4,5);
    Rectangle z5;
    return (x * y);
}
  
// ===============================================
int main()
{

    std::cout << "1 =======================\n";
    
    const int x = product(10, 20);
    std::cout << x << std::endl;

    // value of res is computed at compile time. 
    const long int res = fib(30);
    std::cout << res<< std::endl;

    // value of res is NOT computed at compile time. 
    long int res2 = fib(30);
    std::cout << res<< std::endl;

    std::cout << "2 =======================\n";
    // Below object is initialized at compile time
    constexpr Rectangle obj(10, 20);
    //std::cout << obj.getArea()<< std::endl;

    // template with constexpr
    int xx = 12;
    int xSQ= square(xx);
    std::cout << " template_constexpre square: " << xSQ << std::endl;
    voidSquare(xx);
    std::cout << " void template_constexpre square: " << xx << std::endl;

    std::cout << "3 =======================\n";

    return 0;
}
