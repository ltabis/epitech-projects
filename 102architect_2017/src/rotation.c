/*
** EPITECH PROJECT, 2017
** rotation.c
** File description:
** rotation functions for the 102architect project
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/proto.h"

#define PI 3.14159265

float **do_rotation(int rot)
{
	double ar = rot;
	unsigned int j = 0;
	unsigned int i = 0;
	float **rotate_matrix = malloc(sizeof(float) * 3);

	ar = ar * PI / 180;
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
	rotate_matrix[0][0] = cos(ar);
	rotate_matrix[0][1] = -sin(ar);
	rotate_matrix[1][0] = sin(ar);
	rotate_matrix[1][1] = cos(ar);
        return (rotate_matrix);
}
