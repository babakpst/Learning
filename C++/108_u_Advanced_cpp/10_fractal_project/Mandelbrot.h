
#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace bob {

class Mandelbrot {
private:
public:
  static const int MAX_ITERATIONS = 10000;

public:
  Mandelbrot(/* args */);
  virtual ~Mandelbrot();

  static int getIterations(double x, double y);
};

} // namespace bob

#endif // !MANDELBROT_H