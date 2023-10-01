import os
import sys
from decimal import Decimal


def square(a, b):
    if (isinstance(a, str)):
        raise Exception("Incorrect width")
    
    if (isinstance(b, str)):
        raise Exception("Incorrect height")

    a = Decimal(str(a))
    
    b = Decimal(str(b))
    
    if (a < 0):
        raise Exception("Negative width")
    elif (b < 0):
        raise Exception("Negative height")
    else:
        return float(a * b)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Неверное число аргументов")
    else:
        a = sys.argv[1]
        b = sys.argv[2]
        print(square(a, b))