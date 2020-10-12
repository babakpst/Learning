/**
 * Connecting cell phones to a charger
 */
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore(unsigned long init_count) {
        count_ = init_count;
    }

    void acquire() { // decrement the internal counter
        std::unique_lock<std::mutex> lck(m_);
        while (!count_) {
            cv_.wait(lck);
        }
        count_--;
    }

    void release() { // increment the internal counter
        std::unique_lock<std::mutex> lck(m_);
        count_++;
        lck.unlock();
       cv_.notify_one();
    }

private:
    std::mutex m_;
    std::condition_variable cv_;
    unsigned long count_;
};

Semaphore charger(4);

void cell_phone(int id) {
    charger.acquire();
    printf("Phone %d is charging...\n", id);
    srand(id); // charge for "random" amount between 1-3 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));
    printf("Phone %d is DONE charging!\n", id);
    charger.release();
}

int main() {
    std::thread phones[10];
    for (int i=0; i<10; i++) {
        phones[i] = std::thread(cell_phone, i);
    }
    for (auto& p : phones) {
        p.join();
    }
}