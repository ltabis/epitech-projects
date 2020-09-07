/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/

#ifndef PROTO_H_
#define PROTO_H_

typedef struct bsq_s {
	int x;
	int y;
	int x_save;
	int y_save;
	int size_max;
	char **x_file;
} bsq_t;

int main(int, char **);
char *concat_params(char *, char *);
void free_memory(bsq_t *);
void verify_file_stat(char *);
void verify_file_content(char *);
void display_biggest_square(bsq_t *);
bsq_t *draw_x_and_stock(bsq_t *);
bsq_t *find_biggest_square(bsq_t *);
bsq_t *add_custom_malloc_file_row(bsq_t *);
bsq_t *add_custom_malloc_file_col(bsq_t *, int);
bsq_t *verify_square(bsq_t *, int, int, int);
bsq_t *load_2d_arr_from_file(char *, bsq_t *);
bsq_t *find_widht_and_height(bsq_t *, char *);

#endif /* !PROTO_H_ */
