
// Babak Poursartip
// 03/21/2020 Happy Norouz

#include <stdio.h>

void test_for_(int *, double *, double *, int *);


int main()
{

int i=1, ny=3;

double x=3.14159;
double y[]={1.1, 2.2, 3.3};

printf("C calling Fortran subroutine, passing\n");

printf("i=%d, x=%g\n", i,x);
printf("y[]=%g,%g,%g\n",y[0],y[1],y[2]);

test_for_(&i, &x, y, &ny);

return 0;
}

