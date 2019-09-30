
# Babak Poursartip
# 17 September 2019

import calendar

# create a plain text calendar
c = calendar.TextCalendar(calendar.SUNDAY)
#c = calendar.TextCalendar(calendar.MONDAY)
st = c.formatmonth(2019, 1, 0, 0)
print(st)

# create an HTML formatted calendar
hc = calendar.HTMLCalendar(calendar.SUNDAY)
st = hc.formatmonth(2019,1)
print(st)

# loop over the days of a month
# zeroes mean that the day of the week is in an overlapping month
for i in c.itermonthdays(2019,8):
  print(i)


# useful utilities for locale such as the names of days and motn in both full an abbreviated form
for name in calendar.month_name:
  print(name)

for day in calendar.day_name:
  print(day)


# Calculate days based on a rule: For example, consider
# a team meeting on the first Friday of every month.
# To figure out what days that would be for each month,
# we can use this script:
print ("Team meetings will be on:")
for m in range(1,13):
  # returns an array of weeks that represent the month
  cal = calendar.monthcalendar(2017, m)
  # The first Friday has to be within the first two weeks
  weekone = cal[0]
  weektwo = cal[1]
   
  if weekone[calendar.FRIDAY] != 0:
    meetday = weekone[calendar.FRIDAY]
  else:
    # if the first friday isn't in the first week, it must be in the second
    meetday = weektwo[calendar.FRIDAY]
      
  print ("%10s %2d" % (calendar.month_name[m], meetday))  