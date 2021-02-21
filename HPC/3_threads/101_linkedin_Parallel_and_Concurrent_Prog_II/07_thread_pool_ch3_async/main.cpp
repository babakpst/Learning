
/*

Babak Poursartip
10/28/2020

run with makefile

Linkedin course on concurrent programming

thread pool: instead of having one thread for each task, we define a thread
pool, with only a limited number of threads and we do all the tasks by this
limited number of threads in the thread pool. The benefit of having a thread
pool is that, we eliminate the overhead of thread creating. Even though the
threads are considered as lightweight, but still, if we want to generate several
threads, it slows down the code.

Not working.

*/

#include <boost/asio.hpp>
//#include <boost/asio/io_service.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread/thread.hpp>
#include <iostream>
#include <thread>

void veg_chopper(int veg_id) {
  std::cout << " Thread " << std::this_thread::get_id() << " chopped vegtable "
            << veg_id << std::endl;
}

int main() {

  std::cout << " starts ..." << std::endl;

  // std::thread choppers[100];
  boost::asio::thread_pool pool(4); // now we have 4 threads in the loop

  for (int i = 0; i < 100; ++i) {
    // choppers[i] = std::thread(veg_chopper, i);

    // we wrap the function in a lambda function.
    boost::asio::post(pool, [i]() { veg_chopper(i); })
  }

  /*
  for (auto &c : choppers)
    c.join();
  */
  pool.join(); // this waits until all submitted tasks have finished executing.

  std::cout << " finished" << std::endl;

  return 0;
}