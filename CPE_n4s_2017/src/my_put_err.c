/*
** EPITECH PROJECT, 2017
** my_put_err.c
** File description:
** a function that display an error given in argument
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

void my_put_err(const char *msg)
{
	write(2, msg, my_strlen(msg));
}
