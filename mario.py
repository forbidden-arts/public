# Mario (more)

from cs50 import get_int

while True:
    h = get_int("Height: ")
    if h in range(1, 9):
        # No reason to print zero #'s, so let's start at one.
        for i in range(1, h + 1):
            print(" " * (h - i), end="")
            print("#" * (i), end="")
            print("  ", end="")
            print("#" * (i), end="")
            print()
        break
    else:
        pass