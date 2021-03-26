#include <iostream>
#include <cassert>

// There is no reason to use pure enum. Alwasy use enum class.
// enum has to be an integer: 
// enum is to give a name to certain values. 


enum TrafficLight {
  red, green, yellow
};

enum CarColor {
  black, white, gray, silver,
//  green  // can't have the color green in two enums
};

enum class Pet {
  dog, cat, bird
};

enum class Mammal {
  bear, cougar, coyote, dog
};

//===========
enum class Gender { Male, Female };

//===========
enum  { A, B, C };
//enum  { C, D, E }; C cannot be used.

/*
This is not acceptable too
enum  Babak { D, E, F };
enum  Shiva { D, E, F };
*/

enum  Babak { D=5, E, F };
enum  Shiva { G=5, H=10, I=12 };


int main() {

  std::cout << " \n 1 =======\n";
  // By defining color of type TrafficLight, color can take items only from TrafficLight enum.
  TrafficLight color = TrafficLight::red;
  // TrafficLight color2 = 23; error.
  //TrafficLight color3 = 2; //error.
  CarColor camry = CarColor::silver;

  std::cout << " TrafficLight: " << color << std::endl;

  std::cout << " \n 2 =======\n";
  // the surround scope has been polluted
  int colorNumber = red;
  int myCarsColor = black;

  Pet pet = Pet::dog;
  Mammal mammal = Mammal::dog;

  // these are all errors, as they should be
  // Pet otherPet = Mammal::bear;
  // int petNum = pet;
  // assert(pet == mammal);
  // assert (Pet::dog == Mammal::dog);


  std::cout << " \n 3 =======\n";
  // Creating Gender type variable 
  Gender gender = Gender::Male; 
  
    switch (gender) { 
    case Gender::Male: 
        std::cout << "Gender is Male\n";
        break; 
    case Gender::Female: 
        std::cout << "Gender is Female\n"; 
        break; 
    default: 
        std::cout << "Value can be Male or Female\n";
    } 


  std::cout << " \n 4 =======\n";
  std::cout << " enum w/o name: " << A << std::endl;
  std::cout << " enum w/o name: " << C << std::endl;

  std::cout << " \n 5 =======\n";
  std::cout << " enum Babak: " << D << " " << E << " " << F << " " << std::endl;
  std::cout << " enum Shiva: " << G << " " << H << " " << I << " " << std::endl;

  return 0; 
}

