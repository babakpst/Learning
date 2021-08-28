// from geeksforgeeks

// 09/25/2020

// override: override specifier ensures that the function is virtual and is overriding a virtual function from a base class with same signature i.e return type and parameters.

// A CPP program without override keyword. Here 
// programmer makes a mistake and it is not caught. 
#include <iostream> 
using namespace std; 

// ===============================
class Base { 
public: 
	// user wants to override this in 
	// the derived class 
	virtual void func1() {cout << "func1 in base" << endl;}
	virtual void func2() {cout << "func2 in base" << endl;}  
}; 


// ===============================
class derived : public Base { 
public: 
	// did a silly mistake by putting 
	// an argument "int a" 
	void func1(int a) {cout << "func1 in derived class" << endl;}

  // This would be an error 
	//void func2(int a) override {cout << "func2 in derived class" << endl;}
	void func2() override {cout << "func2 in derived class" << endl;}  


}; 


// ==================================================
// Driver code 
int main() 
{ 
	Base b; 
	derived d; 

  b.func1();
  d.func1(5);

  b.func2();
  d.func2();

  // ==============
  Base *pb = new derived;
  pb->func1();
  pb->func2();


	cout << "Compiled successfully" << endl; 
	return 0; 
} 

