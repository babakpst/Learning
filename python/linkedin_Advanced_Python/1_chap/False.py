
# Babak Poursartip
# Advanced Python
# 29 September 2019

def main():

  # Any object can be tested for boolean truth value.
  # Almost everything is classified as bool true, except a couple of items:

  x = []
  print("{1} {0}".format(bool(x), " The boolean value of an empty list: "))

  y = {}
  print("{1} {0}".format(bool(y), " The boolean value of an empty dictionary: "))

  print("{1} {0}".format(bool(0), " The boolean value of zero (int): "))
  print("{1} {0}".format(bool(1), " The boolean value of one (int): "))


if __name__ == "__main__":
    main()