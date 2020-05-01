

// Developer: Babak Poursartip

/*

This is based on the Bo Qian STL playlist

*/


#include <iostream>
#include <vector>
#include <algorithm>


bool lsb_less(int x, int y){
  return (x%10)<(y%10);
}


bool lessThan10(int i){
  return (i<10);
}

int main(){

  std::cout << " This is the soring section of STL ..." << std::endl;

  std::vector<int> vec = {9,1,10,2,45,3,90,4,9,5,8};

  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // Sorting
  std::sort(vec.begin(), vec.end());

  std::cout << " Sorting ... " << std::endl;

  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // Sorting with a function
  std::sort(vec.begin(), vec.end(), lsb_less);

  std::cout << " Sorting with lsb_less ... " << std::endl;
  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // Partial sorting ....
  std::vector<int> vec2 = {9, 60, 70, 8,45,87,90,69,69,55,7};

  // top five numbers in the vector if you use the function greater
  std::partial_sort(vec2.begin(), vec2.begin()+5, vec2.end(), std::greater<int>());
  
  std::cout << " Partial sorting ... " << std::endl;
  for (std::vector<int>::iterator itr=vec2.begin(); itr !=vec2.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // bottom five numbers in the vector if you use the function greater
  std::partial_sort(vec2.begin(), vec2.begin()+5, vec2.end());
  
  std::cout << " Partial sorting ... " << std::endl;
  for (std::vector<int>::iterator itr=vec2.begin(); itr !=vec2.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // top five numbers, but not ordered, in the vector if you use the function greater
  std::nth_element(vec2.begin(), vec2.begin()+5, vec2.end(), std::greater<int>());
  
  std::cout << " Partial sorting ... " << std::endl;
  for (std::vector<int>::iterator itr=vec2.begin(); itr !=vec2.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }


  // find numbers less that a specific number, here 10. Then we have two partitiones, neither is sorted.
  std::partition(vec2.begin(), vec2.end(), lessThan10);
  
  std::cout << " Less than a number ... " << std::endl;
  for (std::vector<int>::iterator itr=vec2.begin(); itr !=vec2.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

// find numbers less that a specific number, here 10. It preserve the order of the original order within each partition
  std::stable_partition(vec2.begin(), vec2.end(), lessThan10);
  
  std::cout << " Less than a number ... " << std::endl;
  for (std::vector<int>::iterator itr=vec2.begin(); itr !=vec2.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }


  // HEAP -----------------------------------------------------------------------------------------
  std::make_heap(vec.begin(), vec.end());
  
  std::cout << " Heap ... " << std::endl;
  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  std::pop_heap(vec.begin(), vec.end());
  
  std::cout << " Pop Heap ... " << std::endl;
  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  vec.pop_back();
  
  std::cout << " Pop Heap ... " << std::endl;
  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  // adding one element to the heap
  vec.push_back(100);
  std::push_heap(vec.begin(), vec.end()); // Heapify the last item in vec
  std::cout << " Pop Heap ... " << std::endl;
  for (std::vector<int>::iterator itr=vec.begin(); itr !=vec.end(); ++itr){
    std::cout << " vector " << *itr << std::endl;
  }

  std::cout << " Well done. The end! " << std::endl;
  return 0;
}

