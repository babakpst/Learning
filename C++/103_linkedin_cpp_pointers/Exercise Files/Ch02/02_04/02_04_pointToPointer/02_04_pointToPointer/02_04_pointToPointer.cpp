// 02_04_pointToPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int num = 10;
	int* pNum = &num;
	int** p2Num = &pNum;

    return 0;
}

