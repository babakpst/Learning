

/*
Babak Poursartip

Checking the installation of MPI

07/15/2020

*/

#include <iterator>
#include <mpi.h>
#include <stdio.h>
#include <vector>

struct var_list {
  int ivar1, ivar2;
  float fvar1, fvar2;
  std::vector<int> myVec;
  char *name;
};

struct var_list2 {

  float fvar1, fvar2;

  int ivar1, ivar2, nvar1, nvar2;

  // int nvar1, nvar2;
  // char *name;
};

struct var_list3 {

  float fvar1, fvar2;

  int ivar1, ivar2, nvar1, nvar2;

  int *myVec;
  // char *name;
};

int main(int argc, char **argv) {

  int rank, size;
  int buf;
  const int root = 0;

  MPI_Comm comm = MPI_COMM_WORLD;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);

  // example 1 =================================================================
  if (rank == root) {
    buf = 777;
  }

  printf(" EX 1- [%d/%d]: Before Bcast, buf is %d\n", rank, size, buf);
  fflush(stdout);

  /* everyone calls bcast, data is taken from root and ends up in everyone's buf
   */
  MPI_Bcast(&buf, 1, MPI_INT, root, comm);

  printf(" EX 1- [%d/%d]: After Bcast, buf is %d\n", rank, size, buf);
  fflush(stdout);
  printf("<<<<<< END EXAMPLE 1 >>>>>>>\n\n");
  fflush(stdout);

  // example 2 =================================================================
  MPI_Barrier(comm);
  std::vector<int> myVect;

  myVect.resize(20); // should be resized for all threads

  printf(" EX 2- [%d/%d]: Before Bcast vector, buf is %d\n", rank, size,
         myVect[5]);
  fflush(stdout);
  if (rank == root) {

    int i = 1;
    for (std::vector<int>::iterator it = myVect.begin(); it != myVect.end();
         ++it) {
      *it = i++;
    }
  }

  MPI_Bcast(&myVect[0], myVect.size(), MPI_INT, root, comm);

  printf(" EX 2- [%d/%d]: After Bcast vector, buf is %d\n", rank, size,
         myVect[5]);
  fflush(stdout);

  printf("<<<<<< END EXAMPLE 2 >>>>>>>\n\n");
  fflush(stdout);

  // example 7 =================================================================
  MPI_Barrier(comm);
  int narr = 10;
  int *arr;
  arr = (int *)malloc(narr * sizeof(int));

  /*
  printf(" EX 7- [%d/%d]: Before Bcast vector, buf is %d\n", rank, size,
         arr[5]);
  fflush(stdout);
  */
  for (int i = 0; i < narr; ++i)
    arr[i] = rank;

  if (rank == root) {
    int i = 1;
    for (int i = 0; i < narr; ++i)
      arr[i] = i;
  }
  printf(" EX 7 - [%d/%d]: BEFORE vec: ", rank, size);
  fflush(stdout);
  for (int i = 0; i < narr; ++i) {
    printf(" %d ", arr[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);

  MPI_Bcast(arr, narr, MPI_INT, root, comm);

  printf(" EX 7 - [%d/%d]: AFTER vec: ", rank, size);
  fflush(stdout);
  for (int i = 0; i < narr; ++i) {
    printf(" %d ", arr[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);

  printf("<<<<<< END EXAMPLE 2 >>>>>>>\n\n");
  fflush(stdout);

  free(arr);
  // example 3 =================================================================
  MPI_Barrier(comm);

  var_list2 v2, *vl2 = &v2; // defining the pointer to the struct var_list

  if (rank == root) {
    // filling out the struct
    vl2->ivar1 = 10;
    vl2->ivar2 = 12;

    vl2->nvar1 = 812;
    vl2->nvar2 = 813;

    vl2->fvar1 = 110.1;
    vl2->fvar2 = 112.2;
  }

  printf("EX 3 - [%d/%d]: BEFORE %d, %d, %f, %f - %d, %d \n", rank, size,
         vl2->ivar1, vl2->ivar2, vl2->fvar1, vl2->fvar2, vl2->nvar1,
         vl2->nvar2);
  fflush(stdout);

  MPI_Bcast(vl2, sizeof(var_list2), MPI_BYTE, root, comm);

  printf("EX 3 - [%d/%d]: AFTER  %d, %d, %f, %f - %d, %d \n", rank, size,
         vl2->ivar1, vl2->ivar2, vl2->fvar1, vl2->fvar2, vl2->nvar1,
         vl2->nvar2);
  fflush(stdout);

  printf("<<<<<< END EXAMPLE 3 >>>>>>>\n\n");
  fflush(stdout);

  // example 4 MPI_BYTE ========================================================
  MPI_Barrier(comm);

  printf(" \n\n [%d/%d]: MPI_BYTE\n", rank, size);
  fflush(stdout);

  if (rank == root) {
    buf = 999;
  }
  printf("[%d/%d]: Before Bcast, buf is %d\n", rank, size, buf);
  fflush(stdout);
  MPI_Barrier(comm);

  /* everyone calls bcast, data is taken from root and ends up in everyone's buf
   */
  MPI_Bcast(&buf, sizeof(int), MPI_BYTE, root, comm);

  printf("[%d/%d]: After Bcast, buf is %d\n", rank, size, buf);
  fflush(stdout);
  printf("<<<<<< END EXAMPLE 4 >>>>>>>\n\n");
  fflush(stdout);

  // example 5 =================================================================
  MPI_Barrier(comm);
  var_list v, *vl = &v; // defining the pointer to the struct var_list

  vl->myVec.resize(10);

  if (rank == root) {
    // filling out the struct
    vl->ivar1 = 10;
    vl->ivar2 = 12;

    vl->fvar1 = 110.1;
    vl->fvar2 = 112.2;

    int i = 0;
    for (std::vector<int>::iterator it = vl->myVec.begin();
         it != vl->myVec.end(); ++it) {
      *it = i++;
    }

    printf("EX 5 [%d/%d]: - BEFORE vector: ", rank, size);
    fflush(stdout);
    for (std::vector<int>::iterator it = vl->myVec.begin();
         it != vl->myVec.end(); ++it) {
      printf(" %d ", *it);
      fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
  }

  printf("EX 5 - [%d/%d]: BEFORE %d, %d, %f, %f \n", rank, size, vl->ivar1,
         vl->ivar2, vl->fvar1, vl->fvar2);
  fflush(stdout);
  /*
  MPI_Bcast(vl, sizeof(var_list), MPI_BYTE, root, comm);

      printf("EX 5 - [%d/%d]: AFTER  %d, %d, %f, %f \n", rank, size, vl->ivar1,
             vl->ivar2, vl->fvar1, vl->fvar2);
      fflush(stdout);

      printf("EX 5 - [%d/%d]: AFTER vector: \n", rank, size);
      fflush(stdout);

      for (std::vector<int>::iterator it = vl->myVec.begin(); it !=
      vl->myVec.end();
           ++it) {
        printf(" %d ", *it);
        fflush(stdout);
      }
      printf("\n");
      fflush(stdout);
  */

  printf("<<<<<< END EXAMPLE 5 >>>>>>>\n\n");
  fflush(stdout);

  // example 6 =================================================================

  // This section is not working, due to the pointer allocation within the
  // struct

  MPI_Barrier(comm);
  var_list3 v3, *vl3 = &v3; // defining the pointer to the struct var_list
  int n = 10;
  vl3->myVec = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; ++i)
    vl3->myVec[i] = rank;

  if (rank == root) {
    // filling out the struct
    vl3->ivar1 = 123;
    vl3->ivar2 = 456;

    vl3->fvar1 = 123.114;
    vl3->fvar2 = 456.234;

    for (int i = 0; i < n; ++i)
      vl3->myVec[i] = i;
  }

  printf("EX 6 - [%d/%d]: BEFORE %d, %d, %f, %f \n", rank, size, vl3->ivar1,
         vl3->ivar2, vl3->fvar1, vl3->fvar2);
  fflush(stdout);

  printf("EX 6 [%d/%d]: - BEFORE vector: ", rank, size);
  fflush(stdout);
  for (int i = 0; i < n; ++i) {
    printf(" %d ", vl3->myVec[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);

  MPI_Bcast(vl3, sizeof(var_list3), MPI_BYTE, root, comm);
  // MPI_Bcast(vl3->myVec, n, MPI_INT, root, comm);
  // MPI_Bcast(vl3->myVec, n * sizeof(int), MPI_BYTE, root, comm);

  printf("EX 6 - [%d/%d]: AFTER  %d, %d, %f, %f \n", rank, size, vl3->ivar1,
         vl3->ivar2, vl3->fvar1, vl3->fvar2);
  fflush(stdout);

  printf("EX 6 - [%d/%d]: AFTER vector: \n", rank, size);
  fflush(stdout);
  for (int i = 0; i < n; ++i) {
    printf(" %d ", vl3->myVec[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);

  printf("<<<<<< END EXAMPLE 6 >>>>>>>\n\n");
  fflush(stdout);

  // free(vl3->myVec);

  // ===========================================================================
  // ===========================================================================
  printf(" \n\n [%d/%d]: SUCCESSFUL EXECUTION! \n", rank, size);
  fflush(stdout);
  MPI_Finalize();

  printf(" \n\n [%d/%d]: YES, YOU DID IT! \n", rank, size);
  fflush(stdout);
  return 0;
}