/*
** EPITECH PROJECT, 2019
** shared_func_1.hpp
** File description:
** shared_func_1 class
*/

#include "nm.h"
#include "flags.h"

int len_special(const char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    for (int j = 0; str[j]; j++)
        i += str[j] != '_' ? 1 : 0;
    return (i);
}

bool disp_error(const char *program, const char *av, const char *msg,
                bool file_error)
{
    if (file_error == TRUE)
        fprintf(stderr, "%s: '%s': %s\n", program + 2, av, msg);
    else
        fprintf(stderr, "%s: %s: %s\n", program + 2, av, msg);
    return (FALSE);
}

char strcmpchar(const char *str1, const char *str2)
{
    for (unsigned int i = 0, j = 0; str1[i] && str2[j]; i++, j++) {
        for (; str1[i] && !isalpha(str1[i]); i++);
        for (; str2[j] && !isalpha(str2[j]); j++);
        if (tolower(str1[i]) < tolower(str2[j]))
            return (1);
        else if (tolower(str1[i]) > tolower(str2[j]))
            return (0);
    }
    if (len_special(str1) == len_special(str2))
        return (1);
    return ((char)(strlen(str1) > strlen(str2) ? 0 : 1));
}

int get_unused_name(const char *displayed, size_t len)
{
    for (unsigned int i = 0; i < len; i++)
        if (!displayed[i])
            return (i);
    return (-1);
}

void display_flags(unsigned int flags_hex)
{
    unsigned int last = 0;
    unsigned int mac[] = {HAS_RELOC, EXEC_P, HAS_SYMS, DYNAMIC, D_PAGED};
    char *str[] = {"HAS_RELOC", "EXEC_P", "HAS_SYMS", "DYNAMIC", "D_PAGED"};

    for (unsigned int i = 0; i < 5; i++)
        last = flags_hex & mac[i] ? i : last;
    for (unsigned int i = 0; i < 5; i++)
        if (flags_hex & mac[i] && i != last)
            printf("%s, ", str[i]);
        else if (flags_hex & mac[i] && i == last)
            printf("%s", str[i]);
    printf("\n");
}