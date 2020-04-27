// Babak Poursartip
// 03/21/2020


#include <iostream>
using namespace std;

extern"C" {
void fortran_sub_(int *ii, float *ff);
}

main()
{

 int ii=5;
 float ff=5.5;

 fortran_sub_(&ii, &ff);

 return 0;
}
