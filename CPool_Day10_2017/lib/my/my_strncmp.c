/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** task06 Day06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{

	int count = 0;
	int result;
	
	while (s2[count] == s1[count] && s1[count] != '\0' && s2[count] != '\0' && n - 1 != 0) {
		count++;
		n--;
	}
	result = s1[count] - s2[count];
	return (result);
}
