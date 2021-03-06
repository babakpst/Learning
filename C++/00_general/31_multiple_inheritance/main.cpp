
// Babak Poursartip
// 07/24/2020

// https://www.geeksforgeeks.org/multiple-inheritance-in-c/

#include<iostream> 
// ==============================
class A { 
public: 
  int a;
  char b;
  A()  { std::cout << "A's constructor called" << std::endl; } 
}; 
  
class B { 
public: 
  int a;
  int b;
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
  Person(int x){ std::cout << "Person::Person(int ) called" << std::endl;} 
	Person(){ std::cout << "Person::Person() called" << std::endl;} // this constructor is needed bcs the TA class, cannot call Person(int x), even though facutly and sutdent both call the constructor of Person. If the point is to call Person, TA should specifically call Person. It is the responsibility of TA to call the grandparent class.
}; 
  

class Faculty : public Person { 
   // data members of Faculty 
public: 
  Faculty(int x):Person(x){
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
// ======================================================
// ======================================================
// ======================================================
class AA {
private:

public: 
  //void func1(){std::cout << "func1 in AA \n";};
  virtual void func1(void)=0;
};

class BB: public AA{
private:
public:
  void func1(){std::cout << "func1 in BB \n";}
};

class CC: public BB{
private:
public:
  void func1(){std::cout << "func1 in CC \n";}
};


// ======================================================
int main() 
{ 
    puts(" 1 =======================");
    C c; 
    //c.a = 5; ambiguous
    c.B::a = 5;  // ok
    c.A::a = 6;// ok
    
    c.B::b = 5;  // ok
    c.A::b = 'c';// ok

    std::cout << " a in B: " << c.B::a << std::endl;
    std::cout << " a in A: " << c.A::a << std::endl;
    std::cout << " b in B: " << c.B::b << std::endl;
    std::cout << " b in A: " << c.A::b << std::endl;

    puts(" 2 =======================");
    TA ta1(30); 
    puts(" 3 =======================");
    TA2 ta2(40); 

    puts(" 4 =======================");
    //AA a_cls;
    BB b_cls;
    CC c_cls;

    BB *pb_cls = new CC;

    //a_cls.func1();
    b_cls.func1();
    c_cls.func1();

    pb_cls->func1();

    return 0; 
} 


