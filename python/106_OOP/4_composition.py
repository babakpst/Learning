
# babak poursartip
# June 9, 2023

# composition relation: has a
# inheritance relation: is a


class person:
    def __init__(self, fname, lname):
      self.fname = fname
      self.lname = lname


    def __str__(self):
       return f" person: ({self.fname} {self.lname})"

class employee:
   def __init__(self, fname, lname, ID, salary):
      self.p = person(fname, lname)
      self.ID = ID
      self.salary = salary


class employee2:
   def __init__(self, ID, salary, person=None):
      self.p = person
      self.ID = ID
      self.salary = salary


em1 = employee("babak", "sartip", 122, 4343)

per = person("babak", "sartip")
em2 = employee2(122, 4343, per)

print(em1.p, em1.ID, em1.salary)

print("\n employee 2")
print(em2.p, em2.ID, em2.salary)

