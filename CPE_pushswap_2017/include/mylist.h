/*
** EPITECH PROJECT, 2017
** mylist.h
** File description:
** chained list for my_pushswap
*/
#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct list_s {
        int data;
        struct list_s *prev;
	struct list_s *next;
} list_t;

#endif /* !MYLIST_H_ */
