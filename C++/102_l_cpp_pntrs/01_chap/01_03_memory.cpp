// 01_03 memory.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

int main()
{
	cout << "Size of boolean: " << sizeof(bool) << endl;  // 1
	cout << "Size of char: " << sizeof(char) << endl;     // 1
	cout << "Size of int: " << sizeof(int) << endl;       // 4
	cout << "Size of float: " << sizeof(float) << endl;   // 4
	cout << "Size of long: " << sizeof(long) << endl;     // 8
	cout << "Size of double: " << sizeof(double) << endl; // 8

	bool* pBool;
	char* pChar;
	int* pInt;
	cout << "Size of boolean ptr: " << sizeof(pBool) << endl;  // 8
	cout << "Size of char ptr: " << sizeof(pChar) << endl;  // 8
	cout << "Size of int ptr: " << sizeof(pInt) << endl;  // 8


    return 0;
}

