
// Babak Poursartip
// 09/12/2020

#ifndef BitmapFileHeader_H
#define BitampFileHeader_H

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace bob {
struct BitmapFileHeader {
  char header[2]{'B', 'M'};
  int32_t fileSize; // we need 32 bit, so to guarantee that we use int32
  int32_t reserved{0};
  int32_t dataOffset;
};
} // namespace bob

#endif // !BitmapFileHeader_H
