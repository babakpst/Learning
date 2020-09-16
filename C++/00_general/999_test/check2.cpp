
#include <iostream>

using namespace std;

class Point {
  int xcoor, ycoor;

public:
  Point(int i = 0, int j = 0) {
    xcoor = i;
    ycoor = j;
  }
  int getX() const { return xcoor; }
  int getY() { return ycoor; }
};

int main() {
  const Point pnt_1;
  cout << pnt_1.getX() << endl;

  Point pnt_2;
  cout << pnt_2.getY() << endl;

  int xcoordinate = pnt_2.getX();
  cout << xcoordinate << endl;

  return 0;
}