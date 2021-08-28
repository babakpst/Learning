
// Babak Poursartip
// 09/26/2020

// destructor

#include <iostream>
#include <memory>
using std::cout;
using std::endl;

// ===========================================
class entity {
public:
  float x, y;
  entity() {
    x = 0.0f;
    y = 0.0f;
    cout << "ctor\n";
  }
  entity(float x, float y) : x{x}, y{y} { cout << "ctor\n"; }
  void print() { cout << x << ", " << y << endl; }

  // destructor:
  ~entity() { cout << "destructor\n"; }
};

// ===========================================
void func() {
  entity e;
  e.print();
}

// ===========================================
// remark: if the base destructor is not virtual, a pointer of type base that points the derived class, will only call the base class destructor, and not the destructor of the derived class, when it is destroyed. But with the virtual base destructor, it calls both the base and the derived destructor.
class base {
public:
  base() { cout << "base ctor\n"; }
  ~base() { cout << "base dtor\n"; } 
  //virtual ~base() { cout << "base dtor\n"; }
};

class derived : public base {
public:
  derived() {
    pArr = new int[5];
    cout << "derived ctor\n";
  }
  ~derived() {
    delete[] pArr;
    cout << "derived dtor\n";
  }

private:
  int *pArr;
};

// ===========================================
int main() {

  cout << " code starts ... \n";
  cout << "1 ====== \n";
  func();

  cout << "2 ====== \n";
  base *b = new base;
  delete b;

  cout << "3 ====== \n";
  derived *d = new derived;
  delete d;

  cout << "4 ====== \n";
  base *poly = new derived;
  delete poly;

  {
  cout << "5 ====== \n";
  std::unique_ptr<base> pb(new derived);
  }
  
  cout << " finished\n";
  return 0;
}
