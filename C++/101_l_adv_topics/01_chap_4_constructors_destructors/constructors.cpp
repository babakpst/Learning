
/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: constructors and destructors
important notes:

implicit op
1- default constructor
2- copy constructor
3- copy operator assignment
4- destructor


c++ provides implicit copy constructor, destructor, and the copy operator.
Rule of three: If you need to define one of the above three constructors, you need to provide all three of them. 


*/

#include <cstdio>
#include <string>

const std::string unk = "unknown";
const std::string clone_prefix = "clone-";

// interface
class Animal {
  std::string _type = "";
  std::string _name = "";
  std::string _sound = "";

public:
  Animal(); // default constructor
  Animal(const std::string &type, const std::string &name,
         const std::string &sound);
  Animal(const Animal &); // copy constructor
  Animal &operator=(const Animal &rhs); // assignment operator
  ~Animal(); // destructor

  void print() const;
};
//==============================================================================
// implementation
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
  puts("default constructor");
};

//=====
Animal::Animal(const std::string &type, const std::string &name,
               const std::string &sound)
    : _type(type), _name(name), _sound(sound) {
  puts("constructor you built with arguments.");
};

//=====
Animal::Animal(const Animal &rhs) {
  puts("copy constructor");
  _type = rhs._type;
  _name = clone_prefix + rhs._name;
  _sound = rhs._sound;
};

//=====
Animal::~Animal() {
  printf(" destructor: %s the %s \n", _name.c_str(), _type.c_str());
};

//=====
void Animal::print() const {
  printf(" %s the %s says %s \n", _name.c_str(), _type.c_str(), _sound.c_str());
}


//=====
Animal &Animal::operator=(const Animal &rhs) {
  puts("copy operator");
  if (this != &rhs) {
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
  }
  return *this;
};

//==============================================================================
int main() {

  printf(" program starts ... \n\n");

  Animal a;
  a.print();

  const Animal b("cat", "fluffy", " meow");
  b.print();

  const Animal c = b;
  c.print();

  a = c;
  a.print();

  printf(" \n program ends! \n");

  return 0;
}
