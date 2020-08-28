

// Babak Poursartip
// 08/28/2020

// Files
// Udemy: Advanced c++

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  puts(" starts \n");
  string fileName = "inputFile.txt";

  // ifstream is used to open a file only for reading purposes.
  // We can do it in two ways.
  // option 1:
  ifstream inputFile;
  inputFile.open(fileName);

  // option 2:
  fstream inputFile2;
  inputFile2.open(fileName, ios::in);

  if (inputFile.is_open()) {
    string line;

    // this or next line
    //  while (!inputFile.eof()) {
    while (inputFile) {
      // reads the entire line. One can use delimitor ':', using single quote
      getline(inputFile, line); // you can add delimitor
      // inputFile >> line; // only reads until the firs space
      cout << line << endl;
    }

  } else
    cout << " could not open the file for read \n";

  puts(" \n ends");

  return 0;
}
