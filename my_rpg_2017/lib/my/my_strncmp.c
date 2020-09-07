/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** a function that compare two strings with a n bites limit
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (s1[i] == s2[i] && i < n) {
		i++;
		if (s1[i] == '\0')
			return (0);
	}
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
