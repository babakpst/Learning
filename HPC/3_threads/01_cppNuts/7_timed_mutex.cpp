
/*

Babak Poursartip
10/21/2020

REMARKS:
1- std::timed_mutex is blocked until timeout_time or the lock is acquired. It
returns true if successfully acquire the lock, otherwise it returns false.

2- Member function:
 a. lock
 b. try_lock
 c. try_lock_for
 d. try_lock_until
 e. unlock


EXAMPLE:
The thread waits for the specified timeout_duration to acquire the lock,
otherwise it passes the lock.

*/

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

int myAmount = 0;
std::timed_mutex m;

void increment(int i) {
  if (m.try_lock_for(std::chrono::seconds(1))) {
    ++myAmount;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << " thread: " << i << " entered\n";
    m.unlock();
  } else {
    std::cout << " thread: " << i << " could not enter\n";
  }
}

void increment2(int i) {                       // same as the previous function
  auto now = std::chrono::steady_clock::now(); // current time
  if (m.try_lock_until(now + std::chrono::seconds(1))) {
    ++myAmount;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << " thread: " << i << " entered\n";
    m.unlock();
  } else {
    std::cout << " thread: " << i << " could not enter\n";
  }
}

int main() {

  std::thread t1(increment, 1);
  std::thread t2(increment, 2);
  t1.join();
  t2.join();

  std::cout << myAmount << std::endl;
  std::cout << "============" << std::endl;

  std::thread t3(increment, 1);
  std::thread t4(increment, 2);
  t3.join();
  t4.join();

  std::cout << myAmount << std::endl;

  return 0;
}
