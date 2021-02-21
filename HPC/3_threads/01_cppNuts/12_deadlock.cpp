

// Babak Poursartip
// 09/30/2020

// cppNuts
// multithreaded programming: deadlock

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1(){
  m1.lock();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  m2.lock();
  std::cout << " critical section of thread 1" << std::endl;
  m1.unlock();
  m2.unlock();
}


// if we change the order of the lock, then there would be no deadlock.
void thread2(){
  m2.lock();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  m1.lock();
  std::cout << " critical section of thread 2" << std::endl;
  m2.unlock();
  m1.unlock();
}

//====================================================
int main() {
  std::cout << " starts \n";

  std::thread t1(thread1);
  std::thread t2(thread2);

  t1.join();
  t2.join();
  std::cout << " \n ends\n";

  return 0;
}
