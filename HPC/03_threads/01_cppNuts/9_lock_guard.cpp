
/*

Babak Poursartip
10/23/2020

lock_guard

syntac: std::lock_guard<mutex> lock(m1);

REMARKS:
1- It is a light weight wrapper for owning mutex on scoped basis.
2- It acquires the mutex lock the moment you create the object of lock_guard();
3- You cannot explicitly unlock the lock_guard();
4- You cannot copy lock_guard();
5- This is different from the unique_lock(). Unique_lock is more powerful, can
be unlocked, etc.
*/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor) {
  // instead of using lock and unlock method, we can use the lock_guard().
  // m1.lock();
  // This is wrappter for owning the mutex, scoped base. The destructor of the
  // lock_guard releases the lock once the thread goes out of scope.
  std::lock_guard<std::mutex> lock(m1);
  for (int i = 0; i < loopFor; ++i) {
    buffer++;
    std::cout << threadNumber << buffer << std::endl;
  }
  // m1.unlock();
}

int main() {

  std::thread t1(task, "T0 ", 10);
  std::thread t2(task, "T1 ", 10);

  t1.join();
  t2.join();

  return 0;
}