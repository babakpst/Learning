

#include "Rec_cls.h"

Rectangle::Rectangle(int a, int b) : Polygon(a, b) {}
Rectangle::~Rectangle() { std::cout << " destructor of Rec_cls \n"; }

int Rectangle::area() { return width * height; }
