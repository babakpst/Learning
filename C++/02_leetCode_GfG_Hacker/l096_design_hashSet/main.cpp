
// babak poursartip
// Nov 16, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class MyHashSet {
public:
    set<int> mySet;    
    MyHashSet() {}
    
    void add(int key) {
      mySet.insert(key);
    }
    
    void remove(int key) {
        mySet.erase(key);
    }
    
    bool contains(int key) {
        return mySet.find(key) != mySet.end();
    }

    void printSet()
    {
      cout << " here is the set: " << endl;
      for_each(mySet.begin(), mySet.end(), [](auto x){cout << x << " ";});
      cout << endl;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  obj->printSet();
  obj->add(2);
  obj->printSet();
  
  cout << obj->contains(1) << endl;
  cout << obj->contains(3) << endl;
  
  obj->add(2);
  obj->printSet();
  cout << obj->contains(2) << endl;

  obj->remove(2);
  obj->printSet();
  cout << obj->contains(2) << endl;

  
 

// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[],           [1],   [2],      [1],       [3],      [2],      [2],      [2],       [2]]



  std::cout << " done \n";
  return 0;
}