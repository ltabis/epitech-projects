#!/usr/bin/env python

from sys import *

def do_newton(tab, n):
    xn = 0.5
    res = (tab[0] * (xn**4)) + (tab[1] * (xn**3)) + (tab[2] * (xn**2)) + (tab[3] * xn) + tab[4]
    deriv = (4 * tab[0] * (xn**3)) + (3 * tab[1] * (xn**2)) + (2 * tab[2] * xn) + tab[3]
    xn1 = xn - (res / deriv)
    print("x = " + str(xn))
    if xn != xn1:
        print("x = {1:.{0}f}".format(n, xn1))
        while (abs(xn1 - xn) / abs(xn1)) > 10**-n:
            xn = xn1
            res = (tab[0] * (xn**4)) + (tab[1] * (xn**3)) + (tab[2] * (xn**2)) + (tab[3] * xn) + tab[4]
            deriv = (4 * tab[0] * (xn**3)) + (3 * tab[1] * (xn**2)) + (2 * tab[2] * xn) + tab[3]
            xn1 = xn - (res / deriv)
            if str(xn) != str(xn1):
                print("x = {1:.{0}f}".format(n, xn1))

def main():
    opt = int(argv[1])
    tab = [float(argv[6]), float(argv[5]), float(argv[4]), float(argv[3]), float(argv[2])]
    n = int(argv[7])
    if (opt == 1):
        pass
    elif (opt == 2):
        do_newton(tab, n)
    elif (opt == 3):
        pass
    else:
        print("lol")

main()
