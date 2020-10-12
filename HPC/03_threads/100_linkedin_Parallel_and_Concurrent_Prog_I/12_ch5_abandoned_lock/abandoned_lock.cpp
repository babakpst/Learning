/**
 * Two philosophers, thinking and eating sushi
 */


#include <thread>
#include <mutex>

#define ABANDON

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {

        #ifdef ABANDON
        chopsticks.lock();
        #else
        // by replacing the mutex to scoped_lock there is no deadlock
        // The scoped lock holds on to the lock, for the scope in which the lock is created. Means, if the thread terminates, the lock would be unlocked.
        std::scoped_lock lock(chopsticks);
        #endif

        if (sushi_count) {
            sushi_count--;
        }
        
        // If we use the mutex lock and the following if statement, the first thread reaches the 10 sushi and who acquires the lock terminates before unlocking the lock. The other thread is waiting for a lock that is not going to release. 
        if (sushi_count==10) {
          puts(" this philosopher had enough");
          break; // this breaks the loop before the thread has the chance to unlock the chopstick. This would be a deadlock.
        } 
        #ifdef ABANDON
        chopsticks.unlock();
        #endif
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
