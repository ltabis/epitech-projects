#!/usr/bin/env python3

import sys

_arg_number_ = 4

def parsing():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        display_usage()
        exit(0)
    elif len(sys.argv) != _arg_number_:
        exit(84)
    try_int(sys.argv[1])
    try_int(sys.argv[2])
    if int(sys.argv[1]) < int(sys.argv[2]):
        exit(84)
    try_float(sys.argv[3])
    return (sys.argv)

def try_int(arg):
    try:
        a = int(arg)
        if a <= 0:
            exit(84)
    except ValueError:
        exit(84)

def try_float(arg):
    try:
        a = float(arg)
        if a < 0 or a > 100:
            exit(84)
    except ValueError:
        exit(84)

def display_usage():
    print("USAGE\n"\
"    ./209poll pSize sSize p\n\n"\
"DESCRIPTION\n"\
"    pSize   size of the population\n"\
"    sSize   size of the sample (supposed to be representative)\n"\
"    p       percentage of voting intentions for a specific candidate")
