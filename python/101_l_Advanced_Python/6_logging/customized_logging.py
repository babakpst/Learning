
# Babak Poursartip
# 12/26/2019

# Advanced python, linkedin course

# customized logging
# basicConfig: format - specifies a string, that controls the precise formating 
#                       of the output messaging that is sent to the log.

# basicConfig: datefmt - is used in conjunction with the format argument. 
#                        If the format argumet contains a date specifier, then 
#                        the date format argument is used to format the date 
#                        string using the same kind of the date formating 
#                        strings that you would pass to the time function.


# See the following link for formatting tokens in logging, section 15.7.7.
# https://docs.python.org/2/library/logging.html    


# import logging
import logging

# embed data in the log file
exData = {
    'user' : 'babakpst@gmail.com',

}

# another function to call log from
def NewFunc():
  print(" Inside the new function ...")
  logging.debug(" This is a debug-level message", extra = exData)
  print(" End of the new function ...")


def main():

  print()
  print(" Starting the program ...")
  print()

  # set the output file and debug level, and use a custom formatting specification
  #fmtstr = "%(asctime)s: %(levelname)s: %(funcName)s Line:%(lineno)d %(message)s"
  fmtstr = "User: %(user)s  %(asctime)s: %(levelname)s: %(funcName)s Line:%(lineno)d %(message)s"
  datestr = "%m/%d/%Y %I:%M:%S %p"
  logging.basicConfig(filename="output2.log",
                      level = logging.DEBUG, 
                      filemode = "w",
                      format = fmtstr,
                      datefmt = datestr)


  logging.info(" This is an info-level log message", extra = exData)
  logging.warning(" This is a warning-level message", extra = exData)
  NewFunc()

  # embed custom data to the log file


  print()
  print(" End successfully")
  print()

if __name__ == "__main__":
  main()