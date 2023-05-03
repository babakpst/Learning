
#babak poursartip
# May 3, 2023


# iterable: anything with items that we can loop/iterate over its elements. Ex: lists, tuples, dics, sets, strings.
# sequence is a subset of iterable, that has length, index, and can be sliced. Ex: strings, lists, tuples
# tuples and strings are immutable, lists are mutable.

# Example of iterables that are not sequences: dics, sets, files, generators.

# reverse() function  || reverses a sequence in-place        || reverse function works only with mutable sequences
# slicing[::-1]       || creates a reversed copy of sequence || fast, but requires more memory-working with mutable/immutable seq.
# reversed()          || returns a reverse iterator          || for both mutable/immutable seqs.

fruits = ['apple', 'orange', 'strawberry', 'cucumber', 'extra']
print(fruits)

fruits.reverse()
print(fruits)

# reverse using slicing

print(fruits[::-1])
print(fruits)

# reverse loop
for fr in reversed(fruits):
  print(fr)

reversed_fruits = list(reversed(fruits))
print(reversed_fruits)


# how to reverse an immutable object (tuple, string)? we cannot use reverse() function, but the reversed iterable or slicing is possible.
# 'babak'.reverse() # error
print('babak'[::-1])
tuples= tuple(fruits)
print(tuples)

for fr in reversed(tuples):
  print(fr)
