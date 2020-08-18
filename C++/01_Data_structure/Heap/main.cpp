// Heap data strucutre + Min heap operations.
// developer: Babak Poursartip

// libraries

// classes
#include "heap.h"

// =============================================================================
// Driver
int main() {

  std::cout << " Starting the Heap code..." << std::endl;

  // Create the heap
  std::cout << " Creating the heap in the main code ... " << std::endl;
  Heap_Data_Structure h(11);

  // Insert a new element in the heap
  std::cout << " Inserting new elements ..." << std::endl;
  h.InsertKey(3);
  h.InsertKey(2);
  h.InsertKey(1);
  h.InsertKey(15);
  h.InsertKey(5);
  h.InsertKey(4);
  h.InsertKey(45);
  h.InsertKey(6);

  h.PrintHeap();

  h.extractMin();

  h.PrintHeap();

  std::cout << " The min element of the heap is: " << h.getMin() << std::endl;

  std::cout << " End of the Heap code." << std::endl;
}