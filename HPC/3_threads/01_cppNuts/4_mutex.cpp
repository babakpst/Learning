
/*
Babak Poursartip
10/21/2020
source: https://www.youtube.com/watch?v=eZ8yKZo-PGw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=4&ab_channel=CppNuts

mutex (what is mutex? what is the race condition? what is the critical section?)

RACE CONDITION:
1- Race condition is a situation where two or more threads/process try to modify a data at the same time. 
2- We should protect the code from the race condition. The protected area is called the critical section.


MUTEX:
1- Mutex is used to avoid the race condition.
2- We use lock()-unlock() on mutex to avoid the race condition.

*/

#include <iostream>
#include <thread>
#include <mutex>

int myAmount = 0;
std::mutex m;

void addMoney(){
  for (int i = 0; i < 10000; ++i){
  m.lock();
  ++myAmount;
  m.unlock();
  }
}

int main(){

std::thread t1(addMoney);
std::thread t2(addMoney);
t1.join();
t2.join();

std::cout << myAmount << std::endl;
return 0;
}
