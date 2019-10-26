
# Babak Poursartip
# 25 October 2019

# Documentation string: DOCSTRING


def myFunc(arg1, arg2=None):
  """myFunc(arg1,arg2=None) --> Does not do anything.

  Parameters:
  arg1: The first argument.
  arg2: The second argumenet.
  """

  print(arg1,arg2)


def main():
  """
  This is the help of the main function.
  """

  print(myFunc.__doc__)

  
  
  print(" This is the documentation string code.")


if __name__ == "__main__":
  main()