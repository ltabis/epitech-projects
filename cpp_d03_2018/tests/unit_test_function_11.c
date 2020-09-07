/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, find)
{
    string_t s;
    string_t t;
    string_t f;
    const char *str1 = "ello";
    const char *str2 = "test";

    string_init(&s, "eeeHello");
    string_init(&t, "Hello");
    string_init(&f, "nope");
    cr_assert_eq(find_s(&s, &t, 1), 3);
    cr_assert_eq(find_s(&s, &f, 0), -1);
    cr_assert_eq(find_c(&s, str1, 1), 4);
    cr_assert_eq(find_c(&s, str2, 0), -1);
    string_destroy(&s);
    string_destroy(&t);
    string_destroy(&f);
}

Test(lib, find_object)
{
    string_t s;
    string_t t;
    string_t f;
    const char *str1 = "ello";
    const char *str2 = "test";

    string_init(&s, "eeeHello");
    string_init(&t, "Hello");
    string_init(&f, "nope");
    cr_assert_eq(s.find_s(&s, &t, 1), 3);
    cr_assert_eq(s.find_s(&s, &f, 0), -1);
    cr_assert_eq(s.find_c(&s, str1, 1), 4);
    cr_assert_eq(s.find_c(&s, str2, 0), -1);
    s.string_destroy(&s);
    t.string_destroy(&t);
    f.string_destroy(&f);
}
