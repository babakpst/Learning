
// simple-inheritance.cpp by Bill Weinman <http://bw.org/>


// my comment: It does not matter where you put the friend statement, in the public or the private section.


#include <iostream>
#include <string>

// Animal class (base) ===================================
class Animal {
  std::string _name;
  std::string _type;
  std::string _sound;

  // private constructor prevents construction of base class
  Animal() {}

  // protected:
  // protected constructor for use by derived classes
  Animal(const std::string &n, const std::string &t, const std::string &s)
      : _name(n), _type(t), _sound(s) {}
  // exposed all the members of the private classes to the derived classes, or
  // even non-derived classes. This is generally not a good idea, bcs it defeats
  // the idea of encapsulation. (Bill says)
  friend class Dog;
  friend class Cat;
  friend class Pig;

  friend const std::string &get_animal_name(const Animal &);

public:
  void speak() const;
  const std::string &name() const { return _name; }
  const std::string &type() const { return _type; }
  const std::string &sound() const { return _sound; }
};

void Animal::speak() const {
  printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal ======================
class Dog : public Animal {
  int _walked;

public:
  Dog(std::string n) : Animal(n, "dog", "woof"), _walked(0){};
  int walk() { return ++_walked; }
  int wl() { return _walked; }
};

// Cat class - derived from Animal  ============================
class Cat : public Animal {
  int _petted;

public:
  Cat(std::string n) : Animal(n, "cat", "meow"), _petted(0){};
  int pet() { return ++_petted; }
};

// Pig class - derived from Animal ==================================
class Pig : public Animal {
  int _fed;

public:
  Pig(std::string n) : Animal(n, "pig", "oink"), _fed(0){};
  int feed() { return ++_fed; }

  std::string la() const { return name() + "-ay"; }
};

const std::string &get_animal_name(const Animal &a) { return a._name; }
const std::string &get_animal_name2(const Animal &a) { return a.name(); }

// ==================================================================
int main() {
  Dog d("Rover");
  Cat c("Fluffy");
  Pig p("Arnold");

  d.speak();
  c.speak();
  p.speak();

  std::cout << "the " << d.type() << " has been walked " << d.walk()
            << " times\n";
  std::cout << "the " << d.type() << " has been walked " << d.walk()
            << " times\n";
  std::cout << "the " << c.type() << " has been petted " << c.pet()
            << " times\n";
  std::cout << "the " << p.type() << " has been fed " << p.feed() << " times\n";

  printf(" the pig also called: %s \n", p.la().c_str());

  Dog d2("Loukas");
  std::cout << " walking: " << d2.wl() << "\n";
  d2.speak();
  std::cout << "the " << d2.type() << " has been walked " << d2.walk()
            << " times\n";

  std::cout << "the " << c.type() << " is named:  " << get_animal_name(c)
            << " \n";
  std::cout << "the " << c.type() << " is named:  " << get_animal_name2(c)
            << " \n";
}
