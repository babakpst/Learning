

// based on pages 47-48 of the book: discoverinsg

// constructing vectors
#include <iostream>

//void vector_add(unsigned size, const double v1[], const double v2[], double s[]) // this won't allow modifications within the function
void vector_add(unsigned size, double v1[], double v2[], double s[])   // We can modify the vectors within the functions
//void vector_add(unsigned size, double &v1, double &v2, double &s)   // wrong, not working
{

for (unsigned i = 0; i < size; ++i)
{
s[i] = v1[i] +  v2[i];
}

v1[2] = 111;
v2[1] = 111;

}


void vector_add_pointer(const int size, double*& v1, double*& v2, double*& sum)
//void vector_add_pointer(const int size, const double*& v1, const double*& v2, const double*& sum)
//void vector_add_pointer(const int size, double* v1, double* v2, double* sum)
//void vector_add_pointer(const int size, double& v1, double& v2, double& sum)
{

for (int i = 0; i < size; ++i)
{
sum[i] = v1[i] +  v2[i];
}

v1[2] = 111;
v2[1] = 111;

}



int main ()
{

//===============================
int name= 12;
int &nickname=name;

std::cout << name<< "  " << nickname << "\n";

nickname =15;

std::cout << name<< "  "  << nickname << "\n";

//===============================

int var = 11;
//int &nvar;

//nvar =var;

//	std::cout << var<< "  "  << nvar << "\n";


double x[] =  {2, 3, 4}, y[] =  {4, 7, 12}, sum[3];

std::cout << " adding vectors: \n";
vector_add(3,x,y,sum);


for (unsigned i = 0; i < 3; ++i) std::cout<< " x=["<<i<<"]=" << x[i] << "\n";
std::cout<< "\n";
for (unsigned i = 0; i < 3; ++i) std::cout<< " y=["<<i<<"]=" << y[i] << "\n";
std::cout<< "\n"; 
for (unsigned i = 0; i < 3; ++i) std::cout<< " sum =["<<i<<"]=" << sum[i] << "\n";

std::cout << " ===================== \n";
int sizeOftheVector=3;
double *vec1=new double[sizeOftheVector],
       *vec2=new double[sizeOftheVector],
       *summation=new double[sizeOftheVector];


vec1[0] =99, vec1[1] =1519, vec1[2] =589;
vec2[0] =99, vec2[1] =159, vec2[2] =89;

std::cout << " adding vectors: \n";

vector_add_pointer(sizeOftheVector, vec1, vec2, summation);

for (unsigned i = 0; i < 3; ++i) std::cout<< " vec1=["<<i<<"]=" << vec1[i] << "\n";
std::cout<< "\n";
for (unsigned i = 0; i < 3; ++i) std::cout<< " vec2=["<<i<<"]=" << vec2[i] << "\n";
std::cout<< "\n"; 
for (unsigned i = 0; i < 3; ++i) std::cout<< " sum =["<<i<<"]=" << summation[i] << "\n";


  return 0;
}
