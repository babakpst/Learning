
// Babak Poursartip
// The code is borrowed from
// https://stackoverflow.com/questions/885937/what-is-the-difference-between-association-aggregation-and-composition

#include <iostream>
using namespace std;
/********************** Engine Class ******************/
class Engine {
  int nEngineNumber;

public:
  Engine(int nEngineNo);
  ~Engine(void);
};
Engine::Engine(int nEngineNo) { cout << " Engine :: Constructor " << endl; }
Engine::~Engine(void) { cout << " Engine :: Destructor " << endl; }

/********************** Car Class ******************/
class Car {
  int nCarColorNumber;
  int nCarModelNumber;
  Engine objEngine;

public:
  Car(int, int, int);
  ~Car(void);
};
Car::Car(int nModelNo, int nColorNo, int nEngineNo)
    : nCarModelNumber(nModelNo), nCarColorNumber(nColorNo),
      objEngine(nEngineNo) {
  cout << " Car :: Constructor " << endl;
}
Car::~Car(void) { cout << " Car :: Destructor " << endl; }

/********************** Bus Class ******************/
class Bus {
  int nBusColorNumber;
  int nBusModelNumber;
  Engine *ptrEngine;

public:
  Bus(int, int, int);
  ~Bus(void);
};
Bus::Bus(int nModelNo, int nColorNo, int nEngineNo)
    : nBusModelNumber(nModelNo), nBusColorNumber(nColorNo) {
  ptrEngine = new Engine(nEngineNo);
  cout << " Bus :: Constructor " << endl;
}
Bus::~Bus(void) {
  cout << " Bus :: Destructor " << endl;
  delete ptrEngine;
}

/********************** Main Function ******************/
int main() {
  freopen("composition.Log", "w", stdout);
  cout << "--------------- Start Of Program --------------------" << endl;
  // Composition using simple Engine in a car object
  {
    cout << "------------- Inside Car Block ------------------" << endl;
    Car objCar(1, 2, 3);
  }
  cout << "------------- Out of Car Block ------------------" << endl;
  // Composition using pointer of Engine in a Bus object
  {
    cout << "------------- Inside Bus Block ------------------" << endl;
    Bus objBus(11, 22, 33);
  }
  cout << "------------- Out of Bus Block ------------------" << endl;
  cout << "--------------- End Of Program --------------------" << endl;
  fclose(stdout);
}
