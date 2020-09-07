/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, compare)
{
    string_t s;
    string_t t;
    string_t f;

    string_init(&s, "Hello  World");
    string_init(&t, "Hello  World");
    string_init(&f, "wrong");
    cr_assert_str_eq(s.str, "Hello  World");
    cr_assert_eq(compare_s(&s, &t), 0);
    cr_assert_eq(compare_s(&s, &f), -47);
    cr_assert_eq(compare_s(&s, NULL), -1);
    cr_assert_eq(compare_c(&s, "Hello  World"), 0);
    cr_assert_eq(compare_c(&s, NULL), -1);
    string_destroy(&s);
    string_destroy(&t);
    string_destroy(&f);
}

Test(lib, compare_object)
{
    string_t s;
    string_t t;
    string_t f;

    string_init(&s, "Hello  World");
    string_init(&t, "Hello  World");
    string_init(&f, "wrong");
    cr_assert_str_eq(s.str, "Hello  World");
    cr_assert_eq(s.compare_s(&s, &t), 0);
    cr_assert_eq(s.compare_s(&s, &f), -47);
    cr_assert_eq(s.compare_s(&s, NULL), -1);
    cr_assert_eq(s.compare_c(&s, "Hello  World"), 0);
    cr_assert_eq(s.compare_c(&s, NULL), -1);
    s.string_destroy(&s);
    t.string_destroy(&t);
    f.string_destroy(&f);
}
