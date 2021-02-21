
/*
Babak Poursartip
10/18/2020

REMARKS:
>> JOIN()
0- the main thread waits for this thread to finish.
1- double join will result in program termination, with runtime error. It aborts
because after join that particular thread does not exist anymore
2- we can use joinable() before join() to check if a thread is joinable.


>> DETACH()
0- To detch a thread from the parent/master thread.
1- Always check whether a thread is joinable before detaching it. Double
detaching terminates the program.
2- If the master thread returns, the detached thread suspends.

- IMPORTANT:
Either join() or detach() should be called on a thread object, otherwise during
thread object's destructor, it will terminate the program. Because inside the
destructor, it checks whether the thread is still joinable.

*/
#include <chrono>
#include <iostream>
#include <thread>

void run(int count) {
  while (count-- > 0)
    std::cout << " count= " << count << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << " thread finished\n";
}

int main() {
  std::cout << " starts ... \n";
  int m = 5;
  std::thread t1(run, m);
  std::cout << " here is main() before\n";
  t1.join();
  // runtime error: called after throwing an instance of 'std::system_error'
  // what():  Invalid argument
  // aborted
  // t1.join();

  if (t1.joinable())
    t1.join();

  std::cout << " here is main() after\n";

  // detach
  std::thread t2(run, m);
  std::cout << " here is main() before\n";

  t2.detach(); // thread t2 may or may not finishes its task before the master
               // thread termination.

  // runtime error: called after throwing an instance of 'std::system_error'
  // what():  Invalid argument
  // aborted
  // t2.detach();
  if (t2.joinable())
    t2.detach();

  std::cout << " here is main() after\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << " finished \n";
  return 0;
}