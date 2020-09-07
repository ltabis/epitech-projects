#!/usr/bin/python3

import sys
from functools import *
from operator import *

letters = "ETAOINSHRDLU"

def cutX(s, l, x):
    tab = []
    for i in range(0, l, x):
        tab.append(s[i:i+x])
    return tab

def checkHex(s):
    try:
        int(s, 16)
    except:
        exit(84)

def searchBestScore(tab):

    listScore = []
    [listScore.append(xorEverything(tabline)) for tabline in tab]
    idxMax = listScore.index(max(listScore))
    print(idxMax + 1, xorEverything(tab[idxMax], True))

def xorEverything(tab, ret = False):

    listXor = []
    maxScore = 0
    idxScore = 0
    res = 0
    tab = bytes.fromhex(tab)

    for i in range(0, 256):
        outputBytes = b''
        for byte in tab:
            outputBytes += bytes([byte ^ i])
        if scoreCalc(outputBytes) > maxScore:
            res = i
            maxScore = scoreCalc(outputBytes)
    if ret == True:
        res = hex(res).replace("0x", "").upper()
        if len(res) == 1:
            res = '0' + res
        return res
    return maxScore

def scoreCalc(inputBytes):
    freq = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
	'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
        'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
	'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
        'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
        'y': .01974, 'z': .00074, ' ': .13000
    }
    return sum([freq.get(chr(byte), 0) for byte in inputBytes.lower()])

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
    [tab.append(line) for line in s]
    try:
        searchBestScore(tab)
    except:
        exit(84)
        
if __name__ == "__main__":
    main()
