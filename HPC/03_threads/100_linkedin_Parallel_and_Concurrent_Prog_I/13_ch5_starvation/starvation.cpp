/**
 * Too many philosophers, thinking and eating sushi
 */

#include <thread>
#include <mutex>
#include <iostream>

// If we have a large number of threads, some threads may never get the chance to acquire the lock. 

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    int sushi_eaten = 0;
    while (sushi_count > 0) {
        std::scoped_lock lock(chopsticks);
        if (sushi_count) {
            sushi_count--;
            sushi_eaten++;
        }
    }
    //printf(" Philsopher %d eats %d \n", std::this_thread::get_id(), sushi_eaten);
    std::cout << " Philsopher " << std::this_thread::get_id() << " eats " << sushi_eaten << "\n";
}


int main() {

    std::mutex chopsticks;
    std::array<std::thread, 200> philosophers;

    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i] = std::thread(philosopher,std::ref(chopsticks));
    }

    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i].join();
    }

    printf("The philosophers are done eating.\n");
}
