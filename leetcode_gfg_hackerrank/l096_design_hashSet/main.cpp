
// babak poursartip
// Nov 16, 2022

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

/*
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
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class bucket
{
 public:
  list<int> myList;

  bool findKey(int key) { return find(myList.begin(), myList.end(), key) != myList.end(); }

  list<int>::iterator findItem(int key) { return find(myList.begin(), myList.end(), key); }

  void printBucket()
  {
    for_each(begin(myList), end(myList), [](int x) { cout << x << " "; });
    cout << endl;
  }
};

class MyHashSet
{
 public:
  vector<bucket> myH;
  int range;

 public:
  MyHashSet(int range = 769) : range(range)
  {
    cout << " creating the HashSet \n";
    myH.resize(range);
  }

  int hashFunc(int key) { return key % range; }

  void add(int key)
  {
    if (!myH[hashFunc(key)].findKey(key)) myH[hashFunc(key)].myList.push_back(key);
    // mySet.insert(key);
  }

  void remove(int key)
  {
    if (myH[hashFunc(key)].findKey(key)) myH[hashFunc(key)].myList.erase(myH[hashFunc(key)].findItem(key));
    // mySet.erase(key);
  }

  bool contains(int key) { return myH[hashFunc(key)].findKey(key); }

  void printSet()
  {
    cout << " here is the set: " << endl;
    for_each(myH.begin(), myH.end(), [](auto x) {
      if (!x.myList.empty()) x.printBucket();
    });
    cout << " --- \n";
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  // obj->printSet();
  obj->add(2);
  // obj->printSet();
  obj->add(5);
  // obj->printSet();
  obj->add(6);
  // obj->printSet();
  obj->add(770);
  obj->add(771);
  obj->add(770 + 769);
  obj->add(770 + 2 * 769);
  obj->printSet();

  cout << obj->contains(1) << endl;
  cout << obj->contains(3) << endl;
  cout << obj->contains(770) << endl;

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
