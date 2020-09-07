/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** task05 Day06
*/

int my_strcmp(char const *s1, char const *s2)
{
	int count = 0;
	int result;

	while (s2[count] == s1[count] && s1[count] != '\0' && s2[count] != '\0')
		count++;
	result = s1[count] - s2[count];
	return (result);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
	int count = 0;
	int result;

	while (s2[count] == s1[count] && s1[count] != '\0' &&
	s2[count] != '\0' && count < n)
		count++;
	result = s1[count] - s2[count];
	return (result);
}