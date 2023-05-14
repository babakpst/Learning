
# babak
# May 15, 2023

# regular methods automatically pass the instance as the first argument in the funciton, it is called self.
# classmethods automatically pass the class as the first argument in the funciton, it is called cls.
# staticmethods don't pass anything automatically. They behave just like the regular functions. But we include them in
#      the class, because they have some logical connection within the class. If a func in a class does not need any
#      members/variables of the class, it should be a staticmethod.

# classmethod decorator applies the operations to all instances of the class.

# self changes the var for each instance, but cls changes this for the entire class (i.e. all instances).

class mathLib:

  value = 5
  more = 2

  def __init__(self, number):
    self.number = number


  @classmethod
  def change(cls, newnum): # cls means we are working with the class instead of an instance.
    cls.value = newnum

  # alternative constructor
  @classmethod
  def from_string(cls, str):
    return cls(int(str))


  def square(self,num): # without self it is not working.
    return num * num

  @staticmethod
  def square2(num):
    return num * num


# classmethod
print()
print("classmethod 0 ")
var = mathLib(11)
print(mathLib.value)
print(var.value)

mathLib.change(8)  # changes the value to 8 for all instances of the class: equivalent to mathLib.value=9

print(mathLib.value)
print(var.value)

print()
print("classmethod 1")

#mathLib.change(8)  # changes the value to 8 for all instances of the class.
mathLib.value=9

print(mathLib.value)
print(var.value)

print()
print("classmethod 2 ")
var = mathLib(11)
print(mathLib.value)
print(var.value)

var.change(10)  # changes the value to 8 for all instances of the class: we can run the class method from an instance

print(mathLib.value)
print(var.value)


print()
print("classmethod ---")
print(mathLib.more)
print(var.more)
var.more=6   # chanes more=6 only for this instance
print(mathLib.more)
print(var.more)


print()
print("classmethod - alternative ctor")
var2 = mathLib.from_string("123")
print(var2.number)

print()
print("staticmethod ")
print(var.square(4))
print(mathLib.square2(5)) # without the staticmethod decorator is also working fine!
