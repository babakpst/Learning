/*

Babak Poursartip
01/02/2021

Reference: Boost
PluralSight

signal2: signal other classes and function that a variable has changed, 

boost::signal<T> a signal that can be sent to anyone willing to listen.

Remark: We can connect a signal to multiple function and define priority for it. 


https://www.boost.org/doc/libs/1_61_0/doc/html/signals2/tutorial.html

*/

#include <iostream>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

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
class coach{
public:
  void playerScored(std::string name){
  std::cout  << " well done, " << name << std::endl;
  }

};

// ======================================
void check(){
  std::cout << " check \n";
}

// ======================================
void check2(int a){
  std::cout << " check: " << a << std::endl;
}

// ======================================
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

coach mCoach;
player mPlayer("bob");

mPlayer.scores.connect(boost::bind(&coach::playerScored, &mCoach, _1));
mPlayer.score();
mPlayer.score();

/*
std::cout << " 1 ============\n";
boost::signals2::signal<void()> s;
// customization of signals, by putting orders, we specify which signal to be triggered.
s.connect(1, [](){std::cout << " first " << std::endl;});
s.connect(0, [](){std::cout << " second " << std::endl;});

s();

std::cout << " 2 ============\n";
boost::signals2::signal<void()> sig;
{
auto c = sig.connect(1, [](){std::cout << " first " << std::endl;});
boost::signals2::scoped_connection sc(c); // restricts the scope of sig(1) to the curly bracket only.
sig.connect(0, [](){std::cout << " second " << std::endl;});
sig();
}

sig();

std::cout << " 3 ============ mutiple func with priority\n";
boost::signals2::signal<void()> sig3;
sig3.connect(check);
{
auto c = sig3.connect(1, [](){std::cout << " sig3 - first " << std::endl;});
boost::signals2::scoped_connection sc(c); // restricts the scope of sig(1) to the curly bracket only.
sig3.connect(0, [](){std::cout << " sig3 - second " << std::endl;});
sig3();
}

sig3();
std::cout << " disconnecting \n";
sig3.disconnect(check);
sig3();


std::cout << " 4 ============\n";
boost::signals2::signal<void(int a)> sig4;
sig4.connect(check2);
sig4(5);
*/
std::cout << " finished.\n";

return 0;
} 