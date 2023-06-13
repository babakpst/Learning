# babak poursartip
# June 12, 2023

# Magic functions are defined by default for each class, but we can override them.


class person:
    def __init__(self,firstname, lastname, age) -> None:
        super().__init__()
        self.firstname = firstname
        self.lastname = lastname
        self.age = age

    # a user friendly string description of the object for the users
    def __str__(self) -> str:
        return f"{self.firstname} {self.lastname} is {self.age}."

    # a more developer facing string, ideally use to recreating the object in the current state.
    # Mainly used for debugging purposes, so it prints a lot of detailed information
    def __repr__(self) -> str:
        return f"name = {self.firstname} - lastname = {self.lastname} - age = {self.age}"

    def __eq__(self, __value: object) -> bool:
        if not isinstance(__value, person):
            return False
            # raise ValueError(" Can not compare person with a different class")

        return (self.firstname == __value.firstname and self.lastname == __value.lastname and self.age == __value.age )

    # this is for >, we have funcs for <, <=, >+. etc.
    def __gt__(self, __value: object) -> bool:
        if not isinstance(__value, person):
            # return False
            raise ValueError(" Can not compare person with a different class")
        return self.age > __value.age

    def __le__(self, __value: object) -> bool:
        if not isinstance(__value, person):
            # return False
            raise ValueError(" Can not compare person with a different class")
        return self.age <= __value.age

#=======================
# Magic functions for strings

per = person("babak", "poursartip", 25)
# without the string object defined, it prints <__main__.person object at 0x7fa284d53d60>
# with the __str__ func, it calls the __str__ funcs, and not the __repr__ function.
print(per)

print(str(per)) # calling str function
print(repr(per)) # calling repr function

#=======================
# Magic functions for equality
per1 = person("babak", "poursartip", 25)
per2 = person("behrang", "poursartip", 25)

# There is a magic functions for equality: __eq__. If there is no __eq__ is defined in the class, it returns false,
# bcs python does not do attribute by attribute comparison by objects, otherwise, it uses the __eq__ function.
print(f" persons are the same: {per1==per2}")


#=======================
# Magic functions for logical operators
per3 = person("roger", "poursartip", 26)
print(f" persons are older: {per3 > per2}") #true
print(f" persons are younger or equal: {per1 <= per2}") #true

#=======================
# With le magic function defined, we can sort objects.
per4 = person("shiva", "aryan", 20)

people = [per1, per2, per3, per4]
people.sort()
print(people)
print([ind.firstname for ind in people ])















