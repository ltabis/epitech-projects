#!/usr/bin/python3

import sys
from functools import *
from operator import *

letters = "ETAOINSHRDLU"

# cutting text into chunks by length
def cutX(s, l, x):
    tab = []
    [tab.append(s[i:i+x]) for i in range(0, l, x)]
    return tab

# Checking if cipher is only in hexadecimal
def checkHex(s):

    if len(s) % 2 != 0:
        exit(84)
    try:
        int(s, 16)
    except:
        exit(84)

# Calculating distance between strings bit by bit
def hammingDistance(str1, str2):
    
    res = 0

    for ch1, ch2 in zip(str1, str2):
        distance, bit = 0 , ord(ch1) ^ ord(ch2)
        while bit:
            distance += 1
            bit &= bit - 1
        res += distance
    return res

# Xoring all the elements from the board
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

# Calculate letter probability
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

# search for the best etaoin's score
def searchBestScore(tab):

    listScore = []
    [listScore.append(xorEverything(tabline)) for tabline in tab]
    string = ""
    for tabline in tab:
        string += xorEverything(tabline, True)
    return max(listScore), string

# Transposing blocks bit by bit (first new block contain first bits of every other blocks etc...)
def transposeBlocks(blocks, size):

    x = []
    idx = 0
    bitIdx = 0

    if len(blocks[len(blocks) - 1]) != size * 2:
        blocks[len(blocks) - 1] += ("0" * int(((size * 2) - len(blocks[len(blocks) - 1]))))
    while bitIdx + 1 < size:
        tmpList = ""
        for it in blocks:
            tmpList += it[bitIdx] + it[bitIdx + 1]
        x.append(tmpList)
        bitIdx += 2
    return x

# Transforming cipher into blocks of key size length
def breakRepeatingKeyCode(keySizeList, s):

    scores = []

    for it in keySizeList:
        blocks = transposeBlocks(cutX(s, len(s), it), it)
        scores.append(searchBestScore(blocks))
    print(max(scores)[1])

# Finding potential key sizes with hamming distance
def findKeySizes(s, samples):

    keyDistList = []
    keySizeList = []
    finalKeySizeList = []

    for size in range(2, 40):

        tab = cutX(s, len(s), size)
        res = 0
        i = 0
        while i + 1 < len(tab):
            res += hammingDistance(str(tab[i]), str(tab[i + 1]))
            i += 1
        keyDistList.append(int(res / size))
        keySizeList.append(size)

    minList = sorted(keyDistList)[:samples]

    for it in minList:
        idx = keyDistList.index(it)
        finalKeySizeList.append(keySizeList.index(idx))

    return finalKeySizeList

def main():
    
    if len(sys.argv) != 2:
        exit(84)
    try:
        file = sys.argv[1]
        with open(file) as f:
            s = f.read().replace("\n", "").upper()
            f.close()
    except:
        exit(84)
    checkHex(s)
    breakRepeatingKeyCode(findKeySizes(s, 10), s)
    
if __name__ == "__main__":
    main()
