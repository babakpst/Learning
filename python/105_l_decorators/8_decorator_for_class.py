
# babak
# May 14, 2023

from functools import update_wrapper, lru_cache


# This class/decorator counts the number of times a function has been called.
class counter():

  def __init__(self, func):
     update_wrapper(self, func) #  this is to make sure we have the correct doc and name for class.
     self.func = func
     self.counter = 0

  # for the class to be callable, we need to implement __call__. Each time, we call the class, this method would be called.
  # it behaves similar to the wrapper function.
  def __call__(self, *args, **kwargs):
     self.counter+=1
     print(f" current counter: {self.counter:}")
     result = self.func(*args, **kwargs)
     return result



@lru_cache(maxsize=None) # for caching memization
@counter
def somefunc(num):
    if num<2:
       return num
    else:
       return num + somefunc(num-1)



somefunc(5)
