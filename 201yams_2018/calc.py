#/usr/bin/python3

def get_numbers(func, arg1, arg2, args):

    n = 5
    k = 0
    count = 0
    if func == "pair":
        for i in range(1, 6):
            if int(args[i]) == arg1:
                n -= 1
                count += 1
        k = 2 - count
        func = "pair"
    elif func == "three":
        for i in range(1, 6):
            if int(args[i]) == arg1:
                n -= 1
                count += 1
        k = 3 - count
        func = "three-of-a-kind"
    elif func == "four":
        for i in range(1, 6):
            if int(args[i]) == arg1:
                n -= 1
                count += 1
        k = 4 - count
        func = "four-of-a-kind"
    elif func == "full":
        c1 = 0
        c2 = 0
        for i in range(1, 6):
            if int(args[i]) == arg1:
                c1 += 1
            elif int(args[i]) == arg2:
                c2 += 1
        func = "full of"
        if c1 > 3:
            c1 = 3
        if c2 > 2:
            c2 = 2
        n = 5 - c1 - c2
        k = 3 - c1
        resC1 = factorial(n) / (factorial(k) * factorial(n - k))
        n = 2 - c2
        k = n
        resC2 = factorial(n) / (factorial(k) * factorial(n - k))
        result = (resC1 * resC2 / pow(6, 5 - c1 - c2)) * 100
        if result == 100:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  100.00%")
        elif result == 0:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  0.00%")
        else:
            print("chances to get a " + str(arg1) + " full of " + str(arg2) +  ":  " + str(round(result, 2))[:str(result).find('.') + 3] + "%")
        exit(0)
    elif func == "straight":
        l1 = [0, 0, 0, 0, 0]
        l2 = [0, 0, 0, 0, 0]
        for i in range(1, 6):
            if int(args[i]) == 1:
                l1[0] = 1
            elif int(args[i]) == 2:
                l1[1] = 1
                l2[0] = 1
            elif int(args[i]) == 3:
                l1[2] = 1
                l2[1] = 1
            elif int(args[i]) == 4:
                l1[3] = 1
                l2[2] = 1
            elif int(args[i]) == 5:
                l1[4] = 1
                l2[3] = 1
            elif int(args[i]) == 6:
                l2[4] = 1
        if arg1 == 5:
            for i in range(0, 5):
                if l1[i] == 1:
                    n -= 1;
        elif arg1 == 6:
            for i in range(0, 5):
                if l2[i] == 1:
                    n -= 1
        k = n
        func = "straight"
    elif func == "yams":
        for i in range(1, 6):
            if int(args[i]) == arg1:
                n -= 1
                count += 1
        k = 5 - count
        func = "yams"
    return n, k, func

def factorial(n):
    x = 1
    for i in range(2, n + 1):
        x *= i
    return x
