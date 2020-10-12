/**
 * Chopping vegetables with a thread pool
 */
#include <thread>

void vegetable_chopper(int vegetable_id) {
    printf("Thread %d chopped vegetable %d.\n", std::this_thread::get_id(), vegetable_id);
}

int main() {
    std::thread choppers[100];
    for (int i=0; i<100; i++) {
        choppers[i] = std::thread(vegetable_chopper, i);
    }
    for (auto& c : choppers) {
        c.join();
    }
}