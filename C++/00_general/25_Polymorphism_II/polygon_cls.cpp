
#include "polygon_cls.h"

Polygon::Polygon(int a, int b) : width(a), height(b) {}
Polygon::~Polygon() { std::cout << " destructor of polygon \n"; }

// virtual int Polygon::area (void) =0;

void Polygon::printarea() { cout << this->area() << '\n'; }
