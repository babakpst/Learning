# Babak Poursartip
# September 15, 2019
# Starting on the online course in linkedin: 
# https://www.linkedin.com/learning/learning-python-2/building-hello-world?u=2163426

# Declare a variable and initialize it
f = 0
print (f)
#print(type(f))  # to print the type of the variable


# re-declaring the variable works
# you can change the type of the variable by assigning new type
f = "abc"  # now this is string
print (f)
#type(f)  # to print the type of the variable


# ERROR: variables of different types cannot be combined
#print ("string type " + 123)
print ("string type " + str(123))
print ("string type ", "This is a new string")

# Global vs. local variables in functions
def someFunction():

  #global f # to make a variable global everywhere in the code. 
  f = "def"
  print (f)

  aa = "123"
  print (aa)

  var1 = 12.2
  print(" this is var", var1)



someFunction()
print (f) 

del f  # deletes a variable from memory
#print (f) # error bcs there is no var f
