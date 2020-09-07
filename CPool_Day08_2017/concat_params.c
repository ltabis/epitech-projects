/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** task02 Day08
*/
#include <stdlib.h>

int count_len(int i, int arg, char **arv)
{
	int count = 0;
	int r = 0;
	
	while (count != arg) {
		while(arv[count][r] != '\0') {
			r++;
			i++;
		}
		r = 0;
		count++;
	}
	return (i);
}

char *concat_params(int argc, char **argv)
{
	int i = count_len(i, argc, argv);
	int j = 0;
	int k = 0;
	char *string = malloc(sizeof(char) * (i + argc) + 1);
 
	i = 0;
	while (i < argc) {
		j = 0;
		while (argv[i][j] != '\0') {
			string[k] = argv[i][j];
			j++;
			k++;
		}
		i++;
		if (i != argc)
			string[k] = '\n';
		k++;
	}
	string[k] = '\0';
	return (string);
}
