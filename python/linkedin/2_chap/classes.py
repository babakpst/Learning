
# Babak Poursartip
# September 15, 2019
# classes
# from the linkedin course: https://www.linkedin.com/learning/learning-python-2/classes?u=2163426

class babakClass():
  def method1(self):
    print(" babakClass method one")

  def method2(self, AString):
    print(" babak class method 2: " + AString)


class ShivaClass(babakClass):
  def method1(self):
    babakClass.method1(self)
    print(" ShivaClass method one")

  def method2(self, AString):
    print(" shiva class method 2: ")



def main():
  bob = babakClass()
 
  bob.method1()
  bob.method2("bob is awesome.")
  

  print()
  print(" inherited class")
  jj = ShivaClass()
  jj.method1()
  jj.method2("yes")


 


if __name__ == "__main__":
  main()