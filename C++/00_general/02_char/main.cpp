
/*
Babak Poursartip
01 September 2019

*/

#include <fstream>
#include <iostream>

struct domain {
  int id;
  int length;
  char *name;
};

int main() {

  std::cout << " the code starts ...\n";

  int recsinfile; // total number of lines in the file
  int recordLength = 12;

  recsinfile = 4;
  domain record[4];

  for (int i = 0; i < recsinfile; i++) {
    record[i].name = new char[recordLength];
  }

  record[0].id = 12;
  record[0].length = 5;

  record[0].name[0] = 'B';
  record[0].name[1] = 'a';
  record[0].name[2] = 'b';
  record[0].name[3] = 'a';
  record[0].name[4] = 'k';

  std::cout << " here is the record: " << record[0].name << ".\n";

  // ==================================
  std::ifstream inputfile("test.txt");

  int lcount = 0; // counter for line records
  char recbuf;    // holds each character from the line in the file

  int mycounter = -1;

  while (lcount < recsinfile) {
    int ll = 0;
    mycounter++;
    std::cout << " a new record: " << lcount << " " << mycounter << "\n";
    while (inputfile.get(recbuf)) { // reads the entire record char by char
      ll++;
      std::cout << " the latest char read: " << recbuf << " -\n";
      if (recbuf == 10) { // this is an indication of the end of the line which
                          // is equivalent to if (recbuf == '\n') {
        lcount++;
        break;
      }
    }
  }

  std::cout << " End of the code.\n";

  for (int i = 0; i < recsinfile; i++) {
    delete[] record[i].name;
  }

  return 0;
}
