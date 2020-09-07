/*
** EPITECH PROJECT, 2018
** checking_error
** File description:
** check the error
*/

int checking_error(char *str)
{
	unsigned int i = 0;

	while (str[i]) {
		if (str[i] == '#' || str[i] == '@' || str[i] == '.')
			i++;
		else
			return (84);
	}
	return (0);
}

int is_ar(char *str)
{
	unsigned int i = 0;

	for (; str[i] != '\0'; i++) {
		if (str[i] == '@')
			i++;
	}
	if (i == 0)
		return (84);
	return (0);
}

int value_befor_ar(char *str)
{
	unsigned int i = 0;

	for (; str[i] != '@'; i++);
	return (i);		
}

int check_ar(char *str)
{
	unsigned int begin = 0;
	unsigned int end = 0;
	unsigned int a = value_befor_ar(str);
	unsigned int i = 0;
	unsigned int result = 0;

	for (; str[i] != '\0'; i++, end++) {
		result = end - begin;
		if (str[i] == '@')
			begin = end;
		if (result != a)
			return (84);
	}
	return (0);
}