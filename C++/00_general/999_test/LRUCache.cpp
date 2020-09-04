#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {

protected:
  map<int, Node *> mp; // map the key to the node in the linked list
  int cp;              // capacity

  Node *tail; // double linked list tail pointer
  Node *head; // double linked list head pointer

  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache {
public:
  LRUCache(int cp) { this->cp = cp; }
  void set(int k, int val) {
    if (mp.empty()) {
      Node *n = new Node(k, val);
      head = n;
      tail = n;
      mp.insert(make_pair(k, n));
    } else if (!mp.empty()) {

      if (mp.find(k) != mp.end()) { // key exists in the map
        Node *n = mp[k];
        n->value = val;
        if (head != n) {
          Node *nmb, *nma;
          nmb = n->prev;
          nma = n->next;
          nmb->next = nma;
          if (nma != NULL)
            nma->prev = nmb;
          else
            tail = nmb;
          head->prev = n;
          n->next = head;
          head = n;
          head->prev = NULL;
        }
      } else { // key does not exist
        if (mp.size() < cp) {
          Node *n = new Node(NULL, head, k, val);
          head->prev = n;
          head = n;
          mp.insert(make_pair(k, n));
        } else if (mp.size() == cp) {
          Node *nb = tail->prev; // node one before tail
          Node *nt = tail;       // tail node
          mp.erase(tail->key);
          delete nt;
          tail = nb;
          Node *n = new Node(NULL, head, k, val);
          head = n;
          mp.insert(make_pair(k, n));
        }
      }
    }
  }

  int get(int k) {
    if (mp.find(k) != mp.end()) {
      Node *n = mp[k];
      return n->value;
    } else
      return -1;
  }
};

int main() {

  cout << "hello\n";
  ifstream input("input01.txt");

  int n, capacity, i;
  input >> n >> capacity;
  LRUCache l(capacity);

  for (i = 0; i < n; i++) {
    cout << " ============= " << i << "\n";
    string command;
    input >> command;
    if (command == "get") {
      int key;
      input >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      input >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
