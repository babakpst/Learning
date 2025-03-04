
// babak poursartip
// Nov 21, 2022

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class bucket
{
 public:
  // list<{int,int}> myList;
  list<pair<int, int>> myList;

  bool findKey(int key)
  {
    return find_if(myList.begin(), myList.end(), [&key](const pair<int, int>& x) { return x.first == key; }) !=
           myList.end();
  }

  list<pair<int, int>>::iterator findItem(int key)
  {
    return find_if(myList.begin(), myList.end(), [&key](const pair<int, int>& x) { return x.first == key; });
  }

  void printBucket()
  {
    for_each(begin(myList), end(myList),
             [](pair<int, int> x) { cout << " (" << x.first << ", " << x.second << ")\n"; });
    cout << endl;
  }
};

class MyHashMap
{
 public:
  vector<bucket> myMap;
  int range;

  MyHashMap(int range = 769) : range(range) { myMap.resize(range); }

  int hashFunc(int key) { return key % range; }

  void put(int key, int value)
  {
    if (myMap[hashFunc(key)].findKey(key))
      myMap[hashFunc(key)].findItem(key)->second = value;
    else
      myMap[hashFunc(key)].myList.push_back({key, value});
  }

  int get(int key) { return myMap[hashFunc(key)].findKey(key) ? myMap[hashFunc(key)].findItem(key)->second : -1; }

  void remove(int key)
  {
    if (myMap[hashFunc(key)].findKey(key)) myMap[hashFunc(key)].myList.erase(myMap[hashFunc(key)].findItem(key));
  }

  void printMap()
  {
    cout << " here is the map: " << endl;
    for_each(myMap.begin(), myMap.end(), [](auto x) {
      if (!x.myList.empty()) x.printBucket();
    });
    cout << " --- \n";
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  MyHashMap* HM = new MyHashMap();
  HM->put(1, 1);  // The map is now [[1,1]]
  HM->printMap();

  HM->put(2, 2);  // The map is now [[1,1], [2,2]]
  HM->printMap();
  cout << " 1: " << HM->get(1) << endl;  // return 1, The map is now [[1,1], [2,2]]
  cout << " 3: " << HM->get(3) << endl;  // return -1, The map is now [[1,1], [2,2]]
  HM->put(2, 1);                         // The map is now [[1,1], [2,1]] (i.e., update the existing value)
  HM->printMap();
  cout << " 2: " << HM->get(2) << endl;  // return 1, The map is now [[1,1], [2,2]]
  // HM->get(2);    // return 1, The map is now [[1,1], [2,1]]
  HM->remove(2);  // remove the mapping for 2, The map is now [[1,1]]
  HM->printMap();
  cout << " 2: " << HM->get(2) << endl;  // return 1, The map is now [[1,1], [2,2]]
  // HM->get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

  std::cout << " done \n";
  return 0;
}
