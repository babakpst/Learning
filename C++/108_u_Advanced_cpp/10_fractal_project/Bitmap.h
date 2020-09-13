

#ifndef BITMAP_H
#define BITMAP_H

#include <cstdint> // to be able to refer to uint8_t
#include <iostream>
#include <memory>
#include <string>

using namespace std;
namespace bob {

class Bitmap {
private:
  int m_width{0};
  int m_height{0};
  unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
  Bitmap(int width, int height);
  void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
  bool write(string filename);

  virtual ~Bitmap();
};

} // namespace bob

#endif // !BITMAP_H