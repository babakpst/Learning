
// Babak Poursartip
// 08/28/2020

// STL
// Udemy: Advanced c++

#include <iostream>
#include <vector>
using namespace std;

int main() {
  puts(" starts \n");

  vector<string> strings(5); // preallocate
  strings[0] = "shiva";
  strings[1] = "behnaz";
  strings[3] = "babak";
  cout << strings[3] << endl;

  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");

  cout << strings.size() << endl;
  // iterate through the vector
  puts(" iterate through the vector ");

  for (int i = 0; i < strings.size(); ++i)
    cout << i << " " << strings[i] << "\n";

  vector<string>::iterator it = strings.begin();
  cout << *it << endl;
  ++it;
  cout << *it << endl;
  it += 2;
  cout << *it << endl;

  int index; // location of iteration
  for (vector<string>::iterator itr = strings.begin(); itr != strings.end();
       ++itr) {
    index = itr - strings.begin();
    cout << index << " " << *itr << endl;
  }

  puts("\n loop =========");
  for (auto c : strings)
    cout << c << endl;

  puts(" \n ends");

  return 0;
}
