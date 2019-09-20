
# Babak Poursartip
# 19 September 2019
# Linkedin Course:
#https://www.linkedin.com/learning/learning-python-2/reading-and-writing-files?u=2163426


def main():

  # opening a file and writing some text there.
  print(" opening the file ...")
  f = open("example.txt", "w+")  # w means write, and + menas that create the file if it does not exist.

  for i in range(10):
    f.write("This is line: " + str(i)+ "\r\n")

  f.close()

  # append more lines at the end of the previous file.
  f = open("example.txt", "a")
  for i in range(10):
    f.write("This is line: " + str(i)+ "\r\n")
  f.close()

  # read from a file
  f = open("example.txt", "r")

  if f.mode == 'r':
    content = f.read()
    print(content)

  f.close()

  print("New reading method: ")

  f = open("example.txt", "r")
  
  if f.mode == 'r':
    fl = f.readlines()
    for x in fl:
      print ("{0} {1}".format(" form file", x))


  f.close()

  print(" End of the code!")

if __name__ == "__main__":
  main()