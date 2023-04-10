
# Babak Poursartip
# 23 November 2019


# In this chapter, we learn how to use various features of classes.

# defining enumerations using the Enum base class

# libraries
from enum import Enum
from enum import unique # to prevent duplicate values for enum
from enum import auto  # to automatically assign values to each item in the enum

# by putting enum in (), we inherit the properties from Enum
class Fruit(Enum):
  # not valid to have duplicate names, but duplicate values is fine
  # Apple = 5, error
  Apple = 1
  Kiwi = 2
  Babana = 3
  Orange = 4
  Grapefruit = 5
  Peach = 1 # There is no unique decorator, so we can have duplicate values.

@unique # the unique decorator prevents duplicate values in an enum
class Fruits(Enum):
  # not valid to have duplicate names, but duplicate values is fine, if we don't have @unique decorator. But with the @unique decorator, duplicate values are not allowed.
  # Apple = 5, error
  Apple = 1
  Kiwi = 2
  Babana = 3
  Orange = 4
  Grapefruit = 5
  #Peach = 1
  Pear = auto() # to automatically assing values to a parameter (from enum.auto).
  # werid, The names should be capitalized, otherwise, it is an error.



def main():
  #	pass
  # enum have
  print(Fruit.Apple)
  print(type(Fruit.Apple))
  print(repr(Fruit.Apple))

  # enum have name and value properties
  print()
  print(Fruit.Apple.name, Fruit.Apple.value)

  # print the value of auto enum
  print(Fruits.Pear.name, Fruits.Pear.value)

  # use enum as hash values
  myFruits = {} # a dictionary
  myFruits[Fruit.Babana] = " Hello Banana "
  print(myFruits[Fruit.Babana])


if __name__=="__main__":
  main()
