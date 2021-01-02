/*

Babak Poursartip
01/02/2021

Reference: Boost
PluralSight

signal2: signal other classes and function that a variable has changed, 

boost::signal<T> a signal that can be sent to anyone willing to listen.

observer pat tern,

*/

#include <iostream>
#include <boost/signals2.hpp>

// ======================================
class player {
private:
  int noOfGoals;

public:
  std::string m_name;
  player(std::string name):m_name(name){noOfGoals = 0;};

  // inside the connect, we need a lambda function that matches the signal signature.
  //boost::signals2::signal<void()>  scores; // void:  takes no parameters.
  boost::signals2::signal<void(std::string, int)>  scores; // void:  takes no parameters.
  void score (){
    noOfGoals++;
    scores(m_name, noOfGoals);
  }
};


// ======================================
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

player p("bob");
auto c = p.scores.connect([](std::string name, int count){
  std::cout << " player " << name << " has scored " << count << " goals\n";
});

p.score();
p.score();

{ // shared connection is going to live for a while that is why we put it in the {}.
  boost::signals2::shared_connection_block b(c); // signal has been blocked?! not very clear.
  p.score();
  p.score();
}

p.score();
p.score();

std::cout << " finished.\n";

return 0;
} 
