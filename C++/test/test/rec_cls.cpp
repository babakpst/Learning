#include "stdafx.h"
#include "rec_cls.h"

void Rectangle_cls::set_values(int a, int b) {
	width = a;
	height = b;
}

int Rectangle_cls::area() {
	return (width * height);
};
