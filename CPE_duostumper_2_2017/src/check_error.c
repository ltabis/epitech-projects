/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** checking error giving in parameter
*/

#include "../include/proto.h"
#include <stdio.h>

int checking_parameter(grid_info_t *var)
{
	if (var->width > 80 || var->height > 16) {
		fprintf(stderr, "Grid too big\n");
		return (84);
	} else if (var->width * var->height < 20) {
		fprintf(stderr, "Grid too small\n");
		return (84);
	} else if (var->p1 == var->p2 || var->p1 == var->ref ||
	var->p2 == var->ref) {
		fprintf(stderr, "Two characters are the same\n");
		return (84);
	} else if (var->p1 == '.' || var->p2 == '.' || var->ref == '.' ||
	var->p1 == '|' || var->p2 == '|' || var->ref == '|' ||
	var->p1 == '+' || var->p2 == '+' || var->ref == '+') {
		fprintf(stderr, "a character match the ones of the board\n");
		return (84);
	}
	return (0);
}
