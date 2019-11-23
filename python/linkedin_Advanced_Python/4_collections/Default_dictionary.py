
# Babak Poursartip  
# 03 November 2019

# default dictionary

from collections import defaultdict

def main():
  print(" Default dectionary starts ...")

  # Some examples of dictionary
  ages = {'Babak':36, 'Shiva': 33, 'Hedyeh': 30, 'Behnaz':34}
  
  print(ages['Babak'])
  ages['maryam']= 38

  print(ages['maryam'])
  

  print()
  print(' Now the lesson: ')
  print()

  # list
  fruits = ['apple', 'kiwi', 'banana', 'orange', 
            'banana', 'apple', 'peach', 'grapefruit', 
            'orange']

  # without default function from the collection library
  fruitCounter = {}

  for fruit in fruits:
    print("{:<20} {}".format("counting: ", fruit))
    if fruit in fruitCounter.keys():
      fruitCounter[fruit] += 1
    else:
      fruitCounter[fruit] = 1

  for k,v in fruitCounter.items():
    print("{}: {}".format(k,v))


  print()
  print(" default dictionary ...")  
  print()

  # with the default function

  # This line says that if I am trying to access a key that does not exist 
  # create a default value for me using this object (int) as the constructor. 
  # By default, it initializes all the items to zero.
  fruitCounter2 = defaultdict(int)

  for fruit in fruits:
    fruitCounter2[fruit] += 1

  for k,v in fruitCounter2.items():
    print("{}: {}".format(k,v))


  print()
  print(" default dictionary ...")  
  print()

  # with the default function, initialized the values of dictionary to 100

  # This line says that if I am trying to access a key that does not exist 
  # create a default value for me using this object (int) as the constructor. 
  # By default, it initializes all the items to zero.
  fruitCounter3 = defaultdict(lambda : 100)

  for fruit in fruits:
    fruitCounter3[fruit] += 1

  for k,v in fruitCounter3.items():
    print("{}: {}".format(k,v))



if __name__=="__main__":
  main()