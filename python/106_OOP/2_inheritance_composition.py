
# babak poursartip
# June 7, 2023

#The super() function is used to give access to methods and properties of a parent or sibling class.
#The super() function returns an object that represents the parent class.


class person:
  def __init__(self, firstname, lastname):
    self.fname = firstname
    self.lname = lastname

class job(person):
  def __init__(self, firstname, lastname, jobtitle, salary):
    super().__init__(firstname, lastname)
    self.title = jobtitle
    self.salary = salary


class h1(person):
  def __init__(self, firstname, lastname, nonesense):
    super.__init__(firstname, lastname)
    self.none = nonesense


class employee(job):
  def __init__(self, firstname, lastname, jobtitle, salary, eID):
    super().__init__(firstname, lastname, jobtitle, salary)
    self.id = eID



em1 = employee("Babak", "Poursartip", "eng", 123, "I195")


print(em1.fname, em1.lname, em1.title, em1.salary, em1.id)
