
/*

Babak Poursartip
10/27/2020

RUN:g++ -pthread -std=c++17 main.cpp -o main


Data race vs race condition: two different problem in concurrent progs.

- Data race: two more threads cuncorrently access the same memory location, if
at least one thread tries to modify/write the memory, threads override each
other or read wrong values. To avoid that we need to use mutex.

- Race condition: flaw in timing or ordering of execution. For example assume
thread ONE runs a func that doubles the value of X and thread TWO runs a func
that increment X by 3. Then, depending on the ordering of the threads, we may
face any of the two following conditions:

** case 1: thread ONE runs first: X*2+3
** case 2: thread TWO runs first: (X+3)*2

- In practice many race conditions are caused by data race and vice versa. But
these two problems are not depend on each other. This means we may have data
race without race condition, or race condition without data race.

- Detecting the race condition is not trivial. We can put sleep statement to
reorder execution of threads.

- Race condition is like HEISENBUG, A SOFTWARE BUG THAT DISAPPEARS WHEN TRY TO
STUDY IT.

- The following code is vulnerable to race condition.

- To prevent the race condition, we can use barrier.
- Barrier: prevents a group of threads from proceeding until enough threads have
reached the barrier.

thread 1       thread 2
   |              |
   |              |
  + 3             |
   |              |
   |              |
   V              V
====== barrier ======
thread 1       thread 2
   |              |
   |              |
   |             x 2
   |              |
   |              |
   V              V

*/
#include <boost/thread/barrier.hpp>
#include <iostream>
#include <mutex>
#include <thread>

unsigned int bags_of_chips = 1;
std::mutex pencil;
// The constructor of barrier takes an argument for the number of threads to
// wait at the barrier before it releases.
boost::barrier fist_bump(10); // all ten threads should reach here.

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
  // if a thread goes into waiting while it still posses the lock, then that
  // would be deadlock, thus, we need to limit the scope of the scoped_lock.
  fist_bump.wait();
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