
  /**
 * Several users reading a calendar, but only a few users updating it
 */


// to compile: g++ -pthread -std=c++17 main.cpp -o main
// Reader-writer lock
// shared read: multiple threads at once.
// exclusive write: only one thread at a time.

#include <thread>
#include <mutex>
#include <chrono>
#include <shared_mutex>

#define SHARED

char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int today = 0;

#ifdef SHARED 
std::shared_mutex marker;
#else 
std::mutex marker;
#endif

void calendar_reader(const int id) {
    for (int i=0; i<7; i++) {
        #ifdef SHARED 
        marker.lock_shared();
        #else 
        marker.lock();
        #endif
        
        printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        #ifdef SHARED 
        marker.unlock_shared();
        #else 
        marker.unlock();
        #endif
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
