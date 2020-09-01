// from Cherno
// 08/31/2020

#include <iostream>
#include <string>

template <typename T, int N> class Array {
private:
  T arr[N];

public:
  int getSize() const { return N; }
};

// ==============================
int main() {

  Array<std::string, 5> mine;
  std::cout << mine.getSize() << std::endl;
}