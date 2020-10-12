/**
 * Exceptionally polite philosophers, thinking and eating sushi
 */

#include <thread>
#include <mutex>

// livelock
// mutiple threads or processes are actively responding to each other to resolve the conflict, but that prevents them from making any progress.

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        //second_chopstick.lock();
        if (!second_chopstick.try_lock()){
          first_chopstick.unlock(); // unlocks the first so that another thread can use it. 
          std::this_thread::yield(); // this causes the thread to wait before it takes the first chopstick again, which gives other threads to grab both chopstick. This will solve the livestock issue. 
        } else {
                if (sushi_count) {
                    sushi_count--;
                }
              second_chopstick.unlock();
              first_chopstick.unlock();
    }
  }
  puts(" this is me");
}

int main() {
    std::mutex chopstick_a, chopstick_b;

    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread barron2(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia2(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));

    barron.join();
    olivia.join();
    barron2.join();
    olivia2.join();

    printf("The philosophers are done eating.\n");
}
