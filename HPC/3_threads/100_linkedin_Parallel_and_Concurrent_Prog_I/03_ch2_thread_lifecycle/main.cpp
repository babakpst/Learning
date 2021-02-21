/**
 * Two threads cooking soup
 */
#include <thread>
#include <chrono>

void chef_olivia() {
    printf("Olivia started & waiting for sausage to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Olivia is done cutting sausage.\n");
}

int main() {
    printf("Barron requests Olivia's help.\n");
    std::thread olivia(chef_olivia);

  
    // joinable: indicates whether a thread is still alive or not.
    printf(" Olivia is joinable? %s\n", olivia.joinable()? "ture":"false");

    printf("Barron continues cooking soup.\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf(" Olivia is joinable? %s\n", olivia.joinable()? "ture":"false");

    printf("Barron patiently waits for Olivia to finish and join...\n");
    olivia.join(); // this is equvalent to barrier/sync

    printf(" Olivia is joinable? %s\n", olivia.joinable()? "ture":"false");

    printf("Barron and Olivia are both done!\n");
}
