/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, to_int)
{
    string_t s;
    string_t t;
    string_t f;
    string_t p;

    string_init(&s, "eeeHello");
    string_init(&t, "1334");
    string_init(&f, "-42");
    string_init(&p, "----42");
    cr_assert_eq(to_int(&s), 0);
    cr_assert_eq(to_int(&t), 1334);
    cr_assert_eq(to_int(&f), -42);
    cr_assert_eq(to_int(&p), 0);
    string_destroy(&s);
    string_destroy(&t);
    string_destroy(&f);
    string_destroy(&p);
}

Test(lib, to_int_object)
{
    string_t s;
    string_t t;
    string_t f;
    string_t p;

    string_init(&s, "eeeHello");
    string_init(&t, "1334");
    string_init(&f, "-42");
    string_init(&p, "----42");
    cr_assert_eq(s.to_int(&s), 0);
    cr_assert_eq(t.to_int(&t), 1334);
    cr_assert_eq(f.to_int(&f), -42);
    cr_assert_eq(p.to_int(&p), 0);
    s.string_destroy(&s);
    t.string_destroy(&t);
    f.string_destroy(&f);
    p.string_destroy(&p);
}
