
# Babak Poursartip
# 27 Oct 2019

# Variable Argument list: to build function that accepts different number of parameters
# use * in front of parameters, put that parameter at the end of regular parameters.
def adding_numbers(*arguments):
  result = 0
  for arg in arguments:
    result += arg
  return result



def main():
  print(adding_numbers(1,2,3,4,5,6))

  Numbers=[1,2, 5, 8, 12, 15]
  print(adding_numbers(*Numbers))

if __name__=="__main__":
  main()
