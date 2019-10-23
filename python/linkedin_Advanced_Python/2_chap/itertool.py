
# Babak Poursartip
# 22 October 2019

# itertool module

import itertools

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



if __name__=="__main__":
  main()