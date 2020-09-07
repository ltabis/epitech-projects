/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, split_struct)
{
    string_t s;
    string_t **new;
    char *responses[50] = {"", "séparation", "", "de", "", "mots",
    "", "mdr", "", "prochain", "", "vides", ""};

    string_init(&s, ";séparation;;de;;mots;;mdr;;prochain;;vides;");
    new = split_s(&s, ';');
    string_destroy(&s);
    for (unsigned int i = 0; new[i]; i++)
        cr_assert_str_eq(responses[i], new[i]->str);
    for (unsigned int i = 0; new[i]; i++)
        string_destroy(new[i]);
    free(new);
}

Test(lib, split_char)
{
    string_t s;
    char **new;
    char *responses[50] = {"", "séparation", "", "de", "", "mots",
    "", "mdr", "", "prochain", "", "vides", ""};

    string_init(&s, ";séparation;;de;;mots;;mdr;;prochain;;vides;");
    new = split_c(&s, ';');
    string_destroy(&s);
    for (unsigned int i = 0; new[i]; i++)
        cr_assert_str_eq(responses[i], new[i]);
    for (unsigned int i = 0; new[i]; i++)
        free(new[i]);
    free(new);
}
