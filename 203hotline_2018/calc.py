from math import *
import time

def calc_binom(n, k):
    num = factorial(n) / (factorial(k) * factorial(n - k))

    print(str(k) + "-combination of a " + str(n) + " set:")
    print(str(round(num)))

def calc_distrib(d):
    n = 3500
    p = d / 28800
    pa = 1 - p
    i = 1
    sum = 0
    li = []

    print("Binomial distribution:")
    start = time.time()
    for k in range(0, 51):
        li.append(factorial(n) / (factorial(k) * factorial(n - k)) * (p ** k) * (pa ** (n - k)))
    end = time.time()

    for k in range(0, 51):
        print(str(k) + " -> " + add_zeros(str(round(li[k], 3))), end='')
        if k >= 26:
            sum += li[k]
        if i % 6 == 0 and k != 0:
            print("")
        elif k != 50:
            print("\t", end='')
        i += 1
    sum *= 100
    print("\noverload:  {:.1f}".format(sum) + "%")
    print("computation time:  " + str(round((end * 100 - start * 100), 2)) +  " ms\n")
    print("Poisson distribution:")

    lambd = n * p
    li = []
    start = time.time()
    for k in range(0, 51):
        li.append((exp(lambd * -1) * (lambd ** k)) / factorial(k))
    end = time.time()

    i = 1
    sum = 0
    for k in range(0, 51):
        print(str(k) + " -> " + add_zeros(str(round(li[k], 3))), end='')
        if k >= 26:
            sum += li[k]
        if i % 6 == 0 and k != 0:
            print("")
        elif k != 50:
            print("\t", end='')
        i += 1
    sum *= 100
    print("\noverload:  {:.1f}".format(sum) + "%")
    print("computation time:  " + str(round((end * 100 - start * 100), 2)) +  " ms")

def factorial(n):
    x = 1
    for i in range(2, n + 1):
        x *= i
    return x

def add_zeros(b):
    if len(b) == 3:
        b += "00"
    elif len(b) == 4:
        b += "0"
    return b
