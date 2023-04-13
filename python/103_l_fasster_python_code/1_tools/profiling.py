
# April 13, 2023

# to run profiler from the terminal: python -m cProfile code.py
# we can drop the profiling results in a log file, and check the results using pstat.
# $ python3 -m pstats prof.out
# then we can review the stats
# $ stats 10 # see the top 10 outputs

import numpy as np

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


if __name__ == "__main__":

  print(power(20))
  print(power(20))

  if 1: # this is more targetted.
    import cProfile
    cProfile.run('power(20)')
    cProfile.run('power(20)', filename='prof.out') # to drop the profiling results in a file.
