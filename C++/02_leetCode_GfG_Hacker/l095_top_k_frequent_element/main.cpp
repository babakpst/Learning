
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      using mtype = pair<int,int>;
      map<int,int> freq;
      
      for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
      {
        if (freq.find(*it) == freq.end() ) 
          freq[*it] = 1;
        else
          freq[*it] =freq[*it]+1;
      }

      vector<int> out(k,INT_MIN);
      for (int i = 0; i<k; i++)
      {
        int max = freq.begin()->first;
        for ( auto it = freq.begin(); it != freq.end(); it++ )
        {
          // cout << k << " -  " <<  it->first << " " << it->second << endl;
          if ( it->second > freq[max] ) 
            max = it->first;        
        }
        out[i] = max;
        freq.erase(max);
      }     
      return out;
    }
};
*/

struct compare
{
  bool operator()(pair<int,int> a,pair<int,int> b) const {return a.second<b.second; }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      using mtype = pair<int,int>;
      map<int,int> freq;
      
      for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        freq[*it] +=1;


      vector<pair<int,int>> myHeap(freq.size());
      {
      int i = 0;
      for ( auto it = freq.begin(); it != freq.end(); it++, i++ )
        myHeap[i] = make_pair(it->first, it->second);
      }

      // cout << " output before heapify \n";
      // for_each( myHeap.begin(), myHeap.end(), [](auto x){std::cout << x.first << " " << x.second << std::endl;} );      
      // cout << " =========== \n";

      make_heap(myHeap.begin(), myHeap.end(), compare());
      // cout << " output after heapify \n";
      // for_each( myHeap.begin(), myHeap.end(), [](auto x){std::cout << x.first << " " << x.second << std::endl;} );      
      // cout << " =========== \n";


      auto end = myHeap.end();
      for (int i = 0; i<k; i++)
      {
        std::pop_heap(myHeap.begin(), end, compare());
        end--;

        // cout << " output after heapify \n";
        // for_each( myHeap.begin(), myHeap.end(), [](auto x){std::cout << x.first << " " << x.second << std::endl;} );      
        // cout << " =========== \n";

      }
      
      vector<int> out(k,INT_MIN);
      for (int i = 0; i<k; i++, end++)
        out[i] = end->first;

      return out;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{1,1,1,2,2,3};
  // int k = 2;
 
  // vector<int> nums{1};
  // int k = 1;

  // vector<int> nums{0,1,1,1,2,2,3};
  // vector<int> nums{-1,0,1,1,1,1,2,3,3};
  // vector<int> nums{-1,0,2,3,3,1,1,1,1};
  // int k = 2;

  vector<int> nums{4,1,-1,2,-1,2,3};
  int k = 2;





  Solution t;

  vector<int> out = t.topKFrequent(nums, k);  
  
  cout << " answer: "<< endl;
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl;
  
  std::cout << " done \n";
  return 0;
}