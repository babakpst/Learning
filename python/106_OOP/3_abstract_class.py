
# babak poursartip
# June 8, 2023

# abstract base class, a common design pattern to create other classes from. But, we don't want to allow instantiation
# form the base class.

from abc import ABC, abstractmethod # ABC stands for abstract base class


# abstract class
class CalculateArea(ABC):
    def __init__(self):
        super().__init__()

    # this virtual func prevents instantiation from the this base class. No implementation in the base class, and each
    # subclass must override this method separately.
    @abstractmethod
    def Area(self):
        pass

# another abstract class - interface
class ToJason(ABC):
    @abstractmethod
    def ToJ(self): # this func should be defined in any child class
        pass

class Rec(CalculateArea):
    def __init__(self, width, len):
        super().__init__()
        self.width = width
        self.len = len

    def Area(self):
        return self.width*self.len


class Circle(CalculateArea, ToJason):
    def __init__(self,radius):
        super().__init__()
        self.radius = radius

    def Area(self):
        return self.radius*self.radius*3.14

    def ToJ(self):
        return f"{{ \" Circle \" : {str(self.Area())} }}"


myRec = Rec(5,6)
print(f" The area of rectangle is {myRec.Area()}")

myCir = Circle(5)
print(f" The area of rectangle is {myCir.Area()}")
print(myCir.ToJ())
