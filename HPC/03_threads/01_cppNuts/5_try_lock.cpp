
/*

Babak Poursartip
10/21/2020

try_lock:
0- try_lock tries to lock the mutex. On successful acquisition, it return true, otherwise false. 

1- If a thread cannot lock the mutex, it proceeds with the rest of the function. Thus, it is non-blocking.

2- If the try_lock is called again by the same thread which owns the mutex, the behavior is undefined, means it is deadlock.

3- If the same thread want to lock the same mutex more than once, recursive_mutex is the solution. 

VARIOUS TRY_lOCK:
- std::try_lock
- std::mutex::try_lock
- std::shared_lock::try_lock
- std::timed_mutex::try_lock
- std::unique_lock::try_lock
- std::shared_mutex::try_lock
- std::recuresive::try_lock
- std::shared_timed_mutex::try_lock
- std::recursive_timed_mutex::try_lock

*/

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void func(){
  for (int i = 0; i<10000; ++i){
    if (m.try_lock()){
      ++counter;
      m.unlock();
    }
  }
}

int main(){

std::thread t1(func);
std::thread t2(func);
t1.join();
t2.join();

std::cout << " counter: " << counter << std::endl;

}

