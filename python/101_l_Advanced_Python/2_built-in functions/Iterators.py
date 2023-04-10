
# Babak Poursartip
# Advanced Python
# 20 October 2019

# built-in mehtods for iterator functions

def main():

  days = ["Sun", "Mon", "Tue", "Wed", "Fri", "Sat"]
  daysFre=["Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"]

  print(days)

  # use iter to create an iteration over a list
  i = iter(days)
  print(next(i))
  print(next(i))
  print(next(i))
  #print(i)
  print()

  # using the iter function to read each line of a code
  fileP = open("iter_example.txt","r")
  for line in iter(fileP.readline, ''):
    print(line)

  # This loop print the items in the list
  for m in days:
    print(m)

  # If we want the items in the list and the corresponding couner
  for m in range(len(days)):
    print (m+1, days[m])

  # Practically, enumerate is similar to the previous loop 
  for i, m in enumerate(days, start=1):
    print(i,m)

  # if you have two lists and you would like to loop over both simultaneously
  for m in zip(days, daysFre):
    print(m)

  for i,m in enumerate(zip(days, daysFre), start=1):
    print(i, m[0], "=", m[1], "in French")


if __name__ == "__main__":
  main()
