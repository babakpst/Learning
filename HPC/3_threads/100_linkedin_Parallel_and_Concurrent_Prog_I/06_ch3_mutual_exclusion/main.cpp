
/**
 * Two shoppers adding items to a shared notepad
 */

// to avoid data race,  we need to use mutual exclusion: only one thread can access at the time.
// To do so, we need to do atomic operation.

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex> // mutual exclusion.

unsigned int garlic_count = 0;
std::mutex pencil;

void shopper() {
    //*
    //pencil.lock();
    for (int i=0; i<10; i++) {
        //printf("shopper %d is thinking \n", std::this_thread::get_id());
        std::cout << "shopper " << std::this_thread::get_id() << " is thinking\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        pencil.lock();
        garlic_count++;
        pencil.unlock();
    }
    //pencil.unlock();
    //*/


}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
}
