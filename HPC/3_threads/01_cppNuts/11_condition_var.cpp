
/*

Babak Poursartip
10/19/2020

Condition varialbe

PURPOSE:
1- Notify other threads
2- Waiting for some other conditions

REMARKS:
1- Condition Varialbe allows running threads to wait on some conditions and once
these conditions are met the waiting thread is notified using:
  a. notify_one();
  a. notify_all();
2- You need mutext to use condition variable.
3- If some thread want to wait on some condition, then it has to do these
things:
  a. acquire mutex lock using std::unique_lock<std::mutex> lock(m);
  b. execute wait, wait_for, or wait_until. The wait operations automatically
release the mutex and suspend the execution of the thread.
  c. when the condition variable is notified, the thread is awakened and the
mutex is automatically reacquired. The thread should then check the condition
and resume waiting if the wake up was spurious.


NOTE:
1- Condition variables are used to synchronize two or more threads.
2- Best use case of condition variable is Producer/Consumer problem.

*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::condition_variable cv;
std::mutex m;

long balance = 0;

// ====================================
void addMoney(int money) {
  std::lock_guard<std::mutex> lg(m);
  balance += money;
  std::cout << " The amount added! The current balance: " << balance
            << std::endl;
  cv.notify_one();
}

// ====================================
void withdrowMoney(int money) {
  // this unique lock is just a wrapper for m, and owning it.
  std::unique_lock<std::mutex> ul(m);

  // if the condition does not meet, the cv.wait unlocks the lock on m.
  cv.wait(ul, [] { return (balance != 0) ? true : false; });
  if (balance >= money) {
    balance -= money;
    std::cout << " Amount deducted: " << money << std::endl;
  } else {
    std::cout << " Amout can't be deducted, current balance is less than: "
              << money << std::endl;
  }

  std::cout << " current balance is: " << balance << std::endl;
}

int main() {

  std::cout << " code starts ...\n";

  /*
  Either of these threads can start first.
  - If t2 starts first, then, it locks the mutex first, thus, the t1 cannot
  acquire the lock at (unique_lock...), and t1 just waits until t2 releases the
  lock. Once t2 is finished, lock_quard releases m and t1 acquire the lock, and
  checks whether the balance is non-zero (which it is), and proceeds. In this
  case the notify_once() is useless becasue no threads is actually waiting for
  the lock.
  - If t1 starts first, it acquire the lock first, but when it checks for the
  condition (balance !=0), it fails and releases the lock and waits until it
  receives the notification that the balance has changed. Since m is unlocked,
  t2, which starts later, acquire the lock and proceeds with adding money. Once
  t2 is done, it notifies t1 about the balance, t1 acquire the lock and
  proceeds.
  */
  std::thread t1(withdrowMoney, 150);
  // std::thread t1(withdrowMoney, 100);
  // std::this_thread::sleep_for(std::chrono::seconds(2));

  std::thread t2(addMoney, 100);
  t1.join();
  t2.join();

  std::cout << "\n  finished! \n";

  return 0;
}