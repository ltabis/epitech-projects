/*
** EPITECH PROJECT, 2018
** my_strrevcmp.c
** File description:
** my_strcmp but reversed
*/

int my_strrevcmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int count = 0;
	unsigned int count2 = 0;

	for (; s1[count]; count++);
	for (; s2[count2]; count2++);
	for (unsigned int i = 0; s1[count] == s2[count2] && count != 0
	&& count2 != 0 && i < n; i++) {
		count--;
		count2--;
	}
	return (s1[count] - s2[count2]);
}