
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node
{
  int key, value;
  node *next, *prev;
  node() : key{0}, value{0}, next{nullptr}, prev{nullptr} {}
  node(int key, int value) : key{key}, value{value}, next{nullptr}, prev{nullptr} {}
  node(int key, int value, node* prev, node* next) : key{key}, value{value}, next{next}, prev{prev}
  {
  }
};

class LRUCache
{
 private:
  unordered_map<int, node*> cache;
  int cap = 0;
  int size = 0;
  node* head = new node(-1, -1);
  node* tail = new node(-1, -1);

 public:
  LRUCache(int capacity) : cap{capacity}
  {
    head->next = tail;
    tail->prev = head;
  }

  int get(int key)
  {
    // cout<< "get====" << key << endl;

    int out = -1;
    if (cache.find(key) != end(cache))
    {
      out = cache[key]->value;
      // cout << " inside get: " << out << endl;
      reorder(key);
      // printList();
    }
    return out;
  }

  void put(int key, int value)
  {
    // cout<< "put==== "<< key << endl;
    if (cache.empty())  // cache is empty
    {
      node* tmp = new node(key, value, head, tail);
      head->next = tmp;
      tail->prev = tmp;
      cache[key] = tmp;
      size++;
    }
    else if (cache.find(key) != end(cache))  // key already exists
    {
      cache[key]->value = value;
      reorder(key);
    }
    else if (cache.find(key) == end(cache))  // key does not exist and cache is not full
    {
      cache[key] = new node(key, value, head, head->next);
      head->next->prev = cache[key];
      head->next = cache[key];
      if (size == cap)
      {
        node* tmp = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        cache.erase(tmp->key);
        delete tmp;
      }
      else
        ++size;
    }
    // printList();
  }

  void reorder(int key)
  {
    if (cache[key]->prev)
    {
      cache[key]->prev->next = cache[key]->next;
      cache[key]->next->prev = cache[key]->prev;

      cache[key]->prev = head;
      cache[key]->next = head->next;
      head->next->prev = cache[key];
      head->next = cache[key];
    }
  }

  void printList()
  {
    cout << "\n list forward: \n";
    node* cur = head;
    while (cur)
    {
      cout << cur->value << " ";
      cur = cur->next;
    }
    cout << endl;

    cout << "\n list backward: \n";
    cur = tail;
    while (cur)
    {
      cout << cur->value << " ";
      cur = cur->prev;
    }
    cout << endl;
  }
};

// int main() {

//   cout << "hello\n";
//   ifstream input("input01.txt");

//   int n, capacity;
//   input >> n >> capacity;
//   LRUCache l(capacity);

//   for (int i = 0; i < n; i++) {
//     cout << " ============= " << i << "\n";
//     string command;
//     input >> command;
//     if (command == "get") {
//       int key;
//       input >> key;
//       cout << l.get(key) << endl;
//     } else if (command == "set") {
//       int key, value;
//       input >> key >> value;
//       l.put(key, value);
//     }
//   }
//   return 0;
// }

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  LRUCache lru(2);

  lru.put(1, 1);  // cache is {1=1}
  lru.put(2, 2);  // cache is {1=1, 2=2}

  cout << "get: " << lru.get(1) << endl;  // return 1

  lru.put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}

  cout << "get: " << lru.get(2) << endl;  // returns -1 (not found)
  lru.put(4, 4);                          // LRU key was 1, evicts key 1, cache is {4=4, 3=3}

  cout << "get: " << lru.get(1) << endl;  // return -1 (not found)
  cout << "get: " << lru.get(3) << endl;  // return 3
  cout << "get: " << lru.get(4) << endl;  // return 4

  std::cout << " done \n";
  return 0;
}
