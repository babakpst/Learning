
# Babak Poursartip
# 22 October 2019

# itertool module

import itertools


def testfunction(x):
  return x < 40

def main():
  # cycle iterator can be used to cycle over a collection
  seq1  = ["Babak", "Shiva", "Behnaz", "Behrang"]

  cycle1 = itertools.cycle(seq1)

  print (next(cycle1))
  print (next(cycle1))
  print (next(cycle1))
  print (next(cycle1))
  print (next(cycle1)) 
  print (next(cycle1))
  print (next(cycle1))
  print (next(cycle1))

  # Create a counter
  count1= itertools.count(100,10) # 100 is the start value, 10 is the increment
  print(next(count1))
  print(next(count1))
  print(next(count1))
  print(next(count1))
  print(next(count1))

  # Accumulate creates an iterator that accumulates values
  values = [10, 20, 30, 40, 50, 40, 30, 20, 10]
  acc = itertools.accumulate(values)
  # print(acc) # this does not do anything.
  print(list(acc))

  acc2 = itertools.accumulate(values, max)
  print(list(acc2))

  # use CHAIN to connect sequences together
  xx = itertools.chain("ABCO", "1234")
  print(list(xx))

  # The dropwhile and takewhile will return values until a certain condition is met that stops themdatetime A combination of a date and a time. 
  bb = itertools.dropwhile(testfunction, values) # drops values until the testfunction returns true
  print("dropwhile: \n",list(bb))

  bb = itertools.takewhile(testfunction, values)  # return values while the testfunction returns true
  print("takewhile: \n", list(bb))

if __name__=="__main__":
  main()
