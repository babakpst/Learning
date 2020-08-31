
// Babak Poursartip
// 08/30/2020

// left shift overload
// Udemy: Advanced c++

#include <iostream>

// using namespace std;
using std::cout;
using std::endl;
using std::ostream;
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

  // w/o const there would be a compile error. Bcs the obj is const.
  int getID() const { return _id; }
  string getNAME() const { return _name; }

  // left bit shift operator has left right associativity
  // When we write cout << per1, indeed, cout goes to ostream &o, and per1 goes
  // to rhs.
  /*
  friend ostream &operator<<(ostream &o, const Person &rhs) {
    return (o << rhs._name << ": " << rhs._id);
    // return (o << rhs.getNAME() << ": " << rhs.getID());
  }*/
};

ostream &operator<<(ostream &o, const Person &rhs) {
  return (o << rhs.getNAME() << ": " << rhs.getID());
}

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  Person per1(10, "Babak");
  Person per2(20, "Shiva");
  // per1.print();

  cout << per1 << endl;
  // Having two objs right after each other is also correct, bcs the output of
  // the << overload is of type ostream.
  cout << per1 << per2 << endl;
  cout << per1 << " " << per2 << endl;

  puts(" \n ends");

  return 0;
}
