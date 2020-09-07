#!/usr/bin/python3

import sys
from functools import *
from operator import *

def cutX(s, l, x):
    tab = []
    [tab.append(s[i:i+x]) for i in range(0, l, x)]
    return tab

def checkHex(s):

    if len(s) % 2 != 0:
        exit(84)
    try:
        int(s, 16)
    except:
        exit(84)

def transformInHex(data):
    res = hex(data).replace("0x", "").upper()
    if len(res) != 2:
        res = '0' + res
    return res

def encrypt(key, tab):

    encryptedList = []
    idx = 0
    for ch in tab:
        idx = 0 if idx == len(key) else idx
        encryptedList.append(int(ch, 16) ^ int(key[idx], 16))
        idx += 1
    [print(transformInHex(ch), end="") for ch in encryptedList]
    print("")
        
def main():

    s = []
    tab = []

    if len(sys.argv) != 2:
        exit(84)
    try:
        file = sys.argv[1]
        with open(file) as f:
            [s.append(line.replace("\n", "")) for line in f]
            f.close()
    except:
        exit(84)
    [checkHex(line) for line in s]
    [tab.append(cutX(line, len(line), 2)) for line in s]
    try:
        key = tab[0]
        tab = tab[1]
        encrypt(key, tab)
    except:
        exit(84)
    
if __name__ == "__main__":
    main()
