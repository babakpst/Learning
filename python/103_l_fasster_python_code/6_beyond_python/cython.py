
# Babak Poursartip
# April 30

# writing part of the code in C
# Cython is Python plus types and connections to C libs,


def sqrt(n, tol = 0.0001):
  init = 1.0

  while (abs(init*init -n) > tol):
    init = (n/init+init)/2.0

  return init




