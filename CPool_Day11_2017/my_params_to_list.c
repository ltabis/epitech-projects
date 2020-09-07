/*
** EPITECH PROJECT, 2017
** my_params_to_list.c
** File description:
** task01 Day11
*/
#include <stdlib.h>
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
	linked_list_t *link_base;
	int count = 1;
	
	link_base = malloc(sizeof(linked_list_t));
	link_base->data = av[0];
	link_base->next = 0;
	while (count < ac) {
		linked_list_t *link;
		link = malloc(sizeof(linked_list_t));
		link->data = av[count];
		link->next = link_base;
		link_base = link;
		count++;
	}
	return (link_base);
}
