
# Babak Poursartip
# 24 November 2019

# Object strings
# Customize string representations of objects

class person():

  def __init__(self):
    self.firstName = "Babak"
    self.lastName = "Poursartip"
    self.age = 35


  # Important: override the repr function
  def __repr__(self):
    return "<Person class - fristName:{0}, lastName:{1}, age:{2}".format(self.firstName, self.lastName, self.age)

  # Important: override the str function
  def __str__(self):
    return "{0} {1} is now {2}".format(self.firstName, self.lastName, self.age)

  # Important: override the bytes function
  def __bytes__(self):
    val =  "person:{0}:{1}:{2}".format(self.firstName, self.lastName, self.age)
    return bytes(val.encode('utf-8'))


def main():

  print()
  print(" Code starts here ..")
  print()



  # ============================================================================
  # we can see if we print string using repr() function then it prints with a
  # pair of quotes and if we calculate a value we get more precise value
  # than str() function.

  # Differences btw str() and repr()
  # -str() is used for creating output for end user while repr() is mainly used
  # for debugging and development. repr’s goal is to be unambiguous and str’s is
  #  to be readable. For example, if we suspect a float has a small rounding
  # error, repr will show us while str may not.
  # - repr() compute the “official” string representation of an object
  # (a representation that has all information about the abject) and str() is
  # used to compute the “informal” string representation of an object
  # (a representation that is useful for printing the object).
  # - The print statement and str() built-in function uses __str__ to display
  # the string representation of the object while the repr() built-in function
  # uses __repr__ to display the object.

  test = "check string"
  print(test) # this is equivalent to str(...).
  print(str(test))
  print(repr(test))

  print(" str form of a float:  {}".format(str(2./11.)))
  print(" repr form of a float: {}".format(repr(2./11.)))


  # ============================================================================

  # printing the object differently
  print()
  print(" class: ")
  myPerson = person()
  print("The first name is: {0}, the last name is: {1}, and the age: {2}"
        .format(myPerson.firstName, myPerson.lastName, myPerson.age))

  print("repr: {}".format(repr(myPerson)))
  print("str:  {}".format(str(myPerson)))

  print("Formatted {0}".format(myPerson))  # This is great. It seems it is using the str format.
  print("bytes: {}".format(bytes(myPerson)))


  print()
  print(" End of the code!")
  print()


if __name__ == "__main__":
  main()
