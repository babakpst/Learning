
/**
 * Two shoppers adding items to a shared notepad
 */

// instead of using mutual exclusion (mutex) as we did in the previous lesson, for simple operations, one can use atomic operation. 

#include <thread>
#include <atomic>

//unsigned int garlic_count = 0;
std::atomic<unsigned int> garlic_count(0);

void shopper() {
    for (int i=0; i<10000000; i++) {
        garlic_count++;
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    //printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u garlic.\n", garlic_count.load());
}
