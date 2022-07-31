
// heap class

#include "heap.h"
#include <algorithm>

// constructors =================================================================
Heap_Data_Structure::Heap_Data_Structure(int CapSize, bool allowExpansion)
    : Capacity(CapSize), Heap_Size(0), allowExpansion(allowExpansion)  {
  std::cout << " Constructing the heap array! \n";
  Heap_Array.reserve(CapSize);
}

Heap_Data_Structure::Heap_Data_Structure()
    : Capacity(0), Heap_Size(0), allowExpansion(true) {
  std::cout << " Constructing the heap array with zero capacity! \n";
}

// insert a new key in the heap ================================================
void Heap_Data_Structure::InsertKey(int var) {

  if (Heap_Size == Capacity && !allowExpansion) 
  {
    std::cout << " You reached the max capacity of the heap. \n";
      return;
  }
  else // expand the size of the heap
  {
    // First we insert the new element at the end of array
    Heap_Size++;
    if (Heap_Size > Capacity)
    {
      std::cout << " Heap size: " << Heap_Size <<" -Capacity is: "<< Heap_Array.capacity() << " - Expanding the capacity \n";
      Heap_Array.push_back(var);
      Capacity = Heap_Array.capacity();
      std::cout << " New capacity: " << Capacity << std::endl;
    }
    else
      Heap_Array.push_back(var);

    std::cout << " node added: " << var << std::endl;
    
    int i = Heap_Size - 1;
    while (i != 0 && Heap_Array[parent(i)] > Heap_Array[i]) {
      std::swap(Heap_Array[parent(i)], Heap_Array[i]);
      i = parent(i);
    };
  }
}

// finds the parent of a key ===================================================
int Heap_Data_Structure::parent(int i) { return (i - 1) / 2; }

// prints the entire heap in the form of array =================================
void Heap_Data_Structure::PrintHeap() {
  std::cout << "\n Final heap array: \n";
  for_each(Heap_Array.begin(), Heap_Array.end(), [](int x){std::cout << x << " ";} );  
  std::cout << "\n";
}

// extract the min of the heap and heapifies the rest of the heap ==============
int Heap_Data_Structure::extractMin() {
  if (Heap_Size <= 0)
    return INT16_MAX;
  if (Heap_Size == 1) {
    Heap_Size--;
    int temp = Heap_Array[0];
    Heap_Array.clear();
    return temp;
  }

  // If the heap has more than one element, we need to extract the root and bubble
  int root = Heap_Array[0];
  Heap_Array[0] = Heap_Array[Heap_Size - 1];
  Heap_Size--;
  Heap_Array.pop_back();
  MinHeapify(0);

  return root;
}

// heapifying function =========================================================
void Heap_Data_Structure::MinHeapify(int term) {

  // find the smallest number from the root and the two children, if exit. 
  int leftItem = left(term);
  int rightItem = right(term);
  int smallest = term;
  if (leftItem < Heap_Size && Heap_Array[leftItem] < Heap_Array[term])
    smallest = leftItem;
  if (rightItem < Heap_Size && Heap_Array[rightItem] < Heap_Array[smallest])
    smallest = rightItem;

  // swap if the smallest is not the parent, and bubble down. 
  if (smallest != term) {
    std::swap(Heap_Array[term], Heap_Array[smallest]);
    MinHeapify(smallest);
  }
}

// returns the left child ======================================================
int Heap_Data_Structure::left(int term) { return 2 * term + 1; }

// returns the right child =====================================================
int Heap_Data_Structure::right(int term) { return 2 * term + 2; }

// returns the min of the heap =================================================
int Heap_Data_Structure::getMin() { return Heap_Array[0]; }
