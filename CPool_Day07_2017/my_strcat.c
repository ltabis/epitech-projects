/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** task02 Day07
*/

char *my_strcat(char *dest, char const *src)
{
	int count_dest = 0;
	int count_src;
	char *ptr = (char *)dest;

	while (dest[count_dest] != '\0')
		count_dest++;
	dest[count_dest] = 0;
	while (src[count_src] != '\0') {
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (&ptr[0]);
}
