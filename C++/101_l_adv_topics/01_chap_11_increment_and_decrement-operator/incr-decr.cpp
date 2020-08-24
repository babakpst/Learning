// incr-decr.cpp by Bill Weinman <http://bw.org/>
// version of 2018-11-10

// 05/26/2020

#include <iostream>
using namespace std;

class num {
    int value = 0;
public:
    num( int x = 0 ) : value(x) {}

    int getvalue() const { return value; }
    void setvalue( int x ) { value = x; }

    num & operator ++ ();  // pre fix - empty parameter

    // post fix - has a variable inside- this is just a dummy variable to tell the compiler 
    // to distiguish it from the pre-inc. This dummy variable is always of type int. Regardless 
    // of the type of the actual class. Even in the implementation, there is no symbol/var for int
    num operator ++ (int); 
    num & operator -- (); // pre-fix
    num operator -- (int); // post-fix
};


// pre-increment
num & num::operator ++ () {
    cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment - no symbol for int
// notice that we return the temp, the value is then incremented.
num num::operator ++ (int) {
    cout << "post-increment: ";
    num temp = *this;  
    value += 1;
    return temp;
}

// pre-decrement
num & num::operator -- () {
    cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement  - no symbol for int
num num::operator -- (int) {
    cout << "post-decrement: ";
    num temp = *this;
    value -= 1;
    return temp;
}

ostream & operator << (ostream & o, const num & n) {
    return o << (n.getvalue());
}

int main()
{
    num n(42);
    cout << "value is " << n << endl;
    // the increment happens before the value is returned
    cout << "value is " << ++n << endl;
    cout << "value is " << n << endl;
   
    // the increment happens after the value is returned
    cout << "value is " << n++ << endl;
    cout << "value is " << n << endl;



 return 0;
}
