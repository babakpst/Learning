

// Babak Poursartip
// 09/09/2020

// initialization c++98
// Udemy: Advanced c++

//#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//====================================================
int main() {
  // puts(" starts \n"); // error in c++98
  cout << " starts \n";
  cout << "\n1-----\n";

  int val[] = {1, 2, 3, 4, 5};
  int *val2 = new int[5];
  val2[0] = 0;
  val2[1] = 1;
  val2[2] = 2;
  val2[3] = 3;
  val2[4] = 4;

  cout << val[0] << endl;

  // ===================
  cout << "\n2 class initialization-----\n";
  class C {
  public:
    string text;
    int id;
  };

  // initialize a class.
  C c1 = {"hello", 7};

  cout << c1.text << endl;

  // ===================
  cout << "\n3 struct initialization-----\n";
  struct S {
    string text;
    int id;
  };

  // initialize a class.
  C S1 = {"hello struct", 8};

  cout << S1.text << endl;

  // ===================
  cout << "\n4 struct initialization-----\n";
  struct da {
    string text;
    int id;
  } m1 = {"hello new", 17};

  cout << m1.text << endl;

  // initialize a class: warning in 98 but ok in 11
  m1 = {"hello new again", 27};

  cout << m1.text << endl;

  // ===================
  cout << "\n5 struct initialization-----\n";
  // if you do not want to use struct again you do not need to put a name there
  struct {
    string text;
    int id;
  } n1 = {"v1", 117}, n2 = {"v2", 127};

  cout << n1.text << " " << n2.text << endl;

  // ===================
  cout << "\n6 vector initialization with {}-----\n";
  vector<string> str;
  str.push_back("one");
  str.push_back("two");
  str.push_back("three");
  str.push_back("four");
  cout << str[1] << endl;

  // not working in 98, but it is ok in 11.
  // vector<string> str2{"one", "two", "three"};
  // cout << str2[1] << endl;

  cout << "\n ends \n ";

  return 0;
}
