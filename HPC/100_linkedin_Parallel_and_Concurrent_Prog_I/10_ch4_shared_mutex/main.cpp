
  /**
 * Several users reading a calendar, but only a few users updating it
 */

// Reader-writer lock
// shared read: multiple threads at once.
// exclusive write: only one thread at a time.

#include <thread>
#include <mutex>
#include <chrono>
#include <shared_mutex>


char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int today = 0;
//std::mutex marker;
std::shared_mutex marker;

void calendar_reader(const int id) {
    for (int i=0; i<7; i++) {
        marker.lock_shared();
        printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        marker.unlock_shared();
    }
}

void calendar_writer(const int id) {
    for (int i=0; i<7; i++) {
        marker.lock();
        today = (today + 1) % 7;
        printf("Writer-%d updated date to %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        marker.unlock();        
    }
}

int main() {

    // create ten reader threads ...but only two writer threads
    std::array<std::thread, 10> readers;
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i] = std::thread(calendar_reader, i);
    }

    std::array<std::thread, 2> writers;
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i] = std::thread(calendar_writer, i);
    }

    // wait for readers and writers to finish
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i].join();
    }
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i].join();
    }
}
