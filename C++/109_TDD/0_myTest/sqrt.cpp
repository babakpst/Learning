
#include <math.h>

double squareRoot(const double &a){

double b = sqrt(a);
if (b!=b) return -1; // NaN check
else return b ;
}
