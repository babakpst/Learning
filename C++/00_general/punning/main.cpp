

// Babak Poursartip
// 10/04/2020


// type punning
// source: https://www.youtube.com/watch?v=8egZ_5GA9Bc&ab_channel=TheCherno


#include <iostream>

using std::cout;
using std::endl;


// ======================================
/* 
There is no type A on memory, when we initiate an obj from struct A. 
When in initiate obj e of type A (A e;), two consecutive int variable would 
be allocated as follows (assuming int is 4 bytes):
____|____
 x    y

We can refer to this memory by type punning:


*/

struct A{

int x, y;

int *GetPosition(){return &x;}

};

// ======================================
int main(){

  cout << " Hello \n";

  cout << "\n 1 ------------------- \n";
  float fVal = 3.2435;
  int iVal1 = fVal;      // implicit conversion
  int iVal2 = (int)fVal; // explicit conversion

  cout << " float: " << fVal << endl;
  cout << " implicit conversion: " << iVal1 << endl;
  cout << " explicit conversion: " << iVal2 << endl;
  cout << " static cast as int: " << static_cast<int>(fVal) << endl;

  int a = 50;
  // Here we copy the content of a var in double var. Thus the output is not the same.
  // This is what happens: It take the address of a, convert to a double pointer,
  // dereference it, and set in v.
  double v = *(double *) &a;

  cout << " int: " << a << " double: " << v << endl;

  cout << "\n 2 ------------------- \n";

  A e = {3,4};

  int *position = (int *)&e;


  cout << " e: " << e.x << " " << e.y << endl;
  cout << " punning: " << position[0] << " " << position[1] << endl;
  cout << " punning: " << *position << " " << *(position+1) << endl;

  int *position2 = e.GetPosition();
  position2[0] = 12;
  cout << " punning2: " << position2[0] << " " << position2[1] << endl;

  cout << "\n 2 ------------------- \n";
  cout << "insane but working \n";

  //int y = e.y;
  int y = *(int*)( (char *)&e+4 );
  cout << " Here is y: " << y << endl;

return 0;

}

