/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** task04 DayO4
*/

char *my_strstr(char const *str, char const *to_find)
{

	int count = 0;
	int n = 0;
	int save;
	char *b = (char *)str;

	while (to_find[n] != str[count])
		count++;
	save = count;
	while (to_find[n] == str[count] && to_find[n] != '\0') {
		count++;
		n++;
	}
	if (to_find[n] == '\0') {
		return (&b[count - n]);	
	} else
		return (0);
}
