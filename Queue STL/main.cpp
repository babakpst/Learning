

// queue container in STL
// Babak Poursartip



#include <iostream>
#include <queue>

int main(){

  // defining a queue using the std
  std::queue <int> q1;


  // filling the queue
  // the value of 0 is at the head and 9 at the tail. The oldest value is 0.
  for (int i = 0; i < 10; i++){
     std::cout << "equeuing " << i << std::endl; 
     q1.push(i);
  }

  std::cout << " size of the queue: " << q1.size() << std::endl;
  std::cout << " The back of my queue: " << q1.back() << std::endl;
  
  while (!q1.empty()) {
    std::cout << " dequeuing: " << q1.front() << std::endl;
    q1.pop();
  }
}
