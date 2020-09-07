/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the 102architect project
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/proto.h"

int main(int argc, char **argv)
{
	unsigned int decal = 3;
	int i = 0;
	unsigned int j = 0;
        float **rotate_matrix = malloc(sizeof(float) * 3);
	float x = 0;
	float y = 0;
	char c;
	int nbr = 1;
        
	if (argc <= 3) {
		how_to_use();
		exit(84);
	}
	if (rotate_matrix == NULL)
		exit(84);
	for (i = 0; i < 3; i++) {
		rotate_matrix[i] = malloc(sizeof(float) * 3);
		if (rotate_matrix[i] == NULL)
			exit(84);
		for (j = 0; j < 3; j++)
			rotate_matrix[i][j] = 0;
	}
	if (argv[3][0] != '-')
		exit(84);
	for (j = 0; argv[i][j] != '\0'; j++) {
		if (argv[i][0] != '-') {
			if (argv[i][j] < '0' || argv[i][j] > '9')
				exit(84);
		}
	}
	for (i = 1; argv[i] != 0; i++) {
		for (j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][0] != '-')
				if (argv[i][j] < '0' || argv[i][j] > '9')
					exit(84);
		}
	}
	for (j = 0, i = 1; i != argc; i++) {
	        if (argv[i][0] == '-' && (argv[i][1] < '0' || argv[i][1] > '9')) {
		        c = argv[i][1];
			switch (c) {
			case 't':
				if (argv[i+1] == NULL || argv[i+2] == NULL)
					exit(84);
				else if (argv[i+3] != NULL && argv[i+3][0] != '-')
					exit(84);
				else
					printf("Translation by the vector (%d, %d)\n", my_getnbr(argv[i+1]), my_getnbr(argv[i+2]));
				break;
			case 'h':
				if (argv[i+1] == NULL || argv[i+2] == NULL)
					exit(84);
			        else if (argv[i+3] != NULL && argv[i+3][0] != '-')
					exit(84);
				else
					printf("Homothety by the ratios %d and %d\n", my_getnbr(argv[i+1]), my_getnbr(argv[i+2]));
				break;
			case 'r':
				if (argv[i+1] == NULL)
					exit(84);
			        else if (argv[i+2] != NULL && argv[i+2][0] != '-')
					exit(84);
				else
					printf("Rotation at a %d degree angle\n", my_getnbr(argv[i+1]));
				break;
			case 's':
				if (argv[i+1] == NULL)
					exit(84);
				else if (argv[i+2] != NULL && argv[i+2][0] != '-')
					exit(84);
				else
			        	printf("Symmetry about an axis inclined with an angle of %d degrees\n", my_getnbr(argv[i+1]));
				break;
			default:
				exit(84);
		        }
		}
	}
	for (i = argc - 1; nbr != 0; i--) {
       		if (argv[i][0] == '-' && (argv[i][1] < '0' || argv[i][1] > '9') && argv[i+1] != NULL) {
		        c = argv[i][1];
		        switch (c) {
			case 't':
			        rotate_matrix = do_translation(my_getnbr(argv[i+1]), my_getnbr(argv[i+2]));
				nbr--;
				i--;
			        break;
			case 'h':
				rotate_matrix = do_homothety(my_getnbr(argv[i+1]), my_getnbr(argv[i+2]));
				nbr--;
				i--;
				break;
			case 'r':
				rotate_matrix = do_rotation(my_getnbr(argv[i+1]));
				nbr--;
				i--;
				break;
			case 's':
				rotate_matrix = do_symmetry(my_getnbr(argv[i+1]));
				nbr--;
				i--;
				break;
			default:
				exit(84);
			}
		}
	}
	for (; i != 0; i--) {
	        if (argv[i][0] == '-' && (argv[i][1] < '0' || argv[i][1] > '9') && argv[i+1] != NULL) {
		        c = argv[i][1];
		        switch (c) {
			case 't':
			        rotate_matrix = calculate_result(rotate_matrix, do_translation(my_getnbr(argv[i+1]), my_getnbr(argv[i+2])));
			        break;
			case 'h':
				rotate_matrix = calculate_result(rotate_matrix, do_homothety(my_getnbr(argv[i+1]), my_getnbr(argv[i+2])));
			        break;
			case 'r':
				rotate_matrix = calculate_result(rotate_matrix, do_rotation(my_getnbr(argv[i+1])));
			        break;
			case 's':
				rotate_matrix = calculate_result(rotate_matrix, do_symmetry(my_getnbr(argv[i+1])));
			        break;
			default:
				exit(84);
			}
		}
	}
        for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++)
			if (rotate_matrix[i][j] == -0)
				printf("0.00\t");
			else
				printf("%.2f\t", rotate_matrix[i][j]);
		if (rotate_matrix[i][j] == -0)
			printf("0.00");
		else
			printf("%.2f", rotate_matrix[i][j]);
		putchar('\n');
	}
	x = calculate_vector_x(my_getnbr(argv[1]), my_getnbr(argv[2]), rotate_matrix);
	y = calculate_vector_y(my_getnbr(argv[1]), my_getnbr(argv[2]), rotate_matrix);	
        printf("(%d,%d) => (%.2f,%.2f)\n", my_getnbr(argv[1]), my_getnbr(argv[2]), x, y);
	
}

void how_to_use(void)
{
        write(2, "\n                      HOW TO USE\n", 36);
	write(2, "\n   - first two arguments must be the x and y coordnates\n", 59);
	write(2, "\n   - the next argument is the transformation to be done\n", 59);
	write(2, "\n Use '-' and 't', 'h', 'r' or 's' to select the transform\n", 61);
	write(2, "\n    Then indicate the angle/coordinates in each case\n\n", 58);
	exit(84);
}

float **calculate_result(float **mat1, float **mat2)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;
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
        for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				rotate_matrix[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return (rotate_matrix);
}

float calculate_vector_x(int x, int y, float **arr)
{
	float j = 0;

	j += x * arr[0][0];
	j += y * arr[0][1];
	j += arr[0][2];
	return (j);
}

float calculate_vector_y(int x, int y, float **arr)
{
	float j = 0;

	j += x * arr[1][0];
	j += y * arr[1][1];
        j += arr[1][2];
	return (j);
}
