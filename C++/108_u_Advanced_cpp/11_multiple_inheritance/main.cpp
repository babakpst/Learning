

// Babak Poursartip
// 09/13/2020

// Udemy: Advanced c++
// multiple inheritance

#include <iostream>

using namespace std;

class MusicalInstrument {
public:
  virtual void play() { cout << " Playing instrument ...\n"; }
  virtual void reset() { cout << " Reseting instrument ... \n"; }
  virtual ~MusicalInstrument(){};
};
class Machine {
public:
  virtual void start() { cout << " Starting machine .. \n"; }
  virtual void reset() { cout << " Resetting machine ... \n"; }
  virtual ~Machine(){};
};

class Synthesizer : public Machine, public MusicalInstrument {
public:
  virtual ~Synthesizer(){};
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  Synthesizer *pSynth = new Synthesizer();

  pSynth->play();
  pSynth->start();
  pSynth->MusicalInstrument::reset();
  pSynth->Machine::reset();

  delete pSynth;

  cout << " \n ends\n";

  return 0;
}
