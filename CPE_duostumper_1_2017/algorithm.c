/*
** EPITECH PROJECT, 2018
** algorithm.c
** File description:
** main file for the fractal's algorithm
*/

#include "include/proto.h"
#include <unistd.h>
#include <stdlib.h>

void compute_fractal_algorithm(int iteration, strings_t patterns,
	buff_t *buff, char *last_patern)
{
	for (unsigned int i = 0; last_patern[i]; i++) {
		if (last_patern[i] == '#' && iteration > 1) {
			compute_fractal_algorithm(iteration - 1,
			patterns, buff, my_strdup(patterns.pat1));
		} else if (last_patern[i] == '.' && iteration > 1) {
			compute_fractal_algorithm(iteration - 1,
			patterns, buff, my_strdup(patterns.pat2));
		}
		check_display(i, iteration, last_patern, patterns);
	}
	free(last_patern);
}

void check_display(unsigned int i,
	int iteration, const char *last_patern, strings_t patterns)
{
	if (last_patern[i] == '#' && iteration == 1) {
		write(1, &patterns.pat1[i], 1);
	} else if (last_patern[i] == '.' && iteration == 1)
		write(1, &patterns.pat2[i], 1);
}

buff_t create_buffer(const char *str)
{
	buff_t buff = {0, 0, 0, NULL};
	unsigned int len_str = 0;

	for (; str[len_str] && str[len_str] != '@'; len_str++);
	buff.y = len_str * len_str;
	for (unsigned int i = 0; i < len_str; i++)
		buff.x *= len_str;
	buff.buffer = malloc(sizeof(char) * (buff.y * buff.x + buff.y + 1));
	if (!buff.buffer)
		return (buff);
	buff.buffer[buff.x * buff.y + buff.y] = 0;
	return (buff);
}