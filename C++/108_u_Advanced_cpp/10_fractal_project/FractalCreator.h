

#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <Zoom.h>
#include <assert.h>
#include <memory>
#include <string>
#include <vector>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "Zoom.h"
#include "ZoomList.h"

using namespace std;
using namespace bob;

namespace bob {

class FractalCreator {
private:
  int m_width;
  int m_height;

  int m_total{0};

  unique_ptr<int[]> m_histogram;
  // holds no. of iteration for each pixel.
  unique_ptr<int[]> m_fractal;

  Bitmap m_bitmap;

  ZoomList m_zoomList;

  vector<int> m_ranges;
  vector<RGB> m_colors;
  vector<int> m_rangeTotals;

  bool m_bGotFirstRange{false};

private:
  void caclulateIteration();
  void drawFractal();
  void calculateTotalIterations();
  void calculateRangeTotals();
  void writeBitmap(std::string name);

public:
  FractalCreator(int width, int height);
  ~FractalCreator();

  int getRange(int iterations) const;

  void addRange(double rangeEnd, const RGB &rgb);
  void addZoom(const Zoom &zoom);
  void run(string name);
};

} // namespace bob
#endif // !FRACTALCREATOR_H
