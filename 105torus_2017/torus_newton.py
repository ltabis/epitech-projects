#!/usr/bin/python3

from sys import *

def do_newton(tab, n):
    xn = 0.5
    res = (float(tab[5]) * (xn**4)) + (float(tab[4]) * (xn**3)) + (float(tab[3]) * (xn**2)) + (float(tab[2]) * xn) + float(tab[1])
    deriv = (4 * float(tab[5]) * (xn**3)) + (3 * float(tab[4]) * (xn**2)) + (2 * float(tab[3]) * xn) + float(tab[2])
    xn1 = xn - (res / deriv)
    print("x = " + str(xn))
    if xn != xn1:
        print("x = {1:.{0}f}".format(n, xn1))
        while (abs(xn1 - xn) / abs(xn1)) > 10**-n:
            xn = xn1
            res = (float(tab[5]) * (xn**4)) + (float(tab[4]) * (xn**3)) + (float(tab[3]) * (xn**2)) + (float(tab[2]) * xn) + float(tab[1])
            deriv = (4 * float(tab[5]) * (xn**3)) + (3 * float(tab[4]) * (xn**2)) + (2 * float(tab[3]) * xn) + float(tab[2])
            xn1 = xn - (res / deriv)
            if str(xn) != str(xn1):
                print("x = {1:.{0}f}".format(n, xn1))
