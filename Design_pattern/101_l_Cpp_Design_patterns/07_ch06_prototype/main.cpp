
#include <cstring>
#include <iostream>

// abstract animal class
class Animals {
protected:
  char _haircolor[10];
  int _hairLength;
  int _tail;
  int _weight;
  int _height;
  int _age;

  int _intelligence;
  int _stubbornness;
  int _aggressiveness;

public:
  virtual Animals *clone() = 0;

  int setHairColor(const char *color) { strcpy(_haircolor, color); }
  int setHairLength(int Length) { _hairLength = Length; }
  int setTail(int Length) { _tail = Length; }
  int setWeight(int kg) { _weight = kg; }
  int setHeight(int m) { _height = m; }
  int setAge(int age) { _age = age; }
};

// derived sheep class
class sheep : public Animals {
public:
  sheep() {
    _hairLength = 6;
    _intelligence = 6;
    _stubbornness = 6;
    _aggressiveness = 6;
  }
  sheep *clone() { return new sheep(*this); }
  void shearing() { _hairLength -= 2; }
};

// derived cow class
class cow : public Animals {
public:
  cow() {
    _intelligence = 7;
    _stubbornness = 7;
    _aggressiveness = 7;
  }
  cow *clone() { return new cow(*this); }
};

int main() {
  puts(" code starts .... ");

  // an instance of sheep object
  sheep *sheep0 = new sheep;
  sheep0->setHairColor("white");
  sheep0->setTail(5);
  sheep0->setWeight(90);
  sheep0->setHeight(1);
  sheep0->setAge(5);

  // an instance of cow object
  cow *cow0 = new cow;
  cow0->setHairColor("brown");
  cow0->setTail(20);
  cow0->setWeight(710);
  cow0->setHeight(145);
  cow0->setAge(9);

  // use cloning to populate the farm
  Animals *farm[5];

  farm[0] = sheep0->clone();
  farm[1] = cow0->clone();
  // change a cow property
  farm[1]->setWeight(1111);

  // shear a sheep and clone it
  sheep0->shearing();
  farm[2] = sheep0->clone();
  farm[3] = sheep0; // any changes to one of them, changes everything.
  sheep0->shearing();

  puts(" code terminated successfully ... ");
}
