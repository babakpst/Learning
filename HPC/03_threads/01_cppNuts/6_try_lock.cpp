
/*
Babak Poursartip
10/21/2020

std::try_lock()
1- It tries to lock all the lockable objects passed to it, one-by-one, in the given order.

SYNTAX:  std::try_lock(m1, m2,...);

Important: The actual use of std::try_lock() is to try to lock multiple mutex at the same time. 



2- On success this function returns -1, otherwise, it will return 0-based mutex index number, which it could not lock.
3- If it fails to lock any of the mutex, then, it will release all the muteces it locked before. 
4- If a call to try_lock, results in an exception, unlock is called for any locked objects before rethrowing. 

5- Different locks can be used here: shared_lock, defer_lock, etc. 

*/


#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

int x = 0, y = 0;
std::mutex m1, m2;

void doSthforSecs(int secs){std::this_thread::sleep_for(std::chrono::seconds(secs));}

void incrementXY(int &XorY, std::mutex &m, const char *desc){
  for (int i = 0; i < 5; ++i){
    m.lock();
    ++XorY;
    std::cout << desc << XorY << '\n';
    m.unlock();
    doSthforSecs(1);
  }
}

void consumeXY(){
  int useCount = 5;
  int XplusY = 0;
  while(1){
    int lockResult = std::try_lock(m1,m2);
    if (lockResult==-1){
      if (x!=0 && y!=0){
        --useCount;
        XplusY+=x+y;
        x=0;
        y=0;
        std::cout << "XplusY " << XplusY << '\n';
      }
      m1.unlock();
      m2.unlock();
      if (useCount == 0) break;
    }
  }

}


int main(){

  std::thread t1(incrementXY, std::ref(x), std::ref(m1), "X ");
  std::thread t2(incrementXY, std::ref(y), std::ref(m2), "Y ");
  std::thread t3(consumeXY);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}


/*


*/

