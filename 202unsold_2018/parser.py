#!/usr/bin/env python3

import sys
from calc import *

_arg_number_ = 3
_nb_to_test_ = 3

def parsing():
    if len(sys.argv) != _arg_number_:
        if len(sys.argv) == 2 and sys.argv[1] == "-h":
            displayChebang()
            exit(0)
        else:
            exit(84)
    for i in range(1, _nb_to_test_):
        try_number(sys.argv[i])
    if int(sys.argv[2]) < 50 or int(sys.argv[1]) < 50:
        exit(84)
    listX, listY = calc(int(sys.argv[1]), int(sys.argv[2]))
    print_z(listX, listY)
    print_variance(listX, listY)

def try_number(arg):
    try:
        test = int(arg)
    except ValueError:
        exit(84)

def displayChebang():
    print ("USAGE\n"\
"           ./202unsold a b\n\n"\
"DESCRIPTION\n"\
"           a"\
"   constant computed from the past results\n"\
"           b"\
"   constant computed from the past results")

def factorial(n):
    x = 1
    for i in range(2, n + 1):
        x *= i
    return x

def print_z(listX, listY):

    print("z         20       30       40       50       60       70       80       90       100      total")
    print("p(Z=z)    ", end='')
    a(listX, listY)
    b(listX, listY)
    c(listX, listY)
    d(listX, listY)
    e(listX, listY)
    f(listX, listY)
    g(listX, listY)
    h(listX, listY)
    j(listX, listY)
    print("1\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––")

def print_variance(listX, listY):

    print("expected value of X:\t" + str(round(calc_esp(listX), 1)))
    print("variance of X:\t\t" + str(round(calc_var(listX), 1)))

    print("expected value of Y:\t" + str(round(calc_esp(listY), 1)))
    print("variance of Y:\t\t" + str(round(calc_var(listY), 1)))

    print("expected value of Z:\t" + str(round(calc_esp(listX) + calc_esp(listY), 1)))
    print("variance of Z:\t\t" + str(round(calc_var(listX) + calc_var(listY), 1)))
    print("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––")

def calc_esp(actualList):
    j = 0
    E = 0

    for i in range(10, 60, 10):
        E += (actualList[j] * i)
        j += 1
    return E

def calc_var(actualList):
    j = 0
    E1 = 0
    E2 = 0

    for i in range(10, 60, 10):
        E1 += (actualList[j] * (i ** 2))
        j += 1
    E2 = calc_esp(actualList) ** 2
    return E1 - E2
