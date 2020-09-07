/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, size)
{
    string_t s;
    string_t *ss = NULL;

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    cr_assert_eq(size(&s), 12);
    cr_assert_eq(size(ss), -1);
    string_destroy(&s);
}

Test(lib, size_object)
{
    string_t s;
    string_t *ss = NULL;

    string_init(&s, "Hello  World");
    s.string_init(&s, "test");
    cr_assert_str_eq(s.str, "test");
    cr_assert_eq(s.size(&s), 4);
    cr_assert_eq(size(ss), -1);
    s.string_destroy(&s);
}
