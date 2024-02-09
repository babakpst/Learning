#include <iostream>

// Duck interface
class Duck
{
 public:
  virtual void quack() = 0;
  virtual void fly() = 0;
};

// Concrete Duck class
class MallardDuck : public Duck
{
 public:
  void quack() override { std::cout << "Quack!" << std::endl; }

  void fly() override { std::cout << "I'm flying" << std::endl; }
};

// Turkey interface/adaptee
class Turkey
{
 public:
  virtual void gobble() = 0;
  virtual void fly() = 0;
};

// Concrete Turkey class
class WildTurkey : public Turkey
{
 public:
  void gobble() override { std::cout << "Gobble gobble!" << std::endl; }

  void fly() override { std::cout << "I'm flying a short distance" << std::endl; }
};

// Adapter class
class TurkeyAdapter : public Duck
{
 private:
  Turkey* turkey;

 public:
  TurkeyAdapter(Turkey* turkey) : turkey(turkey) {}

  void quack() override { turkey->gobble(); }

  void fly() override
  {
    for (int i = 0; i < 5; i++)
    {
      turkey->fly();
    }
  }
};

int main()
{
  MallardDuck duck;
  WildTurkey turkey;
  Duck* turkeyAdapter = new TurkeyAdapter(&turkey);

  // Test the Duck
  duck.quack();
  duck.fly();

  // Test the TurkeyAdapter
  std::cout << "\n turekyAdapter says..." << std::endl;
  turkeyAdapter->quack();
  turkeyAdapter->fly();

  delete turkeyAdapter;

  return 0;
}
