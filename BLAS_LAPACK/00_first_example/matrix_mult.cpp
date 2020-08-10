
// babak poursartip

// 08/09/2020
extern "C"
{
#include <cblas.h>
}

#include <iostream>
#include <random>


int main ( int argc, char* argv[] ) {

    // Random numbers
    std::mt19937_64 rnd;
    std::uniform_real_distribution<double> doubleDist(0, 1);

    // Create arrays that represent the matrices A,B,C
    //const int n = 20;
    const int n = 3;
    double*  A = new double[n*n];
    double*  B = new double[n*n];
    double*  C = new double[n*n];

    // Fill A and B with random numbers
    for(uint i =0; i <n; i++){
        for(uint j=0; j<n; j++){
            A[i*n+j] = doubleDist(rnd);
            B[i*n+j] = doubleDist(rnd);
        }
    }

    // Calculate A*B=C
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);

    printf(" A: \n ");
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        printf(" %5.2f ", A[i*n+j]);
      }
      printf(" \n");
    }

    printf(" B: \n ");
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        printf(" %5.2f ", B[i*n+j]);
      }
      printf(" \n");
    }


    printf(" C: \n ");
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        printf(" %5.2f ", C[i*n+j]);
      }
      printf(" \n");
    }

    // Clean up
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
