

#ifndef ZOOM_H
#define ZOOM_H

namespace bob {

struct Zoom {
  // coordinate we want to zoom into
  int x{0};
  int y{0};
  double scale{0.0};
  Zoom(int x, int y, double scale) : x{x}, y{y}, scale{scale} {};
};

} // namespace bob

#endif // !ZOOM_H