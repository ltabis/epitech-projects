/*
** EPITECH PROJECT, 2017
** nmatch.c
** File description:
** project task02 week2
*/

int match(char const *s1, char const *s2)
{
	int move_s1 = 0;
	int move_s2 = 0;
	int count_matches = 0;
	
	while (s1[move_s1] != '\0' || s2[move_s2] != '\0') {
		if (s2[move_s2] == s1[move_s1]) {
			move_s1++;
			move_s2++;
		}
		if (s2[move_s2] != s1[move_s1]) {
			if (s2[move_s2 - 1] == '*' && s2[move_s2] != '*')
				move_s1++;
			else if (s2[move_s2] == '*' && s2[move_s2 + 1] != '*' || s2[move_s2] == '*' && s2[move_s2 + 1] == '*')
				move_s2++;
		        else
				return (0);
		}
	}
	printf("%i\n", move_s2);
	return (1);
}

int nmatch(char const *s1, char const *s2)
{

}

void main(void)
{
	char s1[] = "abcbd";
	char s2[] = "*b*";
	match(s1, s2);
}
