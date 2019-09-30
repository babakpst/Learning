# Babak Poursartip
# September 15, 2019
# Starting on the online course in linkedin: 
# https://www.linkedin.com/learning/learning-python-2/building-hello-world?u=2163426


# IMPORTANT NOTE: There is no switch statement python

def main():
  x, y = 10, 100
  
  # conditional flow uses if, elif, else  
  if(x < y):
    st= "x is less than y"
  elif (x == y):
    st= "x is same as y"
  else:
    st= "x is greater than y"
  print (st)

  # conditional statements let you use "a if C else b"
  st = "x is less than y" if (x < y) else "x is greater than or equal to y"
  print (st)
  
  # Python does not have support for higher-order conditionals
  # like "switch-case" in other languages
  
if __name__ == "__main__":
  main()
