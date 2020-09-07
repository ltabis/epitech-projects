#!/usr/bin/env python

def do_secant(tab, n):
    i = 0;
    j = 1;
    xn = 0
    xn1 = 1
    temp = xn1 - ((float(tab[5]) * xn1**4 + float(tab[4]) * xn1**3 + float(tab[3]) * xn1**2 + float(tab[2]) * xn1 + float(tab[1])) * (xn1 - xn) / ((float(tab[5]) * xn1**4 + float(tab[4]) * xn1**3 + float(tab[3]) * xn1**2 + float(tab[2]) * xn1 + float(tab[1])) - (float(tab[5]) * xn**4 + float(tab[4]) * xn**3 + float(tab[3]) * xn**2 + float(tab[2]) * xn + float(tab[1]))))
    print("x = " + str(temp))
    xn_lol = xn
    xn1_lol = xn1
    temp_lol = temp
    while (abs(xn1_lol - xn_lol) / abs(xn1_lol)) > 10**-n:
        xn_lol = xn1_lol
        xn1_lol = temp_lol
        temp_lol = xn1_lol - ((float(tab[5]) * xn1_lol**4 + float(tab[4]) * xn1_lol**3 + float(tab[3]) * xn1_lol**2 + float(tab[2]) * xn1_lol + float(tab[1])) * (xn1_lol - xn_lol) / ((float(tab[5]) * xn1_lol**4 + float(tab[4]) * xn1_lol**3 + float(tab[3]) * xn1_lol**2 + float(tab[2]) * xn1_lol + float(tab[1])) - (float(tab[5]) * xn_lol**4 + float(tab[4]) * xn_lol**3 + float(tab[3]) * xn_lol**2 + float(tab[2]) * xn_lol + float(tab[1]))))
        i += 1;
    while j < i:
        xn = xn1
        xn1 = temp
        temp = xn1 - ((float(tab[5]) * xn1**4 + float(tab[4]) * xn1**3 + float(tab[3]) * xn1**2 + float(tab[2]) * xn1 + float(tab[1])) * (xn1 - xn) / ((float(tab[5]) * xn1**4 + float(tab[4]) * xn1**3 + float(tab[3]) * xn1**2 + float(tab[2]) * xn1 + float(tab[1])) - (float(tab[5]) * xn**4 + float(tab[4]) * xn**3 + float(tab[3]) * xn**2 + float(tab[2]) * xn + float(tab[1]))))
        print("x = {0:.{1}f}".format(temp, n))
        j += 1;
