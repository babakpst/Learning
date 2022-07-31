
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T=int>
void printVec(std::vector<T> vec)
{
  for_each(vec.begin(), vec.end(), [](auto x){std::cout << x << " ";});  
  std::cout << " end of vec. \n";  
}

int main(int argc, char* argv[])
{
  std::cout  << " starts here ... \n";

  // ========================
  std::cout << " 1: heapify a vector of int ================\n";
  // input vector
  std::vector<int> heap_vec{12,5,8,1,78,15,79,14,52,14,5,1,57,25};

  std::cout << " before heapify ... \n";
  printVec(heap_vec);
  
  // heapify
  std::make_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after heapify ... \n";
  printVec(heap_vec);

  // insert new element into the heap
  heap_vec.push_back(80);  // adding new element to the vec,
  push_heap(heap_vec.begin(), heap_vec.end()); // bubble up, this funciton only works on the last element of vec.
  std::cout << " after insertion ... \n";
  printVec(heap_vec);
  
  // getting the max element of the heap, front is a vector function and has nothing to do with heap.
  std::cout << "The max element in the heap is: " <<  heap_vec.front() << std::endl;

  // deleting the max element from the heap, the return is void
  std::pop_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after extracting the max ... \n";
  printVec(heap_vec);

  // sort_heap: sorts a heap vector. The time complexity of sort_heap is less than the regular sort
  std::sort_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after sorting ... \n";
  printVec(heap_vec);
  
  // tests whether a function is a heap or not
  std::cout << " is it a heap vector? "<< std::boolalpha << std::is_heap(heap_vec.begin(), heap_vec.end()) << std::endl;
   
  // ========================
  std::cout << " 2: heap with non-int vector ================\n";
  std::vector<float> float_vec{1.1,2.2,3.0,3.5,5.2,6.4,9.8,10.55,98.54};
  std::cout << " before heapify ... \n";
  printVec(float_vec);

  std::make_heap(float_vec.begin(), float_vec.end());

  std::cout << " after heapify ... \n";
  printVec(float_vec);

  std::cout  << " done. \n";
  return 0;
}