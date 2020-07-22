
/**
 * Two shoppers adding garlic and potatoes to a shared notepad
 */
#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
unsigned int potato_count = 0;
//std::mutex pencil; // the mutext only allows the pencil to be locked once.

std::recursive_mutex pencil; // the recursive_mutex allows multiple lock on the pencil

void add_garlic() {
    pencil.lock();
    garlic_count++;
    pencil.unlock();
}

void add_potato() {
    pencil.lock();
    potato_count++;
    add_garlic(); //this creates two nested locks.
    pencil.unlock();
}

void shopper() {
    for (int i=0; i<10000; i++) {
        add_garlic();
        add_potato();
    }
}


int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}
