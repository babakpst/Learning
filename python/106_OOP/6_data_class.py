
# babak poursartip
# June 15, 2023


# dataclass help create and manage classes that mostly exists for holding data. we don't need to define the
# __init__class. dataclass will automatically rewrite the __init__ function to automatically initialization the object.
# Additionally, it automatically creates the __eq__ and __repr__. In short dataclass allows writing concise code,
# at the same time, they are just like any other python classes.


from dataclasses import dataclass

@dataclass
class person:
    firstname: str
    lastname: str
    age: int
    salary: float

    def dosomthing(self):
        return f" You are awesome {self.firstname}"



per1 = person("babak", "poursartip", 12,125.5)
per2 = person("babak", "poursartip", 12,125.5)

print(per1) # calls the __repr__
print(per1.age)
print(per1==per2) # calls the __eq__

print(per1.dosomthing())
