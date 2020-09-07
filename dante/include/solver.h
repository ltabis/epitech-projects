/*
** EPITECH PROJECT, 2017
** solver.h
** File description:
** prototypes for a particular program
*/

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct coords_s {
	int y;
	int x;
} coords_t;

void compute_best_first_algorithm(char *maze, int, int);
int check_paramters(int, char **);
void choose_and_compute_algorithm(char **);
char *start_wall_algorithm(char *);
char compute_wall_algorithm(char *, coords_t *, int);
char *my_strcat(char *, char *);
int is_open(char *, coords_t *, int);
int backtrack(char *, coords_t *, int);

#endif /* !SOLVER_H_ */
