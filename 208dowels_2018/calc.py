#!/usr/bin/env python3

from math import *

percentage = [99, 90, 80, 70, 60, 50, 40, 30, 20, 10, 5, 2, 1]
distribution_table = [[0.00, 0.02, 0.06, 0.15, 0.27, 0.45, 0.71, 1.07, 1.64, 2.71, 3.84, 5.41, 6.63],
[0.02, 0.21, 0.45, 0.71, 1.02, 1.39, 1.83, 2.41, 3.22, 4.61, 5.99, 7.82, 9.21],
[0.11, 0.58, 1.01, 1.42, 1.87, 2.37, 2.95, 3.66, 4.64, 6.25, 7.81, 9.84, 11.34],
[0.30, 1.06, 1.65, 2.19, 2.75, 3.36, 4.04, 4.88, 5.99, 7.78, 9.49, 11.67, 13.28],
[0.55, 1.61, 2.34, 3.00, 3.66, 4.35, 5.13, 6.06, 7.29, 9.24, 11.07, 13.39, 15.09],
[0.87, 2.20, 3.07, 3.83, 4.57, 5.35, 6.21, 7.23, 8.56, 10.64, 12.59, 15.03, 16.81],
[1.24, 2.83, 3.82, 4.67, 5.49, 6.35, 7.28, 8.38, 9.80, 12.02, 14.07, 16.62, 18.48],
[1.65, 3.49, 4.59, 5.53, 6.42, 7.34, 8.35, 9.52, 11.03, 13.36, 15.51, 18.17, 20.09],
[2.09, 4.17, 5.38, 6.39, 7.36, 8.34, 9.41, 10.66, 12.24, 14.68, 16.92, 19.68, 21.67],
[2.56, 4.87, 6.18, 7.27, 8.30, 9.34, 10.47, 11.78, 13.44, 15.99, 18.31, 21.16, 23.21]]

def disp_board(args):

    x = [] # numbers idx
    Ox = [] # numbers sum
    Tx = [] # proba ?
    taken = [0 for i in args] # is taken by another idx

    xi = 0
    Oxi = 0
    Txi = 0
    ti = 0

    i = 0

    while i < len(args):
        x.append([i])
        taken[i] = 1
        if args[i] < 10:
            i, xi, x, taken = add_smaller(x, args, taken, xi, i)
        else:
            xi += 1
        i += 1

    Ox = calc_Ox(x, args)

    Tx, N, p = calc_Tx(Ox, x, args)
    chi = calc_chi(Ox, Tx)
    disp_results(x, Ox, Tx, N, p, chi)

def add_smaller(x, args, taken, xi, i):

    total = args[i]

    taken[i] = 1
    if i == 0:
        while total < 10 and i < len(args) - 1:
            if taken[i + 1] == 0:
                taken[i + 1] = 1
                x[xi].append(i + 1)
                total += args[i + 1]
                i += 1
    else:
        a = 0
        while total < 10 and i < len(args):
            if i == len(args) - 1:
                total = args[i - 1] + args[i]
                xi -= 1
                taken[i - 1] = 1
                x[xi].append(i)
                a = 1
                del x[xi + 1]
                return i, xi + 1, x, taken
            if a != 1 and args[i - 1] < args[i + 1] and args[i - 1] >= 10:
                total = args[i - 1] + args[i]
                xi -= 1
                taken[i - 1] = 1
                x[xi].append(i)
                a = 1
                del x[xi + 1]
            elif taken[i + 1] == 0:
                taken[i + 1] = 1
                x[xi].append(i + 1)
                total += args[i + 1]
                i += 1
                a = 1
    return i, xi + 1, x, taken

def disp_results(x, Ox, Tx, N, p, chi):

    # x
    i = 0
    print("   x     |", end='')
    for xs in x:
        print(" ", end='')
        if i == len(x) - 1:
            print("{:6}".format(str(xs[0]) + "+"), end='')
        else:
            cut_bounds(xs)
        print("|", end='')
        i += 1
    print(" Total")

    # Ox
    print("  Ox     |", end='')
    for xs in Ox:
        print(" {:6}".format(str(xs)), end='')
        print("|", end='')
    print(" 100")

    # Tx
    print("  Tx     |", end='')
    for xs in Tx:
        print(" {:6}".format(str(round(xs, 1))), end='')
        print("|", end='')
    print(" 100")
    print("Distribution:            B(100, {:.4f})".format(p))
    print("Chi-squared:             {0:.3f}".format(chi))
    print("Degrees of freedom:      {0}".format(len(x) - 2))
    print("Fit validity:            {0}".format(find_fit(chi, len(x) - 2)))

def cut_bounds(xs):

    if len(xs) == 1:
        print("{:6}".format(str(xs[0])), end='')
    else:
        str1 = str(xs[0]) + "-" + str(xs[-1])
        print("{:6}".format(str1), end='')

def calc_Ox(x, args):

    Ox = []

    for xs in x:
        if len(xs) > 1:
            Ox.append(0)
            for i in range(int(xs[0]), int(xs[-1]) + 1):
                Ox[-1] += args[i]
        else:
            Ox.append(args[int(xs[0])])
    return Ox

def sum_n(Ox, x, args):

    res = 0
    xi = 0

    for xs in args:
        res += xs * xi
        xi += 1
    return res

def calc_Tx(Ox, x, args):

    N = 100
    xb = (1 / N) * sum_n(Ox, x, args)
    p = xb / N
    Tx = []

    for a in x:
        elem = 0
        if len(a) >= 2:
            for xi in range(a[0], a[-1] + 1):
                elem += (N * binom_coeff(xi, N) * (p ** xi) * ((1 - p) ** (N - xi)))
        else:
            elem += (N * binom_coeff(a[0], N) * (p ** a[0]) * ((1 - p) ** (N - a[0])))
        Tx.append(elem)

    res = 0
    for a in Tx:
        res += a
    Tx[-1] = 100 - res + Tx[-1]
    return Tx, N, p

def binom_coeff(k, n):
    return factorial(n) // (factorial(k) * factorial(n - k))

def calc_chi(Ox, Tx):

    chiSum = 0

    for Oxs, Txs in zip(Ox, Tx):
        chiSum += ((Oxs - Txs) ** 2) / Txs
    return chiSum

def find_fit(chi, v):

    i = 0
    last = distribution_table[v][0]
    if chi < distribution_table[v][0]:
        return "P > 99%"
    for p in distribution_table[v]:
        if chi > float(last) and chi < p:
            return (str(percentage[i + 1]) + "% < P < " + str(percentage[i]) + "%")
        i += 1
        last = p
    return "P < 1%"
