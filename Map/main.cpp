
// map
// Babak Poursartip

#include <iostream>
#include <map>
#include <string>



int main () {

// define the map inventory
std::map<std::string, int> inventory = {{"coffee",20},  {"tea", 25} };

std::cout << " The price of " << " coffee is: " << inventory["coffee"] << std::endl;

inventory["food"]=17;
std::cout << " The price of " << " food is: " << inventory["food"] << std::endl;

  return 0;
}

