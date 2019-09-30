# Babak Poursartip
# September 16, 2019
# libraries: data and time

from datetime import date
from datetime import time
from datetime import datetime


def main():

  # date objects
  today = date.today()
  print(" Today date is: ", today)

  # date components:
  print(" date components: ", today.day, today.month, today.year)

  # weekday number
  print(" Today's weekday number: ", today.weekday())

  days = ["Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"]

  print(" Which is a: ", days[today.weekday()])


  # datetime object
  now = datetime.now()
  print(" time now is:", now)

  time = datetime.time(datetime.now())
  print(" time is: ", time)




if __name__ == "__main__":
  main()