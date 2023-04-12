
# April 10, 2023

# Generator functions
# - written like regular functions,
# - utilize the yield keyword,
# - return a lazy iterator - not stored in memory-> THIS IS IMPORTANT
# To see the contect of generator object:
#   - convert type (for example to list)
#   - Loop
#   - next()
# Note that generator objects are exhausted after use.
words = ["babak", "shiva", "word", "international", "iran", "USA", "irland"]


def contains_i(words):
  i_words = []
  for word in words:
    if "i" in word:
      i_words.append(word)
  return i_words

def contains_i2(words):
  for word in words:
    if "i" in word:
      yield word # This is a generator object-saves memory


print()
print("using function: ")
print(contains_i(words))

print()
print("using function2: ")
print(contains_i2(words)) # prints the generator object
print(list(contains_i2(words))) # to see what it is in the generator object- converting generator object to list.

print()
print("using list comprehensions: ")
i_words2=[x for x in words if "i" in x]
print(i_words2)

# convert genrator object to a variable
gen_ob = contains_i2(words)
# convert the type
print()
print("convert to list: ")
print(list(gen_ob))


print()
print("convert to set-exhausting: ")
print(set(gen_ob)) # returns an empty set, bcs we already used our obj previously, there is nothing in it now.


print()
print("set is working now")
print(set(contains_i2(words)))

# loop
print()
print("loop: ")
gen_ob = contains_i2(words)
for el in gen_ob:
  print(el)

# next
print()
print("next: ")
gen_ob = contains_i2(words)
print(next(gen_ob))
print(next(gen_ob))
print(next(gen_ob))
print(next(gen_ob))

#print(next(gen_ob)) # This would be an error, because there is nothing in the object now.

