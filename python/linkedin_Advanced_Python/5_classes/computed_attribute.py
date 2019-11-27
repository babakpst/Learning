
# Babak Poursartip
# 26 November 2019

# Computed attribute
# How attributes are accessed within an object

# Python will call __getattr__ method whenever you request an attribute that hasn't already been defined.
# __setattr__: Called when an attribute assignment is attempted.

# dir() a built-in function in Python3, which returns list of the attributes and methods of any object (say functions , modules, strings, lists, dictionaries etc.)



class myColor():
  def __init__(self):
    self.red = 50
    self.green = 75
    self.blue = 100

  def __getattr__(self, attr):
    if attr == "rgbcolor":
      return (self.red, self.green, self.blue)
    elif attr == "Babak":
      return "Babak you are great!"
    elif attr == "hexcolor":
      return "#{0:02x}{1:02x}{2:02x}".format(self.red, self.green, self.blue)
    else:
      raise AttributeError

  def __setattr__(self, attr, val):
    if attr == "rgbcolor":
      self.red = val[0]
      self.green = val[1]
      self.blue = val[2]    
    else:
      super().__setattr__(attr, val) # the __getattr__ function will be called instead.

  def __dir__(self):
    return ("red", "green", "blue", "rgbcolor", "hexcolor")



def main():

  print()
  print("Computed attribute ...")
  print()

  # use getattr to dynamically return a value
  myCls = myColor()
  print(myCls.rgbcolor)
  print(myCls.Babak)
  print(myCls.hexcolor)

  # use __setattr__ to dynamically return a value
  myCls.rgbcolor = (125, 200, 86)
  print(myCls.rgbcolor)
  print(myCls.hexcolor)

  # access the regular attributs
  print(myCls.red)  

  # list the available attributes in my class
  print(dir(myCls))

  print()
  print("End of the code!")
  print()



if __name__=="__main__":
  main()
