/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** task05 Day06
*/

int my_strcmp(char *s1, char *s2)
{
	int count = 0;
	int result = 0;

	while (s2[count] == s1[count] &&
	s1[count] != '\0' && s2[count] != '\0')
		count++;
	result = s1[count] - s2[count];
	return (result);
}

int my_strcmp_env(char *s1, char *s2)
{
	int count = 0;
	int i = 0;

	for (; s2[i] != 0 && s2[i] != ' '; i++);
	while (s2[count] == s1[count] &&
	s1[count] != ' ' && s2[count] != ' ' &&
	s1[count] != '\0' && s2[count] != '\0')
		count++;
	if (count == i && (s1[count] == ' ' || s1[count] == '\t' ||
	s1[count] == 0))
		return (0);
	return (1);
}
