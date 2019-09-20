
# Babak Poursartip
# 19 September 2019
# Linkedin Course:
#https://www.linkedin.com/learning/learning-python-2/reading-and-writing-files?u=2163426

import os
#from os import path
import datetime
from datetime import date, time, timedelta
import time


def main():

  print("{0} {1}".format(" name of the operating system", os.name))

  # check if a path exists
  print ("{0} {1}".format(" Item exists", os.path.exists("example.txt")))
  print ("{0} {1}".format(" Item is a file:", os.path.isfile("example.txt")))
  print ("{0} {1}".format(" Item is a directory:", os.path.isdir("example.txt")))

  # work with file path
  print ("{0} {1}".format(" Item path: ",os.path.realpath("example.txt") ))
  print ("{0} {1}".format(" Item path and name: ", os.path.split(os.path.realpath("example.txt"))))

  # Get the modification time of a file
  t = time.ctime(os.path.getmtime("example.txt"))
  print ("{0} {1}".format(" The modification time is:", t))
  print(datetime.datetime.fromtimestamp(os.path.getmtime("example.txt")))

    # Calculate how long ago the item was modified
  td= datetime.datetime.now() - datetime.datetime.fromtimestamp(os.path.getmtime("example.txt"))
  print ("It has been " + str(td) + " since the file was modified")
  print ("Or, " + str(td.total_seconds()) + " seconds")


if __name__ == "__main__":
  main()