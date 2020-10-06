#include <iostream>
#include <string>

using namespace std;

class SomeClass{
    public:
        SomeClass() {total++; cout << "base \n";}
        static int total;
        void Print(string n) { cout << n << ".total = " << total << endl; }
};

int SomeClass::total = 0;

class SomeDerivedClass: public SomeClass{
    public:
        SomeDerivedClass() {total++;cout << "derived \n";}
};




int main(int argc, char ** argv)
{
    SomeClass A;
    SomeClass B;
    SomeDerivedClass C;

    //int SomeClass::total = 0;

    // Each time SomeClass ctor is called, the total var will increments once. 
    // The derived class calls the two ctor, so the final value is 4.
    A.Print("A");  // prints 4
    B.Print("B");  // prints 4
    C.Print("C");  // prints 4

    return 0;
}
