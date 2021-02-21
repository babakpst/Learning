
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

*/
#include <iostream>
#include <mutex>
#include <thread>

unsigned int bags_of_chips = 1;
std::mutex pencil;

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
  std::scoped_lock<std::mutex> lock(pencil);
  bags_of_chips *= 2;
  std::cout << " Barron doubled the bags " << std::endl;
}

// ===============================
void olivia_shopper() {
  cpu_work(1); // do some work
  std::scoped_lock<std::mutex> lock(pencil);
  bags_of_chips += 3;
  std::cout << " Olivia added 3 the bags " << std::endl;
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