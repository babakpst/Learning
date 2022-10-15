
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>


using namespace std;

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
      
      int left = 0, right =10000;
      while(left <= right) 
      {
        int mid = left + (right-left)/2;
        int num = reader.get(mid);
        if ( num == target) return mid;
        else if ( num < target ) left = mid + 1;
        else if ( num > target ) right = mid -1;
      }
      return -1;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  const int reader
  int target
 
  Solution t;

  int out = t.search(reader, target);
  
  cout << " answer: " << out << endl;
  
  std::cout << " done \n";
  return 0;
}