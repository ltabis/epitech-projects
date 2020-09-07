/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, copy)
{
    string_t s;
    char *new = strdup("new!");

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    cr_assert_eq(copy(&s, new, 3, 4), 3);
    cr_assert_str_eq(new, "o  !");
    cr_assert_eq(copy(&s, new, 1, 1), 1);
    cr_assert_str_eq(new, "e  !");
    cr_assert_eq(copy(&s, new, 4, 20), 0);
    cr_assert_eq(copy(NULL, new, 4, 20), 0);
    cr_assert_eq(copy(&s, new, 4, 0), 4);
    cr_assert_str_eq(new, "Hell");
    cr_assert_eq(copy(&s, new, 2, 0), 2);
    cr_assert_str_eq(new, "Hell");
    string_destroy(&s);
}

Test(lib, copy_object)
{
    string_t s;
    char *new = strdup("new!");

    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    cr_assert_eq(s.copy(&s, new, 3, 4), 3);
    cr_assert_str_eq(new, "o  !");
    cr_assert_eq(s.copy(&s, new, 4, 20), 0);
    cr_assert_eq(s.copy(NULL, new, 4, 20), 0);
    cr_assert_eq(s.copy(&s, new, 4, 0), 4);
    cr_assert_str_eq(new, "Hell");
    cr_assert_eq(s.copy(&s, new, 2, 0), 2);
    cr_assert_str_eq(new, "Hell");
    string_destroy(&s);
}
