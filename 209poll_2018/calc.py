import math

def calc(args):
    N = int(args[1])
    n = int(args[2])
    p = float(args[3]) / 100
    mu = n * p
    var = (n * p) * (1 - p) / n
    varP = (var / n) * ((N - n) / (N - 1))
    i95 = [(p - 1.96 * math.sqrt(varP)) * 100, (p + 1.96 * math.sqrt(varP)) * 100]
    i99 = [(p - 2.58 * math.sqrt(varP)) * 100, (p + 2.58 * math.sqrt(varP)) * 100]
    i95[0] = i95[0] if i95[0] > 0 else 0
    i95[1] = i95[1] if i95[1] < 100 else 100
    i99[0] = i99[0] if i99[0] > 0 else 0
    i99[1] = i99[1] if i99[1] < 100 else 100
    aff(args, varP, i95, i99)

def aff(args, var, i95, i99):
    print("Population size:         {}".format(args[1]))
    print("Sample size:             {}".format(args[2]))
    print("Voting intentions:       {}%".format(args[3]))
    print("Variance:                {:.6f}".format(var))
    print("95% confidence interval: [{:.2f}%; {:.2f}%]".format(i95[0], i95[1]))
    print("99% confidence interval: [{:.2f}%; {:.2f}%]".format(i99[0], i99[1]))
