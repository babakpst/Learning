
# May 1, 2023

# this is using pytest
# $ pytest test.py


from func_containsPunctuation import containPunctuation

def test_with_punc():
  print("with")
  assert(containPunctuation('here it is.'))
  assert(containPunctuation('here it ! is'))

def test_with_no_punc():
  print("without")
  assert(containPunctuation('here it is')==False)
  assert(containPunctuation('here it is not')==False)
