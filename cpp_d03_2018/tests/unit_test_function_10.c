/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(empty(&s), 1);
    string_destroy(&s);
    string_init(&s, "a");
    cr_assert_eq(empty(&s), 0);
    string_destroy(&s);
}

Test(lib, empty_obj)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.empty(&s), 1);
    s.string_destroy(&s);
    string_init(&s, "a");
    cr_assert_eq(s.empty(&s), 0);
    s.string_destroy(&s);
}
