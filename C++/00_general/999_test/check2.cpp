#include <iostream>
using namespace std;
class Point {
  int x, y;

public:
  Point(int i = 0, int j = 0) {
    x = i;
    y = j;
  }
  int getX() const { return x; }
  int getY() { return y; }
};

int main() {
  const Point t;
  cout << t.getX() << " ";
  cout << t.getY();
  return 0;
}