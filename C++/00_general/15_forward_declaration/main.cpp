

/*

Babak Poursartip

12/23/2021

Forward declaration

*/

#include <iostream>
using namespace std;

// Forward declaration
class A;
class B;

class B {
	int x;

public:
	void getdata(int n)
	{
		x = n;
	}
	friend int sum(A, B);
};

class A {
	int y;

public:
	void getdata(int m)
	{
		y = m;
	}
	friend int sum(A, B);
};
int sum(A m, B n)
{
	int result;
	result = m.y + n.x;
	return result;
}

int main()
{
	B b;
	A a;
	a.getdata(5);
	b.getdata(4);
	cout << "The sum is : " << sum(a, b) << std::endl;
	return 0;
}

