
// Babak Poursartip
// 08/28/2020

// STL sorting
// Udemy: Advanced c++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
  int _age;
  string _name;

public:
  Person(int _age, string _name) : _age{_age}, _name{_name} {}
  void print() { cout << _name << ": " << _age << endl; }
  // sort by age
  // bool operator<(const Person &rhs)const  { return (_age < rhs._age); }

  // sort alphabetically
  // bool operator<(const Person &rhs) const { return (_name < rhs._name); }

  // sort alphabetically then age
  bool operator<(const Person &rhs) const {
    if (_name != rhs._name)
      return (_name < rhs._name);
    return (_age < rhs._age);
  }

  friend bool comp(const Person &a, const Person &b);
};

// ====================================
bool comp(const Person &a, const Person &b) { return a._name < b._name; };

// ====================================
int main() {
  puts(" starts \n");

  vector<Person> ppl;
  ppl.push_back(Person(39, "Babak"));
  ppl.push_back(Person(38, "Babak"));
  ppl.push_back(Person(35, "Shiva"));
  ppl.push_back(Person(33, "Behnaz"));
  ppl.push_back(Person(42, "Behrang"));

  cout << "1=============\n";
  for (auto c : ppl)
    c.print();

  cout << "2=============\n";
  sort(ppl.begin(), ppl.end(), comp);

  for (auto c : ppl)
    c.print();

  cout << "3=============\n";
  sort(ppl.begin(), ppl.end());

  for (auto c : ppl)
    c.print();

  cout << "4=============\n";
  sort(ppl.begin(), ppl.begin() + 3);

  for (auto c : ppl)
    c.print();

  puts(" \n ends");

  return 0;
}
