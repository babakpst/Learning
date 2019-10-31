
# Babak Poursartip

# 30 October 2019
# Advanced python, linkedin\
# Keyword-only arguments

def someFunction(arg1, arg2, *, SuppressExceptions=False):
#def someFunction(arg1, arg2, SuppressExceptions=False):
  """someFunction(arg1, arg2, SuppressExceptions=False) --> checks the optional variables
  Parameters:
  arg1
  arg2
  """
  print(arg1, arg2, SuppressExceptions)


def main():
  """ main():
  """
  someFunction(1,2, SuppressExceptions = True)
  #someFunction(1,2)
  #someFunction(1,2, True)
  #someFunction(1,2, False)
  print(someFunction.__doc__)
  


if __name__=="__main__":
  main()