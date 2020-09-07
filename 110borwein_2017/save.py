#!/usr/bin/python3
from math import *

# x += 0.5 car 10000 d'intégration alors qu'on veut 5000 de valeur max

def calcul_rectangles(n):
	print("Rectangles:")

	factor = 0.5
	x = 0
	result = 0

	while x < 5000:
		result += calcul_product(n, x)
		x += 0.5
	result *= factor
	print("I" + str(n) + " = " + "{:.10f}".format(result))
	disp_diff(result)
	print("")
	return (result)

def calcul_trapezoïds(n):
	print("Trapezoids:")

	x = 0.5
	result = 0

	while x < 5000:
		result += calcul_product(n, x)
		x += 0.5

	r1 = calcul_product(n, 0)
	r2 = calcul_product(n, 5000)
	result2 = (5000 / 20000) * (r1 + r2 + (2 * result)) 
	print("I" + str(n) + " = " + "{:.10f}".format(result2))
	disp_diff(result2)
	print("")
	return (result2)

def calcul_simpson(n):
	print("Simpson:")

	x = 0.5
	x2 = 0
	result = 0
	result_spec = 0

	while x < 5000:
		result += calcul_product(n, x)
		result_spec += calcul_product(n, (x2 + (0.5 / 2)))
		x += 0.5
		x2 += 0.5
	result_spec += calcul_product(n, (x2 + (0.5 / 2)))
	r1 = calcul_product(n, 0)
	r2 = calcul_product(n, 5000)
	result2 = (5000 / 60000) * (r1 + r2 + (2 * result) + (4 * result_spec)) 
	print("I" + str(n) + " = " + "{:.10f}".format(result2))
	disp_diff(result2)
	return (result2)

def calcul_product(n, x):
	
	k = 0
	result = 1

	while k <= n and x > 0:
		result *= sin(x / (2 * k + 1)) / (x / (2 * k + 1))
		k += 1
	return result

def disp_diff(result):
	print("diff = " + "{:.10f}".format(result - (pi / 2)))
