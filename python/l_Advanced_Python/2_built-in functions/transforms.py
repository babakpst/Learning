

# Babak Poursartip
# Advanced python from linkedin

# 21 October 2019

# transform functions such as sorted, filter, and map

def filterFunc(x):
  if x%2==0:
    return False
  return True   # This is great

def filterFunc2(x):
  if x.isupper():
    return False
  return True

def squareFunc(x):
  return x*x

def toGrades(x):
  if (x >= 90):
    return "A"
  elif (x >= 80 and x < 90):
    return "B"
  elif (x >= 65 and x < 80):
    return "C"
  else:
    return "F"

def main():

  nums = (1, 5, 8, 12, 16, 15, 21, 123, 234, 256) # this is a tuple, immutable
  list1 = [1, 5, 8, 12, 16, 15, 21, 123, 234, 256] # this is a list, mutable
  print(nums)
  print(list1)
  print(nums[1])
  print(list1[1])

  chars = "abcDEFghIjkLMNopqRsTu"
  grades = (81, 12, 95, 100, 79, 69, 59)
  # ----------------------------------------------------------------------------
  # filter to remove some items from a list- remove the even numbers
  odds = list(filter(filterFunc, nums))
  print(odds)

  # change all uppercase letters to lower case chars
  lowers = list(filter(filterFunc2, chars))
  print(lowers)

  # map: create a sequence from another sequence based on a function
  squares = list(map(squareFunc, nums))
  print(squares)

  squares2 = [x*x for x in range(1,10)]
  print(squares2)

  # sort
  grades = sorted(grades)
  print(grades)

  letters = list(map(toGrades, grades))
  print(letters)



if __name__=="__main__":
  main()
