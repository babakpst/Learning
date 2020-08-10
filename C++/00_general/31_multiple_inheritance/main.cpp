
// Babak Poursartip
// 07/24/2020

// https://www.geeksforgeeks.org/multiple-inheritance-in-c/

#include<iostream> 
// ==============================
class A { 
public: 
  A()  { std::cout << "A's constructor called" << std::endl; } 
}; 
  
class B { 
public: 
  B()  { std::cout << "B's constructor called" << std::endl; } 
}; 
  
class C: public B, public A { // Note the order 
public: 
  C()  { std::cout << "C's constructor called" << std::endl; } 
}; 




// ===========================================
//The diamond problem
//The diamond problem occurs when two superclasses of a class have a common base class. For example, in the following diagram, the TA class gets two copies of all attributes of Person class, this causes ambiguities.
// In the above program, constructor of ‘Person’ is called two times. Destructor of ‘Person’ will also be called two times when object ‘ta1’ is destructed. So object ‘ta1’ has two copies of all members of ‘Person’, this causes ambiguities. 

//The solution to this problem is ‘virtual’ keyword. We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class. For example, consider the following program.

// this is called virtual inheritance.

//            person
//              /  \
//             /   \
//            /    \
//      faculty   student
//           \     /
//            \   /
//             \ /
//             TA


class Person { 
   // Data members of person  
public: 
    Person(int x)  { std::cout << "Person::Person(int ) called" << std::endl;   } 
	Person()	 { std::cout << "Person::Person() called" << std::endl; } // this constructor is needed bcs the TA class, cannot call Person(int x), even though facutly and sutdent both call the constructor of Person. If the point is to call Person, TA should specifically call Person. It is the responsibility of TA to call the grandparent class.
}; 
  

class Faculty : public Person { 
   // data members of Faculty 
public: 
    Faculty(int x):Person(x)   {
    //Faculty(int x) {  
       std::cout<<"Faculty::Faculty(int ) called"<< std::endl; 
    } 
}; 
  
class Student : public Person { 
   // data members of Student 
public: 
    Student(int x):Person(x) {
    //Student(int x) {  
        std::cout<<"Student::Student(int ) called"<< std::endl; 
    } 
}; 
  
class TA : public Faculty, public Student  { 
public: 
    TA(int x):Student(x), Faculty(x)   { 
        std::cout<<"TA::TA(int ) called"<< std::endl; 
    } 
}; 

// ============================
class Faculty2 : virtual public Person { 
public: 
	Faculty2(int x):Person(x) { 
	std::cout<<"Faculty::Faculty(int ) called"<< std::endl; 
	} 
}; 

class Student2 : virtual public Person { 
public: 
	Student2(int x):Person(x) { 
		std::cout<<"Student::Student(int ) called"<< std::endl; 
	} 
}; 

class TA2 : public Faculty2, public Student2 { 
public: 
	//TA2(int x):Student2(x), Faculty2(x) {   // this will call person() constructor.
	TA2(int x):Student2(x), Faculty2(x), Person(x) {  
		std::cout<<"TA2::TA2(int ) called"<< std::endl; 
	} 
}; 


int main() 
{ 
    C c; 
    puts("=======================");
    TA ta1(30); 
    puts("=======================");
    TA2 ta2(40); 
    return 0; 
} 
