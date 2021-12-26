
/*
Babak Poursartip
12/25/2021
unnamed namespace: 

All content declared in an unnamed namespace is treated as if it is part of the parent namespace. So even though function doSomething is defined in the unnamed namespace, the function itself is accessible from the parent namespace (which in this case is the global namespace), which is why we can call doSomething from main without any qualifiers.

But the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated as if they had internal linkage, which means that the content of an unnamed namespace can’t be seen outside of the file in which the unnamed namespace is defined.

For functions, this is effectively the same as defining all functions in the unnamed namespace as static functions.

Unnamed namespaces are typically used when you have a lot of content that you want to ensure stays local to a given file, as it’s easier to cluster such content in an unnamed namespace than individually mark all declarations as static.

An inline namespace is a namespace that is typically used to version content. Much like an unnamed namespace, anything declared inside an inline namespace is considered part of the parent namespace. However, inline namespaces don’t give everything internal linkage

*/

#include <iostream>

namespace {
   int variable;
   int i; 
   void funct (int);
   }


namespace {
   void funct (int i) { std::cout << i << std::endl; }
   }

namespace v1 // declare a normal namespace named v1
{
    void doSomething()
    {
        std::cout << "v1\n";
    }
}

inline namespace v2 // declare an inline namespace named v2
{
    void doSomething()
    {
        std::cout << "v2\n";
    }
}



int i = 2;

int main()
{
  std::cout << " starts here ... \n";

  funct(variable);
  //std::cout << i << std::endl; // error: ambiguous i.

  v1::doSomething(); // calls the v1 version of doSomething()
  v2::doSomething(); // calls the v2 version of doSomething()
  doSomething(); // calls the inline version of doSomething() (which is v2)

  std::cout << " done. \n";
  return 0;
}
