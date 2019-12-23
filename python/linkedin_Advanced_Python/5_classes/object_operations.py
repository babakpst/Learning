# Babak Poursartip
# 20 December 2019

# advanced python in Linkedin.
# Object operators, give objects number-like behavior


class Point():
  def __init__(self, x, y):
    self.x = x
    self.y = y

  def __repr__(self):
    return "<Point x:{0},y:{1}>".format(self.x, self.y)
  
  # implement object addition
  def __add__(self, other):
    return Point(self.x + other.x, self.y + other.y)

  # implement object subtraction
  def __sub__(self, other):
    return Point(self.x-other.x, self.y-other.y)

  # implemnet object in-place addition
  def __iadd__(self, other):
    self.x += other.x
    self.y += other.y
    return self
 



def main():

  print()
  print(" Program starts ...")
  print()

  # declaring some points form the Point class
  p1 = Point(10, 20)
  p2 = Point(1, 2)
  print (p1, p2)

  # Add two points:
  p3 = p1 + p2
  print(p3)

  # Subtract two points
  p4 = p1 - p2
  print(p4)

  # In-place addition 
  p1 += p2
  print(p1)


  print()
  print(" End successfully!")
  print()


if __name__ == "__main__":
  main()