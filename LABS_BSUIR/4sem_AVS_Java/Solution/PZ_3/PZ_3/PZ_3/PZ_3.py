from math import copysign, fabs, floor, isfinite, modf

def float_to_bin_fixed(f):
    if not isfinite(f):
        return repr(f)
    sign = '-' * (copysign(1.0, f) < 0)
    frac, fint = modf(fabs(f))  # split on fractional, integer parts
    n, d = frac.as_integer_ratio()  # frac = numerator / denominator
    assert d & (d - 1) == 0  # power of two
    return f'{sign}{floor(fint):b}.{n:0{d.bit_length() - 1}b}'

def add_binary_decimals(decimal_num1, decimal_num2):
    decimal_str1 = str(decimal_num1)
    decimal_str2 = str(decimal_num2)
    int_part1, frac_part1 = decimal_str1.split('.')
    int_part2, frac_part2 = decimal_str2.split('.')
    max_len = max(len(frac_part1), len(frac_part2))
    frac_part1 = frac_part1.ljust(max_len, '0')
    frac_part2 = frac_part2.ljust(max_len, '0')
    frac_sum = int(frac_part1, 2) + int(frac_part2, 2)
    int_part_sum = frac_sum // 2
    frac_sum_binary = bin(frac_sum % 2**max_len).replace("0b", "").rjust(max_len, '0')
    int_sum = int(int_part1) + int(int_part2) + int_part_sum
    int_sum_binary = float_to_bin_fixed(int_sum)
    return int_sum_binary + '.' + frac_sum_binary

print("Nomer 7:")
a = float(input("Enter a: "))
# a1 = float_to_bin_fixed(a)
# print("In binary code:", a1)
b = float(input("Enter b: "))
# b1 = float_to_bin_fixed(b)
# print("In binary code:", b1)
c = float(input("Enter c: "))
# c1 = float_to_bin_fixed(c)
# print("In binary code:", c1)

d = (b**2 - 4*a*c)**0.5
x1 = (-b + d) / (2 * a)
x2 = (-b - d) / (2 * a)

print("x1 =", x1)
print("x2 =", x2)
print("Nomer 8:")

import math
import re
from math import copysign, fabs, floor, isfinite, modf


def float_to_bin_fixed(f):
    if not isfinite(f):
        return repr(f)
    sign = '-' * (copysign(1.0, f) < 0)
    frac, fint = modf(fabs(f))
    n, d = frac.as_integer_ratio()
    assert d & (d - 1) == 0
    return f'{sign}{floor(fint):b}.{n:0{d.bit_length() - 1}b}'


def add_binary_decimals(decimal_num1, decimal_num2):
    decimal_str1 = str(decimal_num1)
    decimal_str2 = str(decimal_num2)
    int_part1, frac_part1 = decimal_str1.split('.')
    int_part2, frac_part2 = decimal_str2.split('.')
    max_len = max(len(frac_part1), len(frac_part2))
    frac_part1 = frac_part1.ljust(max_len, '0')
    frac_part2 = frac_part2.ljust(max_len, '0')
    frac_sum = int(frac_part1, 2) + int(frac_part2, 2)
    int_part_sum = frac_sum // 2
    frac_sum_binary = bin(frac_sum % 2**max_len).replace("0b", "").rjust(max_len, '0')
    int_sum = int(int_part1) + int(int_part2) + int_part_sum
    int_sum_binary = float_to_bin_fixed(int_sum)
    return int_sum_binary + '.' + frac_sum_binary


def frange(start, stop, step):
    i = 0
    while True:
        value = start + i * step
        if value >= stop:
            break
        yield value
        i += 1


a = float(input("Enter initial value of the argument x: "))
b = float(input("Enter eventual value of the argument x: "))
h = float(input("Enter step of the changing argument x: "))
eps = input("Enter required accuracy ε: ")
while re.match(r'^[-0-9]*$', eps) is None:
    print("Error. Try again")
    eps = input()

# Empty lists for keeping results
x_list = []
y_list = []
s_list = []
n_list = []

# Calculating Y(x), S(x) and number of iterations n
for x in frange(a, b, h):
    #y = (1 - (x ** 2) / 2) * math.cos(x) - (x / 2) * math.sin(x)
    y = (1 + 2 * x ** 2) * (math.e ** (x ** 2))
    s = 0
    n = -1
    while True:
        n += 1
        #s += (-1) ** (n) * x ** (2 * n) * (2 * (n ** 2) + 1) / math.factorial(2 * n)
        s += (2 * n + 1) / math.factorial(n) * (x ** (2 * n))
        if abs(y - s) < int(eps):
            break
    x_list.append(x)
    y_list.append(y)
    s_list.append(s)
    n_list.append(n)

# Printing result as a table
print("{:<10} {:<10} {:<10} {:<10}".format("x", "Y(x)", "S(x)", "n"))
for i in range(len(x_list)):
    print("{:<10.3f} {:<10.3f} {:<10.3f} {:<10}".format(x_list[i], y_list[i], s_list[i], n_list[i]))