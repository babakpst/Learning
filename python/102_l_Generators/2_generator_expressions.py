
# April 11, 2023

# list comprehension vs generator expression:
# To see the contect of generator object:
#   - convert type (for example to list)
#   - Loop
#   - next()
# comprehension is faster, but generator saves memory.

import sys
import cProfile

print("list comprehension: ")
mlist = [no**2 for no in range(1,10)]
print(mlist)

gen_exp = (no**2 for no in range(1,10))

print("generator expression: ")
print(list(gen_exp))



print("generator expression: ")
print(set((no**2 for no in range(1,10))))

for num in (no**2 for no in range(1,10)):
  print(num)


check_lc = [no*2 for no in range(1,5000)] # list comprehension
check_ge = (no*2 for no in range(1,5000)) # gnerator expression

print("size of List Comprehension:   {}".format(sys.getsizeof(check_lc))) # 43032
print("size of Generator Expression: {}".format(sys.getsizeof(check_ge))) # 112

print("List Comprehension timing:   {}".format( cProfile.run("max( [no*2 for no in range(1,10000)] )") ))
print("Generator Expression timing: {}".format( cProfile.run("max( (no*2 for no in range(1,10000)) )") ))
