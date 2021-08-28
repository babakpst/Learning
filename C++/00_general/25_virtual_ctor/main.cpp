
/*

Babak Poursartip
07/13/2021

https://www.geeksforgeeks.org/advanced-c-virtual-constructor/

We cannot make a class constructor virtual in C++ to create polymorphic objects. C++ being statically typed (the purpose of RTTI is different) language.

If we make constructor virtual, compiler flags an error. In fact, except inline, no other keyword is allowed in the declaration of the constructor.

The objective of the virtual constructor is to decouple object creation from its type.


In the following example: The User class is independent of object creation. It delegates that responsibility to Base, and provides an input in the form of ID. If the library adds new class Derived4, the library modifier will extend the if-else ladder inside Create to return proper object. Consumers of User need not recompile their code due to extension of Base.

Note that the function Create used to return different types of Base class objects at runtime. It acts like virtual constructor, also referred as Factory Method in pattern terminology.

*/


#include <iostream>
using namespace std;
  
//// LIBRARY START
class Base
{
public:
  
    // The "Virtual Constructor"
    static Base *Create(int id);
  
    Base() { }
  
    virtual // Ensures to invoke actual object destructor
    ~Base() { }
  
    // An interface
    virtual void DisplayAction() = 0;
};
  
class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }
  
    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};
  
class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }
  
    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};
  
class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }
  
    ~Derived3()
    {
        cout << "Derived3 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived3" << endl;
    }
};
  
// We can also declare "Create" outside Base
// But it is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User code need not be recompiled to create newly added class objects
  
    if( id == 1 )
    {
        return new Derived1;
    }
    else if( id == 2 )
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}
//// LIBRARY END
  
//// UTILITY START
class User
{
public:
    User() : pBase(nullptr)
    {
        // Receives an object of Base hierarchy at runtime
  
        int input;
  
        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;
  
        while( (input !=  1) && (input !=  2) && (input !=  3) )
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }
  
        // Get object from the "Virtual Constructor"
        pBase = Base::Create(input);
    }
  
    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = nullptr;
        }
    }
  
    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }
  
private:
    Base *pBase;
};
  
//// UTILITY END
  
//// Consumer of User (UTILITY) class
int main()
{
    User *user = new User();
  
    // Action required on any of Derived objects
    user->Action();
  
    delete user;
    
}    
