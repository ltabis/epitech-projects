#!/usr/bin/env python3

import sys
from calc import *

_arg_number_1 = 2
_arg_number_2 = 3
_nb_to_test_ = 3

def parsing():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        displayChebang()
        exit(0)
    elif not(len(sys.argv) >= _arg_number_1 and len(sys.argv) <= _arg_number_2):
        exit(84)

    if len(sys.argv) == _arg_number_1:
        try_number(sys.argv[1])
        calc_distrib(int(sys.argv[1]))
    elif len(sys.argv) == _arg_number_2:
        try_number(sys.argv[1])
        try_number(sys.argv[2])
        calc_binom(int(sys.argv[1]), int(sys.argv[2]))

def try_number(arg):
    try:
        int(arg)
    except ValueError:
        exit(84)

def displayChebang():
    print ("USAGE\n"\
"           ./203hotline [n k | d]\n\n"\
"DESCRIPTION\n"\
"           n    n value for the computation of (n k)\n"\
"           k    k value for the computation of (n k)\n"\
"           d    average duration of calls (in seconds)")

def factorial(n):
    x = 1
    for i in range(2, n + 1):
        x *= i
    return x

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
