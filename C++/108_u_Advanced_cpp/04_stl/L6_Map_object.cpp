
// Babak Poursartip
// 08/29/2020

// STL
// Udemy: Advanced c++

// MAP: IMPORTANT IF YOU WANT TO USE A CLASS AS ONE OBJECT.
// We need to define the default constructor, bcs map construct the obj using
// the default constructor. AND assign objects to that using the assingment
// operator.

// Map is sorted in the order of keys.

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

  void print() { cout << _name << ":" << _age << "\n"; }
};

//==============================================================================
//==============================================================================
//==============================================================================
int main() {
  puts(" starts \n");

  map<int, Person> ppl;

  // = is the assignment operator. This is just a shallow copy.
  ppl[0] = Person("Babak", 38); // assingment operator will be called here.
  ppl[1] = Person("Shiva", 35);
  ppl[2] = Person("Behnaz", 33);

  cout << "\ninsert\n";
  ppl.insert(make_pair(55, Person("Bob", 45)));
  ppl.insert(make_pair(56, Person("Reza", 18)));

  cout << " \n writing the map \n";
  for (auto c : ppl) { // this will call the copy ctor anytime we iterate.
    cout << c.first << ": ";
    c.second.print();
  }

  puts(" \n ends");

  return 0;
}
