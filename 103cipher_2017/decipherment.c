/*
** EPITECH PROJECT, 2017
** decipherment.c
** File description:
** file for decipherment
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/proto.h"
#include "include/my.h"

float determinant_2(float a00, float a01, float a10, float a11)
{
	float det = a00 * a11 - a01 * a10;

	return (det);
}

void print_matrix(float **matrix)
{
	for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
			printf("%.3f  ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

float **co_matrix(float **matrix)
{
	float **co_matrix = malloc(sizeof(float) * 3);

	for (int i = 0; i < 3; i++)
		co_matrix[i] = malloc(sizeof(float) * 3);
	co_matrix[0][0] = determinant_2(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]);
	co_matrix[0][1] = - determinant_2(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]);
	co_matrix[0][2] = determinant_2(matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][1]);
	co_matrix[1][0] = - determinant_2(matrix[0][1], matrix[0][2], matrix[2][1], matrix[2][2]);
	co_matrix[1][1] = determinant_2(matrix[0][0], matrix[0][2], matrix[2][0], matrix[2][2]);
	co_matrix[1][2] = - determinant_2(matrix[0][0], matrix[0][1], matrix[2][0], matrix[2][1]);
	co_matrix[2][0] = determinant_2(matrix[0][1], matrix[0][2], matrix[1][1], matrix[1][2]);
	co_matrix[2][1] = - determinant_2(matrix[0][0], matrix[0][2], matrix[1][0], matrix[1][2]);
	co_matrix[2][2] = determinant_2(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
	free(matrix);
	return (co_matrix);
}

float **fill_matrix(float **matrix)
{
	float k = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = k;
			k++;
		}
	}
	return (matrix);
}

float **transposee(float **matrix)
{
	int a = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			a = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = a;
		}
	}
	return (matrix);
}

float determinant_3(float **matrix)
{
	float det = matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][1] * matrix[1][0] * matrix[2][2] -
		matrix[0][0] * matrix[1][2] * matrix[2][1];

	return (det);
}

float **inv_matrix(float **co_matrix, float det)
{
	float **inv_matrix = malloc(sizeof(float) * 3);

	for (int i = 0; i < 3; i++)
		inv_matrix[i] = malloc(sizeof(float) * 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			inv_matrix[i][j] = co_matrix[i][j] / det;
		}
	}
	free(co_matrix);
	return (inv_matrix);
}

int do_decipherment(char *c1, char *c2)
{
	float **matrix = malloc(sizeof(float) * 3);
	float det;

	for (int i = 0; i < 3; i++) {
		matrix[i] = malloc(sizeof(float) * 3);
	}
	matrix = fill_matrix(matrix);
	print_matrix(matrix);
	matrix = transposee(matrix);
	print_matrix(matrix);
	det = determinant_3(matrix);
	printf("%.3f\n\n", det);
	matrix = co_matrix(matrix);
	print_matrix(matrix);
	matrix = inv_matrix(matrix, det);
	print_matrix(matrix);
}
