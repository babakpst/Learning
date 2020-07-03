
// simple-inheritance.cpp by Bill Weinman <http://bw.org/>

#include <iostream>
#include <string>

class hair {
  std::string _quality;
  hair(){};

protected:
  hair(const std::string &f) : _quality(f) {}

public:
  const std::string &quality() const { return _quality; }
};

// Animal class (base)
class Animal {
  std::string _name;
  std::string _type;
  std::string _sound;

  // private constructor prevents construction of base class
  Animal() {}

protected:
  // protected constructor for use by derived classes
  Animal(const std::string &n, const std::string &t, const std::string &s)
      : _name(n), _type(t), _sound(s) {}

public:
  void speak() const;
  const std::string &name() const { return _name; }
  const std::string &type() const { return _type; }
  const std::string &sound() const { return _sound; }
};

void Animal::speak() const {
  printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
  int _walked;

public:
  Dog(std::string n) : Animal(n, "dog", "woof"), _walked(0){};
  int walk() { return ++_walked; }
  int wl() { return _walked; }
};

// Cat class - derived from Animal
class Cat : public Animal, public hair {
  int _petted;

public:
  Cat(std::string n) : Animal(n, "cat", "meow"), hair("silky"), _petted(0){};
  int pet() { return ++_petted; }
};

// Pig class - derived from Animal
class Pig : public Animal {
  int _fed;

public:
  Pig(std::string n) : Animal(n, "pig", "oink"), _fed(0){};
  int feed() { return ++_fed; }

  std::string la() const { return name() + "-ay"; }
};

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

  std::cout << "the " << c.type() << " has  " << c.quality() << " hair \n";

  Dog d2("Loukas");
  std::cout << " walking: " << d2.wl() << "\n";
  d2.speak();
  std::cout << "the " << d2.type() << " has been walked " << d2.walk()
            << " times\n";
}
