// 03_04_newAndDelete.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;


int main()
{

  int *pointer(new int(55));
  cout << *pointer << endl;
  delete pointer;

  int *pArray(new int[5]{1,2,3,4,5});
  *(pArray+1) += 5;
  cout << *pArray << " " << *(pArray+1) << endl;
  pArray[1] += 5;
  cout << *pArray << " " << *(pArray+1) << endl;
  delete pArray;

return 0;
}

