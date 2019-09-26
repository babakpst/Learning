
# Babak Poursartip
# 25 September 2019

# linkedin course:
# https://www.linkedin.com/learning/learning-python-2/parsing-and-processing-html?u=2163426

from html.parser import HTMLParser

metacount = 0;

class MyHTMLParser(HTMLParser):
  # function to handle an opening tag in the code
  # this will be called when the closing ">" of the tag is reached


  def handle_comment(self, data): # This is already in html class
    print(" Encountered comment: ", data)
    pos = self.getpos()
    print ("\tAt line: ", pos[0], " position ", pos[1])


  def handle_starttag(self, tag, attrs):
    global metacount
    if tag=='meta':
      metacount +=1
    print(" Encountered tag: ", tag)
    pos = self.getpos()
    print ("\tAt line: ", pos[0], " position ", pos[1])

    if attrs.__len__() > 0:
      print("\tAttribute")
      for a in attrs:
        print("\t", a[0], "=", a[1])
    

  def handle_endtag(self, tag):
    print(" Encountered tag: ", tag)
    pos = self.getpos()
    print ("\tAt line: ", pos[0], " position ", pos[1])

  def handle_data(self, data):
    if data.isspace():
      return
    print(" Encountered data: ", data)
    pos = self.getpos()
    print ("\tAt line: ", pos[0], " position ", pos[1])

def main():

  # instantiate the parser and feed it some HTML
  parser = MyHTMLParser()
  f = open("samplehtml.html")
  if f.mode == 'r':
    contents = f.read()
    parser.feed(contents)
  print(" Meta tags found: " + str(metacount))




if __name__ == "__main__":
  main()