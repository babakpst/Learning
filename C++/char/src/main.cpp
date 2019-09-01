
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

  domain record;

  record.id = 12;
  record.length = 5;
  record.name = new char[record.length];
  record.name[0] = 'B';
  record.name[1] = 'a';
  record.name[2] = 'b';
  record.name[3] = 'a';
  record.name[4] = 'k';

  std::cout << " here is the record: " << record.name << ".\n";

  std::ifstream inputfile("test.txt");

  int recsinfile = 4; // total number of lines in the file
  int lcount = 0;     // counter for line records
  char recbuf;        // holds each character from the line in the file

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
        std::cout << " we reached the 10th char\n";
        lcount++;
        break;
      }
    }
  }

  std::cout << " End of the code.\n";
  delete[] record.name;
  return 0;
}
