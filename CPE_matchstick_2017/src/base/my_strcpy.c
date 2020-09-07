/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01 Day06
*/
#include "../../include/proto.h"
#include <stdlib.h>

unsigned char *my_strcpy(unsigned char *src, unsigned int len)
{
	unsigned char *cpy = malloc(sizeof(unsigned char) * len);

	if (!cpy)
		return (NULL);
	for (unsigned int i = 0; i < len; i++)
		cpy[i] = src[i];
	cpy[len] = 0;
	return (cpy);
}
