/*
** EPITECH PROJECT, 2017
** generator.h
** File description:
** prototypes for a particular program
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>

typedef struct cell_s {
	int idx;
	struct cell_s *prev;
} cell_t;

typedef struct coords_s {
	int y;
	int x;
} coords_t;

cell_t *stop_searching(cell_t *);
void fill_last_walls(int, int, char *);
cell_t *destroy_left_wall_end(char *, cell_t *, int);
cell_t *destroy_upper_wall_end(char *, cell_t *, int);
cell_t *destroy_right_wall(char *, cell_t *, int);
cell_t *destroy_left_wall(char *, cell_t *, int);
cell_t *destroy_upper_wall(char *, cell_t *, int);
cell_t *destroy_below_wall(char *, cell_t *, int);
cell_t *choose_random_way(int, int, char *, cell_t *);
cell_t *create_new_cell(unsigned int, cell_t *);
cell_t *create_first_cell(void);
cell_t *get_back_to_previous_cell(char *, cell_t *, coords_t);
cell_t *choose_destroy_or_backtrack(char *, cell_t *, coords_t, int *);
cell_t *choose_random_last(int, int, char *, cell_t *);
cell_t *put_last_way(char *, cell_t *, coords_t);
cell_t *choose_destroy_or_end(char *, cell_t *, coords_t, int *);
void choose_random_place(int, int, char *, coords_t);
void free_tree(cell_t *);
int is_negative_number(char *, char *);
void display_maze(char *);
char *generate_maze(int, int, char *);
void modify_perfect_maze(int, int, char *, cell_t *);
void modify_inperfect_maze(int, int, char *, cell_t *);
int check_paramters(int, char **);
int is_number(char *);

#endif /* !GENERATOR_H_ */
