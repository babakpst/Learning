# Babak Poursartip
# 18 November 2019
# Ordered dictionary

from collections import OrderedDict

def main():
  # list of sport teams with wins and losses
  sportTeams = [("Royals", (18,12)), ("Rockets", (24,4)), 
  ("Cardinals", (20, 10)), ("Dragons", (22,8)), ("Kings", (15, 15)), 
  ("Chargers", (20, 10)), ("Jets", (16, 14)), ("Warriors", (25, 5))]


  # sort thte teams by the number of wins
  sortedTeams = sorted(sportTeams, key=lambda t: t[1][0], reverse=True)

  print(sortedTeams)


if __name__=="__main__":
  main()