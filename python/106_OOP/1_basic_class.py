
# babak poursartip
# May 22, 2023

class person: # or person():
  #pass
  # When an object is instantiated from this class, init will be called to initialize the attribute in the class.
  # It is not exactly equivalent to constructor. Because the object here is already instantiated, and init just updates the data.
  # self is a naming conventions, you can choose any other name here. The first item in def in each class refers to the object itself.
  def __init__(self, name):
    self.name = name


babak = person("babak")
shiva = person("shiva")

print(babak)
print(babak.name)
