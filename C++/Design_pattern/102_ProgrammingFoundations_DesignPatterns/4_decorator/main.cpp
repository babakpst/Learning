#include <iostream>
#include <string>

// starbuzz example

// Abstract Beverage class
class Beverage
{
 public:
  virtual std::string getDescription() { return description; }

  virtual double cost() = 0;

 protected:
  std::string description = "Unknown Beverage";
};

// Concrete Beverages
class Espresso : public Beverage
{
 public:
  Espresso() { description = "Espresso"; }

  double cost() override { return 1.99; }
};

class HouseBlend : public Beverage
{
 public:
  HouseBlend() { description = "House Blend Coffee"; }

  double cost() override { return 0.89; }
};

// Abstract Condiment Decorator
class CondimentDecorator : public Beverage
{
 public:
  virtual std::string getDescription() = 0;
};

// Concrete Condiments
class Mocha : public CondimentDecorator
{
 private:
  Beverage* beverage;

 public:
  Mocha(Beverage* beverage) { this->beverage = beverage; }

  std::string getDescription() override { return beverage->getDescription() + ", Mocha"; }

  double cost() override { return 0.20 + beverage->cost(); }
};

class Whip : public CondimentDecorator
{
 private:
  Beverage* beverage;

 public:
  Whip(Beverage* beverage) { this->beverage = beverage; }

  std::string getDescription() override { return beverage->getDescription() + ", Whip"; }

  double cost() override { return 0.10 + beverage->cost(); }
};

int main()
{
  Beverage* beverage = new Espresso();
  std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

  Beverage* beverage2 = new HouseBlend();
  beverage2 = new Mocha(beverage2);
  beverage2 = new Mocha(beverage2);
  beverage2 = new Whip(beverage2);
  std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

  delete beverage;
  delete beverage2;

  return 0;
}
