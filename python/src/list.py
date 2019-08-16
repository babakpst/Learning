# Babak Poursartip

squares = [1,4,9,16,25]
print(squares)

print(squares[0])  # indexing returns the item
print(squares[-1])
print(squares[-3:])  # slicing returns a new list

squares += [36, 49, 64, 81, 100]
print(squares)


cubes = [1, 8, 27, 65, 125]

print(cubes)

cubes[3] = 64 
print(cubes)

cubes.append(216)
print(cubes)

print(len(cubes))


for num in squares:
  print(num)


new_List = [x**2 for x in range(1,11)]
print(new_List)
