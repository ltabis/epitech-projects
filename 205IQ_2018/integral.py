#!/usr/bin/python3
import math

def born_inferior(u, o, b):
        x = 0
        result = 0.0

        while x <= b:
                result += func(u, o, x)
                x += 0.01
        print("{0:.1f}% of people have an IQ inferior to {1}".format(result, b))

def born_between(u, o, a, b):

        x = a
        result = 0.0

        while x <= b:
                result += func(u, o, x)
                x += 0.01
        print("{0:.1f}% of people have an IQ between {1} and {2}".format(result, a, b))

def func(u, o, i):
        return (1 / (o * math.sqrt(2 * math.pi))) * math.exp(-((i - u) ** 2) / (2 * (o ** 2)))

def calcul_product(u, o):

        for i in range(0, 201):
                result = (1 / (o * math.sqrt(2 * math.pi))) * math.exp(-((i - u) ** 2) / (2 * (o ** 2)))
                print("{0} {1:.5f}".format(i, result))
