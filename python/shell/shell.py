
# Babak Poursartip
# 22 September 2019

# running shell commands in Python


import os

def main():

  # running a command and getting the output in terminal
  cmd1='ls -la ../'
  os.system(cmd1)


  print()
  print("This is a new command:")
  # running a command and storing the results in a variable
  results = os.popen(cmd1).read()
  print("printing the results:")
  print(results)




if __name__ == "__main__":
  main()
