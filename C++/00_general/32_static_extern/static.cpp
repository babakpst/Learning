/*

- static can be used INSIDE or OUTSIDE of a class/struct.

*** static INSIDE a class/struct **************
- The static variables in a class are shared by the objects. There can not be
multiple copies of same static variables for different objects. Also because of
this reason static variables can not be initialized using constructors.

- By declaring a function member as static, you make it independent of any
 particular object of the class. A static member function can be called even
 if no objects of the class exist and the static functions are accessed using
 only the class name and the scope resolution operator ::.

- Just like the static data members or static variables inside the class, static
member functions also does not depend on object of class

- We are allowed to invoke a static member function using the object and the ‘.’
operator but it is recommended to invoke the static members using the class name
and the scope resolution operator.

- Static member functions are allowed to access only the static data members or
other static member functions, they can not access the non-static data members
or member functions of the class.

- Static member functions have a class scope and they do not have access to the
 this pointer of the class.You could use a static member function to determine
 whether some objects of the class have been created or not.

- static members of a class can be accessed/modified through objects.

- static methods cannot access not-static members of the class.

*** static OUTSIDE a class/struct **************
- internal usage.
- Marking a function or a global variable as static makes it invisible to the
linker once the current translation unit is compiled into an object file.
Declaring a function as static prevents other files from accessing it. In other
words, it is only visible to the file it was declared in; a "local" function. It
prevents other translation units (.c files) from seeing the function. Keeps
things clean and tidy. A function without static is extern by default (is
visible to other modules).


*/

#include <iostream>

using namespace std;

class Box {
public:
  static int objectCount;

  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0)
      : length{l}, breadth{b}, height{h} {
    cout << "Constructor called." << endl;

    // Increase every time object is created
    objectCount++;
  }

  double Volume() { return length * breadth * height; }

  static int getCount_static() {
    // cout << "length:" << length << endl;  error: static functions cannot
    // access non-static members of the class.
    return objectCount;
  }

  static int getCount2(int var) {
    cout << "var:" << var << endl;
    return objectCount;
  }

private:
  double length;  // Length of a box
  double breadth; // Breadth of a box
  double height;  // Height of a box
};

// We have to initialize the static variables. If we do not initialize the
// static variables, we cannot use them.
// Initialize static member of class Box.
int Box::objectCount = 0;

// =========================================
int main(void) {

  // If we do not initialize the static members of the class outside the class,
  // we cannot use them here. That would be an "undefined reference to
  // objectCount"
  Box::objectCount = 5;

  // Print total number of objects before creating object.
  // static function is accessible without initiating and object.
  cout << "Inital Stage Count: " << Box::getCount_static() << endl;
  cout << "static member func with argument: " << Box::getCount2(123) << endl;

  Box Box1(3.3, 1.2, 1.5); // Declare box1
  Box1.objectCount = 12;
  cout << "Box1 calling static count: " << Box1.objectCount << endl;
  Box Box2(8.5, 6.0, 2.0); // Declare box2
  cout << "Box1 calling static count: " << Box1.objectCount << endl;
  cout << "Box2 calling static count: " << Box2.objectCount << endl;

  // Print total number of objects after creating object.
  cout << "Final Stage Count: " << Box::getCount_static() << endl;
  cout << "Final Stage Count: " << Box1.getCount_static() << endl;
  cout << "Final Stage Count: " << Box2.getCount_static() << endl;

  return 0;
}
