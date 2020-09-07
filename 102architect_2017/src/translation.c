/*
** EPITECH PROJECT, 2017
** translation.c
** File description:
** 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/proto.h"

float **do_translation(int a, int b)
{
        unsigned int j = 0;
        unsigned int i = 0;
	float aa = a;
	float bb = b;
        float **rotate_matrix = malloc(sizeof(float) * 3);

        if (rotate_matrix == NULL)
                exit(84);
        for (i = 0; i < 3; i++) {
                rotate_matrix[i] = malloc(sizeof(float) * 3);
                if (rotate_matrix[i] == NULL)
                        exit(84);
                for (j = 0; j < 3; j++) {
                        rotate_matrix[i][j] = 0;
                }
        }
        for (i = 0; i < 3; i++)
                rotate_matrix[i][i] = 1;
        rotate_matrix[0][2] = aa;
        rotate_matrix[1][2] = bb;
        return (rotate_matrix);
}
