/*

Babak Poursartip
10/23/2020

Concurrent programming: producer-comsumer architectre (pattern)

REMARKS:
- Producer-Consumer pattern means
  * one or more threads/processes act as PRODUCERS. Producers add elements to
shared data structures.
  * one or more threads act as consumers which remove elements from shared data
structure.

- Challenges for this pattern:
  * The produced elements are pushed into a queue, and consumers remove the
elements from queue (FIFO).
  * Main challenge here is the synchronization. We need to enforce mutex of
producers and consumers.
  * We need to prevent producers from trying to add data to a full queue. And
prevent consumers from removing data from an empty queue.
  * Some languages may have some implementation of queue that are thread safe
and handles this challenges. Otherwise, using mutex and condition vars, we need
to manually implement a thread-safe, sync queue.
  * In some cases, we may face a situation where the producer can be paused if
the queue fills up. The rate at which the data is produced / consumed. If
production > consumption, we face buffer overflow, and we lose data.
  * A queue can only hold a number of items. Some languages offer implementation
of unbounded queues (unlimited capacity). But, still these are bounded by the
size of the memory.
  * The rate at which the producer adds items may not always be consistent. We
need to design the program such that:
         (average of production < average rate of consumption)
  * To adjust the speed, we may need to have more consumer threads than the
producers.


PIPELINE (of tasks): a chain of processing elements arranged so that the output
of each element is the input to the next one. That is basically, a series of
producer/consumer pairs connected together, with some sort of queue btw
consecutive elements.
  (producer) ===(queue)===>> (consumer)(producer) ===(queue)===>> (consumer)
The downstream consumers should consumer the data faster the its own producer.

C++ standard queue is not thread safe, means it cannot protect itself from data
races, etc, when multiple threads are pushing and poping on and off it. We need
to use mutex to protect it.

IMPORTANT:
The condition variable only accepts unique_lock, that is why we need to use a
unique_lock instead of other forms of lock. The benefit of having this basic
queue with no protection, over protected queues in Python, is that for a single
threaded queue, there is no overhead due to the mutex.


*/

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// =================================
class ServingLine {
private:
  std::queue<int> soup_queue;
  std::mutex ladle;
  std::condition_variable soup_served;

public:
  void serve_soup(int i) {
    std::unique_lock<std::mutex> ladle_lock(ladle);
    soup_queue.push(i);
    ladle_lock.unlock();
    soup_served.notify_one();
  }

  int take_soup() {
    std::unique_lock<std::mutex> ladle_lock(ladle);
    while (soup_queue.empty()) {
      soup_served.wait(ladle_lock);
    }
    int bowl = soup_queue.front();
    soup_queue.pop();
    return bowl;
  }
};

// =================================
ServingLine serving_line; // = ServingLine();

// =================================
void soup_producer() {
  for (int i = 0; i < 1000000; ++i) {
    serving_line.serve_soup(1);
  }
  serving_line.serve_soup(-1); // no more soup
  std::cout << " Producer is done serving soup!\n";
}

// =================================
void soup_consumer() {
  int soup_eaten = 0;
  while (true) {
    int bowl = serving_line.take_soup();
    if (bowl == -1) { // check for the last bowl
      std::cout << " consumer ate: " << soup_eaten << std::endl;
      // putting back the last bowl for other customers/threads
      serving_line.serve_soup(-1);
      return;
    } else {
      soup_eaten += bowl; // eating/consuming the soup
    }
  }
}

// =================================
int main() {
  std::cout << " starts... \n";
  std::thread t1(soup_producer);
  std::thread t2(soup_consumer);
  std::thread t3(soup_consumer);
  t1.join();
  t2.join();
  t3.join();

  return 0;
}