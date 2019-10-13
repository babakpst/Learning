
# Babak Poursartip
# 02 October 2019
# Template string

# Templates are more readable. You may not have control over the strings at all. 
# Regular method may have a security issue.


from string import Template

def main():

  # the name of this file:
  print(__name__)

  str1 = "You're watching {0} by {1}".format("Advanced Python", "Joe Marini")
  print(str1)

  # creating a template with placeholders
  templ = Template("You are watching ${title} by ${author}")
  str2 = templ.substitute(title = "magic", author = "Babak")
  print(str2)

  # use a dictionary to hold variables
  data = {
        "author": " Babak",
        "title": " Great "
  }

  str3 = templ.substitute(data)

  print(str3)


if __name__ == "__main__":
  main()