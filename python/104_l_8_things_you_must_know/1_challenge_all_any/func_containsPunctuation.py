
# May 1, 2023

import string

# string.punctuation is : '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'

def containPunctuation(myStr):
  print(string.punctuation)
  return any( char in string.punctuation for char in myStr )
