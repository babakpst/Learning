

// Babak Poursartip
// 10/11/2020
// Linkedin course: Parallel and concurrent programming with C++ part 2

/*

- Busy waiting/spinning:
repeatedly acquiring and releasing the lock to check for certain condition. Not
very efficient.

- Using mutex only, there is no way to synchronize the action of multiple
threads and signal btw threads.

- To avoid spinning, we can use condition variable, which is a queue of threads
waiting for a certain condition. The condition variable is associated with the
mutex.

- Monitor: threads work together to form a high-level construct associated with
mutex. A monitor protect a section of the code with mutual exclusion AND provide
the ability for threads to wait until a certial condition occurs.

- Condition variable has three main operations:
  1- wait
  2- signal
  3- broadcast

- Before using a condition variable, I first need to acquire the lock, then
check the condition, if the condition is not met, it automatically
releases the lock on the mutex, and the thread goes to sleep and enters the
waiting queue. It will reacquire the lock when it wakes up.

- Signal is used to wake up a thread from a condition variable queue.
- Broadcast is similar to Signal, except that it wakes up all threads(notify all
or wake all).

- For complex cases, we need to use a SHARED QUEUE or BUFFER. If multiple
threads putting items in a queue or taking them out, then it needs a mutex to
ensure that only one thread can add/remove from it at a time. To do so we can
use two condition variables:
  * BufferNotFull: If a thread is trying to add an item to a queue, which is
already full, it can wait on a condition variable to indicate that buffer is not
full.
  * BufferNotEmpty If a thread is trying to take an item, but the buffer is
empty, then it can wait on another condition variable, for buffer not empty.

   These conditions allow threads to signal each other, when the state of the
queue changes.


*/

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;

// =====================================
int soup_servings = 10;
std::mutex cooker_lid;
std::condition_variable soup_taken;

// =====================================
void person(int id) {

  int put_lid_back = 0;
  while (soup_servings > 0) {

    // pick up the slow cooker lid
    std::unique_lock<std::mutex> lid_lock(cooker_lid);

    /*
    // is it your turn to take soup?
    if ((id == soup_servings % 2) && (soup_servings > 0)) {
      soup_servings--; // it's your turn; take some soup!
    } else {
      put_lid_back++; // it's not your turn; put the lid back...
    }
    */
    // The reason put the condition variable inside the while loop is that in
    // certain conditions, the thread may have a spurious wake up (waking up
    // when it not suppose to).
    while ((id != soup_servings % 5) && (soup_servings > 0)) {
      put_lid_back++;            // it's not your turn; put the lid back...
      soup_taken.wait(lid_lock); // ...and wait...
    }
    if (soup_servings > 0) {
      soup_servings--;         // it's your turn; take some soup!
      lid_lock.unlock();       // put back the lid
      soup_taken.notify_all(); // notify another thread to take their turn
    }
  }
  printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

// =====================================
int main() {
  cout << "\n starts ... \n";

  std::thread threads[5];
  for (int i = 0; i < 5; ++i) {
    threads[i] = std::thread(person, i);
  }

  for (auto &c : threads)
    c.join();

  cout << "\n finished successfully. \n";
  return 0;
}