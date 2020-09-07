#!/usr/bin/python3
from sys import *
from math import *
from termcolor import colored, cprint
from curses import *

def print_matrix(matrix):
        i = 0
        l = len(matrix[0])

        while i < l:
                j = 0
                while j < l:
                        if j != l - 1:
                                cprint("{:.2f}".format(matrix[i][j]), 'white', 'on_red', end = '\t')
                        else:
                                cprint("{:.2f}".format(matrix[i][j]), 'white', 'on_red', end = '\n')
                        j += 1
                i += 1

def create_matrix(args):
        matrix = []
        i = 0
        l = int(sqrt(len(args)))
        while i < l:
                matrix.append([])
                i += 1
        i = 0
        while i < l:
                k = 0
                while k < l:
                        matrix[i].append(float(args[i * l + k]))
                        k += 1
                i += 1
        return matrix

def calc_EXP(args, identity, disp):
        i = 1
        switch = 0
        stop = 0
        matrix = create_matrix(args)
        matrix_cpy = create_matrix(args)

        matrix_result = create_matrix(args)
        matrix_cpy2 = create_matrix(args)
        j = 0
        for j in range(i - 1):
                matrix_result = multiply_matricies(matrix_result, matrix_cpy2)
        matrix_result = divid_all_terms(matrix_result, i)
        matrix_result = add_matrices(identity, matrix_result)
        i += 1
        while stop != 1:
                matrix = create_matrix(args)
                matrix_cpy2 = create_matrix(args)
                matrix_cpy = cpy_matrix(matrix_result, matrix_cpy)
                j = 0
                for j in range(i - 1):
                        matrix = multiply_matricies(matrix, matrix_cpy2)
                matrix = divid_all_terms(matrix, i)
                matrix_result = add_matrices(matrix_result, matrix)
                i += 1
                switch += 1
                stop = check_if_stop(matrix_result, matrix_cpy)
        if disp == 0:
                print_matrix(matrix_result)
        else:
                return matrix_result

def calc_COS(args, identity, disp):
        i = 2
        switch = 0
        stop = 0
        matrix = create_matrix(args)
        matrix_cpy = create_matrix(args)

        matrix_result = create_matrix(args)
        matrix_cpy2 = create_matrix(args)
        j = 0
        for j in range(i - 1):
                matrix_result = multiply_matricies(matrix_result, matrix_cpy2)
        matrix_result = divid_all_terms(matrix_result, i)
        matrix_result = sub_matrices(identity, matrix_result)
        i += 2
        while stop != 1:
                matrix = create_matrix(args)
                matrix_cpy2 = create_matrix(args)
                matrix_cpy = cpy_matrix(matrix_result, matrix_cpy)
                j = 0
                for j in range(i - 1):
                        matrix = multiply_matricies(matrix, matrix_cpy2)
                matrix = divid_all_terms(matrix, i)
                if switch % 2 == 0:
                        matrix_result = add_matrices(matrix_result, matrix)
                else:
                        matrix_result = sub_matrices(matrix_result, matrix)
                i += 2
                switch += 1
                stop = check_if_stop(matrix_result, matrix_cpy)
        if disp == 0:
                print_matrix(matrix_result)
        else:
                return matrix_result

def calc_SIN(args, identity, disp):
        i = 3
        switch = 0
        stop = 0
        matrix = create_matrix(args)
        matrix_cpy = create_matrix(args)
        
        matrix_result = create_matrix(args)
        matrix_cpy2 = create_matrix(args)
        j = 0
        for j in range(i - 1):
                matrix_result = multiply_matricies(matrix_result, matrix_cpy2)
        matrix_result = divid_all_terms(matrix_result, i)
        matrix_result = sub_matrices(matrix, matrix_result)
        i += 2
        while stop != 1:
                matrix = create_matrix(args)
                matrix_cpy2 = create_matrix(args)
                matrix_cpy = cpy_matrix(matrix_result, matrix_cpy)
                j = 0
                for j in range(i - 1):
                        matrix = multiply_matricies(matrix, matrix_cpy2)
                matrix = divid_all_terms(matrix, i)
                if switch % 2 == 0:
                        matrix_result = add_matrices(matrix_result, matrix)
                else:
                        matrix_result = sub_matrices(matrix_result, matrix)
                i += 2
                switch += 1
                stop = check_if_stop(matrix_result, matrix_cpy)
        if disp == 0:
                print_matrix(matrix_result)
        else:
                return matrix_result

def calc_COSH(args, identity, disp):
        i = 2
        switch = 0
        stop = 0
        matrix = create_matrix(args)
        matrix_cpy = create_matrix(args)

        matrix_result = create_matrix(args)
        matrix_cpy2 = create_matrix(args)
        j = 0
        for j in range(i - 1):
                matrix_result = multiply_matricies(matrix_result, matrix_cpy2)
        matrix_result = divid_all_terms(matrix_result, i)
        matrix_result = add_matrices(identity, matrix_result)
        i += 2
        while stop != 1:
                matrix = create_matrix(args)
                matrix_cpy2 = create_matrix(args)
                matrix_cpy = cpy_matrix(matrix_result, matrix_cpy)
                j = 0
                for j in range(i - 1):
                        matrix = multiply_matricies(matrix, matrix_cpy2)
                matrix = divid_all_terms(matrix, i)
                matrix_result = add_matrices(matrix_result, matrix)
                i += 2
                switch += 1
                stop = check_if_stop(matrix_result, matrix_cpy)
        if disp == 0:
                print_matrix(matrix_result)
        else:
                return matrix_result

def calc_SINH(args, identity, disp):
        i = 3
        switch = 0
        stop = 0
        matrix = create_matrix(args)
        matrix_cpy = create_matrix(args)
        
        matrix_result = create_matrix(args)
        matrix_cpy2 = create_matrix(args)
        j = 0
        for j in range(i - 1):
                matrix_result = multiply_matricies(matrix_result, matrix_cpy2)
        matrix_result = divid_all_terms(matrix_result, i)
        matrix_result = add_matrices(matrix, matrix_result)
        i += 2
        while stop != 1:
                matrix = create_matrix(args)
                matrix_cpy2 = create_matrix(args)
                matrix_cpy = cpy_matrix(matrix_result, matrix_cpy)
                j = 0
                for j in range(i - 1):
                        matrix = multiply_matricies(matrix, matrix_cpy2)
                matrix = divid_all_terms(matrix, i)
                matrix_result = add_matrices(matrix_result, matrix)
                i += 2
                switch += 1
                stop = check_if_stop(matrix_result, matrix_cpy)
        if disp == 0:
                print_matrix(matrix_result)
        else:
                return matrix_result


def multiply_matricies(matrix, matrix_cpy2):
        
        i = 0
        j = 0
        k = 0
        new_matrix = [0] * len(matrix[0])

        for i in range(len(matrix[0])):
                new_matrix[i] = [0] * len(matrix[0])
        i = 0
        for i in range(len(matrix[0])):
                j = 0
                for j in range(len(matrix[0])):
                        k = 0
                        for k in range(len(matrix[0])):
                                new_matrix[i][j] += matrix[i][k] * matrix_cpy2[k][j]
        return new_matrix

def add_matrices(matrix1, matrix2):
        i = 0
        j = 0
        result = [0] * len(matrix1[0])

        for i in range(len(matrix1[0])):
                result[i] = [0] * len(matrix1[0])
        i = 0
        for i in range(len(matrix1[0])):
                j = 0
                for j in range(len(matrix1[0])):
                        result[i][j] = matrix1[i][j] + matrix2[i][j]

        return result

def sub_matrices(matrix1, matrix2):
        i = 0
        j = 0
        result = [0] * len(matrix1[0])

        for i in range(len(matrix1[0])):
                result[i] = [0] * len(matrix1[0])
        i = 0
        for i in range(len(matrix1[0])):
                j = 0
                for j in range(len(matrix1[0])):
                        result[i][j] = matrix1[i][j] - matrix2[i][j]

        return result

def divid_all_terms(matrix, count):
        i = 0
        j = 0
        factorial = 1
        factor = 1

        for i in range(count):
                factorial = factorial * factor
                factor += 1
        i = 0
        for i in range(len(matrix[0])):
                j = 0
                for j in range(len(matrix[0])):
                        matrix[i][j] = matrix[i][j] / factorial
        return matrix

def cpy_matrix(matrix1, matrix2):
        i = 0
        j = 0

        for i in range(len(matrix1[0])):
                j = 0
                for j in range(len(matrix1[0])):
                        matrix2[i][j] = matrix1[i][j]

        return matrix2

def check_if_stop(matrix, matrix_cpy):

        i = 0
        j = 0
        k = 0
        stop = 0
        str1_cpy = "cpy"
        str2_cpy = "cpy"

        for i in range(len(matrix[0])):
                j = 0
                for j in range(len(matrix[0])):
                        k = 0
                        stop = 0
                        str1_cpy = str(matrix[i][j])
                        str2_cpy = str(matrix_cpy[i][j])
                        while stop != 1:
                                if str1_cpy[k] != str2_cpy[k]:
                                        return 0
                                if str1_cpy[k - 2] == '.':
                                        stop = 1
                                k += 1

        return 1

def calc_ALL(args, identity):

        mat1 = calc_EXP(args, identity, 1)
        mat2 = calc_COS(args, identity, 1)
        mat3 = calc_SIN(args, identity, 1)
        mat4 = calc_COSH(args, identity, 1)
        mat5 = calc_SINH(args, identity, 1)

        big_matrix = [mat1, mat2, mat3, mat4, mat5]

        stdscr = initscr()
        start_color()
        init_pair(1, 2, 0)
        init_pair(2, 0, 1)
        init_pair(3, 1, 0)
        init_pair(4, 3, 0)
        noecho()
        curs_set(0)
        stdscr.keypad(True)
        input_user = 0
        move = 5
                
        while input_user != 27:

                if input_user == 10:
                        disp_matrix_curse(big_matrix[move - 5], stdscr, move - 5)
                if input_user == KEY_UP:
                        move -= 1
                if input_user == KEY_DOWN:
                        move += 1
                if move >= 10:
                        move = 5
                if move <= 4:
                        move = 9
                stdscr.addstr(move, 1, "->", color_pair(1))
                stdscr.addstr(5, 4, "EXP matrix (exponential)");
                stdscr.addstr(6, 4, "COS matrix (cosinus)");
                stdscr.addstr(7, 4, "SIN matrix (sinus)");
                stdscr.addstr(8, 4, "COSH matrix (hyperbolic cosinus)");
                stdscr.addstr(9, 4, "SINH matrix (hyperbolic sinus)");
                stdscr.addstr(15, 4, "Press Escape to quit", color_pair(3));
                stdscr.border(0)
                draw_circle(stdscr)
                input_user = stdscr.getch()
                stdscr.erase()
                stdscr.refresh()

        endwin()


def disp_matrix_curse(mat1, stdscr, move):
        
        input_user = 0
        len1 = len(mat1)
        expr = ["exponential", "cosinus", "sinus", "hyperbolic cosinus", "hyperbolic sinus"]

        while input_user != 27:

                stdscr.addstr(3, 8, "you choosed the " + str(expr[move]) + " method", color_pair(4))
                stdscr.addstr(5, 8, str(len1) + " * " + str(len1) + " matrix", color_pair(2))
                stdscr.addstr(7, 8, getMarixString(mat1))
                stdscr.addstr(17, 8, "Press Escape to go back", color_pair(3));
                stdscr.border(0)
                input_user = stdscr.getch()
                stdscr.refresh()
                stdscr.erase()
        

def getMarixString(m):
    x = ''
    for row in m:
        x += '\t|\t'.join(str(item) for item in row)
        x += "\n\n\t"
    return x

def draw_circle(stdscr):

        x = 0
        y = 5
        m = 5 - 4 * 2
        x1 = 10
        y1 = 50

        while x <= y:
                stdscr.addstr(x + x1, y + y1, "*")
                stdscr.addstr(y + x1, x + y1, "*")
                stdscr.addstr(-x + x1, y + y1, "*")
                stdscr.addstr(-y + x1, x + y1, "*")
                stdscr.addstr(x + x1, -y + y1, "*")
                stdscr.addstr(y + x1, -x + y1, "*")
                stdscr.addstr(-x + x1, -y + y1, "*")
                stdscr.addstr(-y + x1, -x + y1, "*")
                if m > 0:
                        y -= 1
                        m = m - 8 * y
                x += 1
                m = m + 8 * x + 4