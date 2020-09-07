#!/usr/bin/python3

from sys import argv
from base64 import b64decode, b64encode
from Crypto.Cipher import AES

def padd(string, padd_size):
    l = len(string)
    if l % padd_size == 0:
        return string
    to_padd = padd_size - l % padd_size
    i = l
    while i < l + to_padd:
        string += chr(to_padd)
        i += 1
    return string

def unpadd(array):
    l = len(array)
    padd_size = 1
    if type(array) == bytes:
        padd_size = array[l - 1]
        i = 1
        while i < padd_size:
            if array[l - i] != padd_size:
                return array
            i += 1
    elif type(array) == str:
        padd_size = ord(array[l - 1])
        i = 1
        while i < padd_size:
            if ord(array[l - i]) != padd_size:
                return array
            i += 1
    return array[0:l - padd_size]

def printOrd(string):
    for i in string:
        print(hex(ord(i)), end=' ')
    print("")
    return string

def cutX(s, l, x):
    tab = []
    for i in range(0, l, x):
        tab.append(s[i:i+x])
    return tab

def getKey(string):
    res = ""
    tab = cutX(string, len(string), 2)
    for i in tab:
        try:
            res += chr(int(i, 16))
        except ValueError:
            exit(84)
    return res

if __name__ == "__main__":
    if len(argv) != 2:
        exit(84)
    try:
        with open(argv[1]) as f:
            content = f.read()
            f.close()
    except PermissionError:
        exit(84)
    content = content.split("\n")
    try:
        del content[2]
    except IndexError:
        exit(84)
    key = getKey(content[0])
    decoded = b64decode(content[1])
    decipher = AES.new(key, AES.MODE_ECB)
    deciphered = decipher.decrypt(decoded)
    print(b64encode(unpadd(deciphered)).decode("utf-8"))
