

/*

Babak Poursartip
11/20/2021

type_traits type traits

source:https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/types/enable_if.html

*/


#include <type_traits>
#include <iostream>
 
// foo1 overloads are enabled via the return type
template<class T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type 
    foo1(T t) 
{
    std::cout << "foo1: float\n";
    return t;
}
 
template<class T>
std::enable_if_t<std::is_integral<T>::value, T> //Using helper type
    foo1(T t) 
{
    std::cout << "foo1: int\n";
    return t;
}
 
//============================================================
// foo2 overload is enabled via a parameter
template<class T>
T foo2(T t, typename std::enable_if<std::is_integral<T>::value>::type* = 0) // if integral type, then foo2 would be foo2(T t, void* = 0)
{
    std::cout << " foo2 void " << t  << " \n";
    return t;
}

template<class T>
T foo2(T t, typename std::enable_if<std::is_integral<T>::value, T>::type* ) 
{
    std::cout << " foo2 integral " << t  << " \n";
    return t;
}


int foo2_check(int t, void* = 0) // if integral type, then foo2 would be foo2(T t, void* = 0)
{
    std::cout << " foo2 check void " << t  << " \n";
    return t;
}

 
//============================================================
// foo3 overload is enabled via a template parameter
template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr >
T foo3(T t) // note, function signature is unmodified
{
    std::cout << " foo3 \n";
    return t;
}
 
//============================================================
// A is enabled via a template parameter
template<class T, class Enable = void>
class A; // undefined
 
template<class T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value >::type> {
}; // note: for this use case, static_assert may be more appropriate
 

//============================================================
int main()
{

    float fvar = 1.0f;
    double dvar = 2.0;
    int ivar = 5;
    
    foo1(1.2); // OK, calls the first version of foo1()
    foo1(10); // OK, calls the second version of foo1()
    
    foo1(fvar);
    foo1(dvar);
    foo1(ivar);
 
    //foo2(0.1f); // compile-time error
    std::cout << std::endl;
    foo2(7); // OK
    int* pint=new int;
    foo2(7,pint); // OK
 
    float* pflt=new float;
    foo2(7, pflt); // OK

    foo2_check(5);
    foo2_check(8,pflt);


    std::cout << std::endl;
//  foo3(1.2); // compile-time error
    foo3(34); // OK
    void* vflt;
    //foo3<int, vflt>(345); // OK
 
//  A<int> a1; // compile-time error
    A<double> a1; // OK
}
