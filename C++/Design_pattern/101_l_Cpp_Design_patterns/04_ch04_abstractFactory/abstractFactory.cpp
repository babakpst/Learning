
/// 04_02_AbFacImp_Start.cpp
// Babak Poursartip
// Credit goes to Linkedin course: Design pattern

#include <cstring>
#include <iostream>

// ==========================================
// Door Objects
class Door
{
 public:
  Door() { puts(" ctor for Door class "); }
  virtual void Open() = 0;
};

// ==========================================
class GasCarDoor : public Door
{
 public:
  GasCarDoor() { puts("Making a door for a gas car."); }
  void Open() { puts("click"); }
};

// ==========================================
class ElectricCarDoor : public Door
{
 public:
  ElectricCarDoor() { puts("Making a door for an electric car"); }
  void Open() { puts("shhhhh"); }
};

// ==========================================
// Engine objects
class Engine
{
 protected:
  char _sound[15];

 public:
  Engine()
  {
    strcpy(_sound, "");
    puts(" ctor for Engine class");
  }
  virtual void Run() = 0;
};

// ==========================================
class GasEngine : public Engine
{
 public:
  GasEngine()
  {
    strcpy(_sound, "vroom");
    puts("Making a gas engine.");
  }
  void Run() { puts(_sound); }
};

// ==========================================
class ElectricEngine : public Engine
{
 public:
  ElectricEngine()
  {
    strcpy(_sound, "SHHHH");
    puts("Making an electric engine.");
  }
  void Run() { puts(_sound); }
};

// ==========================================
// Factories
class CarFactory
{
 public:
  virtual Door *createDoor() = 0;
  virtual Engine *createEngine() = 0;
};

// ==========================================
class gasCarFactory : public CarFactory
{
 public:
  Door *createDoor() { return new GasCarDoor; }
  Engine *createEngine() { return new GasEngine; }
};

// ==========================================
class electricCarFactory : public CarFactory
{
 public:
  Door *createDoor() { return new ElectricCarDoor; }
  Engine *createEngine() { return new ElectricEngine; }
};

// ==========================================
int main()
{
  CarFactory *CarPlant;
  int choice;

  puts("Select a car type: ");
  puts("1: Gasoline");
  puts("2: Electric");
  printf("Selection: ");
  std::cin >> choice;
  puts("");

  switch (choice)
  {
    case 1:
      CarPlant = new gasCarFactory;
      break;
    case 2:
      CarPlant = new electricCarFactory;
      break;
    default:
      puts("Invalid number");
      CarPlant = NULL;
      break;
  }

  if (CarPlant != NULL)
  {
    Door *myDoor = CarPlant->createDoor();
    Engine *myEngine = CarPlant->createEngine();

    myDoor->Open();
    myEngine->Run();
  }
}
