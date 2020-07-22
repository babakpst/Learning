/**
 * Two philosophers, thinking and eating sushi
 */


#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {

        //chopsticks.lock();
        // by replacing the mutex to scoped_lock there is no deadlock
        std::scoped_lock lock(chopsticks);

        if (sushi_count) {
            sushi_count--;
        }
        // If we use the mutex lock and the following if statement, the first thread reaches the 10 sushi and who acquires the lock terminates before unlocking the lock. The other thread is wainting for a lock that is not going to release. 
        if (sushi_count==10) {
          puts(" this philosopher had enough");
          break; 
        } 
        //chopsticks.unlock();
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
