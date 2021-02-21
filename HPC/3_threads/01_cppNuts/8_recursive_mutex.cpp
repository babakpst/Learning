
/*
Babak Poursartip
10/21/2020

recursive_mutex

REMARKS:
0- It is the same as mutex, but same thread can lock one recursive mutex
multiple times.

1- If thread T1 calls lock/try_lock on a recursive_mutex (say m1) first, then m1
is locked by T1. As T1 is running in recursion, T1 can call lock/try_lock any
number of times.

2- If T1 locks m1 10 times, then T1 has to unlock m1 10 times, before m1 is
fully unlocked. Otherwise, no other thread can use m1. In other words, the
recursive_mutex records total number of locks on m1.

3- There is not specific criterion for the number of times that you can lock
recursive_mutex. It depends on stack. If we reach the max capacity of stack and
we still calling lock(), it will return std::system_error OR if we were calling
try_lock() then it will return false.

4- If possible, we need to avoid recursive_mutex, due to the overhead.
5- Recursive_mutex can be used in loops (see the example).

*/

#include <iostream>
#include <mutex>
#include <thread>

// example one: with recursion
std::recursive_mutex m1;
int buffer = 0;

// example 1:
void recursion(char c, int loopFor) {
  if (loopFor < 0)
    return;
  m1.lock();
  std::cout << "id: " << c << " " << buffer++ << std::endl;
  recursion(c, --loopFor);
  m1.unlock();
  std::cout << " unlock by thread: " << c << " loopFor: " << loopFor
            << std::endl;
}

int main() {
  std::thread t1(recursion, '0', 10);
  std::thread t2(recursion, '1', 20);
  t1.join();
  t2.join();

  // example 2:
  for (int i = 0; i < 5; ++i) {
    m1.lock();
    std::cout << " locked " << i << std::endl;
  }
  for (int i = 0; i < 5; ++i) {
    m1.unlock();
    std::cout << " unlocked " << i << std::endl;
  }

  return 0;
}