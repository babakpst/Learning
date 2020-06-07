
# Babak Poursartip

msg = "Babak"
print(msg)


print('spam eggs')  # single quotes
print('doesn\'t')  # use \' to escape the single quote


print("doesn't")  # ...or use double quotes instead
print('"Yes," they said.')
print("\"Yes,\" they said.")
print('"Isn\'t," they said.')

print('"Isn\'t," they said.')


s = 'First line.\nSecond line.'  # \n means newline
print(s)  # without print, \n is included in the output 'First line.\nSecond line.'
          # with print, \n produces a new line

          
print('C:\some\name')  # here \n means newline!
print( r'C:\some\name')  # note the r before the quote

# """
"""
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
"""


# Strings can be concatenated (glued together) with the + operator, and repeated with *
text = 3 * 'un' + 'ium'
print(text) 
print('Py' 'thon')  # 'Python'

# This feature is particularly useful when you want to break long strings:
text2 = 'Put several strings within parentheses '
'to have them joined together.'
print(text2)

print('Put several strings within parentheses '
'to have them joined together.')

prefix = 'Py'
#print(prefix 'thon')  # can't concatenate a variable and a string literal
print(prefix + 'thon') #


word = 'Python'
print(word[0])    # character in position 0
print(word[5])    # character in position 5
print(word[-1])   # last character
print(word[0:2])  # characters from position 0 (included) to 2 (excluded)


