#!/usr/bin/env python3

import sys
from calc import *

_arg_number_ = 10

# Checking arguments (convert in int)
def parsing():

    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        display_usage()
        exit(0)
    elif len(sys.argv) != _arg_number_:
        exit(84)
    listInt = [try_number(i) for i in sys.argv[1:]]
    disp_board(listInt)

def try_number(arg):

    try:
        int(arg)
    except ValueError:
        exit(84)
    return int(arg)

def display_usage():

    print("USAGE\n"\
"./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8\n\n"\
"DESCRIPTION\n"\
"Oi   size of the observed class")
