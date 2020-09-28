#include <iostream>
#include <string>

using namespace std;

class SomeClass{
    public:
        SomeClass() {total++;}
        static int total;
        void Print(string n) { cout << n << ".total = " << total << endl; }
};

int SomeClass::total = 0;

class SomeDerivedClass: public SomeClass{
    public:
        SomeDerivedClass() {total++;}
};




int main(int argc, char ** argv)
{
    SomeClass A;
    SomeClass B;
    SomeDerivedClass C;

    //int SomeClass::total = 0;

    A.Print("A");
    B.Print("B");
    C.Print("C");

    return 0;
}
