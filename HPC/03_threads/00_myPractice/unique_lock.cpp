
// source: https://www.youtube.com/watch?v=NsqqWDQHldo&ab_channel=CppNuts

// unique_lock: std::unique_lock<mutex> lock(m1)

/*
Remarks:

1- The class unique_lock is a mutex ownership wrapper.
2- It allows:
  a. different locking strategies
  b. time-constrained attemps at locking (try_lock_for, try_lock_until)
  c. recursive locking
  d. transfer of lock ownership (move not copy)
  e. condition variables

** General format for unique_lock:
std::unique_lock<mutex> lock(m1, locking_srategy); 

** We are not unlocking the unique_lock. It is in the destructor of the unique_lock.



LOCKING STRATEGIES: 
1. defer_lock    do not acquire ownership of the mutex
2. try_to_lock   try to acquire ownership of the mutex without blocking
3. adopt_lock    assume the calling thread already has ownership of the mutex

*/


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;
int buffer = 0;


// example 1 =================================================

void task(const char *threadNumber, int loopFor){
// automatically calls lock on mutex m1, we own the mutex this way. Then, we can handle lock m1, using this variable. This would be equivalent to lock and unlock.
std::unique_lock<mutex> lock(m1); 
  //m1.lock();
  for (int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << "  -  "<<buffer << endl;
  }
  //m1.unlock();
}
 

// example 2 =================================================

void task2(const char *threadNumber, int loopFor){
// Does not call lock on mutex m1. 
std::unique_lock<mutex> lock(m1, std::defer_lock); 
  m1.lock(); // We need to explicitly lock m1, then. 
  for (int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << "  -  "<<buffer << endl;
  }
  //m1.unlock(); not needed, automatically works.
}


// =============================================================
int main(){
  thread t1(task, "T1", 10);
  thread t2(task, "T2", 10);
  t1.join();
  t2.join();

  cout << "============\n";

  thread t3(task2, "T3", 10);
  thread t4(task2, "T4", 10);
  t3.join();
  t4.join();


  return 0;
} 



