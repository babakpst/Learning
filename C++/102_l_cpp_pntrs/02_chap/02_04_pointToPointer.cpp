// 02_04_pointToPointer.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main()
{
	int num = 10;
	int* pNum = &num;
	int** p2Num = &pNum;

  cout << "address of num:" << &num << endl;
  cout << "address of pnum:" << pNum << endl;
  cout << "address of p2num:" << &pNum << endl;
  cout << "address of p2num:" << p2Num << endl;

  // array of pointers
  int testScores[5]{12,50,85,96,100};
  int * pointerArray[5];
  for (int i = 0; i < 5; ++i){
     pointerArray[i] = &(testScores[i]);
     cout << pointerArray[i] << endl;
     cout << *(pointerArray[i]) << "  "<<*(pointerArray + i)<<"  "<<**(pointerArray + i)<< endl;
  }

    return 0;
}

