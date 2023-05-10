
# babak poursartip
# May 10, 2023

# ==========================================================
# ==========================================================
# part 1: how to use a decorator with a wrapper

def addItem(func):
  '''decorator function to add header/footer'''
  def wrapper():
    '''this is the wrapper function'''
    print("+++++++++++")
    print("+++++++++++")
    out = func()
    print(out)
    print("+++++++++++")
    print("+++++++++++")
    return out
  return wrapper


@addItem
def pString():
  '''the main print function'''
  return "ThisFuncPrintsAString"

#print(pString())
print()
pString()
print(pString.__name__) # this prints "wrapper" and not pString!
print(pString.__doc__)  # this prints the wrapper docs and not the  and not pString!
print("end of part one")
# the wrapper meta data overrides the function meta data. To fix that, we need to use a trick. See part 2.


# ==========================================================
# ==========================================================
# part 2: how to fix the file name/doc (meta data of the function with decorator)
#         naive option


def addItem2(func):
  '''decorator function to add header/footer'''
  def wrapper():
    '''this is the wrapper function'''
    print("+++++++++++")
    print("+++++++++++")
    out = func()
    print(out)
    print("+++++++++++")
    print("+++++++++++")
    return out
  wrapper.__name__=func.__name__
  wrapper.__doc__=func.__doc__
  return wrapper


@addItem2
def pString2():
  '''the main print function'''
  return "ThisFuncPrintsAString"

#print(pString())
print()
pString2()
print(pString2.__name__) # this prints "wrapper" and not pString!
print(pString2.__doc__)  # this prints the wrapper docs and not the  and not pString!
print("end of part two")

# ==========================================================
# ==========================================================
# part 3: how to fix the file name/doc (meta data of the function with decorator)
#         advanced option

from functools import wraps

def addItem3(func):
  '''decorator function to add header/footer'''
  @wraps(func)
  def wrapper():
    '''this is the wrapper function'''
    print("+++++++++++")
    print("+++++++++++")
    out = func()
    print(out)
    print("+++++++++++")
    print("+++++++++++")
    return out
  #wrapper.__name__=func.__name__
  #wrapper.__doc__=func.__doc__
  return wrapper


@addItem3
def pString3():
  '''the main print function'''
  return "ThisFuncPrintsAString"

#print(pString())
print()
pString3()
print(pString3.__name__) # this prints "wrapper" and not pString!
print(pString3.__doc__)  # this prints the wrapper docs and not the  and not pString!
print("end of part three")






