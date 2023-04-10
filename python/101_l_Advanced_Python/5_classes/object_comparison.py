
# Babak Poursartip
# 12/25/2019

# Advanced Python: linkedin
# object comparison: Using object method to compare objects to each other
# IMPORTANT: The built-in functions are using this comparison functions for
#            comparisons. So we can sort the dept now.

class employee():
  def __init__(self, fname, lname, level, yrsService):
    self.fname = fname
    self.lname = lname
    self.level = level
    self. seniority = yrsService

  # override comparison
  def __ge__(self, other):
    if (self.level == other.level):
      return self.seniority >= other.seniority
    return self.level >= other.level

  def __gt__(self, other):
    if (self.level == other.level):
      return self.seniority > other.seniority
    return self.level > other.level

  def __le__(self, other):
    if (self.level == other.level):
      return self.seniority <= other.seniority
    return self.level <= other.level

  def __lt__(self, other):
    if (self.level == other.level):
      #print(" I am here.")
      #print(self.seniority, other.seniority)
      return self.seniority < other.seniority
    return self.level < other.level

  def __eq__(self, other):
    return self.level == other.level

def main():

  print()
  print(" Program starts ...")
  print()

  # defining employees
  dept = []
  dept.append(employee("Babak", "Poursartip", 5, 9))   # 0
  dept.append(employee("Shiva", "Aryan", 6, 10))       # 1
  dept.append(employee("Behnaz", "Poursartip", 7, 11)) # 2
  dept.append(employee("Behrang", "Poursartip", 5, 14)) # 3
  dept.append(employee("Babak", "Aryan", 5, 13))       # 4

  # Find the senior employee:
  print(dept[0] > dept[2])
  print(dept[4].fname, dept[3].fname)
  print(dept[4].level, dept[3].level)
  print(dept[4].seniority, dept[3].seniority)
  print(dept[4] < dept[3])
  print(dept[4] < dept[2])

  # sorting the employees based the seniority
  print()
  print("before sorting: ")
  for emp in dept:
    print(emp.fname)


  print()
  print("after sorting: ")
  emps = sorted(dept) # The built-in comparison is using these comparisons for the sorting, so we can use our methods to sort employees.
  for emp in emps:
    print(emp.fname)



  print()
  print(" End successfully.")
  print()



if __name__ == "__main__":
  main()
