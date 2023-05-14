

# babak
# May 15, 2023

# all vari

class variables():

  var1 = 1
  #self.var2 = 2  # error self is not defined.
  var2 = 2
  #self.var7 = 7 # we cannot have self here.

  def __init__(self):
    var3 = 3
    self.var4 = 4

  # def test1():  # not working
    # self.var5=5

  def test2(self):
    self.var6=6

  def test3(self):
    var11=10
    var1=10
    self.var2=20

  def test4(self):
    self.var1=100

  # def retvar4(self):
  #   return self.var4


def main():
  var = variables()
  print(f" var1: {var.var1:}")
  print(f" var2: {var.var2:}")
  # print(f" var3: {var.var3:}") # object variable has no attribute var3
  print(f" var4: {var.var4:}")

  # var.test1()
  # print(f" var5: {var.var5:}")

  var.test2()
  print(f" var6: {var.var6:}")


  var.test3()
  print(f" var1: {var.var1:}")
  print(f" var2: {var.var2:}")

  var.test4()
  print(f" var1: {var.var1:}")


if __name__=="__main__":
  main()
