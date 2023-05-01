
# this file goes with the cython.pyx


# to compile the *.pyx file:
# $ python3 setup.py build_ext -i


from distutils.core import setup
from Cython.Build import cythonize

setup(
    ext_modules=cythonize('cysqrt.pyx'),
)
