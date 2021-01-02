
/*

Babak Poursartip
12/31/2020

Reference: Boost
PluralSight

signal2: signal other classes and function that a variable has changed, 

boost::signal<T> a signal that can be sent to anyone willing to listen.

- signal: notification that sth occurred.
- slot: an ordinary method, a func, or lambda. You can call a slot independently.
- connection: associates a signal with a slot, a signal can be connected to multiple slots.
- activation: when the signal is emitted the connected slot is called.  

Remarks:
- most of the signal classes are thread safe.
- slots are called only in the current thread.
- you cannot connect a signal in one thread to a slot in another thread.

*/

#include <iostream>
#include <boost/signals2.hpp>

// ======================================
class player {

public:
  std::string m_name;
  player(std::string name):m_name(name){};

  // inside the connect, we need a lambda function that matches the signal signature.
  //boost::signals2::signal<void()>  scores; // void:  takes no parameters.
  boost::signals2::signal<void(std::string)>  scores; // void:  takes no parameters.
};


// ======================================
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

  player p("bob");
  //p.scores.connect([](){std::cout << "well done\n";});
  //p.scores();
  
  // score is a slot.
  auto c = p.scores.connect([](std::string name){std::cout << "well done " << name << std::endl;});
  p.scores(p.m_name); // we get notification
  p.scores(p.m_name); // we get notification

  p.scores.disconnect_all_slots();
  c.disconnect(); // same effect as previous one.
  
  p.scores(p.m_name); // we do not get notifications, because p.scores is disconnected.
  p.scores(p.m_name); // we do not get notifications, because p.scores is disconnected.

std::cout << " finished.\n";

return 0;
} 
