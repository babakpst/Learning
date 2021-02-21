/**
 * Two philosophers, thinking and eating sushi
 */


// g++ -pthread -std=c++17 main.cpp -o main

#include <thread>
#include <mutex>

// deadlock
// Ensure locks are always taken in the same order by any thread.


// input section 
#define DEADLOCK


int sushi_count = 5000;
int sushi_count2 = 5000;


// lock ordering avoids deadlock here.
void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        second_chopstick.lock();
        if (sushi_count) {
            sushi_count--;
        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

// alternative solution to avoid deadlock: using scoped_lock.
void philosopher2(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count2 > 0) {
        // lock lasts automatically to the end of the while loop. You don't need to unlock them, then. 
        std::scoped_lock lock(first_chopstick, second_chopstick); 
        if (sushi_count2) {
            sushi_count2--;
        }
    }
}

int main() {

    std::mutex chopstick_a, chopstick_b;

    #ifdef DEADLOCK  // This leads to a deadlock
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    #else  // no deadlock because of lock ordering.
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    #endif
    barron.join();
    olivia.join();

    printf("The philosophers are done eating.\n");

    // alternative method to avoid deadlock: scoped_lock. 
    std::thread barron2(philosopher2, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia2(philosopher2, std::ref(chopstick_b), std::ref(chopstick_a));

    barron2.join();
    olivia2.join();

    printf("The philosophers are done eating.\n");

}
