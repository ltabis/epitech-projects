/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** usefule functions for the push_swap project
*/
#include <stdlib.h>
#include "include/my.h"
#include "include/proto.h"
#include "include/mylist.h"
#include "include/structlists.h"

void verify_descending_order_la(stock_t *stock, int ac, unsigned int disp)
{
	int j = 0;
	int tmp = 0;
	int tmp2 = 0;

	for (; tmp2 >= tmp && stock->l1->next != 0; j++) {
		tmp = stock->l1->data;
		stock->l1 = stock->l1->next;
		tmp2 = stock->l1->data;
	}
	if (j == ac) {
		if (disp == 1)
			display_swap(stock);
		else
			my_putchar('\n');
		exit(0);
	}
	for (; stock->l1->prev != 0; stock->l1 = stock->l1->prev);
}

int verify_descending_order_lb(stock_t *stock)
{
	int j = 0;
	int tmp = 0;
	int tmp2 = 0;

	for (; tmp >= tmp2 && stock->l2->next != 0; j++) {
		tmp = stock->l2->data;
		stock->l2 = stock->l2->next;
		tmp2 = stock->l2->data;
	}
	return (j);
}

stock_t *pass_to_l2(stock_t *stock, int ac)
{
	int tmp = 0;
	int tmp2 = 0;
	int i = 0;

	for (; i != ac; i++) {
		tmp = stock->l1->data;
		stock->l1 = stock->l1->next;
		tmp2 = stock->l1->data;
		stock->l1 = stock->l1->prev;
		if (tmp > tmp2) {
			stock = do_sa(stock);
			my_putstr("sa ");
		}
		stock = do_pb(stock);
		my_putstr("pb ");
	}
	return (stock);
}

stock_t *put_sorted_in_l1(stock_t *stock, int ac, unsigned int disp)
{
	int i = 0;

	for (; stock->l1->prev != 0; stock->l1 = stock->l1->prev);
	for (; stock->l2->prev != 0; stock->l2 = stock->l2->prev);
	for (i = 0; i != ac; i++, stock = do_pa(stock)) {
		if (i != ac - 1)
			my_putstr("pa ");
		else
			my_putstr("pa\n");
	}
	if (disp == 1)
		display_swap(stock);
	return (stock);
}
