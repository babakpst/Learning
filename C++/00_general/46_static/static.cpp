

// By declaring a function member as static, you make it independent of any
// particular object of the class. A static member function can be called even
// if no objects of the class exist and the static functions are accessed using
// only the class name and the scope resolution operator ::.

// A static member function can only access static data member, other static
// member functions and any other functions from outside the class.

// Static member functions have a class scope and they do not have access to the
// this pointer of the class.You could use a static member function to determine
// whether some objects of the class have been created or not.

#include <iostream>

using namespace std;

class Box {
public:
  static int objectCount;

  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout << "Constructor called." << endl;
    length = l;
    breadth = b;
    height = h;

    // Increase every time object is created
    objectCount++;
  }
  double Volume() { return length * breadth * height; }
  static int getCount() {
    // cout << "length:" << length << endl;  error
    return objectCount;
  }

private:
  double length;  // Length of a box
  double breadth; // Breadth of a box
  double height;  // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
  // Print total number of objects before creating object.
  // static function is accessible without initiating and object.
  cout << "Inital Stage Count: " << Box::getCount() << endl;

  Box Box1(3.3, 1.2, 1.5); // Declare box1
  cout << "Box1 calling static count: " << Box1.objectCount << endl;
  Box Box2(8.5, 6.0, 2.0); // Declare box2
  cout << "Box1 calling static count: " << Box1.objectCount << endl;
  cout << "Box2 calling static count: " << Box2.objectCount << endl;

  // Print total number of objects after creating object.
  cout << "Final Stage Count: " << Box::getCount() << endl;
  cout << "Final Stage Count: " << Box1.getCount() << endl;

  return 0;
}
