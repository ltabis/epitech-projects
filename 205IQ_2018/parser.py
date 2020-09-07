#!/usr/bin/env python3

import sys
from integral import *

_arg_number_1_ = 3
_arg_number_2_ = 5

def parsing():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        display_help()
        exit(0)
    elif len(sys.argv) >= _arg_number_1_ and len(sys.argv) <= _arg_number_2_:
        try_number(sys.argv[1])
        try_number(sys.argv[2])
        if int(sys.argv[1]) < 0 or int(sys.argv[1]) > 200 or int(sys.argv[2]) < 0:
            exit(84)
        if len(sys.argv) == 4:
            try_number(sys.argv[3])
            if int(sys.argv[3]) < 0:
                exit(84)
            born_inferior(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
        elif len(sys.argv) == 5:
            try_number(sys.argv[3])
            try_number(sys.argv[4])
            if int(sys.argv[3]) < 0 or int(sys.argv[4]) < 0 or int(sys.argv[4]) < int(sys.argv[3]):
                exit(84)
            born_between(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]))
        else:
            calcul_product(int(sys.argv[1]), int(sys.argv[2]))
    else:
        exit(84)

def try_number(arg):
    try:
        int(arg)
    except ValueError:
        exit(84)

def display_help():
    print("USAGE\n"\
"    ./205IQ u s [IQ1] [IQ2]\n\n"\
"DESCRIPTION\n"\
"    u       mean\n"\
"    s       standard deviation\n"\
"    IQ1     minimum IQ\n"\
"    IQ2     maximum IQ")
