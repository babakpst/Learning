
#include <iostream>

// This is an example of interface with code reusability.

// interface class for FlyBehavior
class FlyBehavior
{
 public:
  virtual void fly() = 0;  // pure virtual function
  virtual ~FlyBehavior() {}
};

class FlyWithWings : public FlyBehavior
{
 public:
  void fly() { std::cout << "I'm flying!!" << std::endl; }
  ~FlyWithWings() {}
};

class FlyNoWay : public FlyBehavior
{
 public:
  void fly() { std::cout << "I can't fly" << std::endl; }
  ~FlyNoWay() {}
};

// interface class for QuackBehavior
class QuackBehavior
{
 public:
  virtual void quack() = 0;  // pure virtual function
  virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior
{
 public:
  void quack() { std::cout << "Quack" << std::endl; }
  ~Quack() {}
};

class Squeak : public QuackBehavior
{
 public:
  void quack() { std::cout << "Squeak" << std::endl; }
  ~Squeak() {}
};

class MuteQuack : public QuackBehavior
{
 public:
  void quack() { std::cout << "<< Silence >>" << std::endl; }
  ~MuteQuack() {}
};

// interface class for Duck
class Duck
{
 private:
  FlyBehavior *flyBehavior = nullptr;      // has-a relationship
  QuackBehavior *quackBehavior = nullptr;  // has-a relationship
 public:
  void performFly() { flyBehavior->fly(); }
  void performQuack() { quackBehavior->quack(); }
  void swim() { std::cout << "All ducks float, even decoys!" << std::endl; }
  void display() { std::cout << "I'm a duck!" << std::endl; }
  void setFlyBehavior(FlyBehavior *fb) { flyBehavior = fb; }
  void setQuackBehavior(QuackBehavior *qb) { quackBehavior = qb; }

  virtual ~Duck()
  {
    std::cout << "deleting flyBehavior and quackBehavior" << std::endl;
    delete flyBehavior;
    delete quackBehavior;
  }
};

class MallardDuck : public Duck
{
 public:
  MallardDuck()
  {
    FlyBehavior *fb = new FlyWithWings();
    QuackBehavior *qb = new Quack();
    setFlyBehavior(fb);
    setQuackBehavior(qb);
  }

  void display() { std::cout << "I'm a real Mallard duck" << std::endl; }

  ~MallardDuck() {}
};

class ModelDuck : public Duck
{
 public:
  ModelDuck()
  {
    FlyBehavior *fb = new FlyNoWay();
    QuackBehavior *qb = new Quack();
    setFlyBehavior(fb);
    setQuackBehavior(qb);
  }

  void display() { std::cout << "I'm a model duck" << std::endl; }

  ~ModelDuck() {}
};

class RubberDuck : public Duck
{
 public:
  RubberDuck()
  {
    FlyBehavior *fb = new FlyNoWay();
    QuackBehavior *qb = new Squeak();
    setFlyBehavior(fb);
    setQuackBehavior(qb);
  }
  void display() { std::cout << "I'm a rubber duck" << std::endl; }
  ~RubberDuck() {}
};

class DecoyDuck : public Duck
{
 public:
  DecoyDuck()
  {
    FlyBehavior *fb = new FlyNoWay();
    QuackBehavior *qb = new MuteQuack();
    setFlyBehavior(fb);
    setQuackBehavior(qb);
  }
  void display() { std::cout << "I'm a decoy duck" << std::endl; }
  ~DecoyDuck() {}
};

int main()
{
  MallardDuck mallard;
  mallard.display();
  mallard.performFly();
  mallard.performQuack();

  ModelDuck model;
  model.display();
  model.performFly();
  model.performFly();

  RubberDuck rubber;
  rubber.display();
  rubber.performQuack();
  rubber.performFly();

  DecoyDuck decoy;
  decoy.display();
  decoy.performQuack();
  decoy.performFly();
}
