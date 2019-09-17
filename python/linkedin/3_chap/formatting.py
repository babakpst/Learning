
# Babak Poursartip
# September 16, 2019
# libraries: data and time


from datetime import datetime

def main():
  
  # Times and dates can be formatted using a set of predefined string
  # control codes
  now = datetime.now()

  # %y/%Y - Year, %a/%A - weekday, %b/%B - month, %d - day of month
  print(now.strftime(" The current year is: %Y"))
  print(now.strftime(" %a, %d %B %y"))

  # %c - locale's date and time, %x - locale's date, %X - locale's time
  print(now.strftime(" Locale date and time: %c"))
  print(now.strftime(" Locale date: %x"))
  print(now.strftime(" Locale time: %X"))

  # %I/%H - 12/24 Hour, %M - minute, %S - second, %p - locale's AM/PM
  print(now.strftime(" Current tiem: %I:%M:%S %p"))
  print(now.strftime(" Current tiem: %I:%M:%S %P"))

  print(now.strftime(" 24-Hour Current time: %H:%M"))


if __name__ == "__main__":
  main()