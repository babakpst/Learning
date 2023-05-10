
# babak
# May 8, 2023

# calling a function without () returns the reference to that func, but with () returns the returns.

def func(var1, var2, var3):
   return var1, var2, var3

print("function1")
func(1,2,3)
print(func(1,2,3))   # prints a tuple with three number


def func2():
   return 1, 2, 3
print("function2")
func2()
print(func2())   # prints a tuple with three number
print(func2)   # prints a tuple with three number


#==================================
def outer_func(var1, var2, var3):

  def inner_func():
    return var1, var2, var3

  return inner_func
#  return inner_func()

print("outer func")
print(outer_func(1,2,3)) # this only returns a reference to the outer_func.


new_func = outer_func(1,2,3) # assign the reference to a var
print(new_func())

print(" here ")
print(outer_func(1,2,3)())

