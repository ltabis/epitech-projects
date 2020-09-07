/*
** EPITECH PROJECT, 2017
** mystruct.h
** File description:
** structure to stock argument fot my_ls
*/
#ifndef MYSTRUCT_H_
#define MYSTRUCT_H_

typedef struct stock_s {
	char options[6];
	unsigned int foldNbr;
	char **elem;
} stock_t;

#endif /* !MYSTRUCT_H_ */
