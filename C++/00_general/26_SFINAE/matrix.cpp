
/*

Babak Poursartip
11/20/2021

type_traits type traits

source: modern C++ book, page: 230

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <typeinfo>

// =================================================================================================
template<typename sizeT, typename valueT>
class matrix
{
  public:
    using value_type = valueT;
    using size_type = sizeT;

    matrix(const sizeT& nRow, const sizeT& nCol, const valueT& init)
    {
      valueT val = init;
      Mat.resize(nRow);
      
      auto initialize = [&](auto &row)
      {
        row.resize(nCol,val);
        val++;
      };
      for_each(begin(Mat), end(Mat), initialize);
    }

    void print()
    {
      std::cout << " here is the matrix: \n";
      auto pRow = [](const std::vector<valueT>& row)
      {
        auto pElement = [](const valueT& elem)
        {
          std::cout << elem << " ";
        };
        for_each(begin(row), end(row), pElement);  
        std::cout << std::endl;
      };
      
      for_each(begin(Mat), end(Mat), pRow);
    }

    value_type& operator()(size_type r, size_type c){ return Mat[r][c];}
    const value_type& operator()(size_type r, size_type c) const { return Mat[r][c];}

  private:
    std::vector<std::vector<valueT>>  Mat;
};


// =================================================================================================
// transpose
template <typename Matrix>
class transposed_view
{
  public:
    using value_type=typename Matrix::value_type;
    using size_type=typename Matrix::size_type;

    explicit transposed_view(Matrix& A): ref(A){}
    value_type& operator()(size_type r, size_type c){ return ref(c,r);}
    const value_type& operator()(size_type r, size_type c) const { return ref(c,r);}
  private:
    Matrix& ref;
};

// =================================================================================================
template<typename Matrix>
inline transposed_view<Matrix> trans(Matrix& A)
{
  return transposed_view<Matrix>(A);
}

// =================================================================================================
int main()
{
  using std::cout, std::endl;

  cout << " starts here \n";
  matrix<int, float> ifMatrix(3,4,2.1);
  ifMatrix.print();
  
  transposed_view<matrix<int,float>> ifMatrixTrans(ifMatrix);
  std::cout << "\n A: " << ifMatrix(1,2) << " AT: " << ifMatrixTrans(1,2) << std::endl;

  matrix<uint, double> udMatrix(4,6,3.2);
  udMatrix.print();
  
  transposed_view<matrix<uint,double>> udMatrixTrans(udMatrix);
  std::cout << "\n A: " << udMatrix(1,2) << " AT: " << udMatrixTrans(1,2) << std::endl;  
 
  const matrix<uint, double> udMatrix2(4,6,3.2);
  const transposed_view<const matrix<uint,double>> udMatrixTrans2(udMatrix2); // should be const, otherwise we get error
  
  cout << " trans (udMatrix) is:  " << typeid(trans(udMatrix)).name()  << endl;
  cout << " trans (udMatrix2) is: " << typeid(trans(udMatrix2)).name() << endl;

  //cout << "\n A: " << udMatrix2(1,2) << " AT: " << trans(udMatrix2)(1,2) << endl;  // error of constantness.
  cout << "\n A: " << udMatrix2(1,2) << " AT: " << udMatrixTrans2(1,2) << endl;  
  
 
 
  //const matrix<int, std::complex<double>> icMatrix(5,6,(2.1,3.1));
  //transposed_view<matrix<int, std::complex<double>>> icMatrixTrans(icMatrix);
  //std::cout << "\n A: " << icMatrix(1,2) << " AT: " << transposed_view<matrix<int, std::complex<double>>>(icMatrix)(1,2) << std::endl;  

 
  cout << " End. \n";
  return 0;
}