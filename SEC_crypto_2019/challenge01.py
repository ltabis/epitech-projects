#!/usr/bin/python3

import sys
import b64
from base64 import b64encode

base = b64.base64()

def cutX(s, l, x):
    tab = []
    for i in range(0, l, x):
        tab.append(s[i:i+x])
    return tab

def main():
    try:
        file = sys.argv[1]
    except:
        exit(84)
    
    try:
        with open(file) as f:
            s = f.read()
            f.close()
            if len(s) <= 1:
                exit(84)
    except PermissionError:
        exit(84)

    try:
        s = "{:b}".format(int(s, 16))
    except ValueError:
        exit(84)
    l = len(s)
    i = l % 4
    while i < 4:
        s = "0" + s
        i += 1

    l = len(s)
    i = l % 6
    while i < 6:
        s = s + "0"
        i += 1

    tab = cutX(s, l, 6)

    for i in tab:
        print(base[i], end='')
    
    l = len(tab)
    i = l % 4
    while i < 4:
        print("=", end='')
        i += 1
    print("")

if __name__ == "__main__":
    main()
