
# Babak Poursartip

# 30 October 2019
# Advanced python, linkedin\
# Keyword-only arguments


# separate your positional arguments from the keyword-only arguments with a *, to force the users to define the keyword arguments in the call. Otherwise, it is an error. The parameters followed by the * are keyword only.

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
  #someFunction(1,2, True) # here the SuppressExceptions is not defined, so it is an error.
  #someFunction(1,2, False)
  print(someFunction.__doc__)



if __name__=="__main__":
  main()
