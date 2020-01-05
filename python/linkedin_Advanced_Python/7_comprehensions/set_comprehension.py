
# Babak Poursartip
# 12/27/2019

# Advanced python: linkedin
# Set comprehension

def main():
  print(" Code starts ...")
  print()

  # define a list of temperature data points
  ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
  ftemps1 = [(t*9/5)+32 for t in ctemps]
  ftemps2 = {(t*9/5)+32 for t in ctemps}
  
  print(ftemps1)
  print(ftemps2)

  # build a set of unique Fahrenheit temperatures
   
  sTemp = " Babak is learning advanced python from linkedin."
  chars = {c.upper() for c in sTemp}
  print(chars)
  
  # build a set from an input source
  chars = {c.upper() for c in sTemp if not c.isspace()}
  print(chars)

  print()
  print(" Code ends")

if __name__=="__main__":
  main()