
# Babak Poursartip
# 17 September 2019
# linkedin class: 
# https://www.linkedin.com/learning/learning-python-2/using-timedelta-objects?u=2163426

from datetime import time
from datetime import date
from datetime import datetime
from datetime import timedelta


print(timedelta(days=365, hours=5, minutes=1))

now = datetime.now()
print(now)
print(" Today is: " + str(now))

# one year from now
print("One year from now:" + str(now + timedelta(days=365)))

print(" some time from now: ", str(now+timedelta(days=2,weeks=2)))
print(" some time from now: "+ str(now+timedelta(days=2,weeks=2)))
print(" some time from now: ", now+timedelta(days=2,weeks=2))


# some time in the past
tt = datetime.now() - timedelta(weeks=1)
ss = tt.strftime("%A %B %d, %Y")

print(" One week ago it was: " + ss )

# How many day left until next April Fool's Day
today = date.today() 
afd = date(today.year, 4, 1)

if afd < today:
  print(" April Fool's Day already went by %d days ago" %(today-afd).days)
  afd = afd.replace(year = today.year+1)

time_to_afd = afd-today
print("It's just", time_to_afd.days, "days until next April Fool's Day")


