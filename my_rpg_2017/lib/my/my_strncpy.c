/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** a function that copy n characters from a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n) {
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}
