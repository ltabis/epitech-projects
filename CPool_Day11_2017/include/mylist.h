/*
** EPITECH PROJECT, 2017
** mylist.h
** File description:
** linked_list
*/
#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct linked_list
{
	void *data;
	struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char * const *av);
int my_list_size(linked_list_t const *begin);
int my_rev_list(linked_list_t const **begin);

#endif /* MYLIST_H_ */
