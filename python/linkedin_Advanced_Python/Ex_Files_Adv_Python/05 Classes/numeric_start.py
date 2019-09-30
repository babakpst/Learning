# give objects number-like behavior


class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return "<Point x:{0},y:{1}>".format(self.x, self.y)

    # TODO: implement addition
    def __add__(self, other):
        pass

    # TODO: implement subtraction
    def __sub__(self, other):
        pass

    # TODO: implement in-place addition
    def __iadd__(self, other):
        pass


def main():
    # Declare some points
    p1 = Point(10, 20)
    p2 = Point(30, 30)
    print(p1, p2)

    # TODO: Add two points

    # TODO: subtract two points

    # TODO: Perform in-place addition


if __name__ == "__main__":
    main()
