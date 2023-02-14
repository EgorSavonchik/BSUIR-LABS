#import matplotlib.pyplot as plt
import numpy as np
print("ИНТЕРПОЛЯЦИОННЫЕ МНОГОЧЛЕНЫ\n")


def input():
    x = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    p = [0.0, 0.41, 0.79, 1.13, 1.46, 1.76, 2.04, 2.3, 2.55, 2.79, 3.01]
    k = 3
    m = 1.5
    y = [(p[i] + ((-1) ** k) * m) for i in range(len(x))]
    dots = list(zip(x, y))

    # dots = [(0, 0), (1, 1)] # Пример 1
    # dots = [(-2, 3), (-1, 0), (0, -1), (1, 0), (2, 3)] # Пример 2
    # dots = [(1, 1 / 1), (2, 1 / 2), (3, 1 / 3), (4, 1 / 4), (5, 1 / 5)]  # Пример 3
    # dots = list(
    #     zip([-2, -1, 0, 1, 2], [np.tanh(i) for i in [-2, -1, 0, 1, 2]]),
    # )  # Пример 4

    return dots


dots = input()
(x, y) = map(list, zip(*dots))
print("(x,y) =", dots, "\n")


def Lagrange(dots):
    n = len(dots)
    (x, y) = map(list, zip(*dots))
    polynom = np.poly1d([0])
    for i in range(n):
        p = np.poly1d([1])
        for j in range(n):
            if j != i:
                p *= np.poly1d([1, -x[j]]) / (x[i] - x[j])
        polynom += y[i] * p
    return polynom


lagr = Lagrange(dots)
print("Многочлен Лагранжа =")
print(lagr, "\n")


def DividedDifferences(xs):
    n = len(xs)
    diffs = [[None for j in range(n - i)] for i in range(n)]
    for i in range(n):
        diffs[i][0] = y[i]
    for j in range(1, n):
        for i in range(n - j):
            diffs[i][j] = (diffs[i][j - 1] - diffs[i + 1]
                           [j - 1]) / (xs[i] - xs[i + j])
    return diffs


def Newton(dots):
    n = len(dots)
    (x, y) = map(list, zip(*dots))

    diffs = DividedDifferences(x)

    polynom = np.poly1d([0])
    for i in range(n):
        p = np.poly1d([1])
        for j in range(i):
            p *= np.poly1d([1, -x[j]])
        polynom += p * diffs[0][i]

    return polynom


newt = Newton(dots)
print("Многочлен Ньютона =")
print(newt, "\n")


xdot = 0.47
print(f"Лагранжа({xdot}) =", lagr(xdot))
print(f"Ньютона({xdot}) =", newt(xdot))
print("|Лагранжа - Ньютона| =", abs(lagr(xdot) - newt(xdot)))


print("\nИНТЕРПОЛЯЦИЯ КУБИЧЕСКИМИ СПЛАЙНАМИ\n")


def input():
    def f(x):
        return np.sin(x) + np.cos(x)

    LEFT, DOTS_COUNT, RIGHT = -2 * np.pi, 6, 2 * np.pi
    # Пример 1

    # def f(x):
    #     return 1 / (1 + x**2)

    # LEFT, DOTS_COUNT, RIGHT = -5, 5, 5
    # Пример 2

    # def f(x):
    #     return np.tan(x)

    # LEFT, DOTS_COUNT, RIGHT = -1.5, 11, 1.5
    # Пример 3

    # def f(x):
    #     return np.sin(4 * x)

    # LEFT, DOTS_COUNT, RIGHT = -1, 5, 1
    # Пример 4

    # def f(x):
    #     return np.sqrt(x)
    # LEFT, DOTS_COUNT, RIGHT = 0, 5, 4

    dots = []
    for i in range(DOTS_COUNT):
        x = LEFT + (RIGHT - LEFT) * i / (DOTS_COUNT - 1)
        y = f(x)
        dots += [(x, y)]

    return dots, f


dots, f = input()
(x, y) = map(list, zip(*dots))
print("(x,y) =", dots, "\n")



def tridiag_solve(A, b):
    A = A.copy()
    b = b.copy()
    n = len(A)

    A[0][1] /= A[0][0]
    for i in range(1, n - 1):
        A[i][i + 1] /= A[i][i] - A[i][i - 1] * A[i - 1][i]

    b[0] /= A[0][0]
    for i in range(1, n):
        b[i] = (b[i] - A[i][i - 1] * b[i - 1]) / (A[i][i] - A[i][i - 1] * A[i - 1][i])

    x = np.zeros(n)
    x[-1] = b[-1]
    for i in range(n - 2, -1, -1):
        x[i] = b[i] - A[i][i + 1] * x[i + 1]

    return x


def Spline(dots):

    n = len(dots) - 1
    (x, y) = map(list, zip(*dots))

    h = [None]
    for i in range(1, n + 1):
        h += [x[i] - x[i - 1]]

    A = [[None] * (n) for i in range(n)]
    for i in range(1, n):
        for j in range(1, n):
            A[i][j] = 0.0
    for i in range(1, n - 1):
        A[i + 1][i] = h[i + 1]
    for i in range(1, n):
        A[i][i] = 2 * (h[i] + h[i + 1])
    for i in range(1, n - 1):
        A[i][i + 1] = h[i + 1]

    F = []
    for i in range(1, n):
        F += [3 * ((y[i + 1] - y[i]) / h[i + 1] - (y[i] - y[i - 1]) / h[i])]

    A = [A[i][1:] for i in range(len(A)) if i]

    c = tridiag_solve(A, F)
    c = [0.0] + list(c) + [0.0]

    def evaluate(xdot):
        for i in range(1, len(x)):
            if x[i - 1] <= xdot <= x[i]:
                val = 0
                val += y[i]
                b = (y[i] - y[i - 1]) / h[i] + (2 * c[i] + c[i - 1]) * h[i] / 3
                val += b * (xdot - x[i])
                val += c[i] * ((xdot - x[i]) ** 2)
                d = (c[i] - c[i - 1]) / (3 * h[i])
                val += d * ((xdot - x[i]) ** 3)
                return val
        return None

    def cout():
        print("Кубический сплайн:", "\n")
        for i in range(1, len(x)):
            val = 0
            b = (y[i] - y[i - 1]) / h[i] + (2 * c[i] + c[i - 1]) * h[i] / 3
            d = (c[i] - c[i - 1]) / (3 * h[i])
            print(x[i - 1], x[i], "->")
            print(np.poly1d([d, c[i], b, y[i]]), "\n")

    return evaluate, cout

spl, cout = Spline(dots)


cout()

xdot = 0.0
print(f"          f({xdot}) =", f(xdot))
print(f"Кубический сплайн({xdot}) =", spl(xdot))
print(f"      delta({xdot}) =", abs(f(xdot) - spl(xdot)))

