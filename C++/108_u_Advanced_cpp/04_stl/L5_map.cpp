//============================================================================
// Name        :
// Author      : John Purcell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Map does not allow for duplicates. But if you try to duplicate, it takes the
// latest value of the key.

// To see if a key is available in a Map, use map.find, AND NOT PRINTING OUT THE
// VALUE OF THE KEY, BECAUSE moment you define the key, by default it set it
// equal to 0. For example, even though Sue is not a key in the map, but
// ages["Sue"] adds Sue to the Map with a value of 0.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

  map<string, int> ages;

  ages["Mike"] = 40;
  ages["Raj"] = 20;
  ages["Vicky"] = 30;

  ages["Mike"] = 70; // overrides the previous Mike. Now it is 70 and not 40

  ages.insert(make_pair("Peter", 100));

  cout << ages["Raj"] << endl;

  // This statement will add [Sue,0] to the Map.
  cout << ages["Sue"] << endl;

  if (ages.find("Vicky") != ages.end()) {
    cout << "Found Vicky" << endl;
  } else {
    cout << "Key not found." << endl;
  }

  for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
    pair<string, int> age = *it;

    cout << age.first << ": " << age.second << endl;
  }

  for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }

  return 0;
}