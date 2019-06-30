

// libraries
#include <iostream>
#include <vector>

// classes

#ifndef HEAP_H
#define HEAP_H

//==============================================================================
// defining the heap class  ====================================================
class Heap_Data_Structure {

  // -- members
private:
  std::vector<int> Heap_Array; // pointer to array of elements in heap
  int Capacity;                // max possible size of the min heap
  int Heap_Size;               // current number of elements in the heap
public:
  // -- methods
private:
public:
  // Constructor
  Heap_Data_Structure(int HeapSize);

  // required functions to form the heap data structure
  void InsertKey(int var);     // inserts a new element and heapify
  void swap(int *x1, int *x2); // swaping two keys in the heap used for bubbling
  void PrintHeap();            // prints the entire heap
  void MinHeapify(int term);   // heapifying function

  int extractMin();    // extract the mininum key in the heap
  int left(int term);  // returns the left child
  int right(int term); // returns the right child
  int getMin();
  int parent(int i); // finds the parent of a key
};
#endif // !HEAP_H