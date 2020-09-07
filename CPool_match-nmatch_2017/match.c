/*
** EPITECH PROJECT, 2017
** match.c
** File description:
** project match
*/
#include "include/my.h" 

int match(char const *s1, char const *s2)
{
	int move_s1 = 0;
	int move_s2 = 0;

	while (s1[move_s1] != '\0' || s2[move_s2] != '\0') {
		if (s2[move_s2] == s1[move_s1]) {
			move_s1++;
			move_s2++;
		}
		if (s2[move_s2] != s1[move_s1]) {
			if (s2[move_s2 - 1] == '*' && s2[move_s2] != '*')
				move_s1++;
			else if (s2[move_s2] == '*' && s2[move_s2 + 1] != '*' || s2[move_s2] == '*' && s2[move_s2 + 1] == '*')
				move_s2++;
			else
				return (0);
		}
	}
        return (1);
}
