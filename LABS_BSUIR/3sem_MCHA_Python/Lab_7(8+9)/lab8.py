print("Численное дифференцирование и интегрирование\n")

import numpy as np
import math

np.random.seed(12062003)


L, R, DerXdot = 0, 2, 1


# def f(x):
#     return np.arctan(x)


# def F(x):
#     return x * np.arctan(x) - (1 / 2) * np.log(x**2 + 1)


# def fd1(x):
#     return 1 / (x**2 + 1)


# def fd2(x):
#     return -(2 * x) / (x**2 + 1) ** 2


# def fd3(x):
#     return (6 * x**2 - 2) / (x**2 + 1) ** 3


# def fd4(x):
#     return -(24 * x * (x**2 - 1)) / (x**2 + 1) ** 4


# M2deLR, M4deLR = 0, 0

# L, R, DerXdot = 1, 5, 3


# def f(x):
#     return np.log(x)


# def F(x):
#     return x * (np.log(x) - 1)


# def fd1(x):
#     return 1 / x


# def fd2(x):
#     return -1 / x**2


# def fd3(x):
#     return 2 / x**3


# def fd4(x):
#     return -6 / x**4


# M2deLR, M4deLR = np.log(R), np.log(R)
# M2deLR, M4deLR = 3, 3

# L, R, DerXdot = -1, 1, 1 / 2


# def f(x):
#     return x**5


# def F(x):
#     return x**6 / 6


# def fd1(x):
#     return 5 * x**4


# def fd2(x):
#     return 20 * x**3


# def fd3(x):
#     return 60 * x**2


# def fd4(x):
#     return 120 * x


# M2deLR, M4deLR = -1, 1

L, R, DerXdot = 0, np.pi, np.pi / 2


def f(x):
    return np.cosh(x)


def F(x):
    return np.sinh(x)


def fd1(x):
    return np.sinh(x)


def fd2(x):
    return np.cosh(x)


def fd3(x):
    return np.sinh(x)


def fd4(x):
    return np.cosh(x)


M2deLR, M4deLR = 0, 0


IntEps = 0.000001
IntFormatString = "{:.7f}"

DerEps = 0.01
DerFormatString = "{:.3f}"


def DerivativeFirst(f, x, d):
    return (f(x + d) - f(x - d)) / (2 * d)


def DerivativeFirstViaEstimation(f, x):
    M2 = abs(fd2(x))
    df = 2 * DerEps / M2
    M3 = abs(fd3(x))
    ds = (6 * DerEps / M3) ** (1 / 2)
    return DerivativeFirst(f, x, min(df, ds))


def DerivativeFirstViaTenInMinus5(f, x):
    d = 10.0**-5
    return DerivativeFirst(f, x, d)


def DerivativeSecond(f, x, d):
    return (f(x + d) - 2 * f(x) + f(x - d)) / (d**2)


def DerivativeSecondViaEstimation(f, x):
    M4 = abs(fd4(x))
    if M4 == 0:
        d = DerEps
    else:
        d = (12 * DerEps / M4) ** (1 / 2)
    return DerivativeSecond(f, x, d)


def DerivativeSecondViaTenInMinus4(f, x):
    d = 10.0**-4
    return DerivativeSecond(f, x, d)


print()


def delta1(derappr):
    return np.ceil(abs(derappr - fd1(DerXdot)) * (1 / (DerEps / 10))) * (DerEps / 10)


print(f"Первая производная = {fd1(DerXdot):.3f}")
print(
    f"С помощью приближений    = {DerivativeFirstViaEstimation(f, DerXdot):.3f} | delta = {delta1(DerivativeFirstViaEstimation(f, DerXdot)):.3f}"
)
print(
    f"Округленное   = {DerivativeFirstViaTenInMinus5(f, DerXdot):.3f} | delta = {delta1(DerivativeFirstViaTenInMinus5(f, DerXdot)):.3f}"
)
print()


def delta2(derappr):
    return np.ceil(abs(derappr - fd2(DerXdot)) * (1 / (DerEps / 10))) * (DerEps / 10)


print(f"Вторая производная = {fd2(DerXdot):.3f}")
print(
    f"С помощью приближений     = {DerivativeSecondViaEstimation(f, DerXdot):.3f} | delta = {delta2(DerivativeSecondViaEstimation(f, DerXdot)):.3f}"
)
print(
    f"Округленное    = {DerivativeSecondViaTenInMinus4(f, DerXdot):.3f} | delta = {delta2(DerivativeSecondViaTenInMinus4(f, DerXdot)):.3f}"
)
print()


def IntegralViaMiddleRectangles(f, L, R, N):
    h = (R - L) / N
    x = L + h / 2
    s = 0.0
    while x < R:
        s += f(x) * h
        x += h
    return s


def IntegralViaTrapezoids(f, L, R, N):
    h = (R - L) / N
    x = L + h / 2
    s = 0.0
    while x < R:
        s += ((f(x - h / 2) + f(x + h / 2)) / 2) * h
        x += h
    return s


def IntegralViaSimpson(f, L, R, N):
    h = (R - L) / N
    x = L + h / 2
    s = 0.0
    while x < R:
        fa = f(x - h / 2)
        fm = f(x)
        fb = f(x + h / 2)
        s += (fa + 4 * fm + fb) * h / 6
        x += h
    return s


def IntegralViaRandomSegments(method, f, L, R):
    LeftCoeff, RightCoeff = 1 / 3, 1 / 2
    h_prev = R - L
    ans_prev = method(f, L, R, 1)
    while True:
        h_new = h_prev * (LeftCoeff + (RightCoeff - LeftCoeff) * np.random.rand())
        N = math.floor((R - L) / h_new)
        M = L + h_new * N
        ans_new = method(f, L, M, N) + method(f, M, R, 1)
        if abs(ans_new - ans_prev) < IntEps:
            print("Случайные отрезки: N =", N)
            return ans_new
        ans_prev = ans_new
        h_prev = h_new


def IntegralViaMiddleRectanglesViaEstimation(f, L, R):
    if M2deLR > 0.0:
        M2 = M2deLR
        h = (24 * IntEps / (R - L) / M2) ** (1 / 2)
        N = np.ceil((R - L) / h)
        return IntegralViaMiddleRectangles(f, L, R, N)
    else:
        return IntegralViaRandomSegments(IntegralViaMiddleRectangles, f, L, R)


def IntegralViaTrapezoidsViaEstimation(f, L, R):
    if M2deLR > 0.0:
        M2 = M2deLR
        h = (12 * IntEps / (R - L) / M2) ** (1 / 2)
        N = np.ceil((R - L) / h)
        return IntegralViaTrapezoids(f, L, R, N)
    else:
        return IntegralViaRandomSegments(IntegralViaTrapezoids, f, L, R)


def IntegralViaSimpsonViaEstimation(f, L, R):
    if M4deLR > 0.0:
        M4 = M4deLR
        h = (180 * IntEps / (R - L) / M4) ** (1 / 4)
        N = np.ceil((R - L) / h)
        return IntegralViaSimpson(f, L, R, N)
    else:
        return IntegralViaRandomSegments(IntegralViaSimpson, f, L, R)


print()
intprecised = F(R) - F(L)
print(f"Интеграл =            {intprecised:.7f}")


def delta(intappr):
    return np.ceil(abs(intappr - intprecised) * (1 / (IntEps / 10))) * (IntEps / 10)


intappr = IntegralViaMiddleRectanglesViaEstimation(f, L, R)
print(f"Прямоугольники = {intappr:.7f} | delta = {delta(intappr):.7f}")
intappr = IntegralViaTrapezoidsViaEstimation(f, L, R)
print(f"Трапеции       = {intappr:.7f} | delta = {delta(intappr):.7f}")
intappr = IntegralViaSimpsonViaEstimation(f, L, R)
print(f"Симпсон          = {intappr:.7f} | delta = {delta(intappr):.7f}")
print()