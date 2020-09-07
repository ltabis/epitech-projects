/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "string.h"

Test(lib, append)
{
    string_t s;
    string_t t;

    string_init(&s, "Hello  World");
    string_init(&t, ", I'm here !");
    append_s(&s, &t);
    cr_assert_str_eq(s.str, "Hello  World, I'm here !");
    string_destroy(&s);
    string_destroy(&t);
    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    append_c(&s, ", I'm here !");
    cr_assert_str_eq(s.str, "Hello  World, I'm here !");
}

Test(lib, append_object)
{
    string_t s;
    string_t t;

    string_init(&s, "Hello  World");
    string_init(&t, ", I'm here !");
    s.append_s(&s, &t);
    cr_assert_str_eq(s.str, "Hello  World, I'm here !");
    s.string_destroy(&s);
    t.string_destroy(&t);
    string_init(&s, "Hello  World");
    cr_assert_str_eq(s.str, "Hello  World");
    s.append_c(&s, ", I'm here !");
    cr_assert_str_eq(s.str, "Hello  World, I'm here !");
}
