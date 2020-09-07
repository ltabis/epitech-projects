/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for my_pushswape
*/
#include "mylist.h"
#include "structlists.h"
#ifndef PROTO_H_
#define PROTO_H_

void display_swap(stock_t *);
void verify_descending_order_la(stock_t *, int, unsigned int);
int main(int, char **);
int push_swap(int, char **, unsigned int);
int verify_descending_order_lb(stock_t *);
list_t *build_list(int, char **);
stock_t *do_sa(stock_t *);
stock_t *do_sb(stock_t *);
stock_t *do_sc(stock_t *);
stock_t *do_pa(stock_t *);
stock_t *do_pb(stock_t *);
stock_t *do_rr(stock_t *);
stock_t *do_ra(stock_t *);
stock_t *do_rb(stock_t *);
stock_t *do_rrb(stock_t *);
stock_t *do_rra(stock_t *);
stock_t *do_rrr(stock_t *);
stock_t *algo_swap(stock_t *, int, unsigned int);
stock_t *pass_to_l2(stock_t *, int);
stock_t *put_sorted_in_l1(stock_t *, int, unsigned int);

#endif /* !PROTO_H_ */
