def calc_proba(a, b, x, y):
    return (a - x) * (b - y) / ((5 * a - 150) * (5 * b - 150))

def calc_sum_y(line):
    su = 0
    for i in range(0, 5):
       su += line[i]
    return su

def calc_sum_x(tab, i):
    su = 0
    for j in range(0, 5):
        su += tab[j][i]
    return su

def calc_tot(prob_x):
    tot = 0
    for i in range(0, 5):
        tot += prob_x[i]
    return tot

def calc(a, b):
    print("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––")
    print("         X=10     X=20     X=30     X=40     X=50     Y law")
    tab = []
    prob_y = []
    prob_x = []
    for y in range(10, 60, 10):
        print("Y=" + str(y), end='')
        tab.append([])
        for x in range(10, 60, 10):
            val = calc_proba(a, b, x, y)
            tab[int(y / 10 - 1)].append(val)
            if x == 10:
                print("     {:.03f}".format(val), end='')
            else:
                print("    {:.03f}".format(val), end='')
            if x == 50:
                su = calc_sum_y(tab[int(y / 10 - 1)])
                prob_y.append(su)
                print("    {:.03f}".format(su))
    print("X law", end='')
    for i in range(0, 5):
        su = calc_sum_x(tab, i)
        prob_x.append(su)
        print("    {:.03f}".format(su), end='')
    print("    {:d}".format(int(round(calc_tot(prob_x), 0))))
    print("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––")
    return prob_x, prob_y

def a(listX, listY):
    b = str(round(listX[0] * listY[0], 3))
    add_zeros(b)

def b(listX, listY):
    b = str(round(listX[0] * listY[1] + listX[1] * listY[0], 3))
    add_zeros(b)

def c(listX, listY):
    b = str(round(listX[1] * listY[1] +
                  listX[0] * listY[2] +
                  listX[2] * listY[0]
                  , 3))
    add_zeros(b)

def d(listX, listY):
    b = str(round(listX[1] * listY[2] +
                  listX[2] * listY[1] +
                  listX[3] * listY[0] +
                  listX[0] * listY[3]
                  , 3))
    add_zeros(b)

def e(listX, listY):
    b = str(round(listX[2] * listY[2] +
                  listX[3] * listY[1] +
                  listX[1] * listY[3] +
                  listX[4] * listY[0] +
                  listX[0] * listY[4]
                  , 3))
    add_zeros(b)

def f(listX, listY):
    b = str(round(listX[4] * listY[1] +
                  listX[1] * listY[4] +
                  listX[3] * listY[2] +
                  listX[2] * listY[3]
                  , 3))
    add_zeros(b)

def g(listX, listY):
    b = str(round(listX[3] * listY[3] +
                  listX[4] * listY[2] +
                  listX[2] * listY[4]
                  , 3))
    add_zeros(b)

def h(listX, listY):
    b = str(round(listX[3] * listY[4] +
                  listX[4] * listY[3]
                  , 3))
    add_zeros(b)

def j(listX, listY):
    b = str(round(listX[4] * listY[4], 3))
    add_zeros(b)

def add_zeros(b):
    if len(b) == 3:
        b += "00"
    elif len(b) == 4:
        b += "0"
    print (b, end='    ')
