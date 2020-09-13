
#include "Mandelbrot.h"
#include <complex>
using namespace bob;
using namespace std;

Mandelbrot::Mandelbrot(/* args */) {}

Mandelbrot::~Mandelbrot() {}

int Mandelbrot::getIterations(double x, double y) {
  complex<double> z{0};
  complex<double> c(x, y);

  int iteration{0};

  while (iteration < MAX_ITERATIONS) {
    z = z * z + c;
    if (abs(z) > 2) {
      break;
    }
    ++iteration;
  }

  return iteration;
}