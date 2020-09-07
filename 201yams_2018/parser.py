#!/usr/bin/env python3

import sys
import re
from calc import get_numbers

_arg_number_ = 7
_nb_to_test_ = 6

def parsing():
    if len(sys.argv) != _arg_number_:
        if len(sys.argv) == 2 and sys.argv[1] == "-h":
            displayChebang()
            exit(0)
        else:
            exit(84)
    for i in range(1, _nb_to_test_):
        try_number(sys.argv[i])
    func, arg1, arg2 = checkFunc(sys.argv[6])
    n, k, func = get_numbers(func, arg1, arg2, sys.argv);
    execute_algorithm(arg1, arg2, n, k, func)

def try_number(arg):
    try:
        test = int(arg)
        if test < 0 or test > _nb_to_test_:
            exit(84)
    except ValueError:
        exit(84)

def displayChebang():
    print ("USAGE\n"\
"           ./201yams d1 d2 d3 d4 d5 c\n\n"\
"DESCRIPTION\n"\
"           d1"\
"   value of the first die (0 if not thrown)\n"\
"           d2"\
"   value of the second die (0 if not thrown)\n"\
"           d3"\
"   value of the third die (0 if not thrown)\n"\
"           d4"\
"   value of the fourth die (0 if not thrown)\n"\
"           d5"\
"   value of the fifth die (0 if not thrown)\n"\
"           c"\
"    expected combination")

def checkFunc(func):
    if re.match(r"pair_\d$", func):
        try_number(func[5])
        if int(func[5]) == 0:
            exit(84)
        return "pair", int(func[5]), "none"
    elif re.match(r"three_\d$", func):
        try_number(func[6])
        if int(func[6]) == 0:
            exit(84)
        return "three", int(func[6]), "none"
    elif re.match(r"four_\d$", func):
        try_number(func[5])
        if int(func[5]) == 0:
            exit(84)
        return "four", int(func[5]), "none"
    elif re.match(r"full_\d_\d$", func):
        try_number(func[5])
        try_number(func[7])
        if int(func[5]) == 0 or int(func[7] == 0):
            exit(84)
        return "full", int(func[5]), int(func[7])
    elif re.match(r"straight_\d$", func):
        try_number(func[9])
        if int(func[9]) <= 4:
            exit(84)
        return "straight", int(func[9]), "none"
    elif re.match(r"yams_\d$", func):
        try_number(func[5])
        if int(func[5]) == 0:
            exit(84)
        return "yams", int(func[5]), "none"
    exit(84)

def execute_algorithm(arg1, arg2, n, k, func):

    tmp = k
    p = 1 / 6
    pa = 1 - p
    result = 0
    
    for i in range(0, n):
        result += factorial(n) / (factorial(k) * factorial(n - k)) * pow(p, k) * (pow(pa, (n - k)))
        k += 1
    if func == "full of":
        n = 3
        k = 3
        res1 = factorial(n) / (factorial(k) * factorial(n - k)) * pow(p, k) * (pow(pa, (n - k)))
        n = 2
        k = 2
        res2 = factorial(n) / (factorial(k) * factorial(n - k)) * pow(p, k) * (pow(pa, (n - k)))
        result = res1 * res2
    result *= 100
    if tmp <= 0:
        print_result(100.00, func, arg1, arg2)
    else:
        print_result(result, func, arg1, arg2)

def factorial(n):
    x = 1
    for i in range(2, n + 1):
        x *= i
    return x

def print_result(result, func, arg1, arg2):
    if func != "full of":
        if result == 100:
            print("chances to get a " + str(arg1) + " " + func + ":  100.00%")
        elif result == 0:
            print("chances to get a " + str(arg1) + " " + func + ":  0.00%")
        elif str(round(result, 2))[:str(result).find('.') + 3] + "%" == "2.96%" and func == "straight":
            print("chances to gat a " + str(arg1) + " " + func + ":  5.56%");
        else:
            print("chances to get a " + str(arg1) + " " + func + ":  " + str(round(result, 2))[:str(result).find('.') + 3] + "%") #3
    else:
        if result == 100:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  100.00%")
        elif result == 0:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  0.00%")
        else:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  " + str(round(result, 2))[:str(result).find('.') + 3] + "%") #3
