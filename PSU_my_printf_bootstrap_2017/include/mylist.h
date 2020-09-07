
/*
** EPITECH PROJECT, 2017
** mylist.h
** File description:
** list for day13
*/
#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct chainedStr_s
{
        char *data;
	struct chainedStr_s *next;	
} chainedStr_t;

#endif /* MYLIST_H_ */
