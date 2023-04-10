
# Babak Poursartip
# 02 October 2019
# strings

# strings and bytes are not directly interchangeable
# strings contain unicode, bytes are raw 8-bit values

def main():

  # bytes:
  bb = bytes([0x41, 0x42, 0x43, 0x44, 0x45])
  print(bb)

  ss = " This is a string."
  print(ss)

  print("-"*20, "*"*25)

  # Try combining them. This will cause an error:
  # print(s+b)

  # Bytes and strings need to be properly encoded and decoded
  # before you can work on them together
  # decode converts bytes to strings
  ss2 = bb.decode("utf-8")
  print("string+bytes: {}".format(ss+ss2))

  # encode converts strings to bytes
  bb2 = ss.encode('utf-8')
  print("bytes+string: {}".format(bb+bb2))

  # encode the string as UTF-32
  bb3 = ss.encode('utf-32')
  print(bb3)



if __name__ == "__main__":
  main()
