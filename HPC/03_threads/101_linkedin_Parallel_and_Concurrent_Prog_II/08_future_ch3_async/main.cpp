
/*

Babak Poursartip
10/29/2020

run: g++ -std=c++17 -pthread main.cpp -o main

Linkedin course on concurrent programming

future:
Launching asynchronous task is a great way to accomplish multiple items at once.
Once thread is working on a task while the other one is continuing with its own
task. But we need to get the resutls back from the other tasks. Future is handy
here.

- A future is a placeholder for a result that will be available later. This is a
mechanism to access the resutl of an asynchronous operation. One thread may need
this result to proceed in FUTURE. The future is read-only, and the thread is
waiting until the results are ready.

- Once the results from the other thread is ready, the thread FULFILL/RESOLVE
the FUTURE.

MY UNDERSTANDING OF FUTURE: if the function returns a value, we cannot use the
ordinary thread the get it. The only way to do it, is using the future method,
as we did here.

*/
#include <chrono>
#include <future>
#include <iostream>
//#include <thread>

// ===========================
int how_many_veg() {
  std::cout << " thread is counting ... " << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  return 50;
}

// ===========================
int main() {

  std::cout << " starts ..." << std::endl;
  std::cout << " thread1 asks thread2 to find number of veg " << std::endl;
  std::future<int> results = std::async(std::launch::async, how_many_veg);
  std::cout << " thread1 is doing other stuff" << std::endl;

  // results.get: get function will return the results. But if the future has
  // not completed the task, then the get function blocks the execution, and
  // waits here until it is ready.
  std::cout << " thread2 responds:" << results.get() << std::endl;

  std::cout << " finished!" << std::endl;

  return 0;
}
