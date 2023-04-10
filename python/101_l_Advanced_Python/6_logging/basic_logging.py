
# Babak Poursartip
# 12/26/2019

# Advanced python: linkedin course
# logging api

# use the built-in logging module
import logging



def main():

  print()
  print(" Program starts ...")
  print()

  # use basicConfig to configure logging
  # This line indicates that all the messages should be sent to the output.
  # Without this message only Warning, Error, and Critical would run.
  # filename transmits the output the output file rather that the terminal.
  # The output appends to the previous one, after each run.
  # filemode allows for overwriting the previous log file.
  logging.basicConfig(level=logging.DEBUG,
                      filename = "output.log",
                      filemode = "w")



  # try out each of the following log levels
  logging.debug(" This a debug message")
  logging.info(" This is an info message")
  logging.warning(" This is a warning message")
  logging.error(" This is an error message")
  logging.critical(" This is a critical message")

  # output formatted strings to the log
  logging.info(" Here is a {} variable and an int: {}".format("String", 10))

  print()
  print(" End successfully.")
  print()



if __name__=="__main__":
  main()
