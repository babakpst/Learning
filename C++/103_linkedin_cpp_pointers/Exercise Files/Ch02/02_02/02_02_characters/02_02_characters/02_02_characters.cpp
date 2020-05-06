// 02_02_characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{    
	char initial = 'P';
	char* pInitial = &initial;
	cout << "Memory address for initial P: " << pInitial<<endl;
	//cout << "Memory address for initial P: " << static_cast <void *>(pInitial) << endl;
	/*
	const char* pans1{ "Absolutely yes" };
	const char* pans2{ "Absolutely no" };
	const char* pans3{ "The oracle is out, please try again later" };
	const char* pans4{ "Outlook is good" };
	const char* pans5{ "Today is your lucky day, yes" };
	const char* pans6{ "Try again tomorrow" };
	const char* pans7{ "Most certainly" };
	const char* pans8{ "The answer is unclear" };
	const char* pans{ "The oracle says... " };
	int choice{};

	cout << "Think of a yes/no question, then ask the oracle" << endl;
	cout << "Enter a number between 1 and 8: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << pans << pans1 << endl;
		break;
	case 2:
		cout << pans << pans2 << endl;
		break;
	case 3:
		cout << pans << pans3 << endl;
		break;
	case 4:
		cout << pans << pans4 << endl;
		break;
	case 5:
		cout << pans << pans5 << endl;
		break;
	case 6:
		cout << pans << pans6 << endl;
		break;
	case 7:
		cout << pans << pans7 << endl;
		break;
	case 8:
		cout << pans << pans8 << endl;
		break;
	default:
		cout << "Sorry, you didn't choose a number between 1 and 8." << endl;
	}
	*/
    return 0;
}

