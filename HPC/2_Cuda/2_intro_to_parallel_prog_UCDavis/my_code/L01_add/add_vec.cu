
/*
babak poursartip
adding two vectors

05/14/2020
*/

#include <stdio.h>

__global__
void add_vec( float *d_vec1, float *d_vec2, float *d_out, int vec_size)
{
  int tidx = threadIdx.x;
  int tidy = threadIdx.y;
  int tidz = threadIdx.z;

  int bidx = blockIdx.x;
  int bidy = blockIdx.y;
  int bidz = blockIdx.z;

  int gridx = gridDim.x;
  int gridy = gridDim.y;
  int gridz = gridDim.z;

  int blx   = blockDim.x;
  int bly   = blockDim.y;
  int blz   = blockDim.z;

  printf(" I am: %d  %d  %d  %d %d  %d %d  %d %d  %d %d  %d\n", tidx, tidy, tidz, bidx, bidy, bidz, gridx, gridy, gridz, blx, bly, blz);

  int chunk = vec_size/gridx/blx;

  int id_st = bidx*chunk*blx+tidx*chunk;
  int id_en = bidx*chunk*blx+(tidx+1)*chunk;

  printf("here: %d %d %d %d  \n", tidx, bidx, id_st, id_en  );

    for (int ii =id_st; ii < id_en; ++ii){
      d_out[ii]  = d_vec1[ii] + d_vec2[ii];
    }
  //printf(" yes %f  %f  %f \n",d_out[tidx],d_vec1[tidx],d_vec2[tidx]);

}

int main(){

printf(" code starts ... \n");

float *h_vec1, *h_vec2,*h_out;

int vec_size = 1024;
int vec_size_byte = vec_size * sizeof(float);

h_vec1 = (float *) calloc( vec_size,sizeof(float));
h_vec2 = (float *) calloc( vec_size,sizeof(float));
h_out  = (float *) calloc( vec_size,sizeof(float));

  for (int ii = 0; ii<vec_size; ++ii){
    h_vec1[ii]  = 0.1f*(float)ii;
    h_vec2[ii]  = 0.2f*(float)ii;
    h_out[ii]  = 0.222f;
  }  

// define pointers in the gpu
float *d_vec1, *d_vec2,*d_out;

// alloc memory on the gpu
cudaMalloc((void **) &d_vec1, vec_size_byte);
cudaMalloc((void **) &d_vec2, vec_size_byte);
cudaMalloc((void **) &d_out, vec_size_byte);

// copy arrays to the gpu memory
cudaMemcpy(d_vec1,h_vec1,vec_size_byte,cudaMemcpyHostToDevice);
cudaMemcpy(d_vec2,h_vec2,vec_size_byte,cudaMemcpyHostToDevice);

// lauch kerner
int blc = 4;
dim3 blocks(blc,1,1);
int thrd = 16;
dim3 threads(thrd,1,1);

add_vec<<<blocks,threads>>>(d_vec1, d_vec2, d_out, vec_size);

// transfer the output to host
cudaMemcpy(h_out,d_out,vec_size_byte,cudaMemcpyDeviceToHost);

// output
printf("\n");
  for (int ii = 0; ii<vec_size; ++ii){
    printf(" %d %f + %f  = %f \n",ii,h_vec1[ii],h_vec2[ii], h_out[ii]);
  }  

printf(" code ends. \n");

}
