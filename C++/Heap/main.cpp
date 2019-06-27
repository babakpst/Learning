

// Heap data strucutre + Min heap operations.
// Babak Poursartip

#include <iostream>

class Heap_Data_Structure{

private:
int* Heap_Array; // pointer to array of elements in heap
int  Capacity;   // max possible size of the min heap
int  Heap_Size;  // current number of elements in the heap

public:
// Constructor
Heap_Data_Structure(int HeapSize);

void InsertKey(int var);
void swap(int* x1, int* x2 );
int  parent(int i);
void PrintHeap();
int extractMin();
void MinHeapify(int term);
int left(int term);
int right(int term);
int getMin();

};

Heap_Data_Structure::Heap_Data_Structure(int CapSize)
{
  std::cout << " Constructing the heap array! "  << std::endl;
  Heap_Size = 0;
  Capacity = CapSize;
  Heap_Array = new int[CapSize];
}


// insert a new key in the heap
void Heap_Data_Structure::InsertKey(int var)
{

  if (Heap_Size == Capacity){
    std::cout << " You reached the max capacity of the heap" << std::endl;
    return;
  }

  // First we insert the new element at the end of array
  Heap_Size++;
  Heap_Array[Heap_Size-1] =  var;


  int i = Heap_Size-1;
  while ( i != 0 && Heap_Array[parent(i)] > Heap_Array[i] )
  {
    swap( &Heap_Array[parent(i)], &Heap_Array[i] );
    i = parent(i);
  };

}


void Heap_Data_Structure::swap(int* x1, int * x2)
{
  int temp = *x1;
  *x1=*x2;
  *x2 = temp;
}

int Heap_Data_Structure::parent(int i)
{
  return (i-1)/2;
}


void Heap_Data_Structure::PrintHeap(){
  std::cout << " Final heap array: " << std::endl;
  for (int i =0; i < Heap_Size; i++) std::cout << " heap: " << Heap_Array[i] << std::endl;
}

int Heap_Data_Structure::extractMin()
{
  if (Heap_Size <= 0) return INT16_MAX;
  if (Heap_Size == 1) {
    Heap_Size--;
    return Heap_Array[0];
  }

  // If the heap has more than one element, we need to extract the root and bubble
  int root = Heap_Array[0];
  Heap_Array[0] = Heap_Array[Heap_Size-1];
  Heap_Size--;
  MinHeapify(0);

  return root;
}


void Heap_Data_Structure::MinHeapify(int term)
{
  int leftItem = left(term);
  int rightItem = right(term);
  int smallest = term; 
  if (leftItem  < Heap_Size &&  Heap_Array[leftItem]  < Heap_Array[term]) smallest = leftItem; 
  if (rightItem < Heap_Size &&  Heap_Array[rightItem] < Heap_Array[smallest]) smallest = rightItem; 
    if (smallest != term) 
    { 
        swap( &Heap_Array[term], &Heap_Array[smallest]); 
        MinHeapify(smallest); 
    } 
}


int Heap_Data_Structure::left(int term)
{
  return 2*term+1;
}

int Heap_Data_Structure::right(int term)
{
  return 2*term+2;
}

int Heap_Data_Structure::getMin() {return Heap_Array[0];}


// Driver
int main()
{

std::cout << " Starting the Heap code..."<< std::endl;

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