/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, assign)
{
    string_t s;
    string_t a;

    string_init(&s, "testing");
    string_init(&a, "dumy");
    assign_s(&a, &s);
    cr_assert_str_eq(a.str, "testing");
    cr_assert_str_eq(s.str, "testing");
    assign_c(&a, "new test");
    cr_assert_str_eq(a.str, "new test");
    string_destroy(&s);
    string_destroy(&a);
}
