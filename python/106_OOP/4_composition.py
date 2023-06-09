
# babak poursartip
# June 9, 2023

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



em1 = employee("babak", "sar", 122, 4343)

print(em1.p, em1.ID, em1.salary)
