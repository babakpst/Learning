
// Babak Poursartip
// July 31, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T=int>
void printVec(std::vector<T> vec)
{
  for_each(vec.begin(), vec.end(), [](auto x){std::cout << x << " ";});  
  std::cout << " end of vec. \n";  
}

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
    make_heap(stones.begin(), stones.end());
    //printVec(stones);
    int heap_size = stones.size();
    int s1,s2;
      while(heap_size>1)
      {
        s1=stones.front();
        pop_heap(stones.begin(), stones.begin()+heap_size);
        heap_size--;
        //printVec(stones);
        
        s2=stones.front();
        pop_heap(stones.begin(), stones.begin()+heap_size);
        heap_size--;
        //printVec(stones);

        if (s1!=s2){
          stones[heap_size] =s1-s2;
          //std::cout << " after the new element\n";
          //printVec(stones);
          heap_size++;
          push_heap(stones.begin(), stones.begin()+heap_size);
          //std::cout << " after heapify the new element\n";
          //printVec(stones);
        }
      }

    return heap_size?stones.front():0;

    }
};




int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  //std::vector<int> vec{2,7,4,1,8,1};
  std::vector<int> vec{33,2,2};
  Solution t;
  std::cout << " output: " << t.lastStoneWeight(vec) << std::endl;
  
  std::cout << " done. \n";
  return 0;
}
