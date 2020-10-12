/**
 * Chopping vegetables with a thread pool
 */
#include <boost/asio.hpp>

void vegetable_chopper(int vegetable_id) {
    printf("Thread %d chopped vegetable %d.\n", std::this_thread::get_id(), vegetable_id);
}

int main() {
    boost::asio::thread_pool pool(4); // 4 threads
    for (int i=0; i<100; i++) {
        boost::asio::post(pool, [i](){vegetable_chopper(i);});
    }
    pool.join();
}