

# babak - May 11, 2023

# *args: non-keyword argumets - used to pass a variable number of arguments to a function. The variable that we associate with the * becomes iterable meaning you can do things like iterate over it.

# **kwargs: keyword arguments-used to pass a keyworded, variable-length argument list.  kwargs as being a dictionary that maps each keyword to the value that we pass alongside it.

# The order of having non-kwarags and kwargs in the function is: def func(arg1, arg2, *args, **kwargs)


#=====================
# *args
print(" args")
def sumNum(*args):
  tmp = 0
  for item in args:
    tmp += item
  return tmp

print("sum: ",sumNum(1,2,3,4,5,6,5,4,1,23))

#=====================
# **kwargs

print()
print(" kwargs")
def test(**kwargs):
  for key, value in kwargs.items():
    print(key, value)

test(name="babak", age=25, job="sw dev")

#mydic={"name":"babak", "age":"25", "job":"sw dev"}
mydic={"arg1": "Geeks", "arg2": "for", "arg3": "Geeks"}
#test(mydic) # error


#=====================
# passing *args and **kwargs to a function, the other way around method.

print()
print(" the other way around")

def funcWithMultipleArgs(arg1, arg2, arg3, arg4):
  print(" 1", arg1)
  print(" 2", arg2)
  print(" 3", arg3)
  print(" 4", arg4)

args = (1,2,3,4)
funcWithMultipleArgs(*args)

# kwargs ={"name":"babak", "age":"25", "job":"sw dev", "item4":"nothin"} # this is not working, the keys should be identical to the function argument names.
kwargs ={"arg1":"babak", "arg2":"25", "arg3":"sw dev", "arg4":"nothin"}
funcWithMultipleArgs(**kwargs)


print("+++++++++++++++++++++++++++")

def setAll(dummy, *args, **kwargs):
    print(" dummy", dummy)
    print("args: ", args)
    print("kwargs: ", kwargs)


# Now we can use both *args ,**kwargs
# to pass arguments to this function :
setAll(12, 'Im', 'great', arg1="Babak", arg2="is", arg3="a developer.")

