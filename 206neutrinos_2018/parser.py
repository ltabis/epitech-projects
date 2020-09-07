#!/usr/bin/env python3

import sys
import calc

_arg_number_ = 5

def parsing():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        display_help()
        exit(0)
    elif len(sys.argv) != _arg_number_:
        exit(84)
    try_number(sys.argv[1])
    try_number(sys.argv[2])
    try_number(sys.argv[3])
    try_number(sys.argv[4])
    calc.calc(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]))

def try_number(arg):
    try:
        nb = int(arg)
        if nb <= 0:
            exit(84)
    except ValueError:
        exit(84)

def display_help():
    print("USAGE\n"\
"./206neutrinos n a h sd\n"\
"\n"\
"DESCRIPTION\n"\
"   n       number of values\n"\
"   a       arithmetic mean\n"\
"   h       harmonic mean\n"\
"   sd      standard deviation")
