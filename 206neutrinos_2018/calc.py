import math

def ask():
    new = input("Enter next value: ")
    if new == "END":
        exit(0)
    else:
        try:
            a = int(new)
            return (a)
        except ValueError:
            exit(84)

def updateAriMean(a, new, n):
    return (a * (n - 1) + new) / n

def updateStdDev(a, new, n, sd):
    #return math.sqrt((((sd ** 2) * (n - 1)) + (new - a) ** 2) / n)
    return math.sqrt((n - 2) / (n - 1) * (sd ** 2) + (1 / n) * ((new - a) ** 2))

def rootMeanSquare(a, sd):
    return math.sqrt(a ** 2 + sd ** 2)

def updateHarMean(h, new, n):
    return (1 / ((((1 / h) * (n - 1)) + 1 / new) / n))

def calc(n, a, h, sd):
    while True:
        new = ask()
        n += 1
        a = updateAriMean(a, new, n)
        sd = updateStdDev(a, new, n, sd)
        r = rootMeanSquare(a, sd)
        h = updateHarMean(h, new, n)
        print("    Number of values:   {}".format(n))
        print("    Standard deviation: {}".format(round(sd, 2)))
        print("    Arithmetic mean:    {}".format(round(a, 2)))
        print("    Root mean square:   {}".format(round(r, 2)))
        print("    Harmonic mean:      {}\n".format(round(h, 2)))
