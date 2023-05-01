
# Babak Poursartip
# April 30

# writing part of the code in C
# Cython is Python plus types and connections to C libs,

# first we need to compile the code, using setup.py


# to compile the *.pyx file: 
#python3 setup.py build_ext -i


def sqrt(double n, double tol = 0.0001):
  cdef double init = 1.0
  
  while (abs(init*init -n) > tol):
    init = (n/init+init)/2.0
    
  return init
  



