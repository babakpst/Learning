
/*

Babak Poursartip
10/27/2020

semaphore: a system of sending messages by holding the arms or two flags or
poles in certain positions according to an alphabetic code

- Semaphore is another synchronization mechanizam that can be used to control
access to shered resources. It is different from mutex by allowing multiple
threads to access the data at the same time.
- It has a counter to check how many time the lock has been acquired or
released. As long as the counter is positive, any thread can acquire the
semaphore, which decrements the counter. If the counter is zero, then the
threads trying to acquire the lock, but it is blocked. The acquire will then be
placed in a queue to wait until it is available. When a thread is done using a
semaphore, it releases the semaphore and the counter will increase. If there is
any thread waiting to acquire the semaphore lock, they would wake up after a
thread releases the semaphore lock.

- This semaphore is called the A COUNTING SEMAPHORE, because it counts the total
number of resources we have.

- Binary semaphore: It is possible to restrict the value of the semaphore to be
either 0 or 1; with zero represent a locked state and 1 represents unlocked.
This is indeed similar to mutex (acquireing/releasing). THE DIFFERENCE THOUGH is
that the Mutex can only acquired/released by the same thread. BUT THE SEMAPHORE
can be acquired/released by different threads. This potentially can cause
trouble, if we are not careful. But this allows us as a signaling mechanism. For
example with the producer-cosumer pattern.

- Since the semaphore is not in the standard C++ yet (c++17), we need to design
our own semaphore class as we did here.


This is not very clear, It seems that the unique_lock is accesses by all. Why?

*/

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

//=========================================
class Semaphore {
private:
  std::mutex m_;
  std::condition_variable cv_;
  unsigned long count_;

public:
  Semaphore(unsigned long init_count) { count_ = init_count; }

  void acquire(int id) { // decrement the internal counter
    std::unique_lock<std::mutex> lck(m_);
    while (!count_) {
      std::cout << " this count: " << count_ << " on id: " << id << std::endl;
      cv_.wait(lck);
    }
    --count_;
  }

  void release(int id) { // increment the internal counter
    std::unique_lock<std::mutex> lck(m_);
    std::cout << " release id: " << id << std::endl;
    ++count_;
    lck.unlock();
    cv_.notify_one();
  }
  unsigned long getter() { return count_; }
};

//=========================================
Semaphore charger(4);
// Semaphore charger(1); // this would act as a binary semaphore (not different
// from a mutex)

//=========================================
void cell_phone(int id) {
  charger.acquire(id);
  std::cout << " phone " << id << " is charging-count: " << charger.getter()
            << std::endl;
  srand(id); // this will charge the cell phone for a random amount.
  std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 4000 + 1000));
  std::cout << " phone: " << id << " is done charging" << std::endl;

  charger.release(id);
}

// ================================
int main() {
  std::cout << " starts ..." << std::endl;

  std::thread phone[10];
  for (int i = 0; i < 10; ++i) {
    phone[i] = std::thread(cell_phone, i);
  }
  for (auto &p : phone)
    p.join();

  std::cout << " finished " << std::endl;
  return 0;
}
