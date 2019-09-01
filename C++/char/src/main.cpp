
/*
Babak Poursartip
01 September 2019

*/

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
  delete[] record.name;

  std::cout << " End of the code.\n";

  return 0;
}
