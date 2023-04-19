
# April 19, 2023

# to use memory profiler, we need: sudo pip3 install memory_profiler
# to run:
# $ python3 -m memory_profiler memProfiling.py


# to run time-base mem profiling
# $ mprof run memProfiling.py # this will create a .dat file,
# to visualize the dat file:
# $ mprof plot *.dat

import numpy as np

@profile
def power(n,li):
  m = 1
  k = 1
  mat = np.zeros((100,100))
  print(mat.shape)
  li2 = li
  for i in range(n):
    m *=2
    for i in range(mat.shape[0]):
      for j in range(mat.shape[1]):
        mat[i][j] = 1
  return mat


if __name__=="__main__":
  li=[1,2,3,5,4,8,8,5,7,2]
  mat2 = np.zeros((10,10))
  power(20,li)
  #print(power(20))


