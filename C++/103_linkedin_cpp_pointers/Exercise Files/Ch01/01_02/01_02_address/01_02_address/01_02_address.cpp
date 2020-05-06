// 01_02_address.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int number = 240;		//define an int variable
	int* numPtr ;			//define an integer pointer numPtr
	numPtr = &number;		//assign the address to numPtr
	cout << "The address of number is: " << numPtr << endl;

    return 0;
}

