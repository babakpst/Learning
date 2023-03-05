
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:

    vector<pair<int,int>> myst;
    MinStack() {
        
    }
    
    void push(int val) {
      
      if (myst.empty()) myst.push_back({val,val});
      else myst.push_back({val,min(val,myst[myst.size()-1].second)});
    }
    
    void pop() {
      if (!myst.empty()) myst.pop_back();
    }
    
    int top() {
      return myst.back().first;  
    }
    
    int getMin() {
      return myst[myst.size()-1].second;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  MinStack* obj = new MinStack();
  
  obj->push(8);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
 
  // cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}