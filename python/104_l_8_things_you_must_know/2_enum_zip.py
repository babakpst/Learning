
# babak poursartip

# May 1, 2023

#### enumerate:
# enumerate allows to iterate over a list with their index. We can also indicate the starting point of the enumeration

myList=['apple', 'peach', 'cherry', 'melon', 'cucumber']

for fruit in myList:
  print(fruit)


print()
print("with enumeration ")
for fruit in enumerate(myList, start = 2):
  print(fruit, fruit[0], fruit[1])

print()
print("with enumeration ")
for ind, fruit in enumerate(myList, start = 2):
  print(ind, fruit)

