  

// Babak Poursartip
// 09/08/2020

// Nested class / Inner class
// The nested class is also a member variable of the enclosing class and has the same access rights as the other members. However, the member functions of the enclosing class have no special access to the members of a nested class.


//In C++, unlike (say) Java, an instance of a nested class doesn't intrinsically belong to any instance of the enclosing class.

#include<iostream>
using namespace std;
// =================================
class A {
  private:
    int x;
    class C { 
      int y;    
      void pirnt(){cout << "this is insided the inner class: C\n";}
    };
    //C innerC;
   

  public:
    A(){cout << "A defalt ctor\n";}
    A(int x):x{x}{cout << "A ctor\n";}
    class B {
      private:
        int num;
      public:
        void getdata(int n) {num = n;}
        void putdata() {cout<<"The number is "<<num<< endl;}
        void check(){
          cout << "access private memeber:\n";
          //innerC.y= 15;
          //cout << " innerC value: " << innerC.y << "\n";
          //innerC.print();
        }
 
     };
     B innerB;
};

// ==========================================
class List
{
    public:
        List(): head(nullptr), tail(nullptr) {}
    private:
        class Node
        {
              public:
                  int   data;
                  Node* next;
                  Node* prev;
        };
    private:
        Node*     head;
        Node*     tail;
};

// ===================================================
int main() {
   cout<<"Nested classes in C++"<< endl;
   A :: B obj;
   obj.getdata(9);
   obj.putdata();


   A a;
   a.innerB.getdata(12);
   a.innerB.putdata();
   a.innerB.check();

   // a.innerC.NestedFun(&a); // error innerC is private

   return 0;
}

