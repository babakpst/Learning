
# Babak Poursartip
# 21 September 2019

import shutil
import os
from os import path
from shutil import make_archive
from zipfile import ZipFile

def main():

  if path.exists("example.txt"):

    print("{0}".format(" Shell commands in python ... "))
    src = path.realpath("example.txt") # source
    dst = src + ".bak" # destination
    print(dst)
    shutil.copy(src, dst) # copy files only
    
    dst2 = src + ".chk" # destination
    print(dst)
    shutil.copy(src, dst2) # copy files only

    dst = src + ".bak" # destination
    print(dst)
    #shutil.copystat(src, dst) # copies everything, including the stat.

    # rename a file
    os.rename("example.txt.chk", "example2.txt.chk")
    
    # zip a file
    root_dir, tail = path.split(src)
    make_archive("archive", "zip", root_dir) # compress the entire root_dir

    print("{0}".format(" Success!"))

    # custom zip file
    with ZipFile("testzip.zip", "w") as newzip:
      newzip.write("example.txt")
      newzip.write("example.txt.bak")


if __name__ == "__main__":
  main()