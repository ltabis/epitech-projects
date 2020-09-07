/*
** EPITECH PROJECT, 2017
** my_put_err.c
** File description:
** a function that display an error given in argument
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_put_err(char *msg)
{
	int size = my_strlen(msg);

	write(2, msg, size);
	return (84);
}
