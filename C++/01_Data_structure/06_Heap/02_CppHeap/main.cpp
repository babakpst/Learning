
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template <typename T = int>
void printVec(std::vector<T> vec)
{
  for_each(vec.begin(), vec.end(), [](auto x) { std::cout << x << " "; });
  std::cout << " end of vec. \n";
}

template <typename T = int>
void printQ(std::queue<T> myQ)
{
  while (!myQ.empty())
  {
    std::cout << myQ.top() << " ";
    myQ.pop();
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[])
{
  std::cout << " starts here ... \n";

  // ========================
  std::cout << " 1: heapify a vector of int ================\n";
  // input vector
  std::vector<int> heap_vec{12, 5, 8, 1, 78, 15, 79, 14, 52, 14, 5, 1, 57, 25};

  std::cout << " before heapify ... \n";
  printVec(heap_vec);

  // heapify
  std::make_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after heapify ... \n";
  printVec(heap_vec);

  // insert new element into the heap
  heap_vec.push_back(80);                       // adding new element to the vec,
  push_heap(heap_vec.begin(), heap_vec.end());  // bubble up, this funciton only works on the last element of vec.
  std::cout << " after insertion ... \n";
  printVec(heap_vec);

  // getting the max element of the heap, front is a vector function and has nothing to do with heap.
  std::cout << "The max element in the heap is: " << heap_vec.front() << std::endl;

  // deleting the max element from the heap, the return is void
  std::pop_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after extracting the max ... \n";
  printVec(heap_vec);

  // make a heap again.
  std::make_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after re-hipifying: \n";
  printVec(heap_vec);

  // sort_heap: sorts a heap vector. The time complexity of sort_heap is less than the regular sort
  std::sort_heap(heap_vec.begin(), heap_vec.end());
  std::cout << " after sorting ... \n";
  printVec(heap_vec);

  // tests whether a function is a heap or not
  std::cout << " is it a heap vector? " << std::boolalpha << std::is_heap(heap_vec.begin(), heap_vec.end())
            << std::endl;

  // ========================
  std::cout << " 2: heap with non-int vector ================\n";
  std::vector<float> float_vec{1.1, 2.2, 3.0, 3.5, 5.2, 6.4, 9.8, 10.55, 98.54};
  std::cout << " before heapify ... \n";
  printVec(float_vec);

  std::make_heap(float_vec.begin(), float_vec.end());

  std::cout << " after heapify ... \n";
  printVec(float_vec);

  std::sort_heap(float_vec.begin(), float_vec.end());

  // ========================
  std::cout << "\n 3: using priority queue instead of heap vector ================\n";
  /*
  There's no difference in terms of performance. std::priority_queue is just an adapter class that wraps the container
  and the very same heap-related function calls into a class. The specification of the std::priority_queue openly states
  that. By building a heap from an exposed std::vector and calling heap-related functions directly, you keep it open to
  the possibility of outside access, potentially damaging the integrity of the heap/queue. std::priority_queue acts as a
  barrier restricting that access to a "canonical" minimum: push(), pop(), top() etc. You can see it as self-discipline
  enforcing measure. Also, by adapting your queue interface to the "canonical" set of operations, you make it uniform
  and interchangeable with other class-based implementations of priority queues that conform to the same external
  specification.
  */

  // max heap
  std::priority_queue<int> pq;
  pq.push(0);
  pq.push(1);
  std::cout << pq.top() << std::endl;
  pq.push(10);
  pq.push(11);
  std::cout << pq.top() << std::endl;

  pq.push(20);
  pq.push(21);
  std::cout << pq.top() << std::endl;

  // creating priority queue from vector
  std::priority_queue<float> pq2(float_vec.begin(), float_vec.end());
  std::cout << pq2.top() << std::endl;

  // creating min heap
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq(heap_vec.begin(), heap_vec.end());
  std::cout << min_pq.top() << std::endl;

  std::cout << " done. \n";
  return 0;
}
