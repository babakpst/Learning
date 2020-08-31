
// Babak Poursartip
// 08/30/2020

// Operator overloading:
// Udemy: Advanced c++

#include <iostream>

// using namespace std;
using std::cout;
using std::endl;
using std::string;

//====================================================
class Person {
private:
  int _id;
  string _name;

public:
  Person() : _id(0), _name("") { cout << "default ctor\n"; }
  Person(int _id, string _name) : _id{_id}, _name{_name} { cout << "ctor\n"; }
  void print() { cout << _name << ": " << _id << endl; }
  void setNames(string name) { _name = name; }

  // copy constructor
  Person(const Person &obj) {
    cout << "copy ctor\n";
    _id = obj._id;
    _name = obj._name;
  }

  // assignment operator (always returns by &)
  // rhs is const, bcs we do not want the change the value on the rhs.
  // rhs is a &, bcs it is more efficienct.
  const Person &operator=(const Person &rhs) {
    cout << " assignment operator\n";
    _id = rhs._id;
    _name = rhs._name;
    return *this;
  }
};

//====================================================
int main() {

  puts(" starts \n");

  cout << "\n1-----\n";
  Person per1(10, "Babak");
  per1.print();

  Person per2(12, "Shiva");
  per2.print();
  cout << " calling assignment operator\n";
  per2 = per1;
  per2.print();

  cout << "\n2-----\n";
  per2.setNames("Behnaz");
  per2.print();
  per1.print();

  cout << "\n3-----\n";
  // The equal operator is nothing but a method call, see next line.
  Person per3;
  per3.operator=(per2);
  per3.print();

  // calls the copy constructor
  cout << "\n4-----\n";
  Person per4 = per1;

  // int x1 = 1, x2 = 2, x3 = 3;
  // x3 = x2 = x1;
  // cout << x1 << " " << x2 << " " << x3 << "\n";
  // per3 = per2 = per1;

  puts(" \n ends");

  return 0;
}
