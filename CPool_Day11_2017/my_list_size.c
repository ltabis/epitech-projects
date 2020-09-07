/*
** EPITECH PROJECT, 2017
** my_list_size.c
** File description:
** task02 Day11
*/
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
	linked_list_t *count;
	int i = 1;

	count = begin;
	while (count->next != 0) {
		count = count->next;
		i++;
	}
	return (i);
}
