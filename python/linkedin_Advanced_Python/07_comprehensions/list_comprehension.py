
# Babak Poursartip
# 12/27/2019

# Advanced python: linkedin
# list comprehension


def squares(temp):
  return temp*temp

def main():
  print()
  print(" Code starts ...")

  # define two lists of numbers:
  evens = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
  odds = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]  

  # Perform a mapping and filter funciton on a list: squars of the numbers in the list
  evenSquared1 = list(map(squares, evens))
  evenSquared2 = list(map(lambda t: t*t , evens))
  print(evenSquared1)
  print(evenSquared2)

  evenSquared3 = list(map(lambda t: t*t , filter(lambda t:t>4 and t<16, evens) ))
  print(evenSquared3)

  # Derive a new list of number from a given list- using list comprehension
  evenSquared4 = [ t*t for t in evens ]
  print(evenSquared4)

  # Limit the items operated on with a predacate condition
  oddSquares = [t*t for t in odds if t>3 and t<17]
  print(oddSquares)

  print(" End successfully")
  print()

if __name__=="__main__":
  main()