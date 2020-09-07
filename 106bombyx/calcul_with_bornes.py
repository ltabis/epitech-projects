#!/usr/bin/python3

def calcul_with_bornes(n, i0, i1):
    k = 1.0
    save = i0
    while k < 4.0:
        i = 0
        i0 = save
        while i < i0:
            n = k * n * ((1000 - n) / 1000)
            i += 1
        diff = i1 - i0
        i = 0
        while i <= diff:
            n = k * n * ((1000 - n) / 1000)
            print("{:.2f} {:.2f}".format(k, n));
            i += 1
            i0 += 1
        k += 0.01
