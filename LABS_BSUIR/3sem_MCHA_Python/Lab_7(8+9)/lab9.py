print(f"Методы Эйлера и Рунге-Кутта\n")

import numpy as np
import matplotlib.pyplot as plt

plotdots = 10**3
eps = 10**-3

# Пример 1
# def yder(x, y):
#     return x**2


# y0 = 0
# LEFT, RIGHT = -3, 3


# def ans(x):
#     return x**3 / 3


# xplot = np.linspace(LEFT, RIGHT, plotdots)
# yplot = [ans(xdot) for xdot in xplot]
# plt.plot(xplot, yplot, "black")

# Пример 2
# def yder(x, y):
#     return y**2


# y0 = 1
# LEFT, RIGHT = -0.5, 0.5


# def ans(x):
#     return 1 / (1 - x)


# xplot = np.linspace(LEFT, RIGHT, plotdots)
# yplot = [ans(xdot) for xdot in xplot]
# plt.plot(xplot, yplot, "black")

# Пример 3
# def yder(x, y):
#     return x**2 + y


# y0 = 1
# LEFT, RIGHT = -1, 1


# def ans(x):
#     return 3 * np.exp(x) - x**2 - 2 * x - 2


# xplot = np.linspace(LEFT, RIGHT, plotdots)
# yplot = [ans(xdot) for xdot in xplot]
# plt.plot(xplot, yplot, "black")

# Задание
m, a = 2.0, 0.9


def yder(x, y):
    return (a * (1 - y**2)) / ((1 + m) * x**2 + y**2 + 1)


y0 = 0
LEFT, RIGHT = 0, 1


def Euler(xdot, N):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        ydots += [y + h * yder(x, y)]
    return ydots


def BetterEuler(xdot, N):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        ydots += [y + h * yder(x + h / 2, y + h / 2 * yder(x, y))]
    return ydots


def RungeKutta(xdot, N):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        K1 = h * yder(x, y)
        K2 = h * yder(x + h / 2, y + K1 / 2)
        K3 = h * yder(x + h / 2, y + K2 / 2)
        K4 = h * yder(x + h, y + K3)
        ydots += [y + 1 / 6 * (K1 + 2 * K2 + 2 * K3 + K4)]
    return ydots


def GetValueAtPoint(method, x):
    n = 1
    while True:
        olddots, newdots = method(x, n), method(x, 2 * n)
        if max(abs(newdots[2 * i] - olddots[i]) for i in range(n + 1)) < eps:
            return newdots[-1], 2 * n
        else:
            n *= 2


def CreateYdots(method, xdots):
    ydots = []
    maxn = 0
    midn = []
    for x in xdots:
        y, n = GetValueAtPoint(method, x)
        ydots.append(y)
        maxn = max(maxn, n)
        midn += [n]
    midn = sum(midn) / len(xdots)
    return ydots, midn, maxn


print(f"Количество точек для вычисления = {plotdots}")
print(f"Точность = {eps}")

xdots = [LEFT + (RIGHT - LEFT) / plotdots * i for i in range(plotdots + 1)]

ydots, midn, maxn = CreateYdots(Euler, xdots)
print(f"\n MidN / MaxN отрезков в методе Эйлера = {midn:.6f} / {maxn}")
plt.plot(xdots, ydots, "y")

ydots, midn, maxn = CreateYdots(BetterEuler, xdots)
print(f"\n MidN / MaxN отрезков в модифицированном методе Эйлера = {midn:.6f} / {maxn}")
plt.plot(xdots, ydots, "b--")

ydots, midn, maxn = CreateYdots(RungeKutta, xdots)
print(f"\n MidN / MaxN отрезков в методе Рунге-Кутта = {midn:.6f} / {maxn}")
plt.plot(xdots, ydots, "r:")

plt.show()