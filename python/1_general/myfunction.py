
# Babak Poursartip
# Aug 20, 2019

def fib(n): # return fibonacci series up to n
    """ Print Fibonacci series up to n """

    result = []
    a = 0
    b = 1
    while a < n:
        print a
        a = b
        b = a + b



f100 = fib(10)
