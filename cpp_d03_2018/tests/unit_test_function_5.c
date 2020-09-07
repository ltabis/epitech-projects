/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, clear)
{
    string_t s;

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    clear(&s);
    cr_assert_eq(s.str[0], 0);
    string_destroy(&s);
}

Test(lib, clear_object)
{
    string_t s;

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    s.clear(&s);
    cr_assert_eq(s.str[0], 0);
    s.string_destroy(&s);
}
