/*
** EPITECH PROJECT, 2019
** functions 4 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, at)
{
    string_t s;

    string_init(&s, "dumy test");
    cr_assert_eq(at(&s, 3), 'y');
    cr_assert_eq(at(&s, 134), -1);
    cr_assert_eq(at(&s, 9), -1);
    string_destroy(&s);
    cr_assert_eq(at(&s, 7), -1);
}

Test(lib, at_object)
{
    string_t s;

    string_init(&s, "dumy test");
    cr_assert_eq(s.at(&s, 3), 'y');
    cr_assert_eq(s.at(&s, 134), -1);
    cr_assert_eq(s.at(&s, 9), -1);
    s.string_destroy(&s);
    cr_assert_eq(s.at(&s, 7), -1);
}
