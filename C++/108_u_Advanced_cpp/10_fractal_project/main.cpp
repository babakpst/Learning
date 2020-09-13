
// Babak Poursartip
// 09/12/2020

// Udemy: Advanced c++
// m_bitmap files

#include <cstdint>
#include <iostream>
#include <math.h>

#include "FractalCreator.h"
#include "Zoom.h"

using namespace std;
using namespace bob;

//====================================================
int main() {
  cout << " starts \n";

  FractalCreator fractalCreator(800, 600);

  fractalCreator.addRange(0.0, RGB(0, 0, 0));
  fractalCreator.addRange(0.3, RGB(255, 0, 0));
  fractalCreator.addRange(0.5, RGB(255, 255, 0));
  fractalCreator.addRange(1.0, RGB(255, 255, 255));

  fractalCreator.addZoom(Zoom(295, 202, 0.1));
  fractalCreator.addZoom(Zoom(312, 304, 0.1));
  fractalCreator.run("test.bmp");

  cout << " \n ends\n";

  return 0;
}
