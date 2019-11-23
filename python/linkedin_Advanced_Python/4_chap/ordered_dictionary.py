# Babak Poursartip
# 18 November 2019
# Ordered dictionary

# dictionary does not keep track of the order of items in the dictionary.
# ordered dictionary is a dictionary that remembers the order in which items are inserted.


from collections import OrderedDict

def main():
  # list of sport teams with wins and losses (list of toples)
  sportTeams = [("Royals", (18,12)), ("Rockets", (24,4)), 
  ("Cardinals", (20, 10)), ("Dragons", (22,8)), ("Kings", (15, 15)), 
  ("Chargers", (20, 10)), ("Jets", (16, 14)), ("Warriors", (25, 5))]

  print("{} {}".format(" This is the dictionary: \n", sportTeams))
  
  print(" Iterating the items in a dictionary: ")
  for ii in sportTeams:
    print(ii)
  
  print(" Separating the key and values in a dictionary")
  for key, value in sportTeams:
    print("{0} {2:20s} {1} {3} ".format(" This is the key:", " and the value:", key, value ) )


  print(sportTeams[1][0])

  # sort thte teams by the number of wins
  sortedTeams = sorted(sportTeams, key=lambda t: t[1][0], reverse=True)

  print(" Iterating the items in a dictionary after sorting: ")
  for ii in sortedTeams:
    print(ii)

  # ordered dictionary: each item in the ordered dictionary has an order
  teams = OrderedDict(sortedTeams)
  print(teams)

  # use pop item to remove items from the ordered dictionary (similar to stack)
  # default value for popitem is true which means the last item added, or false which means the first item added.
  team, winlose = teams.popitem(False)  # will remove the first item
  print(" The top team: ", team, winlose) 
  print(" The dictionary after removing the top team: ")
  print(teams)


  # What are the next top 4 teams?
  for i, team in enumerate(teams, start=1):
    print(i, team)
    if i == 4:
      break

  # Check the equality of ordered lists: not only the items should be same, but the orders should be same.
  aa = OrderedDict({"a":1,"b":2,"c":3})
  bb = OrderedDict({"a":1,"c":3,"b":2})

  print(" Equality test: ", aa==bb)

  # comparing an ordinary dictionary with an ordered dictionary: here order does not matter here.
  cc = OrderedDict({"a":1,"b":2,"c":3})
  dd = {"a":1,"c":3,"b":2}

  print(" Equality test: ", cc==dd)




if __name__=="__main__":
  main()