// 01_02_address.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

int main()
{
	int number = 240;		//define an int variable
	int* numPtr ;			//define an integer pointer numPtr (* shows it is a pointer)
	numPtr = &number;		//assign the address to numPtr (& returns the address of a variable)
	cout << "The address of number is: " << numPtr << endl;

  double var2= 15;
  double *pVar;
  pVar = &var2;
	cout << "The address of double number is: " << pVar << endl;

    return 0;
}

