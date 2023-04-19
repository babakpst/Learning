
# April 18, 2023

# line_ profiler: to measure with finer granularity than just functions
# it is not the standard python function
# a @profile is needed before the function

# to use line_profiler:
# $ kernprof -l lineProfiler.py # the output will be dropped in lineProfiler.py.lprof
# python3 -m lineProfiler.py.lprof

# it is not working.


import numpy as np
from line_profiler import LineProfiler


@profile
def power(n):
  m = 1
  mat = np.zeros((100,100))
  print(mat.shape)
  for i in range(n):
    m *=2
    n = 2
    n*=4
    n=12
    for i in range(mat.shape[0]):
      for j in range(mat.shape[1]):
        mat[i][j] = 1
  return m


if __name__=="__main__":

  power(20)
  #print(power(20))


