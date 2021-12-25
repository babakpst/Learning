/*
Babak Poursartip
12/24/2021

topic: template template argument

*/

#include <iostream>
#include <typeinfo>

using namespace std;

//=============================================
template<class T, class U> 
class A
{
public:
   int x;
};


//=============================================
template<class U> 
class A<int, U>
{
public:
   short x;
};

//template-template ==================================
//template<template<class T, class U> typename V>  // correct
template<template<class T, class U> typename V> 
class B
{

public:
   V<int, char> i;
   V<char, char> j;
};

B<A> c;

//==============================
int main() {
   cout << typeid(c.i.x).name() << endl;
   cout << typeid(c.j.x).name() << endl;
}
