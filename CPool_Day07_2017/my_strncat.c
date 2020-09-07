/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** task03 Day07
*/

char *my_strncat(char *dest, char const *src, int nb)
{
	int count_dest = 0;
	int count_src = 0;
	char *ptr = (char *)dest;
	
	while (dest[count_dest] != '\0')
		count_dest++;
	dest[count_dest] = 0;
	while (src[count_src] != '\0' && count_src != nb) {
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (&ptr[0]);
}
