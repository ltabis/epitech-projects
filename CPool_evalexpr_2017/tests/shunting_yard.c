/*
** EPITECH PROJECT, 2017
** shunting_yard
** File description:
** reproduction of the shunting yard algorithme
*/
#include "../include/struct_test.h"
#include "../include/my.h"
#include <stdlib.h>

int number(yard_t *search)
{
	int integer = 0;
	char *replace = search->postfix;
	int i = 0;

	for (i = 0; replace[i] != '\0'; i++) {
		if (replace[i] < '0' || replace[i] > '9')
			return (integer);
		integer = (integer * 10) + (replace[i] - 48);
	}
	return (integer);
}

int count_operators(char *str)
{
	int operators = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '%' || str[i] == '/')
			operators++;
	return (operators);
}

int yard(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	yard_t *search;
	int operators = count_operators(str);

	search = malloc(sizeof(yard_t));
	search->postfix = malloc(sizeof(char) * my_strlen(str));
	search->operator_s = malloc(sizeof(char) * operators);
	my_put_nbr(operators);
	my_putchar('\n');
	search->stack_upper_value = 0;
	for (i; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			search->postfix[k] = str[i];
			k++;
		}
		if (str[i] == '+' || str[i] == '-') {
		        if (search->stack_upper_value == 0) {
				search->postfix[k] = ' ';
				k++;
				search->operator_s[j] = str[i];
				search->stack_upper_value = 2;
			} else if (search->stack_upper_value == 2) {
				search->postfix[k] = search->operator_s[j];
				k++;
				search->operator_s[j] = str[i];
			} else if (search->stack_upper_value == 3 && j != 0) {
			        for (j = 0, k; my_strlen(search->operator_s); j++, k++)
					search->postfix[k] = search->operator_s[j];
				search->stack_upper_value = 2;
				j = 0;
			} else if (search->stack_upper_value == 3 && j == 0) {
				search->postfix[k] = search->operator_s[j];
				k++;
				search->operator_s[j] = str[i];
			}
		} else if (str[i] == '*' || str[i] == '/' || str[i] == '%') {
			if (search->stack_upper_value == 0) {
			        search->postfix[k] = ' ';
				k++;
				search->operator_s[j] = str[i];
				search->stack_upper_value = 3;
			} else if (search->stack_upper_value == 2) {
				search->operator_s[j + 1] = search->operator_s[j];
				search->operator_s[j] = str[i];
				search->stack_upper_value = 3;
			} else if (search->stack_upper_value == 3 && j != 0) {
				j++;
				search->operator_s[j] = str[i];
		        } else if (search->stack_upper_value == 3) {
				search->postfix[k] = search->operator_s[j];
				k++;
				search->operator_s[j] = str[i];
		        }
		}
	}
	my_putstr(search->operator_s);
	for (j = 0, k; j < my_strlen(search->operator_s); j++, k++)
		search->postfix[k] = search->operator_s[j];
	my_putchar('\n');
	my_putstr(search->postfix);
	my_putchar('\n');
	return (search->result);
}
