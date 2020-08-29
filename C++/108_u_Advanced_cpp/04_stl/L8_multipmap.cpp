
// Babak Poursartip
// 08/29/2020

// STL
// Udemy: Advanced c++
// multipmap

#include <iostream>
#include <map>
using namespace std;

int main() {
  puts(" starts \n");

  multimap<int, string> ppl;

  ppl.insert(make_pair(38, "Babak"));
  ppl.insert(make_pair(35, "Shiva"));
  ppl.insert(make_pair(39, "Babak"));
  ppl.insert(make_pair(33, "Behnaz"));
  ppl.insert(make_pair(42, "Behrang"));
  ppl.insert(make_pair(38, "Bob"));
  ppl.insert(make_pair(38, "Maryam"));

  for (auto c : ppl)
    cout << c.first << ": " << c.second << endl;

  cout << " -------------------- \n"; // this is not an accurate method to find.
  for (multimap<int, string>::iterator it = ppl.find(38); it != ppl.end(); ++it)
    cout << it->first << ": " << it->second << endl;

  cout << " -------------------- \n";
  pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its =
      ppl.equal_range(38);

  for (multimap<int, string>::iterator it = its.first; it != its.second; ++it)
    cout << it->first << ": " << it->second << endl;

  cout << " -------------------- \n";
  auto its2 = ppl.equal_range(38);

  for (multimap<int, string>::iterator it = its2.first; it != its2.second; ++it)
    cout << it->first << ": " << it->second << endl;

  puts(" \n ends");

  return 0;
}
