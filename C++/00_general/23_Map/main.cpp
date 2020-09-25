
// map
// Babak Poursartip

#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>

int main() {

  std::cout << "\n1 -------------------- \n\n";

  // define the map inventory
  std::map<std::string, int> inventory = {{"coffee", 20}, {"tea", 25}};

  std::cout << " The price of "
            << " coffee is: " << inventory["coffee"] << std::endl;

  inventory["food"] = 17;
  std::cout << " The price of "
            << " food is: " << inventory["food"] << std::endl;

  // carful here, mmm will be added to the map, eventhough it is not there
  std::cout << " new is: " << inventory["mmm"] << std::endl;

  // insert in map
  inventory.insert(std::make_pair("Cold Coffee", 50));
  std::cout << "\n Here is the map: \n";
  for (std::map<std::string, int>::iterator it = inventory.begin();
       it != inventory.end(); it++) {
    std::cout << it->first << "  " << it->second << std::endl;
  }

  std::cout << "\n2 -------------------- \n\n";

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

  std::cout << "\n3 -------------------- \n\n";
  // map with comparator
  int lval = 3;

  // std::function<bool(int, int)> ft;
  // ft = [=](int x, int y) { return fabs(lval - x) < fabs(lval - y); };
  // std::map<int, int, std::function<bool(int, int)>> ot(ft);

  // auto ft = [=](int x, int y) { return fabs(lval - x) < fabs(lval - y); };
  auto ft = [=](int x, int y) { return fabs(x) < fabs(y); };
  // auto ft = [=](int x, int y) { return (lval - x) < (lval - y); };
  std::map<int, int, decltype(ft)> ot(ft);

  std::vector<int> aa = {1, -2, 3, 4, 5, 6, 2};
  for (auto c : aa)
    ot.insert(std::make_pair(c, c));
  for (auto c : ot)
    std::cout << c.first << " " << c.second << std::endl;

  return 0;
}
