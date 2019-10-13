
# Babak Poursartip
# Advanced Python
# 13 September 2019

# This is about built-in functions in Python
# The list of all built-in functions in PYthon is here:
# https://docs.python.org/3/library/functions.html 

# libraries



def main():
  print("{0:<70}".format(" This is the code for the test of the built-in \
functions in python"))

  print("{0}{1}".format(" This is the code for the test of the built-in", 
                         " functions in python"))

  print("{0}{1}".format(" This is the code for the test of the built-in", \
                         " functions in python"))

  print("{0} {1}".format(" This is the code for the test of the built-in",
                         "functions in python"))


  # use any() and all() to test sequences for boolean values
  list_1 = [1, 2, 3, 0, 5, 6, 12]
  
  # any() will return true if any of the entries of the list is true
  print(any(list_1)) # all entries are True except 0

  # all() will return true if all of the entries of the list is true
  print(all(list_1))  # it returns False because of 0 in the list

  # min and max return the min and max of the list
  print("{0} {1}".format(" The min of the list is: ", min(list_1)))
  print("{0} {1}".format(" The max of the list is: ", max(list_1)))

  # sum returns the sum of all entries in the list
  print("{0} {1}".format(" The sum of the list is: ", sum(list_1)))

  # ==========================================================================
  # use any() and all() to test sequences for boolean values
  list_2 = [1.123, 2.234, 3.456, 0, 5.987, 6.23, 12.159]
  
  # any() will return true if any of the entries of the list is true
  print(any(list_2)) # all entries are True except 0

  # all() will return true if all of the entries of the list is true
  print(all(list_2))  # it returns False because of 0 in the list

  # min and max return the min and max of the list
  print("{0} {1}".format(" The min of the list is: ", min(list_2)))
  print("{0} {1}".format(" The max of the list is: ", max(list_2)))

  # sum returns the sum of all entries in the list
  print("{0} {1}".format(" The sum of the list is: ", sum(list_2)))




if __name__ == "__main__":
  main()

