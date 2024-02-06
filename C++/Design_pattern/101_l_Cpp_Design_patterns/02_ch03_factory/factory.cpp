
// Babak Poursartip
// 08/11/2020
// source linkedin desing pattern for c++
// This is the factory method: We can decouple the creation of the new object
// from the main code. If I want to add one more coffee, I do not need to touch
// the main code.

#include <cstring>
#include <iostream>
#include <string>

// using namespace std;

// This class is the PRODUCT. ConcreteProduct will inherit from this class.
class Coffee
{
 private:
 protected:
  char _type[15];

 public:
  Coffee() {}
  char *getType() { return _type; }
};

// This class is a concreteProduct from, inherited from the product.
class Espresso : public Coffee
{
 private:
 protected:
 public:
  Espresso() : Coffee()
  {
    strcpy(_type, "Espresso");

    printf("\n The coffee machine is making a cup of Espresso... \n");
    printf(" Grind and brew one scoop of espresso beans... \n");
  }
};

// This class is a concreteProduct from, inherited from the product.
class Cappuccino : public Coffee
{
 private:
 protected:
 public:
  Cappuccino() : Coffee()
  {
    strcpy(_type, "Cappuccino");

    printf("\n The coffee machine is making a cup of Cappuccino... \n");
    printf(" Grind and brew one scoop of espresso beans... \n");
    printf(" Heat and foam milk... \n");
  }
};

// This is the coffee maker factory
class CoffeeMakerFactory
{
 private:
  Coffee *_coffee;

 protected:
 public:
  Coffee *GetCoffee()
  {
    int choice;
    printf(" Select the coffee \n");
    printf("1: Espresso \n");
    printf("2: Cappuccino \n");
    printf("Select: \n");
    std::cin >> choice;

    switch (choice)
    {
      case 1:
        return new Espresso;
      case 2:
        return new Cappuccino;
      default:
        printf("Invalid selection.");
        return NULL;
    }
  }
};

int main()
{
  puts(" Code starts here ....");

  CoffeeMakerFactory coffeeMachine;
  Coffee *cup;
  cup = coffeeMachine.GetCoffee();
  printf(" The requested coffee is: %s \n", cup->getType());

  puts(" Successfully terminated.");
  return 0;
}
