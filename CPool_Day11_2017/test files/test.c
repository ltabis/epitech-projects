/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** test for day11
*/
#include <stdlib.h>
#include "mytest.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int i = 0;
	
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}


int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
	}
	my_putchar(nb % 10 + 48);
}

int view_struct(struct s_person *person)
{
	my_putstr(person->first_name);
	my_putstr(person->last_name);
	my_put_nbr(person->phone_nb);
}


struct s_person *new_person(char *first_name, char *last_name, int phone_nb)
{
	struct s_person *person;

	person = malloc(sizeof(struct s_person));
	if (person == NULL)
		return (NULL);
	person->first_name = first_name;
	person->last_name = last_name;
	person->phone_nb = phone_nb;
	return (person);
}

int main(int argc, char *argv[])
{
	struct s_person *person;

	person = new_person("sherlock", "Holmes", 232442);
	view_struct(person);
	free(person->first_name);
	free(person->last_name);
	free(person);
	return (0);
}
