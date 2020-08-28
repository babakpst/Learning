
// Babak Poursartip
// 08/28/2020

// Files: Reading and writing in binary files.
// Udemy: Advanced c++

#include <fstream>
#include <iostream>
using namespace std;

// ========================================================================
#pragma pack(push, 1) // align the following with the boundary of one byte.

struct Person {
  char name[50];
  // string name; // we cannot use string in struct bcs it is a pointer.
  int age;
  double weight;
};

#pragma pack(pop) // terminate the effects of pack.

int main() {
  puts(" starts \n");
  // initialize struct
  Person someone = {"Babak", 38, 175.5};

  // bin, bcs it is a binary file- This cannot be viewed
  string fileName = "output.bin";

  // writing binary file ======================
  puts(" writing ===========");
  fstream outputFile;
  outputFile.open(fileName, ios::binary | ios::out); // | combines the two flags
  if (outputFile.is_open()) {

    // write only accepts the char pointer, so we need to cast it.
    outputFile.write((char *)&someone,
                     sizeof(Person)); // we need the address of object

    outputFile.write(reinterpret_cast<char *>(&someone),
                     sizeof(Person)); // we need the address of object

    outputFile.close();
  } else
    cout << " could not open the file:" + fileName;

  // reading binary file ======================
  puts(" reading ===========");
  Person someoneElse = {"", 0, 0.0};
  fstream inputFile;
  inputFile.open(fileName, ios::binary | ios::in); // | combines the two flags
  if (inputFile.is_open()) {

    inputFile.read(reinterpret_cast<char *>(&someoneElse),
                   sizeof(Person)); // we need the address of object
    inputFile.close();
  } else
    cout << " could not open the file:" + fileName;

  cout << someoneElse.name << "," << someoneElse.age << ","
       << someoneElse.weight << endl;

  puts(" \n ends");

  return 0;
}
