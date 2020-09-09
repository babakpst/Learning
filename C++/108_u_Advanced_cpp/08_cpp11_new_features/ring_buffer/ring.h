
#ifndef RING_H
#define RING_H

#include <iostream>
using namespace std;

template <class T> class ring {
private:
  int m_pos;
  int m_size;
  T *m_values;

public:
  class iterator;

public:
  ring(int size) : m_pos(0), m_size(size), m_values(NULL) {
    m_values = new T[size];
  }
  ~ring() { delete[] m_values; }

  int size() { return m_size; }

  iterator begin() { return iterator(0, *this); }
  iterator end() { return iterator(m_size, *this); }

  void add(T value) {
    m_values[m_pos++] = value;
    if (m_pos == m_size)
      m_pos = 0;
  }

  T &get(int pos) { return m_values[pos]; }
};

// =========================
// This class T here is the same one in the ring class, not a new.
template <class T> class ring<T>::iterator {
private:
  int m_pos;
  ring &m_ring;

public:
  iterator(int pos, ring &r) : m_pos(pos), m_ring(r) {}

  iterator &operator++(int) {
    m_pos++;
    return *this;
  }

  iterator &operator++() {
    m_pos++;
    return *this;
  }

  T &operator*() { return m_ring.get(m_pos); }
  bool operator!=(const iterator &lhs) const { return (m_pos != lhs.m_pos); }

  void print();
};

// =========================
template <class T> void ring<T>::iterator::print() {
  cout << "hello from iterator: " << T() << "\n";
}

#endif // !RING_H
