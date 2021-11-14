
/*
Babak Poursartip

10/23/2021

General Matrix Multiplication

*/


#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <iomanip> 
//#include <math>


#define alpha( i,j ) A[ (j)*ldA + i ]   // map alpha( i,j ) to array A 
#define beta( i,j )  B[ (j)*ldB + i ]   // map beta( i,j )  to array B
#define gamma( i,j ) C[ (j)*ldC + i ]   // map gamma( i,j ) to array C

template<typename T>
void fillMatrix(std::vector<T> mat, int val)
{
for_each(begin(mat), end(mat), [val](T& e){e = (T)val;});
}


// 1: IJK
template<typename T>
void GEMM_IJK(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int i=0; i<m; i++ )
    for ( int j=0; j<n; j++ )
      for ( int p=0; p<k; p++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 2: IKJ
template<typename T>
void GEMM_IKJ(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int i=0; i<m; i++ )
    for ( int p=0; p<k; p++ )
      for ( int j=0; j<n; j++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 3: KIJ
template<typename T>
void GEMM_KIJ(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int p=0; p<k; p++ )
    for ( int i=0; i<m; i++ )
      for ( int j=0; j<n; j++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 4: JIK
template<typename T>
void GEMM_JIK(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int j=0; j<n; j++ )
    for ( int i=0; i<m; i++ )
      for ( int p=0; p<k; p++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 5: JKI
template<typename T>
void GEMM_JKI(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int j=0; j<n; j++ )
    for ( int p=0; p<k; p++ )
      for ( int i=0; i<m; i++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 6: KJI
template<typename T>
void GEMM_KJI(int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> &C, int ldC)
{
  for ( int p=0; p<k; p++ )
    for ( int j=0; j<n; j++ )
      for ( int i=0; i<m; i++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}


template<typename T>
void Gemm_PJI( int m, int n, int k, T* A, int ldA, T* B, int ldB,  T* C, int ldC )
{
  for ( int p=0; p<k; p++ )
    for ( int j=0; j<n; j++ )
      for ( int i=0; i<m; i++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}

// 7: KJI
template<typename T>
void GEMM_JIP_PJI(const int MB, const int NB, const int KB, int m, int n, int k, std::vector<T> &A, int ldA, std::vector<T> &B, int ldB, std::vector<T> C, int ldC)
{
  for ( int j=0; j<n; j+=NB ){
    int jb = std::min( n-j, NB );    /* Size for "finge" block */ 
    for ( int i=0; i<m; i+=MB ){
      int ib = std::min( m-i, MB );    /* Size for "finge" block */ 
      for ( int p=0; p<k; p+=KB ){ 
        int pb = std::min( k-p, KB );    /* Size for "finge" block */ 
        Gemm_PJI<T>( ib, jb, pb, &alpha( i,p ), ldA, &beta( p,j ), ldB, &gamma( i,j ), ldC );
      }
    }
  }
}





//==============================
int main()
{

std::cout << "====== GEMM: General Matrix Multiplication \n";

//typedef std::chrono::steady_clock clock;
typedef std::chrono::high_resolution_clock clock;
typedef int Type;

const int SIZE = 10;
// sizes
long m = 1<<SIZE;
long n = 1<<SIZE;
long k = 1<<SIZE;

long ldA = m;
long ldB = k;
long ldC = m;

long sizeA = m*k;
long sizeB = k*n;
long sizeC = m*n;

long gflops = 2 * m * n * k * 1e-09;;

// define arrays/matrices
// integer vector
std::vector<Type> A(sizeA);
std::vector<Type> B(sizeB);
std::vector<Type> C(sizeC);

// fill matrices
fillMatrix<Type>(A,1);
fillMatrix<Type>(B,1);

//GEMM calls
clock::time_point start;
clock::time_point end;

// 1: IJK
std::cout << "1: IJK ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_IJK<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_IJK = end - start;
std::cout << " Done. \n";

// 2: IKJ
std::cout << "2: IKJ ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_IKJ<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_IKJ = end - start;
std::cout << " Done. \n";

// 3: KIJ
std::cout << "3: KIJ ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_KIJ<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_KIJ = end - start;
std::cout << " Done. \n";

// 4: JIK
std::cout << "4: JIK ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_JIK<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_JIK = end - start;
std::cout << " Done. \n";

// 5: JKI
std::cout << "5: JKI ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_JKI<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_JKI = end - start;
std::cout << " Done. \n";

// 6: KJI
std::cout << "6: KJI ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_KJI<Type>(m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_KJI = end - start;
std::cout << " Done. \n";

// 7: blocked JIP_PJI
const int MB = 8;
const int NB = 8;
const int KB = 8;
std::cout << "7: JIP_PJI ... " << std::flush;
fillMatrix<Type>(C,1);
start = clock::now();
GEMM_JIP_PJI<Type>(MB, NB, KB, m, n, k, A, ldA, B, ldB, C, ldC);
end = clock::now();
std::chrono::duration<double, std::milli> elapsed_JIK_KJI = end - start;
std::cout << " Done. \n";


std::cout << "\n mehtod   time(ms)   tflops \n"
          << "1-IJK    " << std::setprecision(8) << elapsed_IJK.count() << "   " << std::setprecision(4) << gflops/(elapsed_IJK.count()*1e-3) << std::endl
          << "2-IKJ    " << std::setprecision(8) << elapsed_IKJ.count() << "   " << std::setprecision(4) << gflops/(elapsed_IKJ.count()*1e-3) << std::endl
          << "3-KIJ    " << std::setprecision(8) << elapsed_KIJ.count() << "   " << std::setprecision(4) << gflops/(elapsed_KIJ.count()*1e-3) << std::endl
          << "4-JIK    " << std::setprecision(8) << elapsed_JIK.count() << "   " << std::setprecision(4) << gflops/(elapsed_JIK.count()*1e-3) << std::endl
          << "5-JKI    " << std::setprecision(8) << elapsed_JKI.count() << "   " << std::setprecision(4) << gflops/(elapsed_JKI.count()*1e-3) << std::endl
          << "6-KJI    " << std::setprecision(8) << elapsed_KJI.count() << "   " << std::setprecision(4) << gflops/(elapsed_KJI.count()*1e-3) << std::endl
          << "7-blocked    " << std::setprecision(8) << elapsed_JIK_KJI.count() << "   " << std::setprecision(4) << gflops/(elapsed_JIK_KJI.count()*1e-3) << std::endl;

std::cout << " end.\n";
return 0;
}
