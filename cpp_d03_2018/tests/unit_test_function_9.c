/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, c_str)
{
    string_t s;
    const char *ptr;

    string_init(&s, "Hello  World");
    ptr = c_str(&s);
    cr_assert_eq(ptr, s.str);
    string_destroy(&s);
}

Test(lib, c_str_obj)
{
    string_t s;
    const char *ptr;

    string_init(&s, "Hello  World");
    ptr = s.c_str(&s);
    cr_assert_eq(ptr, s.str);
    s.string_destroy(&s);
}
