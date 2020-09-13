
#ifndef RGB_H
#define RGB_H

namespace bob {

struct RGB {
  double r;
  double g;
  double b;

  RGB(double r, double g, double b);
};
RGB operator-(const RGB &first, const RGB &second);
} // namespace bob
#endif // !RGB_H