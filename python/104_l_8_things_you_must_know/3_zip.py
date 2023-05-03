
# babak poursartip
# May 3, 2023

# zip gets an element from each list. If one list is shorter, zip stops at the end of the shorter list.

# If we want to iterate over all the items in the list, we need to use the zip_longest from the iter tool

fruits = ['apple', 'orange', 'strawberry', 'cucumber', 'extra']
colors = ['green','orange',  'red',        'green']

for fr, co in zip (fruits, colors):
  print("{} color is {}".format(fr, co))

# using zip to pair elements
pairs = list ( zip( fruits, colors))
print(pairs)

# to separate items from a list of tuples:
fruits2, colors2 = zip(*pairs)  # * passes the items separately
print(" fruits: {}".format(fruits2))
print(" colors: {}".format(colors2))


from itertools import zip_longest
print()
print("zip longest: ")
for fr, co in zip_longest(fruits, colors, fillvalue='donknow'):
  print("{} color is {}".format(fr, co))


