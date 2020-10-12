/**
 * Two hungry threads, anxiously waiting for their turn to take soup
 */
#include <thread>
#include <mutex>

int soup_servings = 10;
std::mutex slow_cooker_lid;

void hungry_person(int id) {
    int put_lid_back = 0;
    while (soup_servings > 0) {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // pick up the slow cooker lid
        if ((id == soup_servings % 2) && (soup_servings > 0)) { // is it your turn to take soup?
            soup_servings--; // it's your turn; take some soup!
        } else {
            put_lid_back++; // it's not your turn; put the lid back...
        }
    }
    printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

int main() {
    std::thread hungry_threads[2];
    for (int i=0; i<2; i++) {
        hungry_threads[i] = std::thread(hungry_person, i);
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}