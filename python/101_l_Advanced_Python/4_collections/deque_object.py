
# Babak Poursartip
# 22 November 2019

# ------------------------------------------------------------------------------
# deque object
# deque stands for Double Ended Queue
# We can use deque to append or pop objects from either sides of the list.
# They are memory efficient, if one access them from either ends.
# deque can be initialized as empty or from an iterable object.
# We can specify the max length for the deque.
# ------------------------------------------------------------------------------

# libraries
import collections
import string

def main():

  print()
  print(" This is the code for deque object ...")
  print()

  # initialize the deque with all lowercase letters.
  myDeque = collections.deque(string.ascii_lowercase)

  # length of the deque
  print("{} {}".format(" The length of myDeque: ", len(myDeque)))

  # iterating over the items in the deque
  for item in myDeque:
    #print(item.upper(), end=",")  # we can control the print statement by the end statement. The default is newline, but here, instead we are having a , and no newline.
    print(item.upper(), end=":")
    #print(item.upper())  # by default, print has a newline at the end
  print()

  # manipulating items in the deque:
  myDeque.pop()  # removes one item from right
  myDeque.popleft()  # removes one item from left

  myDeque.append(2) # append item to the right
  myDeque.appendleft(3) # append item to the left

  # let's see the results,
  print(myDeque)

  # rotate object to the right
  myDeque.rotate(10)
  print(myDeque)

  # rotate object to the left
  myDeque.rotate(-10)
  print(myDeque)

  print()
  print(" End of the code!")
  print()


if __name__ == "__main__":
  main()
