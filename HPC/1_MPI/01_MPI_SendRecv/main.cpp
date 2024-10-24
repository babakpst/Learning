

/*
Babak Poursartip

Checking the installation of MPI

07/14/2020

*/


#include <mpi.h>
#include <math.h>
#include <stdio.h>
#include <sstream>

/* Prototype */
void other_work(int myid);
float integral(float ai, float h, int n);

int main(int argc, char* argv[])
{
/*######################################################################
 #                                                                     #
 # This is an MPI example on parallel integration to demonstrate the   #
 # use of:                                                             #
 #                                                                     #
 # * MPI_Init, MPI_Comm_rank, MPI_Comm_size, MPI_Finalize              #
 # * MPI_Recv, MPI_Isend, MPI_Wait                                     #
 # * MPI_ANY_SOURCE, MPI_ANY_TAG                                       #
 #                                                                     #
 # Dr. Kadin Tseng                                                     #
 # Scientific Computing and Visualization                              #
 # Boston University                                                   #
 # 1998                                                                #
 #                                                                     #
 #####################################################################*/

int n, p, myid, tag, master, proc, ierr;
float h, integral_sum, a, b, ai, pi, my_int;

MPI_Comm comm;
MPI_Request request;
MPI_Status status;

comm = MPI_COMM_WORLD;       

ierr = MPI_Init(&argc,&argv);           /* starts MPI */
MPI_Comm_rank(comm, &myid);           /* get current process id */
MPI_Comm_size(comm, &p);               /* get number of processes */

printf(" Yes, I am %d/%d \n", myid, p);

master = 0;
pi = acos(-1.0);  /* = 3.14159... */
a = 0.;           /* lower limit of integration */
b = pi*1./2.;     /* upper limit of integration */
n = 500;          /* number of increment within each process */
tag = 123;        /* set the tag to identify this particular job */
h = (b-a)/n/p;    /* length of increment */

ai = a + myid*n*h;  /* lower limit of integration for partition myid */
my_int = integral(ai, h, n);    /* 0<=myid<=p-1 */

printf("Process %d has the partial result of %f \n", myid, my_int);

  if(myid == master) {
    integral_sum = my_int;
    for (proc=1;proc<p;proc++) {
      MPI_Recv(  
            &my_int, 1, MPI_FLOAT,    /* triplet of buffer, size, data type */
            MPI_ANY_SOURCE,       /* message source */
            MPI_ANY_TAG,          /* message tag */
            comm, &status);        /* status identifies source, tag */
      integral_sum += my_int;
    }
    printf("The Integral =%f \n",integral_sum); /* sum of my_int */
  }
  else {
    MPI_Isend(       /* non-blocking send */
          &my_int, 1, MPI_FLOAT,       /* triplet of buffer, size, data type */
          master, 
          tag, 
          comm, &request);       /* send my_int to master */
    other_work(myid);
    MPI_Wait(&request, &status);    /* block until Isend is done */
  }

MPI_Finalize();                        /* let MPI finish up ... */

if(myid == master) printf("\n \n OUTPUT: The Integral =%f \n",integral_sum); /* sum of my_int */

return 0;
}

// ====================================
void other_work(int myid)
{
      printf("more work on process %d \n", myid);
}

// ====================================
float integral(float ai, float h, int n)
{
      int j;
      float aij, integ;

      integ = 0.0;                 /* initialize */
      for (j=0;j<n;j++) {          /* sum integrals */
        aij = ai + (j+0.5)*h;      /* mid-point */
        integ += cos(aij)*h;
      }
      return integ;
}
