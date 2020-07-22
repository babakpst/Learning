/**
 * Two philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {
        chopsticks.lock();
        if (sushi_count) {
            sushi_count--;
        }
        chopsticks.unlock();
    }
}

int main() {
    std::mutex chopsticks;
    std::thread barron(philosopher, std::ref(chopsticks));
    std::thread olivia(philosopher, std::ref(chopsticks));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}