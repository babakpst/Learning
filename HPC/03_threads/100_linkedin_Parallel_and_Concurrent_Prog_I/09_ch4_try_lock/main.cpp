
/**
 * Two shoppers adding items to a shared notepad
 */

// try lock: non-blocking version of mutex


#include <thread>
#include <mutex>
#include <chrono>

unsigned int items_on_notepad = 0; // This is a global variable all threads have access to.
std::mutex pencil;

void shopper(const char* name) {

    int items_to_add = 0; // This is a local variable for each thread.

    while (items_on_notepad <= 20) {
        //if (items_to_add) { // add item(s) to shared items_on_notepad
        //    pencil.lock();
        if (items_to_add  && pencil.try_lock()) { // add item(s) to shared items_on_notepad

            items_on_notepad += items_to_add;
            printf("%s added %u item(s) to notepad.\n", name, items_to_add);
            items_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300)); // time spent writing
            pencil.unlock();
        } else { // look for other things to buy
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // time spent searching
            items_to_add++;
            printf("%s found something else to buy.\n", name);
        }
    }
}

int main() {
    auto start_time = std::chrono::steady_clock::now();

    std::thread barron(shopper, "Barron");
    std::thread olivia(shopper, "Olivia");

    barron.join();
    olivia.join();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();

    printf("Elapsed Time: %.2f seconds\n", elapsed_time/1000.0);
}
