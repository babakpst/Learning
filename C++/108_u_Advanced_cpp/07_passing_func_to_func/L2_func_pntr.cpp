
// Babak Poursartip
// 08/31/2020

// passing function to function
// Udemy: Advanced c++

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool match(string test) {
  // return test == "two";
  return test.size() == 3;
}

// writing a function to mimic count_if;
int countStrings(vector<string> &texts, bool (*matchs)(string test)) {
  int tally = 0;
  for (int i = 0; i < texts.size(); ++i) {
    if (match(texts[i])) {
      tally++;
    }
  }
  return tally;
}

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  vector<string> texts;
  texts.push_back("one");
  texts.push_back("two");
  texts.push_back("three");
  texts.push_back("two");
  texts.push_back("four");
  texts.push_back("two");
  texts.push_back("three");

  cout << boolalpha << match("oned") << endl;

  cout << count_if(texts.begin(), texts.end(), match) << endl;
  cout << countStrings(texts, match) << endl;

  puts(" \n ends");

  return 0;
}
