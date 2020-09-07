/*
** EPITECH PROJECT, 2017
** zomm.c
** File description:
** 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/proto.h"

float **do_homothety(int a, int b)
{
	float aa = a;
	float bb = b;
	unsigned int j = 0;
        unsigned int i = 0;
        float **rotate_matrix = malloc(sizeof(float) * 3);

        if (rotate_matrix == NULL)
                exit(84);
        for (i = 0; i < 3; i++) {
	        rotate_matrix[i] = malloc(sizeof(float) * 3);
                if (rotate_matrix[i] == NULL)
                        exit(84);
                for (j = 0; j < 3; j++)
                        rotate_matrix[i][j] = 0;
        }
        rotate_matrix[2][2] = 1;
        rotate_matrix[0][0] = aa;
        rotate_matrix[1][1] = bb;
        return (rotate_matrix);
}
