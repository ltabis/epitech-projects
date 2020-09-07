/*
** EPITECH PROJECT, 2017
** debug.h
** File description:
** prototypes for the tetris debug mode
*/
#ifndef DEBUG_H_
#define DEBUG_H_

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct sz_s {
	int x;
	int y;
} sz_t;

typedef struct info_s {
	char state;
	int color;
	unsigned int piece_size;
	sz_t size;
} info_t;

typedef struct tetrimino_s {
	char **piece;
	char *name;
	info_t info;
} tetrimino_t;

void check_tetriminos_lenght_and_width(tetrimino_t *);
void analyse_characteristics(char *, info_t *);
info_t analyse_piece(char *, info_t);
info_t check_tetriminos(char *);
info_t update_infos(info_t, int, unsigned int);

#endif /* !DEBUG_H_ */