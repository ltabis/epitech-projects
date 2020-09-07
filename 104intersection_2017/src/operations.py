#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from math import *

PI = 3.141592654

def calc_delta(a, b, c):
    delta = (b*b)-(4*a*c)
    return delta

def calc_one_sol(a, b, argv):
    sol = (-b)/(2.0*a)
    xf = float(argv[2]) + sol * float(argv[5])
    yf = float(argv[3]) + sol * float(argv[6])
    zf = float(argv[4]) + sol * float(argv[7])
    print("({:.3f}, {:.3f}, {:.3f})".format(xf, yf, zf))

def calc_two_sol(a, b, delta, argv):
    sol = ((-b) + sqrt(delta)) / (2 * a)
    xf = float(argv[2]) + sol * float(argv[5])
    yf = float(argv[3]) + sol * float(argv[6])
    zf = float(argv[4]) + sol * float(argv[7])
    print("({:.3f}, {:.3f}, {:.3f})".format(xf, yf, zf))
    sol = ((-b) - sqrt(delta)) / (2 * a)
    xf = float(argv[2]) + sol * float(argv[5])
    yf = float(argv[3]) + sol * float(argv[6])
    zf = float(argv[4]) + sol * float(argv[7])
    print("({:.3f}, {:.3f}, {:.3f})".format(xf, yf, zf))

def calc_result(a, b, c, delta, argv):
    if (delta < 0):
        print("No intersection point.")
    elif (delta == 0):
        print("1 intersection point :")
        calc_one_sol(a, b, argv)
    elif (delta > 0):
        print("2 intersection points :")
        calc_two_sol(a, b, delta, argv)
    
def do_sphere(argv):
    print("sphere of radius {}".format(argv[8]));
    print("straight line going through the ({},{},{}) point and of direction vector ({},{},{})".format(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]));
    a = (float(argv[5]) * float(argv[5]) + float(argv[6]) * float(argv[6]) + float(argv[7]) * float(argv[7]))
    b = 2 * (float(argv[2]) * float(argv[5]) + float(argv[3]) * float(argv[6]) + float(argv[4]) * float(argv[7]))
    c = (float(argv[2]) * float(argv[2]) + float(argv[3]) * float(argv[3]) + float(argv[4]) * float(argv[4]) - float(argv[8]) * float(argv[8]))
    delta = calc_delta(a, b, c)
    calc_result(a, b, c, delta, argv)

def do_cylinder(argv):
    print("cylinder of radius {}".format(argv[8]))
    print("straight line going through the ({},{},{}) point and of direction vector ({},{},{})".format(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]));
    delta = calc_delta(a, b, c)
    calc_result(a, b, c, delta, argv)

def do_cone(argv):
    angle = int(argv[8])
    while angle >= 360:
        angle = angle - 360
    print("cone of degree angle {}".format(angle))
    print("straight line going through the ({},{},{}) point and of direction vector ({},{},{})".format(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]));
    if angle > 90:
        angle = angle - ((angle - 90) * 2)
    elif angle < -90:
        angle = angle + ((-angle - 90) * 2)
    angle = (PI / 2) - (angle * PI / 180)
    a = float(argv[5]) * float(argv[5]) + float(argv[6]) * float(argv[6]) - (float(argv[7]) * float(argv[7])) / (tan(angle) * tan(angle))
    b = 2 * (float(argv[2]) * float(argv[5])) + 2 * (float(argv[3]) * float(argv[6])) - 2 * ((float(argv[4]) * float(argv[7]))) / (tan(angle) * tan(angle))
    c = float(argv[2]) * float(argv[2]) + float(argv[3]) * float(argv[3]) - (float(argv[4]) * float(argv[4])) / (tan(angle) * tan(angle))
    delta = calc_delta(a, b, c)
    calc_result(a, b, c, delta, argv)
