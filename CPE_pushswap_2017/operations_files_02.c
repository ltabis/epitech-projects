/*
** EPITECH PROJECT, 2017
** operations_files_02.c
** File description:
** second file with other types of operations
*/
#include "include/my.h"
#include "include/proto.h"
#include "include/mylist.h"
#include "include/structlists.h"
#include <stdlib.h>

stock_t *do_ra(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	tmp->data = stock->l1->data;
	stock->l1 = stock->l1->next;
	stock->l1->prev = 0;
	for (; stock->l1->next != 0; stock->l1 = stock->l1->next);
	tmp->prev = stock->l1;
	tmp->next = 0;
	stock->l1->data = tmp->data;
	stock->l1->next = tmp;
	for (; stock->l1->prev != 0; stock->l1 = stock->l1->prev);
	return (stock);
}

stock_t *do_rb(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	tmp->data = stock->l2->data;
	stock->l2 = stock->l2->next;
	stock->l2->prev = 0;
	for (; stock->l2->next != 0; stock->l2 = stock->l2->next);
	tmp->prev = stock->l2;
	tmp->next = 0;
	stock->l2->data = tmp->data;
	stock->l2->next = tmp;
	for (; stock->l2->prev != 0; stock->l2 = stock->l2->prev);
	return (stock);
}

stock_t *do_rr(stock_t *stock)
{
	stock = do_ra(stock);
	stock = do_rb(stock);
	return (stock);
}

stock_t *do_rra(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	for (; stock->l1->next != 0; stock->l1 = stock->l1->next);
	stock->l1 = stock->l1->prev;
	tmp->data = stock->l1->data;
	stock->l1->next = 0;
	for (; stock->l1->prev != 0; stock->l1 = stock->l1->prev);
	tmp->next = stock->l1;
	tmp->prev = 0;
	stock->l1->prev = tmp;
	stock->l1 = stock->l1->prev;
	return (stock);
}

stock_t *do_rrb(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	for (; stock->l2->next != 0; stock->l2 = stock->l2->next);
	stock->l2 = stock->l2->prev;
	tmp->data = stock->l2->data;
	stock->l2->next = 0;
	for (; stock->l2->prev != 0; stock->l2 = stock->l2->prev);
	tmp->next = stock->l2;
	tmp->prev = 0;
	stock->l2->prev = tmp;
	stock->l2 = stock->l2->prev;
	return (stock);
}
