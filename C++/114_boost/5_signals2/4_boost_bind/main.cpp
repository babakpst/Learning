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
#include <boost/smart_ptr.hpp>

// ======================================
class player {
private:
  int noOfGoals;

public:
  std::string m_name;
  player(std::string name):m_name(name){noOfGoals = 0;};

  // inside the connect, we need a lambda function that matches the signal signature.
  //boost::signals2::signal<void()>  scores; // void:  takes no parameters.

  typedef   boost::signals2::signal<void(std::string, int)> myType;
  myType scores; // void:  takes no parameters.

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
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

// 1 =================================
coach mCoach;
player mPlayer("bob");

// This is to connect the func in coach to the signal in the player. 
mPlayer.scores.connect(boost::bind(&coach::playerScored, &mCoach, _1));
std::cout << "1 ========\n";
mPlayer.score();
mPlayer.score();

// 2: what happens if coach goes out of scope ========
std::cout << "2 ========\n";
coach *mCoach2 = new coach;
player mPlayer2("shiva");

// This is to connect the func in coach to the signal in the player. 
mPlayer2.scores.connect(boost::bind(&coach::playerScored, mCoach2, _1));


mPlayer2.score();
delete mCoach2; // coach goes out of scope.
mPlayer2.score(); // it is still working as intended.


// How to handle the previous case, where, we have a pointer and it goes out of scope. 
std::cout << "3 ========\n";
player mPlayer3("Behnaz");
{

auto mCoach3 = boost::make_shared<coach>();

// This way we signal when the object is destroyed.
mPlayer3.scores.connect(player::myType::slot_type(&coach::playerScored, mCoach3.get(), _1).track(mCoach3));
mPlayer3.score();
}
mPlayer3.score(); // we get the output only once.


std::cout << " finished.\n";

return 0;
} 






















