
// Babak Poursartip
// 08/29/2020

// STL
// Udemy: Advanced c++

// MAP: IMPORTANT IF YOU WANT TO USE A CLASS AS ONE OBJECT.
// We need to define the default constructor, bcs map construct the obj using
// the default constructor. AND assign objects to that using the assingment
// operator.

// Map is sorted in the order of keys. When we use an obj for the key in a map
// container, we need to define a comparison system, so that the compiler can
// order the pairs. Otherwise this would be an error. < should be defined using
// operator overloading.

// Important: The keys of Map are "const". Thus, any call from the keys should
// be const. (here print)

#include <iostream>
#include <map>
using namespace std;

class Person {
private:
  int _age;
  string _name;

public:
  // constructor
  Person() : _name{""}, _age{0} { cout << "default ctor\n"; };
  Person(string _name, int _age) : _age{_age}, _name{_name} {
    cout << "ctor\n";
  }

  // copy constructor
  Person(const Person &rhs) {
    cout << "copy ctor running\n";
    this->_name = rhs._name;
    this->_age = rhs._age;
  }

  // print should be const, otherwise there is and error. bcs keys are const.
  void print() const { cout << _name << ":" << _age; }

  // operator overloading
  bool operator<(const Person &rhs) const {
    if (_name == rhs._name)
      return _age < rhs._age;

    return _name < rhs._name;
  }
};

//==============================================================================
//==============================================================================
//==============================================================================
int main() {
  puts(" starts \n");

  map<Person, int> ppl;

  // = is the assignment operator. This is just a shallow copy.
  ppl[Person("Babak", 38)] = 0; // assingment operator will be called here.
  ppl[Person("Shiva", 35)] = 1;
  ppl[Person("Shiva", 35)] = 3; // updates the value of the key, no duplicate

  // updates the value of the key, but not the key, bcs it is similar the
  // previous one. However, if we modify the < operator, we can add this key
  // as well.
  ppl[Person("Shiva", 999)] = 999;
  ppl[Person("Behnaz", 33)] = 2;

  cout << " \n writing the map \n";
  for (auto c : ppl) { // this will call the copy ctor anytime we iterate.
    cout << c.second << ": ";
    c.first.print();
    cout << endl;
  }

  puts(" \n ends");

  return 0;
}
