#include <iostream>
#include <cassert>

// There is no reason to use pure enum. Alwasy use enum class.


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
enum class Gender { Male, 
                  Female };


int main() {
  TrafficLight color = TrafficLight::red;
  CarColor camry = CarColor::silver;

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

// Creating Gender type variable 
    Gender gender = Male; 
  
    switch (gender) { 
    case Male: 
        cout << "Gender is Male"; 
        break; 
    case Female: 
        cout << "Gender is Female"; 
        break; 
    default: 
        cout << "Value can be Male or Female"; 
    } 
    return 0; 



}
