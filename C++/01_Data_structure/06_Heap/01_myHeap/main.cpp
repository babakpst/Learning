// Heap data strucutre + Min heap operations.
// developer: Babak Poursartip

// libraries

// classes
#include "heap.h"

// =============================================================================
// Driver
int main() {

  std::cout << " Starting the Heap code..." << std::endl;

  // Example 1: Create the heap
  std::cout << "---\n Example 1: Creating a heap structure ... " << std::endl;
  Heap_Data_Structure heapEx1(11);

  // Insert a new element in the heap
  std::cout << " Inserting new elements ..." << std::endl;
  heapEx1.InsertKey(3);
  heapEx1.InsertKey(2);
  heapEx1.InsertKey(1);
  heapEx1.InsertKey(15);
  heapEx1.InsertKey(5);
  heapEx1.InsertKey(4);
  heapEx1.InsertKey(45);
  heapEx1.InsertKey(6);

  heapEx1.PrintHeap();

  heapEx1.extractMin();

  heapEx1.PrintHeap();

  std::cout << " The min element of the heap is: " << heapEx1.getMin() << std::endl;


  // Example 2: Create the heap
  std::cout << "---\n Example 2: Creating an empty heap ...  " << std::endl;
  Heap_Data_Structure heapEx2;
  heapEx2.InsertKey(10);
  heapEx2.InsertKey(8);
  heapEx2.InsertKey(7);
  heapEx2.InsertKey(12);
  heapEx2.InsertKey(1);
  heapEx2.InsertKey(6);
  heapEx2.InsertKey(10);
  heapEx2.InsertKey(9);
  heapEx2.InsertKey(9);

  heapEx2.PrintHeap();
  heapEx2.extractMin();
  heapEx2.PrintHeap();

  // Example 3: Create the heap
  std::cout << "---\n Example 3: Creating another empty heap ...  " << std::endl;
  Heap_Data_Structure heapEx3;
  heapEx3.InsertKey(10);
  heapEx3.PrintHeap();
  heapEx3.extractMin();
  heapEx3.PrintHeap();

  std::cout << " End of the Heap code." << std::endl;
}