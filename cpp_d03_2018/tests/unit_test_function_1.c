/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, my_string)
{
    string_t s;

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    string_destroy(&s);
}

Test(lib, my_string_object)
{
    string_t s;

    string_init(&s, "Hello  World");
    s.string_init(&s, "test");
    cr_assert_str_eq(s.str, "test");
    s.string_destroy(&s);
}
