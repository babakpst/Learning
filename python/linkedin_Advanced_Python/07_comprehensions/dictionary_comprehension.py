
# Babak Poursartip
# 12/27/2019

# Advanced python: linkedin
# Dictionary comprehension

def main():
  print(" Code starts ...")
  print()

  CTemps = [0, 10, 15, 20, 25, 30, 35, 100]

  # use a comprehension to build a dictionary
  tempDict = {t: (t*9/5)+32 for t in CTemps}
  tempDict2 = {t: (t*9/5)+32 for t in CTemps if t < 100}

  print(tempDict)
  print(tempDict2)
  print(tempDict2[15])

  # merge two dictionaries with a comprehension
  team1 = {"Jones": 24, "Jameson": 18, "Smith": 58, "Burns": 7}
  team2 = {"White": 12, "Macke": 88, "Perce": 4}


  newTeam = {k:v for team in (team1, team2) for k,v in team.items()}
  print(newTeam)

  print()
  print(" End successfully")


if __name__=="__main__":
  main()