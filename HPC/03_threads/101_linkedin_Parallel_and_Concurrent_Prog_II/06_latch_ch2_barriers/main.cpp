
/*

Babak Poursartip
10/28/2020

USE MAKEFILE TO RUN

Linkedin Course on cuncurrent programming

Latch: allows one or more threads to wait until a set of operations being
performed in other threads to complete.

- The latch initialized with a count value which threads can use in two ways:
 * threads can wait at the latch until the count value reaches zero,
 * or they can decrement the count value by calling the latch's count_down func.


- if we initialize the latch with a count of 1, it behaves like a gate: any
number of threads can wait at the gate until another controlling gate executes
the count down funciton just once.

- The latch does not require the threads calling the count down to wait there
until proceeding. They are phrased to continue. It only prevents the threads
that call the wait function from proceeding before the count reaches zero.


- DIFFERENCE BETWEEN BARRIER AND LATCH:
 Barrier releases when certain number of threads are waiting
 Latch releases when count value reaches zero.


*/

#include <boost/thread/latch.hpp>
#include <iostream>
#include <mutex>
#include <thread>

unsigned int bags_of_chips = 1;
std::mutex pencil;
// if this number is greater than the threads that are going through this
// function, it would be a deadlock then.
boost::latch fist_bump(5);

// ===============================
void cpu_work(unsigned long workUnits) {
  unsigned long x = 0;
  for (unsigned long i; i < workUnits * 1000000; ++i) {
    ++x;
  }
}

// ===============================
void barron_shopper() {
  cpu_work(1); // do some work
  fist_bump.wait();
  std::scoped_lock<std::mutex> lock(pencil);
  bags_of_chips *= 2;
  std::cout << " Barron doubled the bags " << std::endl;
}

// ===============================
void olivia_shopper() {
  cpu_work(1); // do some work
  {
    std::scoped_lock<std::mutex> lock(pencil);
    bags_of_chips += 3;
  }
  std::cout << " Olivia added 3 the bags " << std::endl;
  // after each thread here finishes adding their three bags, they call this
  // function to decrement the count value. Barron starts when the count reaches
  // zero.
  fist_bump.count_down();
}

// ===============================
int main() {
  std::cout << " starts ... " << std::endl;
  std::thread shoppers[10];
  for (int i = 0; i < 10; i += 2) {
    shoppers[i] = std::thread(barron_shopper);
    shoppers[i + 1] = std::thread(olivia_shopper);
  }

  for (auto &c : shoppers)
    c.join();

  std::cout << " we need to buy " << bags_of_chips << " bags of chips "
            << std::endl;
  std::cout << " finished " << std::endl;
}