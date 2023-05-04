
# babak poursartip
# May 4, 2023

import re

def del_punc_space(word):
  return re.sub('\W+', '', word)

def palindrome(word):
  word=del_punc_space(word).lower()
  reversedw=''.join(reversed(word))
  return del_punc_space(word).lower() == del_punc_space(reversedw).lower()
#  for ind, ch in enumerate(reversed(word)):
#    print(ch, word[ind])
#    if ch != word[ind]:
#      return False
#  return True

word = "Hey Babak, you are great!"
#print(reversed(word))
word = "Radar"
print( del_punc_space(word) )

print(" Palindrome: {}".format(palindrome(word)))
