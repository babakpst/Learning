
# babak poursartip
# June 15, 2023


# dataclass help create and manage classes that mostly exists for holding data. we don't need to define the
# __init__class. dataclass will automatically rewrite the __init__ function to automatically initialization the object.
# Additionally, it automatically creates the __eq__ and __repr__. In short dataclass allows writing concise code,
# at the same time, they are just like any other python classes.

# How to perform additional object initialization in a data class? Using __post_init__, it will be called after the
# build-in function has finished.

# We can define default values for attributes in the data class, subject to some rules. If we define an empty class,
# it uses the default values. Attributes without default values should come first.

from dataclasses import dataclass, field
import random


#====================================================================
def bonus_generator():
    return float(random.randrange(20,40))


@dataclass
class person:
    firstname: str = "Roger" # default varialbes
    lastname: str  = "Smart"
    age: int       = 25
    salary: float  = field(default=99.99)
    bonus: float  = field(default_factory=bonus_generator)
    #non-default: str  # this is an error, non-default attribute should precede the default attributes.

    # It is for a data class that automatically initializes the data. We can update the data later.
    # We can define new attributes that depend on the other attributes.
    def __post_init__(self):
        self.description = f"{self.firstname} {self.lastname} is {self.age}."


    def dosomthing(self):
        return f" You are awesome {self.firstname}"



per1 = person("babak", "poursartip", 12,125.5)
per2 = person("babak", "poursartip", 12,125.5)

print(per1) # calls the __repr__
print(per1.age)
print(per1==per2) # calls the __eq__

print(per1.dosomthing())
print(per1.description)


# Using default variables, by defining an object without any arguments
per3 = person()
print(per3)
print(per3.firstname)

per4 = person(lastname="intelligent")
print(per4)
print(per4.firstname)
#====================================================================

@dataclass(frozen=True)  # "The "frozen" parameter makes the class immutable
class AnImmutableDataClass:
    value1: str = "Value 1"
    value2: int = 0

    def somefunc(self, newval):
        self.value2 = newval


obj = AnImmutableDataClass()
print(obj.value1)

# attempting to change the value of an immutable class throws an exception
#obj.value1 = "Another value"
#print(obj.value1)

# Frozen classes can't modify themselves either
#obj.somefunc(20)


