
# babak
# May 12, 2023

from time import perf_counter
from functools import wraps

def timer(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = perf_counter()
        results = func(*args, **kwargs)
        end = perf_counter()
        duration = end - start

        args = str(*args) # convert args to string for the print statement

        print(f"{func.__name__}({args}) = {results}  - duration: {duration:.6f} s")
        return results
    return wrapper



@timer
def cpuWaster(num):
    mult = 1
    for i in range(1,num):
        mult *= i
    #print(mult)
    return mult

cpuWaster(1_0)
