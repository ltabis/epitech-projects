/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, insert)
{
    string_t s;
    string_t t;
    string_t f;

    string_init(&s, "eeeHello");
    string_init(&t, "Hello");
    string_init(&f, "nope");
    insert_c(&s, 4, "Hello  World");
    insert_c(&t, 1321, "Hello  World");
    insert_s(&s, 4, &t);
    insert_s(&t, 1321, &f);
    cr_assert_str_eq(s.str, "eeeHHelloHello  WorldHello  Worldello");
    cr_assert_str_eq(t.str, "HelloHello  Worldnope");
    cr_assert_str_eq(f.str, "nope");
    string_destroy(&s);
    string_destroy(&t);
    string_destroy(&f);
}

Test(lib, insert_object)
{
    string_t s;
    string_t t;
    string_t f;

    string_init(&s, "eeemello");
    string_init(&t, "Hello");
    string_init(&f, "nope");
    s.insert_c(&s, 4, "Hello  World");
    t.insert_c(&t, 1321, "Hello  World");
    s.insert_s(&s, 4, &t);
    t.insert_s(&t, 1321, &f);
    cr_assert_str_eq(s.str, "eeemHelloHello  WorldHello  Worldello");
    cr_assert_str_eq(t.str, "HelloHello  Worldnope");
    cr_assert_str_eq(f.str, "nope");
    s.string_destroy(&s);
    t.string_destroy(&t);
    f.string_destroy(&f);
}
