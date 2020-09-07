/*
** EPITECH PROJECT, 2017
** operations_file_01.c
** File description:
** 5 operations for the my_pushswap project
*/
#include "include/my.h"
#include "include/proto.h"
#include "include/mylist.h"
#include <stdlib.h>

stock_t *do_sa(stock_t *stock)
{
	list_t *list = stock->l1;
	int tmp1;
	int tmp2;
	int i = 0;

	for (; list->next != 0; i++, list = list->next);
	for (; list->prev != 0; list = list->prev);
	if (i >= 2) {
		tmp1 = list->data;
		list = list->next;
		tmp2 = list->data;
		list->data = tmp1;
		list = list->prev;
		list->data = tmp2;
		stock->l1 = list;
	}
	return (stock);
}

stock_t *do_sb(stock_t *stock)
{
	list_t *list = stock->l2;
	int tmp1;
	int tmp2;
	int i = 0;

	for (; list->next != 0; i++, list = list->next);
	for (; list->prev != 0; list = list->prev);
	if (i >= 2) {
		tmp1 = list->data;
		list = list->next;
		tmp2 = list->data;
		list->data = tmp1;
		list = list->prev;
		list->data = tmp2;
		stock->l2 = list;
	}
	return (stock);
}

stock_t *do_sc(stock_t *stock)
{
	stock = do_sa(stock);
	stock = do_sb(stock);
	return (stock);
}

stock_t *do_pa(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	tmp->data = stock->l2->data;
	tmp->prev = 0;
	tmp->next = stock->l1;
	stock->l1->prev = tmp;
	stock->l1 = tmp;
	stock->l2 = stock->l2->next;
	stock->l2->prev = 0;
	return (stock);
}

stock_t *do_pb(stock_t *stock)
{
	list_t *tmp = malloc(sizeof(list_t));

	if (tmp == NULL)
		exit(84);
	tmp->data = stock->l1->data;
	tmp->prev = 0;
	tmp->next = stock->l2;
	stock->l2->prev = tmp;
	stock->l2 = tmp;
	stock->l1 = stock->l1->next;
	stock->l1->prev = 0;
	return (stock);
}
