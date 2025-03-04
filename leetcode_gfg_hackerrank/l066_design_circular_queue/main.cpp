
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue
{
 public:
  vector<int> qq;
  vector<int>::iterator head, tail;

  MyCircularQueue(int k) : qq(k, -1)
  {
    head = qq.begin();
    tail = qq.begin() - 1;
  }

  bool enQueue(int value)
  {
    if (tail != qq.begin() - 1 && isFull()) return false;
    tail = nextItr(tail);
    *tail = value;
    return true;
  }

  bool deQueue()
  {
    if (isEmpty()) return false;
    *head = -1;
    head = nextItr(head);
    return true;
  }

  int Front()
  {
    if (isEmpty()) return -1;
    return *head;
  }

  int Rear()
  {
    if (isEmpty()) return -1;
    return *tail;
  }

  bool isEmpty()
  {
    if (*head == -1) return true;
    return false;
  }

  bool isFull()
  {
    if (nextItr(tail) == head && *head != -1) return true;
    return false;
  }

  vector<int>::iterator nextItr(vector<int>::iterator it)
  {
    if (it + 1 == qq.end())
      return qq.begin();
    else
      return (it + 1);
  }

  vector<int>::iterator preItr(vector<int>::iterator it)
  {
    if (it == qq.begin())
      return qq.end();
    else
      return (it - 1);
  }

  void printQueue()
  {
    cout << " here is the queue: ";  // << endl;
    for_each(qq.begin(), qq.end(), [](auto x) { cout << x << " "; });
    cout << endl;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex1:
  MyCircularQueue obj(5);
  obj.printQueue();
  cout << " empty: " << boolalpha << obj.isEmpty() << endl;
  obj.enQueue(5);
  cout << " full: " << boolalpha << obj.isFull() << endl;
  obj.printQueue();
  obj.enQueue(13);
  obj.printQueue();
  obj.enQueue(8);
  obj.printQueue();
  obj.enQueue(2);
  obj.printQueue();
  obj.enQueue(10);
  obj.printQueue();

  cout << " full: " << boolalpha << obj.isFull() << endl;
  obj.deQueue();
  obj.printQueue();
  obj.deQueue();
  obj.printQueue();

  obj.enQueue(23);
  obj.printQueue();
  obj.enQueue(6);
  obj.printQueue();

  cout << " full: " << boolalpha << obj.isFull() << endl;
  obj.deQueue();
  obj.printQueue();
  obj.deQueue();
  obj.printQueue();
  obj.deQueue();
  obj.printQueue();

  obj.deQueue();
  cout << " front: " << obj.Front() << " rear: " << obj.Rear() << endl;
  obj.printQueue();
  obj.deQueue();
  obj.printQueue();
  cout << " empty: " << boolalpha << obj.isEmpty() << endl;
  cout << " full: " << boolalpha << obj.isFull() << endl;

  // obj.deQueue();

  obj.enQueue(23);
  obj.enQueue(23);
  obj.deQueue();
  obj.printQueue();

  cout << " empty: " << boolalpha << obj.isEmpty() << endl;

  std::cout << " done \n";
  return 0;
}
