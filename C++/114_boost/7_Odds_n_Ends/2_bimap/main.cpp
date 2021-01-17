
/*

Babak Poursartip
01/16/2021

Reference: Boost
PluralSight

String operations


*/
#include <boost/bimap.hpp>
#include <iostream>

// =======================
// =======================
enum class color { Red, Greed, Blue };

// =======================
// =======================
// we can use a bimap to create a bidirectional relation
typedef boost::bimap<color, std::string> colorMap;

colorMap colorTypes;

void bimap() {
  colorTypes.insert(colorMap::value_type(color::Red, "red"));
  color c = colorTypes.right.at("red");
  std::string s = colorTypes.left.at(color::Red);
}

// =======================
// =======================
int main() {

  std::cout << " starts here ...\n";

  // auto c = color::Red;
  // std::cout << c << std::endl; // this is a compile error, we cannot get Red.

  std::cout << " finished.\n";

  return 0;
}
