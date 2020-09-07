/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** a function that copie a string into another one
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}
