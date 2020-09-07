/*
** EPITECH PROJECT, 2019
** unit_test_clean_str.c
** File description:
** unti tests for clean str functions
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(lib_tests, clean_str_1)
{
    char str[] = "I'm      a       test!";

    str[4] = '\t';
    my_clean_str(str);
    cr_assert_str_eq(str, "I'm a test!");
}

Test(lib_tests, clean_str_2)
{
    char str[] = "Already cleaned string";

    my_clean_str(str);
    cr_assert_str_eq(str, "Already cleaned string");
}

Test(lib_tests, clean_str_3)
{
    char str[] = "Bad               soooo bad";

    str[4] = '\t';
    str[1] = '\n';
    str[3] = '\r';
    str[10] = '\t';
    my_clean_str(str);
    cr_assert_str_eq(str, "B\nd\r soooo bad");
}

Test(lib_tests, clean_str_4)
{
    char str[] = "space end         ";

    str[0] = '\n';
    my_clean_str(str);
    cr_assert_str_eq(str, "\npace end");
}

Test(lib_tests, clean_str_null)
{
    char *str = NULL;

    my_clean_str(str);
    cr_assert_eq(str, NULL);
}
