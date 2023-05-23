
# babak poursartip
# May 22, 2023

class person: # or person():
  #pass
  # When an object is instantiated from this class, init will be called to initialize the attribute in the class.
  # It is not exactly equivalent to constructor. Because the object here is already instantiated, and init just updates the data.
  # self is a naming conventions, you can choose any other name here. The first item in def in each class refers to the object itself.
  def __init__(self, name, last, age, salary, myjobs):
    self.name = name
    self.last = last
    self.age = age
    self.salary = salary

    # var or functions starting with double underscore __ are private, and inaccessible outside the class.
    # this is not a perfect mechanism. python prefixes the class name with this variable, it is called name mangling. The
    # reason for name mangling is that to prevent subclasses from overriding the def inadvertantly.
    self.__private = 122


  # static attributes/method: properties defined at the class level are shared by all instances
  JOBS = ("ENGINEER","TEACHER", "SOFTWARE DEVELOPER")



  def getAge(self): # without self, no class var will be passed to the function.
    return self.age

  def setAddress(self, address): # there is no public or private method in the python, vars starting with _ are considered private, by convention.
    self._address = address

  def getAddress(self):
    if hasattr(self,"_address"):
      return self._address
    else:
      return "none"


babak = person("babak","poursartip", 30, 100)
# shiva = person("shiva")

print(babak)
print(babak.name)
print(babak.getAge())

print(babak.getAddress())
babak.setAddress("oasis")
# print(babak.address)
print(babak.getAddress())
#print(babak.__private) # error 'person' object has no attribute '__private'
print(babak._person__private) # error 'person' object has no attribute '__private'

print(type(12)) # prints the type of the instance
print(type(babak)) # prints the type of the instance
print(type(babak) == type(123)  ) # prints the type of the instance

print(isinstance(babak, person)) # This is a good way to see if an instance is of particular type
print(isinstance(12, int)) # This is a good way to see if an instance is of particular type
print(isinstance(12, object)) # everything in python is a subclass of object
