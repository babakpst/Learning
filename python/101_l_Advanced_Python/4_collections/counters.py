
# Babak Poursartip
# 11/06/2019
# counter

# libraries
from collections import Counter

def main():
  print()
  print()
  print("{}".format(" Learning the counter module in the collections library:"))

  # list of students in class 1
  class1 = ["Bob", "James", "Chad", "Darcy", "Penny", "Hannah", "Shiva",
              "Kevin", "James", "Melanie", "Becky", "Steve", "Frank", "Shiva"]

  # list of students in class 2
  class2 = ["Bill", "Barry", "Cindy", "Debbie", "Frank", "Behnaz", "Behrang",
              "Gabby", "Kelly", "James", "Joe", "Sam", "Tara", "Ziggy"]

  c1 = Counter(class1)  # The output of Counter is a dictionary, input is a list
  c2 = Counter(class2)

  print(c1)
  print()
  print(c2)

  # How many student in class 1 named James?
  print("{} {}".format("Number of students in class 1 named Shiva: ", c1["Shiva"]))

  # How many students are in class 1
  print("{} {}".format( sum(c1.values()), " students in class 1."))

  # combine two classes/lists
  c1.update(class2)
  print(c1)
  print("{} {}".format( sum(c1.values()), " students in class 1 & 2."))

  # most common names in classes
  print()
  print()
  print("MOST common: {}".format(c1.most_common(3)))
  print()
  print()
  print("MOST common: {}".format(c1.most_common()))
  print()
  print()


  # Separate classes
  c1.subtract(class2)
  print()
  print("subtract two lists: ")
  print(c1)
  print()
  print(c1.most_common(3))

  # what is common between classes? intersection of dictionaries
  print()
  print(" intersection of two dictionaries:")
  print(c1&c2)


if __name__ =="__main__":
  main()
