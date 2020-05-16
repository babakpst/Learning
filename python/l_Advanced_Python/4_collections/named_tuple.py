
# Babak Poursartip

# 31 October 2019 - Happy Halloween
# Advanced collections - linkedin advanced python
# named tuples


#libraries
import collections

def main():
  """main()-> studying advanced collections from the collections class
  """

  print ("{}".format(" program starts ..."))
  print(" doc string for the main code: ")
  print(main.__doc__)

  # named tuples
  Points = collections.namedtuple("Point", "x y")
  p1 = Points(10, 20)
  p2 = Points(11, 21)

  print(p1)
  print(p2)
  print(p1.x, p1.y)
  print("{}: {} and  {}".format(" components of the point", p2.x, p2.y))
  
  print()
  
  # usual tuples
  pp1 = (10,20)
  pp2 = (11,22)
  print(pp1)
  print(pp2)


  # replace some components of the tuple, 
  p1 = p1._replace(x=18)
  print("{} {}".format(" new point replaced", p1))

  print("{} {}".format(" first component",  pp1[1]) )
  #pp1[1] = 123  # tuple is immutable
  #print("{} {}".format(" first component",  pp1[1]) )


if __name__=="__main__":
  main()