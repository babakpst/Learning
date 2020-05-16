
# Babak Poursartip
# 22 September 2019
# linkedin course: 
# https://www.linkedin.com/learning/learning-python-2/fetching-internet-data?u=2163426

# Reading data from internet

import urllib.request

def main():

  # defining the webpage URL
  webURL = urllib.request.urlopen("http://www.google.com")
  # if it prints 200 means it reads the URL correctly.
  print(" result code: " + str(webURL.getcode()))
  print()

  data =  webURL.read()
  print(data) # The HDML code for the google homepage





if __name__ == "__main__":
  main()