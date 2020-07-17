/*
Babak Poursartip
Checking the installation of MPI
07/14/2020
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

int p, myid, ierr;

int *arr = (int*)malloc(10*sizeof(arr));

MPI_Comm comm;
comm = MPI_COMM_WORLD;       

ierr = MPI_Init(&argc,&argv);
MPI_Comm_rank(comm, &myid);
MPI_Comm_size(comm, &p);

int *arr2 = (int*)malloc(10*sizeof(arr2));

free(arr);
free(arr2);

printf(" Yes, I am %d/%d \n", myid, p);

MPI_Finalize();

return 0;
}

// mpicxx -g -Wall -Wextra main.cpp -o main_debug

//valgrind mpiexec -n 2 main
