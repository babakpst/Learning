
# Babak Poursartip
# Advanced Python
# 29 September 2019

import decimal

def main():

  # Any object can be tested for boolean truth value.
  # Almost everything is classified as bool true, except a couple of items:

  emptyString = ''
  print("{1:<45} {0}".format(bool(emptyString), " The boolean value of an empty string: ")) # False

  x = []
  print("{1:<45} {0}".format(bool(x), " The boolean value of an empty list: ")) # False

  y = {}
  print("{1:<45} {0}".format(bool(y), " The boolean value of an empty dictionary: ")) # False


  print("{1:<45} {0}".format(bool(()), " The boolean value of empty set: ")) # False
  print("{1:<45} {0}".format(bool((1,2)), " The boolean value of non-empty set: ")) # True


  print("{1:<45} {0}".format(bool(0), " The boolean value of zero (int): ")) # False
  print("{1:<45} {0}".format(bool(1), " The boolean value of one (int): ")) # True
  print("{1:<45} {0}".format(bool(decimal.Decimal(0)), " The boolean value of decimal: ")) # False
  print("{1:<45} {0}".format(bool(decimal.Decimal(1)), " The boolean value of decimal: ")) # True
  print("{1:<45} {0}".format(bool(range(0)), " The boolean value of range: ")) # False

  # decimal
  var_1 = 8.7 + 7.6
  print('{1} {0:<30}'.format(var_1, " The summation of two numbers is not correct: "))
  var_2 = decimal.Decimal(8.7) + decimal.Decimal(7.6)

  print('{1} {0:<30}'.format(var_2, " The summation of two numbers is not correct: "))

  decimal.getcontext().prec=3
  var_3 = decimal.Decimal(8.7) + decimal.Decimal(7.6)
  print('{1} {0:<30}'.format(var_3, " The summation of two numbers is not correct: "))

  fmt = '{0:<20} {1:<20}'
  print(fmt.format('Input', 'Output'))
  print(fmt.format('-' * 20, '-' * 20))

  # Integer
  print(fmt.format(5, decimal.Decimal(5)))

  # String
  print(fmt.format('3.14', decimal.Decimal('3.14')))

  # Float
  print(fmt.format(repr(0.1), decimal.Decimal(str(0.1))))



if __name__ == "__main__":
    main()
