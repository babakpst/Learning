
#ifndef RING_H
#define RING_H

#include <iostream>
using namespace std;

template <class T> class ring {
public:
  /*
  instead of defining class in this class, we can only define the the class type
  here and define the class itself outside, just for aesthetic reasons.
  class iterator {
    public:
    void print() { cout << "hello from iterator\n"; }
  };
  */
  class iterator;
};

// This class T here is the same one in the ring class, not a new.
template <class T> class ring<T>::iterator {
public:
  void print();
};

template <class T> void ring<T>::iterator::print() {
  cout << "hello from iterator: " << T() << "\n";
}

#endif // !RING_H
