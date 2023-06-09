
# babak poursartip
# June 7, 2023

#The super() function is used to give access to methods and properties of a parent or sibling class.
#The super() function returns an object that represents the parent class.
# super has two major use cases:
#- Allows us to avoid using the base class name explicitly
#- Working with Multiple Inheritance

# in case of duplicates attributes/vars in the inherited class, python is using a method called "the method
# resolution order (mro)" to look up in the class. It starts looking for this attribute in the same class, then in the
# inherited classes in the order they have been defined. So, it always writes the first that it finds.


class person:
  def __init__(self, firstname, lastname):
    self.fname = firstname
    self.lname = lastname

  def printPersonName(self):
      print(f" The name is: {self.fname} {self.lname}")

class job(person):
  def __init__(self, firstname, lastname, jobtitle, salary):
    super().__init__(firstname, lastname)
    self.title = jobtitle
    self.salary = salary


class employee(job):
  def __init__(self, firstname, lastname, jobtitle, salary, eID):
    super().__init__(firstname, lastname, jobtitle, salary)
    self.id = eID


em1 = employee("Babak", "Poursartip", "eng", 123, "I195")
print(em1.fname, em1.lname, em1.title, em1.salary, em1.id)
em1.printPersonName()


j1 = job("shiva", "aryan", "fmp", 23)
j1.printPersonName()



# class testSuper(person):
#   def __init__(self, fname, lname, nonesense):
#     self
#     self.n = nonesense


# t1 = testSuper("shiva", "aryan", 23)
# t1.printPersonName()

# Multiple inheritance ===========================================
print("\n\n")
class Animal:
  def __init__(self, Animal):
    print(Animal, 'is an animal.');
    self.name = Animal

class Mammal(Animal):
  def __init__(self, mammalName):
    print(mammalName, 'is a warm-blooded animal.')
    super().__init__(mammalName)
    self.mammal = "haveBreast"

class NonWingedMammal(Mammal):
  def __init__(self, NonWingedMammal):
    print(NonWingedMammal, "can't fly.")
    super().__init__(NonWingedMammal)
    self.nWing ="noWing"
    self.twin = "Twin1"


class NonMarineMammal(Mammal):
  def __init__(self, NonMarineMammal):
    print(NonMarineMammal, "can't swim.")
    super().__init__(NonMarineMammal)
    self.marine = "havefin"
    self.twin = "Twin2"


class Dog(NonMarineMammal, NonWingedMammal):
  def __init__(self):
    print('Dog has 4 legs.');
    super().__init__('Dog')
    self.dogName = "Twinky"

d = Dog()
print(f"{d.mammal}  {d.dogName}  {d.marine} {d.name} {d.nWing} {d.twin}" )  # for twin it writes Twin2, becasue NonMarineMammal Dog intherited this class first.

print(f"method resolution order \n {Dog.__mro__}") # __mro__ prints the method resolution order: Dog -> NonMarineMammal -> NonWingedMammal -> Mammal -> Animal

print('')
bat = NonMarineMammal('Bat')
