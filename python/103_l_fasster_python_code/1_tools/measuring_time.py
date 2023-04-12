
# April 12, 2023

from time import perf_counter
from timeit import timeit

def sum_for(n):
  """Sum with for loop"""

  acc = 0
  for i in range(n):
    acc += i
  return acc


def sum_builtin(n):
  """Sum using built-in function"""
  return sum(range(n))



n = 1_000_000

start = perf_counter()
sum_for(n)
elapsed=perf_counter()-start
print(" for loop cost: {}".format(elapsed))

start = perf_counter()
sum_builtin(n)
elapsed=perf_counter()-start
print(" builtin sum cost: {}".format(elapsed))



######################
#using timeit
items = {'babak':35, 'shiva': 32}

default = -1

def use_catch(key):
  try:
    return items[key]
  except KeyError:
    return default

def use_get(key):
  return items.get(key, default)


# key is in the dictionary
print(" catch: {}".format(timeit('use_catch("babak")', 'from __main__ import use_catch')))
print(" get:   {}".format(timeit('use_get("babak")', 'from __main__ import use_get')))

# key is missing
print(" catch: {}".format(timeit('use_catch("behrang")', 'from __main__ import use_catch')))
print(" get:   {}".format(timeit('use_get("behrang")', 'from __main__ import use_get')))
