/*
** EPITECH PROJECT, 2017
** mytest.h
** File description:
** test for Day11
*/
#ifndef MYTEST_H_
#define MYTEST_H_ 


struct s_person
{
	char first_name;
	char last_name;
	int phone_nb;
};

int view_struct(struct s_person *person);
struct s_person *new_person(char *first_name, char *last_name, int phone_nb);

#endif /* MYTEST_H_ */
