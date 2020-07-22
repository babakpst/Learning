/**
 * Too many philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

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
    printf("Philosopher %d ate %d.\n", std::this_thread::get_id(), sushi_eaten);
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