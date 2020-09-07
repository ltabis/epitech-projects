#!/usr/bin/python3
import sys
HEX = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']

def main():
    if len(sys.argv) != 2:
        print("Error, wrong set of arguments.", file=sys.stderr)
        exit(84)
    readFile()

def checkHex(s):
    try:
        int(s, 16)
    except:
        exit(84)

def readFile():
    try:
        file = open(sys.argv[1], 'r')
    except Exception as error:
        print("Python couldn't open the file.", file=sys.stderr)
        exit(84)
    line1 = file.readline().replace("\n", "")
    line2 = file.readline().replace("\n", "")
    if len(line1) != len(line2):
        print("Error, the given strings aren't the same lenght.", file=sys.stderr)
        exit(84)
    checkHex(line1 + line2)
    calcHex(line1, line2)

def calcHex(line1, line2):
    try:
        a = [ito16(a) ^ ito16(b) for a, b in zip(line1, line2)]
        printHex(a)
    except Exception as error:
        print("ERROR, " + str(error), file=sys.stderr)
        exit(84)

def printHex(result):
    [print(HEX[a], end='') for a in result]
    print("")

def ito16(value):

    j = 0
    for i in HEX:
        if i == value:
            return j
        j += 1
    print("Error, string isn't in hexadecimal.", file=sys.stderr)
    exit(84)

if __name__ == "__main__":
    main()
