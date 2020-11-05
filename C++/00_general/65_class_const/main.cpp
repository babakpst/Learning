/*

Babak Poursartip

11/05/2020

Item 2: Meyers

- declaration and definition of integral type var in class
- integral types are: integers, chars, bools

- Usually, c++ requires that you provide a definition for anything you use, but class-specific constants that are static and of integral type are an exception. As long as you don't take their address you can declare them and use them without providing a defintion. If you do take the address of a class constatnt, or if your compiler incorrectly insists on a definition even if you don't take the address you provide a separate defintion. See below.

-----------------
- Enum hack: If we need the value of a class constant during compilation, such as declaration of an array (GamePlayers::scores), where the compiler insists on knowing the size of the array during compilation, then the accepted way to compensate for the compilers that (incorrectly) forbid the in-class specification of initial values for static integral class constants is to use ENUM HACK. It takes the advantage of the fact the values of an enumerated type can be used where ints are expected.



*/

#include <iostream>

class GamePlayer{

private:
static const int NumTurns = 5; // this is a declaration, but not definition
int scores[NumTurns];          // use of constant

// This is a compilation error, we cannot initialize non-integral, const varialbes inside a class:
//static const double FudgeFactor = 1.35; // constant declaration

//Enum hack:
enum{NumTurns4=5};
int scores2[NumTurns4];          // use of constant

public: 
static const int NumTurns2 = 6; // constant declaration, but not definition
//static const double NumTurns3 = 6.2; // constant declaration, but not definition
static const double NumTurns3; // constant declaration, but not definition
};

// we have to put this here, if we want to take the address of NumTunrns2, otherwise it would be a compilation error.
const int GamePlayer::NumTurns2; 
const double GamePlayer::NumTurns3=6.2;

int main(){

std::cout << " starts\n";

GamePlayer obj;
GamePlayer *pobj=new GamePlayer;
std::cout << pobj->NumTurns2 << std::endl;
std::cout << pobj->NumTurns3 << std::endl;

const int *pvar = &obj.NumTurns2;



std::cout << " finished!\n";

return 0;
}


