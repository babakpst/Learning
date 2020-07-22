
/**
 * Barron finishes cooking while Olivia cleans
 */
#include <thread>
#include <chrono>


// remarks:
// daemon (background thread)
// daemon does not prevent the process from terminating
// by default, threads are created as non-daemon, thus
// the thread should turn to daemon manually.
// That means the thread is detached.
// Before making a thread daemon, you need to make sure that it has no side effects if it prematurly terminates.
// To make a thread daemon(detached) use thread_name.detach(). IN that case the thread is no longer joinable.

void kitchen_cleaner() {
    while (true) {
        printf("Olivia cleaned the kitchen.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread olivia(kitchen_cleaner);
    olivia.detach(); // detaching the olivia thread.

    for (int i=0; i<3; i++) {
        printf("Barron is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    printf("Barron is done!\n");
    //olivia.join(); // since olivia is detached, it is not joinable.
}
