/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** prototypes
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "base.h"

 typedef struct grid_info_s {
	unsigned int x;
	unsigned int y;
	char **grid;
	char **new_grid;
} grid_info_t;

int check_file_and_input_error(int, char * const *);
int my_is_number(char *);
int check_file_content(FILE *, grid_info_t *);
int create_grid(FILE *, grid_info_t *);
grid_info_t *parsing_file(char * const *);
void display_grid(grid_info_t *);
char **copy_grid(grid_info_t *);
int repeat_iteration(grid_info_t *, int);
int check_map_error(grid_info_t *);
void count_cells(grid_info_t *, unsigned int, unsigned int);
int update_new_iteration(grid_info_t *);
void update_grid(grid_info_t *, unsigned int, unsigned int, unsigned int);
void free_old_grid(grid_info_t *);

#endif
