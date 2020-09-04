#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
  int _age;
  string _name;
  virtual void getdata() = 0;
  virtual void putdata() = 0;
};
class Professor : public Person {
public:
  int publications;
  static int cur_id2;
  int cur_id;
  Professor() {
    cur_id2++;
    cur_id = cur_id2;
  }

  void getdata() { cin >> _name >> _age >> publications; }
  void putdata() {
    cout << _name << " " << _age << " " << publications << " " << cur_id
         << endl;
  }
};

class Student : public Person {
public:
  static int cur_id2;
  int cur_id;

  vector<int> marks;

  Student() {
    marks.resize(6);
    cur_id2++;
    cur_id = cur_id2;
  }
  void getdata() {
    cin >> _name >> _age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >>
        marks[4] >> marks[5];
  }
  void putdata() {
    int sum = 0;
    for (int i = 0; i < 6; i++)
      sum += marks[i];
    cout << _name << " " << _age << " " << sum << " " << cur_id << endl;
  }
};

int Professor::cur_id2 = 0;
int Student::cur_id2 = 0;

int main() {

  int n, val;
  cin >> n; // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;
}
