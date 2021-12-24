
#pragma once
#include "ClassA.h"

/*
Forward declaration, instead of including the header file.
If you are going to invoke the constructor, copy constructor or any method of ClassB in the 
header file of MyClass, then you need to use #include "ClassB.h". If you have a pointer to 
ClassB in MyClass.h or passing ClassB by reference in a method argument, you can simply use the 
forward declaration instead.

You can get the declaration of a function into your current .cpp or .h file by #includ'ing the 
header that already contains a declaration of the function. However, this can slow down your 
compile, especially if you #include a header into a .h instead of .cpp of your program, as 
everything that #includes the .h you're writing would end up #include'ing all the headers you wrote 
#includes for too. Suddenly, the compiler has #included pages and pages of code that it needs to 
compile even when you only wanted to use one or two functions. To avoid this, you can use a 
forward-declaration and just type the declaration of the function yourself at the top of the file. 
If you're only using a few functions, this can really make your compiles quicker compared to always 
#including the header. For really large projects, the difference could be an hour or more of compile
 time bought down to a few minutes.
*/

//#include "ClassB.h" // any changes in the ClassB.h (and not .cpp) will recompile this file. 
class B; // forward declaration

// We do not need to include ClassC header here, bcs in this header we do not use the ClassC in this file, even though
// we are using ClassC in the cpp of this class. So, we can only include the ClassC.h in the cpp file. 
//#include "ClassC.h" 



class myClass
{
public:
  myClass();
  myClass(int, A);
  myClass(int, A, B*);
  void func();
  void setter(int, A, B*);
  int getInt();
  A getA();
  B* getBPnt();

private:
  int cvar;
  A aClassVar;
  B *bPnt;
  int deleteme;

};
