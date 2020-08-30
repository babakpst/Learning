
// Babak Poursartip
// 08/29/2020

// STL complex data type
// Udemy: Advanced c++

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  puts(" starts \n");

  map<string, vector<int>> scores;

  scores["Bob"].push_back(10);
  scores["Bob"].push_back(20);
  scores["Bob"].push_back(10);
  scores["Shiva"].push_back(18);

  for (map<string, vector<int>>::iterator it = scores.begin();
       it != scores.end(); ++it) {
    string name = it->first;
    vector<int> scoreList = it->second;
    cout << name << ": " << flush;
    for (int i = 0; i < scoreList.size(); ++i) {
      cout << scoreList[i] << " " << flush;
    }
    cout << endl;
  }

  puts(" \n ends");

  return 0;
}
