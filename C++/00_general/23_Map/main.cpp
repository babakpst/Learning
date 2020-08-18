
// map
// Babak Poursartip

#include <iostream>
#include <map>
#include <string>

int main() {

  // define the map inventory
  std::map<std::string, int> inventory = {{"coffee", 20}, {"tea", 25}};

  std::cout << " The price of "
            << " coffee is: " << inventory["coffee"] << std::endl;

  inventory["food"] = 17;
  std::cout << " The price of "
            << " food is: " << inventory["food"] << std::endl;

  inventory.insert(std::make_pair("Cold Coffee", 50));
  for (std::map<std::string, int>::iterator it = inventory.begin();
       it != inventory.end(); it++) {
    std::cout << it->first << "  " << it->second << std::endl;
  }

  std::cout << "\n -------------------- \n\n";

  // check the output of a map
  std::map<int, int> list;
  int val;
  for (int i = 0; i < 10; ++i) {
    if (i % 2)
      val = 2 * i;
    else
      val = 3 * i - 5;
    list.insert(std::make_pair(val, i));
    std::cout << val << " " << i << "\n";
  }

  std::cout << "\n here is the map \n";

  for (std::map<int, int>::iterator it = list.begin(); it != list.end(); ++it) {
    std::cout << it->first << "  " << it->second << std::endl;
  }

  return 0;
}
