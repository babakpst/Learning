

// based on pages 47-48 of the book: discoverinsg

// constructing vectors
#include <iostream>

//=======================================================================
// void vector_add(unsigned size, const double v1[], const double v2[], double
// s[]) // this won't allow modifications within the function
void vector_add(unsigned size, double v1[], double v2[],
                double s[]) // We can modify the vectors within the functions
// void vector_add(unsigned size, double &v1, double &v2, double &s)   // wrong,
// not working
{

  std::cout << " inside the vector_add" << v1[1] << std::endl;
  for (unsigned i = 0; i < size; ++i)
    s[i] = v1[i] + v2[i];

  v1[2] = 111;
  v2[1] = 111;
}

//=======================================================================
// These pointer are exactly the same as the pointers in the main code.
void vector_add_by_reference2(const int size, const double *const &v1,
                              const double *const &v2, double *const &sum) {

  double *pNew;
  double dummy = 12.4;
  pNew = &dummy;
  std::cout << " new pointer: " << pNew << " " << *pNew << std::endl;
  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  // v1 = pNew; // due to the second const
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2]
            << std::endl;
  for (int i = 0; i < size; ++i)
    sum[i] = v1[i] + v2[i];

  // v1[2] = 111; // error due to first const

  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2]
            << std::endl;
}

//=======================================================================
// These pointer are exactly the same as the pointers in the main code.
void vector_add_by_reference(const int size, double *&v1, double *&v2,
                             double *&sum) {

  double *pNew;
  double dummy = 12.4;
  pNew = &dummy;
  std::cout << " new pointer: " << pNew << " " << *pNew << std::endl;
  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  v1 = pNew;
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2]
            << std::endl;
  for (int i = 0; i < size; ++i)
    sum[i] = v1[i] + v2[i];

  v1[2] = 111;

  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2]
            << std::endl;
}

//=======================================================================
// make a copy of the pointers, if you change the memory that the pointer is
// referring to, you do not see the changes in the main code.
void vector_add_by_value(const int size, double *v1, double *v2, double *sum) {

  double *pNew;
  double dummy = 12.4;
  pNew = &dummy;
  std::cout << " new pointer: " << pNew << " " << *pNew << std::endl;
  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  v1 = pNew;
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2] << std::endl;
  for (int i = 0; i < size; ++i)
    sum[i] = v1[i] + v2[i];

  v1[2] = 111;

  std::cout << " v1 pointer: " << v1 << " " << *v1 << std::endl;
  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2] << std::endl;
}


//=======================================================================
// make a copy of the pointers, if you change the memory that the pointer is
// referring to, you do not see the changes in the main code.
void vector_add_by_value2(const int size, const double *v1, const double *v2, double *sum) {

  std::cout << " v1 pointer: " << v1[0] << "  " << v1[1] << "  " << v1[2] << std::endl;
  std::cout << " v2 pointer: " << v2[0] << "  " << v2[1] << "  " << v2[2] << std::endl;
  for (int i = 0; i < size; ++i)
    sum[i] = v1[i] + v2[i];


  std::cout << " sum pointer: " << sum[0] << "  " << sum[1] << "  " << sum[2] << std::endl;
}

// =======================================================================
int main() {

  //===============================
  int name = 12;
  int &nickname = name;

  std::cout << name << "  " << nickname << "\n";

  nickname = 15;

  std::cout << name << "  " << nickname << "\n";

  //===============================

  // int var = 11;
  // int &nvar;
  // nvar =var;

  //	std::cout << var<< "  "  << nvar << "\n";
  std::cout << " 1===================== \n";
  std::cout << " adding vectors: \n";
  double x[] = {2, 3, 4}, y[] = {4, 7, 12}, sum[3];

  for (unsigned i = 0; i < 3; ++i)
    std::cout << " x=[" << i << "]=" << x[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " y=[" << i << "]=" << y[i] << "\n";
//   for (unsigned i = 0; i < 3; ++i) std::cout<< " sum =["<<i<<"]=" << sum[i] << "\n";

  vector_add(3, x, y, sum);

  for (unsigned i = 0; i < 3; ++i)
    std::cout << " x=[" << i << "]=" << x[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " y=[" << i << "]=" << y[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " sum =[" << i << "]=" << sum[i] << "\n";

  std::cout << "2 ===================== \n";
  int sizeOftheVector = 3;
  double *vec1 = new double[sizeOftheVector],
         *vec2 = new double[sizeOftheVector],
         *summation = new double[sizeOftheVector];

  vec1[0] = 99.1, vec1[1] = 1519.2, vec1[2] = 589.3;
  vec2[0] = 90, vec2[1] = 159, vec2[2] = 89;
  summation[0] = 190, summation[1] = 1059, summation[2] = 189;

  std::cout << " adding vectors pointer: \n";
  std::cout << " before \n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec1=[" << i << "]=" << vec1[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec2=[" << i << "]=" << vec2[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " sum =[" << i << "]=" << summation[i] << "\n";

  vector_add_by_reference(sizeOftheVector, vec1, vec2, summation);


  std::cout << " after reference\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec1=[" << i << "]=" << vec1[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec2=[" << i << "]=" << vec2[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " sum =[" << i << "]=" << summation[i] << "\n";

  vector_add_by_value(sizeOftheVector, vec1, vec2, summation);
  std::cout << " 3===================== \n";
  std::cout << " after by value \n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec1=[" << i << "]=" << vec1[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec2=[" << i << "]=" << vec2[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " sum =[" << i << "]=" << summation[i] << "\n";
  //delete[] vec1, vec2, summation;


  std::cout << " 4===================== \n";
  double *vec11 = new double[sizeOftheVector],
         *vec21 = new double[sizeOftheVector],
         *sum2 = new double[sizeOftheVector];

  vec11[0] = 100.1, vec11[1] = 100.2, vec11[2] = 100.3;
  vec21[0] = 200.1, vec21[1] = 200.2, vec21[2] = 200.3;

  vector_add_by_value2(sizeOftheVector, vec11, vec21, sum2);


  std::cout << " after by value2 \n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec1=[" << i << "]=" << vec11[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " vec2=[" << i << "]=" << vec21[i] << "\n";
  for (unsigned i = 0; i < 3; ++i)
    std::cout << " sum =[" << i << "]=" << sum2[i] << "\n";

  return 0;
}
