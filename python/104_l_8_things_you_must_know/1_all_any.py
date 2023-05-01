
# babak poursartip

# May 1, 2023

##### all ########
# All function: make sure all items are true
# ex: see if all  numbers are below 100
trueTuple = (0,10,50,100)
falseTuple = (0,10,150,100)

isItTrue = all( 0<= val <=100 for val in trueTuple )
print(" is it true: {}".format(isItTrue))

assert isItTrue == True

isItTrue = all( 0<= val <=100 for val in falseTuple )
print(" is it true: {}".format(isItTrue))

assert isItTrue == False


##### any ########
# any function: make sure at least one item is true/not zero
print("")
print(" any ")
print(all((0,0,0,0,1))) # false
print(any((0,0,0,0,0))) # false
print(any((0,0,0,0,1))) # true

# ex: see if there is a digit in char

withoutDigits = 'This is a text without digits.'
withDigits = 'This is a text with some digits: 1.'

isItTrue = any( char.isdigit() for char in withoutDigits )
print(" is it true: {}".format(isItTrue))

assert isItTrue == False

isItTrue = any( char.isdigit() for char in withDigits )
print(" is it true: {}".format(isItTrue))

assert isItTrue == True
