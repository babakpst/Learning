
import numpy as np

def main():

    
  print(" The code starts ....")

  size  = 5
  #ar = np.zeros(size,size, dtype=np.float)
  ar = np.zeros((size,size),  dtype=np.float)

  print(" Here is the array:")
  print(ar)
  
  vector=np.zeros(size, dtype=np.int32)
  vector[1] = 1
  print(vector)

  print(" End of the code. ")


if __name__=="__main__":
  main()
