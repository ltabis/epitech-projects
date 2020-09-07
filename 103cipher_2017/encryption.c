/*
** EPITECH PROJECT, 2017
** encryption.c
** File description:
** file for encryption
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/proto.h"
#include "include/my.h"

int do_encryption(char *c1, char *c2)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int row = 0;
	float row2 = 0;
	unsigned int row3 = 0;
        int triple = 0;
	int **msg;
	int **key;
	int **cyp;

	for (i = 0; c2[i] != '\0'; i++);
	row2 = sqrt(i);
	for (i = 0, triple = 0; c2[i] != '\0'; triple++, i++) {
		if (triple >= row2)
			triple = 0;
		if (triple == 0)
			row++;
	}
	if (row < row2)
		row++;
	key = create_key_matrix(c2, row);
	printf("Key matrix :\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < row - 1; j++)
			printf("%i\t", key[i][j]);
		printf("%i\n", key[i][j]);
	}
	for (i = 0, triple = 0; c1[i] != '\0'; triple++, i++) {
                if (triple == row)
                        triple = 0;
		if (triple == 0)
                        row3++;
        }
	msg = create_message_matrix(c1, row, row3);
	cyp = encrypt_msg(msg, key, row, row3);
	printf("\nEncrypted message :\n");
	for (i = 0; i < row3; i++) {
		for (j = 0; j < row; j++) {
			if (i == row3 - 1 && j == row - 1 && cyp[i][j] != 0)
				printf("%i", cyp[i][j]);
			else if (cyp[i][j] != 0)
				printf("%i ", cyp[i][j]);
		}
	}
	putchar('\n');
	return (0);
}

int **create_key_matrix(char *c1, unsigned int row)
{
	unsigned int j = 0;
	unsigned int i = 0;
	int **mat;

	mat = malloc(sizeof(int *) * row);
	if (mat == NULL)
		exit(84);
	for (unsigned int decal = 0; i < row; i++) {
		mat[i] = malloc(sizeof(int) * row);
		if (mat[i] == NULL)
			exit(84);
		for (j = 0; j < row && c1[decal] != '\0'; j++, decal++)
			mat[i][j] = c1[decal];
		if (j < row) {
			for (; j < row; j++)
				mat[i][j] = 0;
		}
	}
	return (mat);
}

int **create_message_matrix(char *c1, unsigned int row, unsigned int row2)
{
	unsigned int j = 0;
	unsigned int i = 0;
	int **mat;

	mat = malloc(sizeof(int *) * row2);
	if (mat == NULL)
		exit(84);
	i = 0;
	for (unsigned int decal = 0; i < row2; i++) {
		mat[i] = malloc(sizeof(int) * row);
		if (mat[i] == NULL)
			exit(84);
		for (j = 0; j < row && c1[decal] != '\0'; j++, decal++)
			mat[i][j] = c1[decal];
		if (j < row) {
			for (; j < row; j++)
				mat[i][j] = 0;
		}
	}
	return (mat);
}

int **encrypt_msg(int **msg, int **key, unsigned int row, unsigned int row2)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	int **mat = malloc(sizeof(int *) * row2);

	if (mat == NULL)
		exit(84);
	for (i = 0; i < row2; i++) {
		mat[i] = malloc(sizeof(int) * row);
		if (mat[i] == NULL)
			exit(84);
		for (j = 0; j < row; j++)
			mat[i][j] = 0;
	}
	for (i = 0; i < row2; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < row; k++) {
				mat[i][j] += msg[i][k] * key[k][j];
			}
		}
	}
	return (mat);
}
