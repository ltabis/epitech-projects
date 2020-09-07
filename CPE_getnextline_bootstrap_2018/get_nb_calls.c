/*
** EPITECH PROJECT, 2018
** get_nb_calls.c
** File description:
** function that returns the number of time it as been called
*/

int get_nb_calls(void)
{
	static int call;

	call++;
	return (call);
}
