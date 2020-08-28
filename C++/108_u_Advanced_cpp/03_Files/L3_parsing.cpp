

// Babak Poursartip
// 08/28/2020

// Files
// Udemy: Advanced c++

#include <fstream>
#include <iostream>
using namespace std;

int main() {
  puts(" starts \n");

  string fileName = "info.txt";
  ifstream inputFile;
  inputFile.open(fileName);

  if (!inputFile.is_open())
    return 1;

  while (inputFile) {
    string line;
    getline(inputFile, line, ':'); // delimitor
    int population;
    inputFile >> population;

    // inputFile.get(); // to get rid of extra line in the output OR
    inputFile >> ws; // read whatever white space is there. It is in c++11

    if (!inputFile) // to eliminate the repetition of the last line.
      break;
    cout << line << " == " << population << endl;
  }
  puts(" \n ends");

  return 0;
}
