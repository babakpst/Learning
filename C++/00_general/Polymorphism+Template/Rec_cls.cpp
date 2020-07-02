

#include "Rec_cls.h"


Rectangle::Rectangle(int a,int b):Polygon(a,b) {}


int Rectangle::area()
      { return width*height; }
