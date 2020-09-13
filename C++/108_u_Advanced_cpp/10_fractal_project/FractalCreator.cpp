
#include "FractalCreator.h"

namespace bob {

void FractalCreator::run(string name) {

  caclulateIteration();
  calculateTotalIterations();
  calculateRangeTotals();
  drawFractal();
  writeBitmap(name);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
  m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
  m_colors.push_back(rgb);

  if (m_bGotFirstRange) {
    m_rangeTotals.push_back(0);
  }
  m_bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const {
  int range = 0;

  for (int i = 1; i < m_ranges.size(); i++) {
    range = i;
    if (m_ranges[i] > iterations)
      break;
  }
  range--;
  assert(range > -1); // asserts only works in the debug mode.
  assert(range < m_ranges.size());
  return range;
}

void FractalCreator::addZoom(const Zoom &zoom) { m_zoomList.add(zoom); }

FractalCreator::FractalCreator(int width, int height)
    : m_width{width}, m_height{height},
      m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
      m_fractal(new int[m_width * m_height]{0}), m_bitmap(m_width, m_height),
      m_zoomList(m_width, m_height) {
  m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

FractalCreator::~FractalCreator() {}

void FractalCreator::caclulateIteration() {
  for (int x = 0; x < m_width; ++x) {
    for (int y = 0; y < m_height; ++y) {

      // double xFractal{2.0 * i / m_width - 1 - 0.5};
      // double yFractal{2.0 * j / m_height - 1};
      // double xFractal{(i - m_width / 2 - 200) * 2.0 / m_height};
      // double yFractal{(j - m_height / 2) * 2.0 / m_height};
      pair<double, double> coords = m_zoomList.doZoom(x, y);

      // int iteration = Mandelbrot::getIterations(xFractal, yFractal);
      int iteration = Mandelbrot::getIterations(coords.first, coords.second);

      m_fractal[y * m_width + x] = iteration;
      if (iteration != Mandelbrot::MAX_ITERATIONS)
        m_histogram[iteration]++;
    }
  }
}
void FractalCreator::drawFractal() {

  // RGB startColor(0, 0, 0);
  // RGB endColor(0, 0, 255);
  // RGB colorDiff = endColor - startColor;

  for (int x = 0; x < m_width; ++x) {
    for (int y = 0; y < m_height; ++y) {

      uint8_t red = 0;
      uint8_t green = 0;
      uint8_t blue = 0;

      int iteration = m_fractal[y * m_width + x];

      int range = getRange(iteration);
      int rangeTotal = m_rangeTotals[range];
      int m_rangeStart = m_ranges[range];

      RGB &startColor = m_colors[range];
      RGB &endColor = m_colors[range + 1];

      RGB colorDiff = endColor - startColor;

      if (iteration != Mandelbrot::MAX_ITERATIONS) {

        // optimize here
        int totalPixels = 0;
        for (int i = m_rangeStart; i <= iteration; i++) {
          totalPixels += m_histogram[i];
        }

        // green = pow(255, hue);
        // green = 255 * hue;
        red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
        green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
        blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;

        m_bitmap.setPixel(x, y, red, green, blue);
      }
    }
  }
}

void FractalCreator::calculateRangeTotals() {

  int rangeIndex = 0;

  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
    int pixels = m_histogram[i];
    if (i >= m_ranges[rangeIndex + 1]) {
      rangeIndex++;
    }
    m_rangeTotals[rangeIndex] += pixels;
  }
}

void FractalCreator::calculateTotalIterations() {
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
    m_total += m_histogram[i];
  }
}

void FractalCreator::writeBitmap(std::string name) { m_bitmap.write(name); }

} // namespace bob