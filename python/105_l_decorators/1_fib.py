
# babak
# May 8, 2023

# functions are first class objects, that means they can be passed as args to other functions.

def printString():
  ''' Priint a string'''
  print("This is a message")

def printString2():
  ''' Priint the Fibonacci serires'''
  print("This is a message")
  return "a string"

printString() # function works fine
printString  # does not do anything without ()
print("=========")




print(type(printString)) # functions are objects
print(type(printString())) # printString does not return anything, so it prints nontype
print()
print(type(printString2())) # returns string
#print()
#help(printString)




