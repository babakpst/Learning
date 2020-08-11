

// 03_04_FactVar.cpp
// credit goes to linkedin course: design pattern

#include <cstring>
#include <iostream>

// ===============================
class Rock {
protected:
  char _type[15];

public:
  Rock() { puts(" Rock constructor "); }
  char *getType() { return _type; }
};

// ===============================
class Simple : public Rock {
public:
  Simple() {
    strcpy(_type, "Simple");
    puts(" Simple constructor");
  }
};

// ===============================
class Big : public Rock {
public:
  Big() {
    strcpy(_type, "Big");
    puts(" Big constructor");
  }
};

// ===============================
class Metal : public Rock {
public:
  Metal() {
    strcpy(_type, "Metal");
    puts(" Metal constructor");
  }
};

// ===============================
// Abstract Factory
class RockFactory {
public:
  virtual Rock *getRocks() = 0;
  virtual Rock *getRocks(int i) = 0;
};

// ===============================
// Concrete rock factory that returns the correct rock type based on the level
class LevelRockFactory : public RockFactory {
private:
  Rock *_rock;

public:
  Rock *getRocks() { return getRocks(1); }
  Rock *getRocks(int level) {
    switch (level) {
    case 1:
      puts(" levelRockFac 1");
      return new Simple[10];
    case 2:
      puts(" levelRockFac 2");
      return new Big[10];
    case 3:
      puts(" levelRockFac 3");
      return new Metal[10];
    default:
      puts("Invalid Selection");
      return NULL;
    }
  }
};

// ===============================
// Concrete rock factory that returns the correct rock type based on user input
class PracticeRockFactory : public RockFactory {
private:
  Rock *_rock;

public:
  Rock *getRocks() {
    int choice;

    puts("Select type of rock to practice with: ");
    puts("1: Simple rock");
    puts("2: Big rock");
    puts("3: Metal rock");
    printf("Selection: ");
    std::cin >> choice;

    switch (choice) {
    case 1:
      return new Simple;
    case 2:
      return new Big;
    case 3:
      return new Metal;
    default:
      puts("Invalid Selection");
      return NULL;
    }
  }
  Rock *getRocks(int level) { return getRocks(); }
};

// ===============================
// ===============================
// ===============================
int main() {
  // Generate rocks based on level
  LevelRockFactory RockMachine;
  int level = 1;

  puts("\n checkpoint: 000");
  // generate rocks based on the level
  Rock *r = RockMachine.getRocks(level);
  puts("\n checkpoint: 001");

  // Show the type of rocks created for the level
  for (int i = 0; i < 10; i++) {
    printf("The type of rock created is: %s \n", r[i].getType());
  }
  puts("\n checkpoint: 002");
  puts("");

  // Generate rocks based on user input
  PracticeRockFactory RockMaker;

  puts("\n checkpoint: 003");
  Rock *practice = RockMaker.getRocks();
  puts("\n checkpoint: 004");

  // Show the type of rock the user wanted
  printf("\n Player asked for a %s rock\n", practice->getType());
}
