
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// initialization c++11
// c++11 generalized the uses of {} for initialization.

#include <iostream>
#include <vector>

using namespace std;

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1 initializing variables ---------\n";

  int value{5}; // not possible in c++98, there int value = 5;
  cout << value << endl;

  string text{"babak text"};
  cout << text << endl;

  cout << "\n2 initializing arrays ---------\n";
  int val[]{1, 2, 3, 4};
  cout << val[2] << endl;

  int val2[5]{}; // initialize all 5 elements of val2 to zero
  cout << val2[2] << endl;

  // error: we need to specify the number of element in the array pointer
  // int *pNum = new int[]{1, 3, 5, 8};

  // but if we specify the number of elements here, it is ok.
  int *pNum = new int[4]{1, 3, 5, 8};
  cout << pNum[2] << endl;
  delete pNum;

  cout << "\n3 default initializing ---------\n";
  int iVar{}; // this initializes the variable to its default value which is 0
  cout << iVar << endl;

  string sVar{}; // this initializes sVar to its default string which is empty
  cout << sVar << endl;

  int *pInt{}; // equivalent to int *pInt = nullptr;
  cout << " default pointer initialization: " << pInt << endl;

  cout << "\n4 pointer initializing ---------\n";
  int *pOld = new int;
  *pOld = 10;

  int *pVar{pOld}; // initializing the pointer
  cout << *pVar << endl;

  int *pVar2{&value}; // initializing the pointer
  cout << *pVar2 << endl;

  cout << "\n5 struct/class initializing ---------\n";
  struct {
    int value; // not working = 123;
    string txt;
  } s1{5, "Hi"}, s2{6, "Hi again"};
  cout << s1.txt << endl;

  cout << "\n6 struct/class initializing ---------\n";
  vector<string> str{"one", "two", "three"};
  cout << str[1] << endl;

  cout << " \n ends";

  return 0;
}
