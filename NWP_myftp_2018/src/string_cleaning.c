/*
** EPITECH PROJECT, 2019
** string_cleaning.hpp
** File description:
** string_cleaning class
*/

#include <string.h>

void backup_word(char *str, const unsigned int index)
{
    unsigned int i = index + 1;

    for (; str[i]; i++)
        str[i - 1] = str[i];
    str[i - 1] = str[i];
}

void my_clean_str(char *str)
{
    if (!str)
        return;
    for (unsigned int i = 0; str[i]; i++)
        str[i] = str[i] >= 7 && str[i] < 13 && str[i] != 10 ? ' ' : str[i];
    for (unsigned int i = 0; str[i]; i++)
        if (str[i] == ' ' && str[i + 1] && str[i + 1] == ' ') {
            backup_word(str, i);
            i = 0;
        }
    if (str[strlen(str) - 1] == ' ')
        str[strlen(str) - 1] = 0;
}