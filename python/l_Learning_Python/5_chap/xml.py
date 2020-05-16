
# Babak Poursartip
# 25 September 2019

# linkedin course:
# https://www.linkedin.com/learning/learning-python-2/manipulating-xml?u=2163426

import xml.dom.minidom

def main():
  # use the parse() function to load and parse on XML file
  doc = xml.dom.minidom.parse("samplexml.xml")

  # print out the document node and name of the first child tag
  print(doc.nodeName)
  print(doc.firstChild.tagName)
  
  # get a list of XML tags from the document and print each one
  skills = doc.getElementsByTagName("skill")
  print("%d skills: " % skills.length)
  for skill in skills:
    print(skill.getAttribute("name"))
  
  # create a new XML tag and add it into the document
  newSkill = doc.createElement("skill")
  newSkill.setAttribute("name", "JQuery")
  doc.firstChild.appendChild(newSkill)

  skills = doc.getElementsByTagName("skill")
  print("%d skills: " % skills.length)
  for skill in skills:
    print(skill.getAttribute("name"))


if __name__ == "__main__":
  main()