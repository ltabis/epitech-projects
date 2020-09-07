#!/usr/bin/env python3

import sys
from objects import *
from calc import *

_arg_number_ = 2

def parsing():

    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        display_usage()
        exit(0)
    elif len(sys.argv) < _arg_number_:
        exit(84)
    try_opening("207demography_data.csv")
    countries = get_country_data(sys.argv[1:])
    dates = get_country_data(["Country Code"])
    dates = dates[0]

    display_demography(countries, dates)

def try_number(arg):

    try:
        int(arg)
    except ValueError:
        exit(84)

def get_country_data(argv):

    idx = 0
    f = open("207demography_data.csv", "r")
    objects = []

    for line in f:
        if idx == len(argv):
            break
        line = line.split(';')
        if check_in(argv, line[1]) == True:
            objects.append(Country(line))
            idx += 1
    if idx != len(argv):
        exit(84)
    return objects

def check_in(line, code):

    for i in line:
        if code == i:
            return True

    return False

def try_opening(file):

    try:
        f = open(file, "r")
    except FileNotFoundError:
        exit(84)

def display_usage():

    print("USAGE\n"
"   ./207demography code [...]\n\n"\
"DESCRIPTION\n"\
"   code    country code")

def display_demography(countries, dates):

    signx = '+'
    signy = '+'
    data = countries[0].data
    maxlen = -1
    idx = 1

    # Calculating the smallest len of data
    for country in countries:
        if len(country.data) < maxlen or maxlen == -1:
            maxlen = len(country.data)

    # Adding datas between all countries
    while idx < len(countries):
        data = data[:maxlen]
        data = [a + b for a, b in zip(data, countries[idx].data)]
        idx += 1
    data = [i / 1000000 for i in data]

    # Calculating coeffs for the affine function
    ax = a_coeff(data, dates.data)
    bx = b_coeff(data, dates.data)
    ay = a_coeff_2(data, dates.data)
    by = b_coeff_2(data, dates.data)
    devx = deviationx(data, dates.data)
    devy = deviationy(data, dates.data)
    fiftyx = b_coeff(data, dates.data) * 2050 + a_coeff(data, dates.data)
    fiftyy = (2050 - a_coeff_2(data, dates.data)) / b_coeff_2(data, dates.data)
    if ax < 0:
        ax *= -1
        signx = '-'
    if ay < 0:
        ay *= -1
        signy = '-'

    # Display results
    print("Country: " + get_country_by_order(countries))
    print("Fit1")
    print("    Y = {0:.2f} X {1} {2:.2f}".format(bx, signx, ax))
    print("    Root-mean-square deviation: {0:.2f}".format(devx))
    print("    Population in 2050: {0:.2f}".format(fiftyx))
    print("Fit2")
    print("    X = {0:.2f} Y {1} {2:.2f}".format(by, signy, ay))
    print("    Root-mean-square deviation: {0:.2f}".format(devy))
    print("    Population in 2050: {0:.2f}".format(fiftyy))
    print("Correlation: {0:.4f}".format(correlation(data, dates.data)))

# Sorting names by ASCII order
def get_country_by_order(countries):

    names = []
    str = ""

    for i in countries:
        names.append(i.country_name)

    names.sort()
    for i in names:
        str += i
        if i != names[-1]:
            str += ", "
    return str
