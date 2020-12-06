
/*

Babak Poursartip
12/05/2020

source: Effective C++, Meyer

Topic:
item 6: disallow compiler generate functions

If you to have only one copy of a class, i.e., you do not want to allow any obj
copy an obj of particular type, just declare the copy ctor and assignment ctor
in the private section of the class.
To avoid members or friend classes to use the
copy/assignment ctors, just declare the ctors but do not define them.

*/

#include <iostream>

// ===============================
class friendsCopyMe {
private:
  int _ivar = 11;

  friendsCopyMe(const friendsCopyMe &m) : _ivar(m._ivar) {
    std::cout << " copy ctor\n";
  }

  friendsCopyMe &operator=(const friendsCopyMe &m) {
    std::cout << " assignment ctor\n";
    if (this != &m) {
      this->_ivar = m._ivar;
    }
    return *this;
  }

public:
  friend int babak(const friendsCopyMe &m);
  friendsCopyMe() { std::cout << " default ctor \n"; }
  friendsCopyMe(int ivar) : _ivar(ivar) { std::cout << " ctor \n"; }

  int getVar() { return _ivar; }
};

int babak(const friendsCopyMe &m) {
  std::cout << " I am Babak: " << m._ivar << std::endl;
  return m._ivar;
}

// copy me ===============================
class CopyMe {
private:
  int _ivar = 0;

public:
  CopyMe() { std::cout << " default ctor \n"; }
  CopyMe(int ivar) : _ivar(ivar) { std::cout << " ctor \n"; }

  CopyMe(const CopyMe &m) : _ivar(m._ivar) { std::cout << " copy ctor\n"; }
  CopyMe &operator=(const CopyMe &m) {
    std::cout << " assignment ctor\n";
    if (this != &m) {
      this->_ivar = m._ivar;
    }
    return *this;
  }

  int getVar() { return _ivar; }
};

// do not copy me ===============================
class doNotCopyMe {
private:
  int _ivar = 0;

  // copy ctor with no definition in the private section. Copying in not allowed
  // we can even drop the function parameters.
  doNotCopyMe(const doNotCopyMe &);

  // assignment ctor with no definition in the private section. = in not allowed
  // we can even drop the function parameters.
  doNotCopyMe &operator=(const doNotCopyMe &);

public:
  doNotCopyMe() { std::cout << " default ctor \n"; }
  doNotCopyMe(int ivar) : _ivar(ivar) { std::cout << " ctor \n"; }

  int getVar() { return _ivar; }
};

int main() {

  std::cout << " starts ...\n";

  // copy me ===============================
  puts(" ===== 0: copy me =====");
  CopyMe obj0; // calls the default ctor
  std::cout << " obj0 var: " << obj0.getVar() << " \n";

  CopyMe obj1(1); // calls the ctor
  std::cout << " obj1 var: " << obj1.getVar() << " \n";

  CopyMe obj2(obj1); // calls the copy ctor
  std::cout << " obj2 var: " << obj2.getVar() << " \n";

  CopyMe obj3 = obj1; // calls the copy ctor
  std::cout << " obj3 var: " << obj3.getVar() << " \n";

  CopyMe obj4; // calls the default ctor
  std::cout << " obj4 var: " << obj4.getVar() << " \n";

  obj4 = obj1; // calls the assignment operator
  std::cout << " obj4 var: " << obj4.getVar() << " \n";

  // do not copy me ===============================
  puts(" ===== 1: do not copy me =====");
  doNotCopyMe Dobj0; // calls the default ctor
  std::cout << " Dobj0 var: " << Dobj0.getVar() << " \n";

  doNotCopyMe Dobj1(1); // calls the ctor
  std::cout << " Dobj1 var: " << Dobj1.getVar() << " \n";

  // doNotCopyMe Dobj2(Dobj1); // calls the copy ctor: not allowed
  // std::cout << " Dobj2 var: " << Dobj2.getVar() << " \n";

  // doNotCopyMe Dobj3 = Dobj1; // calls the copy ctor: not allowed
  // std::cout << " Dobj3 var: " << Dobj3.getVar() << " \n";

  doNotCopyMe Dobj4; // calls the default ctor
  std::cout << " Dobj4 var: " << Dobj4.getVar() << " \n";

  // Dobj4 = Dobj1; // calls the assignment operator: not allowed
  // std::cout << " Dobj4 var: " << Dobj4.getVar() << " \n";

  // friends ====================================
  puts(" ===== 2: friends=====");
  friendsCopyMe fobj0;
  friendsCopyMe fobj1(112);
  std::cout << " friend class: " << babak(fobj0) << std::endl;
  std::cout << " friend class: " << babak(fobj1) << std::endl;

  std::cout << " finished!\n";

  return 0;
}
