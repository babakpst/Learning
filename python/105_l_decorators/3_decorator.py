
# babak poursartip
# May 10, 2023


# typical decorator
#def decorator(function):
#  def wrapper()
#    ...
#    result = function()
#    ...
#    return result
#  return wrapper

#@decorator
#def function():
#  pass


# =======================
def decorator2():
  def wrapper():
    return "HereIsTheDecorator"
  return wrapper

print()
aFunc = decorator2()
print(aFunc)
print(aFunc())

# =======================
# =======================
# decorator
def decorator(f):
  def wrapper():
    print("in the wrapper")
    print(f())
    return "HereIsTheDecorator"
  return wrapper

def pString():
  return "StringFunction"

pString = decorator(pString)
print()
print("with decorator")
print(pString())


@decorator # this is equivalent to pString2 = decorator(pString2)
def pString2():
  return "StringFunction"

print()
print("with actual decorator")
print(pString2) #  it prints a reference to the wrapper in the decorator
print(pString2())
