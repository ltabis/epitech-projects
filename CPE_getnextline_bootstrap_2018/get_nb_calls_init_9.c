/*
** EPITECH PROJECT, 2018
** get_nb_calls_init_9.c
** File description:
** same function as get_nb_calls but initiated at 9
*/

int get_nb_calls_init_9(void)
{
	static int call = 9;

	call++;
	return (call);
}
