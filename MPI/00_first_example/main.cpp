

/*
Babak Poursartip

Checking the installation of MPI

07/14/2020

*/


#include <mpi.h>

int main(int argc, char* argv[]){

MPI_Comm Comm=MPI_COMM_WORLD;

MPI_Status status; 
int npes, iam=-1, ierr,irec=-1;

ierr=MPI_Init(&argc, &argv);
ierr=MPI_Comm_size(Comm,&npes);
ierr=MPI_Comm_rank(Comm, &iam);

if(iam==0)
  ierr=MPI_Send(&iam, 1,MPI_INT, 1,9, Comm);
if(iam==1)
  ierr=MPI_Recv(&irec,1,MPI_INT, 0,9, Comm,&status);

ierr=MPI_Finalize();
printf("iam=%d, received=%d\n",iam,irec);
return 0;
}
