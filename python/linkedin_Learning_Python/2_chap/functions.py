# Babak Poursartip
# September 15, 2019
# Starting on the online course in linkedin: 
# https://www.linkedin.com/learning/learning-python-2/building-hello-world?u=2163426

# define a basic function
def func1():
  print()
  print ("I am a function")

# function that takes arguments
def func2(arg1, arg2):
  print ("Here are the arguments passed to the function: ", arg1, " ", arg2)

# function that returns a value
def cube(x):
  return x*x*x

# function with default value for an argument
def power(num, x=1):   # default var for x, it is optional then.
  result = 1;
  for i in range(x):
    result = result * num  
  return result

#function with variable number of arguments
def multi_add(*args):  # star means we can pass variable number of arguments.
  result = 0;
  for x in args:
    result = result + x
  return result

# about the first function
func1()
print (func1()) # since the function does not have a return, it prints None.
print("check the empty print statement:")
print()
print (func1) # functions are objects that can be transferred to other codes.

# second function
func2(10,20)
print (func2(10,20))

# third function
print (cube(3))

# fourth function
print (power(2))
print (power(2,3))
print (power(x=3, num=2)) # the order of args can change if we directly use the names.


print (multi_add(4,5,10,4))
