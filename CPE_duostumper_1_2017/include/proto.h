/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** stumper functions prototypes
*/

#ifndef PROTO_H_
#define PROTO_H_

typedef struct strings_s {
	const char *pat1;
	const char *pat2;
} strings_t;

typedef struct buff_s {
	unsigned int *curr_place;
	unsigned int y;
	unsigned int x;
	char *buffer;
} buff_t;

int my_isnum(char *);
char *my_strdup(const char *);
unsigned int my_strlen(const char *);
int my_getnbr(const char *, const unsigned int,
	unsigned int, unsigned int);
void compute_fractal_algorithm(int, strings_t,
	buff_t *, char *);
void check_display(unsigned int,
	int, const char *, strings_t);
buff_t create_buffer(const char *);

#endif /* !PROTO_H_ */
