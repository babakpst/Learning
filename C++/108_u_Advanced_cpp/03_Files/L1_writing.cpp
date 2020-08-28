
// Babak Poursartip
// 08/28/2020

// Files
// Udemy: Advanced c++

// We can open one file with two handlers. But it may override the other one.

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  puts(" starts \n");

  string fileName = "file.txt"; // file name

  // ofstream indicates that the file is for output, and you cannot read from it
  // The other option is to use fstream but indicate the type of the file.
  // option 1:
  ofstream outputFile;
  outputFile.open(fileName);

  // option 2:
  fstream outputFile2;
  outputFile2.open(fileName, ios::out);

  if (outputFile.is_open()) {
    outputFile << "Hello Babak" << endl;
    outputFile << 123 << endl;
    outputFile.close();
    // no error, but it does nothing.
    outputFile << 123456789 << endl;

    outputFile2 << "Hello Babak2" << endl;
    outputFile2 << 1235 << endl;
    outputFile2.close();

    // error bcs this is an output file
    // outputFile.open(fileName);
    // char *s;
    // outputFile >> s;

  } else {
    cout << "could not creat the file\n";
  }

  string fileName2 = "../file2.txt"; // file name
  outputFile.open(fileName2);
  outputFile.close();

  puts(" \n ends");

  return 0;
}