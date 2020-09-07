/*
** EPITECH PROJECT, 2017
** push_swap.c
** File description:
** functions used in push_swap for the project
*/
#include "include/my.h"
#include "include/proto.h"
#include "include/mylist.h"
#include "include/structlists.h"
#include <stdlib.h>

int push_swap(int ac, char **av, unsigned int disp)
{
	list_t *l1 = build_list(ac, av);
	list_t *l2 = malloc(sizeof(list_t));
	stock_t *stock = malloc(sizeof(stock_t));

	l2->next = 0;
	l2->prev = 0;
	l2->data = 0;
	stock->l1 = l1;
	stock->l2 = l2;
	verify_descending_order_la(stock, ac - 1, disp);
	stock = algo_swap(stock, ac - 1, disp);
	return (0);
}

list_t *build_list(int ac, char **av)
{
	list_t *tmp = malloc(sizeof(list_t));
	list_t *new = malloc(sizeof(list_t));
	int i = 1;

	if (tmp == NULL || new == NULL)
		exit(84);
	for (new->next = 0, new->prev = 0; i < ac ; i++) {
		tmp = malloc(sizeof(list_t));
		if (tmp == NULL)
			exit(84);
		new->data = my_getnbr(av[i]);
		tmp->next = 0;
		tmp->prev = new;
		new->next = tmp;
		new = tmp;
	}
	for (; new->prev != 0; new = new->prev);
	return (new);
}

void display_swap(stock_t *stock)
{
	list_t *l1 = stock->l1; 
	list_t *l2 = stock->l2;

	my_putstr("\n\nl1 : ");
	while (l1->next != 0) {
		my_put_nbr(l1->data);
		l1 = l1->next;
		my_putchar(' ');
	}
	my_putstr("\nl2 : ");
	while (l2->next != 0) {
		my_put_nbr(l2->data);
		l2 = l2->next;
		my_putchar(' ');
	}
	my_putstr("\n\n");
}

stock_t *do_rrr(stock_t *stock)
{
	stock = do_rra(stock);
	stock = do_rrb(stock);
	return (stock);
}

stock_t *algo_swap(stock_t *stock, int ac, unsigned int disp)
{
	int i = 0;
	int j = 0;

	if (disp == 1)
		display_swap(stock);
	stock = pass_to_l2(stock, ac);
	j = verify_descending_order_lb(stock);
	if (j != ac) {
		if (disp == 1)
			display_swap(stock);
		for (; stock->l2->prev != 0; stock->l2 = stock->l2->prev);
		for (i = 0; i != ac; i++, stock = do_pa(stock))
			my_putstr("pa ");
		stock = algo_swap(stock, ac, disp);
	} else
		stock = put_sorted_in_l1(stock, ac, disp);
	return (stock);
}
