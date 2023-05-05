
# babak poursartip
# may 5, 2023


print(max(1,2,3,4,5))

name = ['babak', 'shiva', 'behrang', 'hedyeh', 'bahram']
age    = [25,14,16,18,20]
print(min(name))
print(max(name))

print(list(zip(name,age)))

print(min(zip(name,age)))


def getage(item):
  name, age = item
  return age

print(min(zip(name,age), key=getage))


print(min(zip(name,age), key=lambda x:x[1]))
