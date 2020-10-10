
/**
 * Two shoppers adding items to a shared notepad
 */


#include <thread>

unsigned int garlic_count = 0;


// data race here.
void shopper() {
    //for (int i=0; i<10; i++) {
    for (int i=0; i<10000; i++) {
        garlic_count++;
    }
}


int main() {

    std::thread barron(shopper);
    std::thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("We should buy %u garlic.\n", garlic_count);
}
