# customize string representations of objects


class myColor():
    def __init__(self):
        self.red = 50
        self.green = 75
        self.blue = 100

    # TODO: use getattr to dynamically return a value
    def __getattr__(self, attr):
        pass

    # TODO: use setattr to dynamically return a value
    def __setattr__(self, attr, val):
        super().__setattr__(attr, val)

    # TODO: use dir to list the available properties
    def __dir__(self):
        pass

def main():
    # create an instance of myColor
    cls1 = myColor()
    # TODO: print the value of a computed attribute

    # TODO: set the value of a computed attribute

    # TODO: access a regular attribute

    # TODO: list the available attributes


if __name__ == "__main__":
    main()
