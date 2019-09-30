# Demonstrate the use of keyword-only arguments


# use keyword-only arguments to help ensure code clarity
def myFunction(arg1, arg2, *, suppressExceptions=False):
    print(arg1, arg2, suppressExceptions)


def main():
    # try to call the function without the keyword
    # myFunction(1, 2, True)
    myFunction(1, 2, suppressExceptions=True)


if __name__ == "__main__":
    main()
